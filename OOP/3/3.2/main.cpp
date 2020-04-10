#include "tPoint.h"

using namespace std;

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
