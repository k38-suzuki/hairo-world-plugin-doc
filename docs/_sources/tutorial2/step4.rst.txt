Step 4: Simulating and polling camera images
============================================

The Drone model comes equipped with a camera.
In Step 4, we will learn how to simulate this camera and poll camera images from the controller.

.. contents::
   :local:
   :depth: 2

The project we created in Step 3 contained a variety of visual elements.
This step picks up that project in the state we last left it. First, save the project anew as step4.cnoid before you begin.

Camera devices
--------------

In Step 3, cameras are defined as devices in Choreonoid.The camera installed on the Drone model is called “Camera.”
This name is used to distinguish it from other devices. Access from the controller is the same as other devices, such as the light.

You can refer to the remarks on Camera notation in the section on creating a Drone model to see how the camera is actually defined.

Changing cameras in the Scene View
----------------------------------

The Scene View also allows for you to display the point of view of the camera onboard the robot model.
Use this functionality to see what sort of images are obtained from the camera installed on the Drone model.

You can toggle the camera using the Camera Selection combo box on the Scene Bar below.

.. image:: images/step4-1.png
   :width: 320px

Clicking here will display a list of the cameras defined by the system, as well as those contained in models displayed on the scene.
The current project should display the below choices.

* Perspective - System
* Orthographic - System
* Camera - Drone

Perspective - System and Orthographic - System are the default cameras provided in the Scene View; they allow the user to change the viewpoint using the mouse.
These cameras respectively render using perspective projection and orthographic projection. By default, perspective is selected.

“Camera - Drone” indicates that there is a camera named “Camera” installed on the Drone model. We want to see the scene from the perspective of this camera, so select it.
While the outcome will vary based on the orientation of the Drone model and the render settings of the Scene View, you should see an image like the below on the Scene View.

.. image:: images/step4-2.png
   :width: 320px

Launch the simulation and try operating the Drone model with the gamepad. You should see that the image now moves in sequence with the movement of the Drone.
This video is sourced from the camera onboard the Drone model.

Simulations will also let you simultaneously display a camera image like this one and an overhead view of the original Scene View.
Choreonoid allows for doing this by adding and enabling the display of a Scene View. Let’s give it a try now.

From the Main Menu, select View, then Generate View, then Scene. This will bring up the Generate Scene View dialog.
You can set a name for the View you intend to add, but if there is no particular need for a unique name, you can use the default.
Clicking the Generate button will generate an additional Scene View and position it on top of the main window.

The location where a view is generated is determined in advance for each view type. The new Scene View will likely appear to overlap where the prior Scene View was.
You can manipulate the tabs to toggle between the current and former view, but this prevents you from seeing them simultaneously.
For simultaneous display, carry out the steps described in the section on How to Relocate Views and move the newly-added view to a different part of the main window.

Once you have succeeded in moving the view, toggle the camera to be used for rendering. The respective Scene View cameras can be toggled independently of each other.
In this case, the scene bar control is applied to the Scene View last in focus.
First click the mouse within or otherwise gain control of the previous Scene View to put it in focus, then select Perspective - System from the camera combo bar on the scene bar.
Next, focus on the newly-added Scene View and select Camera - Drone from the camera selection combo box. You can now tweak the view positions and sizes to get the right fit.
This lets you get a display like, for example, the one below.

.. image:: images/step4-3.png
   :width: 320px

We arrange the new Scene View on the left side and then display the Drone model’s camera image there. On the Scene View on the right side, we display an overhead view from the default camera.

Simulating camera images
------------------------

We have learned how to use the Scene View to display camera images. However, this is limited to rendering in the GUI; this functionality is separate from the simulation functionality.
You should have seen that this allows you to render camera images even without launching the simulation itself.
To obtain camera images from the controller while running a simulation, you must run a camera image simulation as a device.

To do so, you must add a Sensor Visualizer and a GL Vision Simulator Item to your project.
From the Main Menu, click File > New > then Sensor Visualizer to generate an item. Then, from the Main Menu, click File > New > then GL Vision Simulator to generate an item.
Position it as a sub-item of the simulator item. The item layout should be as below.

.. image:: images/step4-4.png
   :width: 320px

.. image:: images/step4-4-2.png
   :width: 320px

Next, check the **"Camera" sub-item in the Sensor Visualizer**.
Finally, change the **"Record vision data" property of the GL Vision Simulator to true**.

Running a simulation in this state will simulate camera images being taken within the simulator, letting you poll them from the controller.

For details on the GL Vision Simulator Item, see the section on Simulation of Vision Sensor.

Controller source code
----------------------

We have learned how to simulate camera images by incorporating the GL Vision Simulator item into our project.
To check the output, you need a controller to poll images from the camera device.
Here we create a controller designed to export images polled from the devices as files to the local system. The source code follows:

.. _controller-example4:

.. literalinclude:: ./src/drone/CameraController.cpp
   :language: C++
   :caption: CameraController.cpp

As before, save the above source code in the project directory as a file named CameraController.cpp.
Add the below to CMakeLists.txt and compile::

 add_cnoid_simple_controller(DroneTutorial_CameraController CameraController.cpp)

Deploying the controller
------------------------

As before, you can use the SimpleController item to implement the controller you created in your project and position it as a sub-item of the Drone.
This will cause the Item Tree View to be as follows.

.. image:: images/step4-5.png
   :width: 320px

Polling and displaying camera images
------------------------------------

Now, let’s go ahead and run a simulation.
Using the B button on a gamepad or in the virtual joystick view, you can control the camera. (On a PlayStation controller, this corresponds to the circle button.)
Pressing this will save an image of the current camera view to a file. The Message View will display the following message::

 The image of Camera has been saved to "Camera.png".

The file export destination will be the current directory, and the file will be named Camera.png.
Try clicking the button and then opening the image file in your preferred image viewer. In Ubuntu, you can use the “eog” image viewer. It is opened by invoking the below on the command line::

 eog Camera.png

This lets you view the camera image you created.
eog includes functionality to auto-update the displayed image if the image file is updated. This lets you keep the file open in eog and see the results each time it is changed.

How this implementation works
-----------------------------

Using the below initialize function::

 camera = io->body()->findDevice<Camera>("Camera");

lets you poll the Device object for Camera and store this as a camera variable.
Also, using::

 io->enableInput(camera);

enables input from the device. The above notation is required if you want to enable device input.

.. note:: For device output, you must invoke notifyStateChange() against the device. Therefore, there is no function like enableOutput() against the device.

The control function is used to check the state of the B button and, when it is pushed, save a file from the Camera device. In this process, the line below::

 const Image& image = camera->constImage();

polls the image data the Camera has. Provided this value is not empty, the below::

 camera->constImage().save(filename);

will save the image file as-is.
In the actual controller, image processing could be performed against the image data, or the image data obtained could be forwarded to another device remotely, among other potential applications.
