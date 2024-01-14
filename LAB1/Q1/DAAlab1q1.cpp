#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("lab1q1inp.txt");


    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1; 
    }

   

    int size;
    inputFile >> size;

    vector<int> a(size);
    for (int i = 0; i < size; ++i) {
        inputFile >> a[i];
    }
    
    inputFile.close();

    if (size < 2) {
        cerr << "Error: Array should have at least two elements." << endl;
        return 1; 
    }

    ofstream outputFile("lab1q1outp.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }
   
    int m1=max(a[0],a[1]),m2=min(a[0],a[1]);
    for(int i=2;i<size;i++){
        if(a[i]>m1){
           m2=m1;
           m1=a[i];
        }else if(a[i]>m2){
            m2=a[i];
        }
    }

    outputFile << "Maximum Sum: " << m1+m2 << endl;

    outputFile.close();


    return 0; 
}
