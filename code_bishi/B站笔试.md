### B站笔试题
![b1b9563400ebbfe4498a8b71fa14e079.jpeg](https://github.com/ruoan777/hello-world/blob/master/upload-graph/B1.jpeg)
![af2bf3387ee30c606dcaf6cd17b6cfdb.jpeg](https://github.com/ruoan777/hello-world/blob/master/upload-graph/B2.jpeg)
<img src="https://github.com/ruoan777/hello-world/blob/master/upload-graph/B1.jpeg" width = "200" height = "200" alt="demo2" />

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
