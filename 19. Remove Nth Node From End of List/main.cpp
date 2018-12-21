#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //单链表翻转
    ListNode* ReverseList(ListNode* phead) {
        ListNode* pCur = phead;    //当前节点
        ListNode* pPrev = NULL;    //当前节点的上一个节点
        ListNode* pNext = NULL;    //当前节点的下一个节点
        ListNode* pRevHead = NULL; //翻转后链表的头指针

        while(pCur != NULL) {
            pNext = pCur->next;    //将pNext指向当前节点的下一个节点
            if(pNext == NULL)      //判断当前节点pCur是不是最后一个节点
                pRevHead = pCur;

            pCur->next = pPrev;    //指针翻转
            pPrev = pCur;
            pCur = pNext;
        }

        return pRevHead;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n == 1)  //链表只有一个元素的情况
            return NULL;
        ListNode* RevHead = NULL;
        ListNode* Rev2Head = NULL;
        RevHead = ReverseList(head);  //翻转链表
        ListNode* delNode = RevHead;
        if(n == 1)                   //如果要删除的元素是第一个(不存在前一个节点)
            RevHead = RevHead->next;
        else {
            for(int i = 0; i < n - 2; ++i) {
                delNode = delNode->next; //指向要删除节点的前一个节点
            }
            delNode->next = delNode->next->next; //删除该节点
        }
        Rev2Head = ReverseList(RevHead); //再翻转链表

        return Rev2Head;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int n = stringToInteger(line);

        ListNode* ret = Solution().removeNthFromEnd(head, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
