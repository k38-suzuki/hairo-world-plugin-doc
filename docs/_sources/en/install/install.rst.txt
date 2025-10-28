
Building and Installing from Source (Ubuntu Linux)
==================================================

Obtaining the source code
-------------------------

To access the HAIROWorldPlugin, the software is no longer available on GitHub due to a change in JAEA's software management policy and is now accessible by application only. We apologize for the inconvenience and request that you submit the following Application Form and GDPR for Use.


:download:`Download the Application Form <./Application_Form_HAIROWorldPlugin_Yamato Univ_Satoshi Sasaki.pdf>`

:download:`Download the GDPR <./GDPR_HAIROWorldPlugin_Yamato Univ_Satoshi Sasaki.pdf>`

Please keep the following points in mind when preparing the Application Form and the GDPR:

 1. Please complete the form-fillable PDF by entering information in the grey fields and submit it electronically (do not print it).
 2. The signatures (one each on the Application Form and the Pledge) should be made using an Acrobat Self-Sign Digital ID. Clicking on the signature field will initiate the signing process; select "Self-Sign Digital ID" → "Save to file" → enter the required information such as your name and email address to create and apply the signature. If you are unfamiliar with the process for creating a Self-Sign Digital ID, you may paste an image of your handwritten signature instead.
 3. The file name of the Application Form should include your organization name and full name as shown in the attachment (example: Application_Form_HAIROWorldPlugin_Yamato Univ_Satoshi Sasaki.pdf).
 4. Please submit the Application Form and GDPR to suzuki.kenta38[a]jaea.go.jp. (Please replace [a] with @.)

Upon receipt of your Application Form, a JAEA representative will send you a download link via email. Once you have obtained the source code, please unzip it and place the contents into the ext directory located directly under the Choreonoid source directory.

Installing dependent packages
-----------------------------

In Ubuntu, you can easily install most of the software above by running the script “install-requisites-ubuntu-x.x.sh” under “misc/script.” x.x should be your version of Ubuntu. For example, if you have Ubuntu 18.04, execute ::

 misc/script/install-requisites-ubuntu-18.04.sh

You will be prompted to enter your sudo password. After you do so, the necessary packages will be automatically installed via the package management system. (The latest version of HAIROWorldPlugin does not have any dependent packages.)

As for Qt, version 5 is supported. Qt version 4 was supported up to Choreonoid 1.7, but the latest version does not support it.

Also, following commands are automatically written. ::

 <username>    ALL=NOPASSWD: /sbin/modprobe
 <username>    ALL=NOPASSWD: /sbin/ip
 <username>    ALL=NOPASSWD: /sbin/tc
 <username>    ALL=NOPASSWD: /sbin/rmmod

<username> means the name of your user account. This is a setting for NetEmPlugin to execute commands (modprobe, ip and etc.) which require root privileges without a password.

CMake build settings
--------------------

First, use the cmake command to generate the makefile you need to build Choreonoid. In the Choreonoid source directory, execute ::

 cmake .

to find the necessary libraries and generate a makefile. (Note the period after the cmake command.)

If you are working in one of the Ubuntu versions described above, you should be able to generate a makefile without any problems. However, if the necessary libraries are not installed in the prescribed location, you may get an error when executing cmake. In that case, you will need to install the libraries properly or modify the CMake build settings. You can also change these build settings from the command line by using the cmake command. Execute the ccmake command ::

 ccmake .

to access all settings in the form of a menu. Check the CMake manual for details.

For using HAIROWorldPlugin, set BUILD_HAIRO_WORLD_PLUGIN to “ON.”

Choreonoid also has some optional functions that are not built during the default process described above. You can find a summary of these functions in Optional Functions Overview . If you want to use them, you can enable them in the CMake settings.

Building Choreonoid
-------------------

If CMake successfully generates a makefile, you can use the make command to build Choreonoid. In the directory where you executed CMake (the build directory), execute ::

 make

to build Choreonoid.

If you have a multi-core CPU, you can shorten the build time by using the “-j” option to do a parallel build. For example, ::

 make -j8

Installation
------------

On Linux, you can run the executable file generated in the build directory as it is (without going through an installation process). If the build was successful, an executable file called “choreonoid” will have been generated in the “bin” directory inside the build directory. Execute this file. ::

 bin/choreonoid

If there are no problems with the build, this will launch the Choreonoid main window.

It is convenient that you can run the program without going through the installation process. Usually, however, you would go through this installation process and then run the executable file in the installation destination directory. To install the program, execute ::

 make install

in the build directory. A set of files needed to run the program will be installed in the specified directory.

On Linux, the default install location is “/usr/local.” You will usually need root privileges to write to this directory. Execute ::

 sudo make install

You can also change the install location by changing CMake’s CMAKE_INSTALL_PREFIX setting. If there is no need for multiple accounts to have access to Choreonoid, you can install it anywhere in the Home directory. In that case, you also will not need sudo to install the program.

Normally, you would need have a common library path pointing to the lib directory of the install location. If you set ENABLE_INSTALL_RPATH to “ON,” you can use the program even without that common library path.
