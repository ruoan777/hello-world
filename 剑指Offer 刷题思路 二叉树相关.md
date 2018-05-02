#题目：
===============
##面试题32 从上到下打印二叉树（从上到下，从左到右，不分行）
-------
例如对于这样的一棵树  

           1
         /   \
        2     3
      /  \   /  \
     4    5 6    7
需要输出序列:

	{1,2,3,4,5,6,7}

##思路：
（注意分析过程，为何要用队列来实现）  
先打印根结点1，为了接下来可以打印1的左右子节点2和3，我们应该取出  2和3，把它们放到一个容器中。现在容器中有了节点2和3。  
按照从左到右的顺序，我们先取出2，打印完2以后，把2的左右子节点4和5放入容器中。现在容器中有了节点3，4和5。  
接下来取出3，打印3以后，将3的子孩子6和7放入容器。现在容器中有了4，5，6，7。  
注意到3的放入顺序在6和7之前，又比6和7先行取出，故这是一个先进先出的顺序，不难发现我们应该使用队列来实现这一题。  

##代码：
	class Solution {
	public:    
	    vector<int> PrintFromTopToBottom(TreeNode* root){
	        vector<int> result;//用来返回
	        queue<TreeNode*> printtree;
	        if (root==nullptr)
	            return result;
	        printtree.push(pNode);
	        while(!printtree.empty())
	        {
	            TreeNode* pNode=printtree.front();
	            result.push_back(pNode->val);
	            printtree.pop();
	            if(pNode->left)
	                printtree.push(pNode->left);
	            if(pNode->right)
	                printtree.push(pNode->right);
	        }
	        return result;
	    }
	};

题目：（leetcode 102）
================
上题的拓展 分行从上到下打印二叉树（从上到下，从左到右，但要分行）  
例如对于这样的一棵树  

	    3
	   / \
	  9  20
	    /  \
	   15   7
需要输出序列:  

	[
	  [3],
	  [9,20],
	  [15,7]
	]
##思路：
与上面的类似，但是需要增加两个变量:  
一个变量tobePrinted表示当前层中还没有打印的节点数。  
另一个变量nextleve表示下一层中节点的数目。  
##代码：
	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
	class Solution {
	public:
	    vector<vector<int>> levelOrder(TreeNode* root) {
	        vector<vector<int>> result;
	        vector<int> v;
	        queue<TreeNode*> printTree;
	        if (root==nullptr)
	            return result;
	        int tobePrinted=1;
	        int nextlevel=0;
	        printTree.push(root);
	        while(!printTree.empty())
	        {
	            TreeNode* pNode=printTree.front();
	            v.push_back(pNode->val);
	            printTree.pop();
	            if(pNode->left)
	            {
	                nextlevel++;
	                printTree.push(pNode->left);
	            }
	            if(pNode->right)
	            {
	                nextlevel++;
	                printTree.push(pNode->right);
	            }
	            tobePrinted--;
	            if(tobePrinted==0)
	            {
	                result.push_back(v);
	                v.clear();
	                tobePrinted=nextlevel;
	                nextlevel=0;
	            }
	        }
	        return result;
	    }
	};

#题目：
请实现一个函数按照之字形打印二叉树。  
即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。  

	       1
	     /   \
	    2     3
	  /  \   /  \
	 4    5 6    7
需要输出序列:

	[
		[1],
		[3,2],
		[4,5,6,7]
	]
##思路：
用两个栈来实现，当我们在打印某一层的节点时，把下一层的子节点保存到相应的栈里面。
如果当前打印的是奇数层，则先保存左子节点再保存右子节点到第一个栈里面；
如果当前打印的是偶数层，则先保存右子节点再保存左子节点到第二个栈里面。

