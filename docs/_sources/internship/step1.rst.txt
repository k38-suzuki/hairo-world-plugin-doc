ステップ1: シミュレーションプロジェクトの作成
=============================================

まずはシミュレーション対象となるモデルをChoreonoid上に読み込んで、シミュレーション用のプロジェクトを作成します。この手順の詳細は `シミュレーションプロジェクトの作成 <https://choreonoid.org/ja/documents/latest/simulation/simulation-project.html>`_ を参照して下さい。ここでは今回必要な作業を具体的に説明していきます。

.. contents:: 目次
   :local:
   :depth: 2

.. highlight:: sh

.. _step1-ref1:

Choreonoidの起動
----------------

まずChoreonoidを起動しましょう。

どのように起動してもよいのですが、本チュートリアルでは説明の都合上、コマンドライン端末から起動するものとします。また、説明を簡潔にするため、Choreonoidビルド時にビルドディレクトリ内に生成される実行ファイルを直接実行するものとします。この場合、"make install" によるインストール操作を行う必要はありません。

例えば、"build" というビルドディレクトリでビルドを行った場合は、端末上で以下のようにしてChoreonoidを起動できます。 ::

 cd [ソースディレクトリ]
 ./build/bin/choreonoid

この場合、Choreonoidに付属のモデルファイルや、本チュートリアルで新たに作成するコントローラのファイル等は、Choreonoidのソース／ビルドディレクトリ内のものが使われるようになります。この方が、ディレクトリがひとつにまとまっていて分かりやすいかと思います。

.. note:: もちろん、"make install" によって"/usr/local"等のディレクトリにインストールされたファイルを使ってもOKですので、必要であればそのようにして下さい。この場合、コントローラの作成時にも"make install"を実行して、使用するコントローラのファイルもインストール先に格納されているものが対象となりますので、その点ご注意下さい。
.. note:: Linuxの基本的な使用方法については、 `Linuxの基本的な使用方法について <https://choreonoid.org/ja/documents/latest/tips/howto-use-commands.html>`_ を参照ください。


.. _step1-ref2:

ワールドアイテムの作成
----------------------

Choreonoidを起動したら、まずワールドアイテムを作成しましょう。メインメニューの「ファイル」-「新規」から「ワールド」を選択します。すると「新しいワールドアイテムの生成」ダイアログが出ますので、ここで「生成」ボタンを押します。すると以下の図のように、 `アイテムツリービュー <https://choreonoid.org/ja/documents/latest/basics/mainwindow.html#basics-mainwindow-itemtreeview>`_ 上に "World" という名前のアイテムが表示されたかと思います。

.. image:: images/step1-1.png

ワールドアイテムはひとつの仮想世界に対応するものであり、シミュレーションを実行するにあたって必ず生成しておく必要があります。


.. _step1-ref3:

Crawlerモデルの読み込み
-----------------------

今回のシミュレーション対象となる、 :ref:`tutorial-1` を読み込みます。Crawlerモデルは遠隔操作ロボットのモデルであり、2軸のカメラ台座と左右2つのクローラ、左右2つのサブクローラで構成されます。また、ライト（光源）とカメラも備えています。

まず、アイテムツリービュー上で先ほど作成したWorldアイテムをクリックして、選択状態にしておきましょう。このようにしておくことで、新たに読み込むアイテムがWorldの子アイテムとなります。

次にメインメニューの「ファイル」-「読み込み」から「ボディ」を選択します。するとファイル読み込み用のダイアログが表示されますので、ここで事前に作成したCrawlerモデルファイルを選択します。

Choreonoidに入っているモデルを開くにあたっては、ダイアログ左側のサイドバーを活用しましょう。ここには下図のように "choreonoid-x.x" （x.xはバージョン番号）もしくは "choreonoid" というディレクトリが表示されているかと思います。

.. image:: images/step1-2.png
    :scale: 80%

ここでは "choreonoid-2.3" を選択していますが、これがChoreonoidのshareディレクトリに対応します。これを選択すると、ダイアログの右側にshareディレクトリの内容が表示され、Choreonoidに入っているモデルを読み込むことができます。

モデルファイルが正常に読み込まれると、アイテムツリービューには以下のように表示されるはずです。

.. image:: images/step1-3.png

ロボットや環境のモデルはChoreonoid上では `ボディモデル <https://choreonoid.org/ja/documents/latest/handling-models/bodymodel.html>`_ と呼ばれており、これはアイテムツリービュー上で「ボディアイテム」として管理されます。今回読み込んだCrawlerモデルに対応するボディアイテムが、アイテムツリービュー上で"Crawler"と表示されています。

