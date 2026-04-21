ステップ4: ゲームパッドによるヒンジの制御
=========================================

ステップ3の復習として、Crawlerの左右のヒンジ部分を制御するコントローラを作成してみましょう。

まずプロジェクトを保存しておきましょう。ファイル名は "step4.cnoid" として、プロジェクトディレクトリに保存しておくとよいかと思います。

.. _step4-ref1:

ヒント
------

 1. ファイル名は"HingeController.cpp"としてください。
 2. 左ヒンジ（HINGE_L）と右ヒンジ（HINGE_R）を十字キー（上下）で動かすシンプルコントローラを作成してください。
 3. CMakeLists.txtにHingeController.cppを追記してください。このときモジュール名は"CrawlerTutorial_HingeController"としてください。
 4. シンプルコントローラを生成して、名前を"HingeController"としてください。
 5. HingeControllerをCrawlerの子アイテムに設定してください。
 6. HingeControllerのコントローラモジュールにCrawlerTutorial_HingeController.soを設定してください。
 7. シミュレーションを実行して、ヒンジの動きを確認してください。
