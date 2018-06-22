//
//  SgLInkList.cpp
//  test_lianbiao
//
//  Created by Ruoan on 2018/6/22.
//  Copyright © 2018年 Ruoan. All rights reserved.
//

#include "SgLInkList.hpp"
//创建单链表
pNODE CreateList(pNODE head){
    int length;
    int value;
    printf("请输入要创建链表的长度：");
    scanf("%d", &length);
    for(int i=1;i<=length;i++){
        cout<<"请输入第"<<i<<"个节点的值：";
        cin>>value;
        AddToTail(&head,value);
    }
    return head;
}
//在链表末尾添加一个节点
void AddToTail(NODE** pHead,int value){
    NODE* pNew=new NODE();
    pNew->data=value;
    pNew->pNext=nullptr;
    if((*pHead)==nullptr)
        *pHead=pNew;
    else{
        NODE* pNode=*pHead;
        while(pNode->pNext!=nullptr){
            pNode=pNode->pNext;
        }
        pNode->pNext=pNew;
    }
}
//打印单链表
void TraverseSgLinkList(pNODE pHead)
{
    pNODE pt = pHead;
    while (pt != nullptr)
    {
        printf("%d ", pt->data);
        pt = pt->pNext;
    }
    putchar('\n');
}
//判断单链表是否为空
void IsEmptySgLinkList(pNODE pHead)
{
    int flag;
    if (pHead== NULL)
        flag=1;
    else
        flag=0;
    if (flag)
        printf("单向链表为空！\n");
    else
    {
        int length = GetLengthSgLinkList(pHead);
        printf("单向链表的长度为：%d\n", length);
        TraverseSgLinkList(pHead);
    }
}
//计算单向链表长度
int GetLengthSgLinkList(pNODE pHead)
{
    int length = 0;
    pNODE pt = pHead;
    
    while (pt != nullptr)
    {
        length++;
        pt = pt->pNext;
    }
    return length;
}
//向单向链表插入一个节点,位置从1开始，到链表长度加1结束。
int InsertEleSgLinkList(pNODE pHead, int pos, int data)
{
    pNODE pt = NULL, p_new = NULL;
    
    if (pos > 0 && pos < GetLengthSgLinkList(pHead) + 2)
    {
        p_new = (pNODE)malloc(sizeof(NODE));
        if (NULL == p_new)
        {
            printf("内存分配失败！\n");
            exit(EXIT_FAILURE);
        }
        p_new->data = data;
        
        while (1)
        {
            pos--;
            if (0 == pos)
                break;
            pHead  = pHead->pNext;
        }
        
        pt = pHead->pNext;
        pHead->pNext = p_new;
        p_new->pNext = pt;
        
        return 1;
    }
    else
        return 0;
}
//在链表中找到第一个含有某值的节点并删除该节点
void RemoveNode(NODE **phead,int value){
    if(phead==nullptr||*phead==nullptr){
        cout<<"链表为空，无法删除";
        return;
    }
    NODE *ptodelete=nullptr;
    if((*phead)->data==value){
        ptodelete=*phead;
        *phead=(*phead)->pNext;
    }
    else{
        NODE *pNode=*phead;
        while(pNode->pNext->data!=value&&pNode->pNext!=nullptr){
            pNode=pNode->pNext;
        }
        if(pNode->pNext->data==value&&pNode->pNext!=nullptr){
            ptodelete=pNode->pNext;
            pNode->pNext=ptodelete->pNext;
        }
    }
    if(ptodelete!=nullptr){
        delete ptodelete;
    }
}
//从单向链表中删除一个节点，位置从1开始，到链表长度结束。
int DeleteEleSgLinkList(pNODE pHead, int pos)
{
    pNODE pt = NULL;
    
    if (pos > 0 && pos < GetLengthSgLinkList(pHead) + 1)
    {
        while (1)
        {
            pos--;
            if (0 == pos)
                break;
            pHead = pHead->pNext;
        }
        
        pt = pHead->pNext->pNext;
        free(pHead->pNext);
        pHead->pNext = pt;
        
        return 1;
    }
    else
        return 0;
}
void FreeMemory(pNODE *ppHead)
{
    pNODE pt = NULL;
    while (*ppHead != NULL)
    {
        pt = (*ppHead)->pNext;
        free(*ppHead);
        *ppHead = pt;
    }
}  
//创建单链表
pNODE CreateSgLinkList(void)
{
    int i, length, data;
    pNODE p_new = NULL, pTail = NULL;
    //创建头节点，头结点是第0个节点，后面的节点从1开始计数
    pNODE pHead = (pNODE)malloc(sizeof(NODE));
    
    if (NULL == pHead)
    {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }
    
    pHead->data = 0;
    pHead->pNext = NULL;
    pTail = pHead;
    
    printf("请输入要创建链表的长度：");
    scanf("%d", &length);
    
    for (i=1; i<length+1; i++)
    {
        p_new = (pNODE)malloc(sizeof(NODE));
        if (NULL == p_new)
        {
            printf("内存分配失败！\n");
            exit(EXIT_FAILURE);
        }
        
        printf("请输入第%d个节点的值：", i);
        scanf("%d", &data);
        
        p_new->data = data;
        p_new->pNext = NULL;
        pTail->pNext = p_new;
        pTail = p_new;
    }
    return pHead;
}
