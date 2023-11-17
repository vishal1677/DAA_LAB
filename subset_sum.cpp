#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&nums, int ind, vector<int>&ds, int sum, int n)
{
  if(sum == 0)
  {
   for(int i=0; i<ds.size(); i++)
   {
    cout<<ds[i]<<" ";
   }
   cout<<"\n";
   return;
  }

  if(ind == n)
  {
    if(sum == 0)
    {
        for(int i=0;i<ds.size(); i++)
        {
            cout<<ds[i]<<" ";
        }

        cout<<"\n";
    }
    return;
  }
  
  ds.push_back(nums[ind]);
  solve(nums,ind+1,ds,sum-nums[ind],n);
  ds.pop_back();
  solve(nums,ind+1,ds,sum,n);

}

int main()
{
 vector<int>nums={1,3,2,4};
 int val=5;
 vector<int>ds;
 int n=4;
 solve(nums,0,ds,val,n);
return 0;
}