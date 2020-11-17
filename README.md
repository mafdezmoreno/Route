# Route

Based in [CppND-Route-Planning-Project](https://github.com/udacity/CppND-Route-Planning-Project) form Udacity


## Dependencies
* cmake >= 3.11.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.4.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
* Windows: I recommend to use WLS2 with Kali linux and [Win-KeX](https://www.kali.org/docs/wsl/win-kex/)
* IO2D
  * Installation instructions for all operating systems can be found [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md)
  * This library must be built in a place where CMake `find_package` will be able to find it

  * Cairo/Xlib on Linux

    CMake script expects cairo and graphicsmagick to be installed. libpng is required in order to run tests. These installation steps assume APT package manager on Ubuntu Linux. Installation steps:

      * Refresh apt: sudo apt update
      * Install GCC: sudo apt install build-essential
      * Install CMake: sudo apt install cmake
      * Install Cairo: sudo apt install libcairo2-dev
      * Install graphicsmagick: sudo apt install libgraphicsmagick1-dev
      * Install libpng: sudo apt install libpng-dev

    Example of CMake execution:
    ```
    git clone --recurse-submodules https://github.com/cpp-io2d/P0267_RefImpl
    cd P0267_RefImpl
    mkdir Debug
    cd Debug
    cmake --config Debug "-DCMAKE_BUILD_TYPE=Debug" ..
    cmake --build .
    sudo make install
    ```

## Compiling and Running

### Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
mkdir build && cd build
```
From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```
### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./OSM_A_star_search
```
Or to specify a map file:
```
./OSM_A_star_search -f ../<your_osm_file.osm>
```

## Testing

The testing executable is also placed in the `build` directory. From within `build`, you can run the unit tests as follows:
```
./test
```

