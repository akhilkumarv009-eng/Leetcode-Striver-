#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int partion(vector <int> &arr,int l,int h)
{
    int pivot = arr[l];
    int start=l;
    int end=h;
    while(start<end)
    {
    while(arr[start]<=pivot && start <= h)
    {
        start++;
    }
    while (arr[end]>pivot)
    {
        end--;
    }
    if(start<end){
    swap(arr[start],arr[end]);
    }

    }
    swap(arr[l],arr[end]);
    return end;
}
void quicksort(vector <int> & arr,int l,int h)
{
    if(l<h){
    int q=partion(arr,l,h);
    quicksort(arr,l,q-1);
    quicksort(arr,q+1,h);
    }
}
int main()
{
    vector<int> arr={5,2,5,3,6,3};
    int l=0;
    int h=arr.size()-1;
    quicksort(arr,l,h);
     for(int x : arr)
    {
        cout << x << " ";
    }
}