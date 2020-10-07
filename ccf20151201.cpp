//ccf 20151201 数位之和
#include<iostream>
using namespace std;
char a[10];
int main()
{
	int i,sum;
	cin>>a;
	for(i=0;a[i]!='\0';i++)
	{
		sum+=(int)(a[i]-'0');	
	}
	cout<<sum-1<<endl;
	return 0;
 } 
