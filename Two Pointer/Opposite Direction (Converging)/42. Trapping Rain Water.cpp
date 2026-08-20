// question : https://leetcode.com/problems/trapping-rain-water/description/

// resources: https://youtu.be/1_5VuquLbXg?si=ThC51Xsh19-Dx-h_


// Understanding the problem:
// https://www.notion.so/42-Trapping-Rain-Water-368bc354b84b80ba8087cc6d4da95f91?source=copy_link


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int left = 0;
        int right = n - 1;

        int leftMax = 0;    // initially no height is seen from left
        int rightMax = 0;

        int water = 0;

        while (left < right) {

            // Process left side
            if (height[left] < height[right]) {   // this is the deciding factor that how much water can be tarpped, as samller height will decide the water trapping capacity  

                if (height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    water += leftMax - height[left];
                }

                left++;
            }

            // Process right side
            else {

                if (height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {
                    water += rightMax - height[right];
                }

                right--;
            }
        }

        return water;
    }
};

// In the two pointer approach, we maintain two pointers, left and right, starting at 
// the beginning and end of the array, respectively. We also keep track of the maximum
// height seen so far from both sides (leftMax and rightMax) and keep comparing the heights
// at the left and right pointers. We move the pointer that has the smaller height, and check
// if the current height of left or right pointer is greater than or equal to the maximum 
// height seen so far from that side. If it is, we update the maximum height; otherwise, we 
// calculate the water trapped at that position and add it to the total water. We continue this
//  process until the left and right
// pointers meet.


// simply we are moving pointer inward form both the end (left and right pointer) and these pointers
// aslo checking if we are the current height is greater than or equal to the maximum height seen so far 
// from that side (left or right). If it is, we update the maximum height; otherwise, we calculate the water by subtracting
// the current height from the maximum height seen so far from that side and that side max height is smaller from the other side,
// which gives us the amount of water trapped at that position and add it to the total water. We continue 
// this process until the left and right pointers meet.














