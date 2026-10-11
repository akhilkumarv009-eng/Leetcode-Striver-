#include <iostream>
#include <vector>
#include <map>
using namespace std;



class Solution {
public:
    int cnt = 0;

    void  merge(vector<int> &a ,int low,int mid,int high)
    {
        
        vector<int> temp;
        int l = low;
        int r = mid+1;

        while(l <= mid && r <= high )
        {
            if(a[l] <= a[r])temp.push_back(a[l++]);
            else{ temp.push_back(a[r++]);

            }
        }

        while(l <= mid) temp.push_back(a[l++]);

        while(r <= high) temp.push_back(a[r++]);

        for(int i = low; i <= high; i++)
       {
           a[i] = temp[i - low];
       }

    

    }
    void countpairs(vector<int> &a ,int low,int mid,int high)
    {
        int right = mid+1;
        for(int i = low ; i <= mid ; i++)
        {
            while(right <= high && (long long)a[i] > 2LL * a[right])
            {
                right++;
            }
            cnt+=(right-(mid+1));
        }
    }
    void mergesort(vector<int> &a ,int low ,int high)
    {
        
        if(low >= high) return;
        int mid = (high + low) / 2;

        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        countpairs(a,low,mid,high);
        merge(a,low,mid,high);

        
    }
   
    int reversePairs(vector<int>& nums) {
        cnt = 0;
        
        int n = nums.size();
        mergesort(nums,0,n-1);
        return cnt;
    }
};