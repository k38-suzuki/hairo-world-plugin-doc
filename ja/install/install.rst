
ソースコードからのビルドとインストール
======================================

ソースコードの取得
------------------

開発版
~~~~~~

HAIROWorldPluginはgitリポジトリとして管理されており、githubの以下のアドレスにて公開されています。

- https://github.com/k38-suzuki/hairo-world-plugin

Choreonoidのソースディレクトリ直下にあるextディレクトリに移動して、
以下のコマンドでHairoWorldPluginを取得します。 ::

 git clone https://github.com/k38-suzuki/hairo-world-plugin.git

これによってリポジトリを格納した "hairo-world-plugin" というディレクトリが生成されます。このディレクトリ内で ::

 git pull

などとすることにより、その時点での最新のソースコードにアップデートできます。

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

<username>は、使用しているユーザ名です。これは、TCプラグイン内で利用しているルート権限を要するコマンド(modprobe, ip等)をパスワードなしで実行するための設定です。これにより、シミュレーション実行時にパスワードの入力が求められ、シミュレーションが停止しないようにしています。

CMake によるビルド設定
----------------------

まず、cmakeコマンドを使ってMakefileを更新します。Choreonoidのビルドディレクトリ上で ::

 cmake ..

を実行すると、必要なライブラリをチェックしMakefileを更新します。(cmakeコマンドのあとのピリオドに注意してください。）

次にHairoWorldPluginを有効にします。Choreonoidのビルドディレクトリ上でccmakeコマンドを ::

 ccmake ..

と実行し、**BUILD_HAIRO_WORLD_PLUGIN** を "ON" にします。

Choreonoidのビルドとインストール
--------------------------------

CMakeによりMakefileの生成が成功すれば、makeコマンドでChoreonoidをビルドします。Choreonoidのビルドとインストールについては `Choreonoidのビルド <https://choreonoid.org/ja/manuals/latest/install/build-ubuntu.html>`_ 以降を参照してください。

