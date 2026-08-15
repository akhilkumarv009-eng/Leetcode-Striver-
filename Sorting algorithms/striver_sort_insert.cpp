#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> arr = {5,4,10,1,6};
    for(int i=1;i<arr.size();i++)
    {
        int temp=arr[i];
        int j=0;
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=temp;
    }
    for(int k=0;k<arr.size();k++)
    { 
        cout << arr[k] << endl;
    }
}