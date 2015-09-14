//
//  main.c
//  hackerrank_worldcup
//
//  Created by Pooshan Vyas on 9/12/15.
//  Copyright © 2015 Pooshan Vyas. All rights reserved.
//


/*
 
 Problem Statement
 
 Hackerrank's World Cup is approaching and every coach is trying to form the best possible team to win the cup.
 
 Hackerland university has 2 coaches and only 10 good programmers. A team consists of 3 programmers. Both coaches want to lead the best team and each programmer can only join one team.
 
 To solve the dispute, the coaches decided that they will take turns selecting one team member at a time until both teams have 3 members.
 
 You are given the Hackerrank rating points for each of the 10 programmers. A team's value is the sum of rating points of each member. The two coaches will try to maximize the value of their own team. Determine the value of the best team a coach can get.
 
 Input Format
 
 There will be 10 lines, where each of them is an integer between 0 to 3000 denoting the rating points of the programmers.
 
 Output Format
 
 Print just one line which is the value of the best team a coach can get.
 
 */

#include<stdio.h>

void sort(int a[],int n)
{ int i,j,k,temp;
    
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
            if(a[j]<a[i])
            {
                temp=a[i];
                for(k=i;k>j;k--)
                    a[k]=a[k-1];
                a[k]=temp;
            }
    }
}

int main()
{
    int total_value = 0;
    int a[100],i;
    //printf("Enter Length:  "); scanf("%d",&n);
    
    printf("Enter data: \n");
    for(i=0;i<10;i++) scanf("%d",&a[i]);
    
    sort(a,10);
    
    //printf("After sorting \n");
    //for(i=0;i<10;i++) printf("%d\n",a[i]);
    
    total_value = a[0] + a[2] + a[4];
    
    printf("%d \n", total_value);
}



