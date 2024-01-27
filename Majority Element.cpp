// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.





class Solution {
public:
    int majorityElement(vector<int>& a) {
       // Boyer-Moore Majority Vote Algorithm
       int major = a[0];
       int count = 0;
       for(int i=0; i<a.size(); i++){
           if(count == 0){
               count++;
               major = a[i];
           }
           else if(major == a[i]){
               count ++;
           }
           else if(major != a[i]){
               count --;
           }
        }
        return major;
    }
};
