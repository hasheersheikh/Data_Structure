//function for sorting 
//#sorting headers

//header file
#include<stdio.h>
#include<stdlib.h>
//created by hashir

//bubble sort
void bubble_sort(int arr[],int len){
	int temp,i,j;
	for(i=0;i<len;i++)
		{
		for(j=0;j<len-i-1;j++)
			{
			if(arr[j]>arr[j+1])
				{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				}
			}
		}
	}

//insertion sort

void insertion_sort(int arr[],int len){
   int i,j,key;
    for(j=1;j<=len-1;j++)
     {
	key=arr[j];
	i=j-1;
	while(i>=0 && arr[i]>key)
	    {
	    arr[i+1]=arr[i];
		i=i-1;
	    }
	arr[i+1]=key;
     }
}

//selection sort

void selection_sort(int arr[],int len){
        int i,j,swap;
        for(i=0;i<len-1;i++){
                for(j=i+1;j<len;j++){
	                if(arr[i]>arr[j]){
                                swap=arr[i];
                                arr[i]=arr[j];
                                arr[j]=swap;
                        }
                 }
        }
}

//shell sort

void shell_sort(int arr[],int len){
	int gap,i,key,j;
	for(gap=len/2;gap>0;gap/=2){
		for(i=gap;i<len;i++){
        	      	key=arr[i];
	              	for(j=i;j>=gap && arr[j-gap]>key;j-=gap){
        	            	arr[j]=arr[j-gap];
	            	}
		        arr[j]=key;
	        }
	}
}


