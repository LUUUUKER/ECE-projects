#include <avr/io.h>
#include <util/delay.h>

#define IR_PIN 2

void setup() {
    DDRD &= ~(1 << IR_PIN); // Set IR_PIN as input
    PORTD |= (1 << IR_PIN); // Enable pull-up resistor for IR_PIN
}

uint8_t readIR() {
    while (PIND & (1 << IR_PIN)) {} // Wait for the pin to go low
    _delay_us(500); // Delay to ensure stable signal
    if (PIND & (1 << IR_PIN)) // Check if the pin is still high
        return 0xFF; // Error, no IR signal
    _delay_us(500); // Delay to ensure stable signal
    uint8_t data = 0;
    for (int i = 0; i < 8; i++) {
        _delay_us(500); // Delay to ensure stable signal
        if (PIND & (1 << IR_PIN)) // Check if the pin is high
            data |= (1 << i); // Set the corresponding bit in the data
        _delay_us(1000); // Delay to ensure stable signal
    }
    return data;
}

int main() {
    setup(); // Call setup function

    while (1) {
        uint8_t data = readIR(); // Read data from IR receiver
        if (data != 0xFF) { // Check if valid data received
            // Process the received data here
        }
    }
    return 0;
}