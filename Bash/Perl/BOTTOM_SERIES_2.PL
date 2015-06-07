#! /usr/bin/perl

# Program to create a menu for the DVD of Bottom series 2.

print "Bottom Series 2\n\n";


# Menu of episodes etc.

print "1. Digger\n";
print "Richie and Eddie try and get shagged. \n\n";
print "2. Parade\n";
print "They take part in a police line up and steal someone's false leg. \n\n";
print "3. Burglary\n";
print "They get burgled but catch the burglars. They then try and flog the loot. \n\n";
print "4. Culture\n";
print "They have to live without a telly and take up chess to relieve the boredom.\n\n";
print "5. Holy\n";
print "It's the full length Christmas episode, very funny. \n\n";
print "6. S' Out\n";
print "Richie and Eddie try out camping. \n\n";
print "\n7. Digger - Extended version\n";
print "8. Bottom Fluff\n";
print "Fuck ups in the recording. \n\n";

#User input
print "\nPick one of the numbers above and type it in: ";
$choice = <STDIN>;

#Menu bit, plays the dvd episode with mplayer
if ( $choice == 1 ) {

'mplayer dvd://3 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd'
};
elsif ( $choice == 2 ) {

"mplayer dvd://5 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd"
};
elsif( $choice == 3 ) {

"mplayer dvd://6 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd"
};
elsif( $choice == 4 ) {

"mplayer dvd://7 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd"
};
elsif( $choice == 5 ) {

"mplayer dvd://8 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd"
};
elsif( $choice == 6 ) {

"mplayer dvd://9 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd"
};
elsif( $choice == 7 ) {

"mplayer dvd://4 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd"
};
elsif( $choice == 8 ) {

"mplayer dvd://2 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd"
};
else( $choice == 0 ) {

print "Wrong answer.\n"
};

#end of menu.
