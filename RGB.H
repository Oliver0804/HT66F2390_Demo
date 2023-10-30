#include "MyType.h"	
//#define TinyRGB						//RGB�ҲխY�O�j�����A���Ѧ���

#ifdef TinyRGB
	enum {Green=1, Red, Blue, Alpha};
#else
	enum {Red=1, Green, Blue, Alpha};
#endif

#define  KeyPort	_pe
#define  KeyPortC	_pec
#define  KeyPortPU	_pepu

#define	_TX			_pa1			//�s�����Ū�RX (Yellow)
#define	_TXC		_pac1
#define	_RX			_pa3			//�s�����Ū�TX (Blue)
#define	_RXC		_pac3			
#define	fSYS		8000000	
#define	BaudRate	38400	
#define	BITC		(fSYS/BaudRate)	//Bit Interval Time Constant