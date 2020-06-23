# クイックソートの比較

1. JavaScript で クイックソートをベタ書き。
2. JavaScript の sort()関数を使って、ソート。
3. JavaScript から C++ へソートしたい配列を渡して、C++でクイックソート。

2はクイックソート？V8が内部で動くから速い？？


# 環境
node v12.16.0

npm v6.13.4

# インストール
```bash
npm install -g node-gyp
```

# 実行
- 実行
```bash
$ npm install
$ node sort_test.js
```
- 再コンパイル
```bash
$ node-gyp build
```

# OS
MacOS10 と Windows10 ともに動いた。

# 速度
MacOSだと2と3は同じくらいだったけど、Windowsだと2の方が速い。もっと要素数を増やした方がわかる？？

# 参考サイト


- ドキュメント

https://nodejs.org/api/addons.html

- JavaScript の配列を C++ 配列へ

https://stackoverflow.com/questions/52553524/node-addon-api-pass-array-as-function-argument

https://medium.com/@denismalykhin/n-api-add-on-and-js-code-performance-comparison-9a69c6282fa6

- JavaScript のNumberを C++ double へ

https://qiita.com/Satachito/items/fa681ba96dc8e52ca7c1


- 色々な例を作ってアップしてくれてる

https://github.com/nodejs/abi-stable-node-addon-examples