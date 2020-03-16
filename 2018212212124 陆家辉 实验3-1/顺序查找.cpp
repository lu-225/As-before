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
	//输入n个排好序的数 
	for(int i=1;i<=n;i++){
		scanf("%d",&T[i]);
	}
	int x;
	//多次询问 
	while(scanf("%d",&x)!=EOF){
		int j=0;
		for(int i=1;i<=n;i++){
			if(x==T[i]){
				//找到x记录下标，并退出循环 
				j=i;
				break;
			}
		}
		printf("%d的下标为%d\n",x,j);
	}
	return 0;
}
