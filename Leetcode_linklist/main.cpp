#include "LinkList.h"
#include "MyLinkedList.cpp"
#include "deleteDuplicates.cpp"
class solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head==nullptr)
            return res;
        ListNode* pNode=head;
        stack<ListNode*> ListStack;
        while(pNode){
            ListStack.push(pNode);
            pNode=pNode->next;
        }
        while(!ListStack.empty()){
            pNode=ListStack.top();
            res.push_back(pNode->val);
            ListStack.pop();
        }
        return res;
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)
            return head;
        while(head && head->val==val){
            head=head->next;
        }//现在head指向链表中第一个值不是val的节点
        ListNode* pNode=head;
//        while(pNode && pNode->next){
//            while(pNode->next && pNode->next->val!=val)
//                pNode=pNode->next;
//            if(pNode->next==nullptr)
//                break;
//            else{
//                if(pNode->next->next)
//                    pNode->next=pNode->next->next;
//                else
//                    pNode->next=nullptr;
//            }
//        }
        while(pNode && pNode->next){
            if(pNode->next->val==val)
                pNode->next=pNode->next->next;
            else
                pNode=pNode->next;
        }
        return head;
    }
    
    void DeleteNode(ListNode **pHead,ListNode **pToDeleted){
        if(*pHead==nullptr || *pToDeleted==nullptr)
            return;
        if((*pHead)->next==nullptr){//链表只有一个节点的情况
            (*pHead)=nullptr;
            return;
        }
        if((*pToDeleted)->next){//要删除的节点不是尾节点
            ListNode *pNext=(*pToDeleted)->next;
            (*pToDeleted)->val=pNext->val;
            (*pToDeleted)->next=pNext->next;
            delete pNext;
            *pToDeleted=nullptr;
        }
        else{
            ListNode *pNode=(*pHead);
            while(pNode->next!=(*pToDeleted))
                pNode=pNode->next;
            delete pToDeleted;
            pNode->next=nullptr;
        }
    }
    
    ListNode* findANodeToDelete(ListNode *pHead){
        //模拟返回链表中要删除的节点
        return pHead;//第一个节点
        //return pHead->next;//第二个节点
        //return pHead->next->next->next->next;//五个节点长的链表的最后一个节点
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pNode=head;
        ListNode* pDelete=nullptr;
        while(pNode && pNode->next){
            if(pNode->val==pNode->next->val){
                pDelete=pNode->next;
                pNode->next=pDelete->next;
                delete pDelete;
                pDelete=nullptr;
            }
            else
                pNode=pNode->next;
        }
        return head;
    }
    
    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        if(head==nullptr)
            return head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        auto p = dummy;
        for (int i = 1; i < m; i++)
            p = p->next;
        auto pre = p;
        p = p->next;
        for (int i = m; i < n; i++) {
            auto q = p->next;
            p->next = q->next;
            q->next = pre->next;
            pre->next = q;
        }
        return dummy->next;
    }
//    ListNode* reverseBetween(ListNode* head, int m, int n) {
//        if(head==nullptr || m>n)
//            return head;
//        ListNode* pHead=head;
//        ListNode* pRever=head;
//        int M=m;
//        if(m==1)
//            pRever=nullptr;
//        while(m>2){
//            pRever=pRever->next;
//            m--;
//        }
//        ListNode* pPre=nullptr;
//        ListNode* pNext=nullptr;
//        ListNode* pLast=nullptr;
//        m=M;
//        while(m>1){
//            pHead=pHead->next;
//            m--;
//        }
//        ListNode* pEnd=pHead;
//        while(n-M){
//            pEnd=pEnd->next;
//            n--;
//        }//现在pHead和pEnd分别指向要翻转的链表的首尾
//        pLast=pEnd->next;
//        pPre=pLast;
//        while(pHead!=pLast){
//            pNext=pHead->next;
//            pHead->next=pPre;
//            pPre=pHead;
//            if(pNext==pLast){
//                break;
//            }
//            pHead=pNext;
//        }
//        if(pRever==nullptr)
//            head=pHead;
//        else
//            pRever->next=pHead;
//        return head;
//    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr)
            return true;
        ListNode* pNode=head;
        vector<int> num;
        while(pNode){
            num.push_back(pNode->val);
            pNode=pNode->next;
        }
        size_t left=0;
        size_t right=num.size()-1;
        while(left<=right){
            if(num[left]==num[right]){
                left++;
                right--;
            }
            else
                break;
        }
        if(left>right)
            return true;
        else
            return false;
    }
};
int main(){
    //创建实验所需的链表
    ListNode *pHead=nullptr;
    cout<<"Create a LinkList:"<<endl;
    CreateList(&pHead);
//    PrintList(pHead);
//    Solution S;
    
//    //题目1:从尾到头打印链表
//    vector<int> res;
//    res=S.printListFromTailToHead(pHead);
//    cout<<"从尾到头打印链表:";
//    for(unsigned int i=0;i<res.size();i++)
//        cout<<res[i]<<" ";
//    cout<<endl;
    
    //题目2:删除链表中指定val的节点
//    PrintList(S.removeElements(pHead,6));
    
    //题目3:删除链表中的指定节点
//    ListNode *pToDeleted=S.findANodeToDelete(pHead);
//    S.DeleteNode(&pHead,&pToDeleted);
//    PrintList(pHead);
    
    //题目4:删除排序链表中重复的节点(1->2->3->3->4->4->5  变为 1->2->3->4->5)
//    S.deleteDuplicates(pHead);
//    PrintList(pHead);
    
    //题目5:链表的中间结点
//    PrintList(S.middleNode(pHead));
    
    //题目6:反转链表II
//    PrintList(S.reverseBetween(pHead,2,4));
    
    //题目7:回文链表
//    cout<<S.isPalindrome(pHead);
    
    //题目8:设计链表
//    MyLinkedList linkedList;
//    cout<<linkedList.get(0)<<endl;
//    linkedList.addAtIndex(1,2);
//    cout<<linkedList.get(0)<<endl;
//    cout<<linkedList.get(1)<<endl;
//    linkedList.addAtIndex(0,1);
//    cout<<linkedList.get(0)<<endl;
//    cout<<linkedList.get(1)<<endl;
    
    //题目9:删除排序链表中重复的元素
    Solution S;
    PrintList(S.deleteDuplicates(pHead));
    return 0;
}
