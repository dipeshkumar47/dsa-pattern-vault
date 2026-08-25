// You just to have to find the find the index of first and last occurrence of the target element in the sorted array,
// which can be done using binary search. The difference between the last and first occurrence will give you the count 
// of occurrences of the target element in the sorted array.


#include <iostream>
using namespace std;

// Function to find first occurrence
int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;   // Search left half
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

// Function to find last occurrence
int lastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;   // Search right half
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;

    int first = firstOccurrence(arr, n, key);
    int last = lastOccurrence(arr, n, key);

    if (first == -1) {
        cout << "Element not found";
    } else {
        int count = last - first + 1;                             
        cout << "Occurrences of " << key << " = " << count;
    }

    return 0;
}


// 1 2 3 
// 1,2,3 => (3 - 1) = 2 X 
// 1,2,3 => (3 - 1) + 1 = 3 ✅



// --------------------------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countFreq(vector<int> &arr, int target) {
    int l = lower_bounda(arr.begin(), arr.end(), target) - arr.begin();
    int r = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
      
    // Return the differnce between upper
    // bound and lower bound of the target
    return r - l;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int target = 2;
    cout<< countFreq(arr, target);
    return 0;
}


// --------------------------------------------------------------------------------------------------------------------------------------






