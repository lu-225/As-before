#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=1010;
priority_queue <int,vector<int>,greater<int> > q;
//ÉýÐò¶ÓÁÐ£¬Ð¡¶¥¶Ñ
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		q.push(x); 
	}
	int ans=0;
	n--;
	while(n--){
		int x=q.top();
		q.pop();
		int y=q.top();
		q.pop();
		int t=x+y;
		ans+=t;
		q.push(t);
	}
	printf("%d\n",ans);
}
