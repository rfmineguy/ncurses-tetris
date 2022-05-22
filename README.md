# ncurses-tetris
Final project for CS2 class


# Build instructions
* git clone https://github.com/rfmineguy/ncurses-tetris

## Windows
* not supported
* NCurses is simply not available / doesn't run in the Windows system.
  - I think you *could* use WSL (Windows Subsystem for Linux), but I haven't tested this.

## Linux (ubuntu)
1. sudo apt-get install libncurses5-dev libncursesw5-dev
2. sh build.sh

## Linux (fedora)
1. sudo dnf install ncurses-devel

## Linux (arch)
1. sudo pacman -S ncurses-dev

## MacOS
1. brew install ncurses
2. sh build.sh


# Info
* *project_info.sh* runs a script that analyzes the code files of the project and outputs line counts of various types
