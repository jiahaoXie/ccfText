////ccf 20160403 ·������
////��string �洢�ַ���������Ϊ��ǰĿ¼�� ����forѭ����һ�δδ����������ַ��� 
//
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int p,pos;
	string str;
	cin>>p;
	getchar();	//���ջ��з�
	cin>>str;
	getchar();
	
	while(p--)
	{
		string tmp;
		getline(cin,tmp);
		
		//�ԷǸ�·�����д���
		if(tmp[0]!='/')
			tmp=str+'/'+tmp;
		
		//whileѭ�� ȥ�����'/'
		while(tmp.find("//") != -1)
		{
			pos=tmp.find("//");
			tmp.erase(pos,1);	//����Ϊ����һ��/ ��дΪtmp.erase(pos);���ǲ���pos֮�������Ԫ�� 
//			int count = 2;  
//            while(tmp[pos + count] == '/')  
//                count++;  
//            tmp.erase(pos, count-1);
			
		}
		//ȥ��/./ 
		while(tmp.find("/./") != -1)
		{
			pos=tmp.find("/./");
			tmp.erase(pos,2);	//����±�pos��ʼ�������ַ� Ҳ����/. 
			}
			
		//ȥ��/../ ��Ҳ�ǳ�������ӵ�һ��	���������������һ���������������
		while( (pos=tmp.find("/../")) != -1)
		{
			if(pos==0)
				tmp.erase(pos,3);	//����/.. 
			else
			{
				int spos=tmp.rfind('/',pos-1);	//�Ӻ���ǰ�����±�pos-1֮ǰ�ĵ�һ��/
				tmp.erase(spos,pos-spos+3); 	//��������3�е�/d3/.. (��Ϊ..��ʾ��һ��Ŀ¼ֻ��d2) 
			
			}
			
		}
		//ȥ����/��β
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
