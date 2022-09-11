# Overview
This is a work in progress - it's not even close to done. It is a minecraft clone I am coding using the C++ lanugage and the OpenGL rendering API. 

Additional Dependencies: 
- GLFW (Graphics Library Framework - provides ability to program windows & read keyboard/mouse input)
- GLFW link: https://www.glfw.org/download.html
- GLAD (OpenGL Loader/Generator - provides ability to use modern OpenGL functions)
- GLAD link: https://glad.dav1d.de/
- GLM (OpenGL Mathematics - makes complicated math like matrices and vectors easier with a library of functions)
- GLM link: https://github.com/g-truc/glm
- STBI (or stb_image, loads images of many file types, in this case to be used for textures)
- stb_image.h file (which is all you need): https://github.com/nothings/stb/blob/master/stb_image.h

# Versions/Updates
v0.1.5 (9/10/22)
- Created Block and Chunk classes
- Organization / Code Cleanup
- 3 hours of pain because I forgot to close the shader files after they are read
- 1.5 hours of pain because arrays are pointers and can literally edit values from a different file (I was unknowingly editing the vertices in `BlockTypes.cpp` when applying the offsets to each cube)

v0.1.0 (9/8/22)
- Fully textured blocks of many types. I won't list them all, but they can be found easily in the `BlockTypes.hpp` file (in `src/`).
- When program is ran, there will be a demo of several block types rotating on the screen.

v0.0.2 (9/7/22)
- Fully textured grass block rendering

v0.0.1 (9/6/22)
- Quad rendering to screen with grass block side texture

# How to Compile + Run
You MUST have the includes and libs downloaded and in the correct directories if you want this code to work without any changes. The reason they are not included in this repo is because of how many files there are.


Download a zip containing the updated "include" and "lib" files:

MediaFire - https://www.mediafire.com/file/3k6tl9lwzhko40q/dependencies.zip/file

MEGA - https://mega.nz/file/Ch5W0Bhb#Vgf3fZ7CpKbwKxTloKOTY9fPbNFsab9_HIdNw939zUQ


Once downloaded, extract the zip and place the `dependencies` folder (note - make sure this is the dependencies folder that directly has the `include` and `lib` folders, not one with another `dependencies` folder) in the same directory as all the other base directories like `src`, `assets`, and `.vscode`.

Once that is done, you may compile/build to an executable by either:
- Running `make` or `mingw32-make` in your terminal (while in the same directory as the Makefile) - this will work if you have make or MinGW installed and added to PATH, respectively
- Running the command that you can find in the makefile: `g++ -g --std=c++17 -Idependencies/include -Ldependencies/lib  src/*.cpp src/*.c -lglfw3dll -lopengl32 -o debug/a` (also while in the same directory as the Makefile) - this will work as long as you have g++ installed. If you don't you must install it to compile any C++ code.

Once you have compiled/built into an executable, you should have a 'a.exe' file in the `debug` folder. To run the program, you can simply run `./debug/a`.

What I do is I use the integrated Git Bash terminal in VSCode and run `make && ./debug/a` - this is just shorthand for what I explained before, what this does is run the makefile to build/compile the program, and then, only if the first command was successful, run debug/a.exe. If you are using MS PowerShell instead of bash, `make; ./debug/a` will do the same thing except if will run main.exe no matter if the first command was successful or not. `&&` is not valid in PowerShell. If you don't have make, you can either install it or use `mingw32-make && ./main` instead if you have MinGW installed and added to PATH.
