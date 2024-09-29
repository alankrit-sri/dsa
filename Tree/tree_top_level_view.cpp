#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    void topView(Node * root) {
        if(root == NULL)
            return;
        pair<Node *, int> P;
        queue<pair<Node * , int>> Q;
        map<int, int> topViewMap;
        map<int, int> :: iterator topViewItr;

        Node * temp = root;
        P.first = root;
        P.second = 0;
        topViewMap[0] = root->data;
        //cout << "Inserting at index : 0 & value : " << P.first->data << endl;
        Q.push(P);

        while(!Q.empty())
        {
            P = Q.front();
            pair<Node *, int> newPair;
            if(P.first->left != NULL)
                {
                    newPair.first = P.first->left;
                    newPair.second = P.second - 1;
                    Q.push(newPair);

                    if(topViewMap.find(newPair.second) == topViewMap.end())
                    {
                        //cout << "Inserting at index : " << ind << " & value 
: " << newPair.first->data << endl;
                        topViewMap[newPair.second] = newPair.first->data;
                    }
                }
            if(P.first->right != NULL)
                {
                    newPair.first = P.first->right;
                    newPair.second = P.second + 1;
                    Q.push(newPair);   
                    
                    if(topViewMap.find(newPair.second) == topViewMap.end())
                    {
                        //cout << "Inserting at index : " << ind << " & value 
: " << newPair.first->data << endl;
                        topViewMap[newPair.second] = newPair.first->data;
                    }
                }
                
            Q.pop();
        }
        topViewItr = topViewMap.begin();
        while(topViewItr != topViewMap.end())
        {
            cout << topViewItr->second << ' ';
            ++topViewItr;
        }
        
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);

    return 0;
}
