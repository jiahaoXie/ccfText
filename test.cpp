//#include<iostream>  
//#include<map>  
//#include<vector>  
// 
//#include<string>  
//using namespace std;  
//  
//int isRepeat(map<string,string> m,string s)  //�ж������Ƿ��ظ�   
//{  
//    map<string,string>::iterator it;  
//    it = m.find(s);  
//    if(it == m.end())  
//    {  
//        return 0;  
//    }else  
//    {  
//        return 1;  
//    }  
//}  
//  
//int find(string str,char c)  //  ���������Ƿ���ں��Ƿ����   
//{  
//    int i;  
//    int flag = str.find(c);  
//    if(flag != -1)  // ���������   
//    {  
//        if(flag < str.length()-1 && str.at(flag+1) == ':')  
//        {  
//            return 2;   //  �в���   
//        }else  
//        {  
//            return 1;  // �޲���   
//        }  
//    }  
//    return 0;  //�������   
//}  
//int main()  
//{  
//    string str;  
//    int i,j,n;  
//    cin>>str;  
//    cin>>n;  
//    getchar();  
//    for(i = 0; i < n; i++)  
//    {  
//        vector<string> v;  
//        map<string,string> m;  
//        string op;  
//        getline(cin,op);  
//        string line = op;  
//        int t;   
//        for(t = line.find(" "); t != -1; t = line.find(" "))  //���ַ����Կո��и�װ��vector��   
//        {  
//            v.push_back(line.substr(0,t));  
//            line = line.substr(t+1);  
//        }  
//        v.push_back(line);  
//        vector<string>::iterator it;  
//        for(it = v.begin()+1; it != v.end(); it++)  
//        {   
//            string ss = *it;  
//            if(ss.at(0) == '-' && ss.length() == 2 && find(str,ss.at(1)))  
//            {  
//                if(find(str,ss.at(1)) == 1) //�޲�������   
//                {  
//                    m.insert(pair<string,string>(ss,"null"));  
//                }else if(find(str,ss.at(1)) == 2 && ++it != v.end()) // �в�������   
//                {  
//                    if(isRepeat(m,ss))   //���ظ���  
//                    {  
//                        m[ss] = *it;   //�޸�key��Ӧ��ֵ  
//                    }else  
//                    {  
//                        m.insert(pair<string,string>(ss,*it));  
//                    }     
//                }else  //�в�������� -w�������Ǻ���û������ҲΪ���Ϸ�������   
//                {  
//                    break;  
//                }  
//            }else  
//            {  
//                break;  
//            }  
//        }  
//        cout<<"Case "<<i+1<<":";   
//        map<string,string>::iterator itr;  
//        for(itr = m.begin(); itr != m.end(); itr++)  
//        {  
//            if(itr->second != "null")  
//            {  
//                cout<<" "<<itr->first<<" "<<itr->second;  
//            }else  
//            {  
//                cout<<" "<<itr->first;  
//            }  
//        }  
//        cout<<endl;  
//    }  
//   
//    return 0;  
//} 


//#include<iostream>
//#include<map>
//using namespace std;
////int a[1001];
//
//int main()
//{
//	int n,i,tmp;
//	map<int ,int> m;
//	map<int,int>::iterator it;
//	cin>>n;
//	for(i=0;i<n;i++)
//	{
//		cin>>tmp;
//		m[tmp]++;
//	}
//	int mid=(n+1)/2,count=0;
//	for(it=m.begin();it!=m.end();it++)
//	{
//		if(count+it->second <=mid)
//			count+=it->second;
//		else break;
//	}
//	int left=count;
//	int right=n-left-it->second;
//	if(left==right)
//		cout<<it->first<<endl;
//	else cout<<"-1"<<endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//struct Privilege{
// string name;
// int level;
//}privilege[101];
//struct Role{
//	string name;
//	int s;
//	Privilege pri[11];
//}role[101];
//int main()
//{
//	int roleNum,i,j;
//	cin>>roleNum;
//	for(i=0;i<roleNum;i++)
//	{
//		cin>>role[i].name>>role[i].s;
//		cout<<"***"<<role[i].name<<" "<<role[i].s<<endl;
//		for(j=0;j<role[i].s;j++)
//		{
//			cin>>role[i].pri[j].name>>role[i].pri[j].level;
//		}
//	}
//	for(i=0;i<roleNum;i++)
//	{
//		cout<<role[i].name<<" "<<role[i].s<<" ";
//		for(j=0;j<role[i].s;j++)
//		{
//			cout<<role[i].pri[j].name<<" "<<role[i].pri[j].level<<" ;";
//		}
//		cout<<endl;
//	}
//	return 0;
//	
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str;
//	char s[10];
//	int i;
//	float j;
//	cin>>str>>s>>i>>j;
//	cout<<"str:"<<str<<";"<<"s:"<<s<<";"<<i<<";"<<j<<endl;
//	return 0;
//}

////ѧ���Ŷ� 
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n,m,i;
//	vector<int> v;
//	vector<int>::iterator it;
//	cin>>n>>m;
//	for(i=1;i<=n;i++)
//		v.push_back(i);
//	
//	for(i=1;i<=m;i++)
//	{
//		int p,q;
//		cin>>p>>q;
//		for(it=v.begin();it!=v.end();it++)
//			if(*it==p)
//				break;
//		v.erase(it);	//ɾ����������ָ���Ԫ�� 
//		v.insert(it+q,p);	//�ڵ�����it+q��ָ���Ԫ��ǰ�����p 
//	}
//	for(it=v.begin();it!=v.end();it++)
//	{
//		cout<<*it<<" ";
//	}
//	cout<<endl;
//	return 0;
//}


