/*
  ToDo

  ** Make BIG note on board - pcDuino board is 3.3 volt logic! to avoid damaging the pcDuino ALL 5v sensors/boards MUST be safely level shifted! The Linksprite translation board (T board) board will do this if configured and used properly!

  make instructions - suggestions web page - english & chinese versions
  display on MOST button combos
   
  
      - button combo for version info - pcd# & prog version (?and sensors attached or at least config in prog)
	  do as web page or in console
      - email - add power off messages .... need to do via a linux shutdown script?
      - email - add power on messages		<<<<---- added but not yet tested :)
      - email - update with button pushed /cmd 	<<<<---- added but not yet tested :)
      - more sensible web pages - ie usefull info!!!!
      - web pages in chinese!!!! (there is VERY LITTLE chinese info on the wiki!) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      - lights, temp - has someone left lights/air con on?
      - buzzers, motion sensors
      - LCD ??? Use LinkSprite LCD to say booting up, please turn on monitor?????
	  ... change it's boot msg????
      - Nabaztag
      - rfid
 
  ??do multiple code files/tabs work???
  
  for print: can echo to console
        printf("from printf!!! %d/n", i);
        delay(500);
  
  printf - SOMETIMES can see them grouped - not in sequence
    added delay - no longer any o/p from printf
    
  printing - also dif if run exe from std terminal! - could not see prints!

*/


