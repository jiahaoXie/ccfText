////CCF 20170302 分蛋糕
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

//ccf 20170302 学生排队
//思路 利用两个数组分别存储学号 和位置（注意二者之间进行对应）
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
	while(m--)		//模仿移动次数   
	{
		cin>>p>>q;
		flag=(q>0)?1:-1;	//flag表示元素值向前移还是向后移
	 
		for(i=loc[p];i!=loc[p]+q;i+=flag)	//这里for循环在判断时 因为q有正有负 所以不能写成i<loc[p]+q  
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
