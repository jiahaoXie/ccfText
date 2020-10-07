#include<iostream>
#include<vector>
using namespace std;

vector<int> v[1001];//邻接表 
int isconnect[1001][1001];

void dfsSolve(int u,int visit[],int cur){
	visit[u] = 1;
	isconnect[u][cur] = isconnect[cur][u] = 1;
	for(int i = 0; i < v[u].size(); i++){
		if(visit[v[u][i]] == 0){
			dfsSolve(v[u][i],visit,cur);
		}
	}
}

int main(){
	int n,m,total = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int s,e;
		cin >> s >> e;
		v[s].push_back(e);//这里是有向图就这样存一条有向边，无向图需要两个顶点互相存储 
	}
	for(int i = 1; i <= n; i++){
		int visit[1001] = {0};
		dfsSolve(i,visit,i);
	}
	for(int i = 1; i <= n; i++){
		int j;
		for(j = 1; j <= n; j++){
			if(isconnect[i][j] == 0)break;//数组值为0说明不连通，就退出了这个循环。n是最后一个，例子里面的4 
		}
		if(j == n+1) total++;//j是这个for(30-36行)的局部变量,自增到最后会比n多1，这时就找到一个知道全部部门的。 
	}
	cout<<total;
	return 0;
} 
