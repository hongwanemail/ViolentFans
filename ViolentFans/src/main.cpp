#include <Arduino.h>

int val = 50;    //定义速度
#define KEY_L 4  //宏定义按键引脚
#define KEY_M 14 //宏定义按键引脚
#define KEY_R 12 //宏定义按键引脚

void setup()
{
  pinMode(13, OUTPUT);  //设置引脚模式
  analogWrite(13, val); //设置初始化占空比0%

  pinMode(KEY_L, INPUT_PULLUP); //按键初始化
  pinMode(KEY_M, INPUT_PULLUP); //按键初始化
  pinMode(KEY_R, INPUT_PULLUP); //按键初始化
  Serial.begin(115200);         //设置串口波特率9600
}

void loop()
{
  if (digitalRead(KEY_L) == 0) //当按键按下，进入检测
  {
    val++;
    if (val >= 150)
      val = 150;
    analogWrite(13, val); //给指定引脚写入数据
    delay(25);            //按键按下延时消抖25ms
    Serial.println("KEY_L");
  }

  if (digitalRead(KEY_M) == 0) //当按键按下，进入检测
  {
    if (val != 0)
      analogWrite(13, 0); //给指定引脚写入数据
    else
      analogWrite(13, val); //给指定引脚写入数据
    delay(25);              //按键按下延时消抖25ms
    while (!(digitalRead(KEY_M)))
      ;        //一直循环，直到按键释放，跳出死循环
    delay(25); //按键松开延时消抖25ms

    Serial.println("KEY_M");
  }

  if (digitalRead(KEY_R) == 0) //当按键按下，进入检测
  {
    val--;
    if (val <= 0)
      val = 0;
    analogWrite(13, val); //给指定引脚写入数据
    delay(25);            //按键按下延时消抖25ms
    Serial.println("KEY_R");
  }
}