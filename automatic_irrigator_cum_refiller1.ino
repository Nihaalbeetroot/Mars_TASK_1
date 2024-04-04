//The project automatically switches on Motor whenever water is need in the soil
//Morevover if the tank from which the water is sucked is low in amount
//it notifies the user to refill

#define trig 4
#define echo 3
#define buzz 5
#define soil A0
#define pump 8

void setup()
{ 

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(soil,INPUT);
  pinMode(pump,OUTPUT);
}

void loop()
{
  long time = 0;
  long cm = 0;
  int flag = 0;
  int wetness = 0;
  
  //sending pulse
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
 
  time = pulseIn(echo, HIGH);
    
  cm = 0.01723*time;  //(340 m/s in cm/microsec and then /2 because twice)
 
  wetness = analogRead(soil);
  
  //if water is needed
  
  if(wetness<=150)
  {
    //if tank is empty
    if(cm>=100) //water has receded farther than 100
    {
      digitalWrite(buzz,HIGH); //to alert user
    }
    
    //if tank has enough water, (this check happpens only if water is needed)
    
    else
    {
      digitalWrite(buzz,LOW); //switch off buzzer
      digitalWrite(pump,HIGH); //turn on pump
      delay(500); //letting pump run for 0.5 sec
      digitalWrite(pump,LOW); //turning off pump 
      delay(500); //letting water settle in soil and then rechecking in loop
    }
  }
  
  //if water is no longer needed
  else
  {
  	digitalWrite(pump,LOW);
    digitalWrite(buzz,LOW);
  }
 
}
