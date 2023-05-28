#include<stdio.h>
void main()
{
    int a[25];
    int i,j,c=0;
    printf("Enter array\n");
    for(i=0;i<25;i++)
    scanf("%d",&a[i]);
    for(i=0;i<25;i++)
    {
        for(j=0;j<25;j++)
        {
            if(a[i]==a[j])
            c++;
        }
        printf("The number %d is repeated for %d\n",a[i],c);
        c=0;
    }



}
