//ccf 20140303 ������ѡ�� 

//���ⲽ�裺
//1����ÿ��������������ַ����Կո�ֿ�װ��vector<string>������
//2��Ȼ��������е�ÿ���ַ��������жϣ���һ���ַ����ǹ����������жϣ�Ȼ��������еڶ�����ʼ�жϵ�ǰ�ַ����Ƿ�Ϊ�Ϸ����
		//����Ҫ��Ϊ2�������һ���������������ʱ��һ�������������ʱ��
//�����������ʱ�����ַ�������Ϊ2���ԡ�-����ͷ���ҵڶ����ַ������ڸ�ʽ�ַ�����-->������Ϸ�Ϊ���
//�������������ʱ�����ַ�������Ϊ2���ԡ�-����ͷ���ҵڶ����ַ��������ڸ�ʽ�ַ����У���Ҫ������ַ��������Ƿ��ж�Ӧ�Ĳ����ַ�����
		//���У�������Ϸ������򲻺Ϸ���ֹͣ������
//3���Ϸ�����ļ��ϴ����map<string,string>�У���Ϊmap�е�key��Ҫ��key��������(�����-��ĸ��ͷ)����key-value��value����������Ų���ֵ���޲���Ϊnull����
		//map�в���Ϸ�����ʱӦ���Ǹ������Ƿ��Ѿ�����map�С������޲ε����ֱ�Ӳ��롣�����в����������������map��ֱ�Ӳ��������Ͳ���ֵ�����Ѿ����ھͽ�������Ĳ���ֵ���£�C++��map�ж���key��ͬ�Ĳ��벻�Ḳ�ǣ����Ƿ�������
//4������ʽ���map���ŵĺϷ�������

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
using std::map;
using std::vector;
 //�ж������Ƿ��ظ�
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
//��������ѡ�� �Ƿ���ڲ����Ƿ񸽴����� 
int find(string str,char c)	
{
	int i;
	int flag=str.find(c);	//����flagӦ���Ǳ�ʾ��str��c���±�ֵ 
	if(flag != -1)
	{//������� 
		if(flag<str.length()-1&&str.at(flag+1)==':')
		{//str.length()-1��ʾstr�е����ڶ����ֽ��±� ��Ϊ���ε�ѡ�����Ϊ�� 
			return 2; 
		}
		else{	//��ʾ�޲� 
			return 1;	
		}
		
	}
	 return 0;	//�������  
}

int main()
{
	string str;
	int i,n;
	
	cin>>str;
	cin>>n;
	getchar();	//��ʾ�Ӽ����ж���һ���ַ� �ڱ�������Ҫ�Ǳ�ʾ ������n�� ��ȡ�������Ļس��� ��Ϊ����Ҫ����n�������� 
	for(i=0;i<n;i++)
	{
		vector<string> v;
		map<string,string> m;
		string line;
		getline(cin,line);	//�ӿ���̨��ȡһ�������и�ֵ��line 
		int t;
		//���ַ����Կո���ʽ�и����vector��
		for(t=line.find(" ");t!=-1;t=line.find(" ")) 
		{
			v.push_back(line.substr(0,t));	//���ַ���line�±�0-t���ַ�����v�� 
			line=line.substr(t+1);
		}
		v.push_back(line);	//����ʵ���ʾ�������������һ���ַ�����ֵ��vector�� 
			
		//�������������еĵڶ����ַ��� ��ʼ���� ����һ��Ϊ�����������ô��� 
		vector<string>::iterator it;
		for(it=v.begin()+1;it!=v.end();it++)
		{
			string ss=*it;;
			if(ss.at(0)=='-' && ss.length()==2&&find(str,ss.at(1)))
			{
				int num=find(str,ss.at(1));
				if(num==1)
				{//��ʾ�޲ε�ѡ�� 
					m.insert(pair<string,string>(ss,"null"));
					//��Ϊmap��insert���� û��ֱ�Ӳ���������ֵ�ı�ʾ ����Ҳ����дΪ
						//m.insert(map<string,string>::value_type(ss,"null")) ;
						
				}
				else if(num==2 && (++it)!=v.end())
				{//�в���ѡ�� 
					if(isRepeat(m,ss))
						m[ss]=*it;	//������ظ����޸�key��ֵ 
									//��Ϊ��Ŀ�����˵���һ����������ѡ�����������г� ���˶��,ֻ������һ�γ���ʱ�����Ĳ����� 
					else
						m.insert(pair<string,string>(ss,*it));
				}
				else	//�в���ѡ�� ���� -w�������Ǻ���û������ҲΪ���Ϸ�������  
					break;
			}
			else break;		//����ѡ���ڸ�ʽ�������治���� ֱ������ ����documents 
			
			
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
//	getline(cin,line);	//�ӿ���̨��ȡһ�������и�ֵ��line 
//	int t;
//	//���ַ����Կո���ʽ�и����vector��
//	for(t=line.find(" ");t!=-1;t=line.find(" ")) 
//	{
//		v.push_back(line.substr(0,t));	//���ַ���line�±�0-t���ַ�����v�� 
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
