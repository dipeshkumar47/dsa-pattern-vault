Lower Bound:

Question:
👉 Find the first element that is greater than or equal to x in a sorted array.

Example:
Array = [1, 3, 3, 5, 8], x = 3
Answer = Index of first 3 (index 1)

Upper Bound:

Question:
👉 Find the first element that is strictly greater than x in a sorted array.

Example:
Array = [1, 3, 3, 5, 8], x = 3
Answer = Index of 5 (index 3)

One-Line Memory Trick
Lower Bound = First >= x
Upper Bound = First > x ✅




// Lower Bound (First Element >= x)
int lowerBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x){
            ans = mid;
            high = mid - 1;   // search left part
        } 
        else {
            low = mid + 1;
        }
    }

    return ans;
}




// Upper Bound (First Element > x)
int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;   // search left part
        } else {
            low = mid + 1;
        }
    }

    return ans;
}






// Another method using STL (C++)

int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

// lower_bound() returns an iterator to the first element ≥ x.
// - arr.begin() converts that iterator into an index.





