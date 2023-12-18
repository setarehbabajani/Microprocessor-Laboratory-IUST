/*******************************************************
This program was created by the
CodeWizardAVR V3.14 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : HW9
Version : 
Date    : 12/16/2023
Author  : setareh babajani
Company : IUST
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/
#include <mega32.h>
#include <alcd.h>
#include <stdio.h>

void usart_send_string(char *str);
unsigned char i;
void main(void)
{
    unsigned char a, counter=0;
    UCSRA=0x00;
    UCSRB=0x18;
    UCSRC=0x86;
    UBRRH=0x00;
    UBRRL=0x33;

    lcd_init(16);

    while (1)
      {
        a = getchar();
        lcd_putchar(a);
        putchar(a);
        if(a == 'C')      
        {
            lcd_clear();  
            putchar(0x0D);
            putchar(0x0A); 
        }  
        else if(a == 'c')
        {
            for(counter =0; counter < 24; counter++)
            {          
                putchar(0x0D);   
                putchar(0x0A);
            }
        }
        else if(a == 'N')
        {       
            putchar(0x0D); 
            putchar(0x0A); 
            usart_send_string("Setareh Babajani");
            putchar(0x0D); 
            putchar(0x0A); 
            
        }
        else if(a == 'M')
        {
            
            putchar(0x0D);   
            putchar(0x0A);
            lcd_clear();
            lcd_gotoxy(5,0);
            lcd_puts("Setareh");
            lcd_gotoxy(0,1);
            lcd_puts("Babajani");          
        }
          
      }        
}
void usart_send_string(char *str)
{
    for(i=0;str[i];i++)
    putchar(str[i]);
}

