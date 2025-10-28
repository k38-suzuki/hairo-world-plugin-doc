
ソースコードからのビルドとインストール
======================================

ソースコードの取得
------------------

HAIROWorldPluginは、JAEAのソフトウェア管理ポリシーの変更に伴い、GitHubでの公開を取止め、申込制となりました。
お手数おかけしますが、以下の利用申込書の提出をお願いします。

:download:`利用申込書をダウンロード <./利用申込書__HAIROWorldPlugin(ヤマト大学 佐々木サトシ).pdf>`

利用申込書の作成にあたっては、以下の事項をご留意ください。

 1. Form形式のPDFでグレー枠内に記載しそのまま（印刷せずに）提出してください。
 2. 署名(申込書と誓約書それぞれ1か所)はacrobatの自己電子署名(Self-Sign Digital ID)でお願いします。署名欄をクリックすると署名が開始されますのでSelf-Sign Digital IDを選び →Save to file→名前やメールアドレスなど必要情報を入力で作成し署名することができます。Self-Sign Degital IDのやり方が、よくわからない方は手書き署名の画像データを貼り付けて頂いてもOKです。
 3. 申込書ファイル名は添付のように組織名と氏名を入れてください。
 4. suzuki.kenta38[a]jaea.go.jp宛に送信ください。※[a]は＠に置き換きえてください

利用申込書の受理後、JAEA担当者よりダウンロード案内をメールで発信いたします。
取得したソースコードは、解凍してからChoreonoidのソースディレクトリ直下にあるextディレクトリに入れてください。

依存パッケージのインストール
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Ubuntuの場合、"hairo-world-plugin/misc/script" 以下にある "install-requisites-ubuntu-x.x.sh" というスクリプトを用いることにより、以上のソフトウェアのほとんどを簡単にインストールすることができます。x.xはUbuntuのバージョンに対応します。例えば Ubuntu 18.04 であれば ::

 misc/script/install-requisites-ubuntu-18.04.sh

を実行すると、sudoのパスワードが求められるので入力してください。すると、パッケージシステム経由で、必要なパッケージが自動でインストールされます。（現在は、インストールされるパッケージはありません。）

また、/etc/sudoersに以下が自動で書き込まれます。 ::

 <username>    ALL=NOPASSWD: /sbin/modprobe
 <username>    ALL=NOPASSWD: /sbin/ip
 <username>    ALL=NOPASSWD: /sbin/tc
 <username>    ALL=NOPASSWD: /sbin/rmmod

<username>は、使用しているユーザ名です。これは、NetEmプラグイン内で利用しているルート権限を要するコマンド(modprobe, ip等)をパスワードなしで実行するための設定です。これにより、シミュレーション実行時にパスワードの入力が求められ、シミュレーションが停止しないようにしています。

CMake によるビルド設定
----------------------

まず、cmakeコマンドを使ってMakefileを更新します。Choreonoidのビルドディレクトリ上で ::

 cmake ..

を実行すると、必要なライブラリをチェックしMakefileを更新します。(cmakeコマンドのあとのピリオドに注意してください。）

次にHAIROWorldPluginを有効にします。Choreonoidのビルドディレクトリ上でccmakeコマンドを ::

 ccmake ..

と実行し、 **BUILD_HAIRO_WORLD_PLUGIN** を "ON" にします。

.. note::
  | 2022年12月21日のアップデートで、このビルドオプションを廃止しました。これに伴い、Choreonoidのビルドと同時に、HAIROWorldPluginが必ずビルドされるようになりました。

Choreonoidのビルドとインストール
--------------------------------

CMakeによりMakefileの生成が成功すれば、makeコマンドでChoreonoidをビルドします。Choreonoidのビルドとインストールについては `Choreonoidのビルド <https://choreonoid.org/ja/manuals/latest/install/build-ubuntu.html>`_ 以降を参照してください。

簡易インストール
------------------

スクリプトを使用して、ChoreonoidとHAIROWorldPluginのビルドを一括して行うこともできます。なお、この方法では、Choreonoidのビルドまで行います。Choreonoidのインストールが必要な場合は、別途実行してください。また、スクリプトはUbuntu 20.04 LTS向けのものです。他のOS、ディストリビューション、バージョンでご使用の際は、ご自身の環境に合わせて適宜修正してください。

まず、:download:`こちら <./install-choreonoid.sh>` からスクリプトを任意のディレクトリにダウンロードします。 ::

次に、スクリプトを保存したディレクトリ上で端末を開き、 ::

 chmod +x install-choreonoid.sh
 ./install-choreonoid.sh

を実行します。実行が成功すると、ホームディレクトリに"cnoid_ws"というディレクトリが生成され、このディレクトリ内でChoreonoidがビルドされます。
