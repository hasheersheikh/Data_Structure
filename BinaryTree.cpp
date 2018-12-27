#include<bits/stdc++.h>
using namespace std;

#define max 999

struct node{
        int value;
        struct node *left;
        struct node *right;
};
typedef struct node n;
typedef n* tree;

tree node(void){
        tree n;
        n->left=NULL;
        n->right=NULL;
        return n;
}


int getleft(int len,int idx){
        if(2*idx+1 > len)
                return len;
        return (2*idx+1);
}

int getright(int len,int idx){
        if(2*idx+2>len){
                return len;
        }
        return 2*idx+2;
}


tree createTree(vector<int> &vect, int len,int idx){
        tree root = NULL;
        if(idx<len){
                root = (tree)malloc(sizeof(tree));
                root->value = vect[idx];
                root->left = createTree(vect,len,getleft(len,idx));
                root->right = createTree(vect,len,getright(len,idx));
        }
        return root;
}
int height(tree root){
        int i=0;
        tree r=root;
        while(r->left != NULL){
                i++;
                r= r->left;
                }
        return i;
}               
void inorder(tree root){
        if(root!= NULL){
                cout<<root->value<<endl;
                inorder(root->left);
                inorder(root->right);
        }
        return ;
}
int parentNode(tree root){
		if(root==NULL)
			return 0;
		if(root->left!=NULL || root->right!=NULL){
			return 1;
		}
	return parentNode(root->left)+
	parentNode(root->right);
}
int leafNode(tree root){
	if(root== NULL)        
   		 return 0;
	if(root->left == NULL && root->right==NULL)       
   		 return 1;             
  else 
    return leafNode(root->left)+ 
           leafNode(root->right);  				
}


int main(){     
        vector<int> vect;
        int n;
        cout<<"enter the node for tree (999 to exit)"<<endl;
        cin>>n;
        while(n!=999){
                vect.push_back(n);
                cin>>n;
        }

        tree root = createTree(vect,vect.size(),0);
        cout<<"inorder"<<endl;
        inorder(root);
        cout<<"height=="<<height(root)<<endl;
		cout<<"leaf=="<<leafNode(root)<<endl;
		cout<<"parent Node =="<<parentNode(root)<<endl;
		return 0;
        }


