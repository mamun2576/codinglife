#include<iostream>
using namespace std;
#define lim 200
int temp[lim];

print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
}
void Merge(int arr[],int l,int mid, int r)
{
    int i,j,k=0;
    i=l;
    j=mid+1;
    while(i<=mid && j<=r)
    {
        if(arr[i] < arr[j])
        {
          temp[k++]=arr[i++];

        }
        else
            temp[k++]=arr[j++];

    }
    while(i<=mid)
    {
          temp[k++]=arr[i++];

    }
    while(j<=r)
    {
        temp[k++]=arr[j++];

    }
    for(i=l,j=0;i<=r;i++,j++)
    {
        arr[i]=temp[j];
    }

}
 void Mergesort(int arr[],int l,int r)
 {
     if(l>=r)
        return;

     else
     {
         int mid;
         mid=(l+r)/2;

         Mergesort(arr,l,mid);
         Mergesort(arr,mid+1,r);

         Merge(arr,l,mid,r);
     }
 }

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    Mergesort(arr,0,n-1);
    print(arr,n);
}
