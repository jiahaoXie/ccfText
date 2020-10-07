//ccf 20170903 JSON��ѯ 

//Json��һ���ݹ����ݽṹ����˿���ʹ�ú����ĵݹ���������н���(��Ϊ����ṹ�����ж�� �漰��Ƕ��)��
//ÿһ�����ݶ�Ӧһ������������������parseStringʵ�ֽ����ַ����Ĺ��ܣ�parseObjectʵ�ֽ�������Ĺ��ܡ�
//�������������幦�ܾ������α���ÿһ���ַ��������ַ��ж��Ƿ����ַ����Ŀ�ʼ������Ŀ�ʼ������������Ӧ�Ĵ���
//json��һ����ֵ�ԵĽṹ����˿�����map�洢��map�ļ������ò�ѯ�ĸ�ʽ����С����.���ָ����ļ���

#include<iostream>
#include<cassert>	//���� ����������׽�߼�����
#include<map>
#include<string>
using namespace std;
using std::map;

//�����ַ��� 
string parseString(string& str,int& i)
{
	if(str[i]=='"')	i++;		 
	else assert (0);
	
	string tmp;
	while(i<str.size())
	{
	//	if(str[i]=='\\'||str[i]=='\"')	//�����ԭ������д��str[i]=='\"' ��������(��һ��ֻ��10��~) 
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

//�������� 
void parseObject(string &str, string pre, map<string, string> &m, int &i)
{
	if(str[i]=='{')	i++;		//string������{ ��ʾ�����ݿ�ʼ���� 
	else assert (0);				//����else assert(0)	��ʾ��׽������� ������� ����ֱ�ӱ���
	
	string key,value;
	bool strType=false;	//False is key,True is value
	while(i<str.size())
	{
		if(str[i]=='"')	//�����ַ������� ��ȡ�����ַ� 
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
					//pre==""?"":"." ���������ж�pre�Ƿ�Ϊ"" 
					//һ�������preΪ== ���ǵ����ݹ���ã��ж��ṹ��ʱ����С�����ʾ���ṹ	(�������) 
			}
		}
		else if(str[i]==':')	//����value 
		{
			strType=true;
			i++;
		}
		else if(str[i]=='{')	//��ʾ����ṹ�ж�� �����ݹ� 
		{
			m[key]="";	//��ʾ��һ������ 
			parseObject(str,key,m,i);	//�����ݹ�
		}
		else if(str[i]==',')	//�ж����ֵ�ԣ���������һ�� 
		{
			strType=false;
			i++;
			
		}
		else if(str[i]=='}')
			break;	//JSON���ݱ������� 
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
		cin.ignore();	//cin.peek()�ķ���ֵ��һ��char�͵��ַ����䷵��ֵ��ָ��ָ��ĵ�ǰ�ַ� 
						//������������ ����ʱenter���� 
	for(j=0;j<n;j++)	
	{	//����n��JSON���� 
		string tmp;
		getline(cin,tmp);
		json+=tmp;
	}
	
	map<string,string> m1;
	
	parseObject(json,"",m1,i);	
		//����JSON���� ��Ϊstring���ݰ�����Object�� �������ȵ��ö�������������н���
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

