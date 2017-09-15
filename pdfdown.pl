#!/usr/bin/perl

system("mkdir", "pdfs");
chdir "pdfs";
$url = @ARGV[0];
system ("wget", $url);
open( DATA,"index.html")
  or die "Could not open file '$threadname' $!";

foreach $line (<DATA>) {
	if ($line =~ /.+\.pdf/){
		@urls = split(/"/, $line); 
		$url = @urls[1];
		print $url;
		system("wget","-nc", $url);
	}
}
system("rm", "index.html");

