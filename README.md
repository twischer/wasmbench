# WebAssambler benchmark

## Booting [Android 1.6](https://copy.sh/v86/?profile=android)

| CPU         | Engine               |Boot animation|Avg MIPS|Launcher|Avg MIPS|
|-------------|----------------------|--------------|--------|--------|--------|
|Tesla M3 MCU2|Chromium 2022.28.2 [1]|     26:50min |    5,4 |>32+7min|    5,9 |
|i5-2520M     |Firefox 102.3.0esr    |      3:00min |   45,0 | 5:50min|   51,6 |
|i5-2520M     |Chromium 106.0.5249.91|      3:05min |   45,1 | 5:50min|   49,9 |

[1] VESA mode is not selected. First boot loader entry is used. Auto select timeout was active.
Tesla system resets sometimes. May be due to high memory usage of browser.

## Booting [Android 4](https://copy.sh/v86/?profile=android4)

| CPU         | Engine               |Boot animation|Avg MIPS|Launcher|Avg MIPS|
|-------------|----------------------|--------------|--------|--------|--------|
|i5-2520M     |Firefox 102.3.0esr    |      1:55min |   51,0 |16:55min|  140,0 |
|i5-2520M     |Chromium 106.0.5249.91|      2:00min |   49,0 |17:30min|  130,0 |

[1] VESA mode is not selected. First boot loader entry is used. Auto select timeout was active.

## Install

```
sudo apt install emscripten
```

## Binary

```
clang++-14 test.cpp -o test
./test
clang++-14 -O3 test.cpp -o test_o3
./test_o3
```

| CPU		| VM		| -O0	| -O3	|
|---------------|-------	|-------|-------|
| RPi 2 B+	|Native		| 234s	|	|
| RPi 3 B+	|Native		| 201s	|	|
| Banana PI M3	|Native		| 142s	|	|
| i5-2520M	|Native		| 27s	| 3s	|
| i5-2520M	|[Alpine](https://bellard.org/jslinux/vm.html?url=alpine-x86.cfg&mem=192)||807s|
| i5-2520M	|[Fedora33](https://bellard.org/jslinux/vm.html?cpu=riscv64&url=fedora33-riscv.cfg&mem=256)||812s|
| i5-2520M      |[v86 Arch](https://copy.sh/v86/?profile=archlinux)||75s|
| i5-2520M      |[WebVM](https://webvm.io)||27s|
| Ryzen 9 5900X	|Native		| 2s	| ???	|

## Script

| CPU		|Engine			|[Native JS](https://raw.githack.com/twischer/wasmbench/main/native_js.html)|[emcc JS](https://raw.githack.com/twischer/wasmbench/main/build/emcc_js.html)|[emcc -O3 JS](https://raw.githack.com/twischer/wasmbench/main/build/emcc_js_o3.html)|[emcc Wasm](https://raw.githack.com/twischer/wasmbench/main/build/emcc_wasm.html)|[emcc -O3 Wasm](https://raw.githack.com/twischer/wasmbench/main/build/emcc_wasm_o3.html)|
|---------------|-----------------------|----|----|----|----|----|
| Tesla M3 MCU2 |Chromium 2022.28.2	|    |177s| 11s|457s| 21s|
| i5-2520M	|NodeJS	v18.7.0		| 58s| 35s|  3s|    |    |
| i5-2520M	|Firefox 102.3.0esr	| 74s| 29s| 12s| 30s| 13s|
| i5-2520M	|Chromium 106.0.5249.91	|345s| 45s|  3s| 88s|  5s|
| i7-8700	|Firefox 105.0		| 35s| 18s| 11s|    |  7s|

## Native Java-Script

This web page uses `native_js.js`. This script was found in
https://dirask.com/posts/CPU-Benchmark-single-core-speed-test-with-Fibonacci-Sequence-in-JavaScript-pJqwoD

## Compiled Java-Script

```
em++ -s WASM=0 test.cpp -o build/emcc_js.html
em++ -s WASM=0 test.cpp -o build/emcc_js_o3.html
em++ -O3 -s WASM=0 test.cpp -o build/emcc_js_o3.js
```

### For NodeJS

```
node emcc_js.js
```

### For web browser

```
python3 -m http.server &
xdg-open http://localhost:8000/emcc_js.html
```

## WebAssambly

```
em++ test.cpp -o build/emcc_wasm.html
em++ test.cpp -o build/emcc_wasm_o3.html
em++ -O3 test.cpp -o build/emcc_wasm_o3.js
```

### For NodeJS

```
node emcc_wasm.js
```

### For web browser

```
python3 -m http.server &
xdg-open http://localhost:8000/emcc_wasm.html
```
See https://emscripten.org/docs/getting_started/Tutorial.html for details.

