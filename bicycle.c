#include "HT66F2390.h"
#include "Mytype.H"
void Delayms(u16);

#include "HT66F2390.h"

#define LED_PORT _pdc  // Enable register
#define LED1 _pd0      // Output IO port for LED1
#define LED2 _pd2      // Output IO port for LED2
#define LED3 _pd4      // Output IO port for LED3


void main() {
    _wdtc=0b10101111;  // Disable watchdog timer

    LED_PORT=0b00001111;        // Set PDC register as output mode 1=Read 0=output
    LED1=0;
    LED2=0;
    LED3=0;
    while(1) {
        LED1 = !LED1;   // Toggle LED1 state
        LED2 = !LED2;   // Toggle LED1 state
        LED3 = !LED3;   // Toggle LED1 state
        Delayms(500); // Delay 500 milliseconds (assuming _delay_ms function is available)
    }
}


void Delayms(u16 del)
{	u16 i;
	for(i=0;i<del;i++) GCC_DELAY(2000);		//Delay del ms @fSYS=8MHz
}