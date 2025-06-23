#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void bda(int x1, int y1, int x2, int y2) {
    int maxWidth = getmaxx();
    int maxHeight = getmaxy();
    int centerX = maxWidth / 2;
    int centerY = maxHeight / 2;

    line(0, centerY, maxWidth, centerY);
    line(centerX, 0, centerX, maxHeight);

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x = x1;
    int y = y1;

    // Direction of steps
    int xinc = (x2 > x1) ? 1 : -1;
    int yinc = (y2 > y1) ? 1 : -1;

    int p;

    // Case 1 & 2: (|m| = 1)
    if (dx >= dy) {
        p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            putpixel(centerX + x, centerY - y, WHITE);

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

    // Case 3 & 4: (|m| > 1)
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
}int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2;
    cout << "Enter x1 y1 x2 y2 (relative to center): ";
    cin >> x1 >> y1 >> x2 >> y2;

    bda(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

