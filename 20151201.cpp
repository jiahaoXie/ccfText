//////ccf 20151201 ��λ֮��
#include<iostream>
using namespace std;
char a[10];
int main()
{
	int i,sum=0;
	cin>>a;
	for(i=0;a[i]!='\0';i++)
	{
		sum+=(int)(a[i]-'0');	
	}
	cout<<sum<<endl;
	return 0;
 } 
 

////ccf 20151202 ��������Ϸ
////�ؼ������ڽ�����ֵ����ȡΪ��ֵ ���þ���ֵ���������к��е�����ֵ�Ƚϣ�������и�����Ϊ0 
//#include<iostream>
//using namespace std;
//
//const int MAX=30;
//int a[MAX][MAX];
//
//int fabs(int x)
//{
//	return (x>=0)?x:-x;
//}
// 
// int main()
// {
// 	int n,m,i,j;
// 	cin>>n>>m;
// 	for(i=0;i<n;i++)
// 	{
// 		for(j=0;j<m;j++)
// 			cin>>a[i][j];	 
//	 }
//	 
//	 //�ȴ��п�ʼ���� ����в���
//	 for(i=0;i<n;i++)
//	 {
//	 	for(j=0;j<m-2;j++)
//	 	{
//	 		 if(fabs(a[i][j]) == fabs(a[i][j+1]) && fabs(a[i][j+1]) == fabs(a[i][j+2])) {  
//                if(a[i][j] > 0)  
//                    a[i][j] = - a[i][j];  
//                if(a[i][j+1] > 0)  
//                    a[i][j+1] = - a[i][j+1];  
//                if(a[i][j+2] > 0)  
//                    a[i][j+2] = - a[i][j+2];  
//            } 
//			 
//		 }
//		
//	  } 
//	  
//	 for(j=0;j<m;j++)
//	 {
//	 	for(i=0;i<n-2;i++)
//	 	{
//	 		if(fabs(a[i][j]) == fabs(a[i+1][j]) && fabs(a[i+1][j]) == fabs(a[i+2][j]))
//	 		{
//	 			if(a[i][j]>0) 	a[i][j]=-a[i][j];
//	 			if(a[i+1][j]>0) a[i+1][j]=-a[i+1][j];
//	 			if(a[i+2][j]>0) a[i+2][j]=-a[i+2][j];
//			 }
//		 }
//	 }
//	 
//	 //cout<<"========================================================\n";
//	 //��� ��ֵȫ����Ϊ0
//	 for(i=0;i<n;i++)
//	 {
//	 	for(j=0;j<m;j++)
//	 	{
//	 		if(a[i][j]<0)	a[i][j]=0;
//	 		cout<<a[i][j];
//	 		if(j!=m-1)
//	 			cout<<" ";
//		 }
//		 cout<<endl;
//	  } 
// 	return 0;
// 	
// }
 
 
