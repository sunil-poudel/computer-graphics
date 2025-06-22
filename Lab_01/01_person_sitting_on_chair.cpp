#include <iostream>
#include <graphics.h>

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);\
	setbkcolor(WHITE);
	cleardevice();
	
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLUE);
	// Chair
	line(10, 200, 10, 300);
	line(10, 200, 150, 200);
	line(150, 10, 150, 300);
	
	setcolor(BROWN);
	//	man
	circle(75, 70, 30);
	line(75, 100, 75, 150);
	line(75, 150, 45, 200);
	line(75, 150, 105, 200);
	line(75, 105, 45, 150);
	line(75, 105, 105, 150);
	
	setcolor(BLACK);
	//eyes
	circle(65, 65, 5);
	circle(85, 65, 5);
	circle(65, 65, 1);
	circle(85, 65, 1);

	setcolor(BROWN);
	//nose
	circle(75, 80, 1);
	
	//mouth
	line(65, 90, 85, 90);
	
	getch();
    closegraph();
}

floodfill(x, y, BLUE);