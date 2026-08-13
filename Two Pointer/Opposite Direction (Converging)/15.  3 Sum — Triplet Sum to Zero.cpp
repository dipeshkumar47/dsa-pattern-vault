
// question: https://leetcode.com/problems/3sum/?utm_source=chatgpt.com


// Code Recipe:
// best article: https://www.code-recipe.com/post/three-sum
// https://youtu.be/cRBSOz49fQk?si=2QvVsX5kMu7PEvOG


// better readable code
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {-1,0,1,2,-1,-4};
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int l = i + 1, r = n - 1;

        while(l < r) {
            int sum = arr[i] + arr[l] + arr[r];
            if(sum == 0) {
                cout << "[" << arr[i] << ", " << arr[l] << ", " << arr[r] << "] ";
                l++; r--;                                                                       // to avoid duplicates 
                while(l < r && arr[l] == arr[l-1]) l++;  // to avoid duplicates from left
                while(l < r && arr[r] == arr[r+1]) r--;  // to avoid duplicates from right
            }
            else if(sum < 0) l++;
            else r--;
        }
    }
    return 0;
}





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {

                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicates from left
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicates from right
                    while (left < right &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                else if (sum < 0) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return ans;
    }
};



























