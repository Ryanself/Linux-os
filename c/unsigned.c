#include <stdio.h>
#include <stdint.h>
#include <glob.h>

static char * zz(int sig)
  {
      static char buf[10];
       if (!sig)
       snprintf(buf, sizeof(buf), "unknown");
      else
       snprintf(buf, sizeof(buf), "%d dBm", sig);

       return buf;
  }



static char * gg(int qual)
  {
       static char buf[8];
        if (qual < 0)
        snprintf(buf, sizeof(buf), "unknown");
       else
        snprintf(buf, sizeof(buf), "%d", qual);

         return buf;
  }
  void main()
{
	char* a1 = "-28";
	char* a2 = "3";

	int rssi1 = atoi(a1);
	int rssi2 = atoi(a2);

	printf(">>>>>>>rssi1 %d  rssi2 %d>>>>>\n", rssi1, rssi2);

	uint8_t sig1 = rssi1;
	uint8_t sig2 = rssi2;
	uint8_t sig3 = 255;

	printf(">>>>>>>sig1 %s>>>>>\n", zz(sig1));

	printf(">>>>>>>sig1 %s>>>>>\n", zz(sig1 - 0x100));
        printf(">>>>>>>sig2 %s>>>>>\n",  zz(sig2));


        printf(">>>>>>>sig2 %s>>>>>\n",  zz(sig2 - 0x100));
	printf(">>>>>>>sig2 %s>>>>>\n",  gg(sig2));
	printf(">>>>>>>sig3 %s>>>>>\n",  zz(sig3));
	printf(">>>>>>>sig3 %s>>>>>\n",  zz(sig3 - 0x100));

}
