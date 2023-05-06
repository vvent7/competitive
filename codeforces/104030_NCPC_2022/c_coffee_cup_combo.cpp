#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main(){_
  string s;
  int n; cin>>n>>s;

  int ans=0, hand=0;
  for(char c:s){
    if(c=='1'){
      ans++; hand=2;
    }
    else if(hand>0){
      ans++; hand--;
    }
  }

  cout<<ans<<endl;

  return 0;
}
