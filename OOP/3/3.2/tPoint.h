#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <graphics.h>
#define ScreenHeight 800
#define ScreenWeight 600

using namespace std;

class tPoint
{
	private:
		int x_point;
		int y_point;
		int dx_point;
		int dy_point;
		int color;	
	public:
		tPoint()
		{
			x_point = rand() % ScreenHeight;
			y_point = rand() % ScreenWeight;
			color = rand() % 15 + 1;    
            dy_point = 0;
            dx_point = 0;
		}
		void printPoint()
		{	
			setcolor(color);
			circle(x_point, y_point, 4);
		}
		void deletePoint()
		{	
			setcolor(0);
			circle(x_point, y_point, 4);
		}
		void Move()
		{   
			deletePoint(); 
            x_point += dx_point;
			y_point += dy_point;
			printPoint(); 
			if(x_point >= ScreenHeight)
			dx_point--;
			if(x_point < 0)
			dx_point++;
			if(y_point >= ScreenWeight)
			dy_point--;
			if(y_point < 0)
			dy_point++;
        } 
		void LineMove()
		{
			dx_point = rand() % 11 - 5;	
			if(dx_point == 0)
			{
				dx_point++;	
			}		
			dy_point = 0;
		}
		void RandMove()
		{
			dx_point = rand()% 11 - 5;
			if(dx_point == 0)
			{
				dx_point++;	
			}
			dy_point = rand()% 11 - 5;
			if(dy_point == 0)
			{
				dy_point++;	
			}	
		}
};
/*if (y_point >= ScreenHeight) dy_point -= (2 * dy_point);
			if (y_point <=0 ) dy_point -=(2*dy_point) ;
			if (x_point >= ScreenWeight) dx_point -= (2 * dx_point);
			if (x_point <= 0) dx_point -= (2 * dx_point);*/
