#include <graphics.h>
#include <conio.h>

void drawChairWithMan() {
    // Chair seat (parallelogram)
    line(200, 300, 300, 300);     // front edge
    line(200, 300, 180, 270);     // left edge
    line(300, 300, 280, 270);     // right edge
    line(180, 270, 280, 270);     // back edge

    
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawChairWithMan();

    getch();
    closegraph();
    return 0;
}
