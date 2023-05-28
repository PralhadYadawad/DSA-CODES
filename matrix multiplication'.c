#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void readm(int *r1,int *c1,int a[][10]);
void matr(int *r1,int *c1,int a[][10]);
void mult(int *r1,int *c1,int *r2,int *c2,int a[][10],int b[][10],int c[][10]);
void main()
{
    int a[10][10],b[10][10],c[10][10];
    int r1,c1,r2,c2;
    printf(" enter order of 1st matrix\n");
    scanf("%d\t%d",&r1,&c1);
    if(r1<1||c1<1||r1>10||c1>10)
    {
        printf("invalid order of 1st matrix");
        exit(0);
    }
    printf("enter 1st matrix \n");
    readm(&r1,&c1,a);
    printf(" enter order of 2nd matrix\n");
    scanf("%d\t%d",&r2,&c2);
    if(r2<1||c2<1||r2>10||c2>10)
    {
        printf("invalid order of 1st matrix");
        exit(0);
    }
    printf("enter 2nd matrix \n");
    readm(&r2,&c2,b);
    printf(" the 1st matrix is:\n");
    matr(&r1,&c1,a);
    printf(" the 2nd matrix is:\n");
    matr(&r2,&c2,b);
    mult(&r1,&c1,&r2,&c2,a,b,c);
    printf(" multiplied matrix is:\n");
    matr(&r1,&c2,c);
    return;
}
void readm(int *r1,int *c1,int a[][10])
{
    int i,j;
    for(i=0;i<*r1;i++)
    {
        for(j=0;j<*c1;j++)
        {
            scanf("%d",(*(a+i)+j));
        }
    }
    return;
}
void matr(int *r1,int *c1,int a[][10])
{
    int i,j;
    for(i=0;i<*r1;i++)
    {
        printf("\n");
        for(j=0;j<*c1;j++)
        {
            printf("%d\t",((a+i)+j));
        }
    }
    printf("\n");
    return;
}
void mult(int *r1,int *c1,int *r2,int *c2,int a[][10],int b[][10],int c[][10])
{
    int i,j,k;
    if(*c1!=*r2)
    {
        printf(" order not compatible to find product\n");
        exit(0);
    }
    for(i=0;i<*r1;i++)
    {
        for(j=0;j<*c2;j++)
        {
            c[i][j]=0;
            for(k=0;k<*c2;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    return;
}
