HAIROWorldプラグイン関連パッケージのビルド
==========================================

ROS環境のChoreonoidのビルド
---------------------------

HAIROWorldプラグインとROSを連携させるために、まずROS環境でChoreonoid関連パッケージをビルドします。
ROSのインストールとChoreonoid関連パッケージのビルドについては、以下のページを参照してください。

 1.  `ROSのインストール <https://choreonoid.org/ja/manuals/latest/ros/install-ros.html>`_ 
 2.  `Choreonoid関連パッケージのビルド <https://choreonoid.org/ja/manuals/latest/ros/build-choreonoid.html>`_ 
 3.  `ROS環境におけるChoreonoidの実行 <https://choreonoid.org/ja/manuals/latest/ros/run-choreonoid.html>`_ 

ROS環境のChoreonoidへのHAIROWorldプラグインの導入
-------------------------------------------------

ROS環境のChoreonoidのソースディレクトリ直下にあるextディレクトリ（例：catkin_ws/src/choreonoid/ext）に移動して、 以下のコマンドでHAIROWorldPluginを取得します。 ::

 git clone https://github.com/k38-suzuki/hairo-world-plugin.git

依存パッケージのインストール
----------------------------

HAIROWorldプラグインのビルド・実行に必要となる依存パッケージをインストールしておきます。

HAIROWorldプラグインのソースディレクトリに移動し対応するスクリプトを実行します。Ubuntu 20.04であれば、 ::

 sudo ./misc/script/install-requisites-ubuntu-20.04.sh

を実行します。

Ubuntu 18.04は ::

 sudo ./misc/script/install-requisites-ubuntu-18.04.sh

を実行してください。

ビルド
------

設定が完了したら、ビルドを行いましょう。ワークスペース内のディレクトリであれば、以下のコマンドでビルドできます。 ::

 catkin build

