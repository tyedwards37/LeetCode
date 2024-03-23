/* Daily Question: 143. Reorder List
 * by Tyler Edwards | March 22nd, 2024 
 * Code Credit: YehudisK
 * You are given the head of a singly linked-list. The list can be represented as:
 * L0 → L1 → … → Ln - 1 → Ln
 * Reorder the list to be on the following form:
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * You may not modify the values in the list's nodes. Only nodes themselves may be changed. */

 class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // if the head, or any of the two after are NULL
        
        stack<ListNode*> my_stack; // create a stack of Nodes
        ListNode* ptr = head; // have a pointer that points to the head
        int size = 0; // intialize a starting size of 0 
        while (ptr != NULL) // checks if the head is NULL
        {
            my_stack.push(ptr); // puts Node in stack 
            size++; // update the size by 1
            ptr = ptr->next; // move the pointer to the next Node
        }
        
        ListNode* pptr = head; // create another ppinter that goes to the head 
        for (int j=0; j<size/2; j++) // loop for half the size of the list of Nodes
        {
            ListNode *element = my_stack.top(); // gets the top Node of the stack 
            my_stack.pop(); // pops the top Node of teh stack 
            element->next = pptr->next; // moves the element Node to the next node 
            pptr->next = element; // sets second pointer's next Node to the current element Node
            pptr = pptr->next->next; // sets the second pointer to the Node two after
        }

        pptr->next = NULL; // sets the second pointer to NULL
    }
};