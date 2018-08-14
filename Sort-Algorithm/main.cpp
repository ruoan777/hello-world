//
//  main.cpp
//  DataStructure
//
//  Created by Ruoan on 2018/7/28.
//  Copyright © 2018年 Ruoan. All rights reserved.
//
#include "Sort.h"
int main(){
    vector<int> a;
    a=InputData();
    int n=(int)a.size();
    /*以上为一些输入函数，第一行输入元素的个数，第二行输入相应的整数，
     记得在每个排序函数里面调用打印函数*/
    //BubbleSort(a,n);
    //InsertionSort(a,n);
    //ShellSort(a,n);
    //SelectSort(a,n);
    //HeapSort1(a,n);
    //MergeSort(a,n);
    //QuickSort(a,n);
    QuickSortWithMid(a,n);
    return 0;
}

