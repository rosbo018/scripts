#!/usr/bin/perl
#audio file is first argument
#time file is second argument
#time file looks like this:
#00:00:40-00:00:50
#00:01:20-00:02:40
#or
#60-70
#100-200
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
	$filename = substr ( $audiofile, 0,$ind ) . "." . $n . substr ( $audiofile, $ind);
	system("ffmpeg","-i",  $audiofile, "-ss", @times[0], "-to", @times[1], "-c", "copy", $filename);
	$n= $n + 1;
}
