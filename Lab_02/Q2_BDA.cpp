#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void bda(int x1, int y1, int x2, int y2) {
    int maxWidth = getmaxx();
    int maxHeight = getmaxy();
    int centerX = maxWidth / 2;
    int centerY = maxHeight / 2;

    // Draw axes
    line(0, centerY, maxWidth, centerY);
    line(centerX, 0, centerX, maxHeight);

    // Transform logical coordinates (centered) to screen coordinates
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x = x1;
    int y = y1;

    // Direction of steps
    int xinc = (x2 > x1) ? 1 : -1;
    int yinc = (y2 > y1) ? 1 : -1;

    // Decision parameter
    int p;

    // Case 1 & 2: gentle slope (|m| = 1)
    if (dx >= dy) {
        p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            putpixel(centerX + x, centerY - y, WHITE); // plot relative to center

            if (p < 0) {
                x += xinc;
                p += 2 * dy;
            } else {
                x += xinc;
                y += yinc;
                p += 2 * dy - 2 * dx;
            }
            delay(5);
        }
    }

    // Case 3 & 4: steep slope (|m| > 1)
    else {
        p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) {
            putpixel(centerX + x, centerY - y, WHITE);

            if (p < 0) {
                y += yinc;
                p += 2 * dx;
            } else {
                x += xinc;
                y += yinc;
                p += 2 * dx - 2 * dy;
            }
            delay(5);
        }
    }
}
