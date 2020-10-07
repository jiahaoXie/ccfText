//#include<iostream>  
//#include<map>  
//#include<vector>  
// 
//#include<string>  
//using namespace std;  
//  
//int isRepeat(map<string,string> m,string s)  //判断命令是否重复   
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
//int find(string str,char c)  //  查找命令是否存在和是否带参   
//{  
//    int i;  
//    int flag = str.find(c);  
//    if(flag != -1)  // 该命令存在   
//    {  
//        if(flag < str.length()-1 && str.at(flag+1) == ':')  
//        {  
//            return 2;   //  有参数   
//        }else  
//        {  
//            return 1;  // 无参数   
//        }  
//    }  
//    return 0;  //命令不存在   
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
//        for(t = line.find(" "); t != -1; t = line.find(" "))  //将字符串以空格切割装进vector中   
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
//                if(find(str,ss.at(1)) == 1) //无参数命令   
//                {  
//                    m.insert(pair<string,string>(ss,"null"));  
//                }else if(find(str,ss.at(1)) == 2 && ++it != v.end()) // 有参数命令   
//                {  
//                    if(isRepeat(m,ss))   //有重复的  
//                    {  
//                        m[ss] = *it;   //修改key对应的值  
//                    }else  
//                    {  
//                        m.insert(pair<string,string>(ss,*it));  
//                    }     
//                }else  //有参数命令（如 -w），但是后面没参数，也为不合法的命令   
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

////学生排队 
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
//		v.erase(it);	//删除迭代器所指向的元素 
//		v.insert(it+q,p);	//在迭代器it+q所指向的元素前面插入p 
//	}
//	for(it=v.begin();it!=v.end();it++)
//	{
//		cout<<*it<<" ";
//	}
//	cout<<endl;
//	return 0;
//}


////公共钥匙盒 
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//struct Action {
//    int room;
//    int time;
//    int operators; // 0:放回, 1:取
//    Action(int room1,int time1,int operators1){//构造函数 
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
//	return false;//首先根据时间的先后排序。时间相同，根据取放排序，先放后取。时间相同，是相同的操作，先房间号低的操作。
//} 
//
//int main() {
//    int N, K;
//    cin >> N >> K;
//    vector<Action> actions;
//    vector<int> states(N+1);//比N大一防止向量数组溢出，N+1个参数 
//    for(int n=1; n<=N; n++) states[n] = n;
//    
//    for(int k=0; k<K; k++) {
//        int room, begin, length;
//        cin >> room >> begin >> length;
//        actions.push_back(Action(room, begin, 1));//取钥匙输入开始时间 
//        actions.push_back(Action(room, begin+length, 0));//放回钥匙输入结束时间（开始时间+持续时间） 
//    }
//    sort(actions.begin(), actions.end(),cmp);//调用cmp函数，给sort()排序加上具体的规则 
//    for(int i=0; i<actions.size(); i++) 
//	{ 
//		if(actions[i].operators == 0) { // 放回
//            for(int n=1; n<=N; n++) {
//                if(states[n] == -1) {
//                    states[n] = actions[i].room;
//                    break;
//                }
//            }
//        }
//        else { // 取钥匙 
//            for(int n=1; n<=N; n++) {
//                if(states[n] == actions[i].room) {
//                    states[n] = -1;//-1是对拿走钥匙后对空位置的标记 
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

//通信网络
//利用vector存储M行 表示想通道路
//dfs进行遍历 map[][]保存两个节点之间是否可以互通

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int map[1001][1001];
//vector<int> path[1001];
//
//void DFS(int a,int visit[],int b)
//{
//	visit[a]=1;	//表示已遍历 
//	map[a][b]=map[b][a]=1;	//表示两个节点之间想通
//	for(int i=0;i<(int)path[a].size();i++) 
//		if(visit[path[a][i]]==0)
//			DFS(path[a][i],visit,b);	//递归遍历 
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
//		path[a].push_back(b);	//存储相连接的道路	
//	}
//	//开始进行遍历
//	for(i=1;i<=n;i++)
//	{
//		int visit[1001]={0};	//visit表示符号位 该节点是否被访问 
//		DFS(i,visit,i);
//		
//	 } 
//	 //输出判断
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

//窗口	用vector来写(觉得应该是最简单的了)
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
		v.insert(v.begin(),tmp);	//每次将元素插入最顶层	
	
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

