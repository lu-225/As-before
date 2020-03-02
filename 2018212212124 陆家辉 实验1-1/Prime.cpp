#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[3010][3010],d[3030],n,m,ans;
bool v[3010];
void prime(){
	memset(d,0x3f,sizeof(d));//初始化d数组,默认为无穷大 
	memset(v,0,sizeof(v));//初始化v数组为0,即所有点未被连通 
	d[1]=0;//特定从点1开始形成最小生成树 
	for(int i=1;i<n;i++){
		int x=0;
		for(int j=1;j<=n;j++){
			if(!v[j]&&(x==0||d[j]<d[x])){
				x=j;
			}
			//点未被连通且找到最小权值边,记为x 
		}
		v[x]=1;//标记点已经走过 
		for(int y=1;y<=n;y++){ 
			if(!v[y])d[y]=min(d[y],a[x][y]);
			//如果该点未连通,则更新d数组
		}
	}
	for(int i=2;i<=n;i++){//权值相加 
		ans+=d[i];
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int i=1;i<=m;i++){//邻接矩阵存图 
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=a[v][u]=min(a[u][v],w);
	}
	prime();
	printf("最小生成树权值和为：%d\n",ans); 
}
