////ccf 20140901 ÏàÁÚÊı¶Ô
// #include<iostream>
// using namespace std;
// 
// int a[1000];
// int fabs(int x)
// {
// 	return (x>=0)?x:-x;
// }
// 
// int main()
// {
// 	int n,i,j,count;
// 	cin>>n;
// 	for(i=0;i<n;i++)
// 		cin>>a[i];
// 	
// 	for(i=0;i<n;i++)
// 	{
// 		for(j=0;j<i;j++)
// 		{
// 			if(fabs(a[i]-a[j])==1)
// 				count++;
//		 }
//	 }
//	 cout<<count<<endl;
// 	return 0;
// 	
// }


//CCF 20140902 »­Í¼
#include<iostream>
using namespace std;
const int MAX=101;
int a[MAX][MAX];
int main()
{
	int n,x1,y1,x2,y2;
	int i,j,count;
	cin>>n;
	while(n--)
	{
		cin>>x1>>y1>>x2>>y2;
		for(i=x1;i<x2;i++)
		{
			for(j=y1;j<y2;j++)
				a[i][j]=1;
		}
	}
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			if(a[i][j])
				count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
