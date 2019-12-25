[![Waffle.io - Columns and their card count](https://badge.waffle.io/UCSolarCarTeam/Epsilon-Dashboard.png?columns=all)](https://waffle.io/UCSolarCarTeam/Epsilon-Dashboard?utm_source=badge)
# Epsilon-Dashboard

The Epsilon Dashboard displays information on the screens.

## Switching Modes

There are three different modes for the dashboard: Display mode, Debug Display mode and race mode. The default mode is display mode.
To run the application in different modes, navigate to the directory where you made the executable file for the dashboard. 

To run the application in display mode, run the command:
	`./EpsilonDashboard`

To run the application in debug display mode, run the command:
	`./EpsilonDashboard -d`
  
To run the application in race mode, add the -r flag at the end:
  `./EpsilonDashboard -r`

## Setting up Rabbitmq

In this repo, there are dependencies needed for Rabbitmq before you will be able to build or run anything.

To install these dependencies, run the command:
	`./EpsilonDashboardSetup.sh`

## Config file

Create a copy of the `config.ini.example` file in the `build` directory called `config.ini` and update any necessary settings.

## Building via Command Line

Create a new directory for your build & navigate into it:

`mkdir build && cd build`

Call qmake, passing in the directory with the root `EpsilonDashboard.pro` to generate the makefile:

`qmake <path-to-source-pro>`

Later you need to re-run qmake on the project due to a new UI file or a change to a .pro, call:

`make qmake_all`

Build with:

`make -j4`
