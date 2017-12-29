#include<stdio.h>
#include<conio.h>
void swap(int *a,int*b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int low,int high)
{
	int i,j,pivot;
	pivot=arr[high];
	i=low-1;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i=i+1;
			swap(&arr[j],&arr[i]);
		}
		
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}
void quickSort(int arr[],int low,int high)
{	
	int p;
	if(low<high)
	{
		p=partition(arr,low,high);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
		
	}
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
	int arr[]={56,12,45,13,1,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	quickSort(arr,0,size-1);
	 printf("Sorted array:\n");
    printArray(arr, size);
    return 0;
}
