#include <iostream>
#include <graphics.h>
using namespace std;

void drawTriangle(int x1, int x2, int x3, int y1, int y2, int y3){
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
}

void drawAxes(int* x1, int* x2, int* x3, int* y1, int* y2, int* y3){
	int maxHeight = getmaxy();
	int maxWidth = getmaxx();
	int centerX = maxWidth/2;
	int centerY = maxHeight/2;
	
	line(0, centerY, maxWidth, centerY);
	line(centerX,0, centerX, maxHeight);
	*x1+=centerX;
	*x2+=centerX;
	*x3+=centerX;
	*y1=centerY-*y1;
	*y2=centerY-*y2;
	*y3=centerY-*y3;
}


int main(){
	int gd = DETECT , gm;
	initgraph(&gd, &gm, "");
	
	int x1,x2,x3,y1,y2,y3;
	int tx, ty;
	
	cout<<"input the coordinates of a triangle: "<<endl;
	cout<<"(x1,y1) ";
	cin>>x1>>y1;
	cout<<"(x2,y2) ";
	cin>>x2>>y2;	
	cout<<"(x3,y3) ";
	cin>>x3>>y3;
	
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);
	
	drawAxes(&x1,&x2,&x3,&y1,&y2,&y3);
	drawTriangle(x1,x2,x3,y1,y2,y3);
	
	//for translation
	int k = 3;
	while(k!=0){
		cout<<"enter translation vector: "<<endl;
		cout<<"tx ty --- ";
		cin>>tx>>ty;
		
		setcolor(RED);
		drawTriangle(x1+tx, x2+tx, x3+tx, y1-ty, y2-ty, y3-ty);
		k--;	
	}
		
	getch();
	closegraph();
}