//ccf 20170303 Markdown

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
////	string line;
////	line="";	//��ʾlineΪ0�ֽ� 
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
//	v.resize(0);	//resize()���������� ���������Ĵ�С  ����Ӧ���ǽ��䳤����Ϊ0 ��ʾ����� 
//	cout<<v.size()<<endl;
//	
//	for(it=v.begin();it != v.end();it++)
//		cout<<*it<<" ";
//	cout<<endl;
//	//cout<<v[0]<<endl;		//����������ɻ��һ���� ���vector�е�Ԫ�ز����±�v[0],v[1],...,v[i]��ʾ ���û�б䣿������
//							//���ǲ��õ��������Ԫ�� �����ı��� 
//	
//	return 0;
//}

//Markdown��Ϊ����ṹ�����ڽṹ��
//����ṹ�����Ϳ��Ը��ݵ�һ�����Ž��б������ṹ�����Ŀ���ͨ�����������
	//ÿ��������ڲ� ͨ�����ڽṹ���д�������Ҫ���п촦����Ϊ�������Ӻ��� ����ε��ã� 
		//���ڽṹ������ṹ�Ĵ���ͬ������Ҫ����ÿһ�е����ݡ� 
			//����ע�⵽���ڽṹ������:ǿ���ͳ�������  �������Ӻ�ǿ�������໥Ƕ�ף���ÿ�ָ�ʽ���ᳬ��һ��(���õ��ݹ����)
//��˳�����������ⲿ��Ϊ�ָ����顢�������ڽṹ����������ṹ���߼���main�����У��������ڽṹ���߼���parseLine�����С�
//ÿһ���﷨��Ӧ��һ��������

////����1 ������ַ�����string��ʾ ��vector<string> v�������� 
//��֪Ϊ��������˽�� 0��~ 
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
////parseLink������������������ 
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
////����ǿ�� 
//string parseEmphasize(string text)
//{
//	string result;
//	result += "<em>";
//	result+=text;
//	result += "</em>";
//	return result;
//}
////�������ڽṹ  ���ڽṹ������:ǿ���ͳ�������  �������Ӻ�ǿ�������໥Ƕ�ף���ÿ�ָ�ʽ���ᳬ��һ��(���õ��ݹ����)
//string parseLine(string line)
//{		//�������ڽṹ �ǳ����ӻ���ǿ��ʱ�������õ�i j�����������õ���Ч�ַ�����λ�� 
//	string result;
//	int i=0;
//	while(i<line.size())
//	{
//		if(line[i]=='[')
//		{//��ʾ��ʼ����������
//			string text,link;
//			int j=i+1;
//			while(line[j] != ']')	j++;
//			text=line.substr(i+1,j-i-1);	//��ȡ��Ч�ַ�text
//			
//			i=j+1;
//			assert(line[i]=='(');	//���ö��� ��ʾ�߼��ϵ�˳��	������[text]�������link�� 
//			while(line[j] != ')') j++;
//			link=line.substr(i+1,j-i-1);	// ��ȡ��Ч�ַ�link
//			
//			text=parseLine(text);	//�ݹ����
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
//			text=parseLine(text);	//�ݹ����
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
////�������� ��������������� 
//string parseParagraph(vector<string> &v)
//{
//	string result;
//	result+="<p>";//��һ��֮ǰ����<p> 
//	for(int i=0;i<v.size();i++)
//	{//������ַ������н��� 
//		result+=parseLine(v[i]);	
//		if(v.size() != 0 && i != v.size()-1)
//			result+='\n';
//	}
//	result+="</p>\n";
//	return result;
//	
//}
//
////�������� 
//string parseTile(vector<string> &v)
//{
//	assert(v.size()==1);	//��Ϊ����ֻ��һ�� �ö���ȷ���߼��ϵ�׼ȷ��
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
//	result+=inttostring(level);	//���ú��� ��intת��Ϊstring���� 
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
//	result +="<ul>\n";	//�����б���ǰ�����<ul> 
//	int j;
//	for(int i=0;i<v.size();i++)
//	{
//		result+="<li>";
//		j=1;
//		while(v[i][j]==' ')	j++;	
//		//��Ϊ�����б� ÿ����*��ͷ ������һ�������ո� Ȼ����Ǳ�������
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
//	int type;	//������־λ��ʾ ������� ���У�0�������䣨1�������⣨2���������б�3�� 
//	string result;
//	while(getline(cin,line) || v.size()>0 )
//	{
//		if(v.empty())	//�������Ϊ���� ����ǿ���ɾ�� ������һ������
//		{
//			if(type != 0)
//			{
//				switch(type)
//				{
//					case 1:result+=parseParagraph(v);break;
//					case 2:result+=parseTile(v);break;
//					case 3:result+=parseUnorderlist(v);break;
//				}
//				v.resize(0);	//resize()���������� ���������Ĵ�С  ����Ӧ���ǽ��䳤����Ϊ0 ��ʾ����գ�ɾ�����У� 
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
//		line=""; ////��ʾlineΪ0�ֽ� 
//	}
//	
//	cout<<result<<endl;
//	return 0;
//}

////��1 ac100
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



