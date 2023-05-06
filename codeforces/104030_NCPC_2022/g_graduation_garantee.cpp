#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

#define MAX_N 5005
#define PADDING 5000

#define PAD(x) (x+PADDING)
#define UNPAD(x) (x-PADDING)

int k, n;
double p[MAX_N];
double dp[MAX_N][2*MAX_N];

double f(int m, int q){
  if(m==0){
    if(q<=0) return 1;
    else return 0;
  }
  
  double &cur = dp[m][PAD(q)];
  
  if(cur!=-1) return cur;

  return cur=p[m]*f(m-1, q-1)+(1.0-p[m])*f(m-1, q+1);
}

int main(){_
  cin>>n>>k;

  for(int i=0;i<=n;i++)
    for(int j=PAD(k-n);j<=PAD(k+n);j++)
      dp[i][j]=-1;

  for(int i=1;i<=n;i++) cin>>p[i];

  sort(p+1, p+n+1, greater<double>());

  double ans=0;
  for(int m=k;m<=n;m++)
    ans=max(ans, f(m, k));

  cout<<fixed<<setprecision(6);
  cout<<ans<<endl;

  return 0;
}
