#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1010;
const int inf=0x3f3f3f3f; 
int dp[maxn][maxn];
int p[maxn];
int s[maxn][maxn];
void print(int i,int j){
	if(i!=j){
     	printf("(");
		print(i,s[i][j]);
		print(s[i][j]+1,j);
		printf(")");	
	}
	else{
		printf("A%d",i);
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	memset(dp,0,sizeof(dp));
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1;
			dp[i][j]=inf;
			for(int k=i;k<=j-1;k++){
				int q=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<dp[i][j]){
					dp[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("最优乘法次序为：\n"); 
	print(1,n-1);
	printf("\n乘积为%d\n",dp[1][n-1]);
	
} 
