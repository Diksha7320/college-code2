/*A book consists of chapters, chapters consist of sections and sections consist of 
subsections. Construct a tree and print the nodes. Find the time and space requirements 
of your method.
*/
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    int count;
    Node *child[10];
};

class BookTree
{
public:
    Node *head;
    bool present(Node *root, string val);
    void display();
    void createtree();
    BookTree()
    {
        head = NULL;
    }
};

void BookTree::createtree()
{
    head = new Node;
    cout << "Enter Name of book:";
    cin >> head->name;
    cout << "Enter number of chapter in book:";
    cin >> head->count;

    for (int i = 0; i < head->count; i++)
    {
        bool flag = true;
        string temp;
        head->child[i] = new Node;
        cout << "Enter Name of chapter " << i + 1 << ":";
        cin >> head->child[i]->name;
        cout << "Enter number of sections in chapter" << i + 1 << ":";
        cin >> head->child[i]->count;
        for (int j = 0; j < head->child[i]->count; j++)
        {
            head->child[i]->child[j] = new Node;
            cout << "Enter Name of section " << j + 1 << ":";
            cin >> head->child[i]->child[j]->name;
        }
    }
}
void BookTree::display()
{
    cout<<"****Book Tree Hierarchy****"<<endl;
    if (head == NULL)
        cout << "Tree empty" << endl;
    cout << "Book name is : " << head->name << endl;
    for (int i = 0; i < head->count; i++)
    {
        cout << "\tChapter name:" << head->child[i]->name << endl;
        for (int j = 0; j < head->child[i]->count; j++)
        {
            cout << "\t\tName of section:" << head->child[i]->child[j]->name << endl;
        }
    }
}

int main()
{
	BookTree B;
	int ch,ans;
	do
	{
		cout<<"**********MENU**********"<<endl;
		cout<<"1.Entry in the tree\n2.Display the tree data"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				B.createtree();
				break;
				
			case 2:
				B.display();
				break;
				
			default:
				cout<<"You have entered a wrong choice!!!"<<endl;
				cout<<"Please try again!!"<<endl;
				
		}
		cout<<"\nDo you want to continue???"<<endl;
		cout<<"1.Yes\n2.No"<<endl;
		cin>>ans;
		
		
	}while(ans==1);
	
	if (ans>=2)
		cout<<"Exited successfully!!!"<<endl;
	return 0;
}
