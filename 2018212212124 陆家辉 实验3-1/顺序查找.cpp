#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T[1010];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	//����n���ź������ 
	for(int i=1;i<=n;i++){
		scanf("%d",&T[i]);
	}
	int x;
	//���ѯ�� 
	while(scanf("%d",&x)!=EOF){
		int j=0;
		for(int i=1;i<=n;i++){
			if(x==T[i]){
				//�ҵ�x��¼�±꣬���˳�ѭ�� 
				j=i;
				break;
			}
		}
		printf("%d���±�Ϊ%d\n",x,j);
	}
	return 0;
}
