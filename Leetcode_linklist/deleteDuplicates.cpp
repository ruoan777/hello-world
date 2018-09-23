//
//  deleteDuplicates.cpp
//  leetcode
//
//  Created by Ruoan on 2018/9/22.
//  Copyright © 2018年 Ruoan. All rights reserved.
//
#include "LinkList.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* pHead){
        if(pHead==nullptr)
            return nullptr;
        ListNode *pPreNode=nullptr;
        ListNode *pNode=pHead;
        while(pNode!=nullptr){
            ListNode *pNext=pNode->next;
            bool needdelete=false;
            if(pNext!=nullptr && pNext->val==pNode->val)
                needdelete=true;
            if(needdelete==false){//不需要删除 则继续往后走
                pPreNode=pNode;
                pNode=pNode->next;
            }
            else{//需要删除 说明至少有两个元素重复
                int val=pNode->val;
                ListNode *ptoDelete=pNode;
                while(ptoDelete!=nullptr && ptoDelete->val==val){
                    pNext=ptoDelete->next;
                    delete ptoDelete;
                    ptoDelete=pNext;
                }
                if(pPreNode==nullptr)
                    pHead=pNext;
                else
                    pPreNode->next=pNext;
                pNode=pNext;
            }
        }
        return pHead;
    }
};
