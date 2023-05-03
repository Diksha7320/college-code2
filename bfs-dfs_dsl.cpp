#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#define MAX 10
using namespace std;

int v;
int adj_mat[MAX][MAX] = {0};
vector<vector<int>> adj_list = {{}};

void dfs(int mat[MAX][MAX])
{
    bool visited[MAX] = {false};
    vector<int> ans;
    int i = 0;
    stack<int> s;
    s.push(i);
    while (!s.empty())
    {
        int t = s.top();
        if (visited[t] == false)
        {
            ans.push_back(t);
        }

        bool flag = false;
        for (i = 0; i < v; i++)
        {
            if (mat[t][i] == 1 && visited[i] == false)
            {
                s.push(i);
                flag = true;
            }
        }
        if (!flag)
        {
            s.pop();
        }
        visited[t] = true;
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
}

void bfs()
{
    bool visited[MAX] = {false};
    queue<int> temp;
    vector<int> ans;
    temp.push(0);
    while (!temp.empty())
    {
        int t = temp.front();
        temp.pop();
        if (visited[t] == false)
        {
            ans.push_back(t);
        }
        visited[t] = true;
        for (int i : adj_list[t])
        {
            if (visited[i] == false)
                temp.push(i);
        }
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
}

void add(int i, int j)
{
    adj_list[i].push_back(j);
    adj_list[j].push_back(i);
}

int main()
{
        cout << "Enter number of vertices:";
        cin >> v;

        // node* vert[MAX]={NULL};
        for (int i = 0; i < v; i++)
        {
        adj_list.push_back({});
        }

        int e;
        cout << "Enter number of edges:";
        cin >> e;
        for (int c = 0; c < e; c++)
        {
        int i, j;
        cout << "Enter vertex 1:";
        cin >> i;
        cout << "Enter vertex 2:";
        cin >> j;
        adj_mat[i][j] = 1;
        adj_mat[j][i] = 1;
        adj_list[i].push_back(j);
        adj_list[j].push_back(i);
        }
        cout<<"Adjecency matrix:"<<endl;
        for (int i = 0; i < v; i++)
        {
        for (int j = 0; j < v; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
        }
        cout<<"Adjecency List:"<<endl;
        for(int i=0;i<v;i++){
            cout<<i<<"->";
            for(int j:adj_list[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }

        //dfs(adj_mat);
        cout <<"DFS search order is:";
        dfs(adj_mat);
        cout<<"\nBFS search order is:";
        bfs();
        // bfs(adj_mat,v);
        return 0;
}
