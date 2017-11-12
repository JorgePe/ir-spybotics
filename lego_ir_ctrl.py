#! /usr/bin/env python3

# Use keyboard to control old LEGO devices with LIRC
# - '1', '2', '3', '4': choose channel for Old LEGO protocol (4 = All)
# - '5' : choose PF #1 channel
# - F: move forward
# - B: move back
# - L: rotate left
# - R: rotate right
# - Q: quit
#
# For FTDI-X needs sudo or root rights (or device rule)
# before using script assure lircd is running for the right FTDI-X device
# sudo lircd -dserial=DN02SWUF,output=3 -Hftdix
#
# need boht LIRC configuration files:
# - 'LEGO_Old_RC.conf' for old LEGO IR protocol
# - 'All_Combo_Direct.conf' for LEGO Power Functions IR protocol
#

from subprocess import run
import getch                        # sudo pip3 install getch
from time import sleep

Channels = ['Old#1', 'Old#2', 'Old#3', 'Old#All', 'PF#1', 'PF#2', 'PF#3', 'PF#4']


def front(channel):
    if channel == 0:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch1_OrangeFwd_YellowFwd'])
    elif channel == 1:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch2_OrangeFwd_YellowFwd'])
    elif channel == 2:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch3_OrangeFwd_YellowFwd'])
    elif channel == 3:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'All_OrangeFwd_YellowFwd'])
    elif channel == 4:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '1_FORWARD_FORWARD'])
    elif channel == 5:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '2_FORWARD_FORWARD'])
    elif channel == 6:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '3_FORWARD_FORWARD'])
    elif channel == 7:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '4_FORWARD_FORWARD'])


def back(channel):
    if channel == 0:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch1_OrangeRev_YellowRev'])
    elif channel == 1:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch2_OrangeRev_YellowRev'])
    elif channel == 2:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch3_OrangeRev_YellowRev'])
    elif channel == 3:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'All_OrangeRev_YellowRev'])
    elif channel == 4:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '1_BACKWARD_BACKWARD'])
    elif channel == 5:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '2_BACKWARD_BACKWARD'])
    elif channel == 6:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '3_BACKWARD_BACKWARD'])
    elif channel == 7:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '4_BACKWARD_BACKWARD'])


def left(channel):
    if channel == 0:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch1_OrangeFwd_YellowRev'])
    elif channel == 1:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch2_OrangeFwd_YellowRev'])
    elif channel == 2:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch3_OrangeFwd_YellowRev'])
    elif channel == 3:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'All_OrangeFwd_YellowRev'])
    elif channel == 4:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '1_BACKWARD_FORWARD'])
    elif channel == 5:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '2_BACKWARD_FORWARD'])
    elif channel == 6:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '3_BACKWARD_FORWARD'])
    elif channel == 7:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '4_BACKWARD_FORWARD'])


def right(channel):
    if channel == 0:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch1_OrangeRev_YellowFwd'])
    elif channel == 1:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch2_OrangeRev_YellowFwd'])
    elif channel == 2:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'Ch3_OrangeRev_YellowFwd'])
    elif channel == 3:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_Old_RC', 'All_OrangeRev_YellowFwd'])
    elif channel == 4:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '1_FORWARD_BACKWARD'])
    elif channel == 5:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '2_FORWARD_BACKWARD'])
    elif channel == 6:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '3_FORWARD_BACKWARD'])
    elif channel == 7:
        run(['irsend', '-d', '/var/run/lirc/lircd', 'SEND_ONCE', 'LEGO_All_Combo_Direct', '4_FORWARD_BACKWARD'])


channel = 0

while(True):
    print('Channel: ',Channels[channel],'   \r',end='')
    c = char = getch.getch()
    if c == '1':
        channel = 0
    elif c == '2':
        channel = 1
    elif c == '3':
        channel = 2
    elif c == '4':
        channel = 3
    elif c == '5':
        channel = 4
    elif c == '6':
        channel = 5
    elif c == '7':
        channel = 6
    elif c == '8':
        channel = 7
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
