サンプルの実行
==============

前節までの設定が完了したら、下記のコマンドでサンプルを起動することができます。

Huskyの場合 ::

 roslaunch hairo_world_plugin_ros_samples husky.launch
 
Jackalの場合 ::

 roslaunch hairo_world_plugin_ros_samples jackal.launch

Husky及びJackalの操作方法は以下のとおりです。

DUALSHOCK 4の場合

 * 左スティック(L_STICK) ->　車体の操作（前進／後退／左旋回／右旋回）
 * 左ボタン(LB) -> デッドマンスイッチ（走行速度が1倍）
 * 右ボタン(RB) -> デッドマンスイッチ（走行速度が2倍）

例1：　左ボタンを押しながら、左スティックを前へ倒す -> 1倍速で車体が前進

例2：　右ボタンを押しながら、左スティックを左へ倒す -> 2倍速で左旋回

