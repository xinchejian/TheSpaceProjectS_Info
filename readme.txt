/* Introduction     REVIEW - HOW MUCH HERE - VS THE WIKI!!!!!!!

     Xinchejian Hackerspace Shanghai 

 All information including assembly details are at: http://wiki.xinchejian.com/wiki/TheSpaceProjectS
 And the code is at https://github.com/xinchejian/TheSpaceProjectS_Info/tree/master/TheSpaceProjectS_Info

 The projects are open source and everyone is encourage to contribute to the hardware, the software,
 the documentation (in many languages) and especially in using the devices.

 This sub-project aims to be a:-
	- Members HIGHLY interactive information system
	- actively and forever hacked and changed and stuffed about with by everyone
	- send "space open" and closed messages
	- log interactive use and space open/closed messages
	- be used as a portable display to promote XinCheJian
	- keep getting added to ......
*/

/* Licence(s)
 Default Xinchejian licence is:-     CC by SA See http://creativecommons.org/licenses/by-sa/2.0/

 If this does not suit your needs, then get in touch to discuss.

 If the above licence conflicts with licences of contributors code,
 then either youre gonna have to work it out,
 or go with the spirit of Open Source and sharing,
 or call your bank manager and lawyer!
 */

 
 
=========================================================================================

How to setup the code and compile and make it auto-run at startup, and also to configure email sending.

1. setup the code and compile
  grab the code from https://github.com/xinchejian/TheSpaceProjectS_Info/tree/master/TheSpaceProjectS_Info/TheSpaceProjectS_Info
  place in in /ubuntu/Arduino/TheSpaceProjectS_Info/TheSpaceProjectS_Info.ino
  open Arduino GUI, open sketchbook and above code
  compile and test runs OK

  If Arduino GUI fails to run, then power pcDuino off, on and press F8 when prompted, then run a full update, then try again.
  
  You also need the web pages - I just saved them from XCJ wiki to /home/ubuntu/Desktop/www, so that it all works off-line - eg for use at external displays etc.
  See the code for the web pages currently in use.
  
2. make code auto-run at startup
      Running a program at boot
	https://learn.sparkfun.com/tutorials/getting-started-with-pcduino/all
	    Say you want to always have an LXTerminal window open when the GUI loads. How do you go about doing this?
	    All you need to do is add the command to the end of the autostart file located here:
	      /etc/xdg/lxsession/Lubuntu/autostart
	    For instance, to launch LXTerminal at boot, add the line “lxterm” to the end of the file.
      ..If you are doing any development work on this project AFTER doing this, then you need to disable above - or you will have two instances of the program running = confusion!

      an example autostart file is included in this git repo.

3. configure email sending.

In a command shell (all commands need sudo)
Install the packages:
$sudo apt-get update 
  if you get conflicting wii error, ignore for now as seems OK.
$sudo apt-get install ssmtp
$sudo apt-get install mailutils
$sudo apt-get install mpack
$sudo apt-get install nano	// or your fav editor

Next we configure SSMTP:
$sudo nano /etc/ssmtp/ssmtp.conf

You need a working email account.

Add details to /etc/ssmtp/ssmtp.conf - see example file provided in github

You need to add the password into this file, so of course make sure that:
  - you do not COMMIT to github with password in the file!!!!
  - use sudo, so the file is "protected"

You may also need to update the mail server lines....


If running the code, or just in a shell running "mail" you see :-
  "Cannot open mailbox /var/mail/ubuntu: Permission denied"

Then follow adivce from these sites
  http://ubuntuforums.org/showthread.php?t=1500892
  http://stackoverflow.com/questions/9153398/permission-denied-when-doing-postfix-ubuntu-tutorial
both suggest:
sudo touch /var/mail/$USER
sudo chown $USER:mail /var/mail/$USER
sudo chmod o-r /var/mail/$USER
sudo chmod g+rw /var/mail/$USER

now mail runs and says no mail = :)

Plus you need the sendEmails.sh script - place in the the pcDuino desktop (/home/ubuntu/Desktop)

AND you also need to update the code to use the same FROM address, eg:-
          sendEmail("thespaceprojects@xinchejian.com", "xinchejian@googlegroups.com", "thespaceprojects 'date'", "'body text here'");

=========================================================================================


Web pages/msgs loaded - extracted from the code:-
  Xinchejian Membership - XinCheJian.html'",
  Xinchejian Machine Room Guide - XinCheJian.html'",
  Shop - XinCheJian.html'",
  Kits - XinCheJian.html'",

    //page #5
  Hackerspace etiquette - XinCheJian.html'",
  Staff members - XinCheJian.html'",
    "echo hack me please",
  The Space - XinCheJian.html'",
    "echo hack me!!!",

    //page #10
    "echo who=;who;echo pwd=;pwd;echo PATH=;echo $PATH",
all pages > 10   "echo pXX",
 
    