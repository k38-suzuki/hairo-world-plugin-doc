kinova-ros連携版 Gen2チュートリアル
===================================

本チュートリアルでは、HAIROWorldPluginのサンプルモデルのひとつである "Gen2" モデルを対象とし、"kinova-ros"を介して"Gen2"モデルを動かすため方法を説明します．"Gen2"は、Kinova社（カナダ）の多関節ロボットアームで、本チュートリアルで用いる"Gen2"モデルは、Kinova社が公開しているROSパッケージ `kinova-ros <https://github.com/Kinovarobotics/kinova-ros>`_ 内にある7自由度のGen2（j2s7s300）のメッシュファイル及びURDFファイルを参考に、ChoreonoidのBodyファイルとして再構成したものです。なお、このパッケージには、kinova-rosのパッケージで提供されるメッセージ（kinova_msgs::JointVelocityおよびkinova_msgs::PoseVelocity）のパブリッシャは含まれませんのでご注意ください。

本チュートリアルでは、環境のセットアップと実行方法を説明します。環境のセットアップについて、"Gen2"モデルが必要無い方は「 ROSとの連携 」に戻り、項目の上から順番にお読みください。

.. toctree::
   :maxdepth: 3

   preparation
   example1

