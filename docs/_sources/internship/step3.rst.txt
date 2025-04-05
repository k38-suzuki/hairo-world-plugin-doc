ステップ3: ゲームパッドによるカメラ台座の制御
=============================================

ステップ2では最小限の制御を行うコントローラを作成し、コントローラの導入方法を学びました。ステップ3ではもう少し複雑なコントローラを作成してみましょう。

.. contents:: 目次
   :local:
   :depth: 2
   
.. _step3-ref1:

コントローラのソースコード
--------------------------

.. highlight:: C++
   :linenothreshold: 7


今回作成するコントローラのソースコードを以下に示します。これはステップ2のTurretController1に対して、カメラ台座ヨー軸の制御とゲームパッド入力による指令値の変更を追加した内容となっています。 ::

 #include <cnoid/SimpleController>
 #include <cnoid/Joystick>
 
 using namespace cnoid;
 
 class TurretController2 : public SimpleController
 { 
     Link* joints[2];
     double q_ref[2];
     double q_prev[2];
     double dt;
     Joystick joystick;
 
 public:
     virtual bool initialize(SimpleControllerIO* io) override
     {
         joints[0] = io->body()->link("TURRET_Y");
         joints[1] = io->body()->link("TURRET_P");
 
         for(int i=0; i < 2; ++i){
             Link* joint = joints[i];
             joint->setActuationMode(Link::JointEffort);
             io->enableIO(joint);
             q_ref[i] = q_prev[i] = joint->q();
         }
 
         dt = io->timeStep();
       
         return true;
     }
 
     virtual bool control() override
     {
         static const double P = 200.0;
         static const double D = 50.0;
         static const int axisID[] = { 2, 3 };
 
         joystick.readCurrentState();
 
         for(int i=0; i < 2; ++i){
             Link* joint = joints[i];
             double q = joint->q();
             double dq = (q - q_prev[i]) / dt;
             double dq_ref = 0.0;
 
             double pos = joystick.getPosition(axisID[i]);
             if(fabs(pos) > 0.25){
                 double deltaq = 0.002 * pos;
                 q_ref[i] += deltaq;
                 dq_ref = deltaq / dt;
             }
      
             joint->u() = P * (q_ref[i] - q) + D * (dq_ref - dq);
             q_prev[i] = q;
         }
 
         return true;
     }
 };
 
 CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(TurretController2)

.. _step3-ref2:

コントローラのコンパイル
------------------------

上記のソースコードを入力・保存し、コンパイルを行いましょう。

手順はステップ2で行ったのと同様です。ソースコードを "TurretController2.cpp" というファイル名でプロジェクトディレクトリに保存し、CMakeLists.txt に以下の記述を追加して下さい。

.. code-block:: cmake

 choreonoid_add_simple_controller(CrawlerTutorial_TurretController2 TurretController2.cpp)

これでChoreonoid本体のコンパイル操作を行うと、このコントローラも同時にコンパイルされ、コントローラディレクトリ内に "CrawlerTutorial_TurretController2.so" というファイルが生成されます。

.. _step3-ref3:

コントローラの置き換え
----------------------

今度はこのコントローラをCrawlerモデルのコントローラとして使用するようにしましょう。

ステップ2で作成したプロジェクトがあるかと思いますので、そこのコントローラの設定だけを変えることにします。ステップ2で解説した :ref:`step2-ref7` を再度行って、今回作成した "CrawlerTutorial_TurretController2.so" のコントローラファイルに置き換えるようにして下さい。

これでコントローラの準備は完了です。この状態でプロジェクトを "step3.cnoid" といったファイル名で保存し直しておくとよいでしょう。

仮想ジョイスティックビューを使用する場合は、必ずビューが表示されている状態でプロジェクトを保存してください。Joystickオブジェクトは、生成時に接続されているJoystickの状態を確認します。プロジェクトファイルに仮想ジョイスティックビューの設定が保存されていれば、プロジェクトの読み込み時に仮想ジョイスティックビューが復元され、その後コントローラが作成され、コントローラが仮想ジョイスティックビューを認識します。また、コントローラアイテムのプロパティで、再読込の項をTrueにすると、シミュレーション開始時に、毎回コントローラを作成し直すように設定出来ます。

.. _step3-ref4:

カメラ台座の操作
----------------

シミュレーションを実行しましょう。

