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
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(T[mid]<x){
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		if(T[l]==x) printf("%d���±�Ϊ%d\n",x,l);
		else printf("%d���±�Ϊ0\n",x);
	}
	return 0;
}
