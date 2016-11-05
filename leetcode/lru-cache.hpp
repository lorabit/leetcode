//
//  max-points-on-a-line.hpp
//  leetcode
//
//  Created by lorabit on 10/26/16.
//  Copyright © 2016 From Network Technology. All rights reserved.
//
//  https://leetcode.com/problems/lru-cache/

#ifndef lru_cache_hpp
#define lru_cache_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <regex>

using namespace std;

struct CacheNode {
    int priority;
    int key;
    int value;
    CacheNode() : priority(0), key(0), value(0) {}
    CacheNode(int a, int b,int c) : priority(a), key(b), value(c) {}
};

class LRUCache {
private:
    CacheNode* cache;
    int capacity;
    int size;
    int priority;
    
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        cache = new CacheNode[capacity];
        size = 0;
        priority = 0;
    }
    
    int get(int key) {
        for (int i = 0; i<size; i++) {
            if(cache[i].key == key){
                cache[i].priority = priority++;
                return cache[i].value;
            }
        }
        return -1;
    }
    
    void set(int key, int value) {
        for (int i = 0; i<size; i++) {
            if(cache[i].key == key){
                cache[i].priority = priority++;
                cache[i].value = value;
                return;
            }
        }
        if(size == capacity){
            int minPriority = priority;
            int minPriorityIndex = 0;
            for(int i = 0; i<size;i++){
                if(cache[i].priority<minPriority){
                    minPriority = cache[i].priority;
                    minPriorityIndex = i;
                }
            }
            cache[minPriorityIndex] = CacheNode(priority++, key, value);
            return;
        }
        cache[size++] = CacheNode(priority++, key, value);
    }
    
};

class Test146 {
    
    
public:
    void fail(){
        cout << "Failed\n";
    }
    
    void testCase1(){
        LRUCache cache(2);
        if(cache.get(1)!=-1){
            fail();return;
        }
        cache.set(1, 2);
        if(cache.get(1)!=2){
            fail();return;
        }
        cache.set(2, 2);
        if(cache.get(2)!=2){
            fail();return;
        }
        cache.set(999, 3);
        if(cache.get(1)!=-1){
            fail();return;
        }
        if(cache.get(999)!=3){
            fail();return;
        }
        cout << "Passed.\n";
        
        
        
    }
    
//    void testCase2(){
//        vector<Point> points = {Point(0,9),Point(138,429),Point(115,359),Point(115,359),Point(-30,-102),Point(230,709),Point(-150,-686),Point(-135,-613),Point(-60,-248),Point(-161,-481),Point(207,639),Point(23,79),Point(-230,-691),Point(-115,-341),Point(92,289),Point(60,336),Point(-105,-467),Point(135,701),Point(-90,-394),Point(-184,-551),Point(150,774)};
//        int answer = 12;
//        cout << "TestCase 2: ";
//        (testWithCase(points, answer));
//    }
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


#endif /* lru_cache_hpp */
