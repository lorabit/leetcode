//
//  max-points-on-a-line.hpp
//  leetcode
//
//  Created by lorabit on 10/26/16.
//  Copyright © 2016 From Network Technology. All rights reserved.
//
//  https://leetcode.com/problems/max-points-on-a-line/

#ifndef max_points_on_a_line_hpp
#define max_points_on_a_line_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <regex>

#define MAX_LENGTH 200

struct Point {
         int x;
         int y;
         Point() : x(0), y(0) {}
         Point(int a, int b) : x(a), y(b) {}
};

using namespace std;

class Solution149 {
public:
    int maxPoints(vector<Point>& points) {
        int maxCount = 0;
        if(points.size() == 0) return 0;
        if(points.size() == 1) return 1;
        for(int i = 0; i<points.size(); i++){
            int identical = 1;
            for(int j = i+1; j<points.size(); j++){
                int n = 0;
                Point p1 = points[i];
                Point p2 = points[j];
                if(p1.x == p2.x && p1.y==p2.y) identical ++;
                int a = p2.y - p1.y;
                int b = p1.x - p2.x;
                int c = - p1.x*(p2.y - p1.y) + p1.y*(p2.x - p1.x);
                if(a==0 && b==0 && c==0) continue;
                for(int k = 0;k<points.size();k++){
                    Point p3 = points[k];
                    if(a*p3.x + b*p3.y + c == 0)
                        n++;
                }
                if(n>maxCount)
                    maxCount = n;
            }
            if(identical > maxCount)
                maxCount = identical;
        }
        return maxCount;
    }
    
};

class Test149 {
    
private:
    Solution149 solution;
    
    void testWithCase( vector<Point>& points,  int answer){
        int result = solution.maxPoints(points);
        if(result == answer){
            cout << "Passed\n";
        }else{
            cout << "Failed\n";
//            cout << "Input: " << word<<'\n';
            cout << "Your answer: \n";
            cout << result;
            cout << "\n";
            cout << "Correct answer: \n";
            cout << answer;
            cout << "\n";
        }
    }
    
public:
    void testCase1(){
        vector<Point> points = {Point(-1,-2),Point(0,0),Point(2,4),Point(1,1)};
        int answer = 3;
        cout << "TestCase 1: ";
        (testWithCase(points, answer));
    }
    
    void testCase2(){
        vector<Point> points = {Point(0,9),Point(138,429),Point(115,359),Point(115,359),Point(-30,-102),Point(230,709),Point(-150,-686),Point(-135,-613),Point(-60,-248),Point(-161,-481),Point(207,639),Point(23,79),Point(-230,-691),Point(-115,-341),Point(92,289),Point(60,336),Point(-105,-467),Point(135,701),Point(-90,-394),Point(-184,-551),Point(150,774)};
        int answer = 12;
        cout << "TestCase 2: ";
        (testWithCase(points, answer));
    }
//
//    void testCase3(){
//        string s = "abc";
//        bool answer = false;
//        cout << "TestCase 3: ";
//        (testWithCase(s, answer));
//    }
//    
//    void testCase4(){
//        string s = "1 a";
//        bool answer = false;
//        cout << "TestCase 4: ";
//        (testWithCase(s, answer));
//    }
//    
//    void testCase5(){
//        string s = "2e10";
//        bool answer = true;
//        cout << "TestCase 5: ";
//        (testWithCase(s, answer));
//    }
//    
//    void testCase6(){
//        string s = ".1";
//        bool answer = true;
//        cout << "TestCase 6: ";
//        (testWithCase(s, answer));
//    }
//    void testCase7(){
//        string s = ".";
//        bool answer = false;
//        cout << "TestCase 7: ";
//        (testWithCase(s, answer));
//    }
//    void testCase8(){
//        string s = ".e";
//        bool answer = false;
//        cout << "TestCase 8: ";
//        (testWithCase(s, answer));
//    }
//    void testCase9(){
//        string s = ".e1";
//        bool answer = false;
//        cout << "TestCase 9: ";
//        (testWithCase(s, answer));
//    }
//    void testCase10(){
//        string s = "3.";
//        bool answer = true;
//        cout << "TestCase 10: ";
//        (testWithCase(s, answer));
//    }
//    void testCase11(){
//        string s = " 005047e+6";
//        bool answer = true;
//        cout << "TestCase 11: ";
//        (testWithCase(s, answer));
//    }
    
};


#endif /* max_points_on_a_line_hpp */
