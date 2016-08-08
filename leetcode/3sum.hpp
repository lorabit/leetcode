//
//  3sum.cpp
//  leetcode
//
//  Created by lorabit on 8/5/16.
//  Copyright © 2016 From Network Technology. All rights reserved.
//

#ifndef 3sum_hpp
#define 3sum_hpp

class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
    }
};


bool tripleComparator(vector<int> trip1, vector<int> trip2){
    for (vector<int>::iterator iter = trip1.begin(),vector<int>::iterator iter2 = trip2.begin(); iter != trip1.end() ; iter++, iter2++) {
        if(*iter>*iter2)
            return true;
        if(*iter<*iter2)
            return false;
    }
    return true;
}


class Test15 {
    
private:
    Solution15 solution;
    
    bool compareResult( vector<string>& solution, vector<string>& correctAnswer){
        if(solution.size() != correctAnswer.size()) return false;
        sort(solution.begin(), solution.end(), stringComparator);
        sort(correctAnswer.begin(), correctAnswer.end(),stringComparator);
        vector<string>::iterator iter1, iter2;
        for (iter1 = solution.begin(), iter2 = correctAnswer.begin(); iter1!=solution.end(); iter1++, iter2++) {
            if(iter2->compare(*iter1)!=0){
                return false;
            }
        }
        return true;
    }
    
    void testWithCase( vector<int> &nums ,  vector<vector<int>> &result){
        
    }
    
public:
    Test140(){
        solution = Solution140();
    }
    
    void testCase1(){
        cout << "TestCase 1: ";
        
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> result = {
            {-1, 0, 1},
            {-1, -1, 2}
        };
        testWithCase(nums,result);
    }
    
    void testCase2(){
        cout << "TestCase 2: ";
        
    }
    
    void testCase3(){
        cout << "TestCase 3: ";
        
        
    }
};


#endif


