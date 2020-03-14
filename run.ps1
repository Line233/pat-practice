
$PSDefaultParameterValues['Out-File:Encoding'] = 'utf8'

$name = $args[0]
$check = $args[1]
get-content .//input//${name}.txt | . .//exe//${name}.exe -Encoding utf8  > .//output.txt

$content = (Get-Content .//output.txt) 
[IO.File]::WriteAllLines(".//output.txt", $content)

If ($check -eq "-c") {
    $cmdOutput = &".//exe//compare.exe" .//output//${name}.txt .//output.txt 2>&1
    Write-Host $cmdOutput
}