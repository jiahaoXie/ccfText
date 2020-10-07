#include<stdio.h>  
#include<iostream>  
#include<cstring>   
#include<vector>  
#include<queue>  
#define inf 99999999  
using namespace std;  
int dis[200005];  
int vis[200005];  
  
struct Lu  
{  
    int to;  
    int cost;  
    Lu(int too,int costt)  
    {  
        to=too;  
        cost=costt;  
    }  
  
};  
vector<Lu> V[200005];  
int spfa(int n)  
{  
    for(int i=0; i<=200005; i++)  
    {  
        vis[i]=0;  
        dis[i]=inf;  
    }  
    dis[1]=0;  
    queue<int>Q;  
    Q.push(1);  
    vis[1]=1;  
    while(!Q.empty())  
    {  
        int top=Q.front();  
        Q.pop();  
        vis[top]=0;  
        for(int i=0; i<V[top].size(); i++)  
        {  
            int to=V[top][i].to;  
  
            int cost=V[top][i].cost;  
            if(dis[to]>max(dis[top],cost))  
            {  
  
                dis[to]=max(dis[top],cost);  
                if(!vis[to])  
                {  
                    Q.push(to);  
                    vis[to]=1;  
                }  
            }  
  
        }  
  
    }  
  
    return dis[n];  
}  
int main()  
{  
    std::ios::sync_with_stdio(false);
	int n,m;  
    cin >> n >> m;
	for(int i=0; i<=200005; i++)  
    {  
        V[i].clear();//初始化vector数组  
    }
	//V[200005] = '0';不能这么写  
    int a,b,c;  
    for(int i=0; i<m; i++)  
    {  
        cin >> a >> b >> c;  
        V[a].push_back(Lu(b,c));  
        V[b].push_back(Lu(a,c));  
    }  
        cout<<spfa(n)<<endl;		
	return 0;   
}  
