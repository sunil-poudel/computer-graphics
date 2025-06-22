#include <iostream>
#include <graphics.h>

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	// Chair
	line(10, 200, 10, 300);
	line(10, 200, 150, 200);
	line(150, 10, 150, 300);
	
	//	man
	circle(75, 70, 30);
	line(75, 100, 75, 150);
	line(75, 150, 45, 200);
	line(75, 150, 105, 200);
	line(75, 105, 45, 150);
	line(75, 105, 105, 150);
	
	getch();
    closegraph();
}