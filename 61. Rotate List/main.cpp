#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL)
            return head;

        //求链表长度，并定位最后一个元素
        int len = 1;
        ListNode* tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
            len++;
        }
        ListNode* last = tmp;

        //定位倒数第k个元素(k>len则取余)
        if(k > len)
            k = k % len;

        if(k == len || k == 0 || len == 1)
            return head;

        ListNode* forward = head;
        ListNode* back = head;
        ListNode* pre_forward; //倒数第k+1个元素

        int j = k;
        while(j--) {
            back = back->next;
        }

        while(back->next != NULL) {
            forward = forward->next;
            back = back->next;
        }
        pre_forward = forward;
        forward = forward->next;

        //在倒数第k个位置(forward)处断链，移到前面
        ListNode* res;
        res = forward;
        last->next = head;
        pre_forward->next = NULL;

        return res;
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
        int k = stringToInteger(line);

        ListNode* ret = Solution().rotateRight(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