##代码：
	class Solution {
	public:
	    vector<vector<int>> Print(TreeNode* pRoot) {
	        vector<vector<int>> result;
	        vector<int> v;
	        stack<TreeNode*> printTree[2];
	        if(pRoot==nullptr)
	            return result;
	        int current=0;//巧妙之处！！！
	        int next=1;
	        printTree[current].push(pRoot);
	        while(!printTree[1].empty()||!printTree[0].empty())
	        {
	            TreeNode*pNode=printTree[current].top();
	            v.push_back(pNode->val);
	            printTree[current].pop();
	            if(current==0)
	            {
	                if(pNode->left)
	                    printTree[next].push(pNode->left);
	                if(pNode->right)
	                    printTree[next].push(pNode->right);
	            }
	            else
	            {
	                if(pNode->right)
	                    printTree[next].push(pNode->right);
	                if(pNode->left)
	                    printTree[next].push(pNode->left);
	            }
	            if(printTree[current].empty())
	            {
	                result.push_back(v);
	                v.clear();
	                current=1-current;
	                next=1-next;
	            }
	        }
	        return result;
	    }
	};

#题目：
##面试题33:二叉搜索树的后序遍历序列。
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出true，否则输出false。假设输入的数组的任意两个数字都互不相同。
例如，输入数组{5,7,6,9,11,10,8}，则返回true，因为它是如下图所示二叉搜索树的后序遍历的结果。
               8
             /   \
            6     10
          /  \   /  \
         5    7 9    11
         
##思路：
在后序遍历得到的序列中，最后一个元素是对应的树的根结点，则数组中前面的数字可以分成两部分:  
第一部分是左子树的节点，它们都比根结点的值要小。  
第二部分是右子树的节点，它们都比根节点的值要大。  
我们接下来用同样的方法判读左右子树是否为二叉搜索树，故这可以用递归来完成。  

##代码：
	class Solution {
	public:
	    bool VerifySquenceOfBST(vector<int> sequence) {
	        if(sequence.empty())
	            return false;
	        int length=sequence.size();
	        int root=sequence[length-1];//数组的最末尾元素为二叉搜索树的根节点
	        int i=0;
	        for(;i<length-1;i++)
	        {
	            if(sequence[i]>root)
	                break;
	        }
	        int j=i;
	        for(;j<length-1;j++)
	            if(sequence[j]<root)
	                return false;//右边的部分必须都比root大，如反例：[7,4,6,5]就不是一个二叉搜索树对应的数组
	        bool left=true;
	        vector<int> templeft(sequence[0],i);
	        if(!templeft.empty())//注意这个判断，不加的话算法会错误处理输入的空树（实际为true，但会算出false）
	            left=VerifySquenceOfBST(templeft);//判断左子树是不是二叉搜索树
	        bool right=true;
	        vector<int> tempright(sequence[i],length-i-1);
	        if(!tempright.empty())
	            right=VerifySquenceOfBST(tempright);//判断右子树是不是二叉搜索树
	        return left&&right;
	    }
	};

#题目：
##面试题34：二叉树中和为某一值的路径。
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。  
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
  
	       8
	     /   \
	    6     10
	  /  \   /  \
	 5    7 9    3
例如输入上面的树和整数21。  
需要输出路径:

	[
	[8,6,7],
	[8,10,3],
	]
##思路：
下面的代码很简洁，使用了递归的方法。用到了深度优先遍历的思路。  
当然也可以把result和path声明为全局变量，这样调用dfs函数的时候就不用输入这两个参数了。  
在纸上走一遍递归调用的流程，就可以知道算法是怎么工作的了。  
##代码：
	class Solution {
	public:
	    vector<vector<int>> pathSum(TreeNode* root, int sum) {
	        vector<vector<int>> result;
	        vector<int> path;
	        if(root)
	            dfs(root,sum,result,path);
	        return result;
	    }
	    void dfs(TreeNode* pNode, int sum,vector<vector<int>> &result,vector<int> &path)
	    {
	        path.push_back(pNode->val);
	        if(!pNode->left&&!pNode->right)
	            if(pNode->val==sum)
	                result.push_back(path);
	        if(pNode->left)
	            dfs(pNode->left,sum-pNode->val,result,path);
	        if(pNode->right)
	            dfs(pNode->right,sum-pNode->val,result,path);
	        path.pop_back();        
	    }
	};   
