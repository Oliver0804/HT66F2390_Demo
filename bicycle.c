#include "HT66F2390.h"
#include "Mytype.H"
void Delayms(u16);

#include "HT66F2390.h"

#define LED_PORT _pdc  // Enable register
#define LEDA _pd0      // Output IO port for LED1
#define LEDB _pd2      // Output IO port for LED2
#define LEDC _pd4      // Output IO port for LED3

#define LED1C	_phc1					//�w�q��ڳs�����󪺦W��
#define LED1	_ph1
#define LED2C	_phc0
#define LED2	_ph0

void main() {
    _wdtc=0b10101111;  // Disable watchdog timer
    LED_PORT=0b00001010;        // Set PDC register as output mode 1=Read 0=output
    LEDA=0;
    LEDB=0;
    LEDC=0;
	_stm2c0=0b00100000;					//fINT=fSYS/16 -> 500KHz
	_stm2c1=0b11000001;					//Timer/Counter�Ҧ�,A�k�X�M��
	_stm2al=(u8)50000; _stm2ah=50000>>8;//50000x2us=100ms	
	LED1C=0; LED2C=0;					//�}���V�W��
	LED1=0; LED2=0;						//�}��Ǧ�]�w
	_stm2ae=1; _mf4e=1; _emi=1;			//���_�P��
	_st2on=1;							//�Ұ�TM2�}�l�p��
	while(1)
	{	LED2=!LED2;						//����LED2���A
		Delayms(1000); 					//����@��
	}
}




DEFINE_ISR(ISR_STM2,0x38)
{	LED1=!LED1;							//����LED1���A
	_stm2af=0;							//�@�ɫ�,�X�Эn�ۦ�M��
}

void Delayms(u16 del)
{	u16 i;
	for(i=0;i<del;i++) GCC_DELAY(2000);		//Delay del ms @fSYS=8MHz
}