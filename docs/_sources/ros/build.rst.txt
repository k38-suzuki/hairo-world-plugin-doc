HAIROWorldプラグイン関連パッケージのビルド
==========================================

ROS環境のChoreonoidのビルド
---------------------------

HAIROWorldプラグインとROSを連携させるために、まずROS環境でChoreonoid関連パッケージをビルドします。
ROSのインストールとChoreonoid関連パッケージのビルドについては、以下のページを参照してください。

 1. ROSのインストール (https://choreonoid.org/ja/manuals/latest/ros/install-ros.html)
 2. Choreonoid関連パッケージのビルド (https://choreonoid.org/ja/manuals/latest/ros/build-choreonoid.html)
 3. ROS環境におけるChoreonoidの実行 (https://choreonoid.org/ja/manuals/latest/ros/run-choreonoid.html)
 
パッケージソースの追加
----------------------

作成したワークスペースの "src" ディレクトリ（例：catkin_ws/src）内に、以下のソースコードリポジトリをクローンします。 ::

 https://github.com/k38-suzuki/hairo_world_plugin_ros.git
 
このリポジトリには、以下のパッケージが含まれています。

 * hairo_world_plugin_ros_samples : HAIROWorldプラグインでROSを使用するサンプル（Husky, Jackal）
 * hairo_world_plugin_joy : サンプル（Husky, Jackal）をジョイスティック（ゲームパッド）で操作するためのROSノード
 
ROS環境のChoreonoidへのHAIROWorldプラグインの導入
-------------------------------------------------

ROS環境のChoreonoidのソースディレクトリ直下にあるextディレクトリ（例：catkin_ws/src/choreonoid/ext）に移動して、 以下のコマンドでHAIROWorldPluginを取得します。 ::

 git clone https://github.com/k38-suzuki/hairo-world-plugin.git

依存パッケージのインストール
----------------------------

HAIROWorldプラグインのビルド・実行に必要となる依存パッケージをインストールしておきます。

HAIROWorldプラグインのソースディレクトリに移動し対応するスクリプトを実行します。Ubuntu 20.04であれば、 ::

 misc/script/install-requisites-ubuntu-20.04.sh

を実行します。

Ubuntu 18.04は ::

 misc/script/install-requisites-ubuntu-18.04.sh

を実行してください。

なお、OS上でROSとは独立して既に最新のChoreonoidをインストールしている場合この作業は適用済みのはずですので、あらためて実行する必要はありません。

ビルド
------

設定が完了したら、ビルドを行いましょう。ワークスペース内のディレクトリであれば、以下のコマンドでビルドできます。 ::

 catkin build

