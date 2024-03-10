#include<bits/stdc++.h>
using namespace std;


void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, int parent,vector<vector<int>> adj,vector<pair<int,int>> &bridges)
{
 static int time = 0;
	visited[u] = true;

	disc[u] = low[u] = ++time;
	for (int i = 0; i != adj[u].size(); i++)
	{
		int v = adj[u][i]; 
		if(v==parent)
			continue;
	
		if(visited[v]){
		low[u] = min(low[u], disc[v]);
		}
	
		else{
		parent = u;
		bridgeUtil(v, visited, disc, low, parent,adj,bridges);

		low[u] = min(low[u], low[v]);
		if (low[v] > disc[u]){
			bridges.push_back({u,v});
            cout<<u<<" "<<v<<endl;
        }
		
		}
	}
}

vector<pair<int,int>> bridge(int n,vector<vector<int>> adj)
{
	vector<bool> visited (n,false);
	vector<int> disc (n,-1);
	vector<int> low (n,-1);
	vector<pair<int,int>> bridges;
	int parent = -1;

	for (int i = 0; i < n; i++)
		if (visited[i] == false)
			bridgeUtil(i, visited, disc, low, parent,adj,bridges);

    return bridges;
}

 
int main(){
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    int n,e;
    inputFile >> n >> e;
    vector<vector<int>> v(n); 
    for (int i = 0; i < e; ++i) {
        int p,q;
        inputFile >>p>>q;
        v[p].push_back(q);  
        v[q].push_back(p); 
    }
    
    inputFile.close();
    ofstream outputFile("output.txt");
     if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }
    vector<pair<int,int>> bridges= bridge(n,v);
    for(int i=0;i<bridges.size();i++){
        outputFile<< bridges[i].first<<" "<<bridges[i].second<<endl;
    }
    outputFile.close();

    return 0;
}