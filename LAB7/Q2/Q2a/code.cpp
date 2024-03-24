#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    return a.first >= b.first;
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
        vector<int> deadline(n);
        for(int &x:deadline)inputFile>>x;
        vector<int> profit(n);
        for(int &x:profit)inputFile>>x;
        vector<pair<int,int>> t(n);
        for(int i=0;i<n;i++){
            t[i]={profit[i],deadline[i]};
        }
        sort(t.begin(),t.end(),comp);
        unordered_map<int,int> mark;
        int profitEarned=0;
        for(int i=0;i<n;i++){
            int a=t[i].first;
            int b=t[i].second;
            for(int j=b;j>0;j--){
                if(mark.find(j)==mark.end()){
                    profitEarned+=a;
                    mark[j]=i;
                    break;
                }
            }
        }
        outputFile<<"The profit earned is "<<profitEarned<<"\n";
    }
    inputFile.close();
    outputFile.close();
    clock_t finish=clock();
    cout<<"The time taken in seconds is : "<<double(finish-begin)/CLOCKS_PER_SEC<<" \n";
    return 0;
}