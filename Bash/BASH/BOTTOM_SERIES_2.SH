#! /bin/sh

# Program to create a menu for the DVD of Bottom series 2.

echo -e "\nBottom Series 2\n"


# Menu of episodes etc.

echo -e "1. Digger"
echo -e "Richie and Eddie try and get shagged. \n"
echo -e "2. Parade"
echo -e "They take part in a police line up and steal someone's false 
leg.\n "
echo -e "3. Burglary"
echo -e "They get burgled but catch the burglars. They then try and flog the loot.\n "
echo -e "4. Culture"
echo -e "They have to live without a telly and take up chess to relieve the boredom.\n"
echo -e "5. Holy"
echo -e "It's the full length Christmas episode, very funny.\n "
echo -e "6. S' Out"
echo -e "Richie and Eddie try out camping. \n"
echo -e "7. Digger - Extended version"
echo -e "8. Bottom Fluff"
echo -e "Fuck ups in the recording. \n"

#User input
echo -ne "\nPick one of the numbers and type in your choice: "
read choice

#Menu bit, plays the dvd episode with mplayer
case $choice in
	1)
mplayer dvd://3 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	2)
mplayer dvd://5 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	3)
mplayer dvd://6 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	4)
mplayer dvd://7 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	5)
mplayer dvd://8 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	6)
mplayer dvd://9 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	7)
mplayer dvd://4 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	8)
mplayer dvd://2 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	*)
echo -e "Wrong answer"
	;;
esac

#end of menu.
