////ccf 20140903 �ַ���ƥ�� 

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
//		{	//��ͬ���� �������Ƚ��ַ� 
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
	getchar();	//��ȡһ���ֽ� ����������ȡһ������ 
	for(i=0;i<n;i++)
	{
		
		getline(cin,s[i]);
	}
//	cout<<"==========================="<<endl;
//	for(i=0;i<n;i++)
//		cout<<s[i]<<endl;
//	cout<<"==========================="<<endl;
	if(flag==1)	//flag=1 ��ʾ�Դ�Сд���� 
	{	for(i=0;i<n;i++)
		{
			//value=Index(s[i],t);
			int pos=s[i].find(t);
			if(pos>=0)
				cout<<s[i]<<endl;	
		}
		
	}
	else	//flag=0 ��ʾ�Դ�Сд������ �������ַ�ͳһת��Ϊ��л�ַ� 
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
//	//��Ŀ���ַ���t��Сд��ʽ��ŵ� tl�� 
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
//			//Ϊ0 �����ִ�Сд ���ַ���ȫ��ת��ΪСд��ʽ 
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
//			//1 ��ʾ���ִ�Сд
//			int pos=s.find(t);
//			if(pos>=0)
//			 	cout<<s<<endl;
//		}
//	}
//	return 0;
// } 
 
// //100�ִ�
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
//    // ��������  
//    cin >> key >> option >> n;  
//  
//    // ���key��Сд�ַ��������ڱ���kt  
//    kt = key;  
//    for(int i=0; i<(int)kt.size(); i++)  
//        if(isupper(kt[i]))  
//            kt[i] = tolower(kt[i]);  
//  
//    // ѭ������  
//    for(int i=1; i<=n; i++) {  
//        cin >> s;  
//  
//        if(option == 0) {   // ��Сд�޹�  
//            st = s;  
//            for(int i=0; i<(int)st.size(); i++)  
//                if(isupper(st[i]))  
//                    st[i] = tolower(st[i]);  
//  
//            int pos = st.find(kt);  
//            if(pos >= 0)  
//                cout << s << endl;  
//        } else { // option = 1����Сд�й�  
//            int pos = s.find(key);  
//            if(pos >= 0)  
//                cout << s << endl;  
//        }  
//    }  
//  
//    return 0;  
//} 