/* Introduction     REVIEW - HOW MUCH HERE - VS THE WIKI!!!!!!!

     Xinchejian Hackerspace Shanghai 

 All information including assembly details are at: http://wiki.xinchejian.com/wiki/??????????????????
 And the code is at github/xinchejian/??????

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

//#include <core.h>

// ALTERNATE button functions, once web page has been displayed.
// ... not yet implemented!
#define BUTTON_CLOSE_PAGE 6
#define BUTTON_UP 0
#define BUTTON_DOWN 1
#define BUTTON_LEFT 2
#define BUTTON_RIGHT 3


boolean sendEmails = false;

int button1 = 2;
int buttonCount = 7;

//ID of this configuration
char tsps_ID[] = "XinCheJian in container";

char* cmdLineS[] = {
  "",  //0 nothing in first element - will not get executed by code!
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/About Us 有关我们 新车间 [Xinchejian].html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/About XinCheJian - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Membership 会员制度 新车间 [Xinchejian].html'",	// from main site
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Xinchejian Membership - XinCheJian.html'",	// from wiki not main site??

  //page #5
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Contact Us 联系我们 新车间 [Xinchejian].html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Contact us.html'",
  "echo p7",
  "echo p8",
  "echo p9",
  
  //page #10
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Xinchejian Membership - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Xinchejian Machine Room Guide - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Shop - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Kits - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/'",

  //page #15
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Hackerspace etiquette - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Staff members - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/The Space - XinCheJian.html'",
  "echo hack me please",
  "echo hack me!!!",

  //page #20
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Aaaiiirrr.org - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/ArduBlock - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Helper Sessions - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Assistive Devices - XinCheJian.html'",
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/TheSpaceProjectS - XinCheJian.html'",

  //page #25
  "/usr/bin/chromium-browser '/home/ubuntu/Desktop/www/Urban Farming - XinCheJian.html'",
  "echo p26",
  "echo p27",
  "echo p28",
  "echo p29",

  //page #30
  "echo p30",
  "echo p31",
  "echo p32",
  "echo p33",
  "echo p34",

  //page #35
  "echo p35",
  "echo p36",
  "echo p37",
  "echo p38",
  "echo p39",

  //page #40
  "echo p40",
  "echo p41",
  "echo p42",
  "echo p43",
  "echo p44",

  //page #45
  "echo p45",
  "echo p46",
  "echo p47",
  "echo p48",
  "echo p49",

  //page #50
  "echo p50",
  "echo p51",
  "echo p52",
  "echo p53",
  "echo p54",

  //page #55
  "echo p55",
  "echo p56",
  "echo p57",
  "echo p58",
  "echo p59",

  //page #60
  "echo p60",
  "echo p61",
  "echo p62",
  "echo p63",

  //page #65
  "echo p65",
  "echo p66",
  "echo p67",
  "echo p68",
  "echo p69",

  //page #70
  "echo p70",
  "echo p71",
  "echo p72",
  "echo p73",
  "echo p74",

  //page #75
  "echo p75",
  "echo p76",
  "echo p77",
  "echo p78",
  "echo p79",

  //page #80
  "echo p80",
  "echo p81",
  "echo p82",
  "echo p83",
  "echo p84",

  //page #85
  "echo p85",
  "echo p86",
  "echo p87",
  "echo p88",
  "echo p89",

  //page #90
  "echo p90",
  "echo p91",
  "echo p92",
  "echo p93",
  "echo p94",

  //page #95
  "echo p95",
  "echo p96",
  "echo p97",
  "echo p98",
  "echo p99",

  //page #10
  "echo p100",
  "echo p101",
  "echo p102",
  "echo p103",
  "echo p104",

  //page #105
  "echo p105",
  "echo p106",
  "echo p107",
  "echo p108",
  "echo p109",

  //page #110
  "echo p110",
  "echo p111",
  "echo p112",
  "echo p113",
  "echo p114",

  //page #115
  "echo p115",
  "echo p116",
  "echo p117",
  "echo p118",
  "echo p119",

  //page #120
  "echo p120",
  "echo p121",
  "echo p122",
  "echo p123",
  "echo p124",

  //page #125
  "echo p125",
  "echo p126",
  "echo p127",
};


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as an output.
  for (int i = 0; i < buttonCount; i++){
    pinMode(i + button1, INPUT);     
  }

  char someText[256];
//          snprintf(someText, sizeof(someText), "echo XCJ opened at `date` | mail -s 'Subject' tsps@usabledevices.com ");

  snprintf(someText, sizeof(someText), "POWER ON/REBOOT `date` thespaceprojects:%s", tsps_ID);
  sendEmail("thespaceprojects@xinchejian.com", "thespaceprojects@xinchejian.com", someText, "'body text here'");  
}

// the loop routine runs over and over again forever:
void loop() {
  processButons();
}


// Read cmdNumber pressed
void processButons(){
  boolean anyPressed = false;
  unsigned int cmdNumber = 0;                // = remember which cmdNumber pressed, in binary

  char someText[256];

//simple to debouncing = detect ANY press, then wait a short while - THEN read the cmdNumber
  while (!anyPressed){
    for (int i = 0; i < buttonCount; i++){
        if (digitalRead(i + button1)){
          anyPressed = true;
          delay(300);  
        }
    }
  }
  anyPressed = false;

  // Now read ALL the cmdNumber pressed
  for (int i = buttonCount -1 ; i >= 0; i--){
	if (!digitalRead(i + button1)){
	    anyPressed = true;
	    cmdNumber += 1;
	}
	cmdNumber = cmdNumber << 1;
  }
  cmdNumber = cmdNumber >> 1;


  if (anyPressed){
      snprintf(someText, sizeof(someText), "echo Button = %d {decimal}, %x {Hexadecimal}", cmdNumber, cmdNumber);
      system(someText);
      //OK now run action for that button - ATM assumes all actions are browser + web page
      char cmdLine[256];
      snprintf(cmdLine, sizeof(cmdLine), "%s &", cmdLineS[cmdNumber]);	//don't wait for app to finish
//    snprintf(cmdLine, sizeof(cmdLine), "%s", cmdLineS[cmdNumber]);	//wait for app to finish
      snprintf(someText, sizeof(someText), "echo Command to run = %s", cmdLine);
      system(someText); // echo cmd line that will be run to the terminal
      system(cmdLine);  //execute the cmd!

      snprintf(someText, sizeof(someText), "Button: %d, `date`, thespaceprojects:%s", cmdNumber, tsps_ID);
      sendEmail("thespaceprojects@xinchejian.com", "thespaceprojects@xinchejian.com", someText, "'body text here'");
      delay(2000);
  }
}

// Function below works, but get different results running manually from terminal to this code.
// for example body text does not appear form below, but does from manual console.
// usage sendEmail(from, to, subject, body);
void sendEmail(char* fromTxt, char* toTxt, char* subjectTxt, char* bodyTxt){
  char cmdText[256];
  if (sendEmails ){
    snprintf(cmdText, sizeof(cmdText), "/home/ubuntu/Desktop/sendEmail.sh %s %s %s %s", fromTxt, toTxt, subjectTxt, bodyTxt);
    system(cmdText);
  }
  else{
    system("echo 'set sendEmails = true; to send emails!'");
  }
}


void tempSnippets(){


  boolean shift = false;
  boolean anyPressed = false;
  int cmdNumber = 0;                // = no cmdNumber pressed
  boolean currentButtonState = false;


  
/*
	//now loop until close button pressed
	while (digitalRead(BUTTON_CLOSE_PAGE)){};	// first up make sure Exit button NOT STILL pressed from above
        delay(1000);               // wait for a bit MORE FOR DEBOUNCE
	//now loop until close button RELEASED
	while(!digitalRead(BUTTON_CLOSE_PAGE)){

... hmmm sending key strokes to an app not so easy in *nix
seems to involve another app ......

so, what about run browser & WAIT for it to finish - ie no "&" in system(cmdLine<<<---)
and user uses k/b or mouse.....

BUTTON_UP
BUTTON_DOWN
BUTTON_LEFT
BUTTON_RIGHT
    }
  }
*/	
}
