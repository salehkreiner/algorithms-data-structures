#include <iostream>
#include <vector>

using namespace std;

// Function to perform shell sort
void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for this gap size
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3};

    // Perform shell sort
    // Time Complexity: Depends on the gap sequence.
    // Optimal gap sequence gives O(n log n) in best and average cases.
    // Worst case is generally O(n^2) but can be better with certain gap sequences.
    shellSort(arr);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
