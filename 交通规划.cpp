#include<iostream>  
#include<vector>  
#include<windows.h>  
using namespace std;  
#define INF 99999999  

struct edge  
{  
    int to; //�ߵ���һ��  
    int cost; //�߳���   
    edge(int a,int b) //���췽������һ����������Ǳߵ���һ�˶��㣬�ڶ�����������Ǳߵĳ��ȡ� 
    {  
        to = a;  
        cost = b;  
    }  
};  
vector<edge> G[10001];   //  �ڽӱ�ķ�ʽ�洢ͼ  
int visited[10001];  //  ��ʶÿ�����Ƿ񱻷�����  
int dis[10001];  //  ��ÿ���㵽Դ������·��  
int selected[10001]; //��¼���·���е�ĳ�����̵�ǰһ����  
int n,m;  
void dijstra()  
{  
    int i;  
    for(i = 1; i <= 10000; i++)  //��ʼ��dis��selected����Ԫ��ֵΪINF  
    {  
        dis[i] = INF;  
        selected[i] = INF;  
    }  
    for(i = 0; i < G[1].size(); i++)   //  ��Դ�����ڵ�v��dis[v]��selected[v]�ĳ�ʼ��  
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
        //��δ��¼�Ķ�������dis��С�Ķ���v  
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
        if(done == 0) //  ���ÿ���㶼��¼��ѭ������  
            break;  
        visited[v] = 1;  
        for(i = 0; i < G[v].size(); i++)  //  �ҵ�v��ÿ���ڽӵ�w  
        {  
            int w = G[v][i].to;  
            int cost = G[v][i].cost;  
            if(!visited[w] && dis[w] > dis[v] + cost)  
            {  
                dis[w] = dis[v] + cost;  
                selected[w] = cost;  
            }else if(!visited[w] && dis[w] == dis[v] + cost)  
            {  
                selected[w] = min(cost,selected[w]); //  ����·��ʱ��������·������ȵģ���������·����ѡ����������һ�����н�С�ı�  
            }  
        }  
    }  
}  
int main()  
{  
    std::ios::sync_with_stdio(false);//����������iostream�������������	
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
