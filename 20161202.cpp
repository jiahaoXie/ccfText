//ccf 20161202 工资计算
//这道题的思路是首先建立两个全局的一维数组 分别表示每个工资段的最大工资和税率  而后有这两个数组得到税后的实际收入范围 
#include<iostream>
using namespace std;

 int salary[]={3500,3500+1500,3500+4500,3500+9000,3500+35000,3500+55000,3500+80000};
 int tax[]={3,10,20,25,30,35,45};
//const int size=sizeof(salary)/sizeof(int);	//注意这里的size 作为全局变量 必须加上const 表示是一个不能改变的量 否则在线测试为0分（着实有些不懂？？？？） 

int main()
{
	
	const int size=sizeof(salary)/sizeof(int);
//	cout<<size<<endl;
	int range[size]={0};
	int t,i,s;
	range[0]=salary[0];
	for( i=1;i<size;i++)
	{
		range[i]=range[i-1]+(salary[i]-salary[i-1])-(salary[i]-salary[i-1])*tax[i-1]/100;
			
	}
//	for(i=0;i<size;i++)
//		cout<<range[i]<<" ";
//	cout<<endl;
	
 	cin>>t;
 	

	
	for(i=0;i<size;i++)
	{
		if(t<=range[i])		///t与税后每个工资端的最大值进行比较 找到t所对应的工资段range[i]	
			break;
	 } 
	 if(i==0)
	 	s=t;
	else
		s=salary[i-1]+(t-range[i-1])*100/(100-tax[i-1]);	
	cout<<s<<endl;
	return 0;
 } 
 // 	for(i=0;i<size;i++)	//这一段测试只有80分  
// 	{		//t与税后每个工资端的最大值进行比较 找到t所对应的工资段range[i] 
// 		if(t<=range[0]) 
//		 {
//		 	cout<<t<<endl;
//			 break;	
//		 }
//		else
//		{
//			if(t<range[i])
//			{
//				s=salary[i-1]+(t-range[i-1])*100/(100-tax[i-1]);	//s为上一个工资段的税前工资加上这个工资段的税后工资除以（1-税率） 
//				cout<<s<<endl;
//				break;
//			}
//			
//		}	
//	 }
