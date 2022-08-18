#include <iostream>
#include <vector>

using namespace std;

struct node {
    char right;
    char left;
};

vector<node> tree(26);

void preOrder(char node) { // 전위순회
    if (node == '.') return ;

    cout << node;
    preOrder(tree[node].left);
    preOrder(tree[node].right);
}

void inOrder(char node) { // 중위순회
    if (node == '.') return ;

    inOrder(tree[node].left);
    cout << node;
    inOrder(tree[node].right);
}

void postOrder(char node) { // 후위순회
    if (node == '.') return ;

    postOrder(tree[node].left);
    postOrder(tree[node].right);
    cout << node;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    char node, left, right;
    for (int i=0;i<n;i++) {
        cin >> node >> left >> right;
        tree[node].left = left;
        tree[node].right = right;
    }

    preOrder('A');
    cout << "\n";

    inOrder('A');
    cout << "\n";

    postOrder('A');
    cout << "\n";
    return 0;
}