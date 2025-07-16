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
	
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);
	
	drawAxes(&x1,&x2,&x3,&y1,&y2,&y3);
	drawTriangle(x1,x2,x3,y1,y2,y3);
	
	//for translation
	while(k!=0){
		cout<<"enter translation vector: "<<endl;
		cout<<"tx ty --- ";
		cin>>tx>>ty;
		
		setcolor(RED);
		drawTriangle(x1+tx, x2+tx, x3+tx, y1-ty, y2-ty, y3-ty);
		k--;	
	}
	
	
	//for scaling
	cout<<"press any key then enter to start scaling: ";
	char c;
	cin>>c;
	setbkcolor(LIGHTBLUE);
	cleardevice();
	setcolor(WHITE);
	
	drawAxes(&x1,&x2,&x3,&y1,&y2,&y3);
	drawTriangle(x1,x2,x3,y1,y2,y3);
	
	cout<<"-----------------------------"<<endl;
	
	k=3;
	
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

//	//for rotating
	k=3;
	cout<<"press any key then enter to start rotating: ";
	cin>>c;
	setbkcolor(BROWN);
	cleardevice();
	setcolor(WHITE);
	
	drawAxes(&x1,&x2,&x3,&y1,&y2,&y3);
	drawTriangle(x1,x2,x3,y1,y2,y3);
	
	float thetaDegrees;
	
	while(k!=0){
		cout<<"-----------------------------"<<endl;
	cout<<"enter the angle to rotate in degrees: "<<endl;
	cout<<"angle -- ";
	cin>>thetaDegrees;
	

	
	float thetaRadian = thetaDegrees * (M_PI / 180.0);
	float xr1, xr2, xr3, yr1, yr2, yr3;
	xr1 = centerX + (x1-centerX) * cos(thetaRadian) - (y1-centerY) * sin(thetaRadian);
	xr2 = centerX + (x2-centerX) * cos(thetaRadian) - (y2-centerY) * sin(thetaRadian);
	xr3 = centerX + (x3-centerX) * cos(thetaRadian) - (y3-centerY) * sin(thetaRadian);
	yr1 = centerY + (x1-centerX) * sin(thetaRadian) + (y1-centerY) * cos(thetaRadian);
	yr2 = centerY + (x2-centerX) * sin(thetaRadian) + (y2-centerY) * cos(thetaRadian);
	yr3 = centerY + (x3-centerX) * sin(thetaRadian) + (y3-centerY) * cos(thetaRadian);
	
	setcolor(randomColor());
	drawTriangle(xr1, xr2, xr3, yr1, yr2, yr3);
	
	
	k--;
	}

	//for shearing
	k=3;
	cout<<"press any key then enter to start shearing: ";
	cin>>c;
	setbkcolor(BROWN);
	cleardevice();
	setcolor(WHITE);
	
	drawAxes(&x1,&x2,&x3,&y1,&y2,&y3);
	drawTriangle(x1,x2,x3,y1,y2,y3);
	
	float shx, shy;
	while(k!=0){
		cout<<"enter value of shx and shy: "<<endl;
		cout<<"shx shy -- ";
		cin>>shx>>shy;
		
		float xsh1, xsh2, xsh3, ysh1, ysh2, ysh3;
		xsh1 = x1 + shx*(centerY-y1);
		ysh1 = y1 + shy*(x1-centerX);
		xsh2 = x2 + shx*(centerY-y2);
		ysh2 = y2 + shy*(x2-centerX);
		xsh3 = x3 + shx*(centerY-y3);
		ysh3 = y3 + shy*(x3-centerX);
		setcolor(randomColor());
		drawTriangle(xsh1, xsh2, xsh3, ysh1, ysh2, ysh3);
		k--;
	}
	getch();
	closegraph();                                 
}