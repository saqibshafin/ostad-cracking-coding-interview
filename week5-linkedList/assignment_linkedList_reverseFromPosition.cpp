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

// Another definition for singly-linked list.
class Node {
  public:
    int data;
    Node *next;

    Node(int d) { // Default Constructor
        data = d;
        next = NULL;
    }
};

class Solution {
  public:
    ListNode *reverseFromPosition(ListNode *head,    //
                                  int startPosition, //
                                  int endPosition    //
    ) {
        int count = 0;

        ListNode *next = nullptr;
        ListNode *current = head;
        ListNode *prev = nullptr;

        while (current != nullptr && count < 6) {
            // next = current->next;
            // current->next = prev;
            // prev = current;
            // current = next;
            count++;
            if (count == startPosition - 1) {
                prev = current;
            }
            if (count >= startPosition && count <= endPosition) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                continue;
            }
            current = current->next;
        }

        head = prev;

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
    solution.display(solution.reverseFromPosition(head, 2, 4));
}

/*

Assignment on Linked List

    Write a function that does the following task.
    Given the head of a singly linked list and two integers left and right
where left <= right, reverse the nodes of the list from position left to
position right, and return the reversed list.

    (You must create the linked list and pass the head to the function you
created.)

    Also, mention the Time and Space Complexity of your solution

    Constraints:
        The number of nodes in the list is n.
        1 <= n <= 500
        -500 <= Node.val <= 500
        1 <= left <= right <= n


    Example 1:
        Input: head = [1,2,3,4,5], left = 2, right = 4
        Output: [1,4,3,2,5]

    Example 2:
        Input: head = [5], left = 1, right = 1
        Output: [5]

    Example 3:
        Input: head = [7,8,9], left = 1, right = 3
        Output: [9,8,7]

*/