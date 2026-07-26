// best article: https://takeuforward.org/data-structure/insert-new-interval


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
//To insert new interval
    vector<vector<int>> insertNewInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // Initialize a vector
        vector<vector<int>> res; 
        
        /* Track the index while
        iterating through 
        intervals */
        int i = 0; 
        
        // Get total intervals
        int n = intervals.size(); 
        
        // Insert intervals before newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            /* Add intervals to the result vector
            until their end time is before
            the start time of newInterval */
            
            res.push_back(intervals[i]); 
            // Move to next interval
            i = i + 1; 
        }
        
        // Merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]){
            /* Update the start time of newInterval to the
            minimum of its current start time and the
            start time of the current interval */
            newInterval[0] = min(newInterval[0], intervals[i][0]); 
            
            /* Update the end time of newInterval to the
            maximum of its current end time and the
            end time of the current interval */
            newInterval[1] = max(newInterval[1], intervals[i][1]); 
            
            // Move to the next interval
            i = i + 1; 
        }
        
        /* Insert the merged interval
        Add the merged interval to 
        the result vector */
        res.push_back(newInterval); 
        
        /* Insert remaining 
        intervals after 
        newInterval */
        while(i < n){
            
            /* Add the remaining intervals
            after newInterval to the result
            vector */
            res.push_back(intervals[i]); 
            
            // Move to next interval
            i = i + 1; 
        }
        
        // Return result vector
        return res; 
    }
};




int main() {
    vector<vector<int>> intervals = {{1, 2}, {3, 4}, {6, 7}, {8, 10}, {12, 16}};
    cout << "Intervals Array: ";
    for(auto interval: intervals){
        cout << "[" << interval[0] << ", "<< interval[1]<< "], ";
    }
    cout << endl;
    
    vector<int> newInterval = {5, 8};
    cout << "New Interval to be Inserted: ";
    cout << "[" << newInterval[0] << ", "<< newInterval[1]<< "]" << endl;
    
    Solution sol;
    vector<vector<int>> result = sol.insertNewInterval(intervals, newInterval);
    for(auto interval: result){
        cout << "[" << interval[0] << ", "<< interval[1]<< "], ";
    }
    cout << endl;
    
    return 0;

}