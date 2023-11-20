#include<bits/stdc++.h>
using namespace std;
#define N 5
#define INF INT_MAX

class Node
{
 public:
        int cost;
        vector<pair<int,int>>path;
        int reducedMatrix[N][N];
        int vertex;
        int level;

};


Node *newNode(int costMatrix[N][N],vector<pair<int,int>>const &path,int level,int i, int j)
{
  Node *node = new Node;
  node->path=path;

  if(level != 0)
  {
    node->path.push_back(make_pair(i,j));
  }

  memcpy(node->reducedMatrix,costMatrix,sizeof node->reducedMatrix);

  // change ith row and jth column to Inf skip for root
  for(int k=0; level !=0 && k<N; k++)
  {
     node->reducedMatrix[i][k]=INF;
     node->reducedMatrix[k][j]=INF;
  }
  
  // starting node is 0
  node->reducedMatrix[j][0]=INF;
  node->level=level;
  node->vertex=j;
  return node;
}



void rowReduction(int reducedMat[N][N], int row[N])
{
    // reduce min of each row ans store it in row
    //memset(row,INF,sizeof(row));
     for(int i=0; i<N; i++)
     {
        row[i]=INF;
     }

    for(int i=0; i<N; i++)
    {
      for(int j=0; j<N; j++)
      {
        if(reducedMat[i][j] < row[i])
        {
            row[i]=reducedMat[i][j];
        }
      }
    }

    for(int i=0; i<N; i++)
    {
      for(int j=0; j<N; j++)
      {
          if(reducedMat[i][j] != INF && row[i] != INF)
          {
            reducedMat[i][j]-=row[i];
          }
      }
    }
}

void colReduction(int reduceMat[N][N], int col[N])
{
   for(int i=0; i<N; i++)
   {
     col[i]=INF;
   }

   for(int i=0; i<N; i++)
   {
    for(int j=0; j<N; j++)
    {
       if(reduceMat[i][j] < col[j])
       {
        col[j]=reduceMat[i][j];
       }
    }
   }
   
   for(int i=0; i<N; i++)
   {
    for(int j=0; j<N; j++)
    {
     if(reduceMat[i][j] != INF && col[j] != INF)
     {
        reduceMat[i][j]-=col[j];
     }
    }
   }
}

int calculateCost(int reducedMatrix[N][N])
{
  int cost=0;
  int row[N];
  rowReduction(reducedMatrix,row);
  int col[N];
  colReduction(reducedMatrix,col);
   
  for(int i=0; i<N;i++)
  {
    if(row[i] != INF)
    {
        cost+=row[i];
    }

    if(col[i] != INF)
    {
     cost+=col[i];
    }
  }

return cost;  
}

void printPath(vector<pair<int,int>>const &path)
{
  for(int i=0; i<path.size(); i++)
  {
    cout<<path[i].first+1<<" -> "<<path[i].second+1<<"\n";
  }
}

struct cmp
{
  bool operator()(const Node *lhs, const Node *rhs)const{
   return lhs->cost < rhs->cost;
  }
};

int solve(int costMatrix[N][N])
{

  priority_queue<Node*,vector<Node*>,cmp>pq;
  vector<pair<int,int>>pair;
  Node *root = newNode(costMatrix,pair,0,-1,0);
  root->cost=calculateCost(root->reducedMatrix);
  
  pq.push(root);
  while(!pq.empty())
  {
    Node *min=pq.top();
    pq.pop();

    int i=min->vertex;

    // all nodes are visited
    if(min->level == N-1)
    {
       min->path.push_back(make_pair(i,0));
       //min->cost+=min->reducedMatrix[i][0];
       printPath(min->path);
       return min->cost;
    }

    for(int j=0; j<N; j++)
    {
        if(min->reducedMatrix[i][j] != INF)
        {
            Node *child= newNode(min->reducedMatrix,min->path,min->level+1,i,j);
            child->cost=min->cost+min->reducedMatrix[i][j]+calculateCost(child->reducedMatrix);
            pq.push(child);
        }
    }

   delete min;
  }


}

int main()
{
    // cost 34
    int costMatrix[N][N] =
    {
        { INF, 10, 8, 9, 7 },
        { 10, INF, 10, 5, 6 },
        { 8, 10, INF, 8, 9 },
        { 9, 5, 8, INF, 6 },
        { 7, 6, 9, 6, INF }
    };


int res=solve(costMatrix);

cout<<"Total cost :- "<<res<<"\n";


return 0;
}