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
void inorder(Node* root, vector<int>& v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int rangeSumBST(Node* root, int low, int high) {
        vector<int> v;
        inorder(root,v);
        int sum=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==low){
                for(int j=i;j<v.size();j++){
                    sum+=v[j];
                    if(v[j]==high) break;
                }
                break;
            }
            
        }
        return sum;
    }
int main(){
    int arr[] = {10,5,15,3,7,-1,18};    // -1 denotes NULL 
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    levelOrder(root);     // level order traversal
    cout<<endl;
    int low,high;
    cout<<"Enter the low and high values  "<<endl;
    cin>>low>>high;
    cout<<"The sum of the range with the values inclusive is ";
    cout<<rangeSumBST(root,low,high);
}