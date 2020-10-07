//ccf 20170303 Markdown

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
////	string line;
////	line="";	//表示line为0字节 
////	cout<<line.size()<<endl;
////	cout<<"line: "<<line<<endl;
//	
//	string line("aaa,bbb,ccc");
//	vector<string> v;
//	vector<string>::iterator it;
//	 
//	v.push_back(line);
//	cout<<v.size()<<endl; 
//	for(it=v.begin();it != v.end();it++)
//		cout<<*it<<" ";
//	cout<<endl;
//	
//	cout<<"==============================="<<endl;
//	v.resize(0);	//resize()函数的作用 调整容器的大小  这里应该是将其长度置为0 表示将清空 
//	cout<<v.size()<<endl;
//	
//	for(it=v.begin();it != v.end();it++)
//		cout<<*it<<" ";
//	cout<<endl;
//	//cout<<v[0]<<endl;		//但是这里很疑惑的一点是 如果vector中的元素采用下标v[0],v[1],...,v[i]表示 输出没有变？？？？
//							//但是采用迭代器输出元素 则结果改变了 
//	
//	return 0;
//}

//Markdown分为区块结构和行内结构。
//区块结构的类型可以根据第一个符号进行辨别，区块结构结束的可以通过空行来辨别。
	//每个区域块内部 通过行内结构进行处理（所以要将行快处理定义为单独的子函数 供多次调用） 
		//行内结构与区块结构的处理不同，则需要分析每一行的内容。 
			//而且注意到行内结构有两种:强调和超级链接  超级链接和强调可以相互嵌套，但每种格式不会超过一层(利用到递归调用)
//因此程序的两个主题部分为分割区块、处理行内结构。处理区块结构的逻辑在main函数中，处理行内结构的逻辑在parseLine函数中。
//每一种语法对应于一个函数。

////代码1 输入的字符串用string表示 用vector<string> v保存内容 
//不知为何输出不了结果 0分~ 
//#include<iostream>
//#include<string>
//#include<vector>
//#include<cassert>
//using namespace std;
//
//string inttostring(int level)
//{
//	char str[25];
//	string s;
//	s=itoa(level, str, 10);
//	return s;
//}
//
////parseLink（）用来解析超链接 
//string parseLink(string text,string link)
//{
//	string result;
//	result+="<a href =\"";
//	result+=link;
//	result+="\">";
//	result+=text;
//	result+="</a>";
//	
//	return result;
//}
//
////解析强调 
//string parseEmphasize(string text)
//{
//	string result;
//	result += "<em>";
//	result+=text;
//	result += "</em>";
//	return result;
//}
////解析行内结构  行内结构有两种:强调和超级链接  超级链接和强调可以相互嵌套，但每种格式不会超过一层(利用到递归调用)
//string parseLine(string line)
//{		//解析行内结构 是超链接还是强调时，；利用到i j两个变量来得到有效字符串的位置 
//	string result;
//	int i=0;
//	while(i<line.size())
//	{
//		if(line[i]=='[')
//		{//表示开始解析超链接
//			string text,link;
//			int j=i+1;
//			while(line[j] != ']')	j++;
//			text=line.substr(i+1,j-i-1);	//截取有效字符text
//			
//			i=j+1;
//			assert(line[i]=='(');	//设置断言 表示逻辑上的顺序	案例中[text]后紧跟（link） 
//			while(line[j] != ')') j++;
//			link=line.substr(i+1,j-i-1);	// 截取有效字符link
//			
//			text=parseLine(text);	//递归调用
//			link=parseLine(link);
//			result+= parseLink(text,link);
//			
//			i=j+1;
//		}
//		else if(line[i]=='_')
//		{
//			string text;
//			int j=i+1;
//			while(line[j] != '_') j++;
//			text=line.substr(i+1,j-i-1);
//			
//			text=parseLine(text);	//递归调用
//			result+=parseEmphasize(text);
//			
//			i=j+1; 
//			 
//		}
//		else{
//			result+=line[i];
//			i++;
//		}
//		 
//	}
//	
//	return result;
//		
//}
//
////解析段落 段落可能有若干行 
//string parseParagraph(vector<string> &v)
//{
//	string result;
//	result+="<p>";//第一行之前加上<p> 
//	for(int i=0;i<v.size();i++)
//	{//输入的字符串进行解析 
//		result+=parseLine(v[i]);	
//		if(v.size() != 0 && i != v.size()-1)
//			result+='\n';
//	}
//	result+="</p>\n";
//	return result;
//	
//}
//
////解析标题 
//string parseTile(vector<string> &v)
//{
//	assert(v.size()==1);	//因为标题只有一行 用断言确保逻辑上的准确性
//	int level=1;
//	int i=0;
//	string heading=parseLine(v[0]);
//	
//	while(heading[i]=='#')	i++;
//	level=i;
//	while(heading[i]==' ')	i++;
//	
//	string result;
//	result+="<h";
//	result+=inttostring(level);	//调用函数 将int转换为string类型 
//	result+='>';
//	
//	result+=heading.substr(i);
//	
//	result+="</h";
//	result+=inttostring(level);
//	result+=">\n";
//	
//	return result;
//	
//}
//
//string parseUnorderlist(vector<string> &v)
//{
//	string result;
//	result +="<ul>\n";	//无序列表最前面加上<ul> 
//	int j;
//	for(int i=0;i<v.size();i++)
//	{
//		result+="<li>";
//		j=1;
//		while(v[i][j]==' ')	j++;	
//		//因为无序列表 每行以*开头 接着有一个或多个空格 然后才是标题内容
//		string tmp=v[i].substr(j);
//		result+=parseLine(tmp);
//		result+="</li>\n"; 
//	}
//	result+="</ul>\n";
//	
//	return result;
//}
//
//int main()
//{
//	string line;
//	vector<string> v;
//	int type;	//设立标志位表示 输入的是 空行（0），段落（1），标题（2），无序列表（3） 
//	string result;
//	while(getline(cin,line) || v.size()>0 )
//	{
//		if(v.empty())	//输入如果为空行 输出是空行删除 处理上一个区块
//		{
//			if(type != 0)
//			{
//				switch(type)
//				{
//					case 1:result+=parseParagraph(v);break;
//					case 2:result+=parseTile(v);break;
//					case 3:result+=parseUnorderlist(v);break;
//				}
//				v.resize(0);	//resize()函数的作用 调整容器的大小  这里应该是将其长度置为0 表示将清空（删除空行） 
//				type=0;
//			}
//		}
//		else if(line[0]=='#')
//		{
//			v.push_back(line);
//			type=2;
//		}
//		else if(line[0]=='*')
//		{
//			v.push_back(line);
//			type=3;
//		}
//		else
//		{
//			v.push_back(line);
//			type=1;
//		}
//		line=""; ////表示line为0字节 
//	}
//	
//	cout<<result<<endl;
//	return 0;
//}

