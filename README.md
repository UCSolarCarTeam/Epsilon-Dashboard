[![Waffle.io - Columns and their card count](https://badge.waffle.io/UCSolarCarTeam/Epsilon-Dashboard.png?columns=all)](https://waffle.io/UCSolarCarTeam/Epsilon-Dashboard?utm_source=badge)
# Epsilon-Dashboard

The Epsilon Dashboard displays information on the screens.

## Project Setup

In this repo, there are dependencies needed for before you will be able to build or run anything.

To install these dependencies, run the setup script:

`sudo ./EpsilonDashboardSetup.sh`

This will install the [RabbitMQ](https://www.rabbitmq.com/) server and the [Conan](https://conan.io/) package manager. See the links for more information.

## Building

### QT Creator

When first setting up your project with QT creator, you must first add a custom step to allow Conan to install dependencies.

1. Navigate to `Projects -> Build`
2. In `Build Steps`, select `Add Build Step -> Custom Process Step`
3. Add the conan command to the step
   - Command: `conan`
   - Arguments: `install --build=missing`
   - Working Directory: `%{buildDir}`
4. Move the step to occur as the first step in the process

### Command Line

1. Create a new directory for your build & navigate into it:

	`mkdir build && cd build`

2. Install conan dependencies:

	`conan install <path/to/conanfile.txt> --build=missing`
	
3. Call qmake, passing in the directory with the root `EpsilonDashboard.pro` to generate the makefile:

	`qmake <path-to-source-pro>`

- Later, if you need to re-run qmake on the project due to a new UI file or a change to a .pro, call:

	`make qmake_all`

4. Build:

	`make -j4`

### Cross Compilation

Same as the above steps, with a few modifications:

1. You must add an additional `-pr=<path/to/rpi_build>` to the `conan install` command.
   - `conan install <path/to/conanfile.txt> --build=missing -pr=<path/tp/rpi_build`
2. When calling qmake, it must be the qmake executed that you compiled for cross-compilation.

## Running the Dashboard

### Config file

There must be a `config.ini` beside the execuable to run properly.
An example can be found in `config.ini.example`, and any necessary settings can be updated.

### Switching Modes

There are three different modes for the dashboard: Display mode, Debug Display mode and race mode. The default mode is display mode.
To run the application in different modes, navigate to the directory where you made the executable file for the dashboard. 

To run the application in display mode, run the command:
	`./EpsilonDashboard`

To run the application in debug display mode, run the command:
	`./EpsilonDashboard -d`
  
To run the application in race mode, add the -r flag at the end:
  `./EpsilonDashboard -r`
