# Gaias-farm

## WINDOWS

### PROGETTO
```bash
cd Gaias-farm
mkdir build    # nome cartella a scelta
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
cd build/x64/Release/Release
Esame.exe
```

### TEST
```bash
cd Gaias-farm
mkdir build-test  # nome cartella a scelta
cd build-test
cmake ..
cmake --build .
cd build/x64/Release/Debug
testM.exe
```



## LINUX

### PROGETTO
```bash
cd Gaias-farm
mkdir build    # nome cartella a scelta
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
cd build/linux/Release
./Esame.exe
```

### TEST
```bash
cd Gaias-farm
mkdir build-test  # nome cartella a scelta
cd build-test
cmake ..
cmake --build .
cd build/linux/Release
./testM.exe
```
