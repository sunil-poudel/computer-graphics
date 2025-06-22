// Program to draw multiple circles with decreasing radii using graphics.h in C++
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 200, yc = 300;
    int radii[] = {100, 90, 70};

    for (int i = 0; i < 3; i++) {
        circle(xc, yc, radii[i]);
    }

    getch();
    closegraph();
    return 0;
}
