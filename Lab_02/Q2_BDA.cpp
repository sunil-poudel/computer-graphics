#include <iostream>
#include <graphics.h>

using namespace std;

void bda(int x1, int y1, int x2, int  y2){
	int maxHeight = getmaxy();
	int maxWidth = getmaxx();
	
	int centerHeight = maxHeight/2;
	int centerWidth = maxWidth/2;
	
	line(0, centerHeight, maxWidth, centerHeight);
}
int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	bda(0,0,100,100);
	getch();
	closegraph();
	
}