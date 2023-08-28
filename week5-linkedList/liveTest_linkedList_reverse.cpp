// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int data;
    ListNode *next;

    // Constructors:
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseLinkedList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *nextNode = nullptr;
        ListNode *currentNode = head;
        ListNode *prevNode = nullptr;

        while (currentNode != nullptr) {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }

        head = prevNode;

        return head;
    };

    void display(ListNode *head) {
        ListNode *start = head;
        cout << start->data << " " << start << endl;
        while (start) { // as long as start!=NULL
            cout << start->data << " " << start->next << endl;
            start = start->next;
        }
    }
};

int main() {
    ListNode *head = NULL;
    ListNode *node1 = new ListNode(); // new ListNode(1);
    ListNode *node2 = new ListNode(); // new ListNode(2);
    ListNode *node3 = new ListNode(); // new ListNode(3);
    ListNode *node4 = new ListNode(); // new ListNode(4);
    ListNode *node5 = new ListNode(); // new ListNode(5);

    head = node1; // initializing "head" with the address of "node1"
    node1->data = 1, node1->next = node2;
    node2->data = 2, node2->next = node3;
    node3->data = 3, node3->next = node4;
    node4->data = 4, node4->next = node5;
    node5->data = 5, node5->next = nullptr; // Terminating the Linked list.

    Solution solution = Solution();
    solution.display(head);
    solution.display(solution.reverseLinkedList(head));
}
