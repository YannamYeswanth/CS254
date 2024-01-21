#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream input_file("input.txt");
    if(!input_file.is_open()){
        cerr << "Error opening the input file" << endl;
    }
    ofstream output_file("output.txt");
    if(!output_file.is_open()){
        cerr << "Error opening the output file" << endl;
    }

    int size;
    input_file >> size;
    
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        input_file >> arr[i];
    }
    input_file.close();

    clock_t start, end;
    start = clock();

    int least_element = INT_MAX;
    int second_least_element = INT_MAX;

    for(int i = 0; i < size; i++){
        if(arr[i] < least_element){
            second_least_element = least_element;
            least_element = arr[i];
        }
        else if(arr[i] < second_least_element && arr[i] != least_element){
            second_least_element = arr[i];
        }
    }

    end = clock();

    output_file << "The least element of the given unsorted array is: " << least_element << endl;
    output_file << "While the second least element is: " << second_least_element << endl;

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    output_file << "The time taken to run the program is: " << time_taken << " sec" << endl;
    output_file << "The program runs a for loop from 0 to n. Hence the Time Complexity is O(n).";
    
    delete[] arr;
    return 0;
}
