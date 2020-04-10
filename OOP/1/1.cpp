#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#define N 5

using namespace std;

void DiagRight(int *B, int* A[N])
{
	int k = 0;
	
	cout << "Значения матрицы по правым диагоналям: ";
	
	for (int diag = N - 1; diag >= 0; diag--) 
    {
        int x = 0; 
        int y = diag; 
 
        while (y <= N - 1) 
        {
            B[k] = A[x][y];
			cout << B[k] << " "; 
            k++;
			x++; 
            y++; 
        }
    }
 
   for (int diag = 1; diag < N; diag++)
    {
        int x = diag; 
        int y = 0;  
 
        while (x <= N - 1) 
        {
            B[k] = A[x][y];
			cout << B[k] << " "; 
            k++;
            x++; 
            y++; 
        }
    }
    cout << endl << endl;
}

void DiagLeft(int *B, int* A[N])
{
	int k = 0;
	
	cout << "Значения матрицы по левым диагоналям : ";
	
	for (int diag = 0; diag < N; diag++) 
    {
        int x = 0; 
        int y = diag; 
 
        while (y >= 0) 
        {
            B[k] = A[x][y];
			cout << B[k] << " "; 
            k++;
            x++;  
            y--; 
        }
    }
 
   for (int diag = 1; diag < N; diag++)
    {
        int x = diag; 
        int y = N - 1;  
 		
        while (x <= N - 1) 
        {
            B[k] = A[x][y];
			cout << B[k] << " "; 
            k++;
            x++; 
            y--; 
        }
    }
	cout << endl << endl;
}

void SpiralCenter(int* B, int* A[N])
{
    cout << "Значения элементов матрицы по спирали из центра : ";
    
	int i1 = N;
	int j1 = N;
	int i = 0;
	int j = 0;
	int k = 0;
	
	while(j < j1)
	{
		i = N - i1;
		j = N - j1;
		for(; j < j1; j++)
		{
			B[k] = A[i][j];
			k++;
		//	cout << " 1 "<<endl;
		}
		j--;
		for(i++; i < i1; i++)
		{
			B[k] = A[i][j];
			k++;
		//	cout << " 2 "<<endl;
		}
		i--;
		for(j--; j >= N - j1; j--)
		{
			B[k] = A[i][j];
			k++;
		//	cout << " 3 "<<endl;
		}
		j++;
		for(i--; i > N - j1; i--)
		{
			B[k] = A[i][j];
			k++;
		//	cout << " 4 "<<endl;
		}
		i++;
		i1--;
		j1--;
	}
	
	for(i = N * N - 1; i >= 0; i--)
	cout << B[i] << " ";

	cout << endl << endl;
}

void SpiralClock(int* B, int* A[N])
{
	int k = 0;
	int umax = 1;
	int lmax = 0;
    int dmax = N - 1;
    int rmax = N - 1;
    
    cout << "Значени элементов матрицы по часовой спирали : ";
    
    while (k < N * N)
    {
        for(int i = lmax; i <= rmax; i++) 
        {
	        B[k] = A[umax - 1][i];
	        cout << B[k] << " ";
	        k++;
        }
        for(int j = umax; j <= dmax; j++) 
        {
            B[k] = A[j][rmax];
            cout << B[k] << " ";
            k++;
        }
        rmax--;
        for(int i = rmax; i >= lmax; i--) 
        {
            B[k] = A[dmax][i];
            cout << B[k] << " ";
            k++;
        }
        dmax--;
        for(int j = dmax; j >= umax; j--)  
        {
            B[k] = A[j][lmax];
            cout << B[k] << " ";
            k++;
        }
        lmax++;
        umax++;
    }	
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    int** A;
    int* B;
    
    A = new int* [N];
    for(int i = 0; i < N; i++)
    A[i] = new int[N];
    
    for(int i = 0; i < N; i++)
    {
            for(int j = 0; j < N; j++)
            {
                    A[i][j] = rand() % N;
                    cout << A[i][j] << " ";
            }
            cout << endl;
    }
    cout << endl;
    
    int n = N * N;
    
    B = new int[n];
    
    DiagRight(B, A);
	DiagLeft(B, A);
	SpiralCenter(B, A);
	SpiralClock(B, A);
        
    cout << endl;
    
    getch();
    //return 0;
}
