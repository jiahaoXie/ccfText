////CCF 20170302 �ֵ���
//#include<iostream>
//using namespace std;
//int a[1000];
//
//int main()
//{
//	int i,n,k,count=0;
//	cin>>n>>k;
//	for(i=0;i<n;i++)
//		cin>>a[i];
//	int t=0;
//	for(i=0;i<n;i++)
//	{
//		if(i==n-1)
//		{
//			count++;
//			break;
//		}
//			
//		if(t+a[i]<k)	
//		{
//			t+=a[i];
//		} 			
//		else if(t+a[i]>=k)
//		{
//			t=0;
//			count++;
//		}
//	}
//	
//	cout<<count<<endl;
//	return 0;
// } 

//ccf 20170302 ѧ���Ŷ�
//˼· ������������ֱ�洢ѧ�� ��λ�ã�ע�����֮����ж�Ӧ��
//
#include<iostream>
using namespace std;

int value[1001];
int loc[1001];
int main()
{
	int n,m,p,q,flag,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		value[i]=i;
		loc[i]=i;
	}
	cin>>m;
	while(m--)		//ģ���ƶ�����   
	{
		cin>>p>>q;
		flag=(q>0)?1:-1;	//flag��ʾԪ��ֵ��ǰ�ƻ��������
	 
		for(i=loc[p];i!=loc[p]+q;i+=flag)	//����forѭ�����ж�ʱ ��Ϊq�����и� ���Բ���д��i<loc[p]+q  
		{
			value[i]=value[i+flag];
			loc[value[i]]=i;
			
		 } 
		value[loc[p]+q]=p;
		loc[p]+=q;
		
		
	}
	
	for(i=1;i<=n;i++)
		cout<<value[i]<<" ";
	cout<<endl; 
	return 0;
}
