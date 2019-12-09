#include <stdio.h>
#include <stdint.h>
enum ieee80211_channel_flags {
       IEEE80211_CHAN_DISABLED       = 1<<0,
       IEEE80211_CHAN_NO_IR       = 1<<1,
       /* hole at 1<<2 */
	IEEE80211_CHAN_RADAR       = 1<<3,
	IEEE80211_CHAN_NO_HT40PLUS     = 1<<4,
	IEEE80211_CHAN_NO_HT40MINUS    = 1<<5,
	IEEE80211_CHAN_NO_OFDM       = 1<<6,
	IEEE80211_CHAN_NO_80MHZ       = 1<<7,
	IEEE80211_CHAN_NO_160MHZ       = 1<<8,
	IEEE80211_CHAN_INDOOR_ONLY     = 1<<9,
	IEEE80211_CHAN_IR_CONCURRENT   = 1<<10,
	IEEE80211_CHAN_NO_20MHZ       = 1<<11,
	IEEE80211_CHAN_NO_10MHZ       = 1<<12,
	IEEE80211_CHAN_RADAR_BACKUP    = 1<<13,
};

int main(){
	uint32_t a = 0x00f34f;
	uint32_t b = 0;
	b |= IEEE80211_CHAN_RADAR;
	uint32_t c = IEEE80211_CHAN_RADAR;
	int e = sizeof(IEEE80211_CHAN_IR_CONCURRENT);
	printf("a %x\n",a);
	printf("b %x  c %x \n", b, c);
	printf("~b %x   ~c %x ~%x\n", ~b, ~c, ~IEEE80211_CHAN_RADAR);
	printf("a&=~c %x\n", a&(~c));
	printf("a&=~c %x\n", a&=~IEEE80211_CHAN_RADAR);
	printf("%d   %d  \n", e, e);
	return 0;
}
