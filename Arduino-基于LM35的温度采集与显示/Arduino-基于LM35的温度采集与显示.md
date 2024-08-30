# Arduino-基于LM35的温度采集与显示

## 电路设计原理

![Tmp_detect](..\Arduino-基于LM35的温度采集与显示\source code and design files\img\Tmp_detect.png)

### 总体架构

主控采用 `arduino UNO R3`，包含LM35温度传感器、I2C协议的OLED12864显示屏、8位WS2812灯带、COMPIN串口调试、NPN三极管和风扇驱动电机和开关。

### 设计原理

- 通过LM35温度传感器检测温度状态，并在OLED屏幕上显示当前温度信息。
- LM35温度传感器采用模拟量输入，因此连接至`arduino`的`A0`引脚。
- OLED显示屏采用IIC总线协议，因此需要将数据线（SDA）和时钟线（SCL）的引脚分别连接至`arduino`的SCL和SDA引脚，位于A4和A5。
- 温度设有上限和下限，当温度<15℃时，WS2812灯带为蓝色，当温度在15℃与30℃之间时，WS2812灯带为绿色，当温度>30℃时，WS2812灯带为红色。
- 在温度＞30℃后，风扇启动，OLED屏幕显示风扇的启动状态和风扇的转速。当温度在30℃至40℃之间时，风扇为低速运转；当温度在40℃至50℃之间时，风扇为中速运转；当温度在50℃以上时，风扇为高速运转。
- 可通过开关控制风扇的开启和关闭，OLED显示屏上风扇的启动状态对应改变。
- 串口打印当前温度信息和风扇的转速。
- 通过NPN三极管放大控制风扇转速的模拟量，风扇的转速通过PWM占空比控制。

## 程序设计原理

***1、库文件的调用***

