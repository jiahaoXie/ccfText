//ccf 20161201 中间数
 
 //方法一 用数组进行初始化 并进行有效排序 并且找到中间数（删除左右两边与中间数相同的数值 然后比较left 与right值是否相等） 
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
//	{		//对数组元素冒泡排序从小到大 
//		for(j=i+1;j<n;j++)
//			if(a[i]>a[j])
//			{
//				t=a[i];
//				a[i]=a[j];
//				a[j]=t;
//			}
//	}
////	t=a[n/2];	//取排序好的数组中 中间值，若有与中间值相同的元素 则通过数组向前移动一位来去除与中间元素相同 
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

//方法二 采用STL 中的map容器(key/value) key为输出的元数 value为出现的次数 利用到默认情况下map迭代器按照key值从小到大进行排序
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
	{	//初始化 构建map 
		cin>>v;
		m[v]++;
	}
//	for(it=m.begin();it!=m.end();it++)		//通过这两条语句 可以测试出 认情况下map迭代器按照key值从小到大进行排序
//		cout<<it->first<<" "<<it->second<<endl;
//		 
	//查找中间数 并计算中间值key左右的总个数
	int mid=(n+1)/2,count=0;	//这里mid=(n+1)/2为100分 mid=n/2为90分 
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
 
