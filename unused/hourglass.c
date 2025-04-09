#include "hourglass.h"

Hourglass globalHourglass;

// array de sandpixels
SandPixel sandPixels[10]; 

SandPixel createSandPixel() {
    SandPixel pixel;
    pixel.x = 0; 
    pixel.y = 0; 
    pixel.vx = (rand() % 3) - 1;    // Vel X (-1, 0, 1)
    pixel.vy = rand() % 2 + 1;      // Vel Y (1, 2)
    pixel.active = 1; // Mark as active
    return pixel;
}

void resetSandPixel(SandPixel* pixel) {
    pixel->x = rand() % (globalHourglass.width - 2) + globalHourglass.x + 1; // Random X within hourglass width
}

void updateSandPixel(SandPixel* pixel) {
    // Update position
    pixel->x += pixel->vx;
    pixel->y += pixel->vy;

    // Check if the pixel is at bottom
    if (pixel->y > globalHourglass.y + globalHourglass.height) {
        resetSandPixel(pixel); // Reset position
    }
}

void initSandPixels() {
    for (int i = 0; i < 10; i++) {
        sandPixels[i] = createSandPixel(); 
    }
}

void drawHourglass(Hourglass* hourglass) {
    // Left side
    drawLine(hourglass->x, hourglass->y, hourglass->x + hourglass->width, hourglass->y + hourglass->height); 
    // Right side
    drawLine(hourglass->x, hourglass->y + hourglass->height, hourglass->x + hourglass->width, hourglass->y); 
    // Bottom side
    drawLine(hourglass->x, hourglass->y + hourglass->height, hourglass->x + hourglass->width, hourglass->y + hourglass->height); 
    // Top side
    drawLine(hourglass->x, hourglass->y, hourglass->x + hourglass->width, hourglass->y); 
}

void initHourglass(int x, int y, int width, int height) {
    globalHourglass.x = x;
    globalHourglass.y = y;
    globalHourglass.width = width;
    globalHourglass.height = height;
}

void setHourglassPercentage(float value) {
    // Set the percentage of the hourglass
    int newHeight = (int)(value * globalHourglass.height);    
}