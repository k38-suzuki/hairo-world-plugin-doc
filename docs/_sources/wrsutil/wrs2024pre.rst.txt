
競技環境の構築
==============

ここでは、WRS2024プレ大会の競技環境の構築の仕方を説明します。
この機能は、競技環境の読込とロボットモデルの配置を自動的に行うためのものです。
この機能を使用するには `こちら <https://github.com/wrs-frei-simulation/WRS-Pre-2024>`_ のパッケージが必要です。

競技環境の読込（基本編）
------------------------

以下のコマンドでChoreonoidを起動してください。
ChoreonoidをROS2環境で使用している場合は、 ::

 $ ros2 run choreonoid_ros choreonoid --wrs-util <mission_name>

Choreonoidを単体で使用している場合は、（例：choreonoid/build内で） ::

 $ ./bin/choreonoid --wrs-util <mission_name>

と入力してください。
<mission_name>で指定できる引数は以下のとおりです。

 .. list-table::
  :widths: 30, 70
  :header-rows: 1

  * - 引数
    - 詳細
  * - M1-1
    - 競技M1の環境（エリア1のみ）を読み込みます。この引数では、ロボットを配置しません。
  * - M1-1-AizuSpiderDA
    - 競技M1の環境（エリア1のみ）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
  * - M1-1-AizuSpiderDA-ROS2
    - 競技M1の環境（エリア1のみ）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - M1-1-AizuSpiderSA
    - 競技M1の環境（エリア1のみ）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
  * - M1-1-AizuSpiderSA-ROS2
    - 競技M1の環境（エリア1のみ）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - M1-1-AizuSpiderSS
    - 競技M1の環境（エリア1のみ）を読み込み、AISTシミュレータ向けのAizuSpiderを配置します。
  * - M1-1-AizuSpiderSS-ROS2
    - 競技M1の環境（エリア1のみ）を読み込み、AISTシミュレータ向けのAizuSpiderを配置します。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - M1-2
    - 競技M1の環境（エリア2のみ）を読み込みます。この引数では、ロボットを配置しません。
  * - M1-2-AizuSpiderDA
    - 競技M1の環境（エリア2のみ）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
  * - M1-2-AizuSpiderDA-ROS2
    - 競技M1の環境（エリア2のみ）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - M1-2-AizuSpiderSA
    - 競技M1の環境（エリア2のみ）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
  * - M1-2-AizuSpiderSA-ROS2
    - 競技M1の環境（エリア2のみ）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - M1-2-AizuSpiderSS
    - 競技M1の環境（エリア2のみ）を読み込み、AISTシミュレータ向けのAizuSpiderを配置します。
  * - M1-2-AizuSpiderSS-ROS2
    - 競技M1の環境（エリア2のみ）を読み込み、AISTシミュレータ向けのAizuSpiderを配置します。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - M2
    - 競技M2の環境（エリア1〜4）を読み込みます。この引数では、ロボットを配置しません。
  * - M2-A1
    - 競技M2の環境（エリア1とエリア2のみ）を読み込みます。この引数では、ロボットを配置しません。
  * - M2-A2
    - 競技M2の環境（エリア2とエリア3のみ）を読み込みます。この引数では、ロボットを配置しません。
  * - M2-A3
    - 競技M2の環境（エリア3とエリア4のみ）を読み込みます。この引数では、ロボットを配置しません。
  * - M2-A4
    - 競技M2の環境（エリア4とエリア1のみ）を読み込みます。この引数では、ロボットを配置しません。
  * - M2-AizuSpiderDA
    - 競技M2の環境（エリア1〜4）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
  * - M2-AizuSpiderDA-ROS2
    - 競技M2の環境（エリア1〜4）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - M2-AizuSpiderSA
    - 競技M2の環境（エリア1〜4）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
  * - M2-AizuSpiderSA-ROS2
    - 競技M2の環境（エリア1〜4）を読み込み、AGXシミュレータ向けのAizuSpiderを配置します。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - M2-AizuSpiderSS
    - 競技M2の環境（エリア1〜4）を読み込み、AISTシミュレータ向けのAizuSpiderを配置します。
  * - M2-AizuSpiderSS-ROS2
    - 競技M2の環境（エリア1〜4）を読み込み、AISTシミュレータ向けのAizuSpiderを配置します。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - M2-SampleDroneA-ROS2
    - 競技M2の環境（エリア1〜4）を読み込み、AGXシミュレータ向けのSampleDroneを配置します。
      SampleDroneは、ROS2のgeometry_msgs::msg::Twistの/cmd_velトピックをサブスクライブします。
      この引数を使用するにはROS2パッケージ `choreonoid_ros2_sample_drone_tutorial <https://github.com/k38-suzuki/choreonoid_ros2_sample_drone_tutorial>`_ が必要です。
  * - M2-SampleDroneS-ROS2
    - 競技M2の環境（エリア1〜4）を読み込み、AISTシミュレータ向けのSampleDroneを配置します。
      SampleDroneは、ROS2のgeometry_msgs::msg::Twistの/cmd_velトピックをサブスクライブします。
      この引数を使用するにはROS2パッケージ `choreonoid_ros2_sample_drone_tutorial <https://github.com/k38-suzuki/choreonoid_ros2_sample_drone_tutorial>`_ が必要です。

