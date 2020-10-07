//ccf 20140303 命令行选项 

//解题步骤：
//1、将每次输入的命令行字符串以空格分开装进vector<string>容器中
//2、然后对容器中的每个字符串进行判断，第一个字符串是工具名不用判断，然后从容器中第二个开始判断当前字符串是否为合法命令。
		//这里要分为2中情况：一种是命令带参数的时，一种是命令不带参数时。
//当命令不带参数时：该字符串长度为2且以‘-’开头，且第二个字符出现在格式字符串中-->该命令合法为命令。
//当该命令带参数时：该字符串长度为2且以‘-‘开头，且第二个字符串出现在格式字符串中，还要看这个字符串后面是否有对应的参数字符串，
		//若有，该命令合法，否则不合法，停止分析。
//3、合法命令的集合存放在map<string,string>中，因为map中的key是要求按key升序排列(命令都是-字母开头)，且key-value的value可以用来存放参数值（无参设为null）。
		//map中插入合法命令时应考虑该命令是否已经存在map中。对于无参的命令，直接插入。对于有参数的命令：若不存在map中直接插入该命令和参数值，若已经存在就将该命令的参数值更新（C++的map中对于key相同的插入不会覆盖，而是放弃处理）
//4、按格式输出map冲存放的合法命令行

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
using std::map;
using std::vector;
 //判断命令是否重复
int isRepeat(map<string,string> m,string s)    
{  
    map<string,string>::iterator it;  
    it = m.find(s);  
    if(it == m.end())  
    {  
        return 0;  
    }
	else  
    {  
        return 1;  
    }  
}  
//查找命令选项 是否存在并且是否附带参数 
int find(string str,char c)	
{
	int i;
	int flag=str.find(c);	//这里flag应该是表示在str中c的下标值 
	if(flag != -1)
	{//命令存在 
		if(flag<str.length()-1&&str.at(flag+1)==':')
		{//str.length()-1表示str中倒数第二个字节下标 因为带参的选项最后为： 
			return 2; 
		}
		else{	//表示无参 
			return 1;	
		}
		
	}
	 return 0;	//命令不存在  
}

int main()
{
	string str;
	int i,n;
	
	cin>>str;
	cin>>n;
	getchar();	//表示从键盘中读入一个字符 在本程序主要是表示 输入完n后 读取接下来的回车键 因为后面要输入n行命令行 
	for(i=0;i<n;i++)
	{
		vector<string> v;
		map<string,string> m;
		string line;
		getline(cin,line);	//从控制台读取一行命令行赋值给line 
		int t;
		//将字符串以空格形式切割存入vector中
		for(t=line.find(" ");t!=-1;t=line.find(" ")) 
		{
			v.push_back(line.substr(0,t));	//将字符串line下标0-t的字符存入v中 
			line=line.substr(t+1);
		}
		v.push_back(line);	//这里实则表示讲命令行中最后一个字符串赋值到vector中 
			
		//迭代器从命令行的第二个字符串 开始遍历 （第一个为工具名，不用处理） 
		vector<string>::iterator it;
		for(it=v.begin()+1;it!=v.end();it++)
		{
			string ss=*it;;
			if(ss.at(0)=='-' && ss.length()==2&&find(str,ss.at(1)))
			{
				int num=find(str,ss.at(1));
				if(num==1)
				{//表示无参的选项 
					m.insert(pair<string,string>(ss,"null"));
					//因为map的insert函数 没有直接插入两个数值的表示 这里也可以写为
						//m.insert(map<string,string>::value_type(ss,"null")) ;
						
				}
				else if(num==2 && (++it)!=v.end())
				{//有参数选项 
					if(isRepeat(m,ss))
						m[ss]=*it;	//如果有重复，修改key的值 
									//因为题目输出中说如果一个带参数的选项在命令行中出 现了多次,只输出最后一次出现时所带的参数。 
					else
						m.insert(pair<string,string>(ss,*it));
				}
				else	//有参数选项 （如 -w），但是后面没参数，也为不合法的命令  
					break;
			}
			else break;		//命令选项在格式命令里面不存在 直接跳出 例如documents 
			
			
		}
		cout<<"Case "<<i+1<<":"<<" ";
		map<string,string>::iterator itm;
		for(itm=m.begin();itm!=m.end();itm++)
		{
			if(itm->second !="null")
				cout<<itm->first<<" "<<itm->second<<" ";
			else
				cout<<itm->first<<" ";
		}		 
		cout<<endl;
	}
	
	return 0;
}

//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//using std::vector;
// 
//int main()
//{
//
//	int i,n;
//	vector<string> v;
//	vector<string>::iterator it;
//
//	string line;
//	getline(cin,line);	//从控制台读取一行命令行赋值给line 
//	int t;
//	//将字符串以空格形式切割存入vector中
//	for(t=line.find(" ");t!=-1;t=line.find(" ")) 
//	{
//		v.push_back(line.substr(0,t));	//将字符串line下标0-t的字符存入v中 
//		line=line.substr(t+1);
//	}
//
//	cout<<"line:"<<line<<endl;
//	for(it=v.begin();it!=v.end();it++)
//		cout<<*it<<","<<" ";
//	cout<<endl;
//	
//	v.push_back(line);
//	for(it=v.begin();it!=v.end();it++)
//		cout<<*it<<","<<" ";
//	cout<<endl;
//}
