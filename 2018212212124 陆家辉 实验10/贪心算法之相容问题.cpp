#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1010;
struct node{
	int i;
	int s;
	int f;
}a[maxn];
int cmp(const node &a,const node &b){
	return a.f<b.f;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].s,&a[i].f);
		a[i].i=i;
	}
	sort(a+1,a+1+n,cmp);
	printf("选择的活动：\n编号：%d , %d--%d\n",a[1].i,a[1].s,a[1].f);
	int ans=1;
	int t=1;
	for(int i=2;i<=n;i++){
		if(a[i].s>=a[t].f){
			ans++;
			t=i;
			printf("编号：%d , %d--%d\n",a[t].i,a[t].s,a[t].f);
		}
	}
	printf("最大活动数量为：%d\n",ans);
}
