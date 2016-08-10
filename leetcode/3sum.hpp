//
//  3sum.cpp
//  leetcode
//
//  Created by lorabit on 8/5/16.
//  Copyright © 2016 From Network Technology. All rights reserved.
//

#ifndef _3sum_hpp
#define _3sum_hpp

#include <vector>
#include <sys/time.h>

bool tripleComparator(vector<int>& trip1, vector<int>& trip2){
    sort(trip1.begin(),trip1.end());
    sort(trip2.begin(),trip2.end());
    vector<int>::iterator iter = trip1.begin();
    vector<int>::iterator iter2 = trip2.begin();
    for (; iter != trip1.end() ; iter++, iter2++) {
        if(*iter>*iter2)
            return true;
        if(*iter<*iter2)
            return false;
    }
    return true;
}



class Solution15 {
    
public:
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0) return result;
        vector<int> sortedNums;
        sortedNums.insert(sortedNums.end(), nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());
        vector<int> filteredNums;
        vector<int>::iterator iter = sortedNums.begin();
        int last = *iter;
        int lastCount = 1;
        filteredNums.push_back(*iter++);
        for (; iter != sortedNums.end(); iter++) {
            if(*iter!=last){
                filteredNums.push_back(*iter);
                last = *iter;
                lastCount = 1;
            }else{
                ++lastCount;
                if((lastCount<=2)||(lastCount<=3 && *iter==0))
                    filteredNums.push_back(*iter);
            }
        }
        int n = (int)filteredNums.size();
        vector<vector<int>> candidates;
        for(int i = 0; i<n; i++){
            if(filteredNums[i]>0) break;
            if(i>0 && filteredNums[i] == filteredNums[i-1]) continue;
            for(int j = i+1; j<n ; j++){
                if(j>i+1 && filteredNums[j] == filteredNums[j-1]) continue;
                int c = filteredNums[i] + filteredNums[j];
                if( c>0) break;
                int l = j + 1;
                int r = n - 1;
                int p;
                int x;
                while(l<r){
                    p = (l+r)/2;
                    x = filteredNums[p];
                    if(x<c){
                        l = p + 1;
                    }else{
                        r = p - 1;
                    }
                }
                for(int k = l; k < n; k++){
                    if(k>j+1 && filteredNums[k] == filteredNums[k-1]) continue;
                    int s = c + filteredNums[k];
                    if(s>0) break;
                    if(s == 0){
                        vector<int> triplet = {filteredNums[i],filteredNums[j],filteredNums[k]};
                        candidates.push_back(triplet);
                    }
                }
            }
        }
        return candidates;
    }
};




class Test15 {
    
private:
    Solution15 solution;
    
    bool compareResult( vector<vector<int>>& solution, vector<vector<int>>& correctAnswer){
        if(solution.size() != correctAnswer.size()) return false;
        sort(solution.begin(), solution.end(), tripleComparator);
        sort(correctAnswer.begin(), correctAnswer.end(), tripleComparator);
        vector<vector<int>>::iterator iter1, iter2;
        for (iter1 = solution.begin(), iter2 = correctAnswer.begin(); iter1!=solution.end(); iter1++, iter2++) {
            if((*iter1)[0] != (*iter2)[0] || (*iter1)[1] != (*iter2)[1] || (*iter1)[2] != (*iter2)[2]){
                return false;
            }
        }
        return true;
    }
    
    void printTriplet(vector<int>& res){
        for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++){
            cout << *iter << " ";
        }
        cout << "\n";
    }
    
    void testWithCase( vector<int> &nums ,  vector<vector<int>> &result){
        struct timeval tv_begin, tv_end;
        gettimeofday(&tv_begin, NULL);
        vector<vector<int>> res = solution.threeSum(nums);
        gettimeofday(&tv_end, NULL);
        if(compareResult(res, result)){
            cout << "Passed\n";
        }else{
            cout << "Failed\n";
            cout << "Your answer: \n";
            for(vector<vector<int>>::iterator iter = res.begin(); iter != res.end(); iter++){
                printTriplet(*iter);
            }
            cout << "\n";
            cout << "Correct answer: \n";
            for(vector<vector<int>>::iterator iter = result.begin(); iter != result.end(); iter++){
                printTriplet(*iter);
            }
            cout << "\n";
        }
        cout << "Time: " << (tv_end.tv_sec - tv_begin.tv_sec)*1000000 + tv_end.tv_usec - tv_begin.tv_usec << "\n";
    }
    
