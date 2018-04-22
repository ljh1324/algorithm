// https://www.acmicpc.net/problem/1991
// «ÿ∞·≈©

#include <stdio.h>


struct Node
{
	int left, right;
};

Node tree[26];

void preorder(int root)
{
	printf("%c", root + 'A');
	if (tree[root].left != -1)
		preorder(tree[root].left);
	if (tree[root].right != -1)
		preorder(tree[root].right);
}

void inorder(int root)
{
	if (tree[root].left != -1)
		inorder(tree[root].left);
	printf("%c", root + 'A');
	if (tree[root].right != -1)
		inorder(tree[root].right);
}

void postorder(int root)
{
	if (tree[root].left != -1)
		postorder(tree[root].left);
	if (tree[root].right != -1)
		postorder(tree[root].right);
	printf("%c", root + 'A');
}

int main()
{
	int n;
	char parent, left, right;
	char temp;
	

	scanf("%d", &n);
	scanf("%c", &temp);
	for (int i = 0; i < n; ++i)
	{
		scanf("%c %c %c", &parent, &left, &right);
		scanf("%c", &temp);

		parent -= 'A';
		tree[parent].left = tree[parent].right = -1;

		if (left != '.')
		{
			left -= 'A';
			tree[parent].left = left;
		}
		
		if (right != '.')
		{
			right -= 'A';
			tree[parent].right = right;
		}
	}

	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");

	return 0;
}