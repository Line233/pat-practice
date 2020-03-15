param (
    [string]$name,
    [switch]$c = $false,
    [switch]$m = $false,
    [switch]$r = $false
)
$PSDefaultParameterValues['Out-File:Encoding'] = 'utf8'

$name = $PSBoundParameters['name']

$exe = ".\exe\${name}.exe"
$source = ".\source\${name}.cpp"
$input = ".\input\${name}.txt"
$output = ".\output\${name}.txt"

$output_c = ".\output.txt"
$compare = ".\exe\compare.exe"

if ($PSBoundParameters.ContainsKey('m')) {
    if (!(Test-Path $source)) {
        Copy-Item ".\source\template.cpp" -Destination $source
    }
    if (!(Test-Path $input)) {
        New-Item $input
    }
    if (!(Test-Path $output)) {
        New-Item $output
    }
}
if ($PSBoundParameters.ContainsKey('r')) {
    get-content $input | . $exe -Encoding utf8  > $output_c
    $content = (Get-Content $output_c) 
    [IO.File]::WriteAllLines($output_c, $content)
}
if ($PSBoundParameters.ContainsKey('c')) {
    $cmdOutput = &$compare $output .//output.txt 2>&1
    Write-Host $cmdOutput
}