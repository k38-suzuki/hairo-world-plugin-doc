CFD Plugin
==========

This section explains how to simulate Remotely Operated Vehicles (ROVs) and Unmanned Aerial Vehicles (UAVs) using the **CFD Simulator**.

Creating and Configuring the CFD Simulator
------------------------------------------

This feature uses Choreonoid's standard "AIST Simulator." To set it up:
Select **File** > **New** > **CFD Simulator** from the main menu. Place the generated CFD Simulator as a child item of the **AIST Simulator**.

Creating and Configuring MultiCollider Items
--------------------------------------------

The **MultiCollider** item is used to virtually define regions in the Choreonoid world that contain fluids such as water or air. 

To create one, select **File** > **New** > **MultiCollider** and specify the type as "**Fluid**". Place it as a child of the World item. You can define complex environments by creating multiple MultiCollider items.

.. note::
   If target areas overlap, the settings of the MultiCollider item positioned lower in the Item Tree view will take precedence.

Fluid items can be toggled on or off using the checkboxes in the Item Tree. Note that hidden MultiCollider items are excluded from the simulation.

The parameters for the MultiCollider item are as follows:

.. list-table::
  :widths: 20,12,12,75
  :header-rows: 1

  * - Parameter
    - Default Value
    - Unit
    - Meaning
  * - Density
    - 0.0
    - kg/m³
    - Specifies the fluid density.
  * - Viscosity
    - 0.0
    - Pa·s
    - Specifies the fluid viscosity.
  * - Steady Flow
    - 0, 0, 0
    - N, N, N
    - Specifies external forces applied to objects within the region.
  * - Shape
    - Box
    - \-
    - Specifies the shape of the region (Box/Cylinder/Sphere).
  * - Size
    - 1.0, 1.0, 1.0
    - m
    - Specifies the XYZ size (only for Box).
  * - Radius
    - 1.0
    - m
    - Specifies the radius (only for Cylinder/Sphere).
  * - Height
    - 1.0
    - m
    - Specifies the height (only for Cylinder).
  * - Position / RPY
    - 0, 0, 0
    - m / deg
    - Specifies the location (XYZ) and orientation (Roll, Pitch, Yaw).
  * - Diffuse Color / Transparency
    - 0, 0, 0 / 0
    - \-
    - Specifies the RGB color and transparency of the region.

Body Item Settings
------------------

The CFD Simulator calculates buoyancy and drag forces acting on each link of the robot. To enable these calculations, add the following parameters to each link in the body file:

.. code-block:: yaml

    density: 1000.0
    centerOfBuoyancy: [ 0.0, 0.0, 0.0 ]
    cdw: 1.0
    cda: 1.0
    cw: 0.2

Details for each key:

.. list-table::
  :widths: 20,16,12,75
  :header-rows: 1

  * - Parameter
    - Default Value
    - Unit
    - Meaning
  * - density
    - 0.0
    - kg/m³
    - Specifies the density of the link.
  * - centerOfBuoyancy
    - 0.0, 0.0, 0.0
    - m
    - Coordinates of the center of buoyancy.
  * - cdw
    - 0.0
    - \-
    - Drag coefficient in water.
  * - cda
    - 0.0
    - \-
    - Drag coefficient in air.
  * - cv
    - 0.0
    - m
    - Viscous force coefficient proportional to velocity.
  * - cw
    - 0.0
    - \-
    - Drag coefficient proportional to angular velocity (opposes rotation).

Thruster Settings (for ROVs)
----------------------------

The CFD Simulator provides a **Thruster** device to power ROVs, applying thrust and torque. The default orientation is the +X axis of the link's local coordinate system. Define it under the ``elements`` of a link:

.. code-block:: yaml

      -
        type: Thruster
        name: Thruster
        forceOffset: 1.0
        torqueOffset: 0.1
        symbol: true

Rotor Settings (for UAVs)
-------------------------

The **Rotor** device provides power for UAVs. The default orientation is the +Z axis of the link's local coordinate system. Define it under the ``elements`` of a link:

.. code-block:: yaml

      -
        type: Rotor
        name: Rotor
        forceOffset: 1.0
        torqueOffset: 0.1
        symbol: true

Running the Simulation
----------------------

Start the simulation from the Simulation Bar. If configured correctly, buoyancy, drag, and other fluid forces will be applied to the robot based on the MultiCollider settings.
