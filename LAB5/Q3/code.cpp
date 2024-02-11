#include<bits/stdc++.h>
using namespace std;

bool isbip(vector<vector<int>>&v,int n,vector<int>&a,int s){
    a[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int c=q.front();q.pop();
        for(int i=0;i<n;i++){
            if(v[c][i]){
                if(a[i]==-1){
                    a[i]=a[c]^1;
                    q.push(i);
                }else if(a[i]==a[c]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool bip(vector<vector<int>>&v,int n){
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i]=-1;
    }

    for(int i=0;i<n;i++){
        if(a[i]==-1){
            if(isbip(v,n,a,i)==false){return false;}
        }
    }
    return true;
}

bool clique(vector<vector<int>>&v,int n){
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    v[i][j]^=1;
                }
            }
         }
         return bip(v,n);
}

 
int main(){
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    int n;
    inputFile >> n;
     vector<vector<int>> v(n,vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
        inputFile >> v[i][j];
        }
    }
    inputFile.close();
    ofstream outputFile("output.txt");
     if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }
    if(clique(v,n)){
        outputFile << "YES!" << endl;
    }else{
        outputFile << "NO!" << endl;
    }
    
    outputFile.close();

    return 0;
}