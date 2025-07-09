#include <iostream>
#include <graphics.h>
using namespace std;

void drawTriangle(int x1, int x2, int x3, int y1, int y2, int y3){
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
}

void drawAxes(){
	int maxHeight = getmaxy();
	int maxWidth = getmaxx();
	int centerX = maxWidth/2;
	int centerY = maxHeight/2;
	line(0, centerY, maxWidth, centerY);
	line(centerX,0, centerX, maxHeight);
}

int main(){
	int gd = DETECT , gm;
	initgraph(&gd, &gm, "");
	drawAxes();
	
	int x1,x2,x3,y1,y2,y3;
	
	cout<<"input the coordinates of a triangle: "<<endl;
	cout<<"(x1,y1) ";
	cin>>x1>>y1;
	cout<<"(x2,y2) ";
	cin>>x2>>y2;	
	cout<<"(x3,y3) ";
	cin>>x3>>x3;
	
	drawTriangle(x1,x2,x3,y1,y2,y3);
	
	getch();
	closegraph();
}