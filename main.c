#include <avr/io.h>
#define F_CPU 11059200UL
//мог быть delay но он для слабых
#include <avr/interrupt.h>   //для использования прерываний
//———————————————
//———————————————

// void timer_ini(void)
// {
// 	ETIMSK = (1<<TOIE3);
// 	TCCR3B = (1<<CS32);
// 	TCNT3 = 43795;
// }


int main(void)
{
	DDRE = 0b00111000;  //вывод светодиода
	TCCR3A = (1<<CS30);  //43200 max
    TCCR3B = (1<<CS30);
    TCCR3C = (1<<CS30);

	
	// timer_ini();
	sei(); //разрешение прерываний
	while (1){
        OCR3A = 65000;
        OCR3B = 20000;
        OCR3C = 0;

    }
}
// C:\Users\student>git config --global http.proxy http://10.128.0.90:8080