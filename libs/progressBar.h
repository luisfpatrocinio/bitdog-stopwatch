#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include "display.h"
#include "draw.h"
#include "math.h"

typedef struct {
    int x;                // X position of the progress bar
    int y;                // Y position of the progress bar
    int width;           // Width of the progress bar
    int height;          // Height of the progress bar
    float percentage;     // Percentage of completion (0.0 to 1.0)
    float percentageTo; // Percentage to animate to (0.0 to 1.0)
} ProgressBar;

ProgressBar createProgressBar(int x, int y, int width, int height);
void setProgressBarPercentage(ProgressBar* bar, float percentage);
void drawProgressBar(ProgressBar* bar);

#endif // PROGRESS_BAR_H