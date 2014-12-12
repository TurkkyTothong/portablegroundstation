#include <UTFT.h>
#include <UTFT_CTE.h>

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
// Set up UTFT for CTE32 Wide 400x240 on Arduino Due
UTFT myGLCD(CTE32W,25,26,27,28);
UTFT_CTE CTE_LCD(&myGLCD);
char buf[10];
int x = 0 ; 
int  time_o,time_n = 0;
int temp = 48 ; 
int px = 30 ;
int py = 30 ;
String a = "a" ; 
String b = "a" ; 
int i = 0; 

void setup()
{
  delay(1000);
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(VGA_BLACK);
  CTE_LCD.SPI_Flash_init(FLASH_CS_PIN);
  Serial.begin(57600);
  Serial1.begin(9600);
}
void loop()
{
      Page_1();
}

void Page_1()
{
   myGLCD.setFont(BigFont);
   myGLCD.print("ARM/DISARM", 10,10);
   myGLCD.print("MODE", 300,10);
   myGLCD.setFont(SmallFont);
   
   myGLCD.print("Dis To WP", 10,75);
   myGLCD.print("GPS Status", 10,110);
   myGLCD.print("Flight Time", 10,150);
   myGLCD.print("No.of Satellite", 210,75);
   myGLCD.print("HDOP",210,110);
   myGLCD.print("Altitude",210,150);
}
void Page_1_var(int DistoWP,int NoSat ,int Hdop,int Att,int Battery )
{
   sprintf(buf,"%d",DistoWP);
   myGLCD.setFont(BigFont);
   myGLCD.print(buf, 10,90);
   myGLCD.print("GPS Lock", 10,125);
   sprintf(buf,"%d",NoSat);
   myGLCD.print(buf, 210,90);
   sprintf(buf,"%d",Hdop);
   myGLCD.print(buf, 210,125);
   sprintf(buf,"%d",Att);
   myGLCD.print(buf, 210,165);
   myGLCD.setFont(SevenSegNumFont);
   myGLCD.print("10", 10,165);
   Battery_percentage(Battery);
  
}
// Draw rc Chanel 
void RC_chanel()
{
  myGLCD.setFont(SmallFont);
  myGLCD.print("yaw", 95,20);
  myGLCD.drawRect(10,10,195,40); //185
  myGLCD.print("Throttle",50,110); 
  myGLCD.drawRect(10,50,40,190); // 140
  myGLCD.print("Pitch",120,130);
  myGLCD.drawRect(165,50,195,190);//140
  myGLCD.print("roll", 95,210);
  myGLCD.drawRect(10,200,195,230); //185
  myGLCD.print("Radio 5", 270,25);
  myGLCD.print("Radio 6", 270,60);
  myGLCD.print("Radio 7", 270,100);
  myGLCD.print("Radio 8", 270,140);
  myGLCD.drawRect(205,10,390,40);
  myGLCD.drawRect(205,50,390,80);
  myGLCD.drawRect(205,90,390,120);
  myGLCD.drawRect(205,130,390,160);
}
//Draw Battery Percentage 
void Battery_percentage(int percent)
{
  int x = (percent*3.99);
   myGLCD.drawRect(0,35,399,65);
   myGLCD.fillRect(0,35,x,65) ;
}
// Write RC value 
void write_RC_chanel(int pitch ,int roll ,int thottle,int yaw)
{
  //myGLCD.clrScr();
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(0,0,200,239); //185
  myGLCD.setColor(255,255,0);
  myGLCD.fillRect(10,10,10+(yaw*1.85),40);
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(10,50,40,190); // 140
  myGLCD.setColor(255,255,0);
  myGLCD.fillRect(10,50,40,50+(thottle*1.4));
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(165,50,195,190);//140
  myGLCD.setColor(255,255,0);
  myGLCD.fillRect(165,50,195,50+(pitch*1.4));
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(10,200,195,230); //185 
  myGLCD.setColor(255,255,0);
  myGLCD.fillRect(10,200,10+(roll*1.85),230);
}

void Measure_time_interface()
{
    Page_1();
  time_o = millis();
  Page_1_var(x,x,x,x,x);
  Serial.print(time_o-time_n);
  Serial.print("  ");
  Serial.println(x);
  time_n = time_o;
  x++;
}
void linear_charecter_testing()
{
    while(i<10){
  time_o = millis();
  myGLCD.print(a, px,py);
  Serial.print(a);
  Serial.print("  : ");
  Serial.print(time_o-time_n);
  Serial.println(" ms");
  a += b ;
  temp = temp ++; 
  py += 10 ;
  time_n = time_o;
  i++ ;   }
}
void seq_charecter_testing()
{
    while(temp<127)
  {
    
      Serial.write(temp);
      Serial.print(" : ");
      sprintf(buf,"%c",temp);
      time_o = millis();
      myGLCD.print(buf, px,py);
      Serial.print(time_o-time_n);
      Serial.println(" ms");
      temp = temp ++; 
      time_n = time_o;
      px += 10 ; 
      if(px>350)
      {
        px = 30; 
        py = py + 10;
      }
 }
}


