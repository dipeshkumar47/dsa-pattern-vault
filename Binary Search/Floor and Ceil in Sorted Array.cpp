
// Floor in a Sorted Array

Question:
👉 Given a sorted array and a target x, find the largest element that is less than or equal to x.


// Ceil in a Sorted Array

Question:
👉 Given a sorted array and a target x, find the smallest element that is greater than or equal to x.


One-Line Memory Trick
Floor = Largest <= x
Ceil = Smallest >= x ✅


// Floor (Largest Element <= x)

int floorValue(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            ans = arr[mid];
            low = mid + 1;    // search right
        } 
        else {
            high = mid - 1;
        }
    }

    return ans;
}


// 👉 Whenever arr[mid] <= x, it can be a possible answer, so store it and move right to find a larger valid value.


// Ceil (Smallest Element >= x)
👉 Same as Lower Bound.

int ceilValue(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = arr[mid];
            high = mid - 1;   // search left
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

// finding ceil is opposite to floor as we are going to left to find a smaller valid value.
// Whenever arr[mid] >= x, it can be a possible answer, so store it and move left to find a smaller valid value.



// Floor = Largest <= x
//        Store answer and move RIGHT

// Ceil  = Smallest >= x
//        Store answer and move LEFT


// Lower Bound → returns index
// Ceil → returns value
// Logic is otherwise the same. ✅
