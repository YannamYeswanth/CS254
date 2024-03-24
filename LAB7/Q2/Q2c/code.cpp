#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}

struct Compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.first < b.first;
    }
};


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
        int maxProfit=0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , Compare> pq;
        for(int i=n-1 ; i>=0 ; i--){
            int numOfSlotsAvailable;
            if(i==0){
                numOfSlotsAvailable=t[i].second;
            }
            else{
                numOfSlotsAvailable=t[i].second-t[i-1].second;
            }
            pq.push(t[i]);
            while(numOfSlotsAvailable > 0 && pq.size()>0){
                int a=pq.top().first;
                int b=pq.top().second;
                maxProfit+=a;
                pq.pop();
                numOfSlotsAvailable--;
            }
        }
        outputFile<<"The profit earned is "<<maxProfit<<"\n";
    }
    inputFile.close();
    outputFile.close();
    clock_t finish=clock();
    cout<<"The time taken in seconds is : "<<double(finish-begin)/CLOCKS_PER_SEC<<" \n";
    return 0;
}