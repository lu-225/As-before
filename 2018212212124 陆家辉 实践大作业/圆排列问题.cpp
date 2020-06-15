#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath> 
using namespace std;
const int inf = 0x3f3f3f3f;
int n=3;
double x[110];//每个圆的横坐标 
double r[110];//每个圆的半径
double minnr[110];//最短圆序列的半径
double minn=inf;//存放最短圆排列长度
double calCenter(int k){//计算圆心坐标
    double temp=0;
    for(int i=1;i<k;i++){
        double c=x[i]+2.0*sqrt(r[i]*r[k]);
        temp=max(c,temp);
    }
    return temp;
}
void calLength(){//计算圆排列的总长度
    double low=inf,high=0;
    for(int i=1;i<=n;i++){
        if(x[i]-r[i]<low){
            low=x[i]-r[i];
        }
        if(x[i]+r[i]>high){
            high=x[i]+r[i];
        }
    }
    if(high-low<minn){
        minn=high-low;
        for(int i=1;i<=n;i++){
            minnr[i]=r[i];
        }
    }
}
void backtrack(int k){ //查找圆排列
    if(k>n){//结束排列，计算排列长度 
        calLength();
        return ;
    }
    for(int i=k;i<=n;i++){
        swap(r[k],r[i]);
        double center=calCenter(k);//获取圆当前的横坐标
        if(center+r[1]+r[k]<minn){//剪枝操作 
        	x[k]=center;
        	backtrack(k+1);//向下继续搜索
		}
        swap(r[k],r[i]);//回溯
    }
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    scanf("%d",&n);
    printf("给出%d圆，每个圆的半径分别为：",n);
    for(int i=1;i<=n;i++){
    	scanf("%lf",&r[i]);
    	printf("%f ",r[i]);
	}
	puts("");
    backtrack(1);
    printf("最小圆排列长度为：%f\n",minn);
    printf("最短圆序列:\n");
    for(int i=1;i<=n;i++){//输出最短圆序列
        printf("%f ",minnr[i]);
    }
    puts("");
    return 0;
}
