#include <iostream>
using namespace std;

class tree
{
int a[20][20],u,w,i,j,l,v,e,visited[20];
public:
            void input();
            void display();
            void minimum();
 };
 
 void tree::input()
 {
    cout<<"Enter number of branches:";
    cin>>v;
    
    for(i=0;i<v;i++)
    {
        visited[i]=0;
        for(j=0;j<v;j++)
        {
            a[i][j]=999;
        }
    }
    
    cout<<"\nEnter number of connections:";
    cin>>e;
    
    for(i=0;i<e;i++)
    {
        cout<<"Enter end branches of the connections:"<<endl;
        cin>>l>>u;
        cout<<"Enter the phone company charge for given connection:";
        cin>>w;
        a[l-1][u-1]=a[u-1][l-1]=w;
     }
}

void tree::display()
{
    cout<<"\nAdjacency matrix:";
    for(i=0;i<v;i++)
    {
        cout<<endl;
        for(j=0;j<v;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void tree::minimum()
{
    int p=0,q=0,total=0,min;
    visited[0]=1;
    
    for(int count=0;count<(v-1);count++)
    {
        min=999;
        for(i=0;i<v;i++)
        {
            if(visited[i]==1)
            {
                for(j=0;j<v;j++)
                {
                    if(visited[j]!=1)
                    {
                        if(min > a[i][j])
                        {
                            min=a[i][j];
                            p=i;
                            q=j;
                        }
                    }
                }
            }
         }
    visited[p]=1;
    visited[q]=1;
    total=total+min;
    cout<<"Minimum cost connection is"<<(p+1)<<" -> "<<(q+1)<<" with charge : "<<min<< endl;
    
    }
    cout<<"The minimum total cost of connections of all branches is(mst): "<<total<<endl;
}

int main()
{
    int ch;
    tree t;
    do
    {
        cout<<"PRIM'S ALGORITHM"<<endl;
        cout<<"\n1.INPUT\n \n2.DISPLAY\n \n3.MST\n"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>ch;

        switch(ch)
        { 
            case 1: cout<<"Give input values:"<<endl; 
                        t.input();
                        break;

            case 2: cout<<"Display the output:"<<endl;
                        t.display();
                        break;

            case 3: cout<<"Display minimum spanning tree:"<<endl;
                        t.minimum();
                        break;
        }

      }while(ch!=4);
      
return 0;
}

    
 
            
