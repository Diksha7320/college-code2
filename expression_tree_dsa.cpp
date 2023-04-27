#include <iostream>
#include<string>
using namespace std;

struct node{
    char data;
    node *left;
    node *right;
};

class stack{
    public:
        node *arr[10];
        int top;
        stack(){
            top=-1;
        }
        bool isempty(){
            return (top==-1)?  true :  false;
        }
        void push(node *a){
            arr[++top]=a;
        }
        node *pop(){
            return arr[top--];
        }
        node *peak(){
            return arr[top];
        }
};

void preorder(node *t){
    if(t!=NULL){
        preorder(t->left);
        preorder(t->right);
        cout<<t->data;
    }
}
void inorder(node *t){
    if(t!=NULL){
        inorder(t->left);
        inorder(t->right);
        cout<<t->data;
    }
}
void postorder(node *t){
    if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        cout<<t->data;
    }
}

int main()
{
    string exp;
    cout<<"Enter Expression:";
    cin>>exp;
    stack s;
    int n=exp.size();
    for(int i=n-1;i>-1;i--){
        if (isalpha(exp[i])){
            node *t=new node;
            t->data=exp[i];
            t->left=NULL;
            t->right=NULL;
            s.push(t);
        }else{
            node *t1=s.pop();
            node *t2=s.pop();
            node *t=new node;
            t->data=exp[i];
            t->left=t1;
            t->right=t2;
            s.push(t);
        }
    }    
    node *t=s.pop();
    cout<<"\nPreorder:";
    preorder(t);
    cout<<"\nInorder:";
    inorder(t);
    cout<<"\nPostorder:";
    postorder(t);

    return 0;
}
