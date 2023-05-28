#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void bubblesort();
void selectionsort();
int main()
{
    int l,u,N,num,i;
    float duration;
    clock_t start,end;
    FILE *fp;
    printf("\nenter range lower and upper:");
    scanf("%d%d",&l,&u);
    printf("\nenter count:");
    scanf("%d",&N);
    fp=fopen("inp.txt","w");
    if(fp==NULL)
    {
        printf("\nerror");
        exit(0);
    }
    srand(time(0));
    printf("\nThe random numbers are: ");
    for(i=0;i<N;i++)
    {
        num=(rand() % (u-l+1))+l;
        printf("\n%d",num);
        fprintf(fp,"%d ",num);
    }
    printf("\n\nNumbers have been printed in file successfully\n");
    fclose(fp);
    start=clock();
    bubblesort();
    end=clock();
    duration=(float)(end-start);
    printf("\n\n\nduration for bubble sort%f",duration);

    start=clock();
    selectionsort();
    end=clock();
    duration=(float)(end-start);
    printf("\n\n\nduration for selection sort%f",duration);
}
void bubblesort()
{
    int arr[100],i,n=0,j,temp,s=0;
    FILE *fp1,*fp2;
     fp1=fopen("inp.txt","r");
    if(fp1==NULL)
    {
        printf("\nerror");
        exit(0);
    }
     fp2=fopen("out.txt","w");
    if(fp2==NULL)
    {
        printf("\nerror");
        exit(0);
    }
    while(fscanf(fp1,"%d",&arr[s])==1)
    {
      s++;
      n++;
    }
    for(s=0;s<n;s++)
      {
          printf("\nNumbers in array:%d\t",arr[s]);
      }
       fclose(fp1);
      for(i=0;i<n-1;i++)
      {
          for(j=0;j<n-i-1;j++)
          {
              if(arr[j]>arr[j+1])
              {
                  temp=arr[j];
                  arr[j]=arr[j+1];
                  arr[j+1]=temp;
              }
          }
      }
      for(s=0;s<n;s++)
      {
          printf("\n\nsorted array%d\t",arr[s]);
          fprintf(fp2,"%d\t",arr[s]);
      }
      fclose(fp2);
}

void selectionsort()
{
    int arr[100],i,n=0,j,temp,s=0,x,r;
    FILE *fp1,*fp2;
     fp1=fopen("inp.txt","r");
    if(fp1==NULL)
    {
        printf("\nerror");
        exit(0);
    }
     fp2=fopen("out.txt","w");
    if(fp2==NULL)
    {
        printf("\nerror");
        exit(0);
    }
    while(fscanf(fp1,"%d",&arr[s])==1)
    {
      s++;
      n++;
    }
    for(s=0;s<n;s++)
      {
          printf("\nNumbers in array:%d\t",arr[s]);
      }
       fclose(fp1);
      for(i=0;i<n-1;i++)
      {
          x=arr[i];
          for(j=i+1;j<n;j++)
          {
              if(arr[j]<x)
              {
                  x=arr[j];
                  r=j;
              }
          }
          temp=arr[i];
          arr[i]=x;
          arr[r]=temp;
      }
      for(s=0;s<n;s++)
      {
          printf("\n\nsorted array%d\t",arr[s]);
          fprintf(fp2,"%d\t",arr[s]);
      }
      fclose(fp2);
}
