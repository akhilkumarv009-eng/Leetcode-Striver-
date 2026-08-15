#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct train
{
    int time;
    int type;
};

bool comp(train a, train b)
{
    if(a.time == b.time)
        return a.type < b.type;
    return a.time < b.time;
}
int main()
{
    int n;

    cin >> n ;

    vector<int> arr(n);
    vector<int> dep(n);

    for(int i =0 ; i < n ; i ++)
    {
        cin >> arr[i];
    }
    for(int i =0 ; i < n ; i ++)
    {
        cin >> dep[i];
    }

    vector<train> trains(2*n);
    int j = 0;

    for(int i = 0 ;i < n ; i ++)
    {
    
       trains[j].time = arr[i];
       trains[j].type=0;
       j++;
       trains[j].time = dep[i];
       trains[j].type=1;
       j++;
    }

    sort(trains.begin(),trains.end(),comp);

    int cnt=0;
    int cntmax=0;

    for(int i = 0 ; i < 2*n ; i ++)
    {
        if(trains[i].type==0)
        {
            cnt++;
            cntmax=max(cnt,cntmax);
        }
        else
        {
            cnt--;
        }
    }

    cout << cntmax;



}