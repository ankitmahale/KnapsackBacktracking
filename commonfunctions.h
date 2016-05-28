#ifndef BRUTEFORCE_H_INCLUDED
#define BRUTEFORCE_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int size=0,capacity=0;
int lastProfit=-1,finalWeight=0;
float s=0.0;
int readfile(int *weight,int *profit,FILE *fp)
{
    int size=0,linesCount=2;

    const char string[2] = ", ";
    char *token;
    int i=0;
    if(fp != NULL)
    {
        char line[50];
        fgets(line, sizeof line, fp);
        token = strtok(line, string);
        size=atoi(token);

        int check=0;
        token = strtok(NULL,string);

        while(fgets(line, sizeof line, fp) != NULL && linesCount--!=0)
        {
            if(check==0)
            {
                token = strtok(line, string);
                for(i=0;i<size;i++)
                {

                        weight[i]=atoi(token);
                        token = strtok(NULL,string);

                }
                if(i==size)
                    check=1;
            }
            else
            {
                token = strtok(line, string);
                for(i=0;i<size;i++)
                {

                        profit[i]=atoi(token);
                        token = strtok(NULL,string);

                }
                if(i==size)
                    check=0;
            }


        }
        fgets(line, sizeof line, fp);
        token = strtok(line, string);
        capacity=atoi(token);

        token = strtok(NULL,string);

        fclose(fp);

    }
/*printf("%d\n",size);
printf("%d\t",profit[0]);
printf("%d\t",profit[1]);
printf("%d\t",profit[2]);
printf("%d\n",profit[3]);
printf("%d\t",weight[0]);
printf("%d\t",weight[1]);
printf("%d\t",weight[2]);
printf("%d\n",weight[3]);
printf("%d\t",capacity);*/
/*size=4;
capacity=16;
profit[0]=40;
profit[1]=30;
profit[2]=50;
profit[3]=10;
weight[0]=2;
weight[1]=5;
weight[2]=10;
weight[3]=5;*/
return size;
}

void print(int *weight,int *profit,int *selected,FILE *Output)
{
int i=0;
int w1=0;



for(i=0;i<size;i++)
   if(selected[i]==1)
   {
   s += profit[i] * selected[i];
   w1 +=weight[i];
   }
   fprintf(Output,"\n%d \n%.0f\n",w1,s);
   for(i=0;i<size;i++)
   if(selected[i]==1)
   {
   fprintf(Output,"%d, ",i);
   }
}





void part_sort(float temp10,int *unit,int *weight,int *profit,int i,int j,int temp8,int temp9)
{
    int tempx=0;
    int tempy=0,iter=0;
    if(unit[i]  < unit[j])
         {

         temp8 = profit[i];
         profit[i] = profit[j];
         profit[j] = temp8;
         iter=0;
        while(iter<j)
        {  j++;
           tempx = profit[j];
            tempy= temp8;
        }
         temp9 = weight[i];
         weight[i] = weight[j];
         weight[j] =temp9;
         iter=0;
        while(iter<j)
        {  j++;
           tempx= unit[j];
         tempy = temp10;
        }
         temp10 = unit[i];
         unit[i] = unit[j];
         unit[j] = temp10;

         }
}



/*Arrange the item based on high profit per Unit*/
void sort(int * weight,int *profit,int *unit)
{
    int i=0,j=0;
int temp8=0,temp9=0;
float temp10;

i=0;
while(i<size-1)
   {
   for(j=i+1;j<size;j++)
      {
         part_sort(temp10,unit,weight,profit,i,j,temp8,temp9);
      }
      i++;
    }
}

float bound(float costProfit,float costWeight,int k,int *weight,int *profit)
{
    int i,tempx,tempy,iter;
float temp4 = costProfit;
float nomi;
i=k;
float temp5 = costWeight;
float denomi;
while(i<=size)
{

    i++;
}
i=k;
while(i<=size)
{
   temp5 = temp5+weight[i];
   if( capacity<=temp5)
   {


       nomi=(temp5-capacity)/ (float)weight[i];
       denomi=1-nomi;
        while(iter<k)
        {  iter++;
           tempx=nomi;
           tempy=denomi;

        }
       return (denomi*profit[i])+temp4;
   }
   else
        temp4+=profit[i];

i++;
}
return temp4;
}

void knapsack(int *weight,int *profit,int *selected,int *temp,int k,float costProfit,float costWeight)
{
    int j=0,i=0,temp2=0,temp3=0,iter=0,tempx=0,tempy=0;
    int temp1=0;
    while(i<=size)
{

    i++;
}
i=size;
 while(iter<k)
        {  iter++;
           tempx=costWeight;
           tempy=costProfit;

        }
 if(costWeight+weight[k] <= capacity)
   {
   temp[k] = 1;
   temp2=size;

   if(k <= size)
      knapsack(weight,profit,selected,temp,k+1,costProfit+profit[k],costWeight+weight[k]);
     if(lastProfit<(profit[k]+costProfit))
      {
          temp2=costWeight+weight[k];
          temp3=costProfit+profit[k];
           while(iter<k)
        {  iter++;
           tempx=costWeight;
           tempy=costProfit;

        }
        if( k == size)
              {
              finalWeight = costWeight+weight[k];
              lastProfit = costProfit+profit[k];
              temp2++;
              temp3++;

              j=0;
                       while(iter<k)
                {  iter++;
                   tempx=costWeight;
                   tempy=costProfit;

                }
              while(k>=j)
              {
                   temp1 = temp[j];
                   selected[j]=temp1;
                   j++;
               }
               i=j;
               i++;
              }
              i=selected[j];
               while(iter<k)
        {  iter++;
           tempx=costWeight;
           tempy=costProfit;

        }
      }
    }
    if(bound(costProfit,costWeight,k,weight,profit) >= lastProfit)
    {
     temp[k] = 0;
     if( k <= size)
     knapsack(weight,profit,selected,temp,k+1,costProfit,costWeight);
     if((k == size))
     {
         if((costProfit > lastProfit) )
           {
           lastProfit = costProfit;
           finalWeight = costWeight;

           j=0;
           while(j<=k)
           {
               temp1 = temp[j];
               selected[j]=temp1;
               j++;
           }
           }
     }
    }
}
int doOperation(FILE *fp,FILE *Output)
{
int i=0,j=0;
    int weight[20]={0},profit[20]={0};
    int selected[20]={0},temp[20]={0};
    float unit[20]={0};

size=readfile(&weight,&profit,fp);


for(i=0;i<size;i++)
unit[i] = (float) profit[i] / (float) weight[i];
sort(&weight,&profit,&unit);
knapsack(&weight,&profit,&selected,&temp,0,0.0,0.0);
print(&weight,&profit,&selected,Output);
}
int bruteforce(FILE *fp,FILE *Output)
{
int i=0,j=0;
    int weight[20]={0},profit[20]={0};
    int selected[20]={0},temp[20]={0};
    float unit[20]={0};

size=readfile(&weight,&profit,fp);


for(i=0;i<size;i++)
unit[i] = (float) profit[i] / (float) weight[i];
sort(&weight,&profit,&unit);
knapsack(&weight,&profit,&selected,&temp,0,0.0,0.0);
print(&weight,&profit,&selected,Output);
}

#endif // BRUTEFORCE_H_INCLUDED
