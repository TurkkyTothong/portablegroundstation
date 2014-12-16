void setup() {
  // put your setup code here, to run once:
    pinMode(13,OUTPUT);
    Serial.begin(9600);
 }

void loop() {
  // put your main code here, to run repeatedly:
  SpeedTest();
}

void SpeedTest(void)
{
   Serial.println(F("Arduino ShowInfo"));
  register int i,j;
  volatile unsigned char c1,c2;
  volatile int v;
  volatile long l1,l2;
  volatile float f1,f2;
  int p,q,r;
  unsigned long m,n;
  float d, overhead;
  char buffer[30];


  Serial.print(F("  F_CPU = "));
  Serial.print(F_CPU,DEC);
  Serial.println(F(" Hz"));
  Serial.print(F("  1/F_CPU = "));
  Serial.print((1000000.0/(float)F_CPU),4);
  Serial.println(F(" us"));


 Serial.print(F("  nop                       : "));  
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<100; i++)
  {
    for (j=0; j<10000; j++)
    {
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
      asm volatile ("nop");
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;           // in micro seconds
  // Calculate overhead with 'nop' instruction per loop in microseconds
  overhead = d - (20.0 * (1000000.0/(float)F_CPU));
  d -= overhead;
  d /= 20.0;             // per instruction
  Serial.print (d,3);
  Serial.println (F(" us"));

 
 Serial.print(F("  Arduino digitalRead       : "));
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<2; i++)
  {
    for (j=0; j<10000; j++)
    {
      digitalRead(13);       
      digitalRead(13);       

      digitalRead(13);       
      digitalRead(13);       

      digitalRead(13);       
      digitalRead(13);       

      digitalRead(13);       
      digitalRead(13);       

      digitalRead(13);       
      digitalRead(13);       

      digitalRead(13);       
      digitalRead(13);       

      digitalRead(13);       
      digitalRead(13);       

      digitalRead(13);       
      digitalRead(13);       

      digitalRead(13);       
      digitalRead(13);       

      digitalRead(13);       
      digitalRead(13);       
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));

  
  
  Serial.print(F("  Arduino digitalWrite      : "));
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<2; i++)
  {
    for (j=0; j<10000; j++)
    {
      digitalWrite(13, HIGH);       
      digitalWrite(13, LOW);       

      digitalWrite(13, HIGH);       
      digitalWrite(13, LOW);       

      digitalWrite(13, HIGH);       
      digitalWrite(13, LOW);       

      digitalWrite(13, HIGH);       
      digitalWrite(13, LOW);       

      digitalWrite(13, HIGH);       
      digitalWrite(13, LOW);       

      digitalWrite(13, HIGH);       
      digitalWrite(13, LOW);       

      digitalWrite(13, HIGH);       
      digitalWrite(13, LOW);       

      digitalWrite(13, HIGH);       
      digitalWrite(13, LOW);       

      digitalWrite(13, HIGH);       
      digitalWrite(13, LOW);       

      digitalWrite(13, HIGH);       
      digitalWrite(13, LOW);       
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));

   
   Serial.print(F("  pinMode                   : "));
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<2; i++)
  {
    for (j=0; j<10000; j++)
    {
      pinMode(13, INPUT);       
      pinMode(13, OUTPUT);       

      pinMode(13, INPUT);       
      pinMode(13, OUTPUT);       

      pinMode(13, INPUT);       
      pinMode(13, OUTPUT);       

      pinMode(13, INPUT);       
      pinMode(13, OUTPUT);       

      pinMode(13, INPUT);       
      pinMode(13, OUTPUT);       

      pinMode(13, INPUT);       
      pinMode(13, OUTPUT);       

      pinMode(13, INPUT);       
      pinMode(13, OUTPUT);       

      pinMode(13, INPUT);       
      pinMode(13, OUTPUT);       

      pinMode(13, INPUT);       
      pinMode(13, OUTPUT);       

      pinMode(13, INPUT);       
      pinMode(13, OUTPUT);       
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  multiply byte             : "));
  c1 = 2;
  c2 = 3;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<20; i++)
  {
    for (j=0; j<10000; j++)
    {
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
      c1 *= c2;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  divide byte               : "));
  c1 = 253;
  c2 = 3;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<2; i++)
  {
    for (j=0; j<10000; j++)
    {
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
      c1 /= c2;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  add byte                  : "));
  c1 = 1;
  c2 = 2;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<20; i++)
  {
    for (j=0; j<10000; j++)
    {
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
      c1 += c2;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));

  

  Serial.print(F("  multiply integer          : "));
  volatile int x,y;
  x = 2;
  y = 3;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<10; i++)
  {
    for (j=0; j<10000; j++)
    {
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
      x *= y;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  divide integer            : "));
  x = 31415;
  y = 3;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<1; i++)
  {
    for (j=0; j<10000; j++)
    {
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
      x /= y;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  add integer               : "));
  x = 1;
  y = 3;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<10; i++)
  {
    for (j=0; j<10000; j++)
    {
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
      x += y;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  multiply long             : "));
  l1 = 2;
  l2 = 3;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<2; i++)
  {
    for (j=0; j<10000; j++)
    {
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
      l1 *= l2;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  divide long               : "));
  l1 = 2000000000L;
  l2 = 3;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<1; i++)
  {
    for (j=0; j<2000; j++)
    {
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
      l1 /= l2;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  add long                  : "));
  l1 = 500000000L;
  l2 = 123;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<4; i++)
  {
    for (j=0; j<10000; j++)
    {
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
      l1 += l2;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  multiply float            : "));
  f1 = 3.24;
  f2 = 1.25;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<2; i++)
  {
    for (j=0; j<10000; j++)
    {
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
      f1 *= f2;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  divide float              : "));
  f1 = 312645.24;
  f2 = 1.21;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<1; i++)
  {
    for (j=0; j<2000; j++)
    {
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
      f1 /= f2;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  add float                 : "));
  f1 = 9876.54;
  f2 = 1.23;
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<1; i++)
  {
    for (j=0; j<10000; j++)
    {
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
      f1 += f2;
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));
 Serial.print(F("  bitSet()                  : "));
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<20; i++)
  {
    for (j=0; j<10000; j++)
    {
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
      bitSet (v, 12);
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));

  Serial.print(F("  analogRead()              : "));
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<1; i++)
  {
    for (j=0; j<1000; j++)
    {
      analogRead (0);
      analogRead (1);
      analogRead (0);
      analogRead (1);
      analogRead (0);
      analogRead (1);
      analogRead (0);
      analogRead (1);
      analogRead (0);
      analogRead (1);
      analogRead (0);
      analogRead (1);
      analogRead (0);
      analogRead (1);
      analogRead (0);
      analogRead (1);
      analogRead (0);
      analogRead (1);
      analogRead (0);
      analogRead (1);
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  analogWrite() PWM         : "));
  // Using pin 13 (system led) for output.
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<1; i++)
  {
    for (j=0; j<10000; j++)
    {
      analogWrite (13, 100);
      analogWrite (13, 200);
      analogWrite (13, 100);
      analogWrite (13, 200);
      analogWrite (13, 100);
      analogWrite (13, 200);
      analogWrite (13, 100);
      analogWrite (13, 200);
      analogWrite (13, 100);
      analogWrite (13, 200);
      analogWrite (13, 100);
      analogWrite (13, 200);
      analogWrite (13, 100);
      analogWrite (13, 200);
      analogWrite (13, 100);
      analogWrite (13, 200);
      analogWrite (13, 100);
      analogWrite (13, 200);
      analogWrite (13, 100);
      analogWrite (13, 200);
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  delay(1)                  : "));
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<1; i++)
  {
    for (j=0; j<100; j++)
    {
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
      delay(1);
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  delay(100)                : "));
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<1; i++)
  {
    for (j=0; j<2; j++)
    {
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
      delay(100);
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  delayMicroseconds(2)      : "));
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<20; i++)
  {
    for (j=0; j<10000; j++)
    {
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
      delayMicroseconds(2);
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  delayMicroseconds(5)      : "));
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<5; i++)
  {
    for (j=0; j<10000; j++)
    {
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
      delayMicroseconds(5);
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));



  Serial.print(F("  delayMicroseconds(100)    : "));
  delay(70);     // Allow the Serial text to be transmitted
  m=millis();
  for (i=0; i<1; i++)
  {
    for (j=0; j<1000; j++)
    {
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
      delayMicroseconds(100);
    }
  }
  n=millis();
  d = ((float)n - (float)m) / ((float)i * (float)j);
  d *= 1000.0;
  d -= overhead;
  d /= 20.0;
  Serial.print (d,3);
  Serial.println (F(" us"));


  Serial.println(F("-----------"));





}
