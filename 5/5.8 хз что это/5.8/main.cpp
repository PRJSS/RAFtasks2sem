
#include "Header.h"

using namespace std;

void compare(char array[][Size], int Leftborder, int Rightborder)
{
    for (int i = 0; i < Size; i++)
    {
        int k = static_cast<int>(array[Leftborder][i]);
        int j = static_cast<int>(array[Rightborder][i]);
        if (k<j)
        {
            for (int j = 0; j < Size; j++)
            {
                swap(array[Leftborder][j], array[Rightborder][j]);
            }
            break;
        }
        
    }
}

void output(char array[][Size], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            cout  << array[i][j];
        }
        cout << endl;
    }

}

void Enter(char array[][Size], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = rand() % 25 + 65;
        }
    }
}

void merge(char array[][Size], int Leftborder, int Rightborder)
{
    if (Rightborder == Leftborder)
        return;
    if (Rightborder - Leftborder == 1)
    {
        compare(array, Leftborder, Rightborder);
    }

    int center = (Rightborder + Leftborder) / 2;
    merge(array, Leftborder, center);
    merge(array, center + 1, Rightborder);
    char buf[Size][Size];
    int xl = Leftborder;
    int xr = center + 1;
    int cur = 0;

    while (Rightborder - Leftborder + 1 != cur)
    {
        if (xl > center)
        {
            for (int i = 0; i < Size; i++)
            {
                buf[cur][i] = array[xr][i];
            }
            cur++ ;
            xr++ ;
        }
        else if (xr > Rightborder)
        {
            for (int i = 0; i < Size; i++)
            {
                buf[cur][i] = array[xl][i];
            }
            cur++; xl++;
        }
        else
        {
            for (int j = 0; j < Size; j++)
            {
                if (array[xl][j] < array[xr][j])
                {
                    for (int i = 0; i < Size; i++)
                    {
                        buf[cur][i] = array[xr][i];
                    }
                    cur++; xr++;
                    break;
                }
                else
                {
                    for (int i = 0; i < Size; i++)
                    {
                        buf[cur][i] = array[xl][i];
                    }
                    cur++; xl++;
                    break;
                }
            }
        }

    }
    for (int i = 0; i < cur; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            array[i + Leftborder][j] = buf[i][j];
        }
    }
}
