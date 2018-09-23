//
//  MyLinkedList.cpp
//  leetcode707 设计链表
//
//  Created by Ruoan on 2018/9/20.
//  Copyright © 2018年 Ruoan. All rights reserved.
//
#include "LinkList.h"

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        LinkedList=nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *cur = LinkedList;
        while(cur && index--){
            cur=cur->next;
        }
        if(cur==nullptr)
            return -1;
        else
            return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *pNode = (ListNode *)malloc(sizeof(ListNode));
        pNode->next = LinkedList;
        pNode->val = val;
        LinkedList = pNode;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *cur = LinkedList;
        ListNode *pNode = (ListNode *)malloc(sizeof(ListNode));
        pNode->next = nullptr;
        pNode->val = val;
        if (cur==nullptr) {
            LinkedList = pNode;
            return;
        }
        while (cur->next) {
            cur=cur->next;
        }
        cur->next = pNode;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>len)
            return;
        ListNode *pNewHead = (ListNode *)malloc(sizeof(ListNode));
        pNewHead->next=LinkedList;
        ListNode *pCur=LinkedList;
        ListNode *pPre=pNewHead;
        while(index--){
            pPre=pPre->next;
            pCur=pCur->next;
        }
        ListNode *newNode=(ListNode *)malloc(sizeof(ListNode));
        newNode->val=val;
        newNode->next=pCur;
        if(LinkedList==nullptr)
            LinkedList=newNode;
        else
            pPre->next=newNode;
        delete pNewHead;
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=len)
            return;
        else if(len==1){
            LinkedList=nullptr;
            return;
        }//上面考虑了index不合法，以及链表只有一个节点这两种情况。接下来找节点即可
        ListNode *pNewHead = (ListNode *)malloc(sizeof(ListNode));
        pNewHead->next=LinkedList;
        ListNode *pPre=pNewHead;
        ListNode *pCur=LinkedList;
        while(index--){
            pPre=pPre->next;
            pCur=pCur->next;
        }
        pPre->next=pCur->next;
        delete pCur;
        delete pNewHead;
        len--;
    }
    
public:
    ListNode* LinkedList;
    int len=0;
};


