//ccf 20150303 节日
#include<iostream>
using namespace std;

int leapyear(int y)		//判别年份是否为闰年
{
	if((y%400==0)||(y%4==0&&y%100!=0))
		return 1;
	else return 0;
}

int mon[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
				{0,31,29,31,30,31,30,31,31,30,31,30,31}};
//定义一个全局数组 用来表示闰年和非闰年的月份天数
 
int main()
{
	int a,b,c,y1,y2;
	int days=0,days2,i,j,k;
	int week,d;
	cin>>a>>b>>c>>y1>>y2;
	for(i=1850;i<y1;i++)
	{
		days+=365+leapyear(i);	//计算出y1年1月1号之前所有的天数 
	}
	
	for(i=y1;i<=y2;i++)
	{
		days2=days;
		j=leapyear(i);
		for(k=0;k<a;k++)
		{
			days2+=mon[j][k];	//计算出到a-1个月最后一天的天数 
		}
		
		//计算出a月1号的前一天为周几
		week=days2%7+1;	//因为1850.01.01为周一 
		
		//计算出a月的第b个星期c为当月的多少号，如果d>a[j][a],则输出wei NONE 表示 不存在这一天
		//d=(b-1)*7+c-week;
		d = (b-1) * 7 + ((week >= c) ? (c + 7 - week) : (c - week+7));
	/**************最重要的就是这一步计算出a月第b周周c为多少号***************/	
		if(d>mon[j][a])
			cout<<"none"<<endl;
		else
		{
			cout<<i<<"/";
			if(a<10)
				cout<<"0"<<a<<"/";
			else
				cout<<a<<"/";
			if(d<10)
				cout<<"0"<<d<<endl;
			else
				cout<<d<<endl;
			
		}
		//用于计算下一年(y1+1 y1+2 ...y2) 
		 days+=365+leapyear(i);  
			
	}
	
	return 0;
	
 } 

//#include<iostream>
//using namespace std;
//int main()
//{
//	int i,sum=0;
//	for(i=0;i<100;i++)
//	{
//		sum+=i;
//	}
//	cout<<sum<<endl;
//	return 0;
// } 
