#include<stdio.h>

void main(){
	FILE *f;
	f = fopen("/var/run/hostapd-phy0.conf", "r");
	if(f)
	      printf("successssssss");
	else
	      printf("ffffffffffailed");
}
