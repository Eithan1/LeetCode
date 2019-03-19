/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    /*-----------方法一（超出内存）-------------
    ListNode* VectorToListNode(vector<int> input_vector) {
        ListNode* dummyRoot = new ListNode(0);
        ListNode* ptr = dummyRoot;
        for(int i = 0; i < input_vector.size(); ++i) {
            ptr->next = new ListNode(input_vector[i]);
            ptr = ptr->next;
        }
        ptr = dummyRoot->next;
        delete dummyRoot;
        return ptr;
    }

    ListNode* partition(ListNode* head, int x) {
        vector<int> left;
        vector<int> right;
        ListNode* scan = head;
        while(scan->next != NULL) {
            if(scan->val < x)
                left.push_back(scan->val);
            else
                right.push_back(scan->val);
        }
        left.insert(left.end(), right.begin(), right.end()); //两个vector合并
        ListNode* res = VectorToListNode(left);
        return res;
    }
     */

    //-------------方法二----------------//
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;;
        while (pre->next && pre->next->val < x) //找到第一个大于或等于x的前一个数
            pre = pre->next;
        cur = pre;
        while (cur->next) { //从cur开始向后搜索，遇到小于x的放到pre之前
            if (cur->next->val < x) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
