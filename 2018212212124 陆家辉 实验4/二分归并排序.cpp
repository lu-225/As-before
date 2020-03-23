#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010];//ԭ���� 
int b[1010];
//����ÿ��������������� 
void Merge(int l,int mid,int r){
	int i=l,j=mid+1,k=l;
	//һ��һ���бȽ����������� 
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			b[k++]=a[i++];
		}
		else{
			b[k++]=a[j++];
		}
	}
	//��������δ�������� 
	while(i<=mid)b[k++]=a[i++];
	while(j<=r)b[k++]=a[j++];
	for(i=l;i<=r;i++){
		a[i]=b[i];
	}
}
//�õݹ�ʵ�ֻ��֡��ϲ����� 
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
	printf("���ֹ鲢����֮ǰ������Ϊ��"); 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		printf("%d ",a[i]);
	}
	MergeSort(1,n);
	printf("\n���ֹ鲢����֮�������Ϊ��");
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n"); 
}
