#include<bits/stdc++.h>
using namespace std;

void merge_in_place(int a[],int n,int m){
    int gap=m;
    while(gap>=1){
        for(int i=0;i+gap<n;i++){
            if(a[i]>a[i+gap]){
                swap(a[i],a[i+gap]);
            }
        }
        if(gap==1){gap=0;}
        else{
            gap=ceil(gap/2.00);
        }
    }
}
int a[10000000];

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }

    int n,m;
    inputFile>>n>>m;
    for(int i=0;i<n;i++){
        inputFile>>a[i];
    }
    clock_t start,end;
    start=clock();
    merge_in_place(a,n,m);
    end=clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);

    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec for "<<n<<" elements"<<endl;
    for(int i=0;i<n;i++){outputFile<<a[i]<<" ";}
    outputFile<<endl;
    return 0;
}