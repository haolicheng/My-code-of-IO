#include<cstdio>
int a[250]={0,3,2,1}; // 1~200 ����
int c[250];
int t=0;
int main(){
	// �߾���int 
	int x=5;
	//      ��x 
	for(int i=200;i>0;i--){
		t=t*10+a[i];
		c[i]=t/x;
		t%=x;
	} 
	for(int i=10;i>=1;i--){
		printf("%d",c[i]);
	}
	return 0;	
}

