#include <cstddef>
#include <iostream>
using namespace std;
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
    Node *prev_node, *next_node;
    Solution() {
        // Were we supposed to add a constructor??
        // Ans: Sorry to bother you made, but this is the constructor...
        prev_node = NULL;
        next_node = NULL;
    }
    Node *insert(Node *head, int data) {
        // Complete this method
        Node *current_node = new Node(data); // Look below links/notes
        // current_node->data = data;
        // current_node->next = NULL;

        if (prev_node == NULL) { // If ‘head’ is NULL, our current node (tmp) is
            // the first node of the linked list and this will be ‘head’ and
            // ‘tail’ both (as it is also the last element right now).
            prev_node = current_node;
            next_node = current_node;
        } else {
            cout << next_node->data << '-';
            next_node->next = current_node;
            cout << next_node->data << '-';
            next_node = next_node->next; // this line, actually, assigns the
            // data & *next parameters of current_node to those of next_node!!
            cout << next_node->data << '-';
        }
        cout << prev_node->next << ' ' << next_node->data << ' '
             << current_node->data << '+' << endl;
        return prev_node; // I really don't get why returning prev_node gives
        // the correct output!!!!
        // Ans: It's because you are returning the address of the first node in
        // the linked list, and from there, the whole of the linked list can be
        // traversed.
    }

    void display(Node *head) {
        Node *start = head;
        while (start) // start!=NULL
        {
            cout << start->data << " ";
            start = start->next;
        }
    }
};
int main() {
    Node *head = NULL;
    Solution mylist;
    // gets initialised to-
    //      prev_node = NULL;
    //      next_node = NULL;

    int T, data;
    cin >> T;
    while (T-- > 0) {
        cin >> data;
        head = mylist.insert(head, data);
    }
    mylist.display(head);
}

// Links/Notes
// https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/
// https://www.geeksforgeeks.org/linked-list-set-1-introduction/
// editorial - https://www.hackerrank.com/challenges/30-linked-list/editorial