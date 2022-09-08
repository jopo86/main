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

MediaFire - https://www.mediafire.com/file/3k6tl9lwzhko40q/dependencies.zip/file

MEGA - https://mega.nz/file/Ch5W0Bhb#Vgf3fZ7CpKbwKxTloKOTY9fPbNFsab9_HIdNw939zUQ


Once downloaded, extract the zip and place the `dependencies` folder (note - make sure this is the dependencies folder that directly has the `include` and `lib` folders, not one with another `dependencies` folder) in the same directory as all the other base directories like `src`, `assets`, and `.vscode`.

Once that is done, you may compile/build to an executable by either:
- Run `make` or `mingw32-make` in your terminal (while in the same directory as the Makefile) - this will work if you have make or MinGW installed and both added to PATH.
- Run the command that you can find in the makefile: `g++ -g --std=c++17 -Idependencies/include -Ldependencies/lib  src/*.cpp src/*.c -lglfw3dll -o main` (also while in the same directory as the Makefile) - this will work as long as you have g++ installed. If you don't you must install it to compile any C++ code.

Once you have compiled/built into an executable, you should have a 'main.exe' file. To run the program, you can simply run `./main.exe`.

What I do is I use the integrated Git Bash terminal in VSCode and run `make && ./main` - this is just shorthand for everything I explained. If you dont have make, you can either install it or use `mingw32-make && ./main` instead if you have MinGW installed and added to PATH.
