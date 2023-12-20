#include <avr/io.h>
#define F_CPU 11059200UL
#include <util/delay.h>
#include <avr/interrupt.h> //для использования прерываний
// ———————————————
// ———————————————

// void timer_ini(void)
// {
// 	ETIMSK = (1<<TOIE3);
// 	TCCR3B = (1<<CS32);
// 	TCNT3 = 43795;
// }

int main(void)
{
    DDRE = 0b00111000;    // вывод светодиода
    TCCR3A = (1 << COM3A1) | (1 << COM3B1) | (1 << COM3C1) | (1 << WGM31) | (1 << WGM30);
    TCCR3B = (1 << CS30);

    // timer_ini();
    // sei(); // разрешение прерываний
    while (1)
    {   
        for (uint16_t i = 0;i<1023;i=i+10){
            for (uint16_t j = 0;j<1023;j=j+10){
                for (uint16_t l = 0;l<1023;l=l+10){
                    OCR3A = i;
                    OCR3B = j;
                    OCR3C = l;
                    _delay_us(100);
                }
            }
        }
        

    }
}
// C:\Users\student>git config --global http.proxy http://10.128.0.90:8080