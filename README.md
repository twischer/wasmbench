# WebAssambler benchmark

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
| Ryzen 9 5900X	|Native		| 2s	| ???	|

Compilation takes >12h on https://webvm.io on Intel i5-2520M.

## Script

| CPU		|Engine			|[Native JS](https://raw.githack.com/twischer/wasmbench/main/native_js.html)|[emcc JS](https://raw.githack.com/twischer/wasmbench/main/build/emcc_js.html)|[emcc -O3 JS](https://raw.githack.com/twischer/wasmbench/main/build/emcc_js_o3.html)|[emcc Wasm](https://raw.githack.com/twischer/wasmbench/main/build/emcc_wasm.html)|[emcc -O3 Wasm](https://raw.githack.com/twischer/wasmbench/main/build/emcc_wasm_o3.html)|
|---------------|-----------------------|----|----|----|----|----|
| i5-2520M	|NodeJS	v18.7.0		| 58s| 35s|  3s|    |    |
| i5-2520M	|Firefox 102.3.0esr	| 74s| 29s| 12s| 30s| 13s|
| i5-2520M	|Chromium 106.0.5249.91	|345s| 45s|  3s| 88s|  5s|
| Tesla M3 MCU2 |Chromium 2022.28.2	|    |177s| 11s|457s| 21s|

The used script was found in
https://dirask.com/posts/CPU-Benchmark-single-core-speed-test-with-Fibonacci-Sequence-in-JavaScript-pJqwoD


## Native Java-Script

Open
[nativejs.html](https://raw.githack.com/twischer/wasmbench/main/nativejs.html)
to execute the test.

This web page uses `nativejs.js`.


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
Open
[emcc_js.html](https://raw.githack.com/twischer/wasmbench/main/build/emcc_js.html)
to execute the test.


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
Open
[emcc_wasm.html](https://raw.githack.com/twischer/wasmbench/main/build/emcc_wasm.html)
to execute the test.

See https://emscripten.org/docs/getting_started/Tutorial.html for details.

