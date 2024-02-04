#include <bits/stdc++.h>
using namespace std;

double median(int a[], int n, int b[], int m){
	int l = 0, r = n, i, j, median;

	while (l <= r) {
		i = (l + r) / 2;
		j = ((n + m + 1) / 2) - i;
		if (j < 0) {
			r = i - 1;
			continue;
		}
		if (i < n && j > 0 && b[j - 1] > a[i])
			l = i + 1;
		else if (i > 0 && j < m && b[j] < a[i - 1])
			r = i - 1;
		else {	
			if (i == 0)
				median = b[j - 1];
			else if (j == 0)
				median = a[i - 1];
			else
				median = max(a[i - 1], b[j - 1]);
			break;
		}
	}
	if ((n + m) % 2 == 1)
		return (double)median;

	if (i == n)
		return (median + b[j]) / 2.0;

	if (j == m)
		return (median + a[i]) / 2.0;

	return (median + min(a[i], b[j])) / 2.0;
}

int main(){

    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    int n,m;
    inputFile >> n>> m;
    if(n>m){swap(n,m);}
    int A[n],B[m];
    
    for (int i = 0; i < n; ++i) {
        inputFile >> A[i];
    }
    for (int i = 0; i < m; ++i) {
        inputFile >> B[i];
    }

    inputFile.close();
    ofstream outputFile("output.txt");
     if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }
   
    outputFile << "Median is : " <<  median(A,n,B,m) << endl;

    outputFile.close();

    return 0;
}