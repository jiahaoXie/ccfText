//ccf 20160903 炉石传说 
//0 1 表示两个玩家； 
//用一个结构体或者类来存储王佳或者随从的生命值和攻击力		
//用vector<>v[2] 存储两个玩家的角色 

#include<iostream>
#include<vector>
#include<string>
using namespace  std;

class  Status{
	public:
		int health;
		int attack;
		Status(int h,int a)
		{
			health=h;
			attack=a;
		}
};
//vector<Status> v[2];
int main()
{
	vector<Status> v[2];
	int n;
	v[0].push_back(Status(30,0));	//双方英雄初始化 
	v[1].push_back(Status(30,0));
	
	cin>>n;
	getchar();
	
	int player=0; //首先是一号玩家 
	while(n--)
	{
		
		string tmp;
		cin>>tmp;
		if(tmp=="summon")
		{
			int position,attack,health;
			cin>>position>>attack>>health;
			v[player].insert(v[player].begin()+position,Status(health,attack));
		//	cout<<"insert :"<<v[player][position].health<<" "<<v[player][position].attack<<endl; 
				//指定位置插入 
		}
		else if(tmp=="attack")
		{
			int attacker,defender;
			cin>>attacker>>defender;
			//双方玩家制定位置的角色 的生命值都要都要变化。最后判断攻击结束后 生命值是否小于等于0 是，则擦除数据
			v[player][attacker].health-= v[!player][defender].attack;
			v[!player][defender].health-=v[player][attacker].attack;
			
			if(	v[player][attacker].health <= 0 &&attacker!=0 )
				v[player].erase(v[player].begin()+attacker);
			
			if(	v[!player][defender].health <= 0 && defender!=0 )
				v[!player].erase(v[!player].begin()+defender);
					
		}
		else if(tmp=="end")
		{
			if(player==0)	player=1;
			else player=0;
		//	player = !player;
		//	continue;
		}
		
	}
	
	//程序输出
	if(v[0][0].health>0 && v[1][0].health>0)
		cout<<0<<endl;
	else if(v[0][0].health<=0 && v[1][0].health>0) 
		cout<<-1<<endl;
	else if(v[0][0].health>0 && v[1][0].health<=0)
		cout<<1<<endl;
	
	for(int i=0;i<2;i++)
	{
		cout<<v[i][0].health<<endl;	//输出英雄生命值
		cout<<v[i].size()-1<<" ";
		 for(int j=1;j<(int)v[i].size();j++)
		 	cout<<v[i][j].health<<" ";
		cout<<endl;
	}
	
	return 0;
}
