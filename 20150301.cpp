
////��һ�� ͼ����ת 
//#include<iostream>
//using namespace std;
//
//int a[1000][1000];
//int main()
//{
//	int m,n,i,j;
//	cin>>n>>m;
//	for( i=0;i<n;i++)
//		for( j=0;j<m;j++)
//			cin>>a[i][j];
//	
//	for(j=m-1;j>=0;j--)
//	{
//		for(i=0;i<n;i++)
//		{
//			cout<<a[i][j]<<" ";
//		}
//			
//		cout<<endl;
//	}
//		
//	return 0;
//	
//}


////�ڶ��� �������� ����map�洢������vector����value������ 
//#include<iostream>
//#include<map>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int a[1000];
//
// 
////typedef pair<int,int>PAIR;
////class CmpValue
////{
////public:
////	bool operator()(const PAIR& x,const PAIR& y)
////	{
////	 if(x.second == y.second)  
////        return x.first< y.first;  
////    else  
////        return x.second > y.second;
////		
////	}
////};
//
//
//typedef pair<int,int> PAIR;
//bool compare(const PAIR& x,const PAIR& y)
//{
//	if(x.second==y.second)
//	{
//		return x.first<y.first;
//	}
//	else
//	{
//		return x.second>y.second;
//	}
//}
//int main()
//{
//	int n,i;
//	cin>>n;
//	map<int,int>m1;
//	
//	for(i=0;i<n;i++)
//	{
//		cin>>a[i];
//		m1[a[i]]++;
//	}
//	
//	vector<PAIR> v1(m1.begin(),m1.end());	//��map�е�Ԫ��ת�浽vector�� 
////	sort(v1.begin(),v1.end(),CmpValue());	//��Ԫ�ؽ��д�С����������
//	sort(v1.begin(),v1.end(),compare);
//	
//	for(i=0;i!=v1.size();i++)
//	{
//		cout<<v1[i].first<<" "<<v1[i].second<<endl;
//	 } 
//	return 0;
//}

////�������� ���������±귨 ���� 
//#include<iostream>
//
//#include<cstring>
//using namespace std;
//int a[1001];
//
//int main()
//{
//	int n,i,j,num;
//	cin>>n;
//	memset(a,0,sizeof(a));
//	for(i=0;i<n;i++)
//	{
//		cin>>num;
//		a[num]++;	//���������±� 
//	}
//	for(j=1000;j>0;j--)
//	{
//		for(i=0;i<1000;i++)
//			if(a[i]==j)
//			{
//				cout<<i<<" "<<j<<endl;
//			
//			}
//			
//	 } 
//	return 0;
//
//}

//����20131201 ���ִ��������� ���������±귨����򵥵ķ��� 
#include<iostream>
#include<cstring>
using namespace std;
int a[1001];

int main()
{
	int n,i,num,max;
	memset(a,0,sizeof(a));
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>num;
		a[num]++;
	}
	max=0;
	for(i=0;i<1001;i++)
	{
		if(a[max]<a[i])
			max=i;
	}
	cout<<max<<endl;
	return 0;
 } 


