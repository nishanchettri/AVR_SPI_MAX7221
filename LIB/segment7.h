/*
 * _7segment.h
 *
 * Created: 08-04-2020 22:05:19
 *  Author: nishan
 */ 


#ifndef segment7_H_
#define segment7_H_

#include <avr/io.h>

#define MOSI 5
#define SCK 7
#define SS 4
void spitransfer(unsigned char data);
void execute(unsigned char cmd,unsigned char info);
void exception();
class segment7
{
	public:
	
	segment7();
	void begin(uint8_t numDisplays);
	
	void displayTest(bool status);
	void intensity(uint8_t val);
	void print(int num);

};



#endif /* 7SEGMENT_H_ */