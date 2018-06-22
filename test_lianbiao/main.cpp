//
//  main.cpp
//  test_lianbiao
//
//  Created by Ruoan on 2018/6/22.
//  Copyright © 2018年 Ruoan. All rights reserved.
//

#include "SgLInkList.hpp"

int main(void)
{
    int flag=0;
    int position = 0, value = 0;
    pNODE head =nullptr;
    head=CreateList(head);
    printf("打印链表：");
    TraverseSgLinkList(head);
    IsEmptySgLinkList(head);
    cout<<"请输入要插入的元素的值";
    cin>>value;
    AddToTail(&head,value);
    cout<<"打印插入元素"<<value<<"后的链表";
    TraverseSgLinkList(head);
    cout<<"输入要删除的节点的值";
    cin>>value;
    RemoveNode(&head,value);
    TraverseSgLinkList(head);
    /*printf("请输入要插入节点的位置和元素值(两个数用空格隔开)：");
    scanf("%d %d", &position, &value);
    flag = InsertEleSgLinkList(head, position, value);
    if (flag)
    {
        printf("插入节点成功！\n");
        TraverseSgLinkList(head);
    }
    else
        printf("插入节点失败！\n");
    
    IsEmptySgLinkList(head);
    if (flag)
        printf("单向链表为空，不能进行删除操作！\n");
    else
    {
        printf("请输入要删除节点的位置：");
        scanf("%d", &position);
        flag = DeleteEleSgLinkList(head, position);
        if (flag)
        {
            printf("删除节点成功！\n");
            TraverseSgLinkList(head);
        }
        else
            printf("删除节点失败！\n");
    }
    */
    FreeMemory(&head);
    if (NULL == head)
        printf("已成功删除单向链表，释放内存完成！\n");
    else
        printf("删除单向链表失败，释放内存未完成！\n");
    
    return 0;
}
