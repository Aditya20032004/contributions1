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
