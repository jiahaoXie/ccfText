////ccf 20150903 ģ������ϵͳ
 //����һ string�洢�����ģ���ַ���  map<string,string>�洢����ı����ͱ�����ֵ 
 //100�� 
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
// 	getchar(); //���������enter�� 
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
////		int startQuote=t.find("\"");	//�����ַ���t�е�һ�γ���"���±�ֵ 
////		int endQuote=t.rfind("\"");		//�����ַ���t�����һ�γ���"���±�ֵ
////		value=t.substr(startQuote+1,endQuote-startQuote-1);	//����ȥ˫���ŵ���Ч�ַ�������mao�� 
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
//	//����ģ���д��д����ŵ��ַ��� ����map�е�keyֵ����ƥ��  ��value�������
//	int startpos,endpos;
//	int startPoint = 0; // start position for string.find
//	while(true)
//	{
//		startpos=str.find("{{",startPoint);	//startpos��ʾ{{֮ǰ���±�λ�� 
//		endpos=str.find("}}",startpos);		//end��ʾ{{֮ǰ���±�λ��
//		if(startpos<0 || endpos<0) break;	//ѭ������ 
//		varKey=str.substr(startpos+3,endpos-startpos-4);	//��ȡ��Ч���ַ���  ��Ϊ{{ name }}������name֮�仹�пո� 
//											
//		varValue="";	//���Ƚ�ֵ��ֵΪ���ַ��� (������address��ƥ�������Ϊ��) 
//		if(m.find(varKey)!=m.end())	//�ٺ�map�е�keyֵ����ƥ�� 
//			varValue=m[varKey];
//		str2+=str.substr(startPoint,startpos-startPoint)+varValue;
//		startPoint=endpos+2; 	//+2Ϊ��ȥ }} 
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
	{	//����ģ�� 
		string tmp;
		getline(cin,tmp);
		str+=tmp+'\n';
	//	v.push_back(tmp);
	}
	while(N--)
	{	//��������ͱ�����ֵ 
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
		str.replace(startPos,endPos-startPos+2,(m.count(key)>0?m[key]:""));	//ֱ�����ַ������ 
		//v[i].replace(startPos,endPos-startPos+2,(m.count(key)>0?m[key]:""));
	//	startPoint+=m.count(key)>0?m[key].length():0;	//��һ���ܹؼ� �����Ǳ����ظ��滻 
	}
	cout<<str;
	
	return 0;
}

////����string str1[],str2[]�ֱ�洢�����ģ��������ģ�� map<string,string>�洢����ı����ͱ�����ֵ
////80��~ 
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
//		int startQuote=t.find("\"");	//�����ַ���t�е�һ�γ���"���±�ֵ 
//		int endQuote=t.rfind("\"");		//�����ַ���t�����һ�γ���"���±�ֵ
//		value=t.substr(startQuote+1,endQuote-startQuote-1);	//����ȥ˫���ŵ���Ч�ַ�������map�� 
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
//////ͬ����˼· ����string str1[],str2[]�ֱ�洢�����ģ��������ģ�� ������string value[i][j] �洢����ı���
////ֻ��80�֣��� 
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
//	getchar();	//������ ����enter�� 
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
//		//��ȡ˫�����������Ч�ַ� �ö�ά�ַ�������ķ�ʽ�洢
//		 
//	}
//	//�������ģ���в�ѯ{{ **** }}������ �����ά�ַ����������ƥ��
//	int flag=0;//����һ������λ 1��ʾƥ��ɹ� 0��ʾƥ�䲻�ɹ� 
//	 for(i=0;i<m;i++)
//	 {
//	 	while(true)
//	 	{
//	 		int sstr=str1[i].find("{{");	//�ҵ�ָ���±� 
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
//			 str2[i]+=str1[i].substr(0,sstr)+tmp;	//��������֮ǰ���ַ����滻����ַ��� ��ֵ��str2[i] 
//			 str1[i]=str1[i].substr(estr+2);
//		 }
//		str2[i]+=str1[i];
//		cout<<str2[i]<<endl; 
//	 	
//	 }
//	 return 0;
// } 



