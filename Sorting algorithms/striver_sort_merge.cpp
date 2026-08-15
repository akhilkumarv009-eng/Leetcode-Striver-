#include <iostream>
#include <vector>
using namespace std;
void merge(vector <int> & arr ,int l,int h,int mid)
{
    int i=l;
    int j=mid+1;
    int k=l;
    vector <int> arr3(arr.size());
    while(i<=mid && j<=h)
    {
       if(arr[i]<arr[j])
       {
            arr3[k++]=arr[i++];
       }
       else
       {
        arr3[k++]=arr[j++];
       }
    }
    while(i <= mid)
    {
        arr3[k++] = arr[i++];
     }
    while(j<= h)
    {
       arr3[k++] = arr[j++];
    }
    for(int v=l;v<=h;v++)
   {
        arr[v]=arr3[v];
   }
}
void mergesort(vector <int> & arr,int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,h,mid);
    }
}
int main()
{
    vector<int> arr = {7,4,10,8,3,1};

    mergesort(arr, 0, arr.size()-1);

    for(int x : arr)
    {
        cout << x << " ";
    }
}