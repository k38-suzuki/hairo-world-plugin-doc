ステップ6: サブクローラの制御
=============================

ステップ5の復習として、Crawlerの左右のサブクローラ部分を制御するコントローラを作成してみましょう。

.. _step6-ref1:

ヒント
------

 1. ファイル名は"TrackController2.cpp"としてください。
 2. 前左サブクローラ（TRACK_FL）と前右サブクローラ（TRACK_FR）を左スティックで動かすシンプルコントローラを作成してください。
 3. CMakeLists.txtにTrackController2.cppを追記してください。このときモジュール名は"CrawlerTutorial_TrackController2"としてください。
 4. TrackControllerのコントローラモジュールにCrawlerTutorial_TrackController2.soを設定してください。
 5. シミュレーションを実行して、サブクローラの動きを確認してください。
