#include <cnoid/Rotor>
#include <cnoid/SimpleController>

using namespace cnoid;

class DroneController1 : public SimpleController
{
    Body* ioBody;
    Rotor* rotor[4];

public:
    virtual bool initialize(SimpleControllerIO* io) override
    {
        ioBody = io->body();

        rotor[0] = io->body()->findDevice<Rotor>("Rotor_FR");
        rotor[1] = io->body()->findDevice<Rotor>("Rotor_FL");
        rotor[2] = io->body()->findDevice<Rotor>("Rotor_RL");
        rotor[3] = io->body()->findDevice<Rotor>("Rotor_RR");

        for(int i = 0; i < 4; ++i) {
            io->enableInput(rotor[i]);
        }

        return true;
    }

    virtual bool control() override
    {
        static const double G = 9.80665;
        double mass = ioBody->mass();
        double gravity = mass * G;
        static const double ATD[] = { -1.0, 1.0, -1.0, 1.0 };
        double thr[4] = { 0.0 };

        thr[0] = gravity / 4.0;
        thr[1] = gravity / 4.0;
        thr[2] = gravity / 4.0;
        thr[3] = gravity / 4.0;

        for(int i = 0; i < 4; ++i) {
            rotor[i]->thrust() = thr[i];
            rotor[i]->torque() = ATD[i] * thr[i];
            rotor[i]->notifyStateChange();
        }
        return true;
    }
};

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(DroneController1)