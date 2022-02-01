#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect* R1,Rect* R2){
	double lx;
	double x1,x2,x1max,x2max;

	if((*R1).x <= (*R2).x){
		x1 = (*R1).x;
		x2 = (*R2).x;
		x1max = (*R1).x + (*R1).w;
		x2max = (*R2).x + (*R2).w;
	}

	else{
		x1 = (*R2).x;
		x2 = (*R1).x;
		x1max = (*R2).x + (*R2).w;
		x2max = (*R1).x + (*R1).w;
	}


	if(x2 >= x1 && x2 < x1max && x2max >= x1max){
		lx = x1max - x2;
	}
	else if(x2 >= x1 && x2 < x1max && x2max < x1max){
		lx = x2max - x2;
	}
	else{
		lx = 0;
	}

	double ly;
	double y1,y2,y1min,y2min;
	
	if((*R2).y >= (*R1).y){
		y2 = (*R2).y;
		y2min = (*R2).y - (*R2).h;
		y1 = (*R1).y;
		y1min = (*R1).y - (*R1).h;
	}
	else {
		y2 = (*R1).y;
		y2min = (*R1).y - (*R1).h;
		y1 = (*R2).y;
		y1min = (*R2).y - (*R2).h;
	}

	if(y1 <= y2 && y1 > y2min && y1min <= y2min){
		ly = y1 - y2min;
	}
	else if(y1 <= y2 && y1 > y2min && y1min > y2min){
		ly = y1 - y1min;
	}
	else{
		ly = 0;
	}

	return ly*lx;



}
