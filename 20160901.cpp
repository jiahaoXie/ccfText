////ccf 20160901 ��󲨶�
//
//#include<iostream>
//using namespace std;
//
//
//int fabs(int n)
//{
//	return (n>=0)?n:-n;
// } 
// int main()
// {
// 	int a[1000];
// 	int n,i,t1=0,t2=0;
// 	cin>>n;
// 	for(i=0;i<n;i++)
// 	{
// 		cin>>a[i];
//	 }
//  	for(i=0;i<n-1;i++)
// 	{
// 		if(i==0)
// 		{
// 			t1=t2=fabs(a[i]-a[i+1]);
//		 }
//		 else 
//		 {
//		 	t2=fabs(a[i]-a[i+1]);
//		 	if(t2>t1)
//		 	{
//		 		t1=t2;
//			 }
//		 		
//		 }
// 		
//	 }
//	cout<<t1<<endl;
// 	return 0;
// }
//

//ccf 20160902 �𳵹�Ʊ 
//����һ ����򵥵ķ����������÷���һ�� 
//����һ ��һά����a[20]�洢ÿһ�е���λ�� �����м�ʱ���� 
#include<iostream>
using namespace std;

int main()
{
	int a[20];
	int n,count,i,j,t;
	for(i=0;i<20;i++)
	{
		a[i]=5;//��ʼ�� ÿ����5����λ 
	}
	cin>>n;
	while(n--)
	{
		cin>>count;	//��ʾÿ��ָ��Ҫ�����Ʊ�� 
		for(i=0;i<20;i++)
		{
			if(a[i]>=count)
			 break;	//�ҵ������������� 
		}
		if(i<20)
		{
			for(t=5*i+6-a[i],j=1;j<=count;j++,t++)
			  cout<<t<<" ";
			cout<<endl;
			a[i]-=count;
		}
		else if(i==20)	//��ʾ���ж�������count�����ڵ���λ ���С������� 
		{
			for(j=0;j<20;j++)
			{
				if(a[j]==0)  continue;
				while(count--&&a[j]--)
					cout<<5*j+5-a[j]<<" ";
				 
			}
			cout<<endl;
		}
	}
}

////������ �ö�ά����a[20][6]����ʾ��λ a[i][0]������ʾһ����λ����
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a[20][6];
//	int n,count,i,j,k;
//	
//	for(i=0;i<20;i++)
//	{
//		a[i][0]=5;
//		for(j=1;j<6;j++)
//			a[i][j]=5*i+j;
//	}
//	
//	cin>>n;
//	
//	while(n--)
//	{
//		cin>>count;
//		int t=count;
//		for(i=0;i<20;i++)
//			if(a[i][0]>=count)
//				break;
//		
//		if(i<20)
//		{
//			for(j=1;j<6;j++)
//			{
//				if(a[i][j]!=0)
//				{
//					cout<<a[i][j]<<" ";
//					a[i][j]=0;
//					t--;	
//				}
//				
//			}
//			a[i][0]-=count;
//			cout<<endl;
//		}
//		
//		else if(i==20)
//		{
//			for(j=0;j<20;j++)
//			{
//				if(a[j][0]==0)	continue;
//				for(k=1;k<6&&a[j][0]>0;k++)
//				{
//					if(a[j][k]!=0)
//					{
//						cout<<a[j][k]<<" ";
//						a[j][k]=0;
//						a[j][0]--;
//						count--;
//						if(count==0) 
//							break;
//					}
//					else continue;
//				}
//				if(count==0)
//					break;
//			}
//			
//		}
//	}
//	return 0;
//} 



