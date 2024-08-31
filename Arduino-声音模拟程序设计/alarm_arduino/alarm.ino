int mode=0;
int buzzerPin = 13;
int UP=1;
int i;
unsigned int freq=600;
unsigned int freq1=800;
unsigned int freq2=1000;
bool playingAlarm;

int switchmode();

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT); 
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  Serial.println("开始报警，按下按键切换不同报警声：\n");
  // 配置外部中断
  attachInterrupt(digitalPinToInterrupt(2),switchmode, FALLING); // 使用数字引脚2并配置下降沿触发中断
}

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
void playAmbulance(){
  while(playingAlarm){  
     tone(13,freq1);
     delay(600);
     tone(13,freq2);
     delay(600);
     if(mode!=2)break;
  }
}
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
int switchmode(){
  noTone(buzzerPin); // 停止报警声
  delay(1000); 
  if(mode>=3){
    mode = 0;    
  }
  return ++mode;
}

void loop() { 
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
}
