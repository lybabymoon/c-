#pragma once
#include <vector>
#include <stack>
#include <string>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val):val(_val),left(nullptr),right(nullptr)
	{}
};

class Tree
{
	vector<int> preNums;
	vector<int> inNums;
	vector<int> postNums;
public:
	Tree() {}
	~Tree() {}
	//前序递归
	std::vector<int> preOrder(TreeNode* root)
	{
		if (root)
		{
			preNums.push_back(root->val);
			preOrder(root->left);
			preOrder(root->right);
		}
		return preNums;
	}
	//迭代 先打印根节点 有右孩子将右孩子入栈 有左孩子访问左孩子，没有左孩子访问栈顶，栈内没有元素则退出
	vector<int> preOrderT(TreeNode* root)
	{
		vector<int> ans;
		if (root)
		{
			return ans;
		}
		stack<TreeNode*> st;
		st.push(nullptr);
		TreeNode* cur = root;

		while (cur)
		{
			ans.push_back(cur->val);

			if (cur->right)
			{
				st.push(cur->right);
			}

			if (cur->left)
			{
				cur = cur->left;
			}
			else
			{
				cur = st.top();
				st.pop();
			}

		}
		return ans;
	}
	
	//中序递归
	vector<int> inOrder(TreeNode* root)
	{
		if (root == nullptr)
		{
			return inNums;
		}
		inOrder(root->left);
		inNums.push_back(root->val);
		inOrder(root->right);
		return inNums;
	}

	//中序遍历迭代  先将所有左孩子入栈，然后打印栈顶元素，访问当前元素的右孩子
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		stack<TreeNode*> st;
		st.push(nullptr);
		TreeNode* cur = root;

		while (cur || !st.empty())
		{
			for (;cur->left;cur = cur->left)
			{
				st.push(cur->left);
			}

			cur = st.top();
			st.pop();
			ans.push_back(cur->val);
			cur = cur->right;
		}
	}
	//后序递归
	vector<int> postOrder(TreeNode* root)
	{
		if (root == nullptr) return postNums;
		postOrder(root->left);
		postOrder(root->right);
		postNums.push_back(root->val);

		return postNums;
	}

	//后序迭代 先将左孩子入栈，清空标记，直到左子树为空，然后访问栈顶，置位标记，访问它的右子树，如果有右子树重复访问他的左子树，清空标记，如果
	//右子树不存在 打印栈顶，然后检测它的父节点是否被置位 如果置位则一并打印，直到找到第一个标记位空的节点然后访问右子树
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		stack<bool> flag;
		stack<TreeNode*> st;
		TreeNode* cur = root;

		while (cur || !st.empty())
		{
			//1.将左孩子入栈，清空标记，直到左子树为空，
			for (;cur;cur = cur->left)
			{
				st.push(cur);
				flag.push(false);
			}
			
			//3.打印栈顶，然后检测它的父节点是否被置位 如果置位则一并打印，直到找到第一个标记位空的节点然后访问右子树
			while (!st.empty() && flag.top())
			{
				cur = st.top();
				ans.push_back(cur->val);
				st.pop();
				flag.pop();
				cur = nullptr;
			}

			//2.访问栈顶 置位，访问右子树
			if (!st.empty())
			{
				flag.top() = true;
				cur = st.top();
				cur = cur->right;
			}
		}

		return ans;
	}

	//二叉搜索树的性质左孩子小于父亲节点 右孩子大于父亲节点
	//二叉搜索数的最近公共祖先
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)
		{
			return nullptr;
		}

		while (root)
		{
			if (root->val > q->val && root->val > p->val)
			{
				root = root->left;
			}
			else if(root->val < q->val && root->val < p->val)
			{
				root->right;
			}
			else
			{
				return root;
			}
		}

	}

	//二叉树的最近公共节点
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root || (!p && !q)) return nullptr;

		return root;
	}

	//897递增顺序查找树
	TreeNode* increasingBST(TreeNode* root) {
		if (root == nullptr) return root;
		TreeNode* res = new TreeNode(0);
		TreeNode* pre = res;
		TreeNode* cur = root;
		stack<TreeNode*> st;
		while (cur || !st.empty())
		{
			for (;cur;cur = cur->left)
			{
				st.push(cur);
			}
			cur = st.top();
			if (cur)
			{
				pre->right = cur;
				pre = pre->right;
			}
				
			
			st.pop();
			cur = cur->right;
		}
		return res->right;
	}

	vector<string> ans;
	vector<string> binaryTreePaths(TreeNode* root)
	{
		if (root == nullptr) return {};
		dfs(root, "");
		return ans;
	}
	void dfs(TreeNode* root, string path)
	{
		if (root == nullptr)
		{
			return;
		}
		path += to_string(root->val);

		if (root->left == nullptr && root->right == nullptr)
		{
			ans.push_back(path);
			return;
		}

		dfs(root->left, path + "->");
		dfs(root->right, path + "->");
	}
};
