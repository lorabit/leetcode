//
//  find-minimum-in-rotated-sorted-array.hpp
//  leetcode
//
//  Created by lorabit on 8/8/16.
//  Copyright © 2016 From Network Technology. All rights reserved.
//
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#ifndef find_minimum_in_rotated_sorted_array_h
#define find_minimum_in_rotated_sorted_array_h

#include <vector>

class Solution153 {
public:
    int findMin(vector<int>& nums) {
        int v = nums[0];
        int n = (int)nums.size();
        if(nums[0] <= nums[n-1]) return nums[0];
        int l = 0;
        int r = n - 1;
        while(l<r){
            int p = (l+r)/2;
            int x = nums[p];
            if(x>=v){
                l = p + 1;
            }else{
                r = p ;
            }
        }
        return nums[r];
    }

};


class Test153 {
    
private:
    Solution153 solution;
    
    void testWithCase( vector<int> &nums, int result){
        int res = solution.findMin(nums);
        if(res == result){
            cout << "Passed\n";
        }else{
            cout << "Failed\n";
            cout << "Your answer: \n";
            cout << res;
            cout << "\n";
            cout << "Correct answer: \n";
            cout << result;
            cout << "\n";
        }
    }
    
public:
    Test153(){
        solution = Solution153();
    }
    
    void testCase1(){
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int result = 0;
        cout << "TestCase 1: ";
        testWithCase(nums, result);
    }
    
    void testCase2(){
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int result = 0;
        cout << "TestCase 2: ";
        testWithCase(nums, result);
    }
    
    void testCase3(){
        vector<int> nums = {0, 5, 7, 10, 11, 12, 14, 15, 20, 33, 49, 555, 777, 1000};
        int result = 0;
        cout << "TestCase 3: ";
        testWithCase(nums, result);
    }
    
    void testCase4(){
        vector<int> nums = {14, 15, 20, 33, 49, 555, 777, 1000,  5, 7, 10, 11, 12};
        int result = 5;
        cout << "TestCase 4: ";
        testWithCase(nums, result);
    }
    
    void testCase5(){
        vector<int> nums = {5, 7, 10, 11, 12, 14, 15, 20, 33, 49, 555, 777, 1000, 0};
        int result = 0;
        cout << "TestCase 5: ";
        testWithCase(nums, result);
    }
    
    void testCase6(){
        vector<int> nums = {1, 3};
        int result = 1;
        cout << "TestCase 6: ";
        testWithCase(nums, result);
    }
    
    void testCase7(){
        vector<int> nums = {3, 1};
        int result = 1;
        cout << "TestCase 7: ";
        testWithCase(nums, result);
    }
    
    void testCase8(){
        vector<int> nums = {4,5,6,7,8,1,2,3};
        int result = 1;
        cout << "TestCase 8: ";
        testWithCase(nums, result);
    }
    
    void testCase9(){
        vector<int> nums = {1, 3};
        int result = 1;
        cout << "TestCase 9: ";
        testWithCase(nums, result);
    }
    
};

#endif /* find_minimum_in_rotated_sorted_array_h */
