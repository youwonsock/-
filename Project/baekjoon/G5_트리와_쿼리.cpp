#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1000001;

vector<int> tree[N];
vector<int> sizeArr(N,1);

struct Node
{
    Node() {};
    Node(int num, Node* parent) : nodeNum(num), parent(parent) {};

    int nodeNum = 0;
    Node* parent = nullptr;
    vector<Node*> children;
};

void MakeTree(Node* current, Node* parent)
{
    for(int i = 0; i < tree[current->nodeNum].size(); ++i)
    {
        if(parent->nodeNum != tree[current->nodeNum][i])
        {
            Node* child = new Node(tree[current->nodeNum][i], current);
            current->children.push_back(child);
            MakeTree(child, current);
        }
    }
}

void CountSubTree(Node* current)
{
    for(auto node : current->children)
    {
        CountSubTree(node);
        sizeArr[current->nodeNum] += sizeArr[node->nodeNum];
    }
}

int main(void)
{
    fastIo

    int n, r, q;

    cin >> n >> r >> q;

    for(int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    Node* root = new Node(r, nullptr);
    Node* vNode = new Node(-1, nullptr);
    MakeTree(root,vNode);
    CountSubTree(root);

    for(int i = 0; i < q; ++i)
    {
        int t;
        cin >> t;

        cout << sizeArr[t] << "\n";
    }

    return 0;
}

/*
// http://boj.kr/5662295e68b34acda6001120c763b723

#include <bits/stdc++.h>
using namespace std;

const int MXN = 10e5 + 10;
int N, R, Q, U, V, q, subTreeSize[MXN];
vector<int> adj[MXN];
vector<bool> vis(MXN);
int countSubtreeNode(int cur) {
  vis[cur] = true;
  for (auto nxt : adj[cur]) {
    if (vis[nxt]) continue;
    subTreeSize[cur] += countSubtreeNode(nxt);
  }
  subTreeSize[cur]++;
  return subTreeSize[cur];
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> R >> Q;
  for (int i = 0; i < N - 1; i++) {
    cin >> U >> V;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  countSubtreeNode(R);
  while (Q--) {
    cin >> q;
    cout << subTreeSize[q] << '\n';
  }
}
*/