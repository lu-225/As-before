#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=1e5+10;
vector<int>s;
int n,k;
void select(vector<int>s,int n,int k) {
	vector<int>t,m;
	t=s;
	//ÿ5��Ԫ�ط�Ϊһ�� ,����λ����������m 
	int len=5;
	for(int i=0;i<n;i+=5){
		if(n-i+1<len)len=n-i+1;
		sort(t.begin()+i,t.begin()+i+len);
		m.push_back(t[i+(len-1)/2]);
	}
	//��ÿ����λ���ļ�����ѡȡ��λ��m*
	sort(m.begin(),m.end());
	int sum=m.size();
	int mmid=m[(sum-1)/2];	
	vector<int>s1,s2;
	for(int i=0;i<n;i+=5){
		if(n-i<5){
			for(int j=i;j<n;j++){
				if(t[j]>mmid)s2.push_back(t[j]);
				else s1.push_back(t[j]);
			}
			break;
		}
		if(t[i+2]<mmid){
			for(int j=i;j<=i+2;j++){
				s1.push_back(t[j]);
			}
			for(int j=i+3;j<i+5;j++){
				if(t[j]>mmid)s2.push_back(t[j]);
				else  s1.push_back(t[j]);
			}
		}
		else if(t[i+2]>mmid){
			for(int j=i;j<=i+2;j++){
				if(t[j]>mmid)s2.push_back(t[j]);
				else  s1.push_back(t[j]);
			}
			for(int j=i+3;j<i+5;j++){
				s2.push_back(t[j]);
			}
		}
		else{
			for(int j=i;j<i+2;j++)s1.push_back(t[j]);
			for(int j=i+3;j<i+5;j++)s2.push_back(t[j]);
		}
	}
	int sum1=s1.size(),sum2=s2.size();
	if (k==sum1+1) {
		printf("%d\n",mmid);
		return;
	}
	else if (k<=sum1){
		select(s1,sum1,k);
	}
	else{
		select(s2,sum2,k-sum1-1);
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	int x;
    	scanf("%d",&x);
    	s.push_back(x);
	}
	printf("%d�����ֱ�Ϊ:",n);
	for(int i=0;i<n;i++){
		printf("%d ",s[i]);
	} 
	printf("\n");
	scanf("%d",&k);
	printf("��%dСԪ��Ϊ:",k);
    select(s,n,k);
} 



