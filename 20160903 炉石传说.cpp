//ccf 20160903 ¯ʯ��˵ 
//0 1 ��ʾ������ң� 
//��һ���ṹ����������洢���ѻ�����ӵ�����ֵ�͹�����		
//��vector<>v[2] �洢������ҵĽ�ɫ 

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
	v[0].push_back(Status(30,0));	//˫��Ӣ�۳�ʼ�� 
	v[1].push_back(Status(30,0));
	
	cin>>n;
	getchar();
	
	int player=0; //������һ����� 
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
				//ָ��λ�ò��� 
		}
		else if(tmp=="attack")
		{
			int attacker,defender;
			cin>>attacker>>defender;
			//˫������ƶ�λ�õĽ�ɫ ������ֵ��Ҫ��Ҫ�仯������жϹ��������� ����ֵ�Ƿ�С�ڵ���0 �ǣ����������
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
	
	//�������
	if(v[0][0].health>0 && v[1][0].health>0)
		cout<<0<<endl;
	else if(v[0][0].health<=0 && v[1][0].health>0) 
		cout<<-1<<endl;
	else if(v[0][0].health>0 && v[1][0].health<=0)
		cout<<1<<endl;
	
	for(int i=0;i<2;i++)
	{
		cout<<v[i][0].health<<endl;	//���Ӣ������ֵ
		cout<<v[i].size()-1<<" ";
		 for(int j=1;j<(int)v[i].size();j++)
		 	cout<<v[i][j].health<<" ";
		cout<<endl;
	}
	
	return 0;
}
