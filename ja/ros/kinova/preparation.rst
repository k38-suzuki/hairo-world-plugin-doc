準備
====

ROSとChoreonoid関連パッケージのセットアップ
-------------------------------------------
本チュートリアルの実施にあたっては、まず `ROSのインストール <https://choreonoid.org/ja/manuals/latest/ros/install-ros.html>`_ と `Choreonoid関連パッケージのビルド <https://choreonoid.org/ja/manuals/latest/ros/build-choreonoid.html>`_ を行っておく必要があります。これらのページの手順に従ってインストールやビルドを行い、  `ROS環境におけるChoreonoidの実行 <https://choreonoid.org/ja/manuals/latest/ros/run-choreonoid.html>`_ が実行できることを確認しておいてください。

なお、 `パッケージソースの追加 <https://k38-suzuki.github.io/hairo-world-plugin-doc/ros/build.html#id1>`_ については実行する必要はありません。（もちろん、導入されていても特に問題はありません。）

ダウンロードとビルド
--------------------

本チュートリアルでは、catkinワークスペースまでのパスは "<catkin_ws>" として表記しますので、適宜読み替えてください。なお、ワークスペース自体の名前は"catkin_ws"で無くても問題ありません（例えば"choreonoid_ws"等）。プロジェクトごとにワークスペースを分けてお使いになることをお勧めします。
               
まずはcatkinワークスペースの下に、"choreonoid_ros_gen2"、"kinova-ros"リポジトリをダウンロード（git clone）します。 ::

 mkdir -p <catkin_ws>/src
 cd <catkin_ws>/src
 git clone https://github.com/k38-suzuki/choreonoid_ros_gen2.git
 git clone https://github.com/Kinovarobotics/kinova-ros.git

最後に、 `catkin_make <http://wiki.ros.org/catkin/commands/catkin_make>`_ もしくは、 `catkin tools <https://catkin-tools.readthedocs.io/en/latest/>`_ を使ってパッケージのビルドを行いましょう。ここでは、 `catkin tools <https://catkin-tools.readthedocs.io/en/latest/>`_ を利用します。::

  cd <catkin_ws>
  catkin build

以上で、パッケージのダウンロードとビルドまで完了です。

