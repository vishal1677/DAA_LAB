#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int all_vis;
#define ll long long

int tsp(int ind,vector<vector<int>>&graph,vector<vector<int>>&dp,int mask, int n)
{
  if(mask == all_vis)
  {
    return graph[ind][0];
  }

  if(dp[mask][ind] != -1) return dp[mask][ind];
  ll mini=LLONG_MAX;

  for(int i=0; i<n; i++)
  {
    if((mask&(1<<i)) == 0)
    {
      ll val=graph[ind][i]+tsp(i,graph,dp,mask|(1<<i),n);
      mini=min(mini,val);
    }
  }

  return dp[mask][ind]=mini;

}

void path(int pos, vector<vector<int>>&graph, vector<vector<int>>&dp,int mask, int n)
{
  if(mask == all_vis)
  {
    return;
  }

  ll mini=LLONG_MAX;
  ll minipos;
  for(int i=0; i<n; i++)
  {
    if((mask&(1<<i)) == 0)
    {
      ll val=graph[pos][i]+dp[(mask|(1<<i))][i];
      if(val < mini)
      {
        mini=val;
        minipos=i;
      }
    }
  }
 cout<<"->"<<minipos+1;
 path(minipos,graph,dp,(mask|(1<<minipos)),n);

}

int main()
{
int n=4;
all_vis=(1<<n)-1;
vector<vector<int>>graph={
        {INF, 5, 4, 3},
        {3, INF, 8, 2},
        {5, 3, INF, 9},
        {6, 4, 3, INF}
};
int mask=1;
vector<vector<int>>dp((1<<n),vector<int>(50,-1));
int res=tsp(0,graph,dp,mask,n);
mask=1;
cout<<"1->";
path(0,graph,dp,mask,n);

cout<<res<<"\n";

return 0;
}