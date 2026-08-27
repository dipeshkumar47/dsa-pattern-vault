
// solution from striver


// Search in Rotated Sorted Array I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to search for target using binary search in rotated sorted array
    int search(vector<int>& nums, int target) {

        // Set the search space to entire array
        int low = 0;
        int high = nums.size() - 1;

        // Continue until the search space becomes invalid
        while (low <= high) {

            // Find the middle index
            int mid = (low + high) / 2;

            // If the target is found at mid, return mid
            if (nums[mid] == target)
                return mid;

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {

                // If target lies in the sorted left half, search there
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                // Else search in the right half
                else {
                    low = mid + 1;
                }
            }

            // Otherwise, right half is sorted
            else {

                // If target lies in the sorted right half, search there
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }
                // Else search in the left half
                else {
                    high = mid - 1;
                }
            }
        }

        // If not found, return -1
        return -1;
    }
};

// Driver code
int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    Solution obj;
    int result = obj.search(nums, target);

    cout << result << endl;

    return 0;
}


//------------------------------------------------------------------------------------------------------------------------------------------------------


// Search in Rotated Sorted Array II

// https://algo.monster/liteproblems/81
// https://youtu.be/w2G2W8l__pc?si=lBPEzpM4zQ2E_b3a

// striver code is more better 



class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;  // Calculate middle index to avoid overflow

            // Case 1: Left half is sorted (pivot is in right half)
            if (nums[mid] > nums[right]) {
                // Check if target is in the sorted left half
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid;  // Search in left half
                } 
                else {
                    left = mid + 1;  // Search in right half
                }
            }


            // Case 2: Right half is sorted (pivot is in left half)
            else if (nums[mid] < nums[right]) {
                // Check if target is in the sorted right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Search in right half
                } else {
                    right = mid;  // Search in left half
                }
            }



            // Case 3: Cannot determine which half is sorted due to duplicates
            else {
                // nums[mid] == nums[right], reduce search space by one
                --right;
            }
        }

        // Check if the remaining element is the target
        return nums[left] == target;
    }

};

// --------------------------------------------------------------------------------------------------------

// striver code version:
// appraoch note : https://takeuforward.org/arrays/search-element-in-rotated-sorted-array-ii


#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If mid points to the target
        if (arr[mid] == k) return true;

        // Edge case: all three are equal, we cannot determine which side is sorted
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        // If the left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1; // Target lies in left
            } else {
                low = mid + 1;  // Target lies in right
            }
        } else {
            // Right half is sorted
            if (arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;  // Target lies in right
            } else {
                high = mid - 1; // Target lies in left
            }
        }
    }

    return false;
}

int main() {
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (ans)
        cout << "Target is present in the array.\n";
    else
        cout << "Target is not present.\n";
    return 0;
}



// -----------------------------------------------------------------------------------------------------------------












