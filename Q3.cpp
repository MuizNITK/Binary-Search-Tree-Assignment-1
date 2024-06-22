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
// construct tree
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
// level order traversal
int levels(Node* root){
    if(root==NULL ) return 0;
    return 1+ max(levels(root->left),levels(root->right));
}
void nthlevel(Node* root,int curr, int level){
    if(root==NULL) return;
    if(curr==level) {
        cout<<root->val<<" ";
        return;
    }
    
    nthlevel(root->left,curr+1,level);
    nthlevel(root->right,curr+1,level);
}

void levelOrder(Node* root){
    if(root==NULL) return;
    int n = levels(root);
    for(int i=0;i<n;i++){
        nthlevel(root,0,i);
        cout<<endl;
    }
}

// Actual answer code
void inorder(Node* root, vector<Node*>& v){
        if(root==NULL) return;
        if(root->left) inorder(root->left,v);
        v.push_back(root);
        if(root->right) inorder(root->right,v);
    }

    Node* solve(int lo, int hi, vector<Node*>& v){
        if(lo>hi) return NULL;
        int mid = lo+(hi-lo)/2;
        v[mid]->left = solve(lo,mid-1,v);
        v[mid]->right = solve(mid+1,hi,v);
        return v[mid];
    }
    Node* balanceBST(Node* root) {
        vector<Node*> v;
        inorder(root,v);
        return solve(0,v.size()-1,v);
    }

int main(){ 
    int arr[] = {1,-1,2,-1,3,-1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    levelOrder(root);

    Node* balancedRoot = balanceBST(root);
    cout<<endl;
    levelOrder(balancedRoot);


}
