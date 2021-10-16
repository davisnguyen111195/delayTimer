/*
 * File:   main.c
 * Author: vedan
 *
 * Created on June 24, 2021, 1:59 PM
 */


#include "config.h"


void __interrupt() ISR(){
    static unsigned int counter = 0;
    if(INTCONbits.INTF == 1) {
        TMR0 = 5;
        INTCONbits.T0IF = 0;
        counter++;
        if(counter == 1000){
            PORTD = ~PORTD;
            counter = 0;
        }
    }
}
    
void main(void) {
    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.PSA = 0;
    OPTION_REGbits.PS2 = 0;
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS0 = 0;
    INTCONbits.GIE = 1;
    INTCONbits.T0IE = 1;
    INTCONbits.T0IF = 0;
    TRISD = 0;
    PORTD = 0;
    while(1);
    return;
}
