#include<bits/stdc++.h>
using namespace std;

void knapsack(vector<int>wt, vector<int>pr, int w)
{
 priority_queue<pair<float,pair<float,float>>>pq;
 for(int i=0; i<wt.size(); i++)
 {
  pq.push({(pr[i]*1.0/wt[i]),{pr[i],wt[i]}});
 }
 float rem=w;
 float ans=0;

 while(!pq.empty() && rem > 0)
 {
    auto node=pq.top();
    pq.pop();
    float pr=node.second.first;
    float wt=node.second.second;
    if(wt <= rem)
    {
        rem-=wt;
        ans+=pr;
    }
    else
    {
        float add=(rem)/wt;
        ans+=(add*pr);
        rem=0;
    }
 }

 cout<<ans<<"\n";
}

int main()
{
vector<int>wt={5,10,20,30,40};
vector<int>pr={30,20,100,90,160};
int w=60;
knapsack(wt,pr,w);

return 0;
}