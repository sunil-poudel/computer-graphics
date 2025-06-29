#include <graphics.h>
#include <iostream>
using namespace std;

void drawEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void midpointEllipse(int xc, int yc, int rx, int ry) {
    float dx, dy, p1, p2;
    int x = 0;
    int y = ry;

    // Initial decision parameter for region 1
    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // Region 1
    while (dx < dy) {
        drawEllipsePoints(xc, yc, x, y);
        x++;
        dx = dx + (2 * ry * ry);
        if (p1 < 0) {
            p1 = p1 + dx + (ry * ry);
        } else {
            y--;
            dy = dy - (2 * rx * rx);
            p1 = p1 + dx - dy + (ry * ry);
        }
    }

    // Initial decision parameter for region 2
    p2 = (ry * ry) * ((x + 0.5) * (x + 0.5)) + 
         (rx * rx) * ((y - 1) * (y - 1)) - 
         (rx * rx * ry * ry);

    // Region 2
    while (y >= 0) {
        drawEllipsePoints(xc, yc, x, y);
        y--;
        dy = dy - (2 * rx * rx);
        if (p2 > 0) {
            p2 = p2 + (rx * rx) - dy;
        } else {
            x++;
            dx = dx + (2 * ry * ry);
            p2 = p2 + dx - dy + (rx * rx);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, rx, ry;
    cout << "Enter center (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radii (rx ry): ";
    cin >> rx >> ry;

    midpointEllipse(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}
