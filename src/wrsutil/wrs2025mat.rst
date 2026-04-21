
マテリアルの設定（本大会）***New（2025/07/29追加）***
=====================================================

ここでは、自作のロボットでAGXクローラを使用するときのマテリアルの設定について説明します。
**このマテリアルの設定は、自作のロボットで競技環境内の階段やスロープを登るために必須ですので、必ず確認してください。**

YAMLファイルの編集
------------------

まず、マテリアルの設定が記述されているYAMLファイルを編集します。
ここでは、WRS2025/share/defaultに格納されているmaterials.yamlを編集します。

任意のテキストエディタでそのYAMLファイルを開き、以下に示す272行目と273行目を書き換えてください。 ::

     reference_body: <your robot name>
     reference_link: <root link of your robot>

272行目では、<your robot name>のところを、自作のロボットのボディの名前に変更してください。例えば、自作のロボットのボディの名前が"MyRobot"の場合は、::

     reference_body: MyRobot

というように書き換えます。
続けて、273行目では、<root link of your robot>のところを、自作のロボットのルートリンクの名前に変更してください。例えば、自作のロボットのルートリンクの名前が"CHASSIS"の場合は、::

     reference_link: CHASSIS

というように書き換えます。

YAMLファイルを保存したら、この手順は終了です。

マテリアルの指定
----------------

YAMLファイルの編集が完了したら、続けてAGXクローラのパラメータを編集します。
まず、AGXVehicleContinuousTrackDeviceのマテリアルを指定します。以下は、AGXVehicleContinuousTrackDeviceの記述例です。::

       -
         type: AGXVehicleContinuousTrackDevice
         name: TRACK_R
         sprocketNames: [ SPROCKET_R ]
         rollerNames: [ ROLLER_R ]
         idlerNames: [ IDLER_R ]
         upAxis: [ 0, 0, 1 ]
         numberOfNodes: 42
         nodeThickness: 0.01
         nodeWidth: 0.1
         nodeThickerThickness: 0.02
         useThickerNodeEvery: 3
         material: WRSCommonTracks
         nodeDistanceTension: 0.002
         stabilizingHingeFrictionParameter: 8e-07
         minStabilizingHingeNormalForce: 100
         hingeCompliance: 2e-05
         hingeSpookDamping: 0.01
         nodesToWheelsMergeThreshold: -0.1
         nodesToWheelsSplitThreshold: -0.05

のように、パラメータ"material"で **"WRSCommonTracks"** を指定してください。

次に、AGXクローラのホイール（スプロケット、ローラ及びアイドラ）のパラメータを編集します。
以下はスプロケットのリンクの記述例です。::

   -
     name: SPROCKET_L
     translation: [ 0.25, 0.2, 0 ]
     jointId: 0
     parent: CHASSIS
     jointType: revolute
     jointAxis: Y
     centerOfMass:  [ 0, 0, 0 ]
     material: WRSCommonWheel
     .
     .
     .

のように、パラメータ"material"で **"WRSCommonWheel"** を指定してください。
続けて、スプロケットの場合と同様にローラ及びアイドラのパラメータを編集します。
以下は、ローラのリンクの記述例です。::

   -
     name: ROLLER_L
     translation: [ 0, 0.2, 0 ]
     jointId: 2
     parent: CHASSIS
     jointType: revolute
     jointAxis: Y
     centerOfMass: [ 0, 0, 0 ]
     material: WRSCommonWheel
     .
     .
     .

以下は、アイドラのリンクの記述例です。::

   -
     name: IDLER_L
     translation: [ -0.25, 0.2, 0 ]
     jointId: 4
     parent: CHASSIS
     jointType: revolute
     jointAxis: Y
     centerOfMass: [ 0, 0, 0 ]
     material: WRSCommonWheel
     .
     .
     .

以上で、マテリアルの指定は完了です。


最後に、Choreonoidをリビルドしてください。ChoreonoidをROS2環境で使用している場合、リビルドするときに追加したファイルが認識されない場合があります。 そのときは、オプション”–cmake-clean-cache”を追加してください。

リビルドが完了したら、ChoreonoidをROS2環境で使用している場合は、ros2_ws/install/choreonoid/share/choreonoid-x.x/WRS2025/share/default以下、 Choreonoidを単体で使用している場合は、choreonoid/build/share/choreonoid-x.x/WRS2025/share/default以下のmaterials.yaml確認します。 choreonoid-x.xは、使用しているChoreonoidのバージョンに読み替えてください。

任意のテキストエディタでそのYAMLファイルを開き、 **YAMLファイルの編集** で書換えたとおりとなっていれば、マテリアルの設定は完了です。
