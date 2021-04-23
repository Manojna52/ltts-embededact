/**
 * @file project_main.c
 * @author manojna (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include<util/delay.h>
int main(void)
{
    /**
     * @brief setting the directional port the the b0 is set as input
     * AND D0 and D1 is set as input
     * 
     */

DDRB=0b00000001;
DDRD=0b00000000;
PORTD=0b00000011;
/**
 * @brief infinite loop
 * 
 */
while(1)
{
    /**
     * @brief if both the pd0 and pd1 triggers then enter into if and if it doesnt
     * the else will execute
     * 
     */
if((!(PIND&(1<<PD0))) &&(!(PIND&(1<<PD1))))
{

    PORTB|=(1<<PB0);
}
else
{


    PORTB&=~(1<<PB0);
}
}

}
