#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

    long long merge(vector<int> &a ,int low,int mid,int high)
    {
        long long cnt =0;
        vector<int> temp;
        int l = low;
        int r = mid+1;

        while(l <= mid && r <= high )
        {
            if(a[l] <= a[r])temp.push_back(a[l++]);
            else{ temp.push_back(a[r++]);

            cnt += (mid - l)+1;
            }
        }

        while(l <= mid) temp.push_back(a[l++]);

        while(r <= high) temp.push_back(a[r++]);

        for(int i = low; i <= high; i++)
       {
           a[i] = temp[i - low];
       }

        return cnt;

    }
    long long mergesort(vector<int> &a ,int low ,int high)
    {
        long long cnt = 0;
        if(low >= high) return cnt;
        int mid = (high + low) / 2;

        cnt += mergesort(a,low,mid);
        cnt += mergesort(a,mid+1,high);
        cnt += merge(a,low,mid,high);

        return cnt;
    }
   long long int numberOfInversions(vector<int> nums) {
    int n = nums.size();
    return mergesort(nums,0,n-1);

    }
};