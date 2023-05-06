#include<bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

inline ll dist2(ll x, ll y){
  return x*x+y*y;
}

inline bool isInside(ll x, ll y, ll r){
  return dist2(x,y)<=r*r;
}

ll bestX(ll x, ll y, ll r){
  while(!isInside(x,y,r)) x--;
  return x+1;
}

int main(){_
  ll r; cin>>r;

  ll ansX=r+1, ansY=0;
  for(ll y=0, x=r+1;y<=r;y++){
    x=bestX(x, y, r);
    if(dist2(x,y)<dist2(ansX, ansY)) ansX=x, ansY=y;
  }

  cout<<ansX<<" "<<ansY<<endl;

  return 0;
}