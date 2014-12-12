int incomingByte = 0;   // for incoming serial data
int count = 0 ;
int cmd = 0 ;
float Attitude [6] ;
byte temp [50];
char string[50];
char stx = 0xFE ;
int byte_left = 1000;
boolean stage  = true  ;
String flight_mode  = "";
int mav_type = 0;
int arm_status = 0;
int  fix_type = 0;
int  sat_visible =0;
int  eph = 0;
int voltage_batt =0;
int heading = 0;
int rc_ch[8] ;
float roll = 0.0;
float pitch = 0.0;
float yaw = 0.0;
float alt = 0.0;
float ground_speed =0.0 ;
void setup() {
  //initialize
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
  }
  if (Serial1.available() > 0) {
    byte  c = Serial1.read();
    if (c == stx   ) {
      count = 0 ;
    }
    else if (count == 1 )
    {
      cmd = c ;
      Serial.print("cmd1 : ");
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
          byte_left = 8;
          break ;
      }
    }
    else if (count <= (byte_left + 1))
    {
      temp[count - 2] = c ;
      if (count == byte_left + 1)
      {
        switch (cmd)
        {
          case 11 :
            { byte temp_string[10] ;
              for (int i = 0 ; i < 9; i++ )
              {
                temp_string[i] = temp[i];
              }
              flight_mode  = read_string(temp_string, 10);
              mav_type = read_int8(temp[10]);
              arm_status = read_int8(temp[11]);
              Serial.println("case 11 ");
              Serial.print("Flight_mode : ");
              Serial.println(flight_mode);
              Serial.print("mav_type : ");
              Serial.println(mav_type);
              Serial.print("arm_status : ");
              Serial.println(arm_status);

            } break ;
          case 12 :
            { fix_type = read_int8(temp[0]);
              sat_visible = read_int8(temp[3]);
              eph = read_int16(temp[1], temp[2]);
              voltage_batt = read_int16(temp[4], temp[5]);
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
                temp_float[i] = temp[i];
              }
               roll = read_float(temp_float);
              for (int i = 4 ; i < 8; i++)
              {
                temp_float[i - 4] = temp[i];
              }
               pitch = read_float(temp_float);
              for (int i = 8 ; i < 12; i++)
              {
                temp_float[i - 8] = temp[i];
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
                temp_float[i] = temp[i];
              }
               alt = read_float(temp_float);
               heading = read_int16(temp[4], temp[5]);
              for (int i = 6 ; i < 9; i++)
              {
                temp_float[i - 6] = temp[i];
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
                rc_ch[i] = read_int8(temp[i]);
                Serial.print("RC_CH :");
                Serial.print(i);
                Serial.println(rc_ch[i]);
              }
            } break ;
        }
      }
    }
    count = count + 1  ;
  }
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


