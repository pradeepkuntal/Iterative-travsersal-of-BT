#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int val;
};
///iterative travarsal of BT
//Inspired from  https://youtu.be/12aMTS0L6WI

// status ==1 ---> push in preorder , status++ ,push in left node (if exist);
//status==2  ---> push in inorder, status++ ,push in right node(if exist);
//status==2  -->push in postorder , pop from stack..

vector<int>preorder;
vector<int>inorder;
vector<int>postorder;

void IterativeTraversal(Node* root)
{
    stack<pair<Node*,int>>st;
    st.push({root,1});
    while(!st.empty())
    {
        Node* node=st.top().first;int status=st.top().second;
        if(status==1)
        {
            preorder.push_back(node->val);
            st.top().second++;
            if(node->left){
                st.push({node->left,1});
            }
        }
        else if(status==2)
        {
            inorder.push_back(node->val);
            st.top().second++;
            if(node->right){
                st.push({node->right,2});
            }
        }
        else{
            postorder.push_back(node->val);
            st.pop();
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout<<"Hello world"<<endl;
    Node* root;///make the tree with some input
    IterativeTraversal(root);

}