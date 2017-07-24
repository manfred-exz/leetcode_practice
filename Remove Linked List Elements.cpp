//
// Created by manfred on 7/16/17.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode *removeElements(ListNode *head, int val) {
        while(head && head->val == val)
            head = head->next;

        if(head == nullptr)
            return nullptr;

        ListNode* prev = head;
        for(ListNode* curr = head->next; curr != nullptr; curr=curr->next){
            if(curr->val == val){
                prev->next = curr->next;
                // prev = prev
            } else{
                prev = curr;
            }
        }

        return head;
    }
};