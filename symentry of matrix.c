#include<stdio.h>
void main()
{
    int a[100][100],n;
    int i,j,key=1;
    printf("Enter size of matrix\n");
    scanf("%d",&n);
    printf("Enter the matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
        if (a[i][j]!=a[j][i])
        {
          key=0;
        }
    }
    }
    if(key==1)
    printf("The given matrix is symmetric\n");
    else
    printf("The given matrix is not symmetric\n");

}
