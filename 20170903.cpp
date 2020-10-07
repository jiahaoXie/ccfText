//ccf 20170903 JSON查询 

//Json是一个递归数据结构，因此可以使用函数的递归调用来进行解析(因为对象结构可能有多层 涉及到嵌套)。
//每一类数据对应一个解析函数，代码中parseString实现解析字符串的功能，parseObject实现解析对象的功能。
//解析函数的主体功能就是依次遍历每一个字符，根据字符判断是否是字符串的开始、对象的开始……并进行相应的处理。
//json是一个键值对的结构，因此可以用map存储。map的键可以用查询的格式，用小数点.来分隔多层的键。

#include<iostream>
#include<cassert>	//断言 用来消除捕捉逻辑错误
#include<map>
#include<string>
using namespace std;
using std::map;

//解析字符串 
string parseString(string& str,int& i)
{
	if(str[i]=='"')	i++;		 
	else assert (0);
	
	string tmp;
	while(i<str.size())
	{
	//	if(str[i]=='\\'||str[i]=='\"')	//错误的原因在于写了str[i]=='\"' ？？？？(这一句只有10分~) 
		if(str[i]=='\\')
		{
			i++;
			tmp+=str[i];
			i++;
		}
		else if(str[i]=='"')	 
			break;
		else 
		{
			tmp+=str[i];
			i++;
		}
			
	}
	if(str[i] == '"') i++;
    else assert(0);
    
	return tmp;
}

//解析对象 
void parseObject(string &str, string pre, map<string, string> &m, int &i)
{
	if(str[i]=='{')	i++;		//string遍历到{ 表示对数据开始解析 
	else assert (0);				//这里else assert(0)	表示捕捉输入错误 如果不是 程序直接报错
	
	string key,value;
	bool strType=false;	//False is key,True is value
	while(i<str.size())
	{
		if(str[i]=='"')	//进行字符串解析 提取有用字符 
		{
			string tmp=parseString(str,i);
			if(strType)	//value 
			{
				value=tmp;
				m[key]=value;
			}
			else		//key
			{
				key=pre+(pre==""?"":".")+tmp;	
					//pre==""?"":"." 这里用来判断pre是否为"" 
					//一般情况下pre为== 但是当它递归调用（有多层结构）时，用小数点表示多层结构	(妙！！！！) 
			}
		}
		else if(str[i]==':')	//解析value 
		{
			strType=true;
			i++;
		}
		else if(str[i]=='{')	//表示对象结构有多层 函数递归 
		{
			m[key]="";	//表示是一个对象 
			parseObject(str,key,m,i);	//函数递归
		}
		else if(str[i]==',')	//有多个键值对，解析到下一个 
		{
			strType=false;
			i++;
			
		}
		else if(str[i]=='}')
			break;	//JSON数据遍历结束 
		else i++;
	 } 
	 
	 if(str[i] == '}') i++;
     else assert(0);
}
int main()
{
	int n,m,i=0,j=0;
	
	string json;
	cin>>n>>m;
	if(cin.peek()=='\n')
		cin.ignore();	//cin.peek()的返回值是一个char型的字符，其返回值是指针指向的当前字符 
						//这里用来屏蔽 输入时enter换行 
	for(j=0;j<n;j++)	
	{	//输入n行JSON数据 
		string tmp;
		getline(cin,tmp);
		json+=tmp;
	}
	
	map<string,string> m1;
	
	parseObject(json,"",m1,i);	
		//解析JSON数据 因为string数据包含在Object中 所以首先调用对象解析函数进行解析
	string query;
	if(cin.peek()=='\n')
		cin.ignore();
	for(j=0;j<m;j++)
	{
		getline(cin,query);
		if(m1.find(query)==m1.end())
			cout<<"NOTEXIST"<<endl;
		else 
		{
			if(m1[query]=="")
				cout<<"OBJECT"<<endl;
			else
				cout<<"STRING "<<m1[query]<<endl;
		}
		
			
	}
	 
	return 0;
 } 

