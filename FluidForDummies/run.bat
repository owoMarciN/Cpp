cmake -G "MinGW Makefiles" -S . -B dist -DSDL3_DIR=D:\Aplikacje\SDL3\SDL3-3.1.3\x86_64-w64-mingw32\lib\cmake\SDL3

cd dist
cmake --build .

app

cd ..