## typedef的转换
>C++中的typedef好处很多，可以让标准化自己DIY的类型。  
为便于理解typedef能干啥，本题考察各种typedef后，某个自定义类型的最终形态是啥。  
输入为两部分，共两行：  
第一行是一堆typedef定义，标准C++语句，以分号结束，这里不用考虑struct/union这类，只需要考虑基本类型和指针。  
第二行是指定某个自定义type  
输出为该自定义type的最终形态  
如输入：
```cpp
typedef int INT; typedef INT** INTP;
INTP
```
则输出：
```cpp
int * *
```

注意，如果有指针类型，则指针表达的`*`和前面的类型中间间隔一个空格，和编译器的输出保持一致；另外，如果第一行输入的语句是编译不过的，或者第二行选择的type在第一行中没有定义，则输出`none`

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int main(){
    int flag=0;
    vector<string> s;
    string temp,res;
    map<string,string> hashtable;
    map<string,string>::iterator it;
    while(1){
        cin>>temp;
        s.push_back(temp);
        if(getchar() == '\n')
            break;
    }
    cin>>res;
    //输入处理完成
    /***********************************************/
    for(auto i=s.begin();i!=s.end();i++){
        if((*i).back() == ';')
            (*i).erase((*i).end()-1);//处理输入的";"
    }
    /***********************************************/
    string constant="typedef";
    for(int i=0;i<s.size();i++){
        if(s[i]==constant){//如果当前的s[i]为typedef
            string Now=s[i+1];
            if(Now.back() == '*'){
                for(auto j=0;j<Now.size();j++){
                    if(Now[j] == '*'){
                        string NowTheLeft=Now.substr(0,j);
                        string NowTheRight=Now.substr(j);
                        if((it=hashtable.find(NowTheLeft))!=hashtable.end()){
                            s[i+1]=it->second+NowTheRight;
                        }
                        else if(isupper(Now[0]))
                            flag=1;
                        else
                            break;
                    }
                }
            }
            else if((it=hashtable.find(Now))!=hashtable.end())
                s[i+1]=it->second;
            else if(isupper(Now[0]))
                flag=1;
            else
                continue;
            hashtable[s[i+2]]=s[i+1];
            i=i+2;
        }
    }
    string output=hashtable[res];
    for(int i=0;i<output.size();i++)
        if(output[i]=='*'){
            output=output.substr(0,i)+' '+output.substr(i);
            break;
        }
    if(flag==1)
        cout<<"none";
    else
        cout<<output<<endl;
    return 0;
}

//typedef int INT; typedef INT** CHAR; typedef CHAR INTP;    正确
//typedef int INT; typedef char CHAR; typedef CHAR** CHARP;  正确
//typedef int INT; typedef char* CHAR; typedef CHAR* CHARR;  正确
//typedef int INT; typedef CHAR CHARP; typedef CHAR* CHARRR;  none
//typedef int INT; typedef CHAR CHARP; typedef char CHAR;  none



```
