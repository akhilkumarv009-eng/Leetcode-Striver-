#include <iostream>
#include <vector>
using namespace std;

struct item{
    int start;
    int end;
    int index;
};
bool compare(item a ,item b)
{
    return a.end < b.end;
}
int main()
{
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> start[i];
    }
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> end[i];
    }

    vector<item> meet(n);
    for(int i = 0 ; i < n ; i ++)
    {
        meet[i].start=start[i];
        meet[i].end=end[i];
        meet[i].index=i;
    }

    sort(meet.begin(),meet.end(),compare);

    int cnt=0;
    cnt=1;
    int max=meet[0].end;

    vector<item> ans;

    ans.push_back(meet[0]);

    for(int i = 1 ; i < n ; i ++)
    {
        if(meet[i].start > max)
        {
            cnt++;
            max=meet[i].end;
            ans.push_back(meet[i]);
        }
    }

    cout << cnt << endl;
    for(auto it : ans)
    {
        cout << it.index << endl;
    }

    


}