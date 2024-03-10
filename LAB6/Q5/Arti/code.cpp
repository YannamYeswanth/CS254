// C++ program to find articulation points in an undirected graph
#include <bits/stdc++.h>
using namespace std;

void APUtil(vector<vector<int>> &adj, int u, bool visited[],int disc[], int low[], int& time, int parent,vector<int>& ans)
{
	int children = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time;
	for (auto v : adj[u]) {
		if (!visited[v]) {
			children++;
			APUtil(adj, v, visited, disc, low, time, u, ans);
			low[u] = min(low[u], low[v]);
			if (parent != -1 && low[v] >= disc[u])
				ans.push_back(u);
           
		}
		else if (v != parent)
			low[u] = min(low[u], disc[v]);
	}
	if (parent == -1 && children > 1)
		ans.push_back(u);
     

}

vector<int> AP(vector<vector<int>> &adj, int n)
{
	int disc[n] = { 0 };
	int low[n];
	bool visited[n] = { false };
	int time = 0, par = -1;
    vector<int> ans;

	for (int u = 0; u < n; u++){
		if (!visited[u]){
            APUtil(adj, u, visited, disc, low,time, par, ans);
        }
    }		
    return ans;
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
    vector<int> ans= AP(v,n);
    for(int i=0;i<ans.size();i++){
        outputFile<< ans[i]<<" ";
    }
    outputFile.close();

    return 0;
}