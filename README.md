# C++Calculator
製作期間：1週間<br>
使用環境：C++, visual studio<br>
<br>
<br>
## 概要
C++を用いて様々な機能を持つ計算機を制作しました<br>
if文ではなく正規表現で読み取りを行っています。<br>
<br>
<br>
## 機能一覧<br>
### ・四則演算＋剰余計算、実数<br>
和「<span style="color: red; ">数＋数</span>」、差「<span style="color: red; ">数-数</span>」、積「<span style="color: red; ">数*数</span>」、商「<span style="color: red; ">数/数</span>」、余「<span style="color: red; ">数%数</span>」<br>
　・少数の計算も可能<br>
  ・空白が間に含まれても計算可能<br>
<br>
### ・括弧の計算、複数の二項演算子<br>
「<span style="color: red; ">(演算)</span>」<br>
 ・()の中に数字を入れ、計算すると、<span style="color: red; ">()の中身</span>の計算が優先される<br>
 ・四則演算をするときは<span style="color: red; ">掛け算、割り算</span>が優先される<br>
<br>
### ・π、初等関数の演算<br>
初等関数「<span style="color: red; ">sin(演算)</span>、<span style="color: red; ">cos(演算)</span>、<span style="color: red; ">tan(演算)</span>」(大文字小文字どちらでも認識)<br>
PI(大文字小文字どちらも認識)で円周率を定義<br>
・PIを用いた計算も可能<br>
・()の中やsinと()の間に空白があっても計算可能<br>
※rad表記のみ<br>
<br>
### ・e、対数関数の演算<br>
eを底とした対数関数「<span style="color: red; ">log(演算)</span>」(大文字小文字どちらでも認識)<br>
e(大文字小文字どちらでも認識)でネイピア数を定義<br>
・eを用いた計算も可能<br>
・()の中やlogと()の間に空白があっても計算可能<br>
<br>
### ・べき乗の演算<br>
べき乗「<span style="color: red; ">数^数</span>」<br>
・数だけでなくsinやlogと一緒に使うことが可能<br>
・数と^の間に空白があっても計算可能<br>
<br>
### ・階乗、割合の実装<br>
階乗「<span style="color: red; ">数！</span>」<br>
割合(数%は何倍になるか)「<span style="color: red; ">数%</span>」<br>
・数と！や％の間に空白があっても計算可能<br>
<br>
### ・ルートの実装<br>
ルート「<span style="color: red; ">r数</span>」<br>
・rの間に空白があっても計算可能<br>
### ・Save機能の実装<br>
前の計算結果を保存する機能「<span style="color: red; ">save</span>」(小文字のみ)<br>
・saveができると「数を保存しました」と出力される<br>
・もし一番最初の処理であれば、saveを押しても数字がないため「まだ保存できる数値がありません」と出力される<br>
<br>
### ・Call機能の実装<br>
saveした数字を呼び出す「<span style="color: red; ">call</span」(小文字のみ)<br>
・callをした<span style="color: red; ">数字にさらに計算を加えることができる</span><br>
<br>
### ・終了機能の実装<br>
任意のタイミングで計算機を閉じる「<span style="color: red; ">finish</span>」(小文字のみ)<br>
・計算機は毎回結果がリセットされ、次の計算が準備される<br>
・この計算機はfinish、割り算を0で割ったとき、剰余を0で割ったとき、終了する<br>
