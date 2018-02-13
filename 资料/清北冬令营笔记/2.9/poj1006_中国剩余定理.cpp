#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int M=21252;
void exgcd(LL a,LL b,LL&d,LL&x,LL&y){
	if(!b) d=a,x=1,y=0;
	else{
		exgcd(b,a%b,d,y,x);y-=(a/b)*x;
	} 
}
LL R1,R2,R3;
int p,e,i,D;
int main(){
	//-x/2 = -(x/2)
	printf("%d %d\n",(-3)/2,-3>>1);
	LL y,d;
	exgcd(M/23,23,d,R1,y);
	exgcd(M/28,28,d,R2,y);
	exgcd(M/33,33,d,R3,y);
	R1=(M/23*R1)%M;
	R2=(M/28*R2)%M;
	R3=(M/33*R3)%M;
	int tt=0;
	
	while(scanf("%d%d%d%d",&p,&e,&i,&D),~p){
		printf("Case %d: the next triple peak occurs in ",++tt);
		LL ans=(R1*p+R2*e+R3*i-D)%M;
		ans=(ans+M)%M;
		if(ans==0){
			printf("%d days.\n",M);
		}else printf("%lld days.\n",ans);
	}
	return 0;
}


