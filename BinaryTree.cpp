#include<iostream>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
    Node(): data(-1), left(NULL), right(NULL){}
    Node(char c): data(c), left(NULL), right(NULL){}
    Node(char c, Node* l, Node* r): data(c), left(l), right(r){}
};

class BTree{
    private:
        string str;
        Node* root;
        Node* buildTree(int& p){
            if(p>=str.size() || str[p] == '#'){
                return NULL;
            }
            Node* s = new Node(str[p]);
            s->left = buildTree(++p);
            s->right = buildTree(++p);
            return s;
        }
    public:
        void createBTree(string s){
            str = s;
            int p = 0;
            root = buildTree(p);
        }

        void preOrder(Node* r){
            if(r){
                cout<<r->data<<" ";
                preOrder(r->left);
                preOrder(r->right);
            }
        }

        void preOrder(){
            preOrder(root);
        }
};

int main(){
    BTree bt;
    string s = "124###3##";
    bt.createBTree(s);
    bt.preOrder();
    return 0;
}