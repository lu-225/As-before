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
//���ŵ����ݣ�����Ȩ����
int find(int x){
    return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
//���鼯ѭ��ʵ��ģ�壬��·��ѹ��
void kruskal(){
    sort(edge,edge+m,cmp);
    //���ߵ�Ȩֵ����
    for(int i=0;i<m;i++){
    	int eu=find(edge[i].u);
        int ev=find(edge[i].v);
        if(eu==ev){
            continue;
        }
        //�������������Ѿ���ͨ�ˣ���˵����һ���߲���Ҫ��
        ans+=edge[i].w;
        //���˱�Ȩ�����
        fa[ev]=eu;
        //��eu��ev�ϲ�
        if(++cnt==n-1){
            break;
        }
        //ѭ������������������Ϊ������һʱ
    }
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    //��ʼ�����鼯
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    kruskal();
    printf("��С������Ȩֵ�ͣ�%d\n",ans);
    return 0;
}

