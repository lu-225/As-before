#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010];//原数组 
int b[1010];
//对于每个子问题进行排序 
void Merge(int l,int mid,int r){
	int i=l,j=mid+1,k=l;
	//一对一进行比较完成排序操作 
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			b[k++]=a[i++];
		}
		else{
			b[k++]=a[j++];
		}
	}
	//若还有数未进行排序 
	while(i<=mid)b[k++]=a[i++];
	while(j<=r)b[k++]=a[j++];
	for(i=l;i<=r;i++){
		a[i]=b[i];
	}
}
//用递归实现划分、合并操作 
void MergeSort(int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		MergeSort(l,mid);
		MergeSort(mid+1,r);
		Merge(l,mid,r); 
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	printf("二分归并排序之前的数组为："); 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		printf("%d ",a[i]);
	}
	MergeSort(1,n);
	printf("\n二分归并排序之后的数组为：");
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n"); 
}
