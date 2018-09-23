//
//  LinkList.cpp
//  leetcode
//
//  Created by Ruoan on 2018/9/17.
//  Copyright © 2018年 Ruoan. All rights reserved.
//

#include "LinkList.h"

//创建单向链表
void CreateList(ListNode **pHead){
    int N,value;
    cout<<"输入要创建的链表的节点个数：";
    cin>>N;
    for(int i=0;i<N;i++){
        cout<<"输入第"<<i+1<<"个节点:";
        cin>>value;
        InsertNode(pHead,value);
    }
}
//void CreateList(ListNode **pHead){
//    cout<<"测试用例为5个节点，值为1->2->3->4->5："<<endl;
//    for(int i=1;i<=5;i++){
//        InsertNode(pHead,i);
//    }
//}

//单向链表的插入
void InsertNode(ListNode** pHead,int value){
    ListNode *pNew=new ListNode(0);
    pNew->val=value;
    pNew->next=nullptr;
    if(*pHead==nullptr){
        *pHead=pNew;
    }
    else{
        ListNode *pNode=*pHead;
        while(pNode->next){
            pNode=pNode->next;
        }
        pNode->next=pNew;
    }
}

//打印单向链表
void PrintList(ListNode *pHead){
    ListNode *pNode=pHead;
    if(pNode==nullptr)
        return;
    cout<<"链表打印结果为:";
    cout<<pNode->val;
    pNode=pNode->next;
    while(pNode){
        cout<<' '<<pNode->val;
        pNode=pNode->next;
    }
    cout<<endl;
}

//判断单向链表是否为空
void IsEmpty(ListNode *pHead);

//计算单向链表的长度
int GetLength(ListNode *pHead);

//从单向链表删除节点
//int DeleteNode(ListNode *pHead, int pos);

//删除整个链表，释放内存
void FreeMemory(ListNode *pHead){
    ListNode* pNode = pHead;
    while(pNode){
        pHead=pHead->next;
        delete pNode;
        pNode=pHead;
    }
}
