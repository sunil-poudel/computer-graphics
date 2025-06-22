#include <iostream>
#include <graphics.h>

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	// Chair
	line(110, 200, 110, 300);
	line(110, 200, 250, 200);
	line(250, 10, 250, 300);
	
	//	man
	circle(175, 70, 30);
	line(175, 100, 175, 150);
	line(175, 150, 145, 200);
	line(175, 150, 205, 200);
	line(175, 105, 145, 150);
	line(175, 105, 205, 150);
	
	//eyes
	circle(165, 65, 5);
	circle(185, 65, 5);
	circle(165, 65, 1);
	circle(185, 65, 1);

	
	//nose
	circle(175, 80, 1);
	
	//mouth
	line(165, 90, 185, 90);
	
	getch();
    closegraph();
}