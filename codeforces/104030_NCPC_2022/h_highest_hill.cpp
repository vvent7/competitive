#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

#define MAX_N 200005LL

ll a[MAX_N];

int main(){_
  int n; cin>>n;

  ll start=-1;

  a[0]=LLONG_MAX;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(start!=-1) continue;
    if(a[i]>=a[i-1]) start=i-1;
  }
  a[n+1]=LLONG_MAX;

  ll ans=0;
  for(ll i=start+1, l=a[start], mid=-1, r=-1;i<=n+1;i++){
    if(mid==-1){
      if(a[i]<a[i-1]) mid=a[i-1];
    }
    else if(r==-1 && a[i]>a[i-1]){
      r=a[i-1];
      // cout<<l<<" "<<mid<<" "<<r<<endl;
      ans=max(ans, min(mid-l, mid-r));
      l=r;
      mid=r=-1;
    }
  }

  cout<<ans<<endl;


  return 0;
}
