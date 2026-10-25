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
class Solution {
public:
class comp{
    public :
    bool operator()(ListNode* a , ListNode* b)
    {
        return (a->val > b->val) ;
    }
};
ListNode* func(priority_queue<ListNode*,vector<ListNode*>,comp>&pq)
{
    if(pq.empty())return NULL;
    ListNode* node = pq.top() ;
    pq.pop() ;
    ListNode* root = new ListNode(node->val) ;
    node = node->next ;
    if(node) pq.push(node) ;
    root->next = func(pq) ;
    return root ;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp>pq ;
        for(auto node : lists)
        {
            if(node!=NULL)
            {
                pq.push(node) ;
            }
        }
        return func(pq) ;
    }
};