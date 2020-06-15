#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath> 
using namespace std;
const int inf = 0x3f3f3f3f;
int n=3;
double x[110];//ÿ��Բ�ĺ����� 
double r[110];//ÿ��Բ�İ뾶
double minnr[110];//���Բ���еİ뾶
double minn=inf;//������Բ���г���
double calCenter(int k){//����Բ������
    double temp=0;
    for(int i=1;i<k;i++){
        double c=x[i]+2.0*sqrt(r[i]*r[k]);
        temp=max(c,temp);
    }
    return temp;
}
void calLength(){//����Բ���е��ܳ���
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
void backtrack(int k){ //����Բ����
    if(k>n){//�������У��������г��� 
        calLength();
        return ;
    }
    for(int i=k;i<=n;i++){
        swap(r[k],r[i]);
        double center=calCenter(k);//��ȡԲ��ǰ�ĺ�����
        if(center+r[1]+r[k]<minn){//��֦���� 
        	x[k]=center;
        	backtrack(k+1);//���¼�������
		}
        swap(r[k],r[i]);//����
    }
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    scanf("%d",&n);
    printf("����%dԲ��ÿ��Բ�İ뾶�ֱ�Ϊ��",n);
    for(int i=1;i<=n;i++){
    	scanf("%lf",&r[i]);
    	printf("%f ",r[i]);
	}
	puts("");
    backtrack(1);
    printf("��СԲ���г���Ϊ��%f\n",minn);
    printf("���Բ����:\n");
    for(int i=1;i<=n;i++){//������Բ����
        printf("%f ",minnr[i]);
    }
    puts("");
    return 0;
}