ここで、CrawlerアイテムはWorldアイテムの一段右側に表示されている（＝Worldアイテムの子アイテムとなっている）ことが重要です。この配置関係をとることで、CrawlerモデルがWorldの仮想世界に所属していると認識されるからです。Crawlerモデルの読み込み時にWorldアイテムが選択状態となっていれば、この配置になっているはずですが、そうでない場合は、アイテムの `移動 <https://choreonoid.org/ja/documents/latest/basics/item.html#basics-item-move>`_ 操作（CrawlerモデルをドラッグしてWroldアイテムの位置でドロップする）等を行って、この配置となるようにして下さい。

また、上図のようにCrawlerアイテムにチェックが入っているかを確認して下さい。もし入っていない場合は、アイテムのチェックボックスをクリックしてチェックを入れるようにして下さい。

Crawlerアイテムにチェックが入っていると、このモデルがシーンビュー上に表示されます。

.. image:: images/step1-4.png

ここでシーンビューに対する `視点の変更 <https://choreonoid.org/ja/documents/latest/basics/sceneview.html#basics-sceneview-viewpoint>`_ 操作を行って、Crawlerモデルが見やすく表示されるようにしておくとよいでしょう。例えばシーンビュー上でマウスのホイールを操作することで、視点を前後に移動させ、モデルを大きく表示することができます。上図もそのような操作を適用したものとなっています。


.. _step1-ref4:

床モデルの読み込み
------------------

Crawlerモデルを読み込みましたが、このままではシミュレーション実行時にCrawlerが重力によってどこまでも落下していってしまいます。そこでCrawlerモデルを支えるための環境モデルとして、床のモデルも読み込んでおきましょう。

先ほどと同様に、Worldアイテムを選択した状態でメインメニューの「ファイル」-「読み込み」-「ボディ」を選択し、Choreonoidインストール先の "share/model/misc" ディレクトリ内の "floor.body" というファイルを読み込んで下さい。するとアイテムツリービューは以下のようになるかと思います。

.. image:: images/step1-5.png

Crawlerアイテムと同様に、

* Worldアイテムの子アイテムとなっているか
* Floorアイテムのチェックが入っているか

を確認して下さい。

チェックが入っていれば、シーンビュー上で以下の図のように床のモデル（青い部分）も表示されるかと思います。

.. image:: images/step1-6.png

これでモデルの準備ができました。

なお、今回は各モデルの初期状態（位置・姿勢）としてデフォルト（読み込み時）のものをそのまま使用していますが、初期状態を変更したい場合は、 `初期状態の設定 <https://choreonoid.org/ja/documents/latest/simulation/simulation-project.html#simulation-setting-initial-status>`_ を参照して下さい。

.. note:: 床のモデルは必ずしもシーンビュー上に表示する必要はありません。今回使用するFloorモデルはZ=0の平面に相当するシンプルなものなので、デフォルトの床グリッドの表示があれば十分かもしれません。その場合はFoorアイテムのチェックを外して、表示をオフとしてもOKです。モデルのアイテムがWorldアイテムの子アイテムとなっていれば、表示のオン／オフに関わらず、シミュレーションにおいては存在するものとみなされます。


.. _step1-ref5:

シミュレータアイテムの作成
--------------------------

シミュレーションを行うためには、 `シミュレータアイテム <https://choreonoid.org/ja/documents/latest/simulation/concept.html#simulation-simulator-item>`_ を作成しておく必要があります。

今回は標準のシミュレータアイテムである "AISTシミュレータ" を使うことにしましょう。メインメニューの「ファイル」-「新規」から「AISTシミュレータ」を選択し、アイテムの生成を行って下さい。

生成したシミュレータアイテムは、モデルのアイテムと同様に、Worldアイテムの子アイテムとして配置しておきます。これにより、シミュレータアイテムのシミュレーション対象となるワールドを明示します。従って、上記のアイテム生成操作を行う際にも、Worldアイテムを選択状態にしておくとよいでしょう。生成したアイテムがアイテムツリービュー上で以下のように表示されていればOKです。

.. image:: images/step1-7.png


.. _step1-ref6:

プロパティの設定
----------------

シミュレーションを適切に実行するため、アイテムのプロパティ設定を行います。

まずCrawlerアイテムのプロパティ設定をしましょう。Crawlerアイテムを選択すると `アイテムプロパティビュー <https://choreonoid.org/ja/documents/latest/basics/mainwindow.html#basics-mainwindow-item-property-view>`_ 上にこのアイテムのプロパティ一覧が下図のように表示されます。

.. image:: images/step1-8.png

