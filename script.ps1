# Check if the filename argument is passed
if ($args.Length -eq 0) {
    echo "No file provided. Please provide the filename as an argument."
    exit
}

# Assign the filename from the argument
$fileName = $args[0]

# Define encryption key and IV
$key = [System.Text.Encoding]::UTF8.GetBytes("ThisIsA16ByteKey")
$iv = [System.Text.Encoding]::UTF8.GetBytes("ThisIsA16ByteIV!")

# Create AES object
$aes = [System.Security.Cryptography.Aes]::Create()
$aes.Key = $key
$aes.IV = $iv

# Create encryptor
$encryptor = $aes.CreateEncryptor()

# Ensure the input file exists before attempting encryption
if (Test-Path $fileName) {
    # Encrypt the file and write the encrypted file as <original_filename>_encrypted.txt
    $encryptedFile = "$($fileName).enc"
    [System.IO.File]::WriteAllBytes($encryptedFile, $encryptor.TransformFinalBlock([System.IO.File]::ReadAllBytes($fileName), 0, [System.IO.File]::ReadAllBytes($fileName).Length))

    # Optional: Show success message
    echo "File '$fileName' encrypted successfully! Encrypted file: '$encryptedFile'"
} else {
    echo "Input file '$fileName' not found. Please ensure it exists before running this script."
}
