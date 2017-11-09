/* rawSend.ino Example sketch for IRLib2
 *  adapted to control old LEGO IR devices
 *  contains signals calculated by 'ir_generate.py'
 */
 
#include <IRLibSendBase.h>    //We need the base code
#include <IRLib_HashRaw.h>    //Only use raw sender

IRsendRaw mySender;

#define Ch1_OrangeNop_YellowNop_LEN 12
uint16_t Ch1_OrangeNop_YellowNop[Ch1_OrangeNop_YellowNop_LEN]={
  1040, 208, 208, 208, 208, 624, 208, 416, 208, 208, 1040, 416
  };
  
#define Ch1_OrangeNop_YellowFwd_LEN 12
uint16_t Ch1_OrangeNop_YellowFwd[Ch1_OrangeNop_YellowFwd_LEN]={
  1040, 208, 208, 208, 208, 624, 624, 208, 208, 624, 208, 624
  };

#define Ch1_OrangeNop_YellowRev_LEN 8
uint16_t Ch1_OrangeNop_YellowRev[Ch1_OrangeNop_YellowRev_LEN]={
  1040, 208, 208, 208, 208, 624, 624, 1872
  };

#define Ch1_OrangeNop_YellowStp_LEN 12
  uint16_t Ch1_OrangeNop_YellowStp[Ch1_OrangeNop_YellowStp_LEN]={
  1040, 208, 208, 208, 208, 624, 208, 416, 1040, 208, 208, 416
  };
  
#define Ch1_OrangeFwd_YellowNop_LEN 12
uint16_t Ch1_OrangeFwd_YellowNop[Ch1_OrangeFwd_YellowNop_LEN]={
  208, 624, 208, 208, 208, 208, 416, 416, 624, 208, 1248, 416
  };

#define Ch1_OrangeFwd_YellowFwd_LEN 14
uint16_t Ch1_OrangeFwd_YellowFwd[Ch1_OrangeFwd_YellowFwd_LEN]={
  208, 624, 208, 208, 208, 208, 416, 416, 208, 208, 208, 1040, 208, 624
  };

#define Ch1_OrangeFwd_YellowRev_LEN 14
uint16_t Ch1_OrangeFwd_YellowRev[Ch1_OrangeFwd_YellowRev_LEN]={
  208, 624, 208, 208, 208, 208, 416, 416, 208, 208, 208, 208, 208, 1456
  };
  
#define Ch1_OrangeFwd_YellowStp_LEN 14
uint16_t Ch1_OrangeFwd_YellowStp[Ch1_OrangeFwd_YellowStp_LEN]={
  208, 624, 208, 208, 208, 208, 416, 416, 624, 416, 624, 208, 208, 416
  };

#define Ch1_OrangeRev_YellowNop_LEN 10
uint16_t Ch1_OrangeRev_YellowNop[Ch1_OrangeRev_YellowNop_LEN]={
  208, 1040, 208, 208, 208, 624, 624, 416, 832, 624
  };  

#define Ch1_OrangeRev_YellowFwd_LEN 14
uint16_t Ch1_OrangeRev_YellowFwd[Ch1_OrangeRev_YellowFwd_LEN]={
  208, 1040, 208, 208, 208, 624, 208, 208, 208, 208, 208, 624, 416, 416
  };
  
#define Ch1_OrangeRev_YellowRev_LEN 12
uint16_t Ch1_OrangeRev_YellowRev[Ch1_OrangeRev_YellowRev_LEN]={
  208, 1040, 208, 208, 208, 624, 208, 208, 208, 1248, 208, 416
  };

#define Ch1_OrangeRev_YellowStp_LEN 10
uint16_t Ch1_OrangeRev_YellowStp[Ch1_OrangeRev_YellowStp_LEN]={
  208, 1040, 208, 208, 208, 624, 624, 208, 832, 832
  };
  
