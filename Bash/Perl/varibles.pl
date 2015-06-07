#! /usr/bin/perl

# start a float scalar
$float = 1.4;

# start an integer scalar
$integer = 34;

# Start string scalars
$string = "Hazel's PERL script";
$var1 = "Howdy!";

#Initalize with the address of var1
$var2 = \$var1;

# output a here document revealing varible values
print << "DOC";
Content-type:text/html\n\n
<html>
<ul>
<li>Floating number: $float
<li>Integer: $integer
<li>String: $string
<li>Reference: ${$var2}
<li>Reference address: $var2
</ul>
</html>

DOC


