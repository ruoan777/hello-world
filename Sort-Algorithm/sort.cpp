//
//  sort.cpp
//  DataStructure
//
//  Created by Ruoan on 2018/7/28.
//  Copyright © 2018年 Ruoan. All rights reserved.
//

#include "Sort.h"

void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int Median3(vector<int> &a,int l,int r){
    int c=(l+r)/2;
    if(a[l]>a[c])
        swap(a[l],a[c]);
    if(a[l]>a[r])
        swap(a[l],a[r]);//l存最小的
    if(a[c]>a[r])
        swap(a[c],a[r]);//r存最大的
    return c;
}
int partitonWithMid(vector<int> &a,int l,int r){//重复元素没有办法处理[3 2 2 3]
    int center = Median3(a,l,r);
    swap(a[l],a[center]);
    int i=l;
    int j=r+1;
    int x=a[i];
    while(1){
        while(a[++i]<x){}
        while(a[--j]>x){}
        if(i<j)
            swap(a[i],a[j]);
        else
            break;
    }
    swap(a[j],a[l]);
    return j;
}
void Quick_SortWithMid(vector<int> &a,int l,int r){
    if(l<r){
        int p=partitonWithMid(a,l,r);
        Quick_SortWithMid(a,l,p-1);
        Quick_SortWithMid(a,p+1,r);
    }
}
void QuickSortWithMid(vector<int> a,int n){
    Quick_SortWithMid(a,0,n-1);
    cout<<"QuickSortWithMid:";
    PrintData(a);
}
int partiton(vector<int> &a,int l,int r){
    int i=l,j=r+1;
    int x=a[i];
    for(;;){
        while(a[++i]<x){}
        while(a[--j]>x){}
        if(i<j)
            swap(a[i],a[j]);
        else
            break;
    }
    swap(a[j],a[l]);
    return j;
}
void Quick_Sort(vector<int> &a,int l,int r){
    if(l<r){
        int p=partiton(a,l,r);
        Quick_Sort(a,l,p-1);
        Quick_Sort(a,p+1,r);
    }
}
void QuickSort(vector<int> a,int n){
    Quick_Sort(a,0,n-1);
    cout<<"QuickSort:";
    PrintData(a);
}
void Merge(vector<int> &a,ElementType *temp,int L,int R,int RightEnd){
    int LeftEnd=R-1;
    int index=L;
    int NumOfElement=RightEnd-L+1;
    while(L<=LeftEnd && R<=RightEnd){
        if(a[L]<a[R])
            temp[index++]=a[L++];
        else
            temp[index++]=a[R++];
    }
    while(L<=LeftEnd)
        temp[index++]=a[L++];
    while(R<=RightEnd)
        temp[index++]=a[R++];
    while(NumOfElement--){
        a[RightEnd]=temp[RightEnd];
        RightEnd--;
    }
}
void MSort(vector<int> &a,ElementType *temp,int L,int RightEnd){
    int center;
    if(L<RightEnd){
        center=(L+RightEnd)/2;
        MSort(a,temp,L,center);
        MSort(a,temp,center+1,RightEnd);
        Merge(a,temp,L,center+1,RightEnd);
    }
}
void MergeSort(vector<int> a,int n){
    ElementType *temp;
    temp=(ElementType *)malloc(n*sizeof(ElementType));
    if(temp!=NULL){
        MSort(a,temp,0,n-1);
        free(temp);
    }
    else
        cout<<"内存不足";
    cout<<"MergeSort:";
    PrintData(a);
}
void PercDown(vector<int> &a,int p,int n){
    int parent,child;
    ElementType X;
    X=a[p];
    for(parent=p;(parent*2+1)<n;parent=child){
        child=parent*2+1;
        if((parent*2+1)<n-1 && a[child]<a[child+1])
            child++;//parent指向儿子中值最大的节点
        if(X>=a[child])
            break;
        else
            a[parent]=a[child];
    }
    a[parent]=X;
}
void HeapSort1(vector<int> a,int n){
    int i;
    for (i=n/2-1;i>=0;i--)/* 先建立一个最大堆 */
        PercDown(a,i,n);
    for (i=n-1;i>0;i--) {
        /* 删除最大堆顶 */
        swap(a[0],a[i]);
        PercDown(a,0,i);
    }
    cout<<"HeapSort1:";
    PrintData(a);
}
void SelectSort(vector<int> a,int n){
    int i,j,k;
    for(j=n-1;j>0;j--){
        k=j;
        for(i=0;i<j;i++){
            if(a[i]>a[k])
                k=i;
        }//k保存当前最大的数下标
        swap(a[k],a[j]);
    }
    cout<<"SelectSort:";
    PrintData(a);
}
void ShellSort(vector<int> a,int n){
    int i,P,D,temp;
    for(D=n/2;D>0;D/=2)
        for(P=D;P<n;P++){
            temp=a[P];
            for(i=P;i>=D && a[i-D]>temp;i-=D)
                swap(a[i],a[i-D]);
            //a[i]=temp;
        }
    cout<<"ShellSort:";
    PrintData(a);
}
void InsertionSort(vector<int> a,int n){
    int i,P,temp;
    for(P=1;P<n;P++){
        temp=a[P];
        for(i=P;i>0 && a[i-1]>temp;i--)
            swap(a[i],a[i-1]);
        //a[i]=temp;
    }
    cout<<"InsertionSort:";
    PrintData(a);
}
void insertSort(vector<int> a,int n){
    int i,P,temp;
    for(P=1;P<n;P++){
        temp=a[P];
        for(i=P;i>0;i--){
            if(a[i]<a[i-1])
                swap(a[i],a[i-1]);
        }
    }
}
void BubbleSort(vector<int> a,int n){
    int i,P,flag;
    for(P=n-1;P>0;P--){
        flag=0;
        for(i=0;i<P;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    cout<<"BubbleSort:";
    PrintData(a);
}
vector<int> InputData(){
    vector<int> a;
    int N=0;
    int Data;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Data;
        a.push_back(Data);
    }
    return a;
}
void PrintData(vector<int> a){
    if(a.empty())
        return;
    cout<<a[0];
    for(int i=1;i<a.size();i++)
        cout<<" "<<a[i];
    cout<<endl;
}
