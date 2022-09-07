# Minecraft Clone
This is just a little project im working on in my free time. This is a work in progress - it's not even close to done.

# How to Compile/Run
You MUST have the includes and libs downloaded and in the correct directories if you want this code to work without any changes. The reason they are not included in this repo is because of how many files there are.


Download a zip containing the "include" and "lib" files:

MediaFire - https://www.mediafire.com/file/qeb2kgpk74uquoc/include_lib.zip/file

MEGA - https://mega.nz/file/K1wXARAR#IMg39lu9uIINJXRV_xDk4QG51gTJONvV8sV0qFfIdow


Once downloaded, extract the zip and place both the "include" and "lib" files in the same directory as all the other base directories - "src", "assets", and ".vscode".

Once that is done, you may compile/build to an executable by either:
- Run 'make' or 'mingw32-make' in your terminal (while in the same directory as the Makefile) - this will work if you have make or MinGW installed and both added to PATH.
- Run the command that you can find in the makefile: 'g++ -g --std=c++17 -Iinclude -Llib  src/*.cpp src/*.c -lglfw3dll -o main' (also while in the same directory as the Makefile) - this will work as long as you have g++ installed. If you don't you must install it to compile any C++ code.

Once you have compiled/built into an executable, you should have a 'main.exe' file. To run the program, you can simply type './main.exe'

What I do is I use the integrated Git Bash terminal in VSCode and run 'make && ./main' - this is just shorthand for everything I explained. If you dont have make, you can either install it or use 'mingw32-make && ./main' instead if you have MinGW installed and added to PATH.
