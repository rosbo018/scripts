#!/usr/bin/perl
#https://boards.4chan.org/g/thread/62382818
#uses 4chan url as only argument
#ex. perl imagedl https://boards.4chan.org/g/thread/62382818
#div class="thread" id="62390226"
#will create a folder named 62382818 and fill it with images
$board = @ARGV[0];
@b = split(/\//,$board);
$boardname = @b[-1];
system ("mkdir", $boardname)
 or chdir $boardname;
system ("wget", $board);
open($boardhtml, "index.html")
 or print "failed to get index.html" and die;
my (@threads) = <boardhtml> =~ m/(div class="thread" id="62390226")/i;
foreach $line (@threads){

@l = split(/\//,$url);
$threadname = @l[-1];
system ("mkdir", $threadname)
 or chdir $threadname;
chdir $threadname 
 or print "chdir failed";

system ("wget", $url);
open( DATA,$threadname)
  or die "Could not open file '$threadname' $!";


foreach $snipet (split( /"/, <DATA>)){
	if ($snipet  =~ /i\.4cdn\.org.+\d+\.(?:jpg|gif|png|gif|webm)/){
		$url = substr $snipet, 2;
		system("wget","-nc" ,$url);
	}
}
system ("rm", $threadname);
