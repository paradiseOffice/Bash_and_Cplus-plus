#! /usr/bin/perl

# initialize an array variable
@arr = ("zero", 1, "TWO", 3.142, 4444);

#init a scalar variable with the array length
$arrlength = @arr;

#output a 'here' document revealing variable values.
print << "DOC";
content-type:text/html\n\n
<html>
<ul>
<li>List is @arr</li>
<li>Element 0 is $arr[0]
<li>Element 1 is $arr[1]
<li>Element 2 is $arr[2]
<li>Element 3 is $arr[3]
<li>Element 4 is $arr[4]
<li>Lenth of array is $arrlength elements.
</ul>
</html>

DOC

