//
//  Header.h
//  DataStructure
//
//  Created by Ruoan on 2018/7/28.
//  Copyright © 2018年 Ruoan. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include<vector>
#include<iostream>
typedef int ElementType;
using namespace std;

vector<int> InputData();
void PrintData(vector<int> a);
void swap(int &a,int &b);

void BubbleSort(vector<int> a,int n);
void InsertionSort(vector<int> a,int n);
void ShellSort(vector<int> a,int n);
void SelectSort(vector<int> a,int n);

void HeapSort1(vector<int> a,int n);
void PercDown(vector<int> &a,int p,int n);

void MergeSort(vector<int> a,int n);
void MSort(vector<int> &a,ElementType *temp,int L,int RightEnd);
void Merge(vector<int> &a,ElementType *temp,int L,int R,int RightEnd);

void QuickSort(vector<int> a,int n);
void Quick_Sort(vector<int> &a,int l,int r);
int partiton(vector<int> &a,int l,int r);

void QuickSortWithMid(vector<int> a,int n);
void Quick_SortWithMid(vector<int> &a,int l,int r);
int partitonWithMid(vector<int> &a,int l,int r);
int Median3(vector<int> &a,int l,int r);
#endif /* Header_h */
