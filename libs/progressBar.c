#include "progressBar.h"

ProgressBar createProgressBar(int x, int y, int width, int height) {
    ProgressBar bar;
    bar.x = x;
    bar.y = y;
    bar.width = width;
    bar.height = height;
    bar.percentage = 0; // Initialize to 0%
    bar.percentageTo = 0;
    return bar;
}

void setProgressBarPercentage(ProgressBar* bar, float percentage) {
    if (percentage < 0.0f) {
        percentage = 0.0f; // Clamp to minimum
    } else if (percentage > 1.0f) {
        percentage = 1.0f; // Clamp to maximum
    }
    bar->percentageTo = percentage; // Set the percentage
}

void drawProgressBar(ProgressBar* bar) {
    // Draw the outer rectangle (border)
    drawEmptyRectangle(bar->x, bar->y, bar->width, bar->height);
    
    // Approach percentage to percentageTo
    // Interpolate percentage towards percentageTo
    bar->percentage += (bar->percentageTo - bar->percentage) * 0.1f;

    // Calculate the width of the filled part based on the percentage
    int filledWidth = (int)(bar->width * bar->percentage);
    
    // Draw the filled part of the progress bar
    drawRectangle(bar->x + 1, bar->y + 1, MAX(filledWidth - 2, 0), bar->height - 1); // Clear rectangle for filled part
}