
rqt_hairo_worldのビルド
=======================

ROS環境のビルド
---------------

ROSのビルドについては、`こちら <http://wiki.ros.org/ja/noetic/Installation/Ubuntu>`_ のページを参照してください。

パッケージソースの追加
----------------------

作成したワークスペースの "src" ディレクトリ（例：catkin_ws/src）内に、以下のコマンドでソースコードリポジトリをクローンします。 ::

 git clone https://github.com/k38-suzuki/rqt_hairo_world.git

このリポジトリには、以下のパッケージが含まれています。

 * rqt_bag_player : ROSのトピックを保存・再生するためのパッケージ
 * rqt_gen2 : Kinova社のGen2に対して指示するためのパッケージ
 * rqt_jackal : Clearpath社のJackalに対して指示するためのパッケージ
 * rqt_joy_publisher : ゲームパッドの値をトピックをパブリッシュするためのパッケージ
 * rqt_minio_client : オブジェクトストレージMinIOのオブジェクトを操作するためのパッケージ
 * rqt_netem : 広域ネットワークのプロパティを模擬してプロトコルをテストするためのパッケージ
 * rqt_ping : ネットワークのテストのためのパッケージ
 * rqt_ur : ユニバーサルロボット社のUR5eに対して指示するためのパッケージ

rqt_gen2を使用する場合は、併せて次のソースコードリポジトリをクローンしてください。 ::

 git clone https://github.com/Kinovarobotics/kinova-ros.git

依存パッケージのインストール
----------------------------

rqt_hairo_worldに含まれるいくつかのパッケージには、ビルド・実行に必要となる依存パッケージがあります。
必要に応じて、それらの依存パッケージをインストールしておきます。

rqt_minio_clientを使用する場合は、rqt_hairo_world内のrqt_minio_clientのソースディレクトリに移動し対応するスクリプトを実行します。 ::

 misc/script/install-requisites-ubuntu-20.04.sh

を実行します。

rqt_netemを使用する場合は、rqt_hairo_world内のrqt_netemのソースディレクトリに移動し対応するスクリプトを実行します。 ::

 misc/script/setup.sh

を実行してください。

ビルド
------

設定が完了したら、ビルドを行いましょう。ワークスペースのディレクトリ下（例：catkin_ws）で、以下のコマンドでビルドできます。 ::

 catkin_make

