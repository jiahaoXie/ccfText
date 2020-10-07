////ccf 20150903 模板生成系统
 //方法一 string存储输入的模板字符串  map<string,string>存储输入的变量和变量的值 
 //100分 
// #include<iostream>
// #include<map>
// #include<string>
// using namespace std;
// 
// int main() 
// {
// 	int M,N,i;
// 	string str,str2;
// 	map<string,string> m;
// 	string key,value;
// 	string varKey,varValue;
// 	cin>>M>>N;
// 	getchar(); //接受输入的enter键 
// 	while(M--)
// 	{
// 		string tmp;
// 		getline(cin,tmp);
// 		str+=tmp+"\n";
// 		
//	 }
//
//	while(N--)
//	{
////		string t;
////		cin>>key;
////		getline(cin,t);
////		int startQuote=t.find("\"");	//查找字符串t中第一次出现"的下标值 
////		int endQuote=t.rfind("\"");		//查找字符串t中最后一次出现"的下标值
////		value=t.substr(startQuote+1,endQuote-startQuote-1);	//将除去双引号的有效字符串存入mao中 
////		m[key]=value;
//		
//		string t;
//		getline(cin,t);
//		int startQuote=t.find("\"");
//		int endQuote=t.rfind("\"");
//		key=t.substr(0,startQuote-1);
//		value=t.substr(startQuote+1,endQuote-startQuote-1);
//		m[key]=value; 
//
//	}
//	
//	//解析模板中带有大括号的字符串 并与map中的key值进行匹配  用value进行替代
//	int startpos,endpos;
//	int startPoint = 0; // start position for string.find
//	while(true)
//	{
//		startpos=str.find("{{",startPoint);	//startpos表示{{之前的下标位置 
//		endpos=str.find("}}",startpos);		//end表示{{之前的下标位置
//		if(startpos<0 || endpos<0) break;	//循环跳出 
//		varKey=str.substr(startpos+3,endpos-startpos-4);	//截取有效的字符串  因为{{ name }}括号与name之间还有空格 
//											
//		varValue="";	//首先将值赋值为空字符串 (范例中address无匹配项输出为空) 
//		if(m.find(varKey)!=m.end())	//再和map中的key值进行匹配 
//			varValue=m[varKey];
//		str2+=str.substr(startPoint,startpos-startPoint)+varValue;
//		startPoint=endpos+2; 	//+2为减去 }} 
//	 } 
//	 str2+=str.substr(startPoint);
//	 cout<<str2;
//	 
// 	return 0;
// 	
// }

#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main()
{
	string str;
	string key,value;
	map<string,string> m;
	vector<string> v;
	int M,N;
	cin>>M>>N;
	getchar();
	while(M--)
	{	//输入模板 
		string tmp;
		getline(cin,tmp);
		str+=tmp+'\n';
	//	v.push_back(tmp);
	}
	while(N--)
	{	//输入变量和变量的值 
		string tmp;
		getline(cin,tmp);
		int start=tmp.find("\"");
		int end=tmp.rfind("\"");
		key=tmp.substr(0,start-1);
		value=tmp.substr(start+1,end-start-1);
		m[key]=value;		
	}
	int startPos,endPos;
	int startPoint=0;
	while(true)
//	for(int i=0;i<M;i++)
	{
		startPos=str.find("{{",startPoint);
		endPos=str.find("}}",startPos);
		if(startPos<0 || endPos<0)	break;
		
		key=str.substr(startPos+3,endPos-startPos-4);
	//	key=v[i].substr(startPos+3,endPos-startPos-4);
		str.replace(startPos,endPos-startPos+2,(m.count(key)>0?m[key]:""));	//直接用字符串替代 
		//v[i].replace(startPos,endPos-startPos+2,(m.count(key)>0?m[key]:""));
	//	startPoint+=m.count(key)>0?m[key].length():0;	//这一步很关键 作用是避免重复替换 
	}
	cout<<str;
	
	return 0;
}

////利用string str1[],str2[]分别存储输入的模板和输出的模板 map<string,string>存储输入的变量和变量的值
////80分~ 
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//string str1[101],str2[101];
//int main()
//{	string vkey,value;
//	int m,n,i;
//	map<string,string>m1;
//	cin>>m>>n;
//	getchar();
//	for(i=0;i<m;i++)
//		getline(cin,str1[i]);
//	
//	while(n--)
//	{
//		string t,key;
//		cin>>key;
//		getline(cin,t);
//		int startQuote=t.find("\"");	//查找字符串t中第一次出现"的下标值 
//		int endQuote=t.rfind("\"");		//查找字符串t中最后一次出现"的下标值
//		value=t.substr(startQuote+1,endQuote-startQuote-1);	//将除去双引号的有效字符串存入map中 
//		m1[key]=value;
//
//	}
//	int flag=0;
//	int start,end;
//	for(i=0;i<m;i++)
//	{
//		while(true)
//		{
//			start=str1[i].find("{{");
//			end=str1[i].find("}}");
//			if(start<0 || end<0)	break;
//			vkey=str1[i].substr(start+3,end-start-4);
//			if(m1.find(vkey)!=m1.end())
//			{
//				value=m1[vkey];
//				flag=1;
//				
//			}
//			if(flag==0) value="";
//			str2[i]+=str1[i].substr(0,start)+value;
//			str1[i]=str1[i].substr(end+2);
//		}
//		str2[i]+=str1[i];
//		cout<<str2[i]<<endl;
//	}
//	
//	return 0;
//	
//}
//////同样的思路 利用string str1[],str2[]分别存储输入的模板和输出的模板 ，利用string value[i][j] 存储输入的变量
////只有80分？？ 
//#include<iostream>
//#include<string>
//using namespace std;
//
//string str1[101],str2[101];
//string value[101][2];
//int main()
//{
//	
//	string tmp;
//	int m,n,i,j;
//	cin>>m>>n;
//	getchar();	//处理换行 接受enter键 
//	for(i=0;i<m;i++)
//		getline(cin,str1[i]);
//	
//	for(i=0;i<n;i++)
//	{
//		cin>>value[i][0];
//		string tmp;
//		getline(cin,tmp);
//		int start=tmp.find('"');
//		int end=tmp.rfind('"');
//		value[i][1]=tmp.substr(start+1,end-start-1);
//		//截取双引号里面的有效字符 用二维字符串数组的方式存储
//		 
//	}
//	//从输入的模板中查询{{ **** }}的内容 并与二维字符串数组进行匹配
//	int flag=0;//定义一个符号位 1表示匹配成功 0表示匹配不成功 
//	 for(i=0;i<m;i++)
//	 {
//	 	while(true)
//	 	{
//	 		int sstr=str1[i].find("{{");	//找到指定下标 
//	 		int estr=str1[i].find("}}");
//	 		if(sstr<0 || estr<0)	break;
//	 		tmp=str1[i].substr(sstr+3,estr-sstr-4);
//	 		for(j=0;j<n;j++)
//	 		{
//	 			if(tmp==value[j][0])
//	 			{
//	 				flag=1;
//	 				tmp=value[j][1];
//	 				break;
//				 }
//			 }
//			 if(flag==0) tmp="";
//			 str2[i]+=str1[i].substr(0,sstr)+tmp;	//将大括号之前的字符和替换后的字符串 赋值给str2[i] 
//			 str1[i]=str1[i].substr(estr+2);
//		 }
//		str2[i]+=str1[i];
//		cout<<str2[i]<<endl; 
//	 	
//	 }
//	 return 0;
// } 



