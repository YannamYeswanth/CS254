#include<bits/stdc++.h>
using namespace std;

void swap_elements(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_elements(int arr[], int left, int right){
    int last = arr[right], i = left, j = left;
    while (j < right) {
        if (arr[j] < last) {
            swap_elements(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    swap_elements(&arr[i], &arr[right]);
    return i;
}

// Picking a random pivot between left and right and partitions arr[left...right] around the randomly picked element using partition_elements();
int random_partition(int arr[], int left, int right){
    int n = right - left + 1;
    int pivot = rand() % n;
    swap_elements(&arr[left + pivot], &arr[right]);
    return partition_elements(arr, left, right);
}

void median_calculation(int arr[], int left, int right, int k, int& lower_median, int& upper_median){
    if (left <= right) {
        int partition_index = random_partition(arr, left, right);
        // If partition index = k, then we found the median of an odd number of elements in arr[]
        if (partition_index == k) {
            upper_median = arr[partition_index];
            if (lower_median != -1)
                return;
        }
 
        // If index = k - 1, then we get lower_median & upper_median as the middle elements of arr[]
        else if (partition_index == k - 1) {
            lower_median = arr[partition_index];
            if (upper_median != -1)
                return;
        }
 
        // If partition_index >= k then find the index in the first half of arr[]
        if (partition_index >= k)
            return median_calculation(arr, left, partition_index - 1, k, lower_median, upper_median);
 
        // If partition_index <= k then find the index in the second half of arr[]
        else
            return median_calculation(arr, partition_index + 1, right, k, lower_median, upper_median);
    }
 
    return;
}

int find_median_value(int arr[], int size){
    int result, lower_median = -1, upper_median = -1;
    if (size % 2 == 1) {
        median_calculation(arr, 0, size - 1, size / 2, lower_median, upper_median);
        result = upper_median;
    }
    else {
        median_calculation(arr, 0, size - 1, size / 2, lower_median, upper_median);
        result = (lower_median + upper_median) / 2;
    }
    return result;
}

int quicksort_partition(int A[], int low, int high){
    int pivot = find_median_value(A + low, high - low + 1);
    int i = (low - 1);
    for (int j = low; j <= high; j++){
        if (A[j] < pivot){
            i++;
            swap_elements(A + i, A + j);
        }
        if (A[j] == pivot){
            swap_elements(A + j, A + high);
        }
    }
    swap_elements(A + i + 1, A + high);
    return (i + 1);
}

void quicksort_algorithm(int A[], int low, int high){
    if (low < high){
        int partition_index = quicksort_partition(A, low, high);
        quicksort_algorithm(A, low, partition_index - 1);
        quicksort_algorithm(A, partition_index + 1, high);
    }
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

    int size;
    input_file >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++){
        input_file >> arr[i];
    }
    input_file.close();

    clock_t start, end;
    start = clock();

    quicksort_algorithm(arr, 0, size - 1);
    end = clock();

    output_file << "The sorted array through Quicksort algo. considering the median to be the pivot: " << endl;
    for (int i = 0; i < size; i++){
        output_file << arr[i] << " ";
    }
    output_file << endl;

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    output_file << "The time taken to run the program is: " << time_taken << " sec" << endl;

    delete[] arr;
    return 0;
}
