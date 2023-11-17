#include<bits/stdc++.h>
using namespace std;
#define N 100
#define ll long long

void bellmanford(vector<pair<int,int>> graph[], int nodes)
{
  int n=nodes;
  vector<bool>vis(n+1,false);
  vector<ll>dis(n+1,INT_MAX);
  dis[1]=0;
  vis[1]=true;
  for(int k=1; k<=n-1; k++)
  {
    bool ischange=true;

    for(int i=1; i<=n; i++)
    {
      for(auto j:graph[i])
      {
        if(dis[j.first] > dis[i]+j.second)
        {
            dis[j.first]=dis[i]+j.second;
            ischange=false;
        }
      }
    }

    if(k == n-1 && !ischange)
    {
        cout<<"No solution\n";
        return;
    }
  }

for(int i=1; i<=n; i++)
{
    cout<<dis[i]<<" ";
}
cout<<"\n";

}

int main()
{
int n=7;
vector<pair<int,int>> graph[N];
graph[1].push_back({2,6});
graph[1].push_back({4,5});
graph[4].push_back({3,-2});
graph[3].push_back({2,-2});
graph[3].push_back({5,1});
graph[2].push_back({5,-1});
graph[4].push_back({6,-1});
graph[6].push_back({7,3});
graph[5].push_back({7,3});
// graph[1].push_back({2,10});
// graph[1].push_back({3,1});
// graph[3].push_back({2,2});

bellmanford(graph,n);


return 0;
}