以上で、競技環境の読込（基本編）は終了です。

競技環境の読込（応用編）
------------------------

ここでは、上述の競技環境の読込の際に自作のロボットモデルも配置できるようにするための手順を説明します。
主な手順は次のとおりです。

 1. ロボットモデルのコピー
 2. プロジェクトの作成
 3. YAMLファイルの作成
 4. Choreonoidの起動

ロボットモデルのコピー
~~~~~~~~~~~~~~~~~~~~~~

まず、choreonoid/ext/WRS2024PRE/model以下に任意の名前（例：model_<チーム名>）のディレクトリを作成して、
ディレクリ内に自作のロボットモデルのファイルやディレクトリを全てをコピーしてください。

次に、Choreonoidをリビルドしてください。
ChoreonoidをROS2環境で使用している場合、リビルドするときに追加したファイルが認識されない場合があります。
そのときは、オプション"--cmake-clean-cache"を追加してください。

リビルドが完了したら、ChoreonoidをROS2環境で使用している場合は、ros2_ws/install/choreonoid/share/choreonoid-x.x/WRS2024PRE/mode以下、
Choreonoidを単体で使用している場合は、choreonoid/build/share/choreonoid-x.x/WRS2024PRE/model以下を確認します。
choreonoid-x.xは、使用しているChoreonoidのバージョンに読み替えてください。

ディレクトリ内に前述の手順で作成したディレクトリ（例：model_<チーム名>）があれば、この手順は終了です。

プロジェクトの作成
~~~~~~~~~~~~~~~~~~

ここでは、ロボットモデルを保存したプロジェクトを作成します。
Choreonoidを起動して、ChoreonoidをROS2環境で使用している場合は、ros2_ws/install/choreonoid/share/choreonoid-x.x/WRS2024PRE/mode以下、
Choreonoidを単体で使用している場合は、choreonoid/build/share/choreonoid-x.x/WRS2024PRE/model以下の自作のロボットモデルを読み込んでください。
choreonoid-x.xは、使用しているChoreonoidのバージョンに読み替えてください。

自作のロボットモデルを読み込んだら、必要なシンプルコントローラ等を全て設定してください。

ChoreonoidをROS2環境で使用している場合で、カメラやレンジセンサ等のデバイスが取得した情報をパブリッシュするときは、
ロボットモデルの子アイテムにBodyROS2アイテムを追加してください。

設定が完了したら、ChoreonoidをROS2環境で使用している場合は、ros2_ws/src/choreonoid/ext/WRS2024PRE/project以下、
Choreonoidを単体で使用している場合は、choreonoid/ext/WRS2024PRE/project以下に任意の名前（例：project_<チーム名>）のディレクトリを作成して、
そのディレクトリ内にプロジェクト(.cnoid)を保存します。プロジェクトは、自作のロボットモデルの名前で保存してください。
**ここで保存したプロジェクトの名前を後述の"YAMLファイルの作成"で使用します。**

次に、Choreonoidをリビルドしてください。ChoreonoidをROS2環境で使用している場合、リビルドするときに追加したファイルが認識されない場合があります。
そのときは、オプション"--cmake-clean-cache"を追加してください。

