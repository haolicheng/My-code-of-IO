struct edge{
	int v;//到达的点
	int next;//下一条边的编号
	int cost;//边权
}e[M];
void add(int x,int y/*,int z*/){
	++num;
	v[num]=y;
	//cost[num]=z;//边权(如果有)
	next[num]=head[x];
	head[x]=num;
}
//增加一条边
for(int i=head[x];i!=0;i=next[i])


void dfs(int u){//邻接矩阵
	for(int i=1;i<=n;i++)
		if(a[u][i]!=0){
		dfs(i);
		...
	}
}
void dfs(int u){//邻接表
	for(int i=head[u];i;i=next[i]){
		dfs(v[i]);
		...
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		add(x,y);
		a[x][y]+=1;//表示x->y有边
	}
	dfs(1);
}

void bfs(){
	int t=0,w=1;
	q[1]=1;
	//q: 1 / 2 5 6 / 3 4 ... / ... /
	//u=6 t=4 w=6
	while(t<w){
		int u=q[++t];
		for(int i=1;i<=n;i++)
			if(a[u][i]){
				q[++w]=i;
			}

		for(int i=head[u];i;i=e[i].next)
			q[++w]=e[i].v;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		
		add(x,y);
		
		a[x][y]+=1;
	}
	bfs();
}

//dijkstra 入门经典P359

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)g[i][j]=1000000000;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		
		add(x,y,z);
		
		g[x][y]=min(g[x][y],z);
	}
	//读入操作
	for(int i=1;i<=n;i++)dis[i]=1000000000;
	dis[1]=0;
	memset(vis,0,sizeof(vis));//vis表示最小值是否固定
	for(int i=1;i<=n;i++){
		int t=-1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0 && (t==-1 || dis[j]<dis[t]))t=j;
		vis[t]=1;
		for(int j=1;j<=n;j++)
			if(vis[j]==0)		
				dis[j]=min(dis[j],dis[t]+g[t][j]);
				//松弛操作
	}
}



//spfa
struct edge{
	int v;//到达的点
	int next;//下一条边的编号
	int cost;//边权
}e[M];
void add(int x,int y,int z){
	++num;
	e[num].v=y;
	e[num].cost=z;
	e[num].next=head[x];
	head[x]=num;
}
bool vis[N];//点i是否在队列当中
void spfa(){
	for(int i=1;i<=n;i++)dis[i]=1000000000;
	dis[1]=0;
	int t=0,w=1;
	vis[1]=1;
	q[1]=1;
	while(t<w){
		int u=q[++t];
		for(int i=head[u];i;i=e[i].next)
			if(dis[e[i].v]>dis[u]+e[i].cost){
				dis[e[i].v]=dis[u]+e[i].cost;
				if(vis[e[i].v]==0){
					vis[e[i].v]=1;
					q[++w]=e[i].v;
				}
			}
		vis[u]=0;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)g[i][j]=1000000000;

	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		
		add(x,y,z);
		
		g[x][y]=min(g[x][y],z);
	}
	spfa();
	
}
//floyd
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)g[i][j]=1000000000;
			else g[i][j]=0;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		g[x][y]=min(g[x][y],z);
	}
for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

	g[i][j]//从i到j的最短路径长度


}

ll read(){
	ll ans=0;
	char ch=getchar(),last=' ';
	while(ch<'0' || ch>'9'){
		last=ch;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	if(last=='-')ans=-ans;
	return ans;
}//读入优化


//kruskal
struct node{
	int x,y,z;
}e[M];
bool cmp(node a,node b){
	return a.z<b.z;
}
int find(int x){//找到x所在的根
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);//压缩路径
}//并查集	找到祖先节点

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		e[i].x=read();
		e[i].y=read();
		e[i].z=read();
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	/*for(int i=1;i<=m;i++)
		if(e[i].x和e[i].y不连通){
			连接e[i].x和e[i].y
			ans+=e[i].z;
		}*/
	for(int i=1;i<=m;i++)
		if(find(e[i].x)!=find(e[i].y)){//连通是祖先节点的连通
			int fx=find(e[i].x);
			int fy=find(e[i].y);
			fa[fx]=fy;
			ans+=e[i].z;
		}
}

-------------下午---------------


//拓扑排序
int main(){
	cin>>n>>m;
	
	for(inti=1;i<=m;i++){
		cin>>x>>y;
		
		add(x,y);
		du[y]++;
		//g[x][y]=1;
	}

	int t=0,w=0;
	for(inti=1;i<=n;i++)
		if(du[i]==0)q[++w]=i;

	while(t<w){
		int u=q[++t];
		for(inti=head[u];i;i=e[i].next){
			du[e[i].v]--;
			if(du[e[i].v]==0)q[++w]=e[i].v;
		}
	}
}

//倍增lca
void dfs(int u){ //2^i
	for(inti=1;(1<<i)<dep[u];i++){
		int t=fa[u][i-1];
		fa[u][i]=fa[ t ][i-1];
	}

	for(inti=head[u];i;i=e[i].next){
		dep[e[i].v]=dep[u]+1;
		fa[e[i].v][0]=u;

		dfs(e[i].v);
	}
}
intlca(intx,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(inti=20;i>=0;i--)
		if(dep[x]-(1<<i)>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(inti=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
int main(){
	cin>>n;
	
	for(inti=1;i<n;i++)
		add(read(),read());
	dep[1]=0;
	dfs(1);
}
//树链剖分
void dfs1(int u){
	size[u]=1;
	for(inti=head[u];i;i=e[i].next){
		dep[e[i].v]=dep[u]+1;
		fa[e[i].v]=u;
		dfs1(e[i].v);
		size[u]+=size[e[i].v];
		if(size[e[i].v]>size[MaxSon[u]])
			MaxSon[u]=e[i].v;
	}
}
void dfs2(int u){
	for(inti=head[u];i;i=e[i].next){
		if(MaxSon[u]==e[i].v)
			path[e[i].v]=path[u];
		else path[e[i].v]=e[i].v;
		dfs2(e[i].v);
	}
}
intlca(intx,int y){
	while(path[x]!=path[y])
	{
		if(dep[path[x]]>dep[path[y]])
			x=fa[path[x]];
		else y=fa[path[y]];
	}
	if(dep[x]<dep[y])return x;
	else return y;
}
int main(){
	cin>>n;
	
	for(inti=1;i<n;i++)
		add(read(),read());
	dep[1]=0;
	dfs1(1);
	path[1]=1;
	dfs2(1);

}
