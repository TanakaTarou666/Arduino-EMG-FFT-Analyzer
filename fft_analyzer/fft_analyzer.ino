#include "arduinoFFT.h"

arduinoFFT FFT;

const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const double samplingFrequency = 2000;
const double signalFrequency = 1000;
const uint8_t amplitude = 100;

double vReal[samples];
double vImag[samples];
double vReal_fft[samples];
double vImag_fft[samples];

void setup() {
  // シリアル通信を開始します（9600bps）
  Serial.begin(115200);
  for (uint16_t i = 0;i < samples; i++)
  {
    vReal[i] = analogRead(A1);
    vImag[i] = 0.0;
    delay(8);
  }
}

void loop() {
  for (uint16_t i = 0;i < 56; i++)
  {
    vReal[i] = vReal[i+8];
    vImag[i] = 0.0;
    vReal_fft[i]= vReal[i];
  }

  for (uint16_t i = 56;i < samples; i++)
  {
    vReal[i] = analogRead(A1);
    vImag[i] = 0.0;
    vReal_fft[i]= vReal[i];
    delay(8);
  }


  FFT = arduinoFFT(vReal_fft, vImag, samples, samplingFrequency);
  FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(FFT_FORWARD);
  FFT.ComplexToMagnitude();

  PrintVectorPlot(vReal_fft, (samples >> 1));
}

void PrintVectorPlot(double *vData, uint16_t bufferSize)
{
  int a =0;
  for (uint16_t i = 0; i < bufferSize; i++)
  {
    if(vData[i] <1000){
    // Serial.print(vData[i], 4);
    if(i>8 && i<24){
      a += vData[i];
    }
    }else{
      // Serial.print(0, 4);
    }
    // Serial.print(" , ");
    // Serial.print(200);
    // Serial.println();
  }
  
  Serial.print(400);
  Serial.print(" , ");
  Serial.println(a);
}