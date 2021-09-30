#include <FirebaseESP32.h>
#include <Arduino.h>
#include "deneyap.h"
#include "WiFi.h"
#include <stdio.h>



#define FIREBASE_HOST "*******"    
#define FIREBASE_AUTH "*******"

#define WIFI_SSID     "***********"
#define WIFI_PASSWORD "******************"

#define left_backward D0 // in4
#define left_forward D1 // in 3     D1
#define right_backward D12  // In2   D12
#define right_forward D13  // In1


void MotorForward();
void MotorBackward();
void MotorStop();

void Sag();
void Sol();





FirebaseData fbdo;
FirebaseJson json;

void setup()
{

  pinMode(left_backward,OUTPUT);
  pinMode(left_forward,OUTPUT);
  pinMode(right_backward,OUTPUT);
  pinMode(right_forward,OUTPUT);


  




   Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);


  while (WiFi.status() != WL_CONNECTED)
  {

    delay(300);
  }



  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);


 
  fbdo.setResponseSize(1024);

  
  Firebase.setReadTimeout(fbdo, 1000 * 60);

  Firebase.setwriteSizeLimit(fbdo, "tiny");


  Firebase.setFloatDigits(2);
  Firebase.setDoubleDigits(6);



}


void loop() 
{
  if(WiFi.status() != WL_CONNECTED) //baglantı giderse kartı yeniden baslat
  {
   
    ESP.restart();
  }


    Firebase.getString(fbdo, "/position"); 
    char stateData = fbdo.intData();

   

  
    
    switch (stateData) {
      
      case 1:  
         Sol(); 
                                   
        break;
      case 2: 
            Sag();
        break;       
      case 3:    // motor ileri
    MotorForward();
        break;
      case 4: 
    MotorBackward();
        break;
        case 5 :
        MotorStop();
        break;



      
  }



}

void MotorForward(void)   
{
  digitalWrite(left_forward,1);
  digitalWrite(right_forward,1);

  digitalWrite(left_backward,0);
  digitalWrite(right_backward,0);

  
}

void MotorBackward(void)   
{
  digitalWrite(left_forward,0);
  digitalWrite(right_forward,0);

  digitalWrite(left_backward,1);
  digitalWrite(right_backward,1);
}

void MotorStop(void)   
{
  digitalWrite(left_forward,0);
  digitalWrite(left_backward,0);
  digitalWrite(right_backward,0);
  digitalWrite(right_forward,0);
}
void Sag()
{
    digitalWrite(left_forward,0);
    digitalWrite(left_backward,0);
    digitalWrite(right_backward,0);
    digitalWrite(right_forward,1);
}

void Sol()
{
    digitalWrite(left_forward,1);
    digitalWrite(left_backward,0);
    digitalWrite(right_backward,0);
    digitalWrite(right_forward,0);
}

