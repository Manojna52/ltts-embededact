/*
 */

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
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
initADC();
TCCR0A |=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
TCCR0B|=(1<<CS00)|(1<<CS01);
DDRD|=(1<<PD6);

uint16_t temp;
    while(1)
    {
      temp=ReadADC(0);
      _delay_ms(1000);
      if((temp>=0 && temp<=200))
      {
         OCR0A=52;
        _delay_ms(2000);

      }
      else if(temp>=210 && temp<=500)
      {

 OCR0A=105;
        _delay_ms(2000);

      }
      else if(temp>=510 && temp<=700)
      {
           OCR0A=179;
        _delay_ms(2000);

      }
      else{
           OCR0A=243;
        _delay_ms(2000);

      }
      }




    return 0;
}
