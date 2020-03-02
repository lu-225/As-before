#include<cstdio> 
#include<algorithm>
using namespace std;
struct Edge{
    int u,v,w;
}edge[200005];
int fa[5005],n,m,ans,cnt;
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
//快排的依据（按边权排序）
int find(int x){
    return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
//并查集循环实现模板，及路径压缩
void kruskal(){
    sort(edge,edge+m,cmp);
    //将边的权值排序
    for(int i=0;i<m;i++){
    	int eu=find(edge[i].u);
        int ev=find(edge[i].v);
        if(eu==ev){
            continue;
        }
        //若出现两个点已经联通了，则说明这一条边不需要了
        ans+=edge[i].w;
        //将此边权计入答案
        fa[ev]=eu;
        //将eu、ev合并
        if(++cnt==n-1){
            break;
        }
        //循环结束条件，即边数为点数减一时
    }
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    //初始化并查集
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    kruskal();
    printf("最小生成树权值和：%d\n",ans);
    return 0;
}

