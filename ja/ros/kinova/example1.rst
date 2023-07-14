実行
====

ここでは，予め用意している `launchファイル <http://wiki.ros.org/roslaunch>`_ について説明します。

関節位置制御（Joint Position Control）によるGen2の操作
------------------------------------------------------
関節位置制御でGen2を操作する場合、下記のコマンドでサンプルを起動することができます。 ::

 roslaunch choreonoid_ros_gen2 gen2_joint.launch

gen2_joint.launchを起動すると、Choreonoidが起動し、関節位置制御でGen2を動かせる状態になります。kinova-rosパッケージで定義されているkinova_msgs::JointVelocityのトピックをパブリッシュすることで、Gen2の各関節の速度を指定できます。

デカルト位置制御（Cartesian Position Control）によるGen2の操作
--------------------------------------------------------------

デカルト位置制御でGen2を操作する場合、下記のコマンドでサンプルを起動することができます。 ::

 roslaunch choreonoid_ros_gen2 gen2_cartesian.launch

gen2_cartesian.launchを起動すると、Choreonoidが起動し、デカルト位置制御でGen2を動かせる状態になります。kinova-rosパッケージで定義されているkinova_msgs::PoseVelocityのトピックをパブリッシュすることで、Gen2の手先の位置・姿勢を指定できます。

