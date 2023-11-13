
Jackal
======

ここでは、Jackalの使い方を説明します。Jackalは、`Clearpath Robotics社のJackal <https://clearpathrobotics.com/jackal-small-unmanned-ground-vehicle/>`_ に指示するためのROSのノードです。

Jackalの起動
------------

Jackalを起動する手順は次のとおりです。

 1. 端末を起動する（Ctrl+Alt+T）
 2. roscoreを起動する（既に起動している場合は、この手順をとばす）
 3. ノードを起動する(コマンド：rosrun rqt_jackal jackal_node)

以上で起動は完了です。他のノードやrqt_joy_publisherなどからパブリッシュされたsensor_msgs/Joyトピックの値に基づいて、geometry_msgs/Twistトピックがパブリッシュされます。

