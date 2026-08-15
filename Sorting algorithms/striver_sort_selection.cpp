#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> arr ={7,4,10,8,3,1};
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    for(int k=0;k<arr.size();k++)
    {
        cout << arr[k] << endl;
    }
}