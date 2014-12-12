#include <UTFT.h>
#include <UTFT_CTE.h>
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
int page_reference = 1 ;
long time_5hz = 0;
int incomingByte = 0;   // for incoming serial data
int count = 0 ;
int cmd = 0 ;
float Attitude [6] ;
byte read_buff [50];
char string[50];
char stx = 0xFE ;
int byte_left = 0;
boolean stage  = true  ;
String flight_mode  = "";
int mav_type = 0;
int arm_status = 0;
int  fix_type = 0;
int  sat_visible = 0;
int  eph = 0;
int voltage_batt = 0;
int heading = 0;
int rc_ch[8] ;
float roll = 0.0;
float pitch = 0.0;
float yaw = 0.0;
float alt = 0.0;
float ground_speed = 0.0 ;
UTFT myGLCD(CTE32W, 25, 26, 27, 28);
UTFT_CTE CTE_LCD(&myGLCD);
char buf[10];
int aaa = 0 ;
void setup() {
  //initialize
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(VGA_BLACK);
  CTE_LCD.SPI_Flash_init(FLASH_CS_PIN);
  Serial.begin(57600);
  Serial1.begin(57600);
  Serial.print("Start");
}
void loop() {
  if (Serial.available() > 0)
  {
    char c = Serial.read();
    if (c == 'a')
    {
      Serial.print("start") ;
      Serial1.print(stx);
      Serial1.print((char)0x00);
    }
    else if (c == 'b')
    {
      Serial.print("Stop") ;
      Serial1.print(stx);
      Serial1.print((char)0x01);
    }
    else if (c == 'q')
    {
      myGLCD.clrScr();

      page_reference ++ ;

    }
    else if (c == 'w')
    {
      myGLCD.clrScr();

      page_reference -- ;
    }

  }
  if (Serial1.available() > 0) {
    byte  c = Serial1.read();
    if (c == stx  && count >= byte_left + 2 ) {
      count = 0 ;
    }
    else if (count == 1 )
    {
      cmd = c ;
      Serial.print("cmd  : ");
      Serial.println(cmd);
      switch (cmd) {
        case  11 :  // CMD = 11 Heart beat (flight mode / Mavtype / Flight Status)
          byte_left = 12 ;
          break ;
        case 12 :  // CMD = 12 EXTEND status (fixtype/eph/sat_view/voltage_batt)
          byte_left = 6  ;
          break ;
        case 13 :  // CMD = 13 EXTRA 1 (ROll/PITCH/YAW)
          byte_left = 12 ;
          break ;
        case 14 : //CMD = 14 EXTRA 2 (Altitude/Heading/Ground speed)
          byte_left = 10 ;
          break ;
        case 15 :  //CMD = 15 RC_CH (RC_data)
          byte_left = 16;
          break ;
      }
    }
    else if (count <= (byte_left + 1))
    {
      read_buff[count - 2] = c ;
      if (count == byte_left + 1)
      {
        switch (cmd)
        {
          case 11 :
            { byte temp_string[10] ;
              for (int i = 0 ; i <= 9; i++ )
              {
                temp_string[i] = read_buff[i];
              }
              flight_mode  = read_string(temp_string, 10);
              mav_type = read_int8(read_buff[10]);
              arm_status = read_int8(read_buff[11]);
              Serial.println("case 11 ");
              Serial.print("Flight_mode : ");
              Serial.println(flight_mode);
              Serial.print("mav_type : ");
              Serial.println(mav_type);
              Serial.print("arm_status : ");
              Serial.println(arm_status);

            } break ;
          case 12 :
            { fix_type = read_int8(read_buff[0]);
              sat_visible = read_int8(read_buff[3]);
              eph = read_int16(read_buff[1], read_buff[2]);
              voltage_batt = read_int16(read_buff[4], read_buff[5]);
              Serial.println("case : 12 ");
              Serial.print("fix_type : ");
              Serial.println(fix_type);
              Serial.print("sat_visible : ");
              Serial.println(sat_visible);
              Serial.print("eph : ");
              Serial.println(eph);
              Serial.print("voltage_batt : ");
              Serial.println(voltage_batt);
            } break ;
          case 13 :
            { byte temp_float [4];
              for (int i = 0 ; i < 4; i++)
              {
                temp_float[i] = read_buff[i];
              }
              roll = read_float(temp_float);
              for (int i = 4 ; i < 8; i++)
              {
                temp_float[i - 4] = read_buff[i];
              }
              pitch = read_float(temp_float);
              for (int i = 8 ; i < 12; i++)
              {
                temp_float[i - 8] = read_buff[i];
              }
              yaw = read_float(temp_float);
              Serial.println("case : 13 ");
              Serial.print("roll : ");
              Serial.println(roll);
              Serial.print("pitch : ");
              Serial.println(pitch);
              Serial.print("yaw : ");
              Serial.println(yaw);
            } break ;
          case 14 :
            {
              byte temp_float[4];
              for (int i = 0 ; i < 4; i++)
              {
                temp_float[i] = read_buff[i];
              }
              alt = read_float(temp_float);
              heading = read_int16(read_buff[4], read_buff[5]);
              for (int i = 6 ; i < 9; i++)
              {
                temp_float[i - 6] = read_buff[i];
              }
              ground_speed = read_float(temp_float);
              Serial.println("case 14");
              Serial.print("alt : ");
              Serial.println(alt);
              Serial.print("heading : ");
              Serial.println(heading);
              Serial.print("ground speed : ");
              Serial.println(ground_speed);
            } break;
          case 15 :
            {
              Serial.println("case 15");
              rc_ch[8] ;
              for (int i = 0 ; i < 8 ; i++)
              {
                rc_ch[i] = read_int16(read_buff[2 * i], read_buff[(2 * i) + 1]);
                Serial.print("RC_CH :");
                //Serial.print(i);
                Serial.println(rc_ch[i]);
              }
            } break ;

        }
        for (int i = 0 ; i < 50 ; i++)
        {
          read_buff[i] = 0;
        }
      }
    }
    count = count + 1  ;
  }
  if (millis() - time_5hz >= 200)
  {
    switch (page_reference) {
      case 1:
         //myGLCD.clrScr();     
        Page_1_var( 20.5, sat_visible , eph, alt , aaa);
        // statements
        break;
      case 2:
         //myGLCD.clrScr();

        Page_2();
        // statements
        break;
      case 3:
        write_RC_chanel();
        RC_chanel();
        // statements
        break;
    }
    time_5hz = millis();
  }
  //aaa ++ ;
}
typedef union {
  byte array[4];
  float value;
} ByteToFloat;

