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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;

      //find length of list
        int n{};
        ListNode* curr = head;
        while(curr != nullptr){
            n++;
            curr = curr->next;
        }
      //modulo of k
        k = k%n;
        if(k == 0) return head;
      //track the last node for the rotated list
        ListNode* back = head;
        for(int i = 0; i<n-k-1; i++){
            back = back->next;
        }
      //preserve the front node

        ListNode* front = back->next;
      //make the back as last
        back->next = nullptr;
        ListNode* p = front;
        while(p->next != nullptr){
            p = p->next;
        }
      //to join the last element to the past head
        p->next = head;
        return front;
    }
};
