#!/usr/bin/perl
#audio file is first argument
#time file is second argument
#time file looks like this:
#00:00:40-00:00:50
#00:01:20-00:02:40
#or
#60-70
#100-200
#
#if there is a third value, then it will become the file's name
#ex. 60-70-aaa will create a file 60-70 sec, with name aaa
#individual files are delimited by new line
#times for file are delimited by - or ' '



$audiofile = $ARGV[0];
$timefile = $ARGV[1];

open $rawfile, '<', $timefile
 or print "can't open file" and die;
(@fileLineArr) = <$rawfile>;

$n = 1;
foreach $line (@fileLineArr) {
	@times = split(/\s|-/, $line);
	$ind = index($audiofile, ".");
	if ( (scalar @times) > 2){
		$name = @times[2];
	}
	else {
		$name = substr ($audiofile, 0, $ind);
	}
	$filename =  $name. "." . $n . substr ( $audiofile, $ind);
	system("ffmpeg","-i",  $audiofile, "-ss", @times[0], "-to", @times[1], "-c", "copy", $filename);
	$n= $n + 1;
}
