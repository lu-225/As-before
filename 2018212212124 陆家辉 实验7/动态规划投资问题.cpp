#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1010;
int n,m;
int f[maxn][maxn];
int val[maxn][maxn];
//x[i][j]表示在总共分配j万元时，取得最大收益时分配给第 i个 项目的钱数 
int x[maxn][maxn];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//n个项目,m投资 
	scanf("%d %d",&n,&m);
	for(int i=0;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&val[j][i]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=j;k++){
				if(f[i-1][j-k]+val[i][k]>f[i][j]){
					f[i][j]=f[i-1][j-k]+val[i][k];
					x[i][j]=k;
				}
			}
		}
	}
	printf("x   f[1][x]  x[1][x]  f[2][x]  x[2][x]  f[3][x]  x[3][x]  f[4][x]  x[4][x]  \n");
    for(int i=1;i<=m;++i){
    	printf("%d   ",i); 
        for(int j=1;j<=n;++j){
            printf("%8d %8d  ",f[j][i],x[j][i]);
        }
        printf("\n");
    }
	printf("最大收益为：%d\n",f[n][m]);
}
