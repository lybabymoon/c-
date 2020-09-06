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
	//ǰ��ݹ�
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
	//���� �ȴ�ӡ���ڵ� ���Һ��ӽ��Һ�����ջ �����ӷ������ӣ�û�����ӷ���ջ����ջ��û��Ԫ�����˳�
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
	
	//����ݹ�
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

	//�����������  �Ƚ�����������ջ��Ȼ���ӡջ��Ԫ�أ����ʵ�ǰԪ�ص��Һ���
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
	//����ݹ�
	vector<int> postOrder(TreeNode* root)
	{
		if (root == nullptr) return postNums;
		postOrder(root->left);
		postOrder(root->right);
		postNums.push_back(root->val);

		return postNums;
	}

	//������� �Ƚ�������ջ����ձ�ǣ�ֱ��������Ϊ�գ�Ȼ�����ջ������λ��ǣ�����������������������������ظ�������������������ձ�ǣ����
	//������������ ��ӡջ����Ȼ�������ĸ��ڵ��Ƿ���λ �����λ��һ����ӡ��ֱ���ҵ���һ�����λ�յĽڵ�Ȼ�����������
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		stack<bool> flag;
		stack<TreeNode*> st;
		TreeNode* cur = root;

		while (cur || !st.empty())
		{
			//1.��������ջ����ձ�ǣ�ֱ��������Ϊ�գ�
			for (;cur;cur = cur->left)
			{
				st.push(cur);
				flag.push(false);
			}
			
			//3.��ӡջ����Ȼ�������ĸ��ڵ��Ƿ���λ �����λ��һ����ӡ��ֱ���ҵ���һ�����λ�յĽڵ�Ȼ�����������
			while (!st.empty() && flag.top())
			{
				cur = st.top();
				ans.push_back(cur->val);
				st.pop();
				flag.pop();
				cur = nullptr;
			}

			//2.����ջ�� ��λ������������
			if (!st.empty())
			{
				flag.top() = true;
				cur = st.top();
				cur = cur->right;
			}
		}

		return ans;
	}

	//��������������������С�ڸ��׽ڵ� �Һ��Ӵ��ڸ��׽ڵ�
	//�����������������������
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

	//����������������ڵ�
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root || (!p && !q)) return nullptr;

		return root;
	}

	//897����˳�������
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
