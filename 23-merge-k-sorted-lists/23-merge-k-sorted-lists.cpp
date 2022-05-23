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

class node{
    public:
    ListNode* curr = NULL;
    int value;
    node(ListNode* curr, int value)
    {
        this->curr = curr;
        this->value = value;
    }
};

class cmp{
    public:
    bool operator()(node &a, node &b)
    {
        return a.value >= b.value;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int k = lists.size();
        if(!k) return NULL;
        if(k == 1) return lists[0];
        priority_queue<node, vector<node>, cmp> pq;
        ListNode head;
        ListNode* tail = &head;
        for(int i = 0; i < k; i++)
        {
            if(lists[i] != NULL)
            {
                pq.push(node(lists[i], lists[i]->val));
            }
        }
        // node temp = pq.top();
        // pq.pop();
        // head = tail = new ListNode(temp.value);
        // if(temp.curr->next != NULL)
        // {
        //     pq.push(node(temp.curr->next, temp.curr->next->val));
        // }
        while(!pq.empty())
        {
            node temp = pq.top();
            pq.pop();
            tail->next = new ListNode(temp.value);
            tail = tail->next;
            if(temp.curr->next != NULL)
            {
                pq.push(node(temp.curr->next, temp.curr->next->val));
            }
        }
        return head.next;
    }
};