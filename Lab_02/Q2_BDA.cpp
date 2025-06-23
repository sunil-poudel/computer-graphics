#include <iostream>
#include <graphics.h>

using namespace std;

void bda(int x1, int y1, int x2, int  y2){
	int maxHeight = getmaxy();
	int maxWidth = getmaxx();
	
	int centerHeight = maxHeight/2;
	int centerWidth = maxWidth/2;
	
	line(0, centerHeight, maxWidth, centerHeight);
	line(centerWidth, 0, centerWidth, maxHeight);
	
	int dx = x2 - x1, dy = y2 - y1;
	
	int decisionParameter = 2*dy - dx;
	
	int x = x1+centerWidth, y = y1+centerHeight;
	
	float m = dy/dx;
	
	for(int i = x1; i<= x2; i++){
		putpixel(x, y, WHITE);
		
		if(decisionParameter<0){
			x++;
			decisionParameter += 2*dy;
		} else{
			x++;
			y++;
			decisionParameter += (2*dy)-(2*dx);
		}
		delay(10);  
		
	}
}
int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int x1, y1, x2, y2;
	
	cout<<"enter the points: for (x1, y1) to (x2, y2)"<<endl;
	cout<<"x1 -> ";
	cin>>x1;
	cout<<"y1 -> ";
	cin>>y1;
	cout<<"x2 -> ";
	cin>>x2;
	cout<<"y2 -> ";
	cin>>y2;
	
	bda(x1, y1, x2, y2);
	getch();
	closegraph();
	
}