#define Ch1_OrangeStp_YellowNop_LEN 10
uint16_t Ch1_OrangeStp_YellowNop[Ch1_OrangeStp_YellowNop_LEN]={
  832, 416, 208, 208, 416, 416, 208, 416, 1248, 624
  };
 
#define Ch1_OrangeStp_YellowFwd_LEN 10
uint16_t Ch1_OrangeStp_YellowFwd[Ch1_OrangeStp_YellowFwd_LEN]={
  832, 416, 208, 208, 416, 416, 624, 1040, 416, 416
  };

#define Ch1_OrangeStp_YellowRev_LEN 12
uint16_t Ch1_OrangeStp_YellowRev[Ch1_OrangeStp_YellowRev_LEN]={
  832, 416, 208, 208, 416, 416, 624, 208, 208, 832, 208, 416
  };
  
#define Ch1_OrangeStp_YellowStp_LEN 12
uint16_t Ch1_OrangeStp_YellowStp[Ch1_OrangeStp_YellowStp_LEN]={
  832, 416, 208, 208, 416, 416, 208, 416, 208, 208, 624, 832
  };

#define Ch2_OrangeNop_YellowNop_LEN 12
uint16_t Ch2_OrangeNop_YellowNop[Ch2_OrangeNop_YellowNop_LEN]={
  1248, 416, 208, 624, 416, 208, 208, 208, 832, 624
  };

#define Ch2_OrangeNop_YellowFwd_LEN 10
uint16_t Ch2_OrangeNop_YellowFwd[Ch2_OrangeNop_YellowFwd_LEN]={
  1248, 416, 208, 624, 208, 416, 416, 624, 416, 416
  }; 

#define Ch2_OrangeNop_YellowRev_LEN 10
uint16_t Ch2_OrangeNop_YellowRev[Ch2_OrangeNop_YellowRev_LEN]={
  1248, 416, 208, 624, 208, 416, 208, 1040, 208, 416
  };

#define Ch2_OrangeNop_YellowStp_LEN 8
uint16_t Ch2_OrangeNop_YellowStp[Ch2_OrangeNop_YellowStp_LEN]={
  1248, 416, 208, 624, 416, 208, 1040, 832
  };

#define Ch2_OrangeFwd_YellowNop_LEN 10
uint16_t Ch2_OrangeFwd_YellowNop[Ch2_OrangeFwd_YellowNop_LEN]={
  208, 624, 416, 416, 416, 416, 208, 416, 1248, 624
  };

#define Ch2_OrangeFwd_YellowFwd_LEN 10
uint16_t Ch2_OrangeFwd_YellowFwd[Ch2_OrangeFwd_YellowFwd_LEN]={
  208, 624, 416, 416, 416, 416, 624, 1040, 416, 416
  };

#define Ch2_OrangeFwd_YellowRev_LEN 12
uint16_t Ch2_OrangeFwd_YellowRev[Ch2_OrangeFwd_YellowRev_LEN]={
  208, 624, 416, 416, 416, 416, 624, 208, 208, 832, 208, 416
  };

#define Ch2_OrangeFwd_YellowStp_LEN 12
uint16_t Ch2_OrangeFwd_YellowStp[Ch2_OrangeFwd_YellowStp_LEN]={
  208, 624, 416, 416, 416, 416, 208, 416, 208, 208, 624, 832
  };

#define Ch2_OrangeRev_YellowNop_LEN 12
uint16_t Ch2_OrangeRev_YellowNop[Ch2_OrangeRev_YellowNop_LEN]={
  208, 832, 208, 416, 208, 624, 208, 416, 208, 208, 1040, 416
  };

#define Ch2_OrangeRev_YellowFwd_LEN 12
uint16_t Ch2_OrangeRev_YellowFwd[Ch2_OrangeRev_YellowFwd_LEN]={
  208, 832, 208, 416, 208, 624, 624, 208, 208, 624, 208, 624
  };

