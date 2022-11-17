struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class NodeCompare {
    public:
        bool operator() (ListNode * & left, ListNode * & right){
            return left->val > right->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = new ListNode();
        priority_queue<ListNode*, vector<ListNode*>, NodeCompare> que;
        
        // construct
        for (auto t : lists) {
            if (t)  que.push(t);
        }

        // heap sort
        ListNode* node = result;
        while (!que.empty()) {
            ListNode* t = que.top();    // the min element
            que.pop();

            if (t->next) que.push(t->next);  // get next

            node->next = new ListNode();
            node = node->next;
            node->val = t->val;
        }

        return result->next;
    }
};