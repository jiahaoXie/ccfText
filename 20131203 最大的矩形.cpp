//ccf 20131203 ���ľ���

#include<iostream>
using namespace std;
int a[1001];

int main()
{
	int n,i,j;
	int max,min,t;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	//�����ҵ��������ε����ֵ ��ֵ��max
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(max<a[i])
			max=a[i];
	 } 
	 //��������forѭ�� ���������ھ��ε����ֵ 
	 for(i=0;i<n;i++)
	 {
	 	min=a[i];
	 	for(j=i+1;j<n;j++)
	 	{
	 		
	 		if(min>a[j])
	 			min=a[j];
	 		t=min*(j-i+1);
	 		if(t>max)
	 			max=t;
		 }
	 }
	 cout<<max<<endl;
	return 0;
	
}
