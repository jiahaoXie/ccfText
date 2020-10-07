#include<iostream>
#include<vector>
using namespace std;

vector<int> v[1001];//�ڽӱ� 
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
		v[s].push_back(e);//����������ͼ��������һ������ߣ�����ͼ��Ҫ�������㻥��洢 
	}
	for(int i = 1; i <= n; i++){
		int visit[1001] = {0};
		dfsSolve(i,visit,i);
	}
	for(int i = 1; i <= n; i++){
		int j;
		for(j = 1; j <= n; j++){
			if(isconnect[i][j] == 0)break;//����ֵΪ0˵������ͨ�����˳������ѭ����n�����һ�������������4 
		}
		if(j == n+1) total++;//j�����for(30-36��)�ľֲ�����,�����������n��1����ʱ���ҵ�һ��֪��ȫ�����ŵġ� 
	}
	cout<<total;
	return 0;
} 
