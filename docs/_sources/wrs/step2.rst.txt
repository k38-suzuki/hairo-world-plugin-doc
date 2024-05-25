
ステップ２：ドローンのシミュレーション
======================================

ここでは、ドローンのシミュレーションの設定を行います。

コントローラのソースコード
--------------------------

ドローンのコントローラを作成します。プロジェクトディレクトリ内に"DroneController.cpp"を作成して、以下を記述してください。
`ドローンのコントローラの記述 <https://raw.githubusercontent.com/k38-suzuki/hairo-world-plugin/main/sample/tutorial/Drone/DroneController.cpp>`_ を参照してください。

CMakeLists.txtの記述
--------------------

.. highlight:: cmake

CMakeLists.txtの記述については、
`CMakeLists.txtの記述 <https://choreonoid.org/ja/manuals/latest/simulation/tank-tutorial/step2.html#cmakelists-txt>`_ を参照してください。
ここでは、コントローラ名に"DroneTutorial_DroneController"、ソースファイルに"DroneController.cpp"を記述します。 ::

 choreonoid_add_simple_controller(DroneTutorial_DroneController DroneController.cpp)
 target_link_libraries(DroneTutorial_DroneController CnoidCFDPlugin)

2行目の"target_link_libraries"では、コントローラ内でロータを使用するためにCFDプラグインの共有ライブラリをコントローラにリンクしています。

コントローラのビルド
--------------------

`コントローラのビルド <https://choreonoid.org/ja/manuals/latest/simulation/tank-tutorial/step2.html#id6>`_ を参照してください。

コントローラの導入
------------------

`コントローラの導入 <https://choreonoid.org/ja/manuals/latest/simulation/tank-tutorial/step2.html#simulation-tank-tutorial-introduce-controller>`_ を参照してください。

CFDシミュレータアイテムの作成
-----------------------------

`CFDシミュレータの作成と設定 <https://k38-suzuki.github.io/hairo-world-plugin-doc/cfd/cfd.html#cfd>`_ を参照してください。

マルチコライダアイテムの作成
----------------------------

`マルチコライダアイテムの作成と設定 <https://k38-suzuki.github.io/hairo-world-plugin-doc/cfd/cfd.html#id1>`_ を参照してください。

プロパティの設定
----------------

マルチコライダアイテムの「サイズ」に10 10 10、「透過度」に1.00を設定してください。

シミュレーションの実行
----------------------

`シミュレーションの実行 <https://k38-suzuki.github.io/hairo-world-plugin-doc/cfd/cfd.html#id5>`_ を参照してください。

