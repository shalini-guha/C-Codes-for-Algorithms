#include<stdio.h>
#include<conio.h>
int main()
{
	int i,n,m,j;
	float p[10],w[10],r[10],profit,temp;
	printf("\n Enter the capacity of the knapsack:\n");
	scanf("%d",&m);
	printf("\n Enter the no. of items:\n");
	scanf("%d",&n);
	printf("\n Enter the price:\n");
	for(i=0;i<n;i++)
	scanf("%f",&p[i]);
	printf("\n Enter the weight:\n");
	for(i=0;i<n;i++)
	scanf("%f",&w[i]);
	for(i=0;i<n;i++)
	{
		r[i]=(p[i]/w[i]);
		
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(r[j]<r[j+1])
			{
				temp=r[j];
				r[j]=r[j+1];
				r[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
			}
		}
	}

		for(i=0;i<n;i++)
		printf("%0.1f\t",p[i]);
		printf("\n");
		for(i=0;i<n;i++)
		printf("%0.1f\t",w[i]);
		printf("\n");
		for(i=0;i<n;i++)
		printf("%0.1f\t",r[i]);
		printf("\n");
	for(i=0;i<n;i++)
	{
		if(m>0&&w[i]<=m)
		{
			m=m-w[i];
			profit=profit+p[i];
		}
		else
		break;
	}
		if(m>0)
		profit=profit+(m*r[i]);
	
	printf("\n The maximised profit is:%f",profit);
}
