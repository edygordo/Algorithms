#include<iostream>
using namespace std;
#define BS 24
int Board[BS+1][BS+1];
int Count=0;

bool isSafe(int i,int j)
{
    int row=i,col=j;
    while(row>=1 && col>=1)
    {
        if(Board[row][col] == 1)
            return false;
        row--; col--;
    }
    row=i;col=j;
    while(row<=BS && col <=BS)
    {
        if(Board[row][col] == 1)
            return false;
        row++;col++;
    }
    row=i;col=j;
    while(row>=1 && col<=BS)
    {
        if(Board[row][col] == 1)
            return false;
        row--;col++;
    }
    row=i;col=j;
    while(row<=BS && col >=1)
    {
        if(Board[row][col] == 1)
            return false;
        row++;col--;
    }

    row=i;col=j;
    while(row>=1)
    {
        if(Board[row][col] == 1)
            return false;
        row--;
    }
    row=i;col=j;
    while(row<=BS)
    {
        if(Board[row][col] == 1)
            return false;
        row++;
    }
    row=i;col=j;
    while(col>=1)
    {
        if(Board[row][col] == 1)
            return false;
        col--;
    }
    row=i;col=j;
    while(col<=BS)
    {
        if(Board[row][col] == 1)
            return false;
        col++;
    }

    return true;
}

void no_of_paths(int row)
{
    if(row == BS+1)
        {Count++;
         return;}
    for(int k=1;k<=BS;k++)
    {
    if(isSafe(row,k))
    {
        Board[row][k] = 1; // PLACED
        no_of_paths(row+1);
        Board[row][k] = 0; // Remove
    }
    }
}
int main()
{
    //Set Board unoccupied

    for(int i=1;i<=BS;i++)
        for(int j=1;j<=BS;j++)
        Board[i][j] = 0;
    no_of_paths(1);
    cout<<Count;
    return 0;
}
