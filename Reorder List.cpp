// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:


// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
 

// Constraints:

// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000






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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return; // No need to reorder for lists with 0, 1, or 2 nodes.
        }

        // Find the middle of the list using the slow and fast pointer approach.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves.
        ListNode* firstHalf = head;
        ListNode* secondHalf = slow->next;
        slow->next = NULL; // Terminate the first half.

        // Reverse the second half.
        secondHalf = reverse(secondHalf);

        // Merge the two halves.
        while (firstHalf != NULL && secondHalf != NULL) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;
            firstHalf->next = secondHalf;
            if (temp1 == NULL) {
                break;
            }
            secondHalf->next = temp1;
            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};
