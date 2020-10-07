//ccf 20161203 Ȩ�޲�ѯ
 //�����Ŀ�ؼ����뵽���������ṹ������ ���ҽṹ���������Ƕ��ʹ��
 //��һ������3���ṹ�������ʾ�û�����ɫ��Ȩ�޵���Ϣ
// �ڶ�����Ȼ���������Ȩ�ޡ���ɫ���û�����Ϣ������Ҫ�����ϵ��һ���û������ж����ɫ��һ����ɫ�ж��Ȩ��
//�������������ѯ��Ϣ����ʼ��ѯ���Ȳ�ѯ�û���Ϣ�����û����ڣ��ٱ����û��Ľ�ɫ���ٱ���ÿ����ɫ��Ȩ����Ϣ����Ȩ���������ʱ���жϲ�ѯ�����࣬���ݲ�ѯ������ı��ʶ������ֵ��
//���Ĳ������ݱ�ʶ����������

#include<iostream>
#include<string>
using namespace std;

//Ȩ����Ϣ 
struct Privilege{
	string name;
	int level;
}privilege[101];

//��ɫ��Ϣ 
struct Role{
	string name;
	int s;
	struct Privilege pri[11];	//ע����Ŀ���� ÿ����ɫ�����г���10��Ȩ�� 
}role[101];

//�û���Ϣ
struct User{
	string name;
	int t;
	struct Role r[11];
}user[101];

//�����Ӻ��� ������������Ȩ��
struct Privilege setPri(string tmp)
{
	struct Privilege p;
	int pos;
	if((pos=tmp.find(':')) != -1)
	{
		p.name=tmp.substr(0,pos);	//��ȡ�±��0��ʼ��pos���ַ�
		p.level=tmp.at(pos+1)-'0'; 
	 } 
	 else
	 {
	 	p.name=tmp;
	 	p.level=-1;
	 }
	 return p;	//һ��Ҫ�ǵ�д�Ϸ���ֵ pʵ��Ϊ��ʱ�ṹ����� 
	 
 } 
 
 int searchRol(string roleName,int roleNum)
 {
 	for(int i=0;i<roleNum;i++)
 		if(roleName==role[i].name)
 			return i;
 	
 	return -1;
 }
 
int searchUser(string userName, int userNum)
{
	for(int i=0;i < userNum; i++)
		if(userName==user[i].name)
			return i;
	
	return -1;
}

int main()
{
	int i,j,k;
	int roleNum,userNum;
	string priName,roleName,userName;
	int p;
	//���Ȩ������ 
	cin>>p;
	getchar();
	for(i=0;i<p;i++)
	{
		getline(cin,priName);
		//��Ϊ����Ȩ��������Ҫ���ַ������н��� ��ɫ����Ҳ��Ҫ���ַ�������
		//�������ｫ�������ķ�������Ϊһ���Ӻ������Ӹ�Ч 
		privilege[i]=setPri(priName);
	}
	//�����ɫ
	cin>>roleNum;
	getchar();
	for(i=0;i<roleNum;i++)
	{
		cin>>role[i].name>>role[i].s;	//���������ɫ���ͽ�ɫӵ�е�Ȩ������
		for(j=0;j<role[i].s;j++)
		{
			cin>>priName;		//��������Ӧ��дΪȨ������privilege[]ƥ�� 
								//��Ϊ��ɫ��Ӧ��Ȩ���б�R �Σ��е�Ȩ�޶���֮ǰ��P �Σ����ֹ��ģ�Ȩ�޿����ظ����֣�������ȼ���Ȩ���ظ����֣��Եȼ���ߵ�Ϊ׼
			role[i].pri[j]=setPri(priName);
		 } 
	}
	//�����û�
	cin>>userNum;
	getchar();
	for(i=0;i<userNum;i++)
	{
		cin>>user[i].name>>user[i].t;
		for(j=0;j<user[i].t;j++)
		{//������Ӧ�Ľ�ɫ�� ����role[]����ƥ�� 
			//��roles[]��Ѱ�Ҷ�Ӧ��role��ƥ�䵽��user����
			cin>>roleName;	
			user[i].r[j]=role[searchRol(roleName, roleNum)];
		}
	 } 
	 
	 //���������Ϣ����ʼ����
	 int q;
	 cin>>q;
	 for(i=0;i<q;i++)
	 {
	 	int maxLevel=-1;	//��priͬ����Ȩ�޵���ߵȼ�
	 	bool flag=false;	// //flag��ʾ�����user�Ƿ��������pri.��Ϊflag����һ��ȫ�����Գ�ʼֵΪfalse 
	 	Privilege prit;	//������ʱҪ��ѯ��user��role��privilege���� 
	 	Role rolet;
	 	User usert;
	 	cin>>userName>>priName;	//�������ѯȨ�� 
	 	if(searchUser(userName,userNum) != -1)	//���ڴ��û�
		 {
		 	usert=user[searchUser(userName,userNum)];
		 	prit=setPri(priName);	
		 	//��������
			 for(j=0;j<usert.t;j++)
			 {//�����û��е�ÿһ����ɫ
			 	rolet=usert.r[j];
				for(k=0;k<rolet.s;k++)
				{//������ɫ�е�ÿһ��Ȩ��
					 if(rolet.pri[k].name==prit.name)	//ƥ�� 
					{
						if(rolet.pri[k].level==-1 && prit.level == -1)	//��ѯ��ʵ�� ��Ȩ�� ���޵ȼ� 
							flag=true;
						else if(rolet.pri[k].level!=-1 && prit.level == -1)	//��ѯ�޵ȼ� ʵ��ֵ�еȼ� ������֣�Ҳ����Ȩ�޵ĵȼ��� 
						{
							flag=true;
							if (maxLevel < rolet.pri[k].level)  maxLevel = rolet.pri[k].level;  
						}
						else if(rolet.pri[k].level!=-1 && prit.level != -1)	//��ѯ��ʵ�� ���еȼ� 
						{
							 if (rolet.pri[k].level >= prit.level) flag = true;
							 /*����Խ���ʾȨ�޵ȼ�Խ�ߡ�ϵͳ�涨����û�����ĳ��ĳһ�ȼ���Ȩ�ޣ���ô��Ҳ���Զ����и�����͵ȼ���Ȩ�ޡ�*/ 
						 } 
					}	
				 } 
			 	
			  } 
		  } 
		  
		  //�����Ƿ������ݵĽ���������  
        if (!flag) cout << "false" << endl;  
        else if (maxLevel != -1) cout << maxLevel << endl;  
        else cout << "true" << endl; 
	 	
	  } 
	  
	return 0;
 } 
