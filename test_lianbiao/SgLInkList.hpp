//
//  SgLInkList.hpp
//  test_lianbiao
//
//  Created by Ruoan on 2018/6/22.
//  Copyright © 2018年 Ruoan. All rights reserved.
//

#ifndef SgLInkList_hpp
#define SgLInkList_hpp
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *pNext;
}NODE, *pNODE;

pNODE CreateList(pNODE head);
//创建单向链表
pNODE CreateSgLinkList(void);
void RemoveNode(NODE **pHead,int value);

void AddToTail(NODE** pHead,int value);

//打印单向链表
void TraverseSgLinkList(pNODE pHead);

//判断单向链表是否为空
void IsEmptySgLinkList(pNODE pHead);

//计算单向链表的长度
int GetLengthSgLinkList(pNODE pHead);

//向单向链表插入节点
int InsertEleSgLinkList(pNODE pHead, int pos, int data);

//从单向链表删除节点
int DeleteEleSgLinkList(pNODE pHead, int pos);

//删除整个链表，释放内存
void FreeMemory(pNODE *ppHead);
#endif /* SgLInkList_hpp */
