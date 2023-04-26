/* Implement DFS using adjacency matrix */

#include <iostream>
using namespace std;

int n;
int a[10][10];
int s[20];
int visited[20];


class G{

    public:
    
    void start()
    {

        cout<<"Enter number of vertices of the graph:"<<endl;
        cin>>n;
        cout<<"Enter 1 if there is an edge present between the the two branches.."<<endl;

        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }

        cout<<"The adjacency matrix is:"<<endl;
        cout<<"* "<<n-n<<" "<<n-2<<" "<<n-1<<endl;
        for (int i=0;i<n;i++)
        {
            cout<<i<<" ";
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }

    }
};

class stack{
    public:
        int top;
        stack()
        {
            top==-1;
        }

        int isempty()
        {
            if(top==-1)
                return 1;
            
            else
                return 0;

        }

        int isfull()
        {
            if(top==n)
                return 1;
            
            else
                return 0;

        }

        void push(int value)
        {
            if(isfull()==1)
                cout<<"Stack is full!!";
            else
                top++;
                s[top]=value;
        }

        void pop(int value)
        {
            if(isempty()==1)
                cout<<"Stack is empty";
            else
            {
                value=s[top];
                top--;
            }
        }
    
};

int main()
{
    G g;
    g.start();
}