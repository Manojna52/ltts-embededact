/*
 */

#include <avr/io.h>
#include<util/delay.h>
void initADC()
{

    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
uint16_t ReadADC(uint8_t ch)
{

    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

int main(void)
{
DDRB=0b00011110;
initADC();
uint16_t temp;
    while(1)
    {
      temp=ReadADC(0);
      _delay_ms(1000);
      if((temp>=0 && temp<=200))
      {
          PORTB|=(1<<PB1);
          PORTB&=~(1<<PB2);
            PORTB&=~(1<<PB3);
              PORTB&=~(1<<PB4);
      }
      else if(temp>=210 && temp<=500)
      {
            PORTB|=(1<<PB2);
          PORTB&=~(1<<PB1);
            PORTB&=~(1<<PB3);
              PORTB&=~(1<<PB4);

      }
      else if(temp>=510 && temp<=700)
      {
            PORTB|=(1<<PB3);
          PORTB&=~(1<<PB2);
            PORTB&=~(1<<PB1);
              PORTB&=~(1<<PB4);
      }
      else{
              PORTB|=(1<<PB4);
          PORTB&=~(1<<PB2);
            PORTB&=~(1<<PB1);
              PORTB&=~(1<<PB3);

      }
      }




    return 0;
}