今回はゲームパッドでCrawlerモデルのカメラ台座を動かせるはずですので、動かしてみましょう。F310であれば、右下のアナログスティックをカメラ台座の操作に対応させていますので、この軸を操作して下さい。別の機種の場合は、どの軸が対応しているか、いろいろ動かして試してみて下さい。うまくいかない場合は、ソースコードの軸設定を変更しましょう。これは次節で解説します。

仮想ジョイスティックビューを使う場合は、キーボードで操作します。ビューに表示されているボタンは、それぞれ"E"、"S"、"D"、"F"が左スティック、 "I"、"J"、"K"、"L"が右スティックに対応しています。


.. image:: images/step3-1.png

この図とゲームパッドF310を見比べると、F310の主要な軸とボタンに対応していることが分かるかと思います。今回はキーボードの "J"、"L" でカメラ台座のヨー軸回転、"I"、"K" でピッチ軸回転を操作できることになります。

注意点として、 仮想ジョイスティックビューは **キーボードフォーカスが入っていないと機能しません。** このため、使用の際にはいったんこのビューをマウスでクリックするなどして、フォーカスを入れておく必要があります。操作している最中にシーンビューの視点を変えるなどの操作をした場合、フォーカスはそちらに行ってしまっているので、再度仮想ジョイスティックビューをクリックしてフォーカスを入れなおす必要があります。

Crawlerモデルのカメラ台座をうまく動かせましたでしょうか？このように、コントローラ次第で、様々な操作が可能となってきます。外部デバイスからの入力を取り込むことで、コントローラの幅も広がります。

.. _step3-ref5:

実装内容の解説
--------------

今回のTurretController2も、ステップ2で作成したTurretController1と同様に、PD制御でカメラ台座の軸を制御するというもので、その部分は基本的に変わりません。

ただ、これをベースとして、以下の２点を拡張した点が異なっています。

1. カメラ台座ヨー軸に対応する "TURRET_Y" 関節に加えて、ピッチ軸に対応する "TURRET_P" 関節も制御するようにした。
2. PD制御の目標関節角について、モデルの初期角度に固定するのではなく、ゲームパッド（ジョイスティック）からの入力に応じて変化させるようにした。

1については関連する変数を配列化し、forループによってそれぞれに同じ処理を行うようにしただけです。

2についてはChoreonoidが提供する "Joysitick" クラスを用いてジョイスティックからの入力を取得するようにしました。これについて解説しましょう。

まず、 ::

 #include <cnoid/Joystick>

によってJoystickクラスが定義されているヘッダをインクルードしています。

JoystickクラスのオブジェクトはTurretController2のメンバ変数 ::

 Joystick joystick;

として定義しています。コンストラクタはデフォルトのものを使っており、この場合は "/dev/input/js0" のデバイスファイルがジョイスティックの入力元となります。また、このデバイスファイルが存在しない場合、仮想ジョイスティックビューがあればそちらを入力元とします。

ジョイスティックの状態を取得するにあたっては、まず ::

 joystick.readCurrentState();

を実行します。するとデバイスファイルや仮想ジョイスティックビューから、ジョイスティックの現在の状態が読み込まれます。

あとは ::

 joystick.getPosition(軸ID）

によって、軸の状態（どれだけ倒しているか）を -1.0 〜 +1.0 の値として取得できますし、 ::

 joystick.getButtonState(ボタンID)

によって、ボタンが押しているかどうかの値をbool値として取得できます。ボタンについてはステップ5以降のコントローラで利用します。

注意点として、アナログスティックの軸の状態値について、0が中立点となるのですが、スティックを倒していない場合でも常に値が0になるとは限りません。ですので、倒しているかどうかの判定として、一定の閾値をかませることが必要になります。この処理は上記ソースコードのcontrol関数内で ::

 if(fabs(pos) > 0.25){
  
というコードで行っています。
 
ジョイスティックの軸の対応は、control関数内の ::

 static const int axisID[] = { 3, 4 };

で設定しています。ここの3,4がそれぞれカメラ台座ヨー軸、ピッチ軸に対応させる軸ID値で、F310の場合は右アナログスティックに対応しています。他のゲームパッドの場合も、jstestコマンドの出力を確認するなどして、適切な軸に対応させて下さい。

実際に目標関節角度を設定している箇所は、control関数内の ::

 double pos = joystick.getPosition(axisID[i]);
 if(fabs(pos) > 0.25){
     double deltaq = 0.002 * pos;
     q_ref[i] += deltaq;
     dq_ref = deltaq / dt;
 }

の部分になります。ここでq_ref[i]が目標関節角、dq_refが目標関節角速度に対応する変数です。あとはこれらの目標値を使って、パート1と同様のPD制御を行っています。
