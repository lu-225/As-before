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
	memset(v,0,sizeof(v));//�ڵ��� 
	//Ĭ�����Ϊ1�Ŷ��� 
	d[1]=0;
	for(int i=1;i<n;i++){
		int x=0;
		//�ҵ�δ��ǽڵ���dist��С�� 
		for(int j=1;j<=n;j++){
			if(!v[j]&&(x==0||d[j]<d[x])){
				x=j;
			}
		}
		v[x]=1;
		//��ȫ����Сֵ��x���������ڵ� 
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
	//��ʼ��������������Ϊ0x3f,��δ��ͨ
	memset(a,0x3f,sizeof(a));
	//ͬһ����ľ���Ϊ0 
	for(int i=1;i<=n;i++)a[i][i]=0;
	//�ڽӾ����ͼ
	for(int i=1;i<=m;i++){
		char c1,c2;
		int u,v,w;
		scanf("%c %c %d",&c1,&c2,&w);
		getchar();
		u=c1-'a'+1,v=c2-'a'+1;
		a[u][v]=min(a[u][v],w);
	}
	dijkstra();
	printf("�ɶ���a������h�����·������Ϊ��%d\n",d[n]);
}
