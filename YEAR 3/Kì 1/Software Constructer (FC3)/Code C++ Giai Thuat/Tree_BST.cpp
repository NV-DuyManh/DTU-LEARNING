#include<bits/stdc++.h>
using namespace std;
struct TNode{
	int data;
	TNode *left, *right;
	TNode(int x, TNode *ll=NULL, TNode *rr=NULL){
		data=x;left =ll; right =rr;
	}
};
class MyBST{
	private:
		TNode *root;
	public:
		MyBST() { root = NULL; }
		TNode *chenbst(TNode *&T, int x){
			if(T==NULL) T= new TNode(x);
			else{
				if(T->data==x){
					cout<<"\n\t Da co gia tri "<<x<<" trong cay!";
				}else if(x>T->data){
					T->right = chenbst(T->right, x);
				}else{
					T->left = chenbst(T->left,x);
				}
			}return T;
		}
		void nhap(){
			int x;
			while(1){
				cout<<"Nhap gia tri khac 0 de chen: ";
				cin >>x;
				if(x==0) break;
				else root=chenbst(root, x);
			}
		}
		void f2(TNode *T){
			if(T!=NULL){
				f2(T->left);
				cout<<" "<<T->data;
				f2(T->right);
			}
		}
		void duyettrungtu(){
			cout<<"\nDuyet trung tu cay: ";
			f2(root);
		}
		TNode *tx(TNode *T, int x){
			if(T==NULL) cout<<"Khong co x trong cay de xoa!";
			else{
				if(x<T->data)T->left = tx(T->left,x);
				else{
			    	if(x>T->data) T->right = tx(T->right,x);
				    else{
				    	if(T->left==NULL && T->right ==NULL){
						    TNode *q=T; T=NULL;delete q;
				    	}else{
					    	if(T->left!=NULL && T->right==NULL){
						    	TNode *q = T; T=T->left; delete q;
					    	}else{
					    		if(T->left==NULL && T->right!=NULL){
					    			TNode *q=T;T=T->right;delete q;
								}
								else{
					 	        	TNode *p = T->left;
						        	while(p->right!=NULL)p=p->right;
						    	    T->data=p->data;
						        	T->left=tx(T->left, p->data);
					        	}
							}	
				    	}
			    	}
		    	}
			}
			return T;
		}
		void xoa(int x){
			root = tx(root, x);
		}
};
int main(){
	MyBST T;
	T.nhap();
	T.duyettrungtu();
	T.xoa(5);
		T.duyettrungtu();
	cout<<" \nXong";
}
