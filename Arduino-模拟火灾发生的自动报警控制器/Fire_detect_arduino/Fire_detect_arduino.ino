volatile float tmp;
int gas;
int key;

void setup()
{
  Serial.begin(9600);
  Serial.println("Detection begin!");
  tmp = 0;
  gas = 0;
  pinMode(8, OUTPUT);
  pinMode(3, INPUT);
  pinMode(9, INPUT);
}

void loop()
{ 
  tmp = analogRead(A0)*0.488;
  gas = digitalRead(3);
  key = digitalRead(9);
  if (tmp >= 50 || gas == 1) {  
    digitalWrite(9,HIGH);
    if(key==1){
      digitalWrite(2,HIGH);
      tone(8,500);
      delay(500);
    }else if(key==0){
      digitalWrite(2,LOW);
      noTone(8);  
    }
  } 
  else if (tmp < 50 && gas == 0) {
    digitalWrite(2,LOW);
    noTone(8);
  }
  
  Serial.print("Temperature for the device is: ");
  Serial.println(tmp); 
  Serial.print("Gas for the device is: ");
  Serial.println(gas);
  delay(500); 
}
