for (int i=1; i<=n; i++)
  if (i%3==0) sum++;
cout<<sum;


1s   10^8   5~10s  

3  6   9  12

1~3   1
1~4   1
1~5   1
1~6   2
  7   2
  8   2
  9   3

cout<<n/3;

3~6  2   4/3
2~7  2
1~8  2   8/3


l~r  ->  (1~r)-(1~l-1)
          r/3   (l-1)/3

cout<<r/3-(l-1)/3;

r/3+r/5+r/7-r/15-r/21-r/35+r/105-
((l-1)/3+(l-1)/5+ ... )

int work(int r)
{
  return r/3+r/5+r/7-r/15-r/21-r/35+r/105;
}

cin>>l>>r;
cout<<work(r)-work(l-1);

for (int i=0; i<=100; i++)
  for (int j=0; j<=100; j++)
    for (int k=0; k<=100; k+=3)
    if (i+j+k==100 && 5*i+3*j+k/3==100)
      sum++;

cout<<sum;


cin>>n; F=true;
for (int i=2; i<=int(sqrt(n)); i++)
  if (n%i==0) F=false;
if (F) cout<<"yes"; else cout<<"no";


cin>>n;
f[i] i这个数字需要多少火柴棒
f[0]=6; f[1]=2; f[2]=5; f[3]=5; f[4]=4;
f[5]=5; f[6]=6; f[7]=3; f[8]=7; f[9]=6;

for (int i=10; i<=20000; i++)
  f[i]=f[i/10]+f[i%10];  

for (int A=0; A<=9999; A++)
  for (int B=0; B<=9999; B++)
      if (f[A]+f[B]+f[A+B]+4==n) sum++;
cout<<sum;


abc

abc.in
1 2

abc.out
3

上传abc.cpp  从 abc.in中得到输入文件， 输出到abc.out

快排，归排，堆排  nlgn


#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
int cmp(int i,int j){return i>j;}
int main()
{
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1,cmp); 
	for (int i=1; i<=n; i++) cout<<a[i]<<' ';
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
struct node {int a,b;} t[100005];
int cmp(node i,node j) {return i.a<j.a || i.a==j.a && i.b<j.b;}
int main()
{
	cin>>n;
	for (int i=1; i<=n; i++) cin>>t[i].a>>t[i].b;
	sort(t+1,t+n+1,cmp); 
	for (int i=1; i<=n; i++) cout<<t[i].a<<' '<<t[i].b<<endl;
	return 0;
}

1 2 2     1^1+2^2 = 5
1 2 2 2 3   1  3  1  =  11


int f[1000000000];

f[i]  i这个数字出现了几次
cin>>n;
for (int i=1; i<=n; i++) cin>>A[i];

... 离散化  
	for (int i=1; i<=n; i++) {t[i].x=A[i]; t[i].y=i;}
	sort(t+1,t+n+1,cmp);
	for (int i=1; i<=n; i++) while (!A[t[i].y]==t[i].x);
	A[t[i].y] 一定等于 t[i].x
	for (int i=1; i<=n; i++)
	{
		if (i==1 || t[i].x!=t[i-1].x) now++;
		A[t[i].y]=now;
	}
...

for (int i=1; i<=n; i++) f[A[i]]++;
for (int i=1; i<=n; i++)
  ans+=f[i]*f[i];
cout<<ans;

1 3 100000 3


1 2 3 2

g[1]=1  g[2]=3  g[3]=100000

3 5 1 6

2 3 1 4

g[1]=1  g[2]=3  g[3]=5  g[4]=6

cin>>n;
for (i=1; i<=n; i++) cin>>A[i];


a  3 3 1
t[1].x=3  t[1].y=1
t[2].x=3  t[2].y=2
t[3].x=1  t[3].y=3

t[1].x=1  t[1].y=3  -> a[3]=1
t[2].x=3  t[2].y=1  -> a[1]=2
t[3].x=3  t[3].y=2  -> a[2]=2


1 3 3 4 5

1 2 2 3 4

Sample input
5
2 3 1 5 4
3
1 3
2 5
4 5

Sample output
6
13
9

s[i] 1~i的和
for (i=1; i<=n; i++) s[i]=s[i-1]+a[i];
for (i=1; i<=m; i++)
{
  cin>>l>>r;
  cout<<s[r]-s[l-1]<<endl;
}

i=1  s[1]=a[1]
i=2  s[2]=s[1]+a[2]=a[1]+a[2]
i=3  s[3]=s[2]+a[3]=a[1]+a[2]+a[3]
 ...

for (i=1; i<=n; i++)
  for (j=1; j<=n; j++)
   ...

O(n^2)

for (i=1; i<=n; i++)
  for (j=1; j<=i; j++)
   ..

O(n^2)

for (i=1; i<=n; i++)
  for (j=1; j<=n; j++)
    ...

for (i=1; i<=n; i++)
  for (j=1; j<=i; j++)
    ...

O(n^2)

for (i=1; i<=n; i++)
  for (j=1; j<=n; j++)
    ..
