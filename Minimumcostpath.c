#include<stdlib.h>
#include<stdio.h>
int min(int x,int y)
{
 return x<y?x:y;
}
void main()
{
 int cm[3][3] = { {1,2,3},
                {4,5,6},
                {7,8,9}
              };
 int p[3][3];
 
 p[0][0] = cm[0][0];
 
 for(int j=1;j<3;j++)
 p[0][j] = p[0][j-1] + cm[0][j];

 for(int i=1;i<3;i++)
 p[i][0] = p[i-1][0] + cm[i][0];

 for(int i=1;i<3;i++)
   for(int j=1;j<3;j++)
    p[i][j] = min(p[i-1][j],p[i][j-1]) + cm[i][j];

 for(int i=0;i<3;i++)
 {for(int j=0;j<3;j++)
  printf("%d ",p[i][j]);
  printf("\n");
 }
}
