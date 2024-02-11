#include<bits/stdc++.h>
using namespace std;


int bfs(int pos[],int n){
    int vis[n];
    for(int i=0;i<n;i++){
        vis[i]=-1;
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int v=q.front().first, c=q.front().second;
        if(v==n-1){
            break;
        }
        q.pop();
        for(int j=v+1;j<=min(n-1,(v+6));j++){            
            if(vis[j]==1){
               continue;
            }
            vis[j]=1;
            if(pos[j]!=-1){
                vis[pos[j]]=1;
                q.push({pos[j],c+1});
            }else{
                q.push({j,c+1});
            }
        }
    }
    return q.front().second;
}
 
int main(){
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    int n;
    inputFile >> n;
    int v[n];
    for (int i = 0; i < n; ++i) {   
        inputFile >> v[i];  
    }
    inputFile.close();
    ofstream outputFile("output.txt");
     if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }
     int ans=bfs(v,n);
     outputFile << "Least chances required : " << ans << endl;
    outputFile.close();

    return 0;
}