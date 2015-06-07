#!/usr/bin/perl

#counter1.pl : one way to count the characters, words, and
#lines in a text file.

#the name of the file that will be counted
$TheFile = "sample.txt";

#open the file but quit if it doesn't exist
open(INFILE, $TheFile) or die "The file $TheFile could " .
	"not be found. \n";

#initialize the counters
$CharCount = 0;
$WordCount = 0;
$LineCount = 0;

while(<INFILE>) {
	$TheLine = $_; #save the lines contents
	chomp( $TheLine); #gets rid of the line break
	$LineCount = $LineCount + 1;
	$LineLen = length($TheLine);
	#we now know how many characters minus the line 
	# break are on this line.
	$CharCount = $CharCount + $LineLen;

# Do the tricky stuff for counting words on the line.

# The line is empty,
if($TheLine eq "") { next };
# The line has at least one word on it.
$WordCount = $WordCount + 1;
# Now loop through each character on this line to look for words.
$CharPos = 0; #position on line
until($CharPos == $LineLen) {
	if(substr($TheLine, $CharPos, 1) eq " ")
	{	$WordCount = $WordCount +1 }
	$CharPos = $CharPos + 1;
} # end of until
} # end of while(<infile>) loop

# All finished so print out the results

print "For the file $TheFile:\n";
print "Number of characters $CharCount\n";
print "Number of Words	$WordCount\n";
print "Number of lines  $LineCount\n";
  
