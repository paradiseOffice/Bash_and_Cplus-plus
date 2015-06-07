#! /bin/sh

# Program to create a menu for DVD's.

echo -e "\nRed Dwarf Series 3\n"


# Menu of episodes etc.

echo -e "Disc 1\n"
echo -e "1. Backwards"
echo -e "The one where they go back to an alternative Earth. \n"
echo -e "2. Marooned"
echo -e "Rimmer and Lister get stuck on an icy planet. \n "
echo -e "3. Polymorph"
echo -e "They encounter a scary genetic lifeform which changes shape. \n "
echo -e "4. Bodyswap"
echo -e "Rimmer and Lister swap bodies and Rimmer takes advantage. \n"
echo -e "5. Timeslides"
echo -e "Lister gets rich by inventing the tension sheet. \n "
echo -e "6. The Last Day"
echo -e "Kryten's replacement arrives and is an insane robot. \n"
echo -e "7. Polymorph bonus feature"

echo -e "\nDisc 2\n"
echo -e "8. Smeg Ups"
echo -e "9. Backwards - Forwards"
echo -e "10. All Change - Series 3"
echo -e "11. Deleted scenes"
echo -e "12. Hatties DJ Diary"
echo -e "13. Building A Better Universe"
echo -e "14. Food Featurette"

#User input
echo -ne "\nPick one of the numbers and type in your choice: "
read choice

#Menu bit, plays the dvd episode with mplayer
case $choice in
	1)
mplayer dvd://3 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	2)
mplayer dvd://4 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	3)
mplayer dvd://5 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	4)
mplayer dvd://6 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	5)
mplayer dvd://7 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	6)
mplayer dvd://8 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	7)
mplayer dvd://9 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	8)
mplayer dvd://2 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	9)
mplayer dvd://4 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	10)
mplayer dvd://5 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	11)
mplayer dvd://6 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	12)
mplayer dvd://7 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	13)
mplayer dvd://11 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	14)
mplayer dvd://12 -brightness 10 -stop-xscreensaver -dvd-device /dev/dvd
	;;
	*)
echo -e "Wrong answer"
	;;
esac

#end of menu.
