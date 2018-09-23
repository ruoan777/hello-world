//
//  LinkList.h
//  leetcode
//
//  Created by Ruoan on 2018/9/17.
//  Copyright © 2018年 Ruoan. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//创建单向链表
void CreateList(ListNode **pHead);

//单向链表的插入
void InsertNode(ListNode** pHead,int value);

//打印单向链表
void PrintList(ListNode *pHead);

//判断单向链表是否为空
void IsEmpty(ListNode *pHead);

//计算单向链表的长度
int GetLength(ListNode *pHead);

//从单向链表删除节点
//int DeleteNode(ListNode *pHead, int pos);

//删除整个链表，释放内存
void FreeMemory(ListNode *pHead);

#endif /* LinkList_h */
