#include <avr/io.h>
#define F_CPU 11059200UL
// мог быть delay но он для слабых
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
        OCR3A = 1023;
        OCR3B = 511;
        OCR3C = 0;
    }
}
// C:\Users\student>git config --global http.proxy http://10.128.0.90:8080