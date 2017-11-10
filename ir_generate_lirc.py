#! /usr/bin/env python3

#
# Generate the IR signals to control old LEGO IR devices used with
# - MINDSTORMS Spybotics (3806, 3807, 3808 and 3809)
# - Bionicle Technic Manas (8539)
# - DUPLO RC Dozer (2949)
# - Technic RC Nitro Flash (4589)
# it will probably also work with the RC Train (7897) but don't have one to test
#
# IR signal uses a 76 kHz carrier
# Each message contains 2 bytes where each nibble as a purpose:
# Channel + Orange Command + Yellow Command + Checkdigit
#
# Message is sent at 4800 bps.
# Each byte has a start bit, 8 data bits (LSB first), 1 odd parity bit and 1 stop bit.
#
# This python script calculates the timings for all possibly messages in a format
# compatible with LIRC
#

BIT_LENGTH = 208    # 1 bit = 208 us long, based on 4800 bit/s
PAUSE = 208         # arbitrary pause of 1 bit between each byte, seems OK

CHANNEL = {'Ch1':0x05, 'Ch2':0x06, 'Ch3':0x07, 'All':0x04}
CMD_ORANGE = {'OrangeNop':0x00, 'OrangeFwd':0x07, 'OrangeRev':0x0F, 'OrangeStp':0x08}
CMD_YELLOW = {'YellowNop':0x00, 'YellowFwd':0x07, 'YellowRev':0x0F, 'YellowStp':0x08}

def reversed( x, num_bits ):
    answer = 0
    for i in range( num_bits ):                   # for each bit number
        if (x & (1 << i)):                        # if it matches that bit
            answer |= (1 << (num_bits - 1 - i))   # set the "opposite" bit in answer
    return answer


def parityOf(int_type):
    parity = 0
    while (int_type):
        parity = ~parity
        int_type = int_type & (int_type - 1)
    return(parity)


def getsignal(channel, orange, yellow):

    # calculate check digit
    check = 0x10 - ((channel + orange + yellow) & 0x0F)

    # convert to binary
    byte1 = channel * 16 + orange
    byte2 = yellow * 16 + check

    # revert bytes
    revbyte1 = reversed(byte1, 8)
    revbyte2 = reversed(byte2, 8)

    # calculate odd parity
    if parityOf(revbyte1) == 0:
        odd1 = '1'
    else:
        odd1 = '0'

    if parityOf(revbyte2) == 0:
        odd2 = '1'
    else:
        odd2 = '0'

    # create message by adding start bit, byte, parity bit and stop bits (with a 1 bit extra in between)
    message = '0' + "{0:08b}".format(revbyte1) + odd1 + '1'
    message += '1'
    message += '0' + "{0:08b}".format(revbyte2) + odd2 + '1'

    lirc = hex(int(message,2))

    return message, lirc

# Main

print('begin remote')
print('  name LEGO_Old_RC')
print('  bits 23')
print('  frequency 76000')
print('  one   1   208')
print('  zero  208   1')
print('  gap   208')
print()
print('  begin codes')


for chn in CHANNEL:
    for cmd_orange in CMD_ORANGE:
        for cmd_yellow in CMD_YELLOW:
            msg, lirc = getsignal(CHANNEL[chn], CMD_ORANGE[cmd_orange], CMD_YELLOW[cmd_yellow])
            print('     ',chn+'_'+cmd_orange+'_'+cmd_yellow,' ', lirc)

print('  end codes')
print('end remote')