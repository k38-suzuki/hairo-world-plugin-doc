#include <cnoid/EigenUtil>
#include <cnoid/Format>
#include <cnoid/Rotor>
#include <cnoid/SimpleController>
#include <cnoid/SimplePilot>
#include <map>
#include <string>
#include <vector>

using namespace std;
using namespace cnoid;

namespace {

const double MAX_TILT_ANGLE = 80.0;

const double delta[] = { 0.5, 4.0, 4.0, 2.1 };
const double pgain[] = { 0.08, 0.003, 0.003, 0.00002 };
const double dgain[] = { 0.02, 0.002, 0.002, 0.00001 };

} // namespace

class DroneController2 : public SimpleController
{
    SimplePilot pilot;
    DeviceList<Rotor> rotors;
    Vector4 zref;
    Vector4 dzref;
    Vector2 dxref;
    std::ostream* os;

public:
    virtual bool initialize(SimpleControllerIO* io) override
    {
        Body* body = io->body();
        os = &io->os();
        rotors = body->devices();

        pilot.setStickMode(SimplePilot::MODE2);
        pilot.setMaxTiltAngle(radian(MAX_TILT_ANGLE));
        if(pilot.initialize(io)) {
            if(!pilot.findImu("Imu")) {
                return false;
            }
            if(!pilot.findBatteryDevice("FlightBattery")) {
                return false;
            }
        }

        for(auto& rotor : rotors) {
            io->enableInput(rotor);
        }

        zref = pilot.zrpy();
        dzref = Vector4::Zero();
        dxref = Vector2::Zero();

        return true;
    }

    virtual bool control() override
    {
        pilot.readCurrentState();

        static const int controlID[] = {
            SimplePilot::THROTTLE, SimplePilot::AILERON, SimplePilot::ELEVATOR, SimplePilot::RUDDER
        };

        double pos[4];
        for(int i = 0; i < 4; ++i) {
            pos[i] = pilot.getPosition(controlID[i]);
            if(fabs(pos[i]) < 0.2) {
                pos[i] = 0.0;
            }
        }

        Vector4 fz = Vector4::Zero();
        Vector4 z = pilot.zrpy();
        Vector4 dz = pilot.dzrpy();
        Vector4 ddz = pilot.ddzrpy();

        Vector2 dx_local = pilot.dxy_local();
        Vector2 ddx_local = pilot.ddxy_local();
        double gc = pilot.gravityCompensation(4);

        static const double P = 1.0;
        static const double D = 1.0;

        for(int i = 0; i < 4; ++i) {
            if(i == 0 || i == 3) {
                dzref[i] = -delta[i] * pos[i];
                fz[i] = (dzref[i] - dz[i]) * pgain[i] + (0.0 - ddz[i]) * dgain[i];
            } else {
                int j = i - 1;
                dxref[j] = -delta[i] * pos[i];
                zref[i] = P * (dxref[j] - dx_local[1 - j]) + D * (0.0 - ddx_local[1 - j]);
                zref[i] = (i != 1 ? 1.0 : -1.0) * zref[i];
                fz[i] = (zref[i] - z[i]) * pgain[i] + (0.0 - dz[i]) * dgain[i];
            }
        }

        if(pilot.arm(SimplePilot::L_STICK_INWARD, 1.0) == SimplePilot::isReady) {
            (*os) << "Ready for takeoff." << std::endl;
        }

        static const double ATD[] = { -1.0, 1.0, -1.0, 1.0 };
        double thr[4] = { 0.0 };
        if(pilot.on()) {
            thr[0] = gc + fz[0] - fz[1] - fz[2] - fz[3];
            thr[1] = gc + fz[0] + fz[1] - fz[2] + fz[3];
            thr[2] = gc + fz[0] + fz[1] + fz[2] - fz[3];
            thr[3] = gc + fz[0] - fz[1] + fz[2] + fz[3];
        }

        for(size_t i = 0; i < rotors.size(); ++i) {
            Rotor* rotor = rotors[i];
            rotor->thrust() = thr[i];
            rotor->torque() = ATD[i] * thr[i];
            rotor->notifyStateChange();
        }

        return true;
    }
};

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(DroneController2)