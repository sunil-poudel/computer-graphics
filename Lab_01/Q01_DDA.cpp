#include <iostream>
#include <cmath>
#include <graphics.h>

using namespace std;

void drawLineDDA(int x1, int y1, int x2, int y2, int maxHeight, int maxWidth) {
    float x_inc, y_inc, x, y, steps;
    int dx = x2 - x1;
    int dy = y2 - y1;

    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    x_inc = dx / steps;
    y_inc = dy / steps;

    // Adjust for screen center and invert Y-axis
    x = x1 + maxWidth / 2;
    y = maxHeight / 2 - y1;  // subtract instead of add

    for (int i = 0; i <= steps; i++) {
        if (x >= 0 && x < maxWidth && y >= 0 && y < maxHeight)
            putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y -= y_inc;  // invert y-axis by subtracting
        delay(10);
    }
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    
    int maxWidth = getmaxx();
    int maxHeight = getmaxy();
	line(maxWidth/2, 0, maxWidth/2, maxHeight);
	line(0, maxHeight/2, maxWidth, maxHeight/2);

    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point (x2 y2): ";
    cin >> x2 >> y2;

    drawLineDDA(x1, y1, x2, y2, maxHeight, maxWidth);
    
	
    getch();
    closegraph();
    return 0;
}
