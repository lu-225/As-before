#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int maxn=1e5+10;
struct node{
	double x,y;
}a[maxn],b[maxn];
int n;
int cmpx(node &a,node &b){
	return a.x<b.x;
} 
int cmpy(node &a,node &b){
	return a.y<b.y;
}
double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double minDist(int l,int r){
	if(r-l==1){
		return dis(a[l],a[r]);
	} 
	if(r-l==2){
		return min(dis(a[l],a[l+1]),dis(a[l+1],a[r]));
	}
	int mid=(l+r)>>1;
	double d=min(minDist(l,mid),minDist(mid+1,r));
	int k=0;
	for(int i=l;i<=r;i++){
		if(fabs(a[i].x-a[mid].x)<=d){
			b[k++]=a[i];
		}
	}
	sort(b,b+k,cmpy);
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k&&j<i+6;j++){
			d=min(d,dis(b[i],b[j]));
		}	
	}
	return d;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&a[i].x,&a[i].y);
	}
	sort(a+1,a+1+n,cmpx);
	printf("%f\n",minDist(1,n));
}

