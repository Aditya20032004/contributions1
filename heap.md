# Day 69
## Kth Largest Element in an Array
#### Given an integer array nums and an integer k, return the kth largest element in the array.Note that it is the kth largest element in the sorted order, not the kth distinct element.Can you solve it without sorting?
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for (int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if (pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }

};
```
# Day 70
## [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
#### You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.Merge all the linked-lists into one sorted linked-list and return it.
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class compare{
public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,compare> pq;

        for (auto list:lists){
            if (list!=NULL) pq.push(list);
        }    
        ListNode* res = new ListNode();
        ListNode* temp = res;

        while (!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();
            temp->next = smallest;
            temp = temp->next;

            if (smallest->next!=NULL){
                pq.push(smallest->next);
            }
        }
        return res->next;
    }
};

```

# Day 71
## [Task Scheduler](https://leetcode.com/problems/task-scheduler/description/)
#### You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.Return the minimum number of CPU intervals required to complete all tasks.
```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26,0);
        for (char c:tasks){
            mpp[c-'A']++;
        }        
        priority_queue<int> pq;
        for (int f:mpp){
            if (f>0) pq.push(f);
        }
        queue<pair<int,int>> q;
        int time = 0;
        while (!pq.empty() || !q.empty()){
            time++;
            if (!q.empty() && q.front().second<time){
                pq.push(q.front().first);
                q.pop();
            }
            if (!pq.empty()){
                int count = pq.top();
                pq.pop();
                count--;
                if (count>0){
                    q.push({count,time+n});
                }
            }   
        }
        return time;
    }
};
```

# Day 72
## [Hands of Straights](https://takeuforward.org/data-structure/hands-of-straights)
#### Problem Statement: You are given an array of integers hand, where hand[i] is the value on the i-th card that Alice owns. Alice wants to split her entire hand into groups such that: every group contains exactly groupSize cards, and the card values in each group form a sequence of groupSize consecutive integers (e.g. [3, 4, 5], [10, 11, 12, 13]).
#### when iterator is used first and scond mjember in a map are acessed using it->first and it->second.
```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // If total cards can't be divided evenly, return false
        if (hand.size() % groupSize != 0) return false;

        // Store the frequency of each card
        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        // Create an iterator pointing to the beginning of the frequency map
        auto it = freq.begin();

        // Loop through all keys in the map
        while (it != freq.end()) {

            // Skip cards that are already used up
            if (it->second == 0) {
                ++it;
                continue;
            }

            // Store the starting card of the group
            int start = it->first;

            // Number of times we need to form this group
            int count = it->second;

            // Try to form a group of consecutive cards of size groupSize
            for (int i = 0; i < groupSize; ++i) {

                // If the current required card is missing or doesn't have enough frequency
                if (freq[start + i] < count) return false;

                // Decrease the frequency for current card
                freq[start + i] -= count;
            }

            // Move the iterator to the next element
            ++it;
        }

        // All groups formed successfully
        return true;
    }
};
```

# Day 73
## [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)
#### You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.Implement the KthLargest class:KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
```cpp
class KthLargest {
    priority_queue<int,vector<int>, greater<int>> minheap;
    int s;
public:
    
    KthLargest(int k, vector<int>& nums) {
        s = k;
        for (int i=0;i<nums.size();i++){
            minheap.push(nums[i]);
            if (minheap.size()>k) minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if (minheap.size()>s) minheap.pop();
        return minheap.top();        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
# Day 73
## [K most frequent elements](https://leetcode.com/problems/top-k-frequent-elements/description/)
#### Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.[ 0(n) ]
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i:nums) mpp[i]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto& i:mpp){
            bucket[i.second].push_back(i.first);
        }        
        vector<int> res;
        for(int j=bucket.size()-1;j>=0;--j){
            for(int i:bucket[j]){
                res.push_back(i);
                if (res.size()==k) return res;
            }
        }
        return res;
    }
};
```
