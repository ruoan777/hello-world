### B站笔试题
![b1b9563400ebbfe4498a8b71fa14e079.jpeg](evernotecid://D3246D17-20EC-4D80-977C-C4EA836A7547/appyinxiangcom/13597806/ENResource/p1348)
![af2bf3387ee30c606dcaf6cd17b6cfdb.jpeg](evernotecid://D3246D17-20EC-4D80-977C-C4EA836A7547/appyinxiangcom/13597806/ENResource/p1349)

```cpp
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int minPathSum(vector<vector<int>>& grid) {
    auto m=grid.size();
    auto n=grid[0].size();
    vector<int> res(n,0);
    int i,j;
    res[0]=grid[0][0];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
            if(i==0 && j!=0)
                res[j]=res[j-1]+grid[i][j];
            else if(i!=0 && j==0)
                res[j]=res[j]+grid[i][j];
            else
                res[j]=grid[i][j]+min(res[j],res[j-1]);
        }
    return res[n-1];
}
int main(){
    string n;
    getline(cin,n);
    int N=stoi(n);
    int num;
    vector<vector<int>> migong;//(n,vector<int>(n,0));
    vector<int> temp;
    string str;
    char ch;
    for(int i=0;i<N;i++){
        getline(cin,str);
        stringstream ss(str);
        while(ss>>num){
            temp.push_back(num);
            ss>>ch;
        }
        migong.push_back(temp);
        temp.clear();
    }
    int res=minPathSum(migong);
    cout<<res<<endl;
    return 0;
}


/*
 3
 5,5,7
 6,7,8
 2,2,4
 3
 1,3,1
 1,5,1
 4,2,1
 */
```