public:
    Test15(){
        solution = Solution15();
    }
    
    //leetcode case
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
        vector<int> nums = {-1, 0};
        vector<vector<int>> result = {
        };
        testWithCase(nums,result);
        
    }
    
    void testCase3(){
        cout << "TestCase 3: ";
        vector<int> nums = {0,0,0,0,0,0};
        vector<vector<int>> result = {
            {0,0,0},
        };
        testWithCase(nums,result);
    }
    
    void testCase4(){
        cout << "TestCase 4: ";
        vector<int> nums = {0,0,1,0,-1,0};
        vector<vector<int>> result = {
            {0,0,0},
            {0,1,-1},
        };
        testWithCase(nums,result);
    }
    
    void testCase5(){
        cout << "TestCase 5: ";
        vector<int> nums = {0,0,0,0,0,0};
        vector<vector<int>> result = {
            {0,0,0},
        };
        testWithCase(nums,result);
    }
    
    //leetcode case
    void testCase6(){
        cout << "TestCase 6: ";
        vector<int> nums = {};
        vector<vector<int>> result = {
        };
        testWithCase(nums,result);
    }
    
    //leetcode case
    void testCase7(){
        cout << "TestCase 7: ";
        vector<int> nums = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
        vector<vector<int>> result = {
            {-15,1,14},
            {-15,2,13},
            {-15,3,12},
            {-15,4,11},
            {-15,5,10},
            {-15,6,9},
            {-15,7,8},
            {-14,0,14},
            {-14,1,13},
            {-14,2,12},
            {-14,3,11},
            {-14,4,10},
            {-14,5,9},
            {-14,6,8},
            {-14,7,7},
            {-13,-1,14},
            {-13,0,13},
            {-13,1,12},
            {-13,2,11},
            {-13,3,10},
            {-13,4,9},
            {-13,5,8},
            {-13,6,7},
            {-12,-2,14},
            {-12,-1,13},
            {-12,0,12},
            {-12,1,11},
            {-12,2,10},
            {-12,3,9},
            {-12,4,8},
            {-12,5,7},
            {-12,6,6},
            {-11,-3,14},
            {-11,-2,13},
            {-11,-1,12},
            {-11,0,11},
            {-11,1,10},
            {-11,2,9},
            {-11,3,8},
            {-11,4,7},
            {-11,5,6},
            {-10,-4,14},
            {-10,-3,13},
            {-10,-2,12},
            {-10,-1,11},
            {-10,0,10},
            {-10,1,9},
            {-10,2,8},
            {-10,3,7},
            {-10,4,6},
            {-10,5,5},
            {-9,-5,14},
            {-9,-4,13},
            {-9,-3,12},
            {-9,-2,11},
            {-9,-1,10},
            {-9,0,9},
            {-9,1,8},
            {-9,2,7},
            {-9,3,6},
            {-9,4,5},
            {-8,-6,14},
            {-8,-5,13},
            {-8,-4,12},
            {-8,-3,11},
            {-8,-2,10},
            {-8,-1,9},
            {-8,0,8},
            {-8,1,7},
            {-8,2,6},
            {-8,3,5},
            {-8,4,4},
            {-7,-7,14},
            {-7,-6,13},
            {-7,-5,12},
            {-7,-4,11},
            {-7,-3,10},
            {-7,-2,9},
            {-7,-1,8},
            {-7,0,7},
            {-7,1,6},
            {-7,2,5},
            {-7,3,4},
            {-6,-6,12},
            {-6,-5,11},
            {-6,-4,10},
            {-6,-3,9},
            {-6,-2,8},
            {-6,-1,7},
            {-6,0,6},
            {-6,1,5},
            {-6,2,4},
            {-6,3,3},
            {-5,-5,10},
            {-5,-4,9},
            {-5,-3,8},
            {-5,-2,7},
            {-5,-1,6},
            {-5,0,5},
            {-5,1,4},
            {-5,2,3},
            {-4,-4,8},
            {-4,-3,7},
            {-4,-2,6},
            {-4,-1,5},
            {-4,0,4},
            {-4,1,3},
            {-4,2,2},
            {-3,-2,5},
            {-3,-1,4},
            {-3,0,3},
            {-3,1,2},
            {-2,-2,4},
            {-2,-1,3},
            {-2,0,2},
            {-2,1,1},
            {-1,-1,2},
            {-1,0,1},
            {0,0,0}
        };
        testWithCase(nums,result);
    }
};


#endif


