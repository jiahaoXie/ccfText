//ccf 20150303 ����
#include<iostream>
using namespace std;

int leapyear(int y)		//�б�����Ƿ�Ϊ����
{
	if((y%400==0)||(y%4==0&&y%100!=0))
		return 1;
	else return 0;
}

int mon[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
				{0,31,29,31,30,31,30,31,31,30,31,30,31}};
//����һ��ȫ������ ������ʾ����ͷ�������·�����
 
int main()
{
	int a,b,c,y1,y2;
	int days=0,days2,i,j,k;
	int week,d;
	cin>>a>>b>>c>>y1>>y2;
	for(i=1850;i<y1;i++)
	{
		days+=365+leapyear(i);	//�����y1��1��1��֮ǰ���е����� 
	}
	
	for(i=y1;i<=y2;i++)
	{
		days2=days;
		j=leapyear(i);
		for(k=0;k<a;k++)
		{
			days2+=mon[j][k];	//�������a-1�������һ������� 
		}
		
		//�����a��1�ŵ�ǰһ��Ϊ�ܼ�
		week=days2%7+1;	//��Ϊ1850.01.01Ϊ��һ 
		
		//�����a�µĵ�b������cΪ���µĶ��ٺţ����d>a[j][a],�����wei NONE ��ʾ ��������һ��
		//d=(b-1)*7+c-week;
		d = (b-1) * 7 + ((week >= c) ? (c + 7 - week) : (c - week+7));
	/**************����Ҫ�ľ�����һ�������a�µ�b����cΪ���ٺ�***************/	
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
		//���ڼ�����һ��(y1+1 y1+2 ...y2) 
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
