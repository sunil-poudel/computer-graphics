#include<graphics.h>

int main(){

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    circle(200, 200, 100);

    // Wait for a key press
    getch();

    // Close the graphics window
    closegraph();
    return 0;
}