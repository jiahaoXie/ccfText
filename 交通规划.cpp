#include<iostream>  
#include<vector>  
#include<windows.h>  
using namespace std;  
#define INF 99999999  

struct edge  
{  
    int to; //边的另一端  
    int cost; //边长度   
    edge(int a,int b) //构造方法，第一个传入参数是边的另一端顶点，第二个传入参数是边的长度。 
    {  
        to = a;  
        cost = b;  
    }  
};  
vector<edge> G[10001];   //  邻接表的方式存储图  
int visited[10001];  //  标识每个点是否被访问了  
int dis[10001];  //  到每个点到源点的最短路径  
int selected[10001]; //记录最短路径中到某点的最短的前一条边  
int n,m;  
void dijstra()  
{  
    int i;  
    for(i = 1; i <= 10000; i++)  //初始化dis和selected数组元素值为INF  
    {  
        dis[i] = INF;  
        selected[i] = INF;  
    }  
    for(i = 0; i < G[1].size(); i++)   //  与源点相邻点v的dis[v]和selected[v]的初始化  
    {  
        int v = G[1][i].to;  
        dis[v] = G[1][i].cost;  
        selected[v] = G[1][i].cost;  
    }  
    dis[1] = selected[1] = 0;  
    visited[1] = 1;  
    while(1)  
    {  
        int done = 0;  
        int minn,v;  
        minn = INF;  
        //从未收录的顶点中找dis最小的顶点v  
        for(i = 1; i <= n; i++)  
        {  
            if(!visited[i])  
            {  
                done = 1;  
                if(dis[i] < minn)  
                {  
                    v = i;  
                    minn = dis[i];  
                }  
            }  
        }  
        if(done == 0) //  如果每个点都收录了循环结束  
            break;  
        visited[v] = 1;  
        for(i = 0; i < G[v].size(); i++)  //  找到v的每个邻接点w  
        {  
            int w = G[v][i].to;  
            int cost = G[v][i].cost;  
            if(!visited[w] && dis[w] > dis[v] + cost)  
            {  
                dis[w] = dis[v] + cost;  
                selected[w] = cost;  
            }else if(!visited[w] && dis[w] == dis[v] + cost)  
            {  
                selected[w] = min(cost,selected[w]); //  更新路径时若有两条路径是相等的，则在两条路径中选到这个点的上一条边中较小的边  
            }  
        }  
    }  
}  
int main()  
{  
    std::ios::sync_with_stdio(false);//可以来打消iostream的输入输出缓存	
    int i;  
    cin >> n >> m;  
    for(i = 1; i <= m; i++)  
    {  
        int a,b,c;  
        cin >> a >> b >> c;  
        G[a].push_back(edge(b,c));  
        G[b].push_back(edge(a,c));  
    }  
    dijstra();  
    int length = 0;  
    for(i = 1; i <= n; i++)  
    {  
        length += selected[i];  
    }  
    cout<<length<<endl;  
    return 0;  
}  
