
////第一题 图像旋转 
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


////第二题 数字排序 利用map存储并利用vector进行value的排序 
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
//	vector<PAIR> v1(m1.begin(),m1.end());	//把map中的元素转存到vector中 
////	sort(v1.begin(),v1.end(),CmpValue());	//对元素进行从小到进行排序
//	sort(v1.begin(),v1.end(),compare);
//	
//	for(i=0;i!=v1.size();i++)
//	{
//		cout<<v1[i].first<<" "<<v1[i].second<<endl;
//	 } 
//	return 0;
//}

////数字排序 采用数组下标法 更快 
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
//		a[num]++;	//采用数组下表法 
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

//这是20131201 出现次数最多的数 采用数组下标法是最简单的方法 
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


