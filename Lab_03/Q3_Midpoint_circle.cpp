#include <graphics.h>
#include <iostream>
using namespace std;

// Function to plot all 8 symmetric points
void plotCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void midpointCircleAlgorithm(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    
    // p0 = (5/4) - r ≈ 1 - r (as integer arithmetic)
    int p = 1 - r;

    plotCirclePoints(xc, yc, x, y);

    while (x < y) {
        x++;

        if (p < 0) {
            // Midpoint is inside the circle
            p = p + 2 * x + 1;
        } else {
            // Midpoint is outside or on the circle
            y--;
            p = p + 2 * (x - y) + 1;
        }

        plotCirclePoints(xc, yc, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, r;
    cout << "Enter center (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> r;

    midpointCircleAlgorithm(xc, yc, r);

    getch();
    closegraph();
    return 0;
}
