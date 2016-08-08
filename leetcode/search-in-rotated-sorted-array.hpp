//
//  search-in-rotated-sorted-array.hpp
//  leetcode
//
//  Created by lorabit on 8/8/16.
//  Copyright © 2016 From Network Technology. All rights reserved.
//

#ifndef search_in_rotated_sorted_array_h
#define search_in_rotated_sorted_array_h

#include <vector>

class Solution33 {
public:
    int search(vector<int>& nums, int target) {
        int v = nums[0];
        int n = (int)nums.size();
        if(target == v) return 0;
        if(target < v){
            int l = 0;
            int r = n-1;
            while(l<=r){
                int p = (l+r)/2;
                int x = nums[p];
                if(x == target) return p;
                if( x>=v || x<target){
                    l = p + 1;
                }else{
                    r = p - 1;
                }
            }
            return -1;
        }else{
            int l = 0;
            int r = n-1;
            while(l<=r){
                int p = (l+r)/2;
                int x = nums[p];
                if(x == target) return p;
                if( x<v || x>target){
                    r = p - 1;
                }else{
                    l = p + 1;
                }
            }
            return -1;
        }
        return 1;
    }
};


class Test33 {
    
private:
    Solution33 solution;
    
    void testWithCase( vector<int> &nums, int target, int result){
        int res = solution.search(nums,target);
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
    Test33(){
        solution = Solution33();
    }
    
    void testCase1(){
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 7;
        int result = 3;
        cout << "TestCase 1: ";
        testWithCase(nums, target, result);
    }
    
    void testCase2(){
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 4;
        int result = 0;
        cout << "TestCase 2: ";
        testWithCase(nums, target, result);
    }
    
    void testCase3(){
        vector<int> nums = {0, 5, 7, 10, 11, 12, 14, 15, 20, 33, 49, 555, 777, 1000};
        int target = 0;
        int result = 0;
        cout << "TestCase 3: ";
        testWithCase(nums, target, result);
    }
    
    void testCase4(){
        vector<int> nums = {14, 15, 20, 33, 49, 555, 777, 1000, 0, 5, 7, 10, 11, 12};
        int target = 7;
        int result = 10;
        cout << "TestCase 4: ";
        testWithCase(nums, target, result);
    }
    
    void testCase5(){
        vector<int> nums = {5, 7, 10, 11, 12, 14, 15, 20, 33, 49, 555, 777, 1000, 0};
        int target = 777;
        int result = 11;
        cout << "TestCase 5: ";
        testWithCase(nums, target, result);
    }
    
    void testCase6(){
        vector<int> nums = {1, 3};
        int target = 2;
        int result = -1;
        cout << "TestCase 6: ";
        testWithCase(nums, target, result);
    }
    
    void testCase7(){
        vector<int> nums = {3, 1};
        int target = 1;
        int result = 1;
        cout << "TestCase 7: ";
        testWithCase(nums, target, result);
    }
    
    void testCase8(){
        vector<int> nums = {4,5,6,7,8,1,2,3};
        int target = 8;
        int result = 4;
        cout << "TestCase 8: ";
        testWithCase(nums, target, result);
    }
    
    void testCase9(){
        vector<int> nums = {1, 3};
        int target = 3;
        int result = 1;
        cout << "TestCase 9: ";
        testWithCase(nums, target, result);
    }
    
};


#endif /* search_in_rotated_sorted_array_h */
