////CCF 20131201 ���ִ���������
//***********************************
//���ȿ���map���
//**********************************
////����1 c++ map��� 
// #include<iostream>
// #include<map>
// using namespace std;
// using std::map;
// 
// int main()
// {
// 	map<int,int> m1;
// 	int n,i,tmp;
// 	cin>>n;
// 	for(i=0;i<n;i++)
// 	{
// 		cin>>tmp;
// 		m1[tmp]++;
//	 }
//	 
//	  // �ҳ����ִ���������  
//    int ans, count=0;  
//    for(map<int,int>::iterator it=m1.begin(); it!=m1.end(); it++)  
//        if(it->second > count) {  
//            count = it->second;  
//            ans = it->first;  
//        } 
//    cout<<ans<<endl;
// }

////������ ������������ ֮�佨������
//#include<iostream>
//using namespace std;
//const int N=1001;
//const int M=10001;
// int a[N];
// int count[M]={0};
// //a[]��ʾʵ���������ֵ count[]��ʾÿ����ֵ��Ӧ�Ĵ���
// 
//int main()
//{
//	int n,i,tmp=0;
//	cin>>n;
//	for(i=0;i<n;i++)
//	{
//		cin>>a[i];
//		count[a[i]]++;
//	}
//	for(i=0;i<M;i++)
//	{
//		if(count[i]>count[tmp])
//			tmp=i;
//	}
//	cout<<tmp<<endl;
//	return 0;
// }

//ISBN����	��֪Ϊ��ֻ��70�֣����� 
//#include<iostream> 
//using namespace std;
//int main()
//{
//	char s[13];
//	int i,sum=0,mod,j=1;
//	char flag;
//	cin>>s;
//	for(i=0;i<12;i++)
//	{
//	//	if(s[i]>='0'&&s[i]<='9')
//		if(s[i]!='-')
//		{
//			sum+=(s[i]-'0')*(j++);
//			
//		}
//	}
//	mod=sum%11;
//	
//	if(mod==10)
//		flag='X';
//	else flag=mod+'0';
//	
//	if(flag==s[12])
//		cout<<"RIGHT"<<endl;
//	else 
//	{
//		s[12]=flag;
//		cout<<s<<endl;
//		
//	 } 
//	return 0;
//	
//}

////��Ϊsring��ʾ������ַ��� ����70������������ 
//#include<iostream>
//#include<string> 
//using namespace std;
//int main()
//{
//	string s;
//	int i,sum=0,mod,j=1;
//	char flag;
//	cin>>s;
//	for(i=0;i<(int)s.length()-1;i++)
//	{
//		if(s[i]!='-')
//		{
//			sum+=(s[i]-'0')*j++;
//			
//		}
//	}
//	mod=sum%11;
//	
//	if(mod==10)
//		flag='X';
//	else flag=mod+'0';
//	
//	if(flag==s[s.length()-1])
//		cout<<"RIGHT"<<endl;
//	else 
//	{
//		s[s.length()-1]=flag;
//		cout<<s<<endl;
//		
//	 } 
//	return 0;	
//}

//100�� �𰸽�� 
//#include <iostream>  
//#include <string>    
//using namespace std;    
//int main()  
//{  
//    string s;  
//  
//    // ��������  
//    cin >> s;  
//  
//    // ����ʶ����  
//    int sum = 0, j = 1,t;  
//    for(int i=0; i<s.length()-1; i++) {  
//        if(s[i] != '-')  
//            sum += (s[i] - '0') * j++;  
//    }  
//  
//    // ʶ����ת�ַ�  
//    char c;  
//    t = sum % 11;  
//    if(t == 10)  
//        c = 'X';  
//    else  
//        c = t + '0'; 
//  
//    // �ж�ʶ���롢У�������  
//    if(c == s[s.length()-1])  
//        cout << "Right" << endl;  
//    else {  
//        s[s.length()-1] = c;  
//        cout << s << endl;  
//    }  
//  
//    return 0;  
//} 
  
  
#include<iostream>
using namespace std;

int main()
{
	cout<<"hello,world!"<<endl;
	return 0;
 } 
