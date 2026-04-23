Step 3: Controlling the drone with a gamepad
=================================================

In Step 2, we created a controller to perform the minimum control required to stabilize the model, and we learned how to implement and import that controller.
In Step 3, we attempt to create a slightly more complex controller.

.. contents::
   :local:
   :depth: 2

Gamepad setup
-------------

The controller we will be creating in this step is used to control the Drone model using a gamepad (joystick). To do so, begin by obtaining a gamepad and connecting it to your computer.
Note that **you can still perform this even without an actual gamepad**. In this case, you can alternatively use the Virtual Joystick View.
You can proceed to the next section on :ref:`drone-tutorial-virtual-joystick-view`. The below explanation presumes use of an actual gamepad.
This tutorial also presumes a gamepad with a layout like that seen below.

.. image:: images/step3-1.jpg
   :width: 320px

This product is the `Logicool F310 <https://gaming.logicool.co.jp/ja-jp/shop/p/f310-gamepad>`_; other similar gamepads include the PlayStation 3 and 4 gamepads (DualShock 3 and 4) and the Xbox gamepad.
If using other gamepads, the axes and placement of buttons may not correspond and fail to operate properly. In that case, you will need to change the axes and button IDs indicated in the source code in order to remap the controller.
A convenient tool to determine whether the gamepad is detected by the OS and whether the axes and button mappings are correct is the “jstest” command.
If the gamepad does not function properly, check it using this command. On Ubuntu, execute the below from the command line::

 sudo apt-get install joystick

to install the package. Use, e.g.,::

 jstest /dev/input/js0

to execute it.
The command argument indicates the device file for the gamepad. “js0” here corresponds to the first gamepad connected and assigned an ID of 0. Ordinarily, this would be the one used. If you want to use two or more gamepads, you would use devices js1 and js2. However, note that this requires changing the source code.
Connecting the gamepad and executing the command above will return information like the below to the console.::

 Driver version is 2.1.0.
 Joystick (Logitech Gamepad F310) has 8 axes (X, Y, Z, Rx, Ry, Rz, Hat0X, Hat0Y)
 and 11 buttons (BtnX, BtnY, BtnTL, BtnTR, BtnTR2, BtnSelect, BtnThumbL, BtnThumbR, ?, ?, ?).
 Testing ... (interrupt to exit)
 Axes:  0:     0  1:     0  2:-32767  3:     0  4:     0  5:-32767  6:     0  7:     0 Buttons:  0:off  1:off  2:off  3:off  4:off  5:off  6:off  7:off  8:off  9:off 10:off

Manipulating the gamepad axes and buttons will change the output. This lets you confirm the connection status and the mapping of the axes and buttons. If you do not get this output or if the gamepad does not produce different output when manipulated, it might not be connected properly. Check your connection method and the gamepad status and try again.

.. note:: The Joystick class used below to handle input from joysticks contains functionality to calibrate the common position of axes and buttons (ID values) for each type of gamepad.This allows the same program to be used by the above gamepad. However, the ID values used within the program may not necessarily correspond to those output by jstest, so use caution.

.. _drone-tutorial-virtual-joystick-view:

Virtual joystick view setup
---------------------------

If you do not have a gamepad, you can use the Virtual Joystick View.
This is accessed by selecting View, Display Views, and Virtual Joystick from the Main Menu. The external appearance is as below.

.. image:: images/step3-2.png
   :width: 320px

This appears in the same area as the Message View usually situated on the bottom of the main window.
This causes messages to be hidden, `so you should change the view layout <https://choreonoid.org/en/manuals/latest/basics/mainwindow.html#basics-modify-view-layout>`_ in order to be able to use both the Message View and Virtual Joystick View at the same time.
You could reconfigure the layout as below.

.. image:: images/step3-3.png
   :width: 320px

Once a gamepad is connected, its input takes precedence. If using the Virtual Joystick View, ensure that there is no gamepad connected at that time.
This completes the setup process.

Controller source code
----------------------

The source code for the controller we will be creating is below.
This code takes DroneController1, which we worked on in Step 2, and adds functionality to control the thrusts and anti-torques of the rotor devices via a gamepad.

.. _controller-example3-1:

.. literalinclude:: ./src/drone/DroneController2.cpp
   :language: C++
   :caption: DroneController2.cpp

Controller compilation
----------------------

Enter and save the source code above and recompile.
The process is the same as described in Step 2. Save the source code to a file named DroneController2.cpp in the project directory and add the below code to CMakeLists.txt.::

 add_cnoid_simple_controller(DroneTutorial_DroneController2 DroneController2.cpp)
 target_link_libraries(DroneTutorial_DroneController2 CnoidCFDPlugin)

Now, when you compile Choreonoid, the controller will also be compiled, and a file called DroneTutorial_DroneController2so will be generated in the controller directory.

Swapping controllers
--------------------

