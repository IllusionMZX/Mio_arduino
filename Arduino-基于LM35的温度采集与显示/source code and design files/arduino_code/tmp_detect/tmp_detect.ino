#include <U8g2lib.h>
#include <Wire.h>
#include <FastLED.h>
#define NUM_LEDS 8
#define LED_PIN 7
#define Fan_Pin 9
#define Key_Pin 6
  
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0,SCL,SDA,U8X8_PIN_NONE); 
uint8_t Bright=255;
uint8_t speed = 0;

CRGB leds[NUM_LEDS];
CRGB temp;
bool fan_start = 0;
bool k_fan = 0;
float tmp = 0;
unsigned char i = 0;
unsigned char red = random(256); // 随机红色分量
unsigned char green = random(256); // 随机绿色分量
unsigned char blue = random(256); // 随机蓝色分量
  
void setup() {
  Serial.begin(9600);
  Serial.println("Detection begin!");
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(Key_Pin,INPUT_PULLUP);
  
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  u8g2.begin();
  
  for ( i = 0; i < NUM_LEDS; i++) {
    red = random(256); 
    green = random(256); 
    blue = random(256); 
    leds[i] = CRGB(red, green, blue);
    FastLED.setBrightness(Bright);
    FastLED.show();
    delay(100); // 控制流水灯的速度
    leds[i] = CRGB(0, 0, 0); // 关闭LED
  }
}

void oled_display(){
  char tmp_str[5];
  char m_str[]="Tmp:";
  dtostrf(tmp,1,0,tmp_str);
  strcat(m_str,tmp_str);
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_unifont_t_weather);
    u8g2.drawGlyph(0,20,0x0031);
    u8g2.setFont(u8g2_font_cu12_t_symbols);
    u8g2.drawStr(16,20,m_str);
    u8g2.drawGlyph(70,20,0x2103);
    u8g2.drawStr(16,40,fan_start?"Fan Start":"Fan Stop");
    if (fan_start == 1){
      char speed_str[7];
      if(speed == 77){
        strcpy(speed_str,"Low");
      }else if(speed == 128){
        strcpy(speed_str,"Middle");
      }else if(speed == 255){
        strcpy(speed_str,"High");
      }
      char s_str[]="Speed:";
      strcat(s_str,speed_str);
      u8g2.setFont(u8g2_font_unifont_t_78_79);
      u8g2.drawGlyph(0,60,0x2724);
      u8g2.setFont(u8g2_font_cu12_t_symbols);
      u8g2.drawStr(18,60,s_str);
    }
  } while ( u8g2.nextPage() );
 
} 


void tmp_fan_control(){
  tmp = analogRead(A0)*0.488;
  if(tmp>=30){
    if(k_fan==0){
      fan_start = 1;
      
    }else if(k_fan==1){
      fan_start = 0;
      speed=0;
    }
    for( i = 0; i < NUM_LEDS; i++){
      leds[i]=CRGB::Red;
    }
    if(tmp<=40){
      if(fan_start==1)
        speed=77;
      analogWrite(Fan_Pin,speed); 
    }else if(tmp>40 && tmp<=50){
      if(fan_start==1)
        speed=128;
      analogWrite(Fan_Pin,speed);
    }else if(tmp>50){
      if(fan_start==1)
        speed=255;
      analogWrite(Fan_Pin,speed);
    }
  }else if(tmp>=15&&tmp<30){
    speed=0;
    fan_start=0;
    analogWrite(Fan_Pin,speed);
    for( i = 0; i < NUM_LEDS; i++){
      leds[i]=CRGB::Green;
    }
  }else if(tmp<15){
    speed=0;
    fan_start=0;
    analogWrite(Fan_Pin,speed);
    for( i = 0; i < NUM_LEDS; i++){
      leds[i]=CRGB::Blue;
    }
  }
  FastLED.setBrightness(Bright);
  FastLED.show();
}

void Serial_print(){
  Serial.print("Temperature for the device is: ");
  Serial.println(tmp);
  Serial.print("Fan Speed:"); 
  Serial.println(speed);
}


void loop() {
  k_fan=digitalRead(Key_Pin);
  tmp_fan_control();
  oled_display();
  Serial_print();
}
