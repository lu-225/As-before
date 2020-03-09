#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int d[maxn][maxn];
int n,m;
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				//d[i][j]保存的是i到j的最短路长度 
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	//初始化各个顶点间距离为0x3f,即未连通
	memset(d,0x3f,sizeof(d));
	//同一个点的距离为0 
	for(int i=1;i<=n;i++)d[i][i]=0;
	//邻接矩阵存图 
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		d[u][v]=min(d[u][v],w);
	}
	Floyd();
	//输出顶点之间的最短距离矩阵 
	printf("顶点之间的最短距离矩阵：\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
} 
