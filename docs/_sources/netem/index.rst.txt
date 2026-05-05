NetEm Plugin
===============

This section explains how to configure communication interference effects using the Network Emulator.

.. note::
   The Network Emulator is used when controlling a robot within the Choreonoid world via Ethernet using OpenRTM, ROS, or similar frameworks.

Creating and Configuring the BodyNetEmController Item
-----------------------------------------------------

First, create a **BodyNetEmController** item. In the Item Tree view, select the body that will perform communication during the simulation, then select **File** > **New** > **BodyNetEmController** from the main menu.

The generated BodyNetEmController item will be placed as a child item of the selected body. If there are multiple bodies performing communication, place one BodyNetEmController item as a child for each body.

Next, configure the parameters for the BodyNetEmController item. The parameters are as follows:

.. list-table::
  :widths: 20,12,12,75
  :header-rows: 1

  * - Parameter
    - Default Value
    - Unit
    - Meaning
  * - Interface
    - lo
    - \-
    - Specifies the wired or wireless interface used for communication.
  * - IFB Device
    - ifb0
    - \-
    - Specifies the virtual network device used for inbound communication. Usually, this does not need to be changed.
  * - Destination IP Address
    - \-
    - \-
    - Specifies the destination IP address for packets. Enter the IP address of the intended communication target for the body. You must include a prefix length (e.g., ``xxx.xxx.xxx.xxx/32``). Using ``/32`` targets only the specific IP address specified.

This completes the configuration of the BodyNetEmController item.

Creating and Configuring the MultiCollider Item
-----------------------------------------------

The **MultiCollider** item defines the regions within the Choreonoid world where communication interference is applied. Select **File** > **New** > **MultiCollider** from the main menu and specify the type as "**Communication Interference**" to generate it. Place the generated MultiCollider item as a child of the World item.

.. note::
   When using multiple MultiCollider items, their target areas may overlap. If an overlap occurs, the settings of the MultiCollider item located lower in the Item Tree view will take precedence.

The parameters for the MultiCollider item are as follows:

.. list-table::
  :widths: 20,12,12,75
  :header-rows: 1

  * - Parameter
    - Default Value
    - Unit
    - Meaning
  * - Inward Delay
    - 0
    - ms
    - Specifies the delay time when receiving packets.
  * - Inward Latency
    - 0
    - kbit
    - Specifies the latency (upper limit of communication speed) when receiving packets.
  * - Inward Packet Loss
    - 0
    - %
    - Specifies the packet loss rate when receiving packets.
  * - Outward Delay
    - 0
    - ms
    - Specifies the delay time when sending packets.
  * - Outward Latency
    - 0
    - kbit
    - Specifies the latency (upper limit of communication speed) when sending packets.
  * - Outward Packet Loss
    - 0
    - %
    - Specifies the packet loss rate when sending packets.
  * - Shape
    - Box
    - \-
    - Specifies the shape of the region (Box/Cylinder/Sphere).
  * - Size
    - 1.0, 1.0, 1.0
    - m, m, m
    - Specifies the XYZ size of the region (only if Shape is Box).
  * - Radius
    - 1.0
    - m
    - Specifies the radius of the region (only if Shape is Cylinder or Sphere).
  * - Height
    - 1.0
    - m
    - Specifies the height of the region (only if Shape is Cylinder).
  * - Position
    - 0, 0, 0
    - m, m, m
    - Specifies the XYZ coordinates of the region's position.
  * - RPY
    - 0, 0, 0
    - deg, deg, deg
    - Specifies the orientation of the region (Roll, Pitch, Yaw).
  * - Diffuse Color
    - 0, 0, 0
    - \-, -, -
    - Specifies the RGB diffuse color of the region.
  * - Transparency
    - 0
    - \-
    - Specifies the transparency of the region.

Running the Simulation
----------------------

Run the simulation as usual from the Simulation Bar. If successful, the communication interference effects will be applied based on the MultiCollider settings. You can verify the status of these effects using the ``ping`` command.
