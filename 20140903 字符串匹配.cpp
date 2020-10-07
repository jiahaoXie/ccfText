////ccf 20140903 字符串匹配 

#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
using std::string;
//
string s[100];
//
//int Index(string& ss,string& t)
//{
//	int i=0,j=0;
//	while(i<=ss.length() && j<=t.length())
//	{
//		if(ss[i]==t[j])
//		{	//相同继续 继续向后比较字符 
//			++i;
//			++j;
//					
//		}
//		else 
//		{
//			i=i-j+1;
//			j=0;
//		}
//	}
//	if(j>t.length())
//		return 1;
//	else return 0;
//	
//}
int main()
{
	string t;
	int i,j,n,flag,value;
	cin>>t;
//	getchar();
	cin>>flag;
	cin>>n;
	getchar();	//读取一个字节 这里用来读取一个换行 
	for(i=0;i<n;i++)
	{
		
		getline(cin,s[i]);
	}
//	cout<<"==========================="<<endl;
//	for(i=0;i<n;i++)
//		cout<<s[i]<<endl;
//	cout<<"==========================="<<endl;
	if(flag==1)	//flag=1 表示对大小写敏感 
	{	for(i=0;i<n;i++)
		{
			//value=Index(s[i],t);
			int pos=s[i].find(t);
			if(pos>=0)
				cout<<s[i]<<endl;	
		}
		
	}
	else	//flag=0 表示对大小写不敏感 将所有字符统一转换为答谢字符 
	{
		for(i=0;i<(int)t.size();i++)
		{
			t[i]=toupper(t[i]);
		}
		for(i=0;i<n;i++)	
		{	string tmp=s[i];
			for(j=0;j!=(int)tmp.size();j++)
				tmp[j]=toupper(s[i][j]);
			
//			value=Index(s[i],t);
//			if(value)
//				cout<<s[i]<<endl;
//				
			int pos=tmp.find(t);
			if(pos>=0)
				cout<<s[i]<<endl;
		}		
		
	}	
	return 0;
}

//#include<iostream>
//#include<string>
//#include<cctype>
//using namespace std;
//
//int main()
//{
//	string t,s,tl,sl;
//	int flag,n,i;
//	cin>>t>>flag>>n;
//	//将目标字符串t的小写形式存放到 tl中 
//	tl=t;
//	for(int i=0; i<(int)tl.length(); i++)  
//        if(isupper(tl[i]))  
//            tl[i] = tolower(tl[i]); 
////	cout<<tl<<endl;
//	getchar(); 
//	for(i=0;i<n;i++)
//	{
//		cin>>s;
//		if(flag==0)
//		{	
//			//为0 不区分大小写 将字符串全部转换为小写形式 
//			sl=s;
//			for(int i=0; i<(int)sl.length(); i++)  
//        		if(isupper(sl[i]))  
//            		sl[i] = tolower(sl[i]); 
//			int pos=sl.find(tl);
//			if(pos>=0)
//			 	cout<<s<<endl;
//		
//		}
//		else
//		{	
//			//1 表示区分大小写
//			int pos=s.find(t);
//			if(pos>=0)
//			 	cout<<s<<endl;
//		}
//	}
//	return 0;
// } 
 
// //100分答案
// #include <iostream>  
//#include <cctype>  
//#include <string>  
//  
//using namespace std;  
//  
//int main()  
//{  
//    string key, s, kt, st;  
//    int option, n;  
//  
//    // 输入数据  
//    cin >> key >> option >> n;  
//  
//    // 获得key的小写字符串，放在变量kt  
//    kt = key;  
//    for(int i=0; i<(int)kt.size(); i++)  
//        if(isupper(kt[i]))  
//            kt[i] = tolower(kt[i]);  
//  
//    // 循环处理  
//    for(int i=1; i<=n; i++) {  
//        cin >> s;  
//  
//        if(option == 0) {   // 大小写无关  
//            st = s;  
//            for(int i=0; i<(int)st.size(); i++)  
//                if(isupper(st[i]))  
//                    st[i] = tolower(st[i]);  
//  
//            int pos = st.find(kt);  
//            if(pos >= 0)  
//                cout << s << endl;  
//        } else { // option = 1，大小写有关  
//            int pos = s.find(key);  
//            if(pos >= 0)  
//                cout << s << endl;  
//        }  
//    }  
//  
//    return 0;  
//} 
