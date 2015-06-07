#!/usr/bin/perl

print "Enter the number you want to convert: \n";

$number = <STDIN>;
print "Enter the conversion rate: \n\n";
$rate = <STDIN>;

$result = $number * $rate;
print "The answer is $result \n";

