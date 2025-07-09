#include <iostream>
#include <cstdlib>
#include <ctime>
#include <graphics.h>
#include <cmath>

using namespace std;

int randomColor(){
		srand(time(0));
		return rand() % 6 + 0;
}

void drawTriangle(float x1, float x2, float x3, float y1, float y2, float y3){
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
}

void drawAxes(float* x1, float* x2, float* x3, float* y1, float* y2, float* y3){
	float maxHeight = getmaxy();
	float maxWidth = getmaxx();
	float centerX = maxWidth/2;
	float centerY = maxHeight/2;
	
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
	
	int k = 3;
	float x1,x2,x3,y1,y2,y3;
	float tx, ty;
	
	float maxHeight = getmaxy();
	float maxWidth = getmaxx();
	float centerX = maxWidth/2;
	float centerY = maxHeight/2;

	setlinestyle(SOLID_LINE, 0, 3);
	
	cout<<"input the coordinates of a triangle: "<<endl;
	cout<<"(x1,y1) ";
	cin>>x1>>y1;
	cout<<"(x2,y2) ";
	cin>>x2>>y2;	
	cout<<"(x3,y3) ";
	cin>>x3>>y3;
	
	setbkcolor(LIGHTBLUE);
	cleardevice();
	setcolor(WHITE);

	drawAxes(&x1,&x2,&x3,&y1,&y2,&y3);
	drawTriangle(x1,x2,x3,y1,y2,y3);

	while(k!=0){
		cout<<"enter the scale:"<<endl;
		cout<<"Sx Sy --- ";
		float sx, sy;
		cin>>sx>>sy;
		float xs1, xs2, xs3, ys1, ys2, ys3;
		xs1=x1*sx+x1 * (1 - sx);
		xs2=x2*sx+x1 * (1 - sx);
		xs3=x3*sx+x1 * (1 - sx);
		ys1=y1*sy+y1 * (1 - sy);
		ys2=y2*sy+y1 * (1 - sy);
		ys3=y3*sy+y1 * (1 - sy);
		

		setcolor(randomColor());
		setlinestyle(SOLID_LINE, 0, 3);
		drawTriangle(xs1, xs2, xs3, ys1, ys2, ys3);
		
		k--;
	}

	getch();
	closegraph();                                 
}