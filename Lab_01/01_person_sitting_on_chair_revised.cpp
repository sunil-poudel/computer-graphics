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
    circle(230, 220, 15);

    // main body
    line(230, 235, 230, 280);

	// Arms (from shoulders down to sides)
    line(230, 235, 200, 250);   // left arm
    line(230, 235, 260, 250);   // right arm

    // Legs (down to floor from seat edge)
    line(230, 280, 200, 300);   // left thigh
    line(230, 280, 260, 300);   // right thigh

    // Feet (legs extended down)
    line(200, 300, 200, 340);   // left shin
    line(260, 300, 260, 340);   // right shin
    
   
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawChairWithMan();

    getch();
    closegraph();
    return 0;
}
