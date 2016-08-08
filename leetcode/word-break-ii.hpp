//
//  word-break-ii.hpp
//  leetcode
//
//  Created by lorabit on 8/5/16.
//  Copyright © 2016 From Network Technology. All rights reserved.
//

#ifndef word_break_ii_hpp
#define word_break_ii_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>

#define MAX_LENGTH 200

using namespace std;


class Solution140 {
private:
    vector<string> result;
    int f[MAX_LENGTH];
    unordered_set<string> _wordDict;
    vector<string> currentResult;
    string sentence;
    
public:
    
    void generateResult(int p){
        if(p==0){
            vector<string>::iterator iter = currentResult.begin();
            string s = *(iter++);
            for (; iter!=currentResult.end(); iter ++) {
                s = *(iter) + " " + s;
            }
            result.push_back(s);
        }
        for(int i = 0; i<p; i++)
            if(f[i]){
                string s = sentence.substr(i,p-i);
                unordered_set<string>::const_iterator iter = _wordDict.find(s);
                if(iter != _wordDict.end()){
                    currentResult.push_back(*iter);
                    generateResult(i);
                    currentResult.pop_back();
                }
            }
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        fill(f, f+s.length()+1, 0);
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
        
        result = vector<string>();
        currentResult = vector<string>();
        _wordDict = wordDict;
        sentence = s;
        generateResult((int)s.length());
        
        return result;
    }
    
};



bool stringComparator(const string& s1, const string &s2){
    return s1.compare(s2)>=0;
}


class Test140 {
    
private:
    Solution140 solution;
    
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
    
    void testWithCase( string word,  unordered_set<string> &wordDict,  vector<string> &result){
        vector<string> res = solution.wordBreak(word,wordDict);
        if(compareResult(res, result)){
            cout << "Passed\n";
        }else{
            cout << "Failed\n";
            cout << "Your answer: \n";
            for(vector<string>::iterator iter = res.begin(); iter != res.end(); iter++){
                cout << *iter << "\n";
            }
            cout << "\n";
            cout << "Correct answer: \n";
            for(vector<string>::iterator iter = result.begin(); iter != result.end(); iter++){
                cout << *iter << "\n";
            }
            cout << "\n";
        }
    }
    
public:
    Test140(){
        solution = Solution140();
    }
    
    void testCase1(){
        string s = "catsanddog";
        unordered_set<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
        vector<string> result = {"cats and dog", "cat sand dog"};
        cout << "TestCase 1: ";
        (testWithCase(s, wordDict, result));
    }
    
    void testCase2(){
        string s = "catsanddog";
        unordered_set<string> wordDict = {"cat", "and", "sand", "dog"};
        vector<string> result = {"cat sand dog"};
        cout << "TestCase 2: ";
        (testWithCase(s, wordDict, result));
    }
    
    void testCase3(){
        string s = "yourpigisverygood";
        unordered_set<string> wordDict = {"your", "pig", "is", "very", "good", "y", "our"};
        vector<string> result = {
            "your pig is very good",
            "y our pig is very good"
        };
        cout << "TestCase 3: ";
        (testWithCase(s, wordDict, result));
    }
};


#endif /* word_break_ii_hpp */
