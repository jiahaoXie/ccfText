////ccf 20160403 路径解析
////用string 存储字符串（这里为当前目录） 并在for循环中一次次处理待处理的字符串 
//
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int p,pos;
	string str;
	cin>>p;
	getchar();	//接收换行符
	cin>>str;
	getchar();
	
	while(p--)
	{
		string tmp;
		getline(cin,tmp);
		
		//对非根路径进行处理
		if(tmp[0]!='/')
			tmp=str+'/'+tmp;
		
		//while循环 去除多个'/'
		while(tmp.find("//") != -1)
		{
			pos=tmp.find("//");
			tmp.erase(pos,1);	//这里为擦除一个/ 若写为tmp.erase(pos);则是擦除pos之后的所有元素 
//			int count = 2;  
//            while(tmp[pos + count] == '/')  
//                count++;  
//            tmp.erase(pos, count-1);
			
		}
		//去除/./ 
		while(tmp.find("/./") != -1)
		{
			pos=tmp.find("/./");
			tmp.erase(pos,2);	//查出下标pos开始的两个字符 也就是/. 
			}
			
		//去除/../ 这也是程序中最复杂的一段	看懂第三个和最后一个样例的输入输出
		while( (pos=tmp.find("/../")) != -1)
		{
			if(pos==0)
				tmp.erase(pos,3);	//擦除/.. 
			else
			{
				int spos=tmp.rfind('/',pos-1);	//从后往前查找下标pos-1之前的第一个/
				tmp.erase(spos,pos-spos+3); 	//擦除样例3中的/d3/.. (因为..表示上一级目录只有d2) 
			
			}
			
		}
		//去除以/结尾
		if(tmp.length()>1 && tmp.rfind('/')==tmp.length()-1) 
		{
			tmp.erase(tmp.length()-1);
		}
			
	cout<<tmp<<endl;
	 } 
	return 0;
}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int pos;
//	string str;
//	cin>>str;
//	while( (pos=str.find("//")) != -1)
//	{
//		cout<<"pos: "<<pos<<" ";
//		str.erase(pos,1);
//		cout<<str<<endl;
//	}
//	
//	return 0;
//}
