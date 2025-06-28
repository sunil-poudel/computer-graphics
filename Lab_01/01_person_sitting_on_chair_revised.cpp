#include <iostream>
#include <graphics.h>

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	//chair's upper section
	rectangle(100, 100,200 , 200);
	
	
	
	getch();
	closegraph();
}