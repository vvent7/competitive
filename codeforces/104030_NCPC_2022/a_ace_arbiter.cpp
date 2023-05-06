#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

//0->A, 1->B
int parity(int x, int y){
  return (x+y)%4==0 || (x+y)%4==3 ? 0 : 1;
}

int main(){_
  int n;
  scanf("%d", &n);

  int preX, preY, i=1, x, y;
  bool done=false;

  scanf("%d-%d", &preX, &preY);
  if(parity(preX, preY)!=0) swap(preX, preY);
  if(preX==11 || preY==11) done=true;
  if(preX==11 && preY==11){
    printf("error %d\n", 1); 
    return 0;
  }
  
  
  for(i=2;i<=n;i++, preX=x, preY=y){
    scanf("%d-%d", &x, &y);

    if(x==11 && y==11) break;    

    if(parity(x, y)!=0) swap(x, y);
    // printf("%d %d\n", preX, preY);
    // printf("%d %d\n\n", x, y);
    if(done && (x!=preX || y!=preY)) break; //change pontuation after end
    if(x<preX || y<preY) break; //decrease pontuation
    if(x==11 || y==11) done=true;
  }

  if(i>n) puts("ok");
  else printf("error %d\n", i);

  return 0;
}