​        由于使用OLED12864显示屏需要调用`<U8g2lib.h>和<Wire.h>`库文件，因此在程序开始部分引入该库文件。`<U8g2lib.h>`的开源网址位于 [olikraus/u8g2: U8glib library for monochrome displays, version 2 (github.com)](https://github.com/olikraus/u8g2)

```C
#include <U8g2lib.h>
#include <Wire.h>
#include <FastLED.h>
```

> `<U8g2lib.h>`库是一款用于嵌入式系统的图形库，用于驱动各种液晶屏幕和OLED显示屏，可实现文本的显示和图形的绘制，库内置了多种字体，包括 ASCII 字符、Unicode 字符、符号和图标，可通过选择合适的字体来显示文本和图形。
>
> `IIC`总线协议的使用需要调用`<Wire.h>`库文件。
>
> `<FastLED.h>`库用于`ws2812`灯带的驱动。

***2、u8g2的初始化***

```C
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0,SCL,SDA,U8X8_PIN_NONE); 
```

​       该代码用于创建一个U8G2库的对象`U8G2_SSD1306_128X64_NONAME_1_SW_I2C` 表示使用一个128x64像素分辨率的SSD1306型号的OLED显示屏，采用软件I2C通信接口协议。`(U8G2_R0, SCL, SDA, U8X8_PIN_NONE)`对u8g2的参数进行初始化。

- `U8G2_R0`：指定了显示屏的旋转方向。`U8G2_R0` 表示不进行旋转，即正常方向。

- `SCL`：用于I2C通信的时钟线的引脚。连接到Arduino的SCL引脚。
- `SDA`：用于I2C通信的数据线的引脚。连接到Arduino的SDA引脚。
- `U8X8_PIN_NONE`：表示没有使用其他控制引脚。

***3、`setup()`启动函数的编写***

```C
void setup() {
  Serial.begin(9600);
  Serial.println("Detection begin!");
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(Key_Pin,INPUT_PULLUP);
  
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  u8g2.begin();
  //WS2812启动，流水灯效果
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
```

​       `setup()`函数中首先启动串口，将波特率设为9600，并在串口打印`Detection begin!`。其次启用`LED_PIN`和`Key_Pin`，分别设为`OUTPUT`输出模式和`INPUT_PULLUP`上拉电阻模式。随后初始化WS2812灯带和u8g2 OLED显示屏。WS2812的启动设置了流水灯效果，提升用户的交互体验。其中流水灯的RGB颜色通过随机函数`random`取得，每个WS2812LED灯点亮不同的颜色。

*** 4、`tmp_fan_control()`温度控制风扇和OLED显示函数的编写***

```C
void tmp_fan_control(){
  tmp = analogRead(A0)*0.488;
  //温度上下限比较  
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
  FastLED.setBrightness(Bright);//设置WS2812亮度
  FastLED.show();
}
```

​       该函数首先读取`A0`引脚所连接的LM35温度传感器的数据，通过`tmp = analogRead(A0)*0.488`将读取到的数据转换为温度值。由于LM35输出电压与摄氏温度成正比一一温度每上升一摄氏度，输出电压上升10mV。因此，使用`Arduino`的模拟输入口读取LM35温度传感器输出的模拟值，再使用以下公式将其换算为对应的摄氏温度： `tmp = (5.0×analogRead(LM35)×100.0) / 1024  `即`tmp = analogRead(A0)*0.488`.

​       随后进行温度值与温度上下限的比较，`tmp<15℃`WS2812显蓝色，风扇处于关闭状态；`tmp>=15℃且tmp<30℃`WS2812显绿色，风扇处于关闭状态；`tmp>=30℃`WS2812显红色，并判断风扇开关状态，若风扇开关关闭（导通），则启动风扇，若风扇开关断开，则不启动风扇。

​       在风扇启动后，再次判断温度区间，根据温度区间调整风扇的转速，转速分为低中高。当温度`tmp>=30℃且tmp<=40℃`风扇处于低转速；当温度`tmp>40℃且tmp<=50℃`风扇处于中转速；当温度`tmp>50℃`风扇处于高转速。

​       风扇的转速通过`anologWrite`控制PWM占空比，`analogWrite(Fan_Pin,speed)`中的speed最大值为255，当`speed=128`时转速即为50%，当`speed=255`时转速即为100%。

***5、`oled_display()`OLED显示函数的编写***

```C
void oled_display(){
  char tmp_str[5];
  char m_str[]="Tmp:";
  dtostrf(tmp,1,0,tmp_str);
  strcat(m_str,tmp_str);
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_unifont_t_weather);
    u8g2.drawGlyph(0,20,0x0031);//温度计图标
    u8g2.setFont(u8g2_font_cu12_t_symbols);
    u8g2.drawStr(16,20,m_str);
    u8g2.drawGlyph(70,20,0x2103);//℃图标
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
      u8g2.drawGlyph(0,60,0x2724);//风扇图标
      u8g2.setFont(u8g2_font_cu12_t_symbols);
      u8g2.drawStr(18,60,s_str);
    }
  } while ( u8g2.nextPage() );
} 
```

- u8g2通过`firstPage()`和`nextPage`函数和`do{}while()`循环语句实现翻页刷新显示的效果。并将温度值`tmp`转换为字符串，以供u8g2输出。
- 设置字体样式和图标样式

​       在`do{}while()`循环体内设置u8g2显示的字体样式，和显示的图标样式，其中温度计等图标Font通过在`github`查找u8g2开源项目文件中的`Font Group`找到对应的图标和字体。<img src="C:\Users\缪子翔\AppData\Roaming\Typora\typora-user-images\image-20231031145757318.png" alt="image-20231031145757318" style="zoom:50%;" />

**以摄氏温度图标`℃`为例**

> 找到`cu12`相关的含`℃`图标的字体样式。
>
> 设置字体样式`u8g2.setFont(u8g2_font_cu12_t_symbols);`
>
> 绘制图标`u8g2.drawGlyph(70,20,0x2103);//℃图标`，其中70为Font的x横坐标，20为Font的y纵坐标，0x2103为`℃`图标的十六进制数。

- `u8g2.drawStr(16,40,fan_start?"Fan Start":"Fan Stop");`该语句通过条件运算符判断风扇的启动和停止状态，在OLED显示屏上输出对应的字符串。

- 若风扇启动，判断风扇转速，在OLED屏幕上输出对应的字符串。

  ```C
  if(speed == 77){
      strcpy(speed_str,"Low");
  }else if(speed == 128){
      strcpy(speed_str,"Middle");
  }else if(speed == 255){
      strcpy(speed_str,"High");
  }
  ```

***6、`Serial_print()`串口打印函数***

```C
void Serial_print(){
  Serial.print("Temperature for the device is: ");
  Serial.println(tmp);
  Serial.print("Fan Speed:"); 
  Serial.println(speed);
}
```

串口打印温度和风扇转速信息。

***7、`loop()`循环函数***

```C
void loop() {
  k_fan=digitalRead(Key_Pin);
  tmp_fan_control();
  oled_display();
  Serial_print();
}
```

`k_fan`读取`Key_Pin`的状态值，`k_fan`为0风扇启动，为1风扇不启动。