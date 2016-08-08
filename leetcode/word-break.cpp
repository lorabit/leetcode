//
//  word-break.cpp
//  leetcode
//
//  Created by lorabit on 8/5/16.
//  Copyright © 2016 From Network Technology. All rights reserved.
//

#include "word-break.hpp"

#define MAX_LENGTH 200


using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int f[MAX_LENGTH] = {0};
        f[0] = 1;
        for(int i = 1; i <= s.length() ; i++){
            for(int j = 0; j < i ; j++){
                if(f[j]){
                    unordered_set<string>::const_iterator iter = wordDict.find(s.substr(j,i-j));
                    if(iter!=wordDict.end()){
                        f[i] = 1;
                        break;
                    }
                }
            }
        }
        return f[s.length()] == 1;
    }
};

