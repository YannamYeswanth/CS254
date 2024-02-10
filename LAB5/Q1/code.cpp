#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>&v,int n){
    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             if(v[i][j]==0){
                continue;
             }
             queue<pair<int,int>> q;
             q.push({i,j});
                v[i][j]=0;
             
             int k=1;
             while(!q.empty()){

                int x=q.front().first,y=q.front().second;
                q.pop();
                if(x!=0){
                
                    if(y!=0&&v[x-1][y-1]==1){q.push({x-1,y-1});k++;v[x-1][y-1]=0;}
                    if(v[x-1][y]==1){q.push({x-1,y});k++;v[x-1][y]=0;}
                    if(y!=n-1&&v[x-1][y+1]==1){q.push({x-1,y+1});k++;v[x-1][y+1]=0;}
                }
                if(y!=0&&v[x][y-1]==1){
                    q.push({x,y-1});k++;v[x][y-1]=0;
                }
                if(y!=n-1&&v[x][y+1]==1){
                    q.push({x,y+1});k++;v[x][y+1]=0;
                }
                if(x!=n-1){
                    if(y!=0&&v[x+1][y-1]==1){q.push({x+1,y-1});k++;v[x+1][y-1]=0;}
                    if(v[x+1][y]==1){q.push({x+1,y});k++;v[x+1][y]=0;}
                    if(y!=n-1&&v[x+1][y+1]==1){q.push({x+1,y+1});k++;v[x+1][y+1]=0;}
                }

             }
             ans=max(ans,k);
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
    int n;
    inputFile >> n;
    // vector<int> a(n);s
    vector<vector<int>> v(n,vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
        inputFile >> v[i][j];
        cout<<v[i][j]<<" ";
        }
    }
    inputFile.close();
    ofstream outputFile("output.txt");
     if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }
     int ans=bfs(v,n);
     outputFile << "Largest  : " << ans << endl;
    outputFile.close();

    return 0;
}