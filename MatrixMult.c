#include<stdio.h>
#include<conio.h>
#include<limits.h>
void mcm(int p[],int n)
{
	int m[10][10];
	int s[10][10];
	int i,j,k,l,q;
	for(i=0;i<n;i++)
	{
		m[i][i]=0;
	}
	for(l=2;l<n;l++)
	{
		for(i=1;i<n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+(p[i-1]*p[j]*p[k]);
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("\n The minimum no of scalar multiplications are:%d",m[1][n-1]);

}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    
                       mcm(arr, size);
 
  
    return 0;
}
