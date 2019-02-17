#include <Keyboard.h>

void type(String s) {
  Keyboard.println(s);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();  
}

void setup() {
  Keyboard.begin();
}

bool done = false;

void loop() {
  if (!done) {
    delay(2000);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(200);
    Keyboard.releaseAll();
    Keyboard.println("notepad.exe");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(1000);
    type("YAY!");                              
    done=true;
  }
  Keyboard.end();
}
