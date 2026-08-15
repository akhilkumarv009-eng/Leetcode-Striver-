#include <iostream>
#include <vector>
using namespace std;

vector<int> Size;
vector<int>parent;

void makeset(int n)
{
    Size.resize(n+1);
    parent.resize(n+1);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        Size[i]=1;
    }
}

int parentnode(int n)
{
    if(n==parent[n])
    return n;

    else
    return parent[n]=parentnode(parent[n]);
}

void unionbysize(int u,int v)
{
    int pu=parentnode(u);
    int pv=parentnode(v);

    if(pu==pv)
    {
        return ;
    }
    if(Size[pv] < Size[pu])
    {
        parent[pv] = pu;

        Size[pu] = Size[pu] + Size[pv] ;
        
    }
    else
    {
        parent[pu] = pv;

        Size[pv] = Size[pv] + Size[pu] ;
    }
}
int main()
{
    makeset(7);
    unionbysize(1,2);
    unionbysize(2,3);
    unionbysize(4,5);
    unionbysize(6,7);
    unionbysize(5,6); 
    if(parentnode(3) == parentnode(7))
        cout << "1 and 3 are connected\n";
    else
        cout << "1 and 3 are not connected\n";

    if(parentnode(1) == parentnode(5))
        cout << "1 and 5 are connected\n";
    else
        cout << "1 and 5 are not connected\n";

    return 0;
}



