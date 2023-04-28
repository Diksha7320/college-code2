#include<iostream>
using namespace std;

struct node
{
	char label[10];
	int ch_cnt;
	struct node *child[10];
}
*root;

class booktree
{
	public:
		void create_tree();
		void display(node *r1);
		booktree()
		{
		root=NULL;
		}
};

void booktree::create_tree()
{
	int tbk,tch,i,j,k;
	root= new node;
	
	cout<<"Enter name of the book:"<<endl;
	cin>>root->label;
	cout<<"Enter number of chapters in book:"<<endl;
	cin>>tch;
	root->ch_cnt=tch;

	for(i=0;i<tch;i++)
	{
		root->child[i]=new node;
		cout<<"Enter chapter name:";
		cin>>root->child[i]->label;
		cout<<"Enter number of sections in "<<root->child[i]->label<<":";
		cin>>root->child[i]->ch_cnt;
		
		for(j=0;j<root->child[i]->ch_cnt;j++)
		{
			root->child[i]->child[j]=new node;
			cout<<"Enter sub-sections in "<<j+1<<":";
			cin>>root->child[i]->child[j]->label;
		}
	}
}

void booktree::display(node *r1)
{
	int i,j,k,tch;
	if(r1!=NULL)
	{
		cout<<"\n******Book Tree Hierarchy******"<<endl;
		cout<<"\nName of book is:"<<root->label;
		tch=r1->ch_cnt;
		for(i=0;i<tch;i++)
		{
			cout<<"\nChapters are: "<<i+1;
			cout<<"\nName of chapter is: "<<r1->child[i]->label;
			cout<<"\nSections are:";
			
			
			for(j=0;j<r1->child[i]->ch_cnt;j++)
			{
				cout<<r1->child[i]->child[j]->label;
			}
		}
	}
}

int main()
{
	int choice;
	booktree bt;
	while(1)
	{
		cout<<"\nMENU:"<<endl;
		cout<<"1. Create \n2. Display \n3. Exit";
		cout<<"\nEnter choice:";
		cin>>choice;

		switch(choice){
				case 1:
					bt.create_tree();
					break;
				case 2: 
					bt.display(root);
					break;

				case 3: 
					exit(1);
					break;
				
				default: 
					cout<<"Wrong Choice!!";
		}
	}
return 0;
}

