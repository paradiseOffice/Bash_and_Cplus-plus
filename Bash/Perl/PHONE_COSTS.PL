#! /usr/bin/perl
# Phone bill calculator

$exvat = 0.72 * 40;
$b = $exvat + 14.04;
$a = $b / 100;
$vat = $a * 17.5;
$total = $b + $vat;
print "$total \n";
