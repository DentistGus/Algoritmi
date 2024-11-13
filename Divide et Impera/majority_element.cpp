/*Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always 
exists in the array.*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums){
    int index = floor((nums.size()-1)/2);
    return nums[index];
}

int main(){
    vector<int> nums1 = {3,2,3};
    vector<int> nums2 = {2,2,1,1,1,2,2};
    vector<vector<int>> input;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    input.push_back(nums1);
    input.push_back(nums2);
    for(int i = 0; i<input.size(); i++){
        cout<<majorityElement(input[i])<<endl;
    }
}