#define Ch2_OrangeRev_YellowRev_LEN 8
uint16_t Ch2_OrangeRev_YellowRev[Ch2_OrangeRev_YellowRev_LEN]={
  208, 832, 208, 416, 208, 624, 624, 1872
  };

#define Ch2_OrangeRev_YellowStp_LEN 12
uint16_t Ch2_OrangeRev_YellowStp[Ch2_OrangeRev_YellowStp_LEN]={
  208, 832, 208, 416, 208, 624, 208, 416, 1040, 208, 208, 416
  };

#define Ch2_OrangeStp_YellowNop_LEN 10
uint16_t Ch2_OrangeStp_YellowNop[Ch2_OrangeStp_YellowNop_LEN]={
  832, 208, 208, 416, 416, 416, 416, 208, 1456, 416
  };

#define Ch2_OrangeStp_YellowFwd_LEN 12
uint16_t Ch2_OrangeStp_YellowFwd[Ch2_OrangeStp_YellowFwd_LEN]={
  832, 208, 208, 416, 416, 416, 208, 416, 208, 832, 208, 624
  };

#define Ch2_OrangeStp_YellowRev_LEN 10
uint16_t Ch2_OrangeStp_YellowRev[Ch2_OrangeStp_YellowRev_LEN]={
  832, 208, 208, 416, 416, 416, 208, 416, 416, 1456
  };
  
#define Ch2_OrangeStp_YellowStp_LEN 14
uint16_t Ch2_OrangeStp_YellowStp[Ch2_OrangeStp_YellowStp_LEN]={
  832, 208, 208, 416, 416, 416, 416, 208, 208, 208, 624, 208, 208, 416
  };

#define Ch3_OrangeNop_YellowNop_LEN 10
uint16_t Ch3_OrangeNop_YellowNop[Ch3_OrangeNop_YellowNop_LEN]={
  1040, 624, 416, 416, 208, 208, 416, 208, 832, 624
  };

#define Ch3_OrangeNop_YellowFwd_LEN 10
uint16_t Ch3_OrangeNop_YellowFwd[Ch3_OrangeNop_YellowFwd_LEN]={
  1040, 624, 416, 416, 416, 208, 416, 624, 208, 624
  };

#define Ch3_OrangeNop_YellowRev_LEN 8
uint16_t Ch3_OrangeNop_YellowRev[Ch3_OrangeNop_YellowRev_LEN]={
  1040, 624, 416, 416, 416, 208, 208, 1664
  };

#define Ch3_OrangeNop_YellowStp_LEN 8
uint16_t Ch3_OrangeNop_YellowStp[Ch3_OrangeNop_YellowStp_LEN]={
  1040, 624, 416, 416, 208, 208, 1248, 832
  };

#define Ch3_OrangeFwd_YellowNop_LEN 10
uint16_t Ch3_OrangeFwd_YellowNop[Ch3_OrangeFwd_YellowNop_LEN]={
  208, 624, 208, 624, 208, 624, 416, 208, 1456, 416
  };

#define Ch3_OrangeFwd_YellowFwd_LEN 12
uint16_t Ch3_OrangeFwd_YellowFwd[Ch3_OrangeFwd_YellowFwd_LEN]={
  208, 624, 208, 624, 208, 624, 208, 416, 208, 832, 208, 624
  };

#define Ch3_OrangeFwd_YellowRev_LEN 10
uint16_t Ch3_OrangeFwd_YellowRev[Ch3_OrangeFwd_YellowRev_LEN]={
  208, 624, 208, 624, 208, 624, 208, 416, 416, 1456
  };

#define Ch3_OrangeFwd_YellowStp_LEN 14
uint16_t Ch3_OrangeFwd_YellowStp[Ch3_OrangeFwd_YellowStp_LEN]={
  208, 624, 208, 624, 208, 624, 416, 208, 208, 208, 624, 208, 208, 416
  };

