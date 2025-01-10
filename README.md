cmake . -B build
cmake --build build
./build/bin/main

to codesign (for Instruments profiling):
codesign -s - -v -f --entitlements debug.plist build/bin/main