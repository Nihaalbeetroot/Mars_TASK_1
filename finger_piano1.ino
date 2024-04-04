//An instrument that can be mounted onto a finger to play notes
//Finger controls pitch, potentiometer controls loudness

#define flex A0
#define buzz 8

//0 and 90 deg resisitances
const float resistance_0 = 29960;
const float resistance_90 = 69921; 

const float Vcc = 5.0;

//10Kohm resistance
const float resistance = 10000.0; 

//duration of one note
const int note_duration = 100;

void setup()
{
  pinMode(flex,INPUT);
  //Serial.begin(9600);
}

void loop()
{
  int ADCval; //anlog read value
  float Vflex; //potential drop across flex
  float Rflex; 
  float angle; //approximate angle 
  
  ADCval = analogRead(flex);
  //Serial.println(ADCval);
  
  Vflex = (ADCval/1023.0)*Vcc;
  
  //voltage divider equation
  Rflex = resistance/((Vcc/Vflex)-1.0);
  
  //Serial.println(Rflex);
  
  angle = map(Rflex,resistance_0,resistance_90,0,90);
  
  //Serial.println(angle);
  
  delay(10);
  
  //notes
  if(angle>0 && angle<=12)
  {
    tone(buzz,261,note_duration);
  }
  else if(angle>12 && angle <=24)
  {
    tone(buzz,293,note_duration);
  }
  else if(angle>24 && angle <=36)
  {
    tone(buzz,329,note_duration);
  }
  else if(angle>36 && angle<=48)
  {
    tone(buzz,349,note_duration);
  }
  else if(angle>48 && angle <=60)
  {
    tone(buzz,392,note_duration);
  }
  else if(angle>60 && angle<=72)
  {
    tone(buzz,440,note_duration);
  }
  else if(angle>72 && angle <=84)
  {
    tone(buzz,493,note_duration);
  }
  else if(angle>84 && angle<=96)
  {
    tone(buzz,523,note_duration);
  }  
  
    
  
}

