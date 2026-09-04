# Find first available COM port and run plink CLI serial monitor

$port = (Get-CimInstance Win32_PnPEntity | 
    Where-Object { $_.Name -match '\(COM\d+\)' } | 
    Select-Object -ExpandProperty Name | 
    ForEach-Object { [regex]::Match($_, 'COM\d+').Value } | 
    Select-Object -First 1)

if ($port) {
    Write-Host "Detected MCU on $port..."
    plink -serial $port -sercfg 115200,8,n,1,N
} else {
    Write-Host "Error: No serial device (COM port) found!"
    exit 1
}
