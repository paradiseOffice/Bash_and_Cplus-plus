#! /usr/bin/perl

#start a hash variable
%data = ("int", 100, "flt", 3.142, "str", "Hello",
"Colour", "red", "gem", "Diamond", 100, "One hundred");

# here document thingy.
print << "DOC";
Content-type:text/html\n\n
<html>
<ul>
<li>Integer is $data{"int"}
<li>Float is $data{"flt"}
<li>String is $data{"str"}
<li>Colour is $data{"Colour"}
<li>Gem is $data{"gem"}
<li>Score is $data{100}
</ul>
</html>

DOC


