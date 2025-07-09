#include <iostream>
#include <graphics.h>
using namespace std;

int main(){
	int gd = DETECT , gm;
	initgraph(&gd, &gm, "");
	
	int x1,x2,x3,y1,y2,y3;
	
	cout<<"input the coordinates of a triangle: "<<endl;
	cout<<"(x1,y1) ";
	cin>>x1>>y1;
	cout<<"(x2,y2) ";
	cin>>x2>>y2;	
	cout<<"(x3,y3) ";
	cin>>x3>>x3;
	
	
	getch();
	closegraph();
}