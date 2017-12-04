/*
 * File:   main.c
 * Author: robda
 *
 * Created on 03 December 2017, 17:47
 */


#include <pic.h> 
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF ); 

#define RS RA1
#define RW RA2
#define E  RA3
#include<string.h>
void delay()
{
    for(int i = 0; i < 500; i++);
}

void writeCmd(char c)
{
    RS = 0;
    RW = 0;
    E = 0;
    
    delay();
    E = 1;
    PORTD = c;
    delay();
    E = 0;
}

void writeData(char c)
{
    RS = 1;
    RW = 0;
    E = 0;
    delay();
    E = 1;
    PORTD = c;
    delay();
    E = 0;
}

void init()
{
    TRISA = 0;
    TRISD = 0;
    PORTA = 0;
    PORTD = 0;
    ADCON1 = 0x6;
    writeCmd(0x0F);
    writeCmd(0x01);
    writeCmd(0x38);

}

void main()
{
    init();
    delay();
    char i[] = {'1','2','3'};
    for (int h = 0; h < 3; ++h)
    {
        writeData(i[h]);
    }
    while(1);
}