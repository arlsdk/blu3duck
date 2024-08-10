//arlsdk - blu3duck, 16u2 microcode
#include "Keyboard.h"
#include "HID.h"
void setup() {
    Serial1.begin(115200);
    Serial.begin(115200);
    Keyboard.begin();
}
void loop() {
    if (Serial1.available()) {
        String received = Serial1.readString();
        bool releaseit = true;
        if (received == "lctrl") Keyboard.press(KEY_LEFT_CTRL);
        else if (received == "lshift") Keyboard.press(KEY_LEFT_SHIFT);
        else if (received == "lalt") Keyboard.press(KEY_LEFT_ALT);
        else if (received == "lgui") Keyboard.press(KEY_LEFT_GUI);
        else if (received == "rctrl") Keyboard.press(KEY_RIGHT_CTRL);
        else if (received == "rshift") Keyboard.press(KEY_RIGHT_SHIFT);
        else if (received == "ralt") Keyboard.press(KEY_RIGHT_ALT);
        else if (received == "rgui") Keyboard.press(KEY_RIGHT_GUI);
        else if (received == "tab") Keyboard.press(KEY_TAB);
        else if (received == "capslock") Keyboard.press(KEY_CAPS_LOCK);
        else if (received == "esc") Keyboard.press(KEY_ESC);
        else if (received == "enter") Keyboard.press(KEY_RETURN);
        else if (received == "quit"){
          Keyboard.press(KEY_LEFT_ALT); 
          Keyboard.press(KEY_F4);
        }
        else {
            Keyboard.print(received);
            releaseit = false;
        }
        if (releaseit) Keyboard.releaseAll();
    }
}
