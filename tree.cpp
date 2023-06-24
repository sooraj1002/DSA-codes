#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *BuildTree(Node *root)
{

    cout << "enter data for node" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "enter data for putting in left side" << endl;
    root->left = BuildTree(root->left);
    cout << "enter data for putting in right side" << endl;
    root->right = BuildTree(root->right);
    return root;
}

void levelordertraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void reverselevelordertraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    stack<int> st;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            st.push(INT_MIN);
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            st.push(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    while (!st.empty())
    {
        if (st.top() == INT_MIN)
            cout << endl;
        else
            cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    Node *root = NULL;
    root = BuildTree(root);
    cout << "printing level ordered" << endl;
    levelordertraversal(root);
    cout << "printing level ordered reversed" << endl;
    reverselevelordertraversal(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    return 0;
}