#define Ch3_OrangeRev_YellowNop_LEN 10
uint16_t Ch3_OrangeRev_YellowNop[Ch3_OrangeRev_YellowNop_LEN]={
  208, 1456, 416, 416, 416, 208, 208, 208, 832, 624
  };

#define Ch3_OrangeRev_YellowFwd_LEN 10
uint16_t Ch3_OrangeRev_YellowFwd[Ch3_OrangeRev_YellowFwd_LEN]={
  208, 1456, 416, 416, 208, 416, 416, 624, 416, 416
  };

#define Ch3_OrangeRev_YellowRev_LEN 10
uint16_t Ch3_OrangeRev_YellowRev[Ch3_OrangeRev_YellowRev_LEN]={
  208, 1456, 416, 416, 208, 416, 208, 1040, 208, 416
  };

#define Ch3_OrangeRev_YellowStp_LEN 8
uint16_t Ch3_OrangeRev_YellowStp[Ch3_OrangeRev_YellowStp_LEN]={
  208, 1456, 416, 416, 416, 208, 1040, 832
  };

#define Ch3_OrangeStp_YellowNop_LEN 8
uint16_t Ch3_OrangeStp_YellowNop[Ch3_OrangeStp_YellowNop_LEN]={
  832, 832, 208, 624, 208, 208, 1664, 416
  };

#define Ch3_OrangeStp_YellowFwd_LEN 10
uint16_t Ch3_OrangeStp_YellowFwd[Ch3_OrangeStp_YellowFwd_LEN]={
  832, 832, 208, 624, 416, 208, 208, 832, 416, 416
  };

#define Ch3_OrangeStp_YellowRev_LEN 10
uint16_t Ch3_OrangeStp_YellowRev[Ch3_OrangeStp_YellowRev_LEN]={
  832, 832, 208, 624, 416, 208, 416, 832, 208, 416
  };

#define Ch3_OrangeStp_YellowStp_LEN 12
uint16_t Ch3_OrangeStp_YellowStp[Ch3_OrangeStp_YellowStp_LEN]={
  832, 832, 208, 624, 208, 208, 416, 208, 624, 208, 208, 416
  };

#define All_OrangeNop_YellowNop_LEN 8
uint16_t All_OrangeNop_YellowNop[All_OrangeNop_YellowNop_LEN]={
  1456, 208, 416, 416, 624, 416, 832, 624
  };

#define All_OrangeNop_YellowFwd_LEN 12
uint16_t All_OrangeNop_YellowFwd[All_OrangeNop_YellowFwd_LEN]={
  1456, 208, 416, 416, 208, 208, 208, 208, 208, 624, 416, 416
  };
  
#define All_OrangeNop_YellowRev_LEN 10
uint16_t All_OrangeNop_YellowRev[All_OrangeNop_YellowRev_LEN]={
  1456, 208, 416, 416, 208, 208, 208, 1248, 208, 416
  };

#define All_OrangeNop_YellowStp_LEN 8
uint16_t All_OrangeNop_YellowStp[All_OrangeNop_YellowStp_LEN]={
  1456, 208, 416, 416, 624, 208, 832, 832
  };

#define All_OrangeFwd_YellowNop_LEN 12
uint16_t All_OrangeFwd_YellowNop[All_OrangeFwd_YellowNop_LEN]={
  208, 624, 624, 208, 208, 624, 208, 208, 208, 208, 1040, 624
  };

#define All_OrangeFwd_YellowFwd_LEN 10
uint16_t All_OrangeFwd_YellowFwd[All_OrangeFwd_YellowFwd_LEN]={
  208, 624, 624, 208, 208, 624, 416, 1248, 208, 624
  };

#define All_OrangeFwd_YellowRev_LEN 10
uint16_t All_OrangeFwd_YellowRev[All_OrangeFwd_YellowRev_LEN]={
  208, 624, 624, 208, 208, 624, 416, 416, 208, 1456
  };

