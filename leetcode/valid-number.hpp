//
//  valid-number.hpp
//  leetcode
//
//  Created by lorabit on 10/26/16.
//  Copyright © 2016 From Network Technology. All rights reserved.
//
//  https://leetcode.com/problems/valid-number/

#ifndef valid_number_hpp
#define valid_number_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <regex>

#define MAX_LENGTH 200


using namespace std;

class Solution65 {
    regex number;
    bool isInitiated = false;
public:
    
    bool isUnsignedInt(string s){
        if(s.length() == 0) return false;
        for(int i = 0;i<s.length();i++){
            if(s[i]>'9' || s[i]<'0') return false;
        }
        return true;
    }
    
    bool isSignedInt(string s){
        if(s.length() == 0) return false;
        if(s[0] == '-' || s[0] == '+')
            return this->isUnsignedInt(s.substr(1));
        return this->isUnsignedInt(s);
    }
    
    bool isUnsignedFloat(string s){
        string::size_type index = s.find('.');
        if(index == string::npos)
            return isUnsignedInt(s);
        if(index == 0) return isUnsignedInt(s.substr(1));
        if(index == s.length()-1) return isUnsignedInt(s.substr(0,s.length()-1));
        return isUnsignedInt(s.substr(0, index)) && isUnsignedInt(s.substr(index+1, s.length() - index - 1));
    }
    
    bool isSignedFloat(string s){
        if(s.length() == 0) return false;
        if(s[0] == '-' || s[0] == '+')
            return isUnsignedFloat(s.substr(1));
        return isUnsignedFloat(s);
    }
    
    bool isNumber(string s) {
        if(s.length()==0) return false;
        unsigned long begin = 0, end = s.length()-1;
        for(unsigned int i = 0; i < s.length() ; i++){
            if(s[i] != ' '){
                begin = i;
                break;
            }
        }
        for(long i = s.length()-1; i >= 0 ; i--){
            if(s[i] != ' '){
                end = i;
                break;
            }
        }
        
        s = s.substr(begin, end - begin + 1);
        long eindex = s.find('e');
        if(eindex == string::npos){
            return isSignedFloat(s);
        }
        return isSignedFloat(s.substr(0,eindex)) && isSignedInt(s.substr(eindex+1, s.length() - eindex));
    }
    
    //works but got TLE
    bool isNumberByReg(string s) {
        if(!this->isInitiated){
            regex number(" *(\\+|-)?(([[:digit:]]+(\\.)?[[:digit:]]*)|([[:digit:]]*(\\.)?[[:digit:]]+))((e(\\+|-)?)?[[:digit:]]+)? *");
            this->number = number;
            this->isInitiated = true;
        }
        return regex_match(s,this->number);
    }
};

class Test65 {
    
private:
    Solution65 solution;
    
    void testWithCase( string word,  bool answer){
        bool result = solution.isNumber(word);
        if(result == answer){
            cout << "Passed\n";
        }else{
            cout << "Failed\n";
            cout << "Input: " << word<<'\n';
            cout << "Your answer: \n";
            cout << (result?"True":"False");
            cout << "\n";
            cout << "Correct answer: \n";
            cout << (answer?"True":"False");
            cout << "\n";
        }
    }
    
public:
    void testCase1(){
        string s = "0";
        bool answer = true;
        cout << "TestCase 1: ";
        (testWithCase(s, answer));
    }
    
    void testCase2(){
        string s = " 0.1 ";
        bool answer = true;
        cout << "TestCase 2: ";
        (testWithCase(s, answer));
    }
    
    void testCase3(){
        string s = "abc";
        bool answer = false;
        cout << "TestCase 3: ";
        (testWithCase(s, answer));
    }
    
    void testCase4(){
        string s = "1 a";
        bool answer = false;
        cout << "TestCase 4: ";
        (testWithCase(s, answer));
    }
    
    void testCase5(){
        string s = "2e10";
        bool answer = true;
        cout << "TestCase 5: ";
        (testWithCase(s, answer));
    }
    
    void testCase6(){
        string s = ".1";
        bool answer = true;
        cout << "TestCase 6: ";
        (testWithCase(s, answer));
    }
    void testCase7(){
        string s = ".";
        bool answer = false;
        cout << "TestCase 7: ";
        (testWithCase(s, answer));
    }
    void testCase8(){
        string s = ".e";
        bool answer = false;
        cout << "TestCase 8: ";
        (testWithCase(s, answer));
    }
    void testCase9(){
        string s = ".e1";
        bool answer = false;
        cout << "TestCase 9: ";
        (testWithCase(s, answer));
    }
    void testCase10(){
        string s = "3.";
        bool answer = true;
        cout << "TestCase 10: ";
        (testWithCase(s, answer));
    }
    void testCase11(){
        string s = " 005047e+6";
        bool answer = true;
        cout << "TestCase 11: ";
        (testWithCase(s, answer));
    }
    
};


#endif /* valid_number_hpp */
