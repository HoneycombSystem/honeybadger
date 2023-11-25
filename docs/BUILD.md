# Build project instructions
> [!CAUTION]
> This project works only on Linux. Windows is not officially supported.

## Prerequisites
You need to have installed:
- CMake 3.21 or higher
- C++ compiler with C++20 support(on CI we use g++ 11)
- Conan package manager

## Build
> [!NOTE]
> If steps below are not working for you, try to look at [CI scripts](../.circleci/config.yml) for more details.

0. Clone the repository
```bash
git clone https://github.com/HoneycombSystem/honeybadger.git
cd honeybadger
```
1. Create a build directory
```bash
mkdir build
```
2. Run Conan to install dependencies
```bash
conan install . --output-folder=build --install-folder=build --build=missing -s build_type=<Debug|Release>
```
3. Run CMake to generate build files
```bash
cmake -Bbuild -GNinja -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=<same as in step 2>
```
4. Build the project
```bash
cmake --build build
```
5. Run tests(optional)
```bash
ctest --test-dir build --no-compress-output -T Test --output-junit Testing/results.xml --rerun-failed --output-on-failure -V
```
