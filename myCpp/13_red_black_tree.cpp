#if 0
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct rb_node
{
	rb_node* parent;
	rb_node* left;
	rb_node* right;
	int key;
	int color;//1(红),2(黑)
};

void rb_insert(rb_node*(&root),rb_node*(&p));
void rb_insert_fixup(rb_node*(&root),rb_node*(&p));
void left_rotate(rb_node*(&root),rb_node*(&p));
void right_rotate(rb_node*(&root),rb_node*(&p));

void main()
{
	//初始化数据集
	rb_node rb_tree[8];
	rb_node* root=NULL;
	streambuf* buf=cin.rdbuf();
	ifstream in("rb_tree_input.txt");
	cin.rdbuf(in.rdbuf());
	for(int i=0;i<8;i++)
	{
		int l,r,p,c;
		cin>>rb_tree[i].key>>p>>l>>r>>c;
		if(p>=0)
			rb_tree[i].parent=&rb_tree[p];
		else
			rb_tree[i].parent=NULL;
		if(l>=0)
			rb_tree[i].left=&rb_tree[l];
		else
			rb_tree[i].left=NULL;
		if(r>=0)
			rb_tree[i].right=&rb_tree[r];
		else
			rb_tree[i].right=NULL;
		rb_tree[i].color=c;
	}
	root=&rb_tree[0];
	//插入一个节点
	rb_node* pnode=new rb_node();
	pnode->key=4;
	rb_insert(root,pnode);

	system("pause");
}

void rb_insert(rb_node*(&root),rb_node*(&p))
{
	rb_node* it=root;
	while((it->left)||(it->right))
	{
		if(p->key<it->key)
			it=it->left;
		else
			it=it->right;
	}
	if(p->key<it->key)
	{
		it->left=p;
		p->parent=it;
		p->color=1;
		p->left=NULL;
		p->right=NULL;
	}else
	{
		it->right=p;
		p->parent=it;
		p->color=1;
		p->left=NULL;
		p->right=NULL;
	}
}
void rb_insert_fixup(rb_node*(&root),rb_node*(&p))
{
	rb_node* it=p;
	while(it->parent->color==1)
	{
		//case1:指定节点parent为左儿子
		if(it->parent->parent->left==it->parent)
		{
			//如果指定节点的右叔父也是红色
			if(it->parent->parent->right->color==1)
			{
				it->parent->color==2;
				it->parent->parent->right->color=2;
				it->parent->parent->color=1;
				it=it->parent->parent;
			}else if(it->parent->right==it)//如果指定节点右叔父不为红色,且指定节点为右儿子
			{
				it=it->parent;
				left_rotate(root,it);
			
				it->parent->color=2;
				it->parent->parent->color=1;
				right_rotate(root,it->parent->parent);
			}else
			{
				it=it->parent;
				right_rotate(root,it);

				it->parent->color=2;
				it->parent->parent->color=1;
				left_rotate(root,it->left->left);
			}
		}
		root->color=2;
	}
	
}
void left_rotate(rb_node*(&root),rb_node*(&p))
{
	if(p==root)
		root=p->right;
	rb_node* rightson=p->right;
	rightson->parent=p->parent;
	p->right=rightson->left;
	rightson->left=p;
	p->parent=rightson;
}
void right_rotate(rb_node*(&root),rb_node*(&p))
{
	if(p==root)
		root=p->left;
	rb_node* leftson=p->left;
	leftson->parent=p->parent;
	p->parent=leftson;
	p->left=leftson->right;
	leftson->right=p;
}
#endif