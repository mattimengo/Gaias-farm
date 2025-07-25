# Gaias-farm

WINDOWS:

PROGETTO
cd Gaias-farm
mkdir build    (nome cartella a scelta)
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
cd build/x64/Release/Release
Esame.exe

TEST
cd Gaias-farm
mkdir build-test  (nome cartella a scelta)
cd build-test
cmake ..
cmake --build .
cd build/x64/Release/Debug
testM.exe





LINUX:

PROGETTO
cd Gaias-farm
mkdir build    (nome cartella a scelta)
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
cd build/linux/Release
cd Esame.exe  

TEST
cd Gaias-farm
mkdir build-test  (nome cartella a scelta)
cd build-test
cmake ..
cmake --build .
cd build/linux/Release
cd testM.exe





