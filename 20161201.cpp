//ccf 20161201 �м���
 
 //����һ ��������г�ʼ�� ��������Ч���� �����ҵ��м�����ɾ�������������м�����ͬ����ֵ Ȼ��Ƚ�left ��rightֵ�Ƿ���ȣ� 
//#include<iostream>
//using namespace std;
//int a[1000]; 
//int main()
//{
//	int n,i,j,mid,left,right,t;
//	cin>>n;
//	
//	for(i=0;i<n;i++)
//		cin>>a[i];
//	
//	for(i=0;i<n;i++)
//	{		//������Ԫ��ð�������С���� 
//		for(j=i+1;j<n;j++)
//			if(a[i]>a[j])
//			{
//				t=a[i];
//				a[i]=a[j];
//				a[j]=t;
//			}
//	}
////	t=a[n/2];	//ȡ����õ������� �м�ֵ���������м�ֵ��ͬ��Ԫ�� ��ͨ��������ǰ�ƶ�һλ��ȥ�����м�Ԫ����ͬ 
////	for(i=0;i<n;i++)
////	{
////		if(i!=n/2&&t==a[i])
////		{
////			for(j=i;j<n;j++)
////				a[j]=a[j+1];
////			n--; 
////		}
////	}
////	if(n%2==1)
////		cout<<a[n/2]<<endl;
////	else
////		cout<<-1<<endl; 
//
//	//sort(a,a+n);
//	mid=n/2;
//	left=mid;
//	right=n-mid-1;
//	for(i=mid-1;i>=0;i--)
//	{
//		if(a[i]==a[mid])
//			left--;
//		else 
//			break;
//	}
//	for(i=mid+1;i<n;i++)
//	{
//		if(a[i]==a[mid])
//			right--;
//		else 
//			break;
//	}
//	if(left==right)
//		cout<<a[mid]<<endl;
//	else 
//		cout<<-1<<endl;
//	return 0;
// } 

//������ ����STL �е�map����(key/value) keyΪ�����Ԫ�� valueΪ���ֵĴ��� ���õ�Ĭ�������map����������keyֵ��С�����������
#include<iostream>
#include<map>
using namespace std;
using std::map;

int main()
{
	map<int,int> m;
	map<int,int>::iterator it;
	int n,i,v;
	cin>>n;
	for(i=0;i<n;i++)
	{	//��ʼ�� ����map 
		cin>>v;
		m[v]++;
	}
//	for(it=m.begin();it!=m.end();it++)		//ͨ����������� ���Բ��Գ� �������map����������keyֵ��С�����������
//		cout<<it->first<<" "<<it->second<<endl;
//		 
	//�����м��� �������м�ֵkey���ҵ��ܸ���
	int mid=(n+1)/2,count=0;	//����mid=(n+1)/2Ϊ100�� mid=n/2Ϊ90�� 
	for(it=m.begin();it!=m.end();it++)
	{
		if(count+it->second<mid)
		{
			count+=it->second;
			
		}
		else break;
		
	 } 
	 int left=count;
	 int right=n-count-it->second;
	 
	 if(left==right)
	 	cout<<it->first<<endl;
	 else
	 	cout<<-1<<endl;
	 
	return 0;
 } 
 
