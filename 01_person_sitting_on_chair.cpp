#include <iostream>
#include <graphics.h>

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	// Chair
	line(10, 200, 10, 300);
	line(10, 200, 150, 200);
	line(150, 10, 150, 300);
}