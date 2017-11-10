#! /usr/bin/env python3

# Use keyboard to control old LEGO devices with LIRC
# - choose channel with '1', '2', '3', '4' for All
# - F: move forward
# - B: move back
# - L: rotate left
# - R: rotate right
#
# For FTDI-X needs sudo or root rights (or device rule)
# before using script assure lircd is running for the right FTDI-X device
# sudo lircd -dserial=DN02SWUF,output=3 -Hftdix
#

from subprocess import run
import getch                        # sudo pip3 install getch
from time import sleep

def front(channel):
    if channel == 1:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch1_OrangeFwd_YellowFwd'])
    elif channel == 2:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch2_OrangeFwd_YellowFwd'])
    elif channel == 3:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch3_OrangeFwd_YellowFwd'])
    else:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'All_OrangeFwd_YellowFwd'])


def back(channel):
    if channel == 1:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch1_OrangeRev_YellowRev'])
    elif channel == 2:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch2_OrangeRev_YellowRev'])
    elif channel == 3:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch3_OrangeRev_YellowRev'])
    else:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'All_OrangeRev_YellowRev'])

def left(channel):
    if channel == 1:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch1_OrangeRev_YellowFwd'])
    elif channel == 2:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch2_OrangeRev_YellowFwd'])
    elif channel == 3:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch3_OrangeRev_YellowFwd'])
    else:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'All_OrangeRev_YellowFwd'])

def right(channel):
    if channel == 1:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch1_OrangeFwd_YellowRev'])
    elif channel == 2:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch2_OrangeFwd_YellowRev'])
    elif channel == 3:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch3_OrangeFwd_YellowRev'])
    else:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'All_OrangeFwd_YellowRev'])

channel = 1

while(True):
    print('Channel: ',channel,'\r',end='')
    c = char = getch.getch()
    if c == '1':
        channel = 1
    elif c == '2':
        channel = 2
    elif c == '3':
        channel = 3
    elif c == '4':
        channel = 4
    elif c == 'F' or c == 'f':
        front(channel)
    elif c == 'B' or c == 'b':
        back(channel)
    elif c == 'L' or c == 'l':
        left(channel)
    elif c == ' R' or c == 'r':
        right(channel)
    elif c == 'Q' or c == 'q':
        exit()
    sleep(0.01)