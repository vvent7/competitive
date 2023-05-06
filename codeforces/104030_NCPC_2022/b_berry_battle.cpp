#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define pb push_back
#define eb emplace_back
typedef long long ll;

#define MAX_N 300005

vector<int> g[MAX_N];
int degree[MAX_N];
bool visited[MAX_N];

void dfs(int u){
  visited[u]=true;
  for(auto v:g[u]){
    if(visited[v]) continue;
    cout<<" "<<v;
    dfs(v);
  }
}

int main(){_
  int n; cin>>n;

  for(int i=1, u, v;i<n;i++){
    cin>>u>>v;
    g[u].eb(v);
    g[v].eb(u);
    degree[u]++;
    degree[v]++;
  }

  // for(int i=1;i<=n;i++) cout<<degree[i]<<" ";
  // cout<<endl;

  int leaf=1;
  while(degree[leaf]>1) leaf++;

  int qtGreater=leaf-1;
  for(int i=leaf+1;i<=n && qtGreater<=1;i++)
    if(degree[i]>1) qtGreater++;


  if(qtGreater<=1) cout<<"NO\n";
  else{
    cout<<"YES\n";
    cout<<g[leaf][0]<<" "<<leaf;
    visited[leaf]=true;
    dfs(g[leaf][0]);
    cout<<endl;
  }

  return 0;
}