シミュレーションを行う際に関係するボディアイテムのプロパティとして、「自己干渉検出」があります。これはデフォルトでは false となっており、モデルのリンク同士で衝突が起きてもそこで止まらずにすり抜けていってしまいます。本チュートリアルではCrawlerモデルのカメラ台座と車体との衝突が想定されるため、このプロパティを true として自己干渉検出を有効にしておきましょう。

「自己干渉検出」プロパティの値として false が表示されている箇所をダブルクリックすると、 true か false を選択するコンボボックスが表示されるので、そこで true を選択してください。

シミュレーションを行う際には、シミュレータアイテムのプロパティも適切に設定しておく必要があります。今回はデフォルトの設定でOKですが、 `時間分解能の設定 <https://choreonoid.org/ja/documents/latest/simulation/simulation-project.html#simulation-time-step>`_ 、 `時間範囲の設定 <https://choreonoid.org/ja/documents/latest/simulation/execution-and-playback.html#simulation-time-range>`_ 、 `実時間との同期 <https://choreonoid.org/ja/documents/latest/simulation/execution-and-playback.html#simulation-realtime-sync>`_ 、 `シミュレーション結果の記録 <https://choreonoid.org/ja/documents/latest/simulation/execution-and-playback.html#simulation-result-recording>`_ 、 `デバイス状態の記録 <https://choreonoid.org/ja/documents/latest/simulation/execution-and-playback.html#simulation-device-state-recording>`_ 等の設定を行うことが可能です。


.. _step1-ref7:

プロジェクトの保存
------------------

ここまでの作業で、シミュレーションプロジェクトの土台を構築することができました。このタイミングで `プロジェクトの保存 <https://choreonoid.org/ja/documents/latest/basics/item.html#basics-project-save>`_ を行っておくとよいでしょう。

メインメニューの「ファイル」-「名前をつけてプロジェクトを保存」を選択し、表示されるダイアログでディレクトリやファイル名を指定して保存を行って下さい。ファイル名は今回は "step1.cnoid" などとし、本チュートリアルのステップごとにファイル名を分けて保存していくとよいかと思います。また、プロジェクト設定の変更後はこまめに上書き保存をしておくとよいでしょう。これを行うにあたっては、以下の図に示す「プロジェクト保存ボタンが便利です。

.. figure:: images/step1-9.png

.. note:: HAIROWorldPluginの "sample/tutorial/Crawler" 以下には、本チュートリアルのステップごとのプロジェクト内容を保存したファイル step1.cnoid 〜 step8.cnoid が収録されています。


.. _step1-ref8:

シミュレーションの実行
----------------------

とりあえずこの状態でシミュレーションを実行してみましょう。

以下に示すシミュレーションバーの「シミュレーション開始ボタン」を押して、シミュレーションを開始して下さい。

.. image:: images/step1-10.png

するとCrawlerモデルのカメラ台座が以下の図のように下向きに落ちていき、車体に当たったところで止まるかと思います。

.. image:: images/step1-11.png
    :scale: 50%

.. image:: images/step1-12.png
    :scale: 50%

これは、Crawlerモデルのカメラ台座関節を制御する `コントローラ <https://choreonoid.org/ja/documents/latest/simulation/concept.html#simulation-controller>`_ がないからです。この場合、関節はフリーの状態となっているため、ピッチ軸に関しては重力によるモーメントで回転してしまうというわけです。

関節がフリーの状態になっていることは、 `インタラクション機能 <https://choreonoid.org/ja/documents/latest/simulation/interaction.html>`_ を用いて直接確認することもできます。シーンビューを編集モードにして、カメラ台座部分をマウスでドラッグして引っ張ってみて下さい。カメラ台座を引っ張ることで容易に動かせることが確認できるかと思います。

このように、コントローラがなければ、モデルの姿勢を維持することもできません。 `コントローラの導入 <https://choreonoid.org/ja/documents/latest/simulation/howto-use-controller.html>`_ の `コントローラ無しの場合 <https://choreonoid.org/ja/documents/latest/simulation/howto-use-controller.html#controller-no-controller-case>`_ で紹介したように、ヒューマノイドロボットの場合にはロボットの前進が崩れ落ちてしまうほどです。

やはりロボットを動かすにはその制御を行うコントローラが必要ということで、次のステップからはコントローラを作成していきます。


.. _step1-ref9:

シミュレーションの停止
----------------------

次のステップに移る前に、シミュレーションを停止しておきましょう。以下の「シミュレーション停止ボタン」を押して、シミュレーションを終了させて下さい。

.. image:: images/step1-14.png

今後も、シミュレーション実行後はシミュレーションを終了させて、その後次のプロジェクトの構築を行うようにして下さい。