for (i=1; i<=m; i++)
  ...
O(n^2+m) 

for (i=1; i<=n; i++)
  for (j=1; j<=n; j++)
    ...
for (i=1; i<=n; i++)
    ...
O(n^2)

3 3
1 2 3
3 2 1
2 2 2
3
1 1 2 2
1 2 2 3
1 1 3 3

8
8
18

for (i=1; i<=n; i++)
  for (j=1; j<=n; j++)
    f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
f[i][j]  左上角在(1,1)，右下角在(i,j)的和是多少
for (i=1; i<=m; i++)
{
  cin>>x>>y>>X>>Y;
  cout<<f[X][Y]-f[x-1][Y]-f[X][y-1]+f[x-1][y-1]<<endl;
}
二维前缀和


4
2 3 1 4
3
1 3 2  //[1,3]+=2
2 4 1  //[2,4]+=1
1 4 3  //[1,4]+=3


7 9 7 8

cin>>n;
for (i=1; i<=n; i++) cin>>a[i];
cin>>m;
for (i=1; i<=m; i++)
{
  cin>>A>>B>>C;  // [A,B]+=C
  for (j=A; j<=B; j++) a[j]+=C;
}
for (i=1; i<=n; i++) cout<<a[i]<<' ';

cin>>n;
for (i=1; i<=n; i++) cin>>a[i];
cin>>m;
for (i=1; i<=m; i++)
{
  cin>>A>>B>>C;
  f[A]+=C; f[B+1]-=C;
}
for (i=1; i<=n; i++) f[i]=f[i-1]+f[i];
for (i=1; i<=n; i++) cout<<a[i]+f[i]<<' ';


f[1]=a[1]
f[2]=a[2]-a[1]  ->  f[1]+f[2] = a[2]
f[3]=a[3]-a[2]  ->  f[1]+f[2]+f[3]  =  a[3]
                    f[1]+f[2]+f[3]+f[4] = a[4] ...  a是f的前缀和

前缀和  差值  

cin  5W   1s
scanf("%d",&a[i]);  100W

cout  5W  1s
printf("%d",a[i]) 100W

int   4
long long  8
short  2
char 1
bool 1

MEMORY LIMITED 128MB   130MB   0分

128*1024*1024/4 这么多个int型  3000W
                    long long  1500W

TIME LIMITED  1s   1亿

for (i=1; i<=n; i++)
  for (j=1; j<=m; j++)
    ...

n=5W  m=5W  O(nm)  50分   70分  70%  n,m<=1000
O(n*m)  n=10000  m=100000    10s

O(n^2+m)  n=1000  m=1000000  

CE MLE 找不到文件

3 3
-2 1 -3
2 2 -4
-2 1 2

4

s[i][j]  (1,1)~(i,j)的和
for (i=1; i<=n; i++)
  for (j=1; j<=n; j++)
    s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
for (i=1; i<=n; i++)
  for (j=1; j<=n; j++)
    for (k=i; k<=n; k++)
      for (l=j; l<=n; l++)
      //(i,j)~(k,l)
      {
         sum=s[k][l]-s[i-1][l]-s[k][j-1]+s[i-1][j-1];
	 ans=max(ans,sum);
      }
cout<<ans;

区间和  矩阵和    并且里面的元素不会被修改   --->  前缀和来加速

for (L=1; L<=n; L++)
  for (R=L; R<=n; R++)
    ans=max(ans,s[R]-s[L-1]);

[L,R] ->  s[R]-s[L-1]

最大的s[R] 和最小的s[L-1]   L-1<R
MIN=0;  MIN表示当前最小的s[L-1]
for (R=1; R<=n; R++)  已知s[R]，找最小的s[L-1]
{
  MIN=min(MIN,s[R-1]);
  ans=max(ans,s[R]-MIN);
}

前缀最小值
for (i=1; i<=n; i++) s[i]=s[i-1]+a[i];
MIN[0]=s[0];
for (i=1; i<=n; i++) MIN[i]=min(MIN[i-1],s[i]);
for (R=1; R<=n; R++) ans=max(ans,s[R]-MIN[R-1]); 


for (i=1; i<=n; i++)
{
  sum+=a[i];
  if (sum<0) sum=0;
  ans=max(ans,sum);
}
f[i][j] 第一行到第i行关于第j列的和

for (i=1; i<=n; i++)
  for (j=1; j<=n; j++)
    f[i][j]=f[i-1][j]+a[i][j];
for (i=1; i<=n; i++)
  for (j=i; j<=n; j++)
  {
    for (k=1; k<=n; k++) b[k]=f[j][k]-f[i-1][k]; // 1~j  -  1~(i-1)

    for (k=1; k<=n; k++) s[k]=s[k-1]+b[i];
    MIN[0]=s[0];
    for (k=1; k<=n; k++) MIN[i]=min(MIN[k-1],s[k]);
    for (R=1; R<=n; R++) ans=max(ans,s[R]-MIN[R-1]);
  }
    