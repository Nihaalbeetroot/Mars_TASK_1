//A digital clock that works based on the inclination of sun

#define left A0
#define right A1
#define servo 8
#define temp A2

#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_display(0);

Servo s;
int error = 10;
int Pos = 0;

void setup()
{
  //Serial.begin(9600);
  
  //ldr
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  
  //servo
  s.attach(servo);
  s.write(Pos);
  
  //lcd
  lcd_display.begin(16,2);
  delay(1000);
}

void loop()
{
  
  //pir variables
  int left_intensity = 0;
  int right_intensity = 0;
  
  
  int difference;
  int hrs;
  int min;
  
  //temperature sensor variables
  int reading;
  
  //finding temperature
  reading = analogRead(temp);
  float voltage;
  voltage = reading*4.68;
  voltage = voltage/1024.0;
  float temperature;
  temperature = (voltage-0.5)*100;
  
  //printing on lcd
  lcd_display.setCursor(0,0);
  lcd_display.clear();
  lcd_display.print("Temp: ");
  lcd_display.print(temperature);
  lcd_display.print("C");
  
  //finding difference in intensity
  left_intensity = analogRead(left);
  right_intensity = analogRead(right);
  
  difference = abs(left_intensity - right_intensity);
  
  //Serial.println(difference);
  
  
  if(difference <= error)
  {
      
  }
  else //moving sevo accordingly to point in sun's direction
  {
    if(left_intensity > right_intensity) 
    {
      Pos = Pos+1;
    }
    else if(right_intensity > left_intensity)
    {
      Pos = Pos-1;
    }
  } 
  s.write(Pos);

  //evaluvating time
  hrs = 6+ Pos/15;
  min = (Pos%15)*4;
  
  //printing time
  lcd_display.setCursor(0,1);
  lcd_display.print("Time: ");
  
  lcd_display.print(hrs);
  lcd_display.print(" : ");
  lcd_display.print(min);
  
  delay(1000);
  
}