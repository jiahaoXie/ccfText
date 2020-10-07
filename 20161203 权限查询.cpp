//ccf 20161203 权限查询
 //这个题目关键是想到利用三个结构体数组 并且结构体数组可以嵌套使用
 //第一步：用3个结构体数组表示用户、角色、权限的信息
// 第二步：然后就是输入权限、角色、用户的信息。这里要理清关系：一个用户可以有多个角色，一个角色有多个权限
//第三步：输入查询信息，开始查询：先查询用户信息，若用户存在，再遍历用户的角色，再遍历每个角色的权限信息，当权限名字相等时，判断查询的种类，根据查询的种类改变标识变量的值。
//第四步：根据标识变量输出结果

#include<iostream>
#include<string>
using namespace std;

//权限信息 
struct Privilege{
	string name;
	int level;
}privilege[101];

//角色信息 
struct Role{
	string name;
	int s;
	struct Privilege pri[11];	//注意题目条件 每个角色不得有超过10中权限 
}role[101];

//用户信息
struct User{
	string name;
	int t;
	struct Role r[11];
}user[101];

//定义子函数 用来解析各个权限
struct Privilege setPri(string tmp)
{
	struct Privilege p;
	int pos;
	if((pos=tmp.find(':')) != -1)
	{
		p.name=tmp.substr(0,pos);	//截取下标从0开始的pos个字符
		p.level=tmp.at(pos+1)-'0'; 
	 } 
	 else
	 {
	 	p.name=tmp;
	 	p.level=-1;
	 }
	 return p;	//一定要记得写上返回值 p实质为临时结构体变量 
	 
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
	//输出权限类型 
	cin>>p;
	getchar();
	for(i=0;i<p;i++)
	{
		getline(cin,priName);
		//因为这里权限输入需要对字符串进行解析 角色输入也需要对字符串解析
		//所以这里将解析：的方法定义为一个子函数更加高效 
		privilege[i]=setPri(priName);
	}
	//输入角色
	cin>>roleNum;
	getchar();
	for(i=0;i<roleNum;i++)
	{
		cin>>role[i].name>>role[i].s;	//首先输入角色名和角色拥有的权限数量
		for(j=0;j<role[i].s;j++)
		{
			cin>>priName;		//下面这里应该写为权限名与privilege[]匹配 
								//因为角色对应的权限列表（R 段）中的权限都是之前（P 段）出现过的，权限可以重复出现，如果带等级的权限重复出现，以等级最高的为准
			role[i].pri[j]=setPri(priName);
		 } 
	}
	//输入用户
	cin>>userNum;
	getchar();
	for(i=0;i<userNum;i++)
	{
		cin>>user[i].name>>user[i].t;
		for(j=0;j<user[i].t;j++)
		{//输入相应的角色名 并与role[]进行匹配 
			//从roles[]中寻找对应的role，匹配到此user名下
			cin>>roleName;	
			user[i].r[j]=role[searchRol(roleName, roleNum)];
		}
	 } 
	 
	 //输入查找信息，开始查找
	 int q;
	 cin>>q;
	 for(i=0;i<q;i++)
	 {
	 	int maxLevel=-1;	//与pri同名的权限的最高等级
	 	bool flag=false;	// //flag表示输入的user是否有输入的pri.因为flag不能一错全错，所以初始值为false 
	 	Privilege prit;	//保存临时要查询的user、role、privilege变量 
	 	Role rolet;
	 	User usert;
	 	cin>>userName>>priName;	//输入待查询权限 
	 	if(searchUser(userName,userNum) != -1)	//存在此用户
		 {
		 	usert=user[searchUser(userName,userNum)];
		 	prit=setPri(priName);	
		 	//处理数据
			 for(j=0;j<usert.t;j++)
			 {//遍历用户中的每一个角色
			 	rolet=usert.r[j];
				for(k=0;k<rolet.s;k++)
				{//遍历角色中的每一个权限
					 if(rolet.pri[k].name==prit.name)	//匹配 
					{
						if(rolet.pri[k].level==-1 && prit.level == -1)	//查询与实际 的权限 都无等级 
							flag=true;
						else if(rolet.pri[k].level!=-1 && prit.level == -1)	//查询无等级 实际值有等级 输出数字（也就是权限的等级） 
						{
							flag=true;
							if (maxLevel < rolet.pri[k].level)  maxLevel = rolet.pri[k].level;  
						}
						else if(rolet.pri[k].level!=-1 && prit.level != -1)	//查询与实际 都有等级 
						{
							 if (rolet.pri[k].level >= prit.level) flag = true;
							 /*数字越大表示权限等级越高。系统规定如果用户具有某类某一等级的权限，那么他也将自动具有该类更低等级的权限。*/ 
						 } 
					}	
				 } 
			 	
			  } 
		  } 
		  
		  //根据是否处理数据的结果进行输出  
        if (!flag) cout << "false" << endl;  
        else if (maxLevel != -1) cout << maxLevel << endl;  
        else cout << "true" << endl; 
	 	
	  } 
	  
	return 0;
 } 
