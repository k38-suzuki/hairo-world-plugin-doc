WRS 2025 Pre-Competition
========================

This section explains how to set up the competition environment for the **WRS 2024 Pre-Competition**.
This feature is designed to **automatically load competition environments and place robot models**.
To use this feature, the package found `here <https://github.com/wrs-frei-simulation/WRS-Pre-2024>`_ is **required**.

Loading the Competition Environment (Basic)
-------------------------------------------

Launch Choreonoid with the following command.

**If you are using Choreonoid in a ROS 2 environment:** ::

 $ ros2 run choreonoid_ros choreonoid ~/ros2_ws/src/choreonoid/ext/WRS2024PRE/registration/registration.yaml --wrs-util <mission_name>

**If you are using Choreonoid standalone (e.g., within choreonoid/build):** ::

 $ ./bin/choreonoid ../ext/WRS2024PRE/registration/registration.yaml --wrs-util <mission_name>

The arguments that can be specified for **<mission_name>** are as follows:

 .. list-table::
  :widths: 30, 70
  :header-rows: 1

  * - Argument
    - Details
  * - **M1-1**
    - Loads the environment for Competition M1 (Area 1 only) and places **AizuSpider** for the AGX simulator.
      AizuSpider subscribes to the **/joy** topic of ROS 2.
  * - **M1-2**
    - Loads the environment for Competition M1 (Area 2 only) and places **AizuSpider** for the AGX simulator.
      AizuSpider subscribes to the **/joy** topic of ROS 2.
  * - **M2**
    - Loads the environment for Competition M2 (Areas 1 to 4). **Robots are not placed** with this argument.
  * - **M2-A1** to **M2-A4**
    - Loads specific areas of Competition M2. **Robots are not placed** with these arguments.

Loading the Competition Environment (Advanced)
----------------------------------------------

This section explains the procedure for **placing your own custom robot model**.

 1. **Copying the robot model**
 2. **Creating a project**
 3. **Creating a YAML file**
 4. **Launching Choreonoid**

Copying the Robot Model
~~~~~~~~~~~~~~~~~~~~~~~

1. Create a directory (e.g., ``model_<team_name>``) under ``choreonoid/ext/WRS2024PRE/model`` and copy your robot files into it.
2. **Rebuild Choreonoid.** If using ROS 2, you may need to add the ``--cmake-clean-cache`` option for new files to be recognized.
3. Verify that the directory exists in the ``install`` (ROS 2) or ``build/share`` (Standalone) directory.

Creating a Project
~~~~~~~~~~~~~~~~~~

1. Launch Choreonoid and load your custom robot model from the **installed/built share directory** (not the source directory).
2. Set up all necessary **Simple Controllers** and items.
3. **Important:** If publishing sensor data (cameras, etc.) in ROS 2, add a **BodyROS2** item as a child of the robot model.
4. Create a directory (e.g., ``project_<team_name>``) under ``ext/WRS2024PRE/project`` and save your project (``.cnoid``) inside.
5. **Rebuild Choreonoid again** to ensure the project file is deployed.

Editing a YAML File
~~~~~~~~~~~~~~~~~~~

Use ``registration_test.yaml`` as a template. Copy and rename it (e.g., ``registration_<team_name>.yaml``).

Rewrite the **second line** as follows: ::

 robot_list: &RobotList [ <Directory_Name>/<Project_Name_Without_Extension> ]

**Example:** ::

 robot_list: &RobotList [ project_team1/my_robot ]

**Key YAML Parameters:**

.. list-table::
  :widths: 25, 75
  :header-rows: 1

  * - Parameter
    - Meaning
  * - **name**
    - The identifier used for the **<mission_name>** argument.
  * - **robot_project**
    - Projects are loaded in order; the **first** is placed on the **left**, the **second** on the **right**.
  * - **start_position**
    - Specifies the initial coordinates **[x, y, z] in meters**.
  * - **enable_ros**
    - If **true**, automatically adds a Joy subscriber (robot 1: ``/joy``, robot 2: ``/joy2``).

Launching Choreonoid
~~~~~~~~~~~~~~~~~~~~

**Launch command:** ::

 $ ros2 run choreonoid_ros choreonoid <path/to/yaml> --wrs-util <mission_name>

**Note:** Please pay close attention to the **order of the arguments**.
If the robot's position is misaligned, adjust the **start_position** parameter in your YAML file.

Loading the Competition Environment (Qualifiers and Finals)
-----------------------------------------------------------

To load the official qualifier/final environments, use the following specific YAML files:

**Qualifiers (2024/10/04):** ::

 $ ros2 run choreonoid_ros choreonoid ~/ros2_ws/src/choreonoid/ext/WRS2024PRE/registration/registration_20241004.yaml

**Finals (2024/10/05):** ::

 $ ros2 run choreonoid_ros choreonoid ~/ros2_ws/src/choreonoid/ext/WRS2024PRE/registration/registration_20241005.yaml

**Post-launch:** Select an area from the **WRSUtil bar** combo box and click the **"Open Project"** button.
