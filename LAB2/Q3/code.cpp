#include<bits/stdc++.h>
using namespace std;

void merge_in_place(int a[],int s,int m,int e){
    int gap=m;
    while(gap>=1){
        for(int i=s;i+gap<e;i++){
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
void merge_sort(int a[],int s,int e){
    if(s>=e){return;}
    int mid=(s+e)/2;
    merge_sort(a,s,mid);
    merge_sort(a,mid+1,e);
    merge_in_place(a,s,mid+1,e);
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
    int n;
    inputFile>>n;
    for(int i=0;i<n;i++){
        inputFile>>a[i];
    }
    clock_t start,end;
    start=clock();
    merge_sort(a,0,n);
    end=clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);

    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec for "<<n<<" elements"<<endl;
    for(int i=0;i<n;i++){outputFile<<a[i]<<" ";}
    outputFile<<endl;
    return 0;
}