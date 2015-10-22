//
//  main.c
//  X
//
//  Created by Pooshan Vyas on 10/21/15.
//  Copyright © 2015 Pooshan Vyas. All rights reserved.
//

/*
 * C Program to Get available Host/IP Address and sort it in decending order
 */


#include <string.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

long long hostAvailable1 (char str[]);
long long hostAvailable2 ();
long long hostAvailable3 ();
long long hostAvailable4 ();
int insertionSort(long long elements[], long long element);
char ipaddress[500];
int noOfElements;
long long a[100];

int main(){

    long long r1;
    int i;
    printf("How many number of IP you want to check? : ");
    scanf("%d", &i);
    int j;
    int counter=0;
    
    for (j=0; j<i; j++) {
        
        r1=hostAvailable1(ipaddress);
        printf("output of R1 : %lli \n",r1);
        
        int pos = 0;
        int iteration=0;
        noOfElements = 0;
        while(a[iteration]!='\0'){
           
            if(a[iteration]<r1){
                while(a[iteration]!='\0'){
                    noOfElements++;
                    iteration++;
                }
                break;
            }
             noOfElements++;
            iteration++;
            pos++;
        }

        if(pos == noOfElements){
            a[pos] = r1;
        }else{
            int loopCounter = noOfElements;
            for(;loopCounter>pos;loopCounter--){
                a[loopCounter] = a[loopCounter-1];
            }
            a[pos] = r1;
        }
        
        printf("Sorted order after iteration \n");
        

        counter++;
    }

    int printCounter = 0;
    int rank = 0;
    while(printCounter <=noOfElements){
        printf("%lli\t",a[printCounter]);
        if(printCounter > 0 ){
            if(a[printCounter] != a[printCounter-1]){
                rank++;
            }
        }
        printf("%d\n",rank);
        printCounter++;
    }
    return(0);
}

long long hostAvailable1 (char *str){

    printf("Please enter IP address: ");
    scanf("%s", ipaddress);
    getchar();
    //char str[] = "10.2.3.4/32";
    //172.16.224.0/23, 192.168.100.97/27, 255.255.255.240/14, 255.255.14.0/28, 10.0.0.0/16
    const char s[] = "/.";
    char *token;
    char *token1,*token2,*token3,*token4,*token5;
    long long result;
    float step1;
    //float newresult;
    int newtoken4;
    //long long addrange;
    long long result1;
    
    /* get the 1st token */
    token = strtok(str, s);
    token1 = token;
    printf("1st token: %s\n", token1);
    
    /* get the 2nd token */
    token = strtok(NULL, ".");
    token2 = token;
    printf("2nd token: %s\n", token2);
    
    /* get the 3rd token */
    token = strtok(NULL, ".");
    token3 = token;
    printf("3rd token: %s\n", token3);
    
    /* get the 4th token */
    token = strtok(NULL, "./");
    token4 = token;
    printf("4th token: %s\n", token4);
    newtoken4=atoi(token4);
    
    
    /* get the 5th token */
    token = strtok(NULL, "/");
    token5 = token;
    printf("5th token: %s\n", token5);
    
    step1=(32)-atoi(token5);
    //printf("%f\n",step1);
    result=pow(2,step1);
    //printf("%f \n",result);
    if (result>1) {
        result1=(result-2);
    }
    else result1=0;
    // Here I assume tha I don't use my network so I take away 2.
    printf("Total number of available host/ip addresses are: %lli \n", result1);
    return result1;

}

/* insertion sort ascending order */


int insertionSort(long long *elements, long long element)
{
    printf("Input to insertionSort : %lli ",element);
    //printf("Enter number of elements\n");
    //scanf("%d", &n);
    
   // printf("Enter %d integers\n", i);
    
    //for (c = 0; c < i; c++) {
      //  scanf("%d", &a[k]);
    //}
    int pos = 0;
    int iteration=0;
     noOfElements = 0;
    while(elements[iteration]=='\0'){
        pos++;
        noOfElements++;
        if(elements[iteration]<element){
            while(elements[iteration]=='\0'){
                noOfElements++;
                iteration++;
            }
            break;
        }
        iteration++;
    }

    return pos;
}