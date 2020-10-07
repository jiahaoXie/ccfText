#include<iostream>
#include<string>
#include<cassert>
using namespace std;

int main ()
{
//	int num = 123;
//	char str[25];
//	string s;
//	s=itoa(num, str, 10);
//	printf("The number 'num' is %d ,and the string 'str' is %s. \n" ,num, str);
//	cout<<s<<endl;

	string s("abcdefgh");
	string s1=s.substr(2);
	cout<<"s= "<<s<<endl;
	cout<<"s1= "<<s1<<endl;
	return 0;
}


