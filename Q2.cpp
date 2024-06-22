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

void inorder(Node* root, vector<int>& v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
int kthSmallest(Node* root, int k) {
        vector<int> v;
        inorder(root,v);
        return v[k-1];
        
}

int main(){
    int arr[] = {10,15,20,2,8,15,25,-1,4,-1,-1,12,-1,-1,-1,3,-1,-1,13};         // -1 denotes NULL 
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
  
    int k = 2;
    cout<<"The kth smallest Node in the BST is "<<kthSmallest(root,k);
}

