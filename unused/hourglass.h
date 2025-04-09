#ifndef HOURGLASS_H
#define HOURGLASS_H

#include <stdlib.h>
#include "draw.h"

typedef struct {
    int x;                // X position of the hourglass
    int y;                // Y position of the hourglass
    int width;           // Width of the hourglass
    int height;          // Height of the hourglass
} Hourglass;

typedef struct {
    int x;
    int y;
    int vx; // velocidade x
    int vy; // velocidade y
    int active;
} SandPixel;

extern Hourglass globalHourglass;

SandPixel createSandPixel();
void resetSandPixel(SandPixel* pixel);
void updateSandPixel(SandPixel* pixel);
void initSandPixels();
void drawHourglass(Hourglass* hourglass);
void initHourglass(int x, int y, int width, int height);
void setHourglassPercentage(float value);


#endif // HOURGLASS_H