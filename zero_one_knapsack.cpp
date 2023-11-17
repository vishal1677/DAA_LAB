#include<bits/stdc++.h>
using namespace std;

int main()
{

vector<int>profit={15,10,9,5};
vector<int>weight={1,5,3,4};
int w=8;
int n=4;
vector<vector<int>>dp(n+1,vector<int>(w+1,0));
for(int i=1; i<=n; i++)
{
  for(int j=1; j<=w; j++)
  {
    if(weight[i-1] <= j)
    {
        dp[i][j]=max(dp[i-1][j],profit[i-1]+dp[i-1][j-weight[i-1]]);
    }
    else
    {
       dp[i][j]=dp[i-1][j];
    }
  }
}

cout<<dp[n][w]<<"\n";
int i=n;
int j=w;
int ans=dp[n][w];
while(i >0 && ans>0)
{
  if(ans == dp[i-1][j])
  {
    i--;
    //j--;
  }
  else
  {
    cout<<weight[i-1]<<" "<<profit[i-1]<<"\n";
    ans-=profit[i-1];
    //i--;
    j-=weight[i-1];
    i--;
  }
}

return 0;
}