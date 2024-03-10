#include<bits/stdc++.h>
using namespace std;

bool TPS(vector<vector<int>>&v,int n){
     vector<int> in(n),tps;
     for(int i=0;i<n;i++){
         for(int j=0;j<v[i].size();j++){
            in[v[i][j]]++;
         }
     }   
     queue<int> q;
     for(int i=0;i<n;i++){
         if(in[i]==0){
            q.push(i);
            tps.push_back(i);
         }
     }
     while(!q.empty()){
        int k=q.front();
        q.pop();
        for(int i=0;i<v[k].size();i++){
            in[v[k][i]]--;
            if(in[v[k][i]]==0){
                q.push(v[k][i]);
                tps.push_back(v[k][i]);
            }
        }
     }
     
     if(tps.size()!=n){return true;}else{return false;}
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
    }
    
    inputFile.close();
    ofstream outputFile("output.txt");
     if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }
    bool cycle=TPS(v,n); 
    if(cycle){
        outputFile <<"YES"<<endl;
    }else{
        outputFile <<"NO"<<endl; 
    }  
    
    outputFile.close();

    return 0;
}