#define All_OrangeFwd_YellowStp_LEN 12
uint16_t All_OrangeFwd_YellowStp[All_OrangeFwd_YellowStp_LEN]={
  208, 624, 624, 208, 208, 624, 208, 208, 208, 416, 624, 832
  };

#define All_OrangeRev_YellowNop_LEN 12
uint16_t All_OrangeRev_YellowNop[All_OrangeRev_YellowNop_LEN]={
  208, 832, 416, 208, 416, 416, 208, 208, 208, 416, 1040, 416
  };

#define All_OrangeRev_YellowFwd_LEN 12
uint16_t All_OrangeRev_YellowFwd[All_OrangeRev_YellowFwd_LEN]={
  208, 832, 416, 208, 416, 416, 416, 416, 208, 624, 416, 416
  };

#define All_OrangeRev_YellowRev_LEN 10
uint16_t All_OrangeRev_YellowRev[All_OrangeRev_YellowRev_LEN]={
  208, 832, 416, 208, 416, 416, 416, 1456, 208, 416
  };

#define All_OrangeRev_YellowStp_LEN 14
uint16_t All_OrangeRev_YellowStp[All_OrangeRev_YellowStp_LEN]={
  208, 832, 416, 208, 416, 416, 208, 208, 208, 208, 832, 208, 208, 416
  };

#define All_OrangeStp_YellowNop_LEN 10
uint16_t All_OrangeStp_YellowNop[All_OrangeStp_YellowNop_LEN]={
  832, 208, 416, 208, 208, 624, 624, 208, 1248, 416
  };

#define All_OrangeStp_YellowFwd_LEN 12
uint16_t All_OrangeStp_YellowFwd[All_OrangeStp_YellowFwd_LEN]={
  832, 208, 416, 208, 208, 624, 208, 208, 208, 1040, 208, 624
  };

#define All_OrangeStp_YellowRev_LEN 12
uint16_t All_OrangeStp_YellowRev[All_OrangeStp_YellowRev_LEN]={
  832, 208, 416, 208, 208, 624, 208, 208, 208, 208, 208, 1456
  };

#define All_OrangeStp_YellowStp_LEN 12
uint16_t All_OrangeStp_YellowStp[All_OrangeStp_YellowStp_LEN]={
  832, 208, 416, 208, 208, 624, 624, 416, 624, 208, 208, 416
  };


void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  Serial.println(F("Every time you press a key is a serial monitor we will send."));
}


#define WAIT 25

void loop() {
  if (Serial.available()) {
    switch(Serial.read()) {
      
      case 'F':
        mySender.send(All_OrangeFwd_YellowFwd,All_OrangeFwd_YellowFwd_LEN,76);
        delay(WAIT);
        break;

      case 'B':
        mySender.send(All_OrangeRev_YellowRev,All_OrangeRev_YellowRev_LEN,76);
        delay(WAIT);
        break;

      case 'L':
        mySender.send(All_OrangeFwd_YellowRev,All_OrangeFwd_YellowRev_LEN,76);
        delay(WAIT);
        break;

      case 'R':
        mySender.send(All_OrangeRev_YellowFwd,All_OrangeRev_YellowFwd_LEN,76);
        delay(WAIT);
        break;

      case '1':
        mySender.send(All_OrangeNop_YellowFwd,All_OrangeNop_YellowFwd_LEN,76);
        delay(WAIT);
        break;

      case '0':
        mySender.send(All_OrangeNop_YellowRev,All_OrangeNop_YellowRev_LEN,76);
        delay(WAIT);
        break;

      case '2':
        mySender.send(All_OrangeFwd_YellowNop,All_OrangeFwd_YellowNop_LEN,76);
        delay(WAIT);
        break;

      case '3':
        mySender.send(All_OrangeRev_YellowNop,All_OrangeRev_YellowNop_LEN,76);
        delay(WAIT);
        break;
      
    }


  }
}
