//ccf 20161202 ���ʼ���
//������˼·�����Ƚ�������ȫ�ֵ�һά���� �ֱ��ʾÿ�����ʶε�����ʺ�˰��  ����������������õ�˰���ʵ�����뷶Χ 
#include<iostream>
using namespace std;

 int salary[]={3500,3500+1500,3500+4500,3500+9000,3500+35000,3500+55000,3500+80000};
 int tax[]={3,10,20,25,30,35,45};
//const int size=sizeof(salary)/sizeof(int);	//ע�������size ��Ϊȫ�ֱ��� �������const ��ʾ��һ�����ܸı���� �������߲���Ϊ0�֣���ʵ��Щ�������������� 

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
		if(t<=range[i])		///t��˰��ÿ�����ʶ˵����ֵ���бȽ� �ҵ�t����Ӧ�Ĺ��ʶ�range[i]	
			break;
	 } 
	 if(i==0)
	 	s=t;
	else
		s=salary[i-1]+(t-range[i-1])*100/(100-tax[i-1]);	
	cout<<s<<endl;
	return 0;
 } 
 // 	for(i=0;i<size;i++)	//��һ�β���ֻ��80��  
// 	{		//t��˰��ÿ�����ʶ˵����ֵ���бȽ� �ҵ�t����Ӧ�Ĺ��ʶ�range[i] 
// 		if(t<=range[0]) 
//		 {
//		 	cout<<t<<endl;
//			 break;	
//		 }
//		else
//		{
//			if(t<range[i])
//			{
//				s=salary[i-1]+(t-range[i-1])*100/(100-tax[i-1]);	//sΪ��һ�����ʶε�˰ǰ���ʼ���������ʶε�˰���ʳ��ԣ�1-˰�ʣ� 
//				cout<<s<<endl;
//				break;
//			}
//			
//		}	
//	 }
