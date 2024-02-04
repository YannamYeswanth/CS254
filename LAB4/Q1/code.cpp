#include<bits/stdc++.h>
using namespace std;
 
long long merge(int a[],int l,int m,int r){
    int i=l,j=m+1,k=0;
    int temp[r-l+1];
    long long ans=0;
    while(i<=m&&j<=r){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            i++;
        }else{
            temp[k]=a[j];
            j++;
            ans+=(m+1-i);
        }
        k++;
    }
    while(i<=m){
            temp[k]=a[i];
            i++;k++;
    }
    while(j<=r){
            temp[k]=a[j];
            j++;k++;
    }
    for(int p=l;p<=r;p++){
        a[p]=temp[p];
    }
    return ans;
}
 
long long merge_sort(int A[],int l,int r){
     int ans=0;
     if(l==r){
        return 0;
     }
     int mid=(l+r)/2;
     ans+= merge_sort(A,l,mid);
     ans+= merge_sort(A,mid+1,r);
     ans+= merge(A,l,mid,r);
     return ans;
}

int main(){
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    int n;
    inputFile >> n;
    int A[n];
    
    for (int i = 0; i < n; ++i) {
        inputFile >> A[i];
    }
    inputFile.close();
    ofstream outputFile("output.txt");
     if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }
    long long ans= merge_sort(A,0,n-1);
    outputFile << "Number of Inversions : " << ans << endl;

    outputFile.close();

    return 0;
}