#include<iostream>
#include<string>
using namespace std;

struct node {
    string key;
    string meaning;
    node *left=NULL;
    node *right=NULL;
}*root;

class Dictionary_Tree{
    public:
        Dictionary_Tree(){
            root=NULL;
        }
        node* add(node* r,node* temp){
            if(r==NULL){
                return temp;
            }
            if(r->key>temp->key){
                r->left=add(r->left,temp);
            }else{
                r->right=add(r->right,temp);
            }
            return r;
            
        }

        node* minval(node* root){
            while(root->left != NULL){
                root = root->left;
            }
            return root;
        }


        node* delete_key(node* r,string k){
            if(r==NULL) return NULL;
            if(r->key==k){
                if(!r->left && !r->right){
                    delete(r);
                    return NULL;
                }
                if(r->left && !r->right){
                    node* temp=r->left;
                    delete(r);
                    return temp;
                }
                if(!r->left && r->right){
                    node* temp=r->right;
                    delete(r);
                    return temp;
                }
                if(r->left && r->right){
                    node* rep=minval(r->right);
                    r->key=rep->key;
                    r->meaning=rep->meaning;
                    r->right=delete_key(r->right,rep->key);
                    return r;
                }
            }
            if(r->key>k){
                r->left=delete_key(r->left,k);
            }else{
                r->right=delete_key(r->right,k);
            }

        }

        void display(node* r){
            if (r!=NULL){
                display(r->left);
                cout<<r->key<<":"<<r->meaning<<endl;
                display(r->right);
            }
        }

        void update(node* r,string t){
            r->meaning=t;
        }
        
        node* find(node*r,string k){
            while(r!=NULL){
                if(r->key==k){
                    return r;
                }
                if(r->key>k){
                    r=r->left;
                }else{
                    r=r->right;
                }
            }
            return NULL;
        }
};

int main()
{
    Dictionary_Tree obj;
    bool flag=true;
    int ch;
    string s,k; 
    node* t;
    while(flag){
        cout<<"MENU"<<endl;
        cout<<"1.Add"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Update"<<endl;
        cout<<"5.Find"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter choice:";
        cin>>ch;
        switch (ch)
        {
            case 1:
                t=new node();
                cout<<"Enter key:";
                cin>>t->key;
                cout<<"Enter meaning:";
                cin>>t->meaning;
                if(root==NULL){
                    root=t;
                }else{
                    obj.add(root,t);
                }
                
                break;
            
            case 2:
                cout<<"Enter key to be deleted:";
                cin>>s;
                obj.delete_key(root,s);
                break;
            
            case 3:
                obj.display(root);
                cout<<endl;
                break;

            case 4:
                cout<<"Enter key you want to update:";
                cin>>s;
                cout<<"Enter new meaning:";
                cin>>k;
                obj.update(obj.find(root,s),k);
                break;
            
            case 5:
                cout<<"Enter key to find:";
                cin>>s;
                t=obj.find(root,s);
                if (t!=NULL){
                cout<<t->key<<":"<<t->meaning<<endl;
                }else{
                    cout<<"Not Present";
                }
                break;

            case 6:
                flag=false;
                break;
            
            default:
                cout<<"Invalid input"<<endl;
                break;
        }
    }

    return 0;
}
