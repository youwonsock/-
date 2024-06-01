#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node
{
    Node() {}
    Node(char newName, Node* newLeft, Node* newRight)
    {
        name = newName;
        left = newLeft;
        right = newRight;
    }

    ~Node()
    {
        if(left != nullptr)
            delete left;
        
        if(right != nullptr)
            delete right;
    }

    char name = '.';

    Node* left = nullptr;
    Node* right = nullptr;
};

class Tree
{
public:
    Node* root = nullptr;

    Tree() {}
    ~Tree() 
    {
        if(root != nullptr)
            delete root; 
    }

    void PreOrder(Node* current)
    {
        if(current == nullptr || current->name == '.')
            return;

        cout << current->name;
        PreOrder(current->left);
        PreOrder(current->right);
    }

    void InOrder(Node* current)
    {
        if(current == nullptr || current->name == '.')
            return;
            
        InOrder(current->left);
        cout << current->name;
        InOrder(current->right);
    }

    void PostOrder(Node* current)
    {
        if(current == nullptr || current->name == '.')
            return;
            
        PostOrder(current->left);
        PostOrder(current->right);
        cout << current->name;
    }

    Node* Find(Node* current, char nodeName)
    {
        if(current == nullptr)
            return nullptr;
        
        if(current->name == nodeName)
            return current;

        Node* t = Find(current->left, nodeName);
        if(t != nullptr)
            return t;
        
        return Find(current->right, nodeName);
    }
};

int main(void)
{
    fastIo

    Tree tree;
    tree.root = new Node('A', nullptr, nullptr);

    int n;
    cin >> n;

    char a,b,c;
    for(int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;

        Node* t = tree.Find(tree.root, a);
        t->left = new Node(b, nullptr, nullptr);
        t->right = new Node(c, nullptr, nullptr);
    }

    tree.PreOrder(tree.root);
    cout << "\n";
    tree.InOrder(tree.root);
    cout << "\n";
    tree.PostOrder(tree.root);

    return 0;
}

/*

// 배열을 사용한 처리

#include <bits/stdc++.h>
using namespace std;

int n;
int lc[30];
int rc[30];

void preorder(int cur)
{
  cout << char(cur+'A'-1);

  if(lc[cur] != 0) 
    preorder(lc[cur]);

  if(rc[cur] != 0) 
    preorder(rc[cur]);  
}

void inorder(int cur)
{
  if(lc[cur] != 0) 
    inorder(lc[cur]);
  
  cout << char(cur+'A'-1);
  
  if(rc[cur] != 0) 
    inorder(rc[cur]);
}

void postorder(int cur)
{
  if(lc[cur] != 0) 
    postorder(lc[cur]);
  
  if(rc[cur] != 0) 
    postorder(rc[cur]);
  
  cout << char(cur+'A'-1);  
}

int main() {
  ios::sync_with_stdio(0);

  cin.tie(0);
  cin >> n;

  for(int i = 1; i <= n; i++)
  {
    char c,l,r; // cur, left, right
    cin >> c >> l >> r;

    if(l != '.') 
        lc[c-'A'+1] = l-'A'+1;
    if(r != '.') 
        rc[c-'A'+1] = r-'A'+1;
  }

  preorder(1); cout << '\n';
  inorder(1); cout << '\n';
  postorder(1); cout << '\n';  
}
*/