////����Կ�׺� 
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//struct Action {
//    int room;
//    int time;
//    int operators; // 0:�Ż�, 1:ȡ
//    Action(int room1,int time1,int operators1){//���캯�� 
//    	room = room1;
//    	time = time1;
//    	operators = operators1;
//    }
//};
//
//bool cmp(Action a,Action b) {
//	if(a.time < b.time) return true;
//	else if(a.time == b.time && a.operators < b.operators)return true;
//	else if(a.time == b.time && a.operators == b.operators && a.room < b.room)return true;
//	return false;//���ȸ���ʱ����Ⱥ�����ʱ����ͬ������ȡ�������ȷź�ȡ��ʱ����ͬ������ͬ�Ĳ������ȷ���ŵ͵Ĳ�����
//} 
//
//int main() {
//    int N, K;
//    cin >> N >> K;
//    vector<Action> actions;
//    vector<int> states(N+1);//��N��һ��ֹ�������������N+1������ 
//    for(int n=1; n<=N; n++) states[n] = n;
//    
//    for(int k=0; k<K; k++) {
//        int room, begin, length;
//        cin >> room >> begin >> length;
//        actions.push_back(Action(room, begin, 1));//ȡԿ�����뿪ʼʱ�� 
//        actions.push_back(Action(room, begin+length, 0));//�Ż�Կ���������ʱ�䣨��ʼʱ��+����ʱ�䣩 
//    }
//    sort(actions.begin(), actions.end(),cmp);//����cmp��������sort()������Ͼ���Ĺ��� 
//    for(int i=0; i<actions.size(); i++) 
//	{ 
//		if(actions[i].operators == 0) { // �Ż�
//            for(int n=1; n<=N; n++) {
//                if(states[n] == -1) {
//                    states[n] = actions[i].room;
//                    break;
//                }
//            }
//        }
//        else { // ȡԿ�� 
//            for(int n=1; n<=N; n++) {
//                if(states[n] == actions[i].room) {
//                    states[n] = -1;//-1�Ƕ�����Կ�׺�Կ�λ�õı�� 
//                    break;
//                }
//            }
//        }
//    }
//    for(int n=1; n<=N; n++) {
//        cout<< states[n] << " ";
//    }
//    cout<<endl;
//    return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str,tmp;
//	getline(cin,str);
//	int i=0;
//	if(str[i]='"')	i++;
//	while(i<(int)str.size())
//	{
//		if(str[i]=='\\' )
//		{
//			i++;
//			tmp+=str[i];
//			i++;
//		}
//		else if(str[i]=='"')
//			break;
//		else
//		{
//			tmp+=str[i];
//			i++;
//		 } 
//		
//	}
//	cout<<tmp<<endl;
//	return 0;
//}

//ͨ������
//����vector�洢M�� ��ʾ��ͨ��·
//dfs���б��� map[][]���������ڵ�֮���Ƿ���Ի�ͨ

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int map[1001][1001];
//vector<int> path[1001];
//
//void DFS(int a,int visit[],int b)
//{
//	visit[a]=1;	//��ʾ�ѱ��� 
//	map[a][b]=map[b][a]=1;	//��ʾ�����ڵ�֮����ͨ
//	for(int i=0;i<(int)path[a].size();i++) 
//		if(visit[path[a][i]]==0)
//			DFS(path[a][i],visit,b);	//�ݹ���� 
//}
//
//int main()
//{
//	int n,m,i,j,count=0;
//	cin>>n>>m;
//	for(i=0;i<m;i++)
//	{
//		int a,b;
//		cin>>a>>b;
//		path[a].push_back(b);	//�洢�����ӵĵ�·	
//	}
//	//��ʼ���б���
//	for(i=1;i<=n;i++)
//	{
//		int visit[1001]={0};	//visit��ʾ����λ �ýڵ��Ƿ񱻷��� 
//		DFS(i,visit,i);
//		
//	 } 
//	 //����ж�
//	 for(i=1;i<=n;i++)
//	 {
//	 	for(j=1;j<=n;j++)
//	 	{
//	 		if(map[i][j]==0)	break;
//		}	
//		if(j==n+1) count++;
//	  } 
//	 cout<<count<<endl;
//	 return 0;
//} 

//����	��vector��д(����Ӧ������򵥵���)
#include<iostream>
#include<vector>
using namespace std;

struct Win{
	int x1;
	int y1;
	int x2;
	int y2;
	int pos;
}; 

int main()
{
	vector<Win> v;
	vector<Win>::iterator it;
	
	struct Win tmp;
	int N,M,i;
	cin>>N>>M;
	for(i=0;i<N;i++)
	{
		cin>>tmp.x1>>tmp.y1>>tmp.x2>>tmp.y2;
		tmp.pos=i+1;
		v.insert(v.begin(),tmp);	//ÿ�ν�Ԫ�ز������	
	
	}
	while(M--)
	{
		int x,y;
		cin>>x>>y;
		for(it=v.begin();it!=v.end();it++)
		{
			if(x>=(*it).x1 &&x<=(*it).x2 && y>=(*it).y1 && y<=(*it).y2)
			{
				cout<<(*it).pos<<endl;
				tmp=*it;
				v.erase(it);
				v.insert(v.begin(),tmp);
				break;
			}
		}
		if(it==v.end())
		 cout<<"IGNORED"<<endl;
	 } 
	return 0;
}

