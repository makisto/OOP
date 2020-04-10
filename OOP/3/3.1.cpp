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
			square(x_point, y_point, 10);
		}
		void deletePoint()
		{	
			setcolor(0);
			circle(x_point, y_point, 10);
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

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	
	tPoint* l;
	l = new tPoint[100];
    		
	char Choose;
	while(1)
	{
		system("CLS");
		cout <<"Choose the moving:\n";
		cout <<"0.Points on window\n";
		cout <<"1.Line\n";
		cout <<"2.Rand\n";
		cout <<"3.Exit\n";
		cin >> Choose;
		switch(Choose)
		{
			case '0':
				initwindow(ScreenHeight, ScreenWeight); 
				for(int i = 0; i < 100; i++) 
				{
					l[i].printPoint();
				}
				getch();
				closegraph(); 
				break;
			case '1':
                for(int i = 0; i < 100; i++) 
                {
		            l[i].LineMove();
                }
				initwindow(ScreenHeight, ScreenWeight);
				while(1)
			    {
				    if (kbhit()) 
               			if (getch() == 27 )
                        {  
                    	   break;
                        }
                    for(int i = 0; i < 100; i++)
                    {
        				l[i].Move();
                    }
                }
                getch();
   				closegraph(); 
   				break;
			case '2':
                for(int i = 0; i < 100; i++) 
                {
		            l[i].RandMove();
                }
				initwindow(ScreenHeight, ScreenWeight);
			    while(1)
			    {
				    if ( kbhit() ) 
               			if ( getch() == 27 ) 
                        {
                    		break;
                        }
                    for(int i = 0; i < 100; i++)
                    {
        				l[i].Move();
                    }
                }
                getch();
				closegraph(); 
				break;
			case '3':
				exit(0);
			default:
				break;	
		}
	}
	
	return 0;
}
