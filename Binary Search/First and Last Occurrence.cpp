// Multiple answers:
// https://takeuforward.org/arrays/first-and-last-occurrences-in-array
// https://www.geeksforgeeks.org/dsa/find-first-and-last-positions-of-an-element-in-a-sorted-array/#alternate-approach-1-using-binary-search-olog-n-time-and-o1-space


// First and Last Occurrence (LeetCode 34)

// Given a sorted array nums and a target, return the first and last position of the target.
// If target is not present, return [-1, -1].


#include <bits/stdc++.h>
using namespace std;

class FirstAndLastPosition {
private:

    // Binary search to find the first occurrence of k
    int firstOccurrence(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        int first = -1; // default: not found

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == k) {
                first = mid;      // store potential first occurrence
                high = mid - 1;   // keep searching left side
            }
            else if (arr[mid] < k) {
                low = mid + 1;    // move to right side
            }
            else {
                high = mid - 1;   // move to left side
            }
        }
        return first;
    }

    // Binary search to find the last occurrence of k
    int lastOccurrence(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        int last = -1; // default: not found

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == k) {
                last = mid;       // store potential last occurrence
                low = mid + 1;    // keep searching right side
            }
            else if (arr[mid] < k) {
                low = mid + 1;    // move to right side
            }
            else {
                high = mid - 1;   // move to left side
            }
        }
        return last;
    }

public:
    // Main function to return first and last occurrence
    pair<int, int> findFirstAndLast(vector<int>& arr, int k) {
        int first = firstOccurrence(arr, k);
        if (first == -1) return {-1, -1}; // element not found

        int last = lastOccurrence(arr, k);
        return {first, last};
    }
};

int main() {
    FirstAndLastPosition solution;
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int k = 8;

    pair<int, int> ans = solution.findFirstAndLast(arr, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";

    return 0;
}




Interview Trick:
Whenever you need first/leftmost answer → store ans and go left.
Whenever you need last/rightmost answer → store ans and go right.


Pattern to Remember

For First Occurrence:

if(arr[mid] == target){
    ans = mid;
    high = mid - 1; // move LEFT
}

For Last Occurrence:

if(arr[mid] == target){
    ans = mid;
    low = mid + 1; // move RIGHT
}


