#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int a[maxn][maxn],d[maxn];
bool v[maxn];
int n,m;
void dijkstra(){
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));//节点标记 
	//默认起点为1号顶点 
	d[1]=0;
	for(int i=1;i<n;i++){
		int x=0;
		//找到未标记节点中dist最小的 
		for(int j=1;j<=n;j++){
			if(!v[j]&&(x==0||d[j]<d[x])){
				x=j;
			}
		}
		v[x]=1;
		//用全局最小值点x更新其他节点 
		for(int y=1;y<=n;y++){
			d[y]=min(d[y],d[x]+a[x][y]);
		}
	}
} 
int main(){
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	//初始化各个顶点间距离为0x3f,即未连通
	memset(a,0x3f,sizeof(a));
	//同一个点的距离为0 
	for(int i=1;i<=n;i++)a[i][i]=0;
	//邻接矩阵存图
	for(int i=1;i<=m;i++){
		char c1,c2;
		int u,v,w;
		scanf("%c %c %d",&c1,&c2,&w);
		getchar();
		u=c1-'a'+1,v=c2-'a'+1;
		a[u][v]=min(a[u][v],w);
	}
	dijkstra();
	printf("由顶点a到顶点h的最短路径长度为：%d\n",d[n]);
}
