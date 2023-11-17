#include<bits/stdc++.h>
using namespace std;


void solve(int i, vector<string>&mat,vector<bool>&col, vector<bool>&rdiag, vector<bool>&ldiag, int n)
{
 if(i == n)
 {
    for(int p=0; p<n; p++)
    {
        for(int q=0; q<n; q++)
        {
          cout<<mat[p][q]<<" ";
        }

        cout<<"\n";
    }
 return;
 }

 for(int j=0; j<n; j++)
 {
    if(col[j] && ldiag[i+j] && rdiag[i-j+n-1])
    {
      mat[i][j]='Q';
      col[j]=false;
      ldiag[i+j]=false;
      rdiag[i-j+n-1]=false;
      solve(i+1,mat,col,rdiag,ldiag,n);
      mat[i][j]='.';
      col[j]=true;
      ldiag[i+j]=true;
      rdiag[i-j+n-1]=true;
    }
 }

return;

}

int main()
{
int n=4;
vector<bool>col(n,true);
vector<bool>rdiag(2*n,true);
vector<bool>ldiag(2*n,true);
vector<string>mat(n,string(n,'.'));
solve(0,mat,col,rdiag,ldiag,n);

return 0;
}