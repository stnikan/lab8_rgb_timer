#include <avr/io.h>
#define F_CPU 11059200UL
#include <util/delay.h>

int main(void)
{
	DDRE = 0b00111000;
    uint8_t my_color[] = {(1<<4),(1<<5),(1<<6),(1<<4)|(1<<5),(1<<4)|(1<<6),(1<<6)|(1<<5),(1<<4)|(1<<5)|(1<<6)};
while(1){
    for (uint8_t i = 0; i<=7;i++){
        PORTE = my_color[i];
        _delay_ms(200);
        }
}

}