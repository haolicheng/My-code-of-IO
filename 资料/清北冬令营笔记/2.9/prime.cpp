#include<cstdio>

using namespace std;

bool judge(int x){
	if(x<2) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

bool not_prime[105];

int prime[105],tot;
int mindiv[105];



int gcd(int a,int b){  //  a<b : swap   a>b
	if(b==0) return a;
	return gcd(b,a%b);
}

int main(){
	//1..n
	int n=100;
	for(int i=1;i<=n;i++){ // O(nsqrtn)
		if(judge(i)){
			printf("%d ",i);
		}
	}
	puts("");
	for(int i=2;i<=n;i++){
		if(!not_prime[i]){
			printf("%d ",i);
			for(int j=2;j*i<=n;j++){// O(nlogn)
				not_prime[j*i]=true;
			}
		}
	}
	// n/2+n/3+n/5+....
	// n*(1/2+1/3+...)
	// 1/2+1/3+1/4+1/5+....1/n O(logn) 调和级数 
	// 1/2   1/4 1/4 1/8 1/8 1/8 1/8 
	
	puts("");
	for(int i=2;i<=n;i++){
		if(!not_prime[i]){
			printf("%d ",i);
			for(int j=i;j*i<=n;j++){// O(nloglogn)
				not_prime[j*i]=true;
			}
		}
	}
	puts("");
	
	
	//O(n)
	// mindiv 一个数字的最小素因子
	// prime  所有的素数 
	// N = p1^a1 p2^a2 p3^a3 .... 
	// mindiv[N] = p1 
	for(int i=2;i<=n;i++){
		// 发现素数 
		if(!mindiv[i]){
			mindiv[i]=i;
			prime[tot++]=i;
			printf("%d ",i);
			// 3)
		}
		// 筛合数 
		//i= 7*9  prime[j] 2,3,5,7 
		for(int j=0;prime[j]*i<=n;j++){
			mindiv[prime[j]*i]=prime[j]; // prime[j]<=mindiv[i]
			//printf("# %d=%d*%d\n",i*prime[j],i,prime[j]);
			if(prime[j]==mindiv[i]){
				// 2)
				break;
			}
			// 1)
		}
	}
	// N = p1^a1 p2^a2 p3^a3 ....   N/p1
	// 1) a1 == 1 i= p2^a2 p3^a3 .... prime[j] = p1
	// 2) a1 >1  i=p1^(a1-1) p2^a2 p3^a3 .... prime[j] = p1
	// O(n)
	
	
	
	
	
	
	return 0;
}
