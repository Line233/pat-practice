param (
    [string]$name,
    [switch]$c = $false,
    [switch]$m = $false,
    [switch]$r = $false,
    [switch]$g = $false,
    [switch]$tmpexe = $false,
    [int]$debug = 0,
    [switch]$remove = $false
)
$PSDefaultParameterValues['Out-File:Encoding'] = 'utf8'

$name = $PSBoundParameters['name']

$exe = ".\exe\${name}.exe"
$source = ".\source\${name}.cpp"
$inputfile = ".\input\${name}.txt"
$output = ".\output\${name}.txt"

$output_exe = ".\output.txt"
$compare = ".\exe\compare.exe"

function RunAndWrite($inputfile, $exe, $output ) {
    get-content $inputfile | . $exe -Encoding utf8  > $output
    $content = (Get-Content $output) 
    [IO.File]::WriteAllLines($output, $content)
}
function generate {
    . ".\exe\g$name.exe" -Encoding utf8  > $inputfile
    $content = (Get-Content $output) 
    [IO.File]::WriteAllLines($output, $content)
}
function fcompare {
    param (
        $name1,
        $name2
    )
    $cmdOutput = &$compare $name1 $name2 2>&1
    Write-Host $cmdOutput

}



if ($PSBoundParameters.ContainsKey('m')) {
    if (!(Test-Path $source)) {
        Copy-Item ".\source\template.cpp" -Destination $source
    }
    if (!(Test-Path $inputfile)) {
        New-Item $inputfile
    }
    if (!(Test-Path $output)) {
        New-Item $output
    }
}
if ($PSBoundParameters.ContainsKey('g')) {
    $generator = ".\exe\g${name}.exe"
    . $generator -Encoding utf8  > $inputfile
    $content = (Get-Content $inputfile) 
    [IO.File]::WriteAllLines($inputfile, $content)
}
if ($PSBoundParameters.ContainsKey('r')) {
    RunAndWrite  ${inputfile} ${exe} ${output_exe}
}
if ($PSBoundParameters.ContainsKey('c')) {
    $cmdOutput = &$compare $output .//output.txt 2>&1
    Write-Host $cmdOutput
}

if ($PSBoundParameters.ContainsKey('remove')) {
    if ((Test-Path $source)) {
        Remove-Item  $source
    }
    if ((Test-Path $inputfile)) {
        Remove-Item  $inputfile
    }
    if ((Test-Path $output)) {
        Remove-Item  $output
    }
}


if ($PSBoundParameters.ContainsKey('tmpexe')) {
    $tmp = ".\exe\tmp.exe"
    $output_tmp = ".\output2.txt"
    RunAndWrite $inputfile $tmp $output_tmp
}

if ($PSBoundParameters.ContainsKey('debug')) {
    $tmp = ".\exe\tmp.exe"
    $output_tmp = ".\output2.txt"
    for ( $i = 0; $i -lt $debug; $i++) {
        generate
        RunAndWrite $inputfile $tmp $output_tmp
        RunAndWrite $inputfile $exe $output_exe
        Write-Host $i " "
        $cmdOutput = &$compare $name1 $name2 2>&1
        if ($cmdOutput -eq "pass")
        { Write-Host $cmdOutput }
        else 
        { break }
    }
}
