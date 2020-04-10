#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int rows = 0;
    
    cout << "¬ведите количество строк: ";
    cin >> rows;
    
    int **A = new int *[rows];
    
    for(int i = 0; i < rows; i++)
    {
            int m = rand()% 10 + 1;
            A[i] = new int[m];
            
            for(int j = 0; j < m; j++)
            {
                    A[i][j] = rand() % 10;
                    cout << A[i][j] << " ";
            }
            cout << endl;
    }
    
    for(int i = 0; i < rows; i++)
    delete[]A[i];
    
    getch();
    //return 0;
}
