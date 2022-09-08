# Overview
This is a work in progress - it's not even close to done. It is a minecraft clone I am coding using the C++ lanugage and the OpenGL rendering API. 

Additional Dependencies: 
- GLFW (Graphics Library Framework - provides ability to program windows & read keyboard/mouse input)
- GLAD (OpenGL Loader/Generator - provides ability to use modern OpenGL functions)
- GLM (OpenGL Mathematics - makes complicated math like matrices and vectors easier with a library of functions)
- STBI (or stb_image, loads images of many file types, in this case to be used for textures)

# Versions
v0.0.2 - current - (9/7/22)
- Fully textured grass block rendering

v0.0.1 (9/6/22)
- Quad rendering to screen with grass block side texture

# How to Compile/Run
You MUST have the includes and libs downloaded and in the correct directories if you want this code to work without any changes. The reason they are not included in this repo is because of how many files there are.


Download a zip containing the updated "include" and "lib" files:

MediaFire - https://www.mediafire.com/file/qeb2kgpk74uquoc/include_lib.zip/file

MEGA - https://mega.nz/file/K1wXARAR#IMg39lu9uIINJXRV_xDk4QG51gTJONvV8sV0qFfIdow


Once downloaded, extract the zip and place both the "include" and "lib" files in the same directory as all the other base directories - "src", "assets", and ".vscode".

Once that is done, you may compile/build to an executable by either:
- Run `make` or `mingw32-make` in your terminal (while in the same directory as the Makefile) - this will work if you have make or MinGW installed and both added to PATH.
- Run the command that you can find in the makefile: `g++ -g --std=c++17 -Iinclude -Llib  src/*.cpp src/*.c -lglfw3dll -o main` (also while in the same directory as the Makefile) - this will work as long as you have g++ installed. If you don't you must install it to compile any C++ code.

Once you have compiled/built into an executable, you should have a 'main.exe' file. To run the program, you can simply run `./main.exe`.

What I do is I use the integrated Git Bash terminal in VSCode and run `make && ./main` - this is just shorthand for everything I explained. If you dont have make, you can either install it or use `mingw32-make && ./main` instead if you have MinGW installed and added to PATH.
