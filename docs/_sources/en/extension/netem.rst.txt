
NetEmPlugin
===========

This section explains how to configure communication disruption effects using a network emulator.

.. note::
  | A network emulator can be used when controlling robots within the Choreonoid world via Ethernet using OpenRTM, ROS, or similar.

Creating and Configuring a Network Emulator Item
------------------------------------------------

Here, we'll use Choreonoid's standard simulator item, "AIST Simulator." To generate it, select "File" - "New" - "Network Emulator" from the main menu. The generated network emulator should be placed as a child item of the AIST Simulator item.

Creating and Configuring a Multi-Collider Item
----------------------------------------------

A Multi-Collider item defines the area within the Choreonoid world where communication disruption will be applied. To generate one, select "File" - "New" - "Multi-Collider" from the main menu and specify the type as "Communication Disruption." The generated Multi-Collider item should be placed as a child item of the World item. The example below shows four Multi-Collider items generated as "Traffic0" to "Traffic3." By creating multiple Multi-Collider items this way, you can define more detailed areas for communication disruption within the Choreonoid world.

.. note::
  | When using multiple Multi-Collider items, their target ranges may overlap. If an overlap occurs, the settings of the Multi-Collider item registered lower in the item tree view will be applied.

You can toggle the visibility of these TC items using the checkboxes in the item tree view. Additionally, hidden Multi-Collider items are excluded from the simulation.

The parameters for a Multi-Collider item are as follows:

.. list-table::
  :widths: 20,12,12,75
  :header-rows: 1

  * - Parameter
    - Default Value
    - Unit
    - Meaning
  * - Inbound Delay
    - 0
    - ms
    - Specifies the delay when receiving packets.
  * - Inbound Latency
    - 0
    - kbit\s
    - Specifies the latency (upper limit of communication speed) when receiving packets.
  * - Inbound Packet Loss
    - 0
    - %
    - Specifies the packet loss rate when receiving packets.
  * - Outbound Delay
    - 0
    - ms
    - Specifies the delay when sending packets.
  * - Outbound Latency
    - 0
    - kbit\s
    - Specifies the latency (upper limit of communication speed) when sending packets.
  * - Outbound Packet Loss
    - 0
    - %
    - Specifies the packet loss rate when sending packets.
  * - Source IP Address
    - 0.0.0.0
    - \-
    - Specifies the IP address to limit the source of packets.
  * - Destination IP Address
    - 0.0.0.0
    - \-
    - Specifies the IP address to limit the destination of packets.
  * - Shape
    - Box
    - \-
    - Specifies the shape of the area (Box/Cylinder/Sphere).
  * - Size
    - 1.0, 1.0, 1.0
    - m, m, m
    - Specifies the size of the area in XYZ (only for Box shape).
  * - Radius
    - 1.0
    - m
    - Specifies the radius of the area (only for Cylinder/Sphere shapes).
  * - Height
    - 1.0
    - m
    - Specifies the height of the area (only for Cylinder shape).
  * - Position
    - 0, 0, 0
    - m, m, m
    - Specifies the position of the area in XYZ.
  * - RPY
    - 0, 0, 0
    - deg, deg, deg
    - Specifies the orientation of the area in Roll, Pitch, Yaw.
  * - Diffuse Color
    - 0, 0, 0
    - \-, -, -
    - Specifies the diffuse color of the area in RGB.
  * - Transparency
    - 0
    - \-
    - Specifies the transparency of the area.

Running the Simulation
----------------------

Run the simulation as usual from the simulation bar. If the simulation is successful, communication disruption effects will be applied based on the Multi-Collider item settings. You can verify the application of these effects using the ping command.
