#include<bits/stdc++.h>
using namespace std;

int* mergeArrays(const int arrayA[], const int arrayB[], int sizeA, int sizeB){
    int *mergedArray = new int[sizeA + sizeB];
    int i = 0, j = 0, k = 0;
    while(i < sizeA && j < sizeB){
        if(arrayA[i] <= arrayB[j]){
            mergedArray[k] = arrayA[i];
            k++; i++;
        } else {
            mergedArray[k] = arrayB[j];
            k++; j++;
        }
    }
    while(i < sizeA) {mergedArray[k] = arrayA[i]; k++; i++;}
    while(j < sizeB) {mergedArray[k] = arrayB[j]; k++; j++;}
    return mergedArray;
}

vector<int> sortedUnion(const int arrayA[], const int arrayB[], int sizeA, int sizeB){
    vector<int> unionArray;
    int i = 0, j = 0;
    while(i < sizeA && j < sizeB){
        if(arrayA[i] < arrayB[j]){
            unionArray.push_back(arrayA[i]);
            i++;
        } else if(arrayA[i] > arrayB[j]){
            unionArray.push_back(arrayB[j]);
            j++;
        } else {
            unionArray.push_back(arrayA[i]);
            i++; j++;
        }
    }
    while(i < sizeA) {unionArray.push_back(arrayA[i]); i++;}
    while(j < sizeB) {unionArray.push_back(arrayB[j]); j++;}
    
    
    unionArray.erase(unique(unionArray.begin(), unionArray.end()), unionArray.end());
    return unionArray;
}

vector<int> intersection(const int arrayA[], const int arrayB[], int sizeA, int sizeB){
    vector<int> intersectionArray;
    int i = 0, j = 0;
    while(i < sizeA && j < sizeB){
        if(arrayA[i] < arrayB[j]){
            i++;
        } else if(arrayA[i] > arrayB[j]){
            j++;
        } else {
            intersectionArray.push_back(arrayA[i]);
            i++; j++;
        }
    }
    
    intersectionArray.erase(unique(intersectionArray.begin(), intersectionArray.end()), intersectionArray.end());
    return intersectionArray;
}

int main(){

    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr << "Error opening the input file" << endl;
        return 1;
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr << "Error opening the output file" << endl;
    }

    int sizeA, sizeB;
    
    inputFile >> sizeA >> sizeB;
    int *arrayA = new int[sizeA];
    int *arrayB = new int[sizeB];
    for(int i = 0; i < sizeA; i++) {inputFile >> arrayA[i];}
    for(int i = 0; i < sizeB; i++) {inputFile >> arrayB[i];}
    inputFile.close();

    clock_t start, end;
    start = clock();

    outputFile << "EACH SUBPART'S OUTPUT IS PRINTED IN THIS FILE ITSELF " << endl;

    int* mergedArray = mergeArrays(arrayA, arrayB, sizeA, sizeB);
    outputFile << "a_ The merge of A and B gives: " << endl;
    for(int i = 0; i < sizeA + sizeB; i++) {
        outputFile << mergedArray[i] << " ";
    }
    outputFile << endl;

    vector<int> unionArray = sortedUnion(arrayA, arrayB, sizeA, sizeB);
    outputFile << "b_ The sorted array C for A U B: " << endl;
    for(const auto &i : unionArray) {
        outputFile << i << " ";
    }
    outputFile << endl;

    vector<int> intersectionArray = intersection(arrayA, arrayB, sizeA, sizeB);
    outputFile << "c_ The sorted array C for A intersection B: " << endl;
    for(const auto &i : intersectionArray) {
        outputFile << i << " ";
    }
    outputFile << endl;

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    outputFile << "The time taken to run the program is: " << time_taken << " sec" << endl;

    delete[] arrayA;
    delete[] arrayB;
    delete[] mergedArray;

    return 0;
}
