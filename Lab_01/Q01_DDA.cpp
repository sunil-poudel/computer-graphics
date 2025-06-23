#include <iostream>
#include <cmath>
#include <graphics.h>

using namespace std;

void drawLineDDA(int x1, int y1, int x2, int y2, int maxHeight, int maxWidth) {
    float x_inc, y_inc, x, y, steps;
    int dx = x2 - x1;
    int dy = y2 - y1;
	
    // Determine number of steps based on max delta
    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    // Calculate incremental values
    x_inc = dx / steps;
    y_inc = dy / steps;

    // Initialize starting position
    x = x1;
    y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y += y_inc;
        delay(10); // Optional delay to visualize
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
