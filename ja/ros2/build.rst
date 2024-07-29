HAIROWorldプラグイン関連パッケージのビルド
==========================================

ROS2環境のChoreonoidのビルド
----------------------------

HAIROWorldプラグインとROS2を連携させるために、まずROS環境でChoreonoid関連パッケージをビルドします。
ROS2のインストールとChoreonoid関連パッケージのビルドについては、以下のページを参照してください。

 1.  `ROS 2のインストール <https://choreonoid.org/ja/manuals/latest/ros2/install-ros2.html>`_ 
 2.  `Choreonoid関連パッケージのビルド <https://choreonoid.org/ja/manuals/latest/ros2/build-choreonoid.html>`_ 
 3.  `ROS環境におけるChoreonoidの実行 <https://choreonoid.org/ja/manuals/latest/ros2/run-choreonoid.html>`_ 

パッケージソースの追加
----------------------

作成したワークスペースの "src" ディレクトリ（例：ros2_ws/src）内で、以下のコマンドでソースコードリポジトリをクローンします。 ::

 git clone https://github.com/k38-suzuki/hairo-world-plugin.git choreonoid/ext/hairo-world-plugin
 git clone https://github.com/k38-suzuki/choreonoid_ros2_sample_drone_tutorial.git

１つ目のコマンドが成功すると、ros2_ws/src/choreonoid/extディレクトリ下にhairo-world-pluginがクローンされます。

２つ目のコマンドが成功すると、ros2_ws/srcディレクトリ下にchoreonoid_ros2_sample_drone_tutorialがクローンされます。

依存パッケージのインストール
----------------------------

HAIROWorldプラグインのビルド・実行に必要となる依存パッケージをインストールしておきます。

HAIROWorldプラグインのソースディレクトリに移動し対応するスクリプトを実行します。 ::

 misc/script/install-requisites-ubuntu-22.04.sh

を実行します。

ビルド
------

設定が完了したら、ビルドを行いましょう。ワークスペース内のディレクトリであれば、以下のコマンドでビルドできます。 ::

 colcon build --symlink-install

ビルド後のChoreonoidにHAIROWorldプラグインがうまく読み込まれない場合は、ros2_ws内のbuild、install、logのディレクトリを削除して、上記のコマンドをもう一度実行してみてください。

ビルドが完了したら、ワークスペースセットアップスクリプトを取り込みます。 ::

 source $HOME/ros2_ws/install/setup.bash

以上で、準備は終了です。

