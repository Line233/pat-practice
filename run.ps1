
$PSDefaultParameterValues['Out-File:Encoding'] = 'utf8'
$name = $args[0]
get-content .//input//${name}.txt |. .//exe//${name}.exe >> output.txt