#include<stdio.h>
#include<conio.h>
#include<limits.h>
void merge(int a[],int p,int q,int r)
{	int n1,n2,i,j,k,l[10],m[10];
	n1=q-p+1;
	n2=r-q;
	for(i=0;i<n1;i++)
	{
		l[i]=a[p+i];
	}
	for(i=0;i<n2;i++)
	{
		m[i]=a[q+i+1];
	}
	i=0;j=0,k=p;
while(i<n1&&j<n2)
	{
		if(l[i]<=m[i])
		{
			a[k]=l[i];
			i++;
			k++;
		}
		else
		{
			a[k]=m[j];
			j++;
			k++;
		}
	}
	while (i < n1)
    {
        a[k] = l[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        a[k] = m[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int p,int r)
{	
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
		merge(arr,p,q,r);
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
	mergeSort(arr,0,size-1);
	 printf("Sorted array:\n");
    printArray(arr, size);
    return 0;
}
