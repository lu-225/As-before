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
				//d[i][j]�������i��j�����·���� 
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	//��ʼ��������������Ϊ0x3f,��δ��ͨ
	memset(d,0x3f,sizeof(d));
	//ͬһ����ľ���Ϊ0 
	for(int i=1;i<=n;i++)d[i][i]=0;
	//�ڽӾ����ͼ 
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		d[u][v]=min(d[u][v],w);
	}
	Floyd();
	//�������֮�����̾������ 
	printf("����֮�����̾������\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
} 
