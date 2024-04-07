#include<bits/stdc++.h>
using namespace std;

int graph[18][18][2];
long long dp[1 << 18][18][2];

long long minCost(int n, int m, int mask, int prev, int col)
{
	if (mask == ((1 << n) - 1)) {
		return 0;
	}
	if (dp[mask][prev][col == 1] != 0) {
		return dp[mask][prev][col == 1];
	}

	long long ans = 1e9;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (graph[prev][i][j] && !(mask & (1 << i)) && (j != col)) {
				long long z = graph[prev][i][j] + minCost(n,m,mask|(1<<i),i,j);
				ans = min(z, ans);
			}
		}
	}

	return dp[mask][prev][col == 1] = ans;
}

void makeGraph(vector<pair<pair<int,int>, pair<int,char>>>& vp,int m){
	for (int i = 0; i < m; i++) {
		int a = vp[i].first.first - 1;
		int b = vp[i].first.second - 1;
		int cost = vp[i].second.first;
		char color = vp[i].second.second;
		graph[a][b][color == 'W'] = cost;
		graph[b][a][color == 'W'] = cost;
	}
}

int getCost(int n,int m){
	long long ans = 1e9;
	for (int i = 0; i < n; i++) {
		ans = min(ans, minCost(n, m, 1 << i, i, 2));
	}
	return ans != 1e9 ? ans : -1;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,pair<int,char>>> v;
    for(int i=0;i<m;i++){
        int a,b,w;
        char c;
        cin>>a>>b>>w>>c;
        v.push_back({{a,b},{w,c}});
    }

	makeGraph(v,m);
	cout << getCost(n,m) << '\n';
	return 0;
}