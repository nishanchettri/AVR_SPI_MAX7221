/*
 * simple7segment.cpp
 *
 * Created: 09-04-2020 14:35:16
 *  Author: nishanchettri
	Website: www.nishanchettri.com
	github: github.com/nishanchettri
 */ 


#include <avr/io.h>
#include "segment7.h"
#include <util/delay.h>

segment7 segment; //initialiaze object for the library
int main(void)
{
	segment.begin(2);//put the number of displays that you want to connect
	segment.print(25);//print any number not alphabet!!
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}