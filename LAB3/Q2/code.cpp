#include <bits/stdc++.h> 
#include <fstream>
using namespace std; 

int findMax(int a, int b) { 
    return (a > b) ? a : b; 
} 

int findMax(int a, int b, int c) { 
    return findMax(findMax(a, b), c); 
} 

int findMaxCrossingSum(int arr[], int low, int mid, int high) { 
    int sum = 0; 
    int leftSum = INT_MIN; 
    for (int i = mid; i >= low; i--) { 
        sum = sum + arr[i]; 
        if (sum > leftSum) 
            leftSum = sum; 
    } 

    sum = 0; 
    int rightSum = INT_MIN; 
    for (int i = mid; i <= high; i++) { 
        sum = sum + arr[i]; 
        if (sum > rightSum) 
            rightSum = sum; 
    } 

    
    return findMax(leftSum + rightSum - arr[mid], leftSum, rightSum); 
} 

int findMaxSubArraySum(int arr[], int low, int high) { 
    if (low > high) 
        return INT_MIN; 
    if (low == high) 
        return arr[low]; 

    int mid = (low + high) / 2; 

   
    return findMax(findMaxSubArraySum(arr, low, mid - 1), 
            findMaxSubArraySum(arr, mid + 1, high), 
            findMaxCrossingSum(arr, low, mid, high)); 
} 

int main() { 
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the input file" << endl;
        return 1;
    }

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening the output file" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        inputFile >> arr[i];
    }

    int maxSum = findMaxSubArraySum(arr, 0, n - 1);

    outputFile << "Maximum contiguous sum is " << maxSum;

    delete[] arr;
    inputFile.close();
    outputFile.close();

    return 0; 
}
