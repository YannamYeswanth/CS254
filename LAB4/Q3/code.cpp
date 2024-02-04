#include <bits/stdc++.h>
using namespace std;

int part(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}

int klarge(int arr[], int l, int r, int K)
{
	if (K > 0 && K <= r - l + 1) {
		int p = part(arr, l, r);
		if (p - l == K - 1)
			return arr[p];
		if (p - l > K - 1)
			return klarge(arr, l, p - 1, K);
		return klarge(arr,p+1,r,K-p+l-1);			
	}
	return INT_MIN;
}
int main()
{
	 ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    int n,K;
    inputFile >> n>>K;
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
    outputFile << "K'th large element is "
		<< klarge(A, 0, n - 1, n-K+1)<< endl;

    outputFile.close();

	return 0;
}
