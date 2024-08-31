# Arduino-声音模拟程序设计

本设计模拟了警车、救护车、消防车的警报声，通过调节频率变化和声音延迟实现

参考国家规定的车用电子警报器标准，如下图：

![image-20231022192856014](C:\Users\缪子翔\AppData\Roaming\Typora\typora-user-images\image-20231022192856014.png)

编写三种车辆的报警函数

```C
//警车
void playPolice(){
  while(playingAlarm){
        if(UP){
          for(i=0;i<900;i++){
            tone(13,freq);
            delay(0.2875);
            freq++;
            if(freq==1500){
              UP=0;  
            }
          }
        }else{
          tone(13,freq);
          delay(0.125);
          freq--;
          if(freq==600){
              UP=1;  
          }
        }
        if(mode!=1)break;
      }
}
//救护车
void playAmbulance(){
  while(playingAlarm){  
     tone(13,freq1);
     delay(600);
     tone(13,freq2);
     delay(600);
     if(mode!=2)break;
  }
}
//消防车
void playFire(){
  while(playingAlarm){
      if(UP){
      for(i=0;i<900;i++){
        tone(13,freq);
        delay(2.22);
        freq++;
        if(freq==1500){
          UP=0;  
        }
      }
      }else{
        tone(13,freq);
        delay(2.22);
        freq--;
        if(freq==600){
            UP=1;  
        }
      }
      if(mode!=3)break;
  }
}
```

通过添加按键实现切换不同报警声，通过外部中断，当数字引脚2处于下降沿时触发中断函数

```C
// 配置外部中断 使用数字引脚2并配置下降沿触发中断
  attachInterrupt(digitalPinToInterrupt(2),switchmode, FALLING); 
```

```C
//中断函数
int switchmode(){
  noTone(buzzerPin); // 停止报警声
  delay(1000); 
  if(mode>=3){
    mode = 0;    
  }
  return ++mode;
}
```

使用`switch`语句切换报警声，并在串口打印相关信息

```C
switch(mode){
    case 1:
      Serial.println("警车驶过报警声模拟\n");
      playingAlarm = true;
      playPolice();
      break;
   case 2:
     Serial.println("救护车驶过报警声模拟\n");
     playingAlarm = true;
     playAmbulance();
     break;
   case 3:
     Serial.println("消防车驶过报警声模拟\n");
     playingAlarm = true;
     playFire();
     break;
   default:
     noTone(buzzerPin);
     break; 
}
```

