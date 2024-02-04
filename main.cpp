#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

int partition(vector<int>& array, int low, int high){
    int pivot = array[low];
    int i = low;
    int j = high;

    while(i < j){
        while(array[i] <= pivot){
            i++;
        }
        while(array[j] > pivot){
            j--;
        }
        if(i < j){
            swap(array[i], array[j]);
        }
    }
    swap(array[j], array[low]);
    return j;
}

void quicksort(vector<int>& array, int low, int high){
    if(low < high){
        int j = partition(array, low, high);
        quicksort(array, low, j);
        quicksort(array, j+1, high);
    }

}

int main() {
    std::vector<int> array = {12, 4, 5, 6, 7, 3, 1, 15};

    std::cout << "Original array: ";
    for (int num : array) {
        std::cout << num << " ";
    }

    int arraySize = array.size();
    quicksort(array, 0, arraySize - 1);

    std::cout << "\nSorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }

    return 0;
}
