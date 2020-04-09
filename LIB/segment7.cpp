/*
 * _7segment.cpp
 *
 * Created: 08-04-2020 22:06:25
 *  Author: nishanchettri
 */ 
#include "segment7.h"
#include <util/delay.h>
void spitransfer(unsigned char data)
{
	SPDR=data;
	while(!(SPSR&(1<<SPIF)));
}

void execute(unsigned char cmd,unsigned char info)
{
	PORTB&=~(1<<SS);
	spitransfer(cmd);
	spitransfer(info);
	PORTB|=(1<<SS);
}
void exception()
{
	execute(0x0B,0x01);//scan 1 display
	execute(0x01,0x6F);//display e in display and blink meaning some error
	_delay_ms(200);
	execute(0x01,0x00);
	_delay_ms(200);
}


segment7::segment7()
{
	DDRB|=(1<<MOSI)|(1<<SCK)|(1<<SS);
	SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
	
}





void segment7::begin(uint8_t numDisplays)
{
	execute(0x0C,0x01);
	
	if ((numDisplays>0)||(numDisplays<9))
	{
		switch(numDisplays)
		{
			case 1:
			execute(0x09,0x01);
			execute(0x0B,0x01);
			break;
			case 2:
			execute(0x09,0x03);
			execute(0x0B,0x02);
			break;
			case 3:
			execute(0x09,0x07);
			execute(0x0B,0x03);
			break;
			case 4:
			execute(0x09,0x0F);
			execute(0x0B,0x04);
			break;
			case 5:
			execute(0x09,0x1F);
			execute(0x0B,0x05);
			break;
			case 6:
			execute(0x09,0x3F);
			execute(0x0B,0x06);
			break;
			case 7:
			execute(0x09,0x7F);
			execute(0x0B,0x07);
			break;
			case 8:
			execute(0x09,0xFF);
			execute(0x0B,0x08);
			break;
		}
	}
	else
	{
		exception();
	}
}



void segment7::displayTest(bool status)
{
	if (status)
	{
		execute(0x0F,0x01);
	}
	if (!status)
	{
		execute(0x0F,0x00);
	}
}
void segment7::intensity(uint8_t val)
{
	if (val<11)
	{
		switch(val)
		{
			case 0:
			execute(0x0A,0x00);
			break;
			case 1:
			execute(0x0A,0x02);
			break;
			case 2:
			execute(0x0A,0x04);
			break;
			case 3:
			execute(0x0A,0x05);
			break;
			case 4:
			execute(0x0A,0x07);
			break;
			case 5:
			execute(0x0A,0x0A);
			break;
			case 6:
			execute(0x0A,0x0B);
			break;
			case 7:
			execute(0x0A,0x0C);
			break;
			case 8:
			execute(0x0A,0x0D);
			break;
			case 9:
			execute(0x0A,0x0E);
			break;
			case 10:
			execute(0x0A,0x0F);
			break;
		}
		if(val>10)
		{
			exception();
		}
	}
}
void segment7::print(int num)
{
	int d0,d1,d2,d3,d4,d5,d6,d7,a=0,b=0,c=0,d=0,e=0,f=0,g=0;
	 a =num/10;
	 b =a/10;
	 c= b/10;
	 d= c/10;
	 e= d/10;
	 f=e/10;
	 g=f/10;
	d0=num%10;
	d1=a%10;
	d2=b%10;
	d3=c%10;
	d4=d%10;
	d5=e%10;
	d6=f%10;
	d7=g%10;
	execute(0x01,d0);
	execute(0x02,d1);
	execute(0x03,d2);
	execute(0x04,d3);
	execute(0x05,d4);
	execute(0x06,d5);
	execute(0x07,d6);
	execute(0x08,d7);
	
}

