
CFDPlugin
=========

Here, we explain how to use CFDPlugin. This plugin calculates buoyancy and resistance acting on a body (robot) moving through a fluid (water, air, etc.) and reflects that to the behavior of the body. Also, by using virtual "Thruster" and "Rotor" devices provided by this plugin, it is possible to apply propulsive force and torque to the center of the link to which they are mounted, and to simulate how the body moves through fluid.

Creating and setting of CFDSimulator item
-----------------------------------------

Create item by "File"-"New"-"CFDSimulator" on main menu.
After the creation, place CFDSimulator item under AISTSimulator item on the item tree view.
CFDSimulator item has no properties.


Creating and setting of FluidArea item
--------------------------------------

Create item by "File"-"New"-"FluidArea" on main menu.
After the creation, place FluidArea item under World item on the item tree view.
FluidArea item has following properties.

.. list-table::
  :widths: 20,12,12,75
  :header-rows: 1

  * - Key
    - Default value
    - Unit
    - Function
  * - Density
    - 0.0
    - kg/m3
    - The density of a fluid.
  * - Viscosity
    - 0.0
    - Pa*s
    - The viscosity of a fluid.
  * - SteadyFlow
    - 0, 0, 0
    - N, N, N
    - External force which is applied to the bodies in the FluidArea.
  * - Shape
    - Box
    - \-
    - The shape of the FluidArea.(Box/Cylinder/Sphere)
  * - Size
    - 1.0, 1.0, 1.0
    - m, m, m
    - The size of the Box-type FluidArea.
  * - Radius
    - 1.0
    - m
    - The radius of the Cylinder-type or Sphere-type FluidArea.
  * - Height
    - 1.0
    - m
    - The height of the Cylinder-type FluidArea.
  * - Translation
    - 0, 0, 0
    - m, m, m
    - The position of the FluidArea.
  * - RPY
    - 0, 0, 0
    - deg, deg, deg
    - The orientation of the FluidArea.
  * - DiffuseColor
    - 0, 0, 0
    - \-, -, -
    - The diffuse color of the FluidArea.
  * - Transparency
    - 0
    - \-
    - The transparency of the FluidArea.

Additional parameters for body model
------------------------------------

This plugin calculates the buoyancy and resistance acting on a body. For calculating them, you need to write following keys for each link of the body.

.. list-table::
  :widths: 20,16,12,75
  :header-rows: 1

  * - Key
    - Default value
    - Unit
    - Function
  * - density
    - 0.0
    - kg/m3
    - The density of a link.
  * - centerOfBuoyancy
    - 0.0, 0.0, 0.0
    - m, m, m
    - The center of buoyancy of a link.
  * - cdw
    - 0.0
    - \-
    - The drag coefficient in water.
  * - cda
    - 0.0
    - \-
    - The drag coefficient in air.
  * - cv
    - 0.0
    - m
    - The coefficient of the resistance which is proportional to the velocity of a link.
  * - cw
    - 0.0
    - \-
    - The coefficient of the resistance which is proportional to the angular velocity of a link.

How to write
~~~~~~~~~~~~

.. code-block:: yaml

    density: 1000.0
    centerOfBuoyancy: [ 0.0, 0.0, 0.0 ]
    cdw: 1.0
    cda: 1.0
    cw: 0.2

Thruster notation
-----------------

Thruster apply thrust and torque to a robot moving through water. You can set as many as you want per link, and the X axis+ direction are set as the default orientation with the link's local coordinate system. For setting thruster, add the below underneath the elements section of the link.

.. code-block:: yaml

      -
        type: Thruster
        name: Thruster
        forceOffset: 1.0
        torqueOffset: 0.1
        symbol: true

Thruster device has following keys.

.. list-table::
  :widths: 20,12,8,75
  :header-rows: 1

  * - Key
    - Default value
    - Unit
    - Details
  * - type
    - \-
    - \-
    - Thruster
  * - name
    - \-
    - \-
    - The name of thruster.
  * - forceOffset
    - 0.0
    - N
    - Offset value of thruster's propulsive force.
  * - torqueOffset
    - 0.0
    - Nm
    - Offset value of thruster's torque.
  * - symbol
    - true
    - \-
    - Give true to show the symbol of thruster.

Rotor notation
--------------

Rotor apply propulsive force and torque to a robot moving through water. You can set as many as you want per link, and the Z axis+ direction are set as the default orientation with the link's local coordinate system. For setting rotor, add the below underneath the elements section of the link.

.. code-block:: yaml

      -
        type: Rotor
        name: Rotor
        forceOffset: 1.0
        torqueOffset: 0.1
        symbol: true

Rotor device has following parameters.


.. list-table::
  :widths: 20,12,8,75
  :header-rows: 1

  * - Key
    - Default value
    - Unit
    - Details
  * - type
    - \-
    - \-
    - Rotor
  * - name
    - \-
    - \-
    - The name of rotor.
  * - forceOffset
    - 0.0
    - N
    - Offset value of rotor's propulsive force.
  * - torqueOffset
    - 0.0
    - Nm
    - Offset value of rotor's torque.
  * - symbol
    - true
    - \-
    - Give true to show the symbol of rotor.

How to execute simulation
-------------------------

You can execute a simulation by clicking the start button on the simulation bar.
