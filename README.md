# ImageFormatChecker (IFC)
### Overview
As we know the extension at the end of the file name doesn't determine the real file extension. It only tells the PC which program to use when trying to open the file.
This way there may be a case where the file is named `image.jpg` but in reality it's just a PNG file. This program solves that problem. It checks the header bytes of the file
to tell which format it's in.

### Building
To build the program follow below steps:
1. Create build directory and change the cwd to build
```bash 
mkdir build && cd build
```
2. Create build files
```bash
cmake ../
```
3. Build the project
```bash
cmake --build ../build
```
After building the program the executable file will be created in build directory. Use below command to run it
```bash 
./main
```
If it doesn't work change the permission of the main file to make it executable
```bash
sudo chmod +x main
```

### Resources used in this project
- https://github.com/capt-jack00/binaryToHexadecimal -> Used for converting binary to hexadecimal