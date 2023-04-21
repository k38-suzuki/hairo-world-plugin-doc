.. jaea-doc documentation master file, created by
   sphinx-quickstart on Thu Feb  6 18:47:13 2020.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

お知らせ
========

2022年3月22日の更新で、一部プラグイン名を変更しました。
（旧）FluidDynamicsPlugin　→　（新）CFDPlugin
（旧）TCPlugin　→　（新）NetEmPlugin

これに伴い、更新前のバージョンで作成されたプロジェクト ``（*.cnoid）`` の読み込みができなくなります。
つきましては、各機能のページ上部のお知らせを確認してください。

HAIROWorldPluginマニュアル
==========================

　このサイトでは、日本原子力研究開発機構が開発したChoreonoidの拡張機能「HAIROWorldPlugin」の使い方を説明します。
詳しく知りたい方は `こちら <https://jopss.jaea.go.jp/search/servlet/search?5070343>`_ をクリックしてください。

.. toctree::
   :maxdepth: 2

   about/index
   install/index
   cfd/index
   netem/index
   visual/index
   motion/index
   collision/index
   phits/index   
   body/index   
   file/index
   bookmark/index
   joystick/index
   ompl/index
   ros/index
   paper/index
   update/index
   en/index

以下の画像をクリックすると紹介動画が再生されます。

.. image:: images/title.png
   :target: https://naraha.jaea.go.jp/information/files/2020/1211/movie/hairoworld2.mp4

対応プラットフォーム
====================

　HAIROWorldPluginは、Choreonoid開発版上で動作することを確認しており、今後もChoreonoidの最新のバージョンに対応していく予定です。対応OSはUbuntu18.04 LTSとUbuntu20.04 LTSです。他のOS、ディストリビューション、バージョン、アーキテクチャについては、公式にはサポートしておりません。Ubuntuベースの他のディストリビューションでは、ビルドをうまく通せば動作する可能性もありますが、保証はできません。また、VMWare・VirtualBox等の仮想マシンでの使用についても動作を保証できませんので、予めご了承ください。

免責事項
========

　HAIROWorldPluginの使用に伴うトラブルやその他の損失・損害について当機構では一切の責任を負いません。予めご了承ください。

.. Indices and tables
.. ==================

.. * :ref:`genindex`
.. * :ref:`modindex`
.. * :ref:`search`
