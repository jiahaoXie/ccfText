////ccf 20150901 ��һ�� ���зֶ�
//#include<iostream>
//using namespace std;
//int a[1000];
//int count=0;
//int main()
//{
//	int n,i,m,j;
//	cin>>n;
//	for(i=0;i<n;i++)
//	{
//		cin>>a[i];
//	}
//	for(i=0;i<n;i+=m)
//	{
//		m=1;
//		for(j=i+1;j<n;j++)
//		{
//			
//			if(a[i]==a[j])
//			{
//				m++;
//			}
//			else
//			{
//				count++;
//				break;
//			}
//				
//		}
//	}
//	cout<<count+1<<endl;
//	return 0;
//}
// 

//ccf 20150902 ���ڼ���
#include<iostream>
using namespace std;
int leapyear(int y)
{
	if((y%400==0)||(y%4==0&&y%100!=0))
	{
		return 1;
	}
	else return 0;
} 
int a[2][13] ={{0,31,28,31,30,31,30,31,31,30,31,30,31},
				 {0,31,29,31,30,31,30,31,31,30,31,30,31}};
				 
int main()
{
	int y,d;
	int i,j,month,day=0,days=0;	//month��ʾΪ����,day��ʾΪ���ţ�days��ʾ��ʾ����ǰ��1��֮ǰ���е����� 
	int sum;
	cin>>y;
	cin>>d;
	if((y>=1900&&y<=2015)&&(d>=1&&d<=365))
	{
		j=leapyear(y);
		for(i=0;i<13;i++)
		{
			days+=a[j][i];
			if(days==d)	//d�պ�Ϊĳ�µ����һ�� 
			{
				month=i;
				day=a[j][i];
				break;
			} 
			else if(days>d)
			{
				month=i;
				break;
			}
		}
		if(day==0)
		{
			for(i=0;i<month;i++)
			{
				sum+=a[j][i];
			}
			day=d-sum;
		}
		cout<<month<<endl;
		cout<<day<<endl;
	}
	return 0;
}
 

