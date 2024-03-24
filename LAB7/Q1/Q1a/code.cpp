#include<bits/stdc++.h>
using namespace std;

bool comp(pair<double,int> a,pair<double,int> b){
    return a.first >= b.first;
}

int greedyKs(int n,vector<int> weights,vector<int> values,int wl){
    vector<pair<double,int>> vbw(n);
    for(int i=0;i<n;i++){
        vbw[i]={((double)(values[i])/(double)(weights[i])),i};
    }
    sort(vbw.begin(),vbw.end(),comp);
    int cweight=0;
    int coutput=0;
    int idx=0;
    int itemidx=vbw[idx].second;
    while(cweight < wl && idx < n){
        if(wl - cweight >= weights[itemidx]){
            cweight+=weights[itemidx];
            coutput+=values[itemidx];
        }
        idx++;
        itemidx=vbw[idx].second;
    }
    return coutput;
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
        int y=greedyKs(n,weights,values,wl);
        outputFile<<"The profit is "<<y<<"\n";
    }
    inputFile.close();
    outputFile.close();
    clock_t finish=clock();
    cout<<"The time taken in seconds is : "<<double(finish-begin)/CLOCKS_PER_SEC<<" \n";
    return 0;
}