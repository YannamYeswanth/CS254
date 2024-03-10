#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<list<int>> gr,stack<int> &st,vector<bool> &visited,int v){
    visited[node]=true;
    for(auto it : gr[node]){
        if(!visited[it]){
            dfs(it,gr,st,visited,v);
        }
    }
    st.push(node);
}

void dfs2(int node,vector<list<int>> grT,vector<bool> &visited,int v,vector<int> &v1){
    visited[node]=true;
    for(auto it : grT[node]){
        if(!visited[it]){
            dfs2(it,grT,visited,v,v1);
        }
    }
    v1.push_back(node);
}

vector<vector<int>> kosaraju(vector<list<int>> gr,int v,int e){
    stack<int> st;
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,gr,st,visited,v);
        }
    }

    vector<list<int>> grT(v);
    for(int i=0;i<v;i++){
        for(auto it : gr[i]){
            grT[it].push_back(i);
        }
    }

    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    vector<vector<int>> stronglyConnectedComponents;
    while(!st.empty()){
        int j=st.top();
        st.pop();
        if(visited[j])continue;
        else{
            vector<int> v1;
            dfs2(j,grT,visited,v,v1);
            stronglyConnectedComponents.push_back(v1);
        }
    }
    return stronglyConnectedComponents;
}

int main(){
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1; 
    }

    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }
    int tc;
    inputFile>>tc;
    clock_t begin=clock();
    while(tc--){
        int v;
        inputFile>>v;
        int e;
        inputFile>>e;
        vector<list<int>> gr;
        for(int i=0;i<v;i++){
            list<int> v1;
            while(true){
                char mm;
                inputFile>>mm;
                if(mm=='n')break;
                v1.push_back((int)(mm-'0'));
            }
            gr.push_back(v1);
        }
        vector<vector<int>> ans=kosaraju(gr,v,e);
        int n=ans.size();
        for(int i=0;i<n;i++){
            int m=ans[i].size();
            for(int j=0;j<m;j++){
                outputFile<<ans[i][j]<<" ";
            }
            outputFile<<"\n";
        }
        outputFile<<"\n";
    }
    inputFile.close();
    outputFile.close();
    clock_t finish=clock();
    cout<<"The time taken in seconds is : "<<double(finish-begin)/CLOCKS_PER_SEC<<" \n";
    return 0;
}