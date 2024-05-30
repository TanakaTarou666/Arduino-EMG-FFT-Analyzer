# Arduino EMG FFT Analyzer

## 概要
このプロジェクトは、Arduinoを使用して筋電位（EMG）信号を取得し、FFT（高速フーリエ変換）を行って周波数成分を分析するものです。EMG信号の周波数分析により、筋肉の活動状態や疲労度などを評価することができます。

## 用いたハードウェア
- Arduino Uno R4 wifi
- Grove-EMG_Sensor_v1.1_SCH

## 必要なソフトウェア
- Arduino IDE 2.3.2（バージョン1.xでは動作しません）
- arduinoFFT 1.6.2（バージョン2.xでは動作しません）

## セットアップとインストール
1. ハードウェアを接続します（emg_ex.jpgおよびGrove-EMG_Sensor_v1.1_SCH.pdfを参照）。
2. Arduino IDEをインストールし、FFTライブラリをインストールします。
3. `fft_analyzer.ino`をArduino IDEで開き、コードをアップロードします。

## 使用方法
1. シリアルモニタ、シリアルプロッタを開きます。
2. EMG信号の周波数成分が表示されることを確認します。

## ライセンス
このプロジェクトはMITライセンスの下で提供されています。
