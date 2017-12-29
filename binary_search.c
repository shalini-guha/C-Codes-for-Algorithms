#include<stdio.h>
void main(){
    int n,*a,i,f=0,l,flag=0,mid,v;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
printf("Enter the array elements");
a=(int*)(malloc(sizeof(int)*n));
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
printf("Enter the value to be searched");
scanf("%d",&v);
l=n-1;
while(f<=l){
    mid=(f+l)/2;
    if(a[mid]==v){
        flag=1;
        break;
    }
    else if(a[mid]>v)
        l=mid-1;
    else
    f=mid+1;
}
if(flag==1)
    printf("Value found %d",(mid+1));
}

