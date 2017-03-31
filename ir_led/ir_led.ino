//Library for IR Remote
#include <IRLib.h>

int RECV_PIN = 11;
int LED_PIN = 5;

int LED_Status = 1;

//Receiver object
IRrecv Receiver(RECV_PIN);

//Decoder object
IRdecode Decoder;

void setup(){
  
  Serial.begin(9600);
  
  pinMode(RECV_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  //Start the receiver
  Receiver.enableIRIn();
}

void loop(){
  
  //Check for button press
  if(Receiver.GetResults(&Decoder)){
    Decoder.decode();
    switch(Decoder.value){
      case 0xFF30CF:
        Serial.println("Power button pressed");
        toggleLED(LED_Status);
        break;
      case 0xFF48B7:
        Serial.println("Mute button pressed");
        break;
      case 0xFF00FF:
        Serial.println("1 button pressed");
        break;
      case 0xFF807F:
        Serial.println("2 button pressed");
        break;
      case 0xFF40BF:
        Serial.println("3 button pressed");
        break;
      case 0xFFC03F:
        Serial.println("4 button pressed");
        break;
      case 0xFF20DF:
        Serial.println("5 button pressed");
        break;
      default:
        Serial.println("Unknown button pressed");
        break;
    }
    //Restart the receiver
    Receiver.resume();
  }
}

void toggleLED(int status){
  
  if(LED_Status){
    //Turn ON the LED
    Serial.println ("Red led ON");
    digitalWrite(LED_PIN,HIGH);
    LED_Status = 0;
  }
  else{
    //Turn OFF the LED
    Serial.println ("Red led OFF");
    digitalWrite(LED_PIN,LOW);
    LED_Status = 1;
  }
}
