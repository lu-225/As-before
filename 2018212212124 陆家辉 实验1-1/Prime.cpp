#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[3010][3010],d[3030],n,m,ans;
bool v[3010];
void prime(){
	memset(d,0x3f,sizeof(d));//��ʼ��d����,Ĭ��Ϊ����� 
	memset(v,0,sizeof(v));//��ʼ��v����Ϊ0,�����е�δ����ͨ 
	d[1]=0;//�ض��ӵ�1��ʼ�γ���С������ 
	for(int i=1;i<n;i++){
		int x=0;
		for(int j=1;j<=n;j++){
			if(!v[j]&&(x==0||d[j]<d[x])){
				x=j;
			}
			//��δ����ͨ���ҵ���СȨֵ��,��Ϊx 
		}
		v[x]=1;//��ǵ��Ѿ��߹� 
		for(int y=1;y<=n;y++){ 
			if(!v[y])d[y]=min(d[y],a[x][y]);
			//����õ�δ��ͨ,�����d����
		}
	}
	for(int i=2;i<=n;i++){//Ȩֵ��� 
		ans+=d[i];
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int i=1;i<=m;i++){//�ڽӾ����ͼ 
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=a[v][u]=min(a[u][v],w);
	}
	prime();
	printf("��С������Ȩֵ��Ϊ��%d\n",ans); 
}
