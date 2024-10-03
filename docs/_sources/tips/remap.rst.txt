
ROS2版choreonoid_joyの使い方
============================

パッケージの取得
----------------

ROS2に対応するchoreonoid_joyを利用したい場合は、 `こちら <https://github.com/k38-suzuki/choreonoid_ros2_sample_drone_tutorial>`_ のROS2パッケージをビルドしてください。
joyトピックをパブリッシュするノード（choreonoid_joy_node）は次のコマンドで実行できます。::

 $ ros2 run choreonoid_ros2_sample_drone_tutorial choreonoid_joy_node

joyトピックのリマップ
---------------------

トピック名を変更したい場合（ここではjoyをjoy2へ変更）、次のコマンドでchoreonoid_joy_nodeを実行します。::

 $ ros2 run choreonoid_ros2_sample_drone_tutorial choreonoid_joy_node --ros-args --remap joy:=/joy2

