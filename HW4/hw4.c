/*******************************************************
This program was created by the
CodeWizardAVR V3.14 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : HW4
Version : 
Date    : 11/21/2023
Author  : setareh babajani(99521109)
Company : IUST
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/
#include <mega32.h>
#include <delay.h>

//initialized time         
unsigned int hour1   = 3;
unsigned int hour2   = 2; 
unsigned int minute1 = 8;
unsigned int minute2 = 5;
unsigned int second1 = 0;
unsigned int second2 = 0;

char dot = 0x80;
unsigned int counter = 0; 

char number[] = { 0x3F, 0x06, 0x5B, 0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F }  ;

// Timer 0 output compare interrupt service routine
interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
   counter++;
    if (counter == 6) 
        counter=0;
}


// Timer1 output compare A interrupt service routine
interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{
    dot = 0x00;
    second1+=1;
    if (second1%2 == 0)
        dot = 0x80;
            
    if(second1==10)
    {
        second1=0;
        second2+=1;
        if(second2==6)
        { 
            second2=0;
            minute1+=1;
            if (minute1==10)
            {
                minute1=0;      
                minute2+=1; 
                if (minute2==6)
                {
                    minute2=0;      
                    hour1+=1;   
                    if (hour1==4 && hour2 == 2 )
                    {
                        hour1=0;      
                        hour2=0;
                    }
                    else if (hour1==10 && hour2 == 0 )
                    {
                        hour1=0;      
                        hour2+=1;
                    }
                }
            }
       } 
    }
}

// Declare your global variables here
void main(void)
{
//ports are self generated and i have only changed their value
PORTA=0x00;
DDRA=0x00;

PORTB=0x00;
DDRB=0x00;

PORTC=0x00;
DDRC=0xFF;

PORTD=0x00;
DDRD=0xFF;

TCCR0=0x0C;
TCNT0=0x00;
OCR0=0x63;

TCCR1A=0x00;
TCCR1B=0x0C;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x7A;
OCR1AL=0x12;
OCR1BH=0x00;
OCR1BL=0x00;

TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

MCUCR=0x00;
MCUCSR=0x00;

TIMSK=0x12;

// Analog Comparator initialization
ACSR=0x80;
SFIOR=0x00;

// Global enable interrupts
#asm("sei")

while (1)
{
    if(counter == 0)
    {
        PORTD = 0b11111110;
        PORTC = number[hour2];
    }
        
    else if(counter == 1)
    { 
        PORTD = 0b11111101;
        PORTC = number[hour1]| dot;
    } 
      
    else if(counter == 2) {
        PORTD = 0b11111011;
        PORTC = number[minute2];
    } 
      
    else if(counter == 3)
    {
        PORTD = 0b11110111;
        PORTC = number[minute1]| dot;
    }  
      
    else if(counter == 4) {
        PORTD = 0b11101111;
        PORTC = number[second2];
    }    
      
    else if(counter == 5){
        PORTD = 0b11011111;
        PORTC = number[second1] | dot;
    }
}
}