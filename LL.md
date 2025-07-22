# Day 14
## Singly LL
```cpp
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = nullptr;
    }
    
    // Insert at head
    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    
    // Insert at tail
    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        
        if(head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    // Insert at position
    void insertAtPosition(int data, int pos) {
        if(pos == 1) {
            insertAtHead(data);
            return;
        }
        
        Node* temp = head;
        int cnt = 1;
        
        while(cnt < pos-1 && temp != nullptr) {
            temp = temp->next;
            cnt++;
        }
        
        if(temp == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }
        
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    // Delete node
    void deleteNode(int pos) {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if(pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        Node* curr = head;
        Node* prev = nullptr;
        int cnt = 1;
        
        while(cnt < pos && curr != nullptr) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        if(curr == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }
        
        prev->next = curr->next;
        delete curr;
    }
    
    // Print the linked list
    void printList() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Reverse the linked list (iterative)
    void reverseIterative() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
    }
    
    // Reverse the linked list (recursive)
    void reverseRecursive(Node* curr, Node* prev) {
        if(curr == nullptr) {
            head = prev;
            return;
        }
        
        Node* next = curr->next;
        curr->next = prev;
        reverseRecursive(next, curr);
    }
    
    void reverseRecursive() {
        reverseRecursive(head, nullptr);
    }
    
    // Find middle of linked list
    Node* findMiddle() {
        if(head == nullptr) return nullptr;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Detect cycle in linked list
    bool detectCycle() {
        if(head == nullptr) return false;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                return true;
            }
        }
        
        return false;
    }
    
    // Remove cycle from linked list (if present)
    void removeCycle() {
        if(head == nullptr) return;
        
        Node* slow = head;
        Node* fast = head;
        bool hasCycle = false;
        
        // Detect cycle
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                hasCycle = true;
                break;
            }
        }
        
        if(!hasCycle) return;
        
        // Find the start of the cycle
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Now fast is at the start of the cycle
        // Move to the last node
        while(fast->next != slow) {
            fast = fast->next;
        }
        
        // Break the cycle
        fast->next = nullptr;
    }
};

int main() {
    LinkedList ll;
    
    // Insert operations
    ll.insertAtHead(5);
    ll.insertAtHead(10);
    ll.insertAtTail(15);
    ll.insertAtPosition(20, 2);
    
    cout << "Original List: ";
    ll.printList(); // Output: 10 20 5 15
    
    // Delete operation
    ll.deleteNode(3);
    cout << "After deletion: ";
    ll.printList(); // Output: 10 20 15
    
    // Reverse operations
    ll.reverseIterative();
    cout << "After iterative reverse: ";
    ll.printList(); // Output: 15 20 10
    
    ll.reverseRecursive();
    cout << "After recursive reverse: ";
    ll.printList(); // Output: 10 20 15
    
    // Middle element
    Node* middle = ll.findMiddle();
    if(middle != nullptr) {
        cout << "Middle element: " << middle->data << endl; // Output: 20
    }
    
    return 0;
}
```
