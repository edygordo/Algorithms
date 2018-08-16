#include<iostream>
#include<utility>
using namespace std;

int Max_weight=7;
int items;
int Value[4][8];

pair<int,int> myItems[items]; // value , weight

void initialise()
{
    for(int i=0;i<items;i++)
    {
        for(int j=0;j<Max_weight;j++)
        {
            Value[i][j] = 0;
        }
    }
}

int knapsack()
{
    for(int i=0;i<items;i++)
    {
        for(int j=1;j<=Max_weight;j++)
        {
            if(i-1 < 0) //first item
            {
                if(myItems[i].second <= j)
                {
                    Value[i][j] = myItems[i].first;
                }
            }
            else
            {
                if(myItems[i].second <= j) // can include or exclude
                {
                    int If_Picked_val = myItems[i].first + Value[i-1][j-myItems[i].second];
                    Value[i][j] = max(If_Picked_val,Value[i-1][j]);
                }
            }
        }
    }
    return Value[items-1][Max_weight];
}

int main()
{
    Max_weight = 7;
    items = 4;
    myItems[0] = make_pair(1,1);
    myItems[1] = make_pair(4,3);
    myItems[2] = make_pair(5,4);
    myItems[3] = make_pair(7,5);
    cout<<knapsack();
    return 0;
}
