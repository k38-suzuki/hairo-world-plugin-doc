
ROS2版choreonoid_joyの使い方
============================

パッケージの取得
----------------

ROS2に対応するchoreonoid_joyを利用したい場合は、 `こちら <https://github.com/k38-suzuki/choreonoid_joy2>`_ のROS2パッケージをビルドしてください。
joyトピックは次のコマンドでパブリッシュします。 ::

 $ ros2 run choreonoid_joy2 node

トピック名の変更
----------------

トピック名を変更したい場合（ここではjoyをjoy2へ変更）、次のコマンドでパブリッシュします。 ::

 $ ros2 run choreonoid_joy2 node --ros-args -p topic_name:=joy2

または、 ::

 $ ros2 run choreonoid_joy2 node --ros-args --remap joy:=/joy2

デバイスの変更
--------------

デバイスを変更したい場合（ここでは/dev/input/js0を/dev/input/js1へ変更）、次のコマンドでパブリッシュします。 ::

 $ ros2 run choreonoid_joy2 node --ros-args -p device_name:=/dev/input/js1

トピック名とデバイスの変更
--------------------------

トピック名とデバイスを同時に変更したい場合、次のコマンドでパブリッシュします。 ::

 $ ros2 run choreonoid_joy2 node --ros-args -p topic_name:=joy2 -p device_name:=/dev/input/js1
