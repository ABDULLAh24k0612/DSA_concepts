#include<iostream>
using namespace std;
 
class node{

	public:

	node*right;
	node*left;
	int key;
	int height;

	node(int k){
		node*left=nullptr;
		node*right=nullptr;
		key=k;
		height=0;
    }
};
   
  int height(node*n){
      if(n==nullptr){
		return -1;
	  }
	  return n->height;
	}

  int getbalance(node*n){
      if(n==nullptr){
		return 0;
	  }
	  return height(n->left)-height(n->right);
  }

  node*rightrotate(node*y){

	node*x=y->left;
	node*t2=x->right;

	y->left=t2;
	x->right=y;

	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return x;
  }

  node*leftrotate(node*y){

	node*x=y->right;
	node*t2=x->left;

	y->right=t2;
	x->left=y;

	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return x;
  }

  node*insert(node*root,int key){
     if(root==nullptr){
		node*newnode=new node(key);
		return newnode;
	 }
	 if(key<root->key){
		root->left=insert(root->left,key);
	 }
	 if(key>root->key){
		root->right=insert(root->right,key);
	 }
	 return root;

	 root->height=max(height(root->left),height(root->right))+1;
	 int balance=getbalance(root);

	 if(balance>1 && key<root->left->key){
		return rightrotate(root);
	 }
	 if(balance<-1 && key>root->right->key){
		return leftrotate(root);
	 }
	 if(balance>1 && key>root->left->key){
		root->left=leftrotate(root->left);
		return rightrotate(root);
	 }
	 if(balance<-1 && key<root->right->key){
		root->right=rightrotate(root->right);
		return leftrotate(root);
	 }
	 return root;
  }
  node*findmin(node*root){
    node*temp=root;
	while( temp &&temp->left!=nullptr){
		temp=temp->left;
	}
	return temp;
  }
  node*deletenode(node*root,int key){
	if(root==nullptr){
		return;
	}
	if(key<root->key){
		root->left=deletenode(root->left,key);
	}
	else if(key>root->key){
		root->right=deletenode(root->right,key);
	}
	else{
		if(root->left==nullptr){
			node*temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==nullptr){
			node*temp=root->left;
			delete root;
			return temp;
		}
		node*temp=findmin(root->right);
		root->key=temp->key;
		root->right=deletenode(root->right,temp->key);
		}
	if(root==nullptr){
		return root;
	}
	root->height=max(height(root->left),height(root->right))+1;
	int balance=getbalance(root);

	if(balance>1 && getbalance(root)>=0){
		return rightrotate(root);
	}
	if(balance>1 && getbalance(root)<0){
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	if(balance<-1 && getbalance(root)<=0){
		return leftrotate(root);
	}
	if(balance<-1 && getbalance(root)>0){
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;

  }

  void inorderdisplay(node*root){
	if(root==nullptr){
		return;
	}
	inorderdisplay(root->left);
	cout<<root->key<<" ";
	inorderdisplay(root->right);

  }
int main()
{
    node *root = nullptr;

    int keys[] = {10, 20, 30, 40, 50, 25};

    for (int key : keys)
        root = insert(root, key);

    cout << "AVL Tree created with root key: " << root->key << endl;

    cout << "Inorder Traversal: ";
    inorderdisplay(root);
    cout << endl;

    return 0;
}

