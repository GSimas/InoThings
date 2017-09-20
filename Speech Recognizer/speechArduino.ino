#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //TX, RX respectively
String device;

int led1Pin = 7;
int led2Pin = 2;

void setup() {
  
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(led1Pin, OUTPUT);

}

//-----------------------------------------------------------------------//  
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = BT.read(); //Conduct a serial read
  device += c; //build the string.
  }
   
  if (device.length() > 0) {
    Serial.println(device);

  if(device == "ligar")
  {
    digitalWrite(led1Pin, HIGH);
  } 
  
  else if(device == "desliga") 
  {
    digitalWrite(led1Pin, LOW);
  }

  else if(device == "andando") 
  {
    digitalWrite(led1Pin, HIGH);
  }

  else if(device == "parado") 
  {
    digitalWrite(led1Pin, LOW);
  }

  else if(device == "proximo")
    digitalWrite(led1Pin,HIGH);

  else if(device == "longe")
    digitalWrite(led1Pin,LOW);
  
  else if (device == "dtwoon")
  {
    digitalWrite (4,HIGH);
  }
  
 else if ( device == "dtwooff")
 {
   digitalWrite (4, LOW);
 }
 
 else if (device == "dthreeon")
 {
   digitalWrite (5, HIGH);
 }
 
 else if (device == "dthreeoff")
 {digitalWrite (5, LOW);}
 
  else if (device == "light on")// voice command 1st device on
 {digitalWrite (3, HIGH);}
 
  else if (device == "light off")// voice command 1st device off
 {digitalWrite (3, LOW);}

 else if (device == "tv on")// voice command 2nd device on
 {digitalWrite (4, HIGH);}
 
  else if (device == "tv off")// voice command 2nd device off
 {digitalWrite (4, LOW);}
 
device="";}} //Reset the variable
