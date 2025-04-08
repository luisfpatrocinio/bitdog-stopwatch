// Standard libraries
#include <stdio.h>
#include <math.h>

// Pico SDK libraries
#include "pico/stdlib.h"

// Custom libraries
#include "display.h"
#include "text.h"
#include "draw.h"
#include "buttons.h"

// Constants
#define DEG2RAD 0.0174532925

// Timer
repeating_timer_t timerMain;            // Timer for the main loop
int waitTimeSeconds = 10;               // Wait time in seconds
volatile bool buttonIsActive = true;    // Flag to check if the button is active
int currentSecond;                      // Current timer time

void resetTimer()
{
    currentSecond = waitTimeSeconds;    // Reset the timer to the initial value
    buttonIsActive = true;              // Reactivate the button
}

bool updateTimer()
{
    // Stop the timer when it reaches zero
    if (currentSecond == 0)
    {
        resetTimer();
        return false; 
    }

    // Decrement the timer
    currentSecond--;

    // Continue the timer
    return true;    
}

void drawInitialScreen()
{
    static int _ang = 0;
    _ang = (_ang + 12) % 360;
    int _y = 10 + sin(_ang * DEG2RAD) * 2;
    drawTextCentered("PatroStopWatch", _y);
}

void confirmButtonCallback(uint gpio, uint32_t events)
{
    if (gpio == BTA) // Botão A
    {
        if (!buttonIsActive)
            return;

        buttonIsActive = false; // Desativa o botão

        add_repeating_timer_ms(-1000, updateTimer, NULL, &timerMain);
    }
}

// Função para inicializar os dispositivos
void setup()
{
    stdio_init_all();
    initI2C();
    initDisplay();
    initializeButtons();
    setButtonCallback(confirmButtonCallback); // Configura o callback para os botões
    currentSecond = waitTimeSeconds; // Inicializa o timer
    clearDisplay();
}

int main()
{
    setup();

    while (true)
    {
        clearDisplay();

        drawInitialScreen();

        // Desenhar Timer
        char timerMessage[20];
        snprintf(timerMessage, sizeof(timerMessage), "Timer: %d", currentSecond);
        drawTextCentered(timerMessage, 20);

        char newTimerMessage[20];
        uint32_t timerValue = remaining_alarm_time_ms(timerMain.alarm_id);
        if (timerValue > 0) {
            snprintf(newTimerMessage, sizeof(newTimerMessage), "Timer: %d", timerValue);
            drawTextCentered(newTimerMessage, 36);
        }
        

        // Desenhar instrução:
        if (buttonIsActive)
            drawTextCentered("Press A to start", 50);
        else
            drawTextCentered("Timer started!", 50);

        showDisplay();
        tight_loop_contents(); // Aguarda o próximo ciclo
    }
}