リビルドが完了したら、ChoreonoidをROS2環境で使用している場合は、ros2_ws/install/choreonoid/share/choreonoid-x.x/WRS2024PRE/project以下、
Choreonoidを単体で使用している場合は、choreonoid/build/share/choreonoid-x.x/WRS2024PRE/project以下を確認します。
choreonoid-x.xは、使用しているChoreonoidのバージョンに読み替えてください。

ディレクトリ内に前述の手順で作成したディレクトリ（例：project_<チーム名>）があれば、この手順は終了です。

YAMLファイルの作成
~~~~~~~~~~~~~~~~~~

競技環境の読込に使用するYAMLファイルを作成します。
ここでは、WRS2024PRE/registration以下に格納されているregistration_test.yamlをテンプレートとして利用します。
registration_test.yamlを任意のディレクトリにコピーして、任意の名前（例：registration_<チーム名>.yaml）に変更してください。

任意のテキストエディタでそのYAMLファイルを開き、1行目を以下のように書き換えてください。 ::

 robot_list: &RobotList [ 作成したディレクトリの名前/自作のロボットモデルを保存したプロジェクトの名前 ]

例えば、<チーム名>が"team1"で、ディレクトリの名前が"project_team1"、
前述の手順で保存したプロジェクトの名前が"my_robot.cnoid"の場合は ::

 robot_list: &RobotList [ project_team1/my_robot ]

というように書き換えます。

自作のロボットモデルの他に、標準で以下のロボットモデルを使用できます。

 .. list-table::
  :widths: 30, 70
  :header-rows: 1

  * - プロジェクトの名前
    - 詳細
  * - AizuSpiderDA
    - AGXシミュレータ向けのAizuSpider。
  * - AizuSpiderDA-ROS2
    - AGXシミュレータ向けのAizuSpider。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - AizuSpiderSA
    - AGXシミュレータ向けのAizuSpider。
  * - AizuSpiderSA-ROS2
    - AGXシミュレータ向けのAizuSpider。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - AizuSpiderSS
    - AISTシミュレータ向けのAizuSpider。
  * - AizuSpiderSS-ROS2
    - AISTシミュレータ向けのAizuSpider。
      AizuSpiderは、ROS2のsensor_msgs::msg::Joyの/joyトピックをサブスクライブします。
  * - SampleDrone
    - SampleDrone。
  * - SampleDrone-ROS2
    - SampleDrone。
      SampleDroneは、ROS2のgeometry_msgs::msg::Twistの/cmd_velトピックをサブスクライブします。
      この引数を使用するにはROS2パッケージ `choreonoid_ros2_sample_drone_tutorial <https://github.com/k38-suzuki/choreonoid_ros2_sample_drone_tutorial>`_ が必要です。
  * - HobbyDrone
    - HobbyDrone。
  * - HobbyDrone-ROS2
    - HobbyDrone。
      HobbyDroneは、ROS2の **sensor_msgs::msg::Joyの/joy2** トピックをサブスクライブします。

例えば、ROS環境で使用できるAGXシミュレータ向けのAizuSpider（AizuSpiderSA-ROS2）を自作のロボットモデル（my_robot）と同時に使用する場合は、
YAMLファイルの1行目を以下のように書き換えてください。 ::

 robot_list: &RobotList [ project_team1/my_robot, AizuSpiderSA-ROS2 ]

この設定で競技環境を読み込んだ場合、my_robotが左側、AizuSpiderSAが右側に配置されます。
配置を入れ替える場合は、順番を入れ替えて次のように書き換えてください。 ::

 robot_list: &RobotList [ AizuSpiderSA-ROS2, project_team1/my_robot ]

YAMLファイルを保存したら、この手順は終了です。

Choreonoidの起動
~~~~~~~~~~~~~~~~

Choreonoidを起動します。

以下のコマンドでChoreonoidを起動してください。
ChoreonoidをROS2環境で使用している場合は、 ::

 $ ros2 run choreonoid_ros choreonoid <path/to/yaml> --wrs-util <mission_name>

Choreonoidを単体で使用している場合は、（例：choreonoid/build内で） ::

 $ ./bin/choreonoid <path/to/yaml> --wrs-util <mission_name>

と入力してください。
**引数の順番に注意してください。**
<path/to/yaml>には、前述の手順で作成したYAMLファイルまでのパスを引数として入力してください。
<mission_name>で指定できる引数は以下のとおりです。

 .. list-table::
  :widths: 30, 70
  :header-rows: 1

  * - 引数
    - 詳細
  * - M2
    - 競技M2の環境（エリア1〜4）を読み込み、自作のロボットモデルを配置します。
  * - M2-A1
    - 競技M2の環境（エリア1とエリア2のみ）を読み込み、自作のロボットモデルを配置します。
  * - M2-A2
    - 競技M2の環境（エリア2とエリア3のみ）を読み込み、自作のロボットモデルを配置します。
  * - M2-A3
    - 競技M2の環境（エリア3とエリア4のみ）を読み込み、自作のロボットモデルを配置します。
  * - M2-A4
    - 競技M2の環境（エリア4とエリア1のみ）を読み込み、自作のロボットモデルを配置します。

Choreonoidを起動したときに、ロボットモデルの配置がズレている場合は、
start_positionで初期位置の座標[ x, y, z ]を調整してください。
ここで、座標はメートル単位で指定します。

以上で、競技環境の読込（応用編）は終了です。

YAMLファイルの詳細
------------------

.. list-table::
  :widths: 20,12,12,75
  :header-rows: 1

  * - パラメータ
    - デフォルト値
    - 単位
    - 意味
  * - name
    - 空
    - \-
    - 設定の名前を指定します。
      **ここで指定した名前が引数<mission_name>で指定できます。**
  * - task_project
    - 空
    - \-
    - フィールドが保存されたプロジェクトをリストで指定します。
      ChoreonoidをROS2環境で使用している場合は、ros2_ws/install/choreonoid/share/choreonoid-x.x/WRS2024PRE/project以下、
      Choreonoidを単体で使用している場合は、choreonoid/build/share/choreonoid-x.x/WRS2024PRE/project以下にあるプロジェクトを指定できます。
      プロジェクトは、リストで指定した順番に読み込まれます。
  * - robot_project
    - 空
    - \-
    - ロボットが保存されたプロジェクトをリストで指定します。
      ChoreonoidをROS2環境で使用している場合は、ros2_ws/install/choreonoid/share/choreonoid-x.x/WRS2024PRE/project以下、
      Choreonoidを単体で使用している場合は、choreonoid/build/share/choreonoid-x.x/WRS2024PRE/project以下にあるプロジェクトを指定できます。
      プロジェクトは、リストで指定した順番に読み込まれ、先に指定したロボットを左側、後に指定したロボットは右側に配置されます。
  * - robot_alignment
    - X+
    - \-
    - 初期配置のロボットの向きを指定できます。
      X+、X-、Y+、Y-、X+Z+、X-Z+、Y+Z+、Y-Z+が指定できます。
      X+Z+、X-Z+、Y+Z+、Y-Z+では、ロボットがZ軸方向に並べて配置されます。
  * - start_position
    - [ 0.0, 0.0, 0.0 ]
    - [ m, m, m]
    - ロボットの初期配置の座標を指定します。
      座標はメートル単位で指定します。
  * - simulator_project
    - 空
    - \-
    - シミュレータアイテムが保存されたプロジェクトをリストで指定します。
      ChoreonoidをROS2環境で使用している場合は、ros2_ws/install/choreonoid/share/choreonoid-x.x/WRS2024PRE/project以下、
      Choreonoidを単体で使用している場合は、choreonoid/build/share/choreonoid-x.x/WRS2024PRE/project以下にあるプロジェクトを指定できます。
      プロジェクトは、リストで指定した順番に読み込まれます。
  * - view_project
    - 空
    - \-
    - ビューのレイアウトが保存されたプロジェクトをリストで指定します。
      ChoreonoidをROS2環境で使用している場合は、ros2_ws/install/choreonoid/share/choreonoid-x.x/WRS2024PRE/project以下、
      Choreonoidを単体で使用している場合は、choreonoid/build/share/choreonoid-x.x/WRS2024PRE/project以下にあるプロジェクトを指定できます。
      プロジェクトは、リストで指定した順番に読み込まれます。
  * - enable_recording
    - false
    - \-
    - 起動した環境のWorldアイテムにWorldLogFileアイテムを子アイテムとして追加します。