Now, let’s try using this controller as a controller for the Drone model.
You should still have the project you created in Step 2. All you have to do is change the controller settings.
Carry out the :ref:`simulation-drone-tutorial-set-controller` described in Step 2 and ensure that you overwrite the DroneTutorial_DroneController2.so file we created previously.
This completes the controller setup. Now, save this project as step3.cnoid.

Drone operation
---------------
Now, let’s run the simulation.

The gamepad should now be working to control the Drone model. Try moving it around. If you are using an F310, the right analog stick should let you move the Drone model.
Try moving its axis. For other gamepads, you can experiment to see which axes correspond, etc. If things do not function as intended, try changing the axis settings in your source code. This will be explained in the next section.
If using the Virtual Joystick View, you can manipulate the view using the keyboard. The buttons onscreen correspond to the directional pad and analog stick axes of a gamepad, as well as the buttons. The correspondence is explained in the image below.

.. image:: images/step3-4.png
   :width: 320px

If you look at the F310 in the context of this image, you will see how the main axes of the analog sticks and buttons on the F310 correspond. Use the J and L buttons on the keyboard to control the yaw rotation of the gun turret and the I and K keys to control the pitch rotation.
One note is that the Virtual Joystick View will not work **unless the keyboard is in focus**. Therefore, you must click the mouse in the view or otherwise regain focus. If you change the viewpoint of the Scene View while manipulating a model, the focus will shift to that new view.
You must click the Virtual Joystick View again to regain focus.
Were you able to move the Drone model as intended? As you can see, you can achieve a range of functionality to manipulate the model depending on how you configure your gamepad. Taking input from external devices allows you to add more functionality to your controllers.

How this implementation works
-----------------------------

Including headers
~~~~~~~~~~~~~~~~~

* **#include <cnoid/EigenUtil>** : Provides utility functions for Eigen-based linear algebra, such as angle conversions.
* **#include <cnoid/SimplePilot>** : An interface to handle joystick/gamepad inputs and common drone flight logic.
* **#include <cnoid/Format>** : Used for formatted string output.

Constants and namespace
~~~~~~~~~~~~~~~~~~~~~~~

The following constants are defined within an anonymous namespace for flight tuning:

* **MAX_TILT_ANGLE**: Sets the safety limit for the drone's tilt to 80 degrees.
* **delta**: Scaling factors for user inputs (Throttle, Aileron, Elevator, Rudder).
* **pgain / dgain**: Proportional and Derivative gains for the PD control loop to ensure stability.

Class member variable declarations
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* **SimplePilot pilot**: Manages flight states (Arm/Disarm) and interprets joystick signals.
* **DeviceList<Rotor> rotors**: A list that automatically stores all ``Rotor`` devices found in the model.
* **Vector4 zref / dzref**: Reference values for position/orientation and their velocities.
* **Vector2 dxref**: Reference velocity for horizontal movement.
* **std::ostream* os**: Pointer to the Choreonoid message view for logging.

Implementing the initialize function
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* **rotors = body->devices();**: Automatically discovers and lists all rotor devices in the body model.
* **pilot.setStickMode(SimplePilot::MODE2);**: Configures the controller to "Mode 2" (typical drone stick layout).
* **pilot.initialize(io)**: Sets up the pilot interface, checking for necessary sensors like **Imu** (Inertial Measurement Unit) and **FlightBattery**.
* **zref = pilot.zrpy();**: Initializes the reference orientation (altitude and RPY angles) to the current state.

Implementing the control function
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The control loop handles pilot commands and calculates the stabilization forces.

1. **Input Processing**:
    * **pilot.readCurrentState()**: Updates sensor data and joystick positions.
    * **pilot.getPosition()**: Retrieves stick positions. A deadzone of **0.2** is applied to ignore minor stick drifts.

2. **State Acquisition**:
    * Retrieves current altitude/orientation (``z``), velocity (``dz``), and acceleration (``ddz``) from the ``SimplePilot`` interface.
    * ``pilot.gravityCompensation(4)``: Calculates the base thrust needed to hover, distributed across 4 rotors.

3. **PD Control Loop**:
    * **Altitude/Yaw (i=0, 3)**: Calculates force (``fz``) based on the difference between target velocity (from stick input) and current velocity.
    * **Roll/Pitch (i=1, 2)**: Translates stick input into horizontal velocity references, then calculates the necessary tilt angles to achieve that movement.

4. **Arming and Safety**:
    * **pilot.arm(...)**: Checks for a specific stick gesture (Left stick inward) to "arm" the motors for takeoff.
    * **pilot.on()**: Only applies thrust if the drone is in an armed/active state.

5. **Thrust Mixing and Output**:
    * The control forces (``fz``) are mixed into the four rotors to execute Roll, Pitch, Yaw, and Throttle movements.
    * **rotor->notifyStateChange()**: Updates the physics engine with the final thrust and torque values for each rotor.

Factory function definitions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The controller uses the standard Choreonoid macro to export the factory function: ::

 CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(DroneController2)

This allows the simulator to dynamically load the ``DroneController2`` class from the shared library.
