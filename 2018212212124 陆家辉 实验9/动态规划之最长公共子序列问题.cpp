#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1010;
int dp[maxn][maxn];
char s1[maxn],s2[maxn];
int b[maxn][maxn];
//1删除两个，2删除x,3删除y 
void print(int i,int j){
	if(i==0||j==0)return ;
	if(b[i][j]==1){
		print(i-1,j-1);
		printf("%c",s1[i]);
	}
	else if(b[i][j]==2){
		print(i-1,j);
	}
	else if(b[i][j]==3){
		print(i,j-1);
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	memset(b,0,sizeof(b));
	scanf("%s %s",s1+1,s2+1);
	int p1=strlen(s1+1);
	int p2=strlen(s2+1);
	for(int i=0;i<=p1;i++)dp[i][0]=0;
	for(int i=0;i<=p2;i++)dp[0][i]=0;
	for(int i=1;i<=p1;i++){
		for(int j=1;j<=p2;j++){
			if(s1[i]==s2[j]){
				dp[i][j]=dp[i-1][j-1]+1;
				b[i][j]=1;
			}
			else{
				if(dp[i-1][j]>dp[i][j-1]){
					dp[i][j]=dp[i-1][j];
					b[i][j]=2;
				} 
				else{
					dp[i][j]=dp[i][j-1];
					b[i][j]=3;
				}
			}
		}
	}
	puts("得到dp数组如下：");
	for(int i=0;i<=p1;i++){
		for(int j=0;j<=p2;j++){
			printf("%d ",dp[i][j]);
		}
		puts("");
	}
	printf("X和Y序列的最长公共子序列长度为：%d\n",dp[p1][p2]);
	print(p1,p2);
} 
