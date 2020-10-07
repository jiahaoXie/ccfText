////CCF 20131201 出现次数最多的数
//***********************************
//优先考虑map编程
//**********************************
////方法1 c++ map编程 
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
//	  // 找出出现次数最多的数  
//    int ans, count=0;  
//    for(map<int,int>::iterator it=m1.begin(); it!=m1.end(); it++)  
//        if(it->second > count) {  
//            count = it->second;  
//            ans = it->first;  
//        } 
//    cout<<ans<<endl;
// }

////方法二 利用两个数组 之间建立索引
//#include<iostream>
//using namespace std;
//const int N=1001;
//const int M=10001;
// int a[N];
// int count[M]={0};
// //a[]表示实际输入的数值 count[]表示每个数值对应的次数
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

//ISBN号码	不知为何只有70分？？？ 
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

////改为sring表示输入的字符串 还是70？？？？？？ 
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

//100分 答案结果 
//#include <iostream>  
//#include <string>    
//using namespace std;    
//int main()  
//{  
//    string s;  
//  
//    // 输入数据  
//    cin >> s;  
//  
//    // 计算识别码  
//    int sum = 0, j = 1,t;  
//    for(int i=0; i<s.length()-1; i++) {  
//        if(s[i] != '-')  
//            sum += (s[i] - '0') * j++;  
//    }  
//  
//    // 识别码转字符  
//    char c;  
//    t = sum % 11;  
//    if(t == 10)  
//        c = 'X';  
//    else  
//        c = t + '0'; 
//  
//    // 判断识别码、校正和输出  
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