float convert(byte* data) {
  ByteToFloat converter;
  for (byte i = 0; i < 4; i++) {
    converter.array[3 - i] = data[i];
  }
  Serial.print(" ");
  return converter.value;
}
void string_clr()
{
  for (int i = 0 ; i < 50; i++)
  {
    string[i] =  0 ;
  }
}
String read_string(byte data[], int data_length)
{
  char string[data_length];
  for (int i = 0 ; i < data_length; i++)
  {
    string[i] = data[i];
  }
  return string ;
}
int read_int8(byte data)
{
  return data ;
}
int read_int16(byte data1, byte data2)
{
  return (data1 << 8)  + data2 ;
}
float read_float(byte data[])
{
  return convert(data);
}
void Page_1()
{
  myGLCD.setFont(BigFont);
  myGLCD.print(flight_mode, 220, 10);
  myGLCD.setFont(SmallFont);
  myGLCD.print("Dis To WP", 10, 75);
  myGLCD.print("GPS Status", 10, 110);
  myGLCD.print("Flight Time", 10, 150);
  myGLCD.print("No.of Satellite", 210, 75);
  myGLCD.print("HDOP", 210, 110);
  myGLCD.print("Altitude", 210, 150);
}
void Page_1_var(float DistoWP, int NoSat , float Hdop, float Att, int Battery )
{

  myGLCD.setFont(BigFont);
  myGLCD.print(flight_mode, 220, 10);
  myGLCD.setFont(SmallFont);
  myGLCD.print("Dis To WP", 10, 75);
  myGLCD.print("GPS Status", 10, 110);
  myGLCD.print("Flight Time", 10, 150);
  myGLCD.print("No.of Satellite", 210, 75);
  myGLCD.print("HDOP", 210, 110);
  myGLCD.print("Altitude", 210, 150);

  //////////////////////////////////////////

  sprintf(buf, "%.2f", DistoWP);
  myGLCD.setFont(BigFont);
  myGLCD.print(buf, 10, 90);
  String temp = "";
  switch (fix_type) {
    case 0 :
      temp = "No GPS";
      break ;
    case 1 :
      temp = "No FIX ";
      break ;
    case 2 :
      temp = "2D FIX";
      break;
    case 3 :
      temp = "3D FIX";
      break;
  }
  myGLCD.print(temp, 10, 125); //print gps status
  switch (arm_status) {
    case 0 :
      temp = "DISARM";
      break ;
    case 1 :
      temp = "   ARM";
      break ;
  }
  myGLCD.print(temp, 10, 10); //print arm status
  sprintf(buf, "%d", NoSat);
  myGLCD.print(buf, 210, 90);
  sprintf(buf, "%.2f", Hdop);
  myGLCD.print(buf, 210, 125);
  sprintf(buf, "%.2f", Att);
  myGLCD.print(buf, 210, 165);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print("10", 10, 165);
  Battery_percentage(Battery);
}
void Page_2()
{
  myGLCD.setFont(BigFont);
  String temp = "";
  switch (arm_status) {
    case 0 :
      temp = "DISARM";
      break ;
    case 1 :
      temp = "   ARM";
      break ;
  }
  myGLCD.print(temp, 10, 10); //print arm status
  myGLCD.print(flight_mode, 220, 10);
  Battery_percentage(50);
  myGLCD.setFont(SmallFont);
  myGLCD.print("Roll", 10, 75);
  myGLCD.print("Pitch", 210, 75);
  myGLCD.print("Yaw", 10, 120);
  myGLCD.print("Compass", 210, 120);
  myGLCD.print("Ground Speed", 10, 170);
  myGLCD.print("Type", 210, 170);
  myGLCD.setFont(BigFont);
  sprintf(buf, "%.2f", roll );
  myGLCD.print(buf, 10, 95);
  sprintf(buf, "%.2f", pitch );
  myGLCD.print(buf, 210, 95);
  sprintf(buf, "%.2f", yaw );
  myGLCD.print(buf, 10, 145);
  sprintf(buf, "%d", heading );
  myGLCD.print(buf, 210, 145);
  sprintf(buf, "%.2f", ground_speed );
  myGLCD.print(buf, 10, 195);
}
// Draw rc Chanel
void RC_chanel()
{
  myGLCD.setFont(SmallFont);
  myGLCD.print("yaw", 95, 20);
  myGLCD.drawRect(10, 10, 195, 40); //185
  myGLCD.print("Throttle", 50, 110);
  myGLCD.drawRect(10, 50, 40, 190); // 140
  myGLCD.print("Pitch", 120, 130);
  myGLCD.drawRect(165, 50, 195, 190); //140
  myGLCD.print("roll", 95, 210);
  myGLCD.drawRect(10, 200, 195, 230); //185
  myGLCD.print("Radio 5", 270, 25);
  myGLCD.print("Radio 6", 270, 60);
  myGLCD.print("Radio 7", 270, 100);
  myGLCD.print("Radio 8", 270, 140);
  myGLCD.drawRect(205, 10, 390, 40);
  myGLCD.drawRect(205, 50, 390, 80);
  myGLCD.drawRect(205, 90, 390, 120);
  myGLCD.drawRect(205, 130, 390, 160);
}
//Draw Battery Percentage
void Battery_percentage(int percent)
{
  int x = (percent * 3.99);
  myGLCD.drawRect(0, 35, 399, 65);
  myGLCD.fillRect(0, 35, x, 65) ;
}
// Write RC value
//void write_RC_chanel(int pitch , int roll , int thottle, int yaw)
void write_RC_chanel()
{
  //yaw CH
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(0, 0, 200, 239); //185
  myGLCD.setColor(255, 255, 0);
  myGLCD.fillRect(10, 10, 10 + ((rc_ch[3] - 1000) * 0.185), 40);
  // throttle ch
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(10, 50, 40, 190); // 140
  myGLCD.setColor(255, 255, 0);
  myGLCD.fillRect(10, 190 - ((rc_ch[2] - 1000) * 0.140 ), 40, 190  ); //th
  // pitch ch
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(165, 50, 195, 190); //140
  myGLCD.setColor(255, 255, 0);
  myGLCD.fillRect(165, 190 - ((rc_ch[1] - 1000) * 0.140), 195, 190 ); //pitch
  // roll ch
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(10, 200, 195, 230); //185
  myGLCD.setColor(255, 255, 0);
  myGLCD.fillRect(10, 200, 10 + ((rc_ch[0] - 1000) * 0.185), 230); //roll

  // CH 5
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(205, 10, 390, 40);
  myGLCD.setColor(255, 255, 0);
  myGLCD.fillRect(205, 10, 205 + ((rc_ch[4] - 1000) * 0.185), 40);

  //CH 6
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(205, 50, 390, 80);
  myGLCD.setColor(255, 255, 0);
  myGLCD.fillRect(205, 50, 205 + ((rc_ch[5] - 1000) * 0.185), 80);
  //ch 7
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(205, 90, 390, 120);
  myGLCD.setColor(255, 255, 0);
  myGLCD.fillRect(205, 90, 205 + ((rc_ch[6] - 1000) * 0.185), 120);
  // ch 8
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(205, 130, 390, 160);
  myGLCD.setColor(255, 255, 0);
  myGLCD.fillRect(205, 130, 205 + ((rc_ch[7] - 1000) * 0.185), 160);
}


