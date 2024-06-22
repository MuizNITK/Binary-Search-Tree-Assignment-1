#include <iostream>                                                               
#include <stack>
#include<queue>
#include <vector>
using namespace std;
class Node{
     public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
       
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* construct(int arr[], int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(i<n){
        Node* temp = q.front();
        q.pop();
        Node* l = new Node(arr[i]);
        if(arr[i]==-1/*NULL*/) l = NULL;       // Check for NULL
        Node* r = new Node(arr[j]);
        if(arr[j]==-1/*NULL*/) r = NULL;       // Check for NULL

        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);    // check for NULL
        if(r!=NULL) q.push(r);

        i+=2;
        j+=2;

    }
    return root;
}
void InOorder(Node* root){
    if(root==NULL) return;
    stack<Node*> st;
    
    Node* help = root;
    while(st.size()>0 || help!=NULL){
        
        if(help!=NULL) {
            st.push(help);
            help = help->left;

        }
        else{
            Node* temp = st.top();
            st.pop();
            cout<<temp->val<<" ";
            help = temp->right;
        }

    }
}
void inorder(Node* root, vector<int>& v){
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}

vector<int> minAndMaxValue(Node* root){
    vector<int> in(2);
    vector<int> v;  
    inorder(root,v);
    in[0] = v[0];
    in[1] = v[v.size()-1];
    return in;    
}
int main(){
    int arr[] = {10,15,20,2,8,15,25,-1,4,-1,-1,12,-1,-1,-1,3,-1,-1,13};      // -1 denotes NULL 
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    InOorder(root);
    vector<int> ans = minAndMaxValue(root);
    cout<<endl<<"The min and max values of the given BST are "<<ans[0]<<" "<<ans[1];


}