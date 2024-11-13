/*Given an integer array nums, find the subarray with the largest sum, and return its sum.*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums){
    vector<int>::iterator it = max_element(nums.begin(), nums.end());
    vector<int>::iterator prev = max_element(nums.begin(), nums.end())-1;
    vector<int>::iterator next = max_element(nums.begin(), nums.end())+1;
    int max_num = *it;
    int sum=0;
    if(nums.size()==1){
        return nums[0];
    }
    for(it; it>=nums.begin(); it--){
        sum+=*it;
        if(sum>max_num){
            max_num=sum;
        }
    }
    sum=max_num;
    it = max_element(nums.begin(), nums.end());
    for(next; next<nums.end(); next++){
        sum+=*next;
        if(sum>max_num){
            max_num=sum;
        }
    }
    next = max_element(nums.begin(), nums.end())+1;
    return max_num;
}

int main(){
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4}; //6
    vector<int> nums2 = {1}; //1
    vector<int> nums3 = {5,4,-1,7,8}; //23
    vector<int> nums4 = {-2,1}; //1
    vector<int> nums5 = {3,-2,-3,-3,1,3,0}; //4
    vector<vector<int>> input;
    input.push_back(nums1);
    input.push_back(nums2);
    input.push_back(nums3);
    input.push_back(nums4);
    input.push_back(nums5);
    for(int i = 0; i<input.size(); i++){
        cout<<maxSubArray(input[i])<<endl;
    }
}