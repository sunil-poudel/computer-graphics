#include <graphics.h>
#include <conio.h>

void drawChairWithMan() {
    // Chair seat (parallelogram)
    line(200, 300, 300, 300);     // front edge
    line(200, 300, 180, 270);     // left edge
    line(300, 300, 280, 270);     // right edge
    line(180, 270, 280, 270);     // back edge

    // Chair legs (verticals)
    line(200, 300, 200, 350);     // front-left
    line(300, 300, 300, 350);     // front-right
    line(180, 270, 180, 320);     // back-left
    line(280, 270, 280, 320);     // back-right

    // Chair backrest (upright rectangle)
    line(180, 270, 180, 200);
    line(280, 270, 280, 200);
    line(180, 200, 280, 200);

	 // Head
    circle(240, 220, 15);

    // main body
    line(240, 235, 240, 280);

	// Arms (from shoulders down to sides)
    line(240, 235, 210, 250);   // left arm
    line(240, 235, 270, 250);   // right arm

    // Legs (down to floor from seat edge)
    line(240, 280, 210, 300);   // left thigh
    line(240, 280, 270, 300);   // right thigh

    // Feet (legs extended down)
    line(210, 300, 210, 330);   // left shin
    line(270, 300, 270, 330);   // right shin
    
   
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawChairWithMan();

    getch();
    closegraph();
    return 0;
}