////答案1 ac100
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

string to_string(int i) {
//    char buffer[10];
//    return string(itoa(i, buffer, 10));
	char str[25];
	string s;
	s=itoa(i, str, 10);
	return s;
}

string parseEmphasize(string text) {
    string result;
    result += "<em>";
    result += text;
    result += "</em>";
    return result;
}

string parseLink(string text, string link) {
    string result;
    result += "<a href=\"";
    result += link;
    result += "\">";
    result += text;
    result += "</a>";
    return result;
}

string parseLine(string line) {
    string result;
    int i = 0;
    while(i<line.size()) {
        if(line[i]=='[') {
            string text, link;
            
			int j = i+1;
            while(line[j] != ']') j++;
            text = line.substr(i+1, j-i-1);
            
            i = j+1;
            assert(line[i]=='(');
            while(line[j]!=')') j++;
            link = line.substr(i+1, j-i-1);
            
            text = parseLine(text);
            link = parseLine(link);
            result += parseLink(text, link);
            
			i = j+1;
        }
        else if(line[i]=='_') {
            string text;
            int j = i+1;
            while(line[j]!='_') j++;
            text = line.substr(i+1, j-i-1);
            
            text = parseLine(text);
            result += parseEmphasize(text);
            i = j + 1;
        }
        else {
            result += line[i];
            i++;
        }
    }
    return result;
}

string parseHeading(vector<string> &contents) {
    assert(contents.size()==1);
    int level = 1;
    int i = 0;
    string heading = parseLine(contents[0]);
    
    while(heading[i] == '#') i++;
    level = i;
    while(heading[i] == ' ') i++;
    
    string result;
    result += "<h";
    result += to_string(level);
    result += '>';
    
    result += heading.substr(i);
    
	result += "</h";
    result += to_string(level);
    result += ">\n";
    
    return result;
}

string parseParagraph(vector<string> &contents) {
    string result;
    result += "<p>";
    for(int i=0; i<contents.size(); i++) {
        result += parseLine(contents[i]);
        if(contents.size() != 0 && i != contents.size()-1) 
			result += '\n';
    }
    result += "</p>\n";
    return result;
}

string parseUnorderedList(vector<string> &contents) {
    string result;
    result += "<ul>\n";
    int j;
    for(int i=0; i<contents.size(); i++) {
        result += "<li>";
        j = 1;
        while(contents[i][j] == ' ') j++;
        result += parseLine(contents[i].substr(j));
        result += "</li>\n";
    }
    result += "</ul>\n";
    return result;
}

int main() 
{
    string line;
    vector<string> contents;
    int blockType; // 0:empty, 1:paragraph, 2:heading, 3:unordered list
    string result;
    while(getline(cin, line) || contents.size()>0) {
        if(line.empty()) {
            if(blockType != 0) {
                switch(blockType) {
                    case 1: result += parseParagraph(contents); break;
                    case 2: result += parseHeading(contents); break;
                    case 3: result += parseUnorderedList(contents); break;
                }
                contents.resize(0);
                blockType = 0;
            }
        }
        else if(line[0] == '#') {
            contents.push_back(line);
            blockType = 2;
        }
        else if(line[0] == '*') {
            contents.push_back(line);
            blockType = 3;
        }
        else {
            contents.push_back(line);
            blockType = 1;
        }
        line = "";
    }
    cout << result<<endl;
    return 0;
} 



