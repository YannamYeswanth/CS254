#include<bits/stdc++.h>
using namespace std;

// Function to swap the elements
void swap_elements(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to return the correct position of the pivot element
int partition_array(int arr[], int left, int right){
    int pivot_value = arr[right];
    int i = left, j = left;
    
    while (j < right) {
        if (arr[j] < pivot_value) {
            swap_elements(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }

    swap_elements(&arr[i], &arr[right]);
    return i;
}

// Randomly selects a pivot element and partitions the array
int random_partition(int arr[], int left, int right){
    int size = right - left + 1;
    int pivot_index = rand() % size;
    
    swap_elements(&arr[left + pivot_index], &arr[right]);
    return partition_array(arr, left, right);
}

// Recursive function to find the median of the array
void find_median_recursive(int arr[], int left, int right, int k, int& lower_median, int& upper_median){
    if (left <= right) {
        int partition_index = random_partition(arr, left, right);

        if (partition_index == k) {
            upper_median = arr[partition_index];
            if (lower_median != -1)
                return;
        } 
        else if (partition_index == k - 1) {
            lower_median = arr[partition_index];
            if (upper_median != -1)
                return;
        }

        if (partition_index >= k)
            return find_median_recursive(arr, left, partition_index - 1, k, lower_median, upper_median);
        else
            return find_median_recursive(arr, partition_index + 1, right, k, lower_median, upper_median);
    }
}

// Finds and returns the median of the array
int find_median_value(int arr[], int size){
    int result, lower_median = -1, upper_median = -1;

    if (size % 2 == 1) {
        find_median_recursive(arr, 0, size - 1, size / 2, lower_median, upper_median);
        result = upper_median;
    } else {
        find_median_recursive(arr, 0, size - 1, size / 2, lower_median, upper_median);
        result = (lower_median + upper_median) / 2;
    }

    return result;
}

int main(){
    ifstream input_file("input.txt");
    if (!input_file.is_open()){
        cerr << "Error opening the input file" << endl;
    }
    ofstream output_file("output.txt");
    if (!output_file.is_open()){
        cerr << "Error opening the output file" << endl;
    }

    int array_size;
    input_file >> array_size;

    int *input_array = new int[array_size];
    for (int i = 0; i < array_size; i++){
        input_file >> input_array[i];
    }
    input_file.close();

    clock_t start, end;
    start = clock();

    int median_result = find_median_value(input_array, array_size);
    end = clock();

    output_file << "The median of the unsorted array is: " << median_result << endl;
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    output_file << "The time taken to run the program is: " << time_taken << " sec" << endl;

    delete[] input_array;
    return 0;
}
