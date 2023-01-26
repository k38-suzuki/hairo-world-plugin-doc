
Building and Installing from Source (Ubuntu Linux)
==================================================

Obtaining the source code
-------------------------

Development version
~~~~~~~~~~~~~~~~~~~

HAIROWorldPlugin is managed as a git repository. You can find it at the following GitHub address.

- https://github.com/k38-suzuki/hairo-world-plugin

You need to run git commands to use this repository. In Ubuntu, you can install git using the following command. ::

 sudo apt-get install git

You can check out the HAIROWorldPlugin repository by executing the following command. ::

 git clone https://github.com/k38-suzuki/hairo-world-plugin.git

This creates a “hairo-world-plugin” directory that holds the repository. In this directory, you can use commands such as ::

 git pull

to update to the source code to the latest available version.

For details on how to use git, see the git manual and explanatory articles.


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
