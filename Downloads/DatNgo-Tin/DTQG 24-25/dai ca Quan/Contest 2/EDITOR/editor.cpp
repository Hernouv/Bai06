#include <bits/stdc++.h>
using namespace std;

struct Node
{
    long long val;
    long long sum;
    long long max_prefix;
    int size;
    int priority;
    Node *left;
    Node *right;

    Node(long long x) : val(x), sum(x), max_prefix(x), size(1), priority(rand()), left(nullptr), right(nullptr) {}
};

int get_size(Node *node)
{
    return node ? node->size : 0;
}

long long get_sum(Node *node)
{
    return node ? node->sum : 0;
}

long long get_max_prefix(Node *node)
{
    return node ? node->max_prefix : LLONG_MIN;
}

void update(Node *node)
{
    if (!node)
        return;
    node->size = 1;
    node->sum = node->val;
    node->max_prefix = node->val;

    if (node->left)
    {
        node->size += node->left->size;
        node->sum += node->left->sum;
    }
    if (node->right)
    {
        node->size += node->right->size;
        node->sum += node->right->sum;
    }

    long long left_sum = node->left ? node->left->sum : 0;
    long long left_max_prefix = node->left ? node->left->max_prefix : LLONG_MIN;
    long long right_max_prefix = node->right ? node->right->max_prefix : LLONG_MIN;

    node->max_prefix = left_max_prefix;
    node->max_prefix = max(node->max_prefix, left_sum + node->val);
    node->max_prefix = max(node->max_prefix, left_sum + node->val + (node->right ? node->right->max_prefix : 0LL));
}

void split(Node *root, int key, Node *&left, Node *&right)
{
    if (!root)
    {
        left = right = nullptr;
        return;
    }
    int curr = get_size(root->left);
    if (key <= curr)
    {
        split(root->left, key, left, root->left);
        right = root;
    }
    else
    {
        split(root->right, key - curr - 1, root->right, right);
        left = root;
    }
    update(root);
}

Node *merge(Node *left, Node *right)
{
    if (!left || !right)
        return left ? left : right;
    if (left->priority > right->priority)
    {
        left->right = merge(left->right, right);
        update(left);
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        update(right);
        return right;
    }
}

Node *insert(Node *root, int pos, long long val)
{
    Node *new_node = new Node(val);
    Node *left, *right;
    split(root, pos, left, right);
    left = merge(left, new_node);
    root = merge(left, right);
    return root;
}

Node *erase(Node *root, int pos)
{
    Node *left, *mid, *right;
    split(root, pos, left, right);
    split(right, 1, mid, right);
    if (mid)
        delete mid;
    root = merge(left, right);
    return root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));

    int n, q;
    cin >> n >> q;
    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        root = merge(root, new Node(x));
    }
    int cursor = n;
    while (q--)
    {
        char op;
        cin >> op;
        if (op == 'A')
        {
            long long x;
            cin >> x;
            root = insert(root, cursor, x);
            cursor++;
        }
        else if (op == 'D')
        {
            if (cursor > 0)
            {
                root = erase(root, cursor - 1);
                cursor--;
            }
        }
        else if (op == 'L')
        {
            if (cursor > 0)
            {
                cursor--;
            }
        }
        else if (op == 'R')
        {
            if (cursor < get_size(root))
            {
                cursor++;
            }
        }
        else if (op == 'Q')
        {
            if (root)
            {
                cout << root->max_prefix << "\n";
            }
            else
            {
                cout << "0\n";
            }
        }
    }
}
