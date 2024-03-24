#include<bits/stdc++.h>
using namespace std;

int dpKs(int n,vector<int> weights,vector<int> values,int wl){
    vector<vector<int>> mat(n+1,vector<int> (wl+1));
    for(int i=0;i<n+1;i++){
        mat[i][0]=0;
    }
    for(int i=0;i<wl+1;i++){
        mat[0][i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<wl+1;j++){
            if(weights[i-1]>j){
                mat[i][j]=mat[i-1][j];
            }
            else{
                mat[i][j]=max(mat[i-1][j],mat[i-1][j-weights[i-1]]+values[i-1]);
            }
        }
    }
    return mat[n][wl];
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
        int n;
        inputFile>>n;
        vector<int> weights(n);
        for(int &x: weights)inputFile>>x;
        vector<int> values(n);
        for(int &x: values)inputFile>>x;
        int wl;
        inputFile>>wl;
        int y=dpKs(n,weights,values,wl);
        outputFile<<"The profit is "<<y<<"\n";
    }
    inputFile.close();
    outputFile.close();
    clock_t finish=clock();
    cout<<"The time taken in seconds is : "<<double(finish-begin)/CLOCKS_PER_SEC<<" \n";
    return 0;
}