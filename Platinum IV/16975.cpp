/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void init(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] =
            tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(vector<int> &a, vector<int> &tree, int node, int start, int end, int index, int val)
{
    if (index < start || index > end)
    {
        return;
    }
    if (start == end)
    {
        tree[node] += val;
        return;
    }
    update(a, tree, node * 2, start, (start + end) / 2, index, val);
    update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] =
        tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    auto lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
    auto rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return lsum + rsum;
}

signed main()
{
    int N, Q;
    scanf("%lld", &N);
    vector<long long> a(N + 1);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    vector<int> tree(tree_size);

    for (int i = 0; i < N; i++)
        scanf("%lld", &a[i]);

    scanf("%lld", &Q);
    while (Q--)
    {
        int oper;
        scanf("%lld", &oper);

        if (oper == 1)
        {
            int i, j, k;
            scanf("%lld %lld %lld", &i, &j, &k);
            update(a, tree, 1, 0, N - 1, i - 1, k);
            update(a, tree, 1, 0, N - 1, j, -k);
        }
        else
        {
            int x;
            scanf("%lld", &x);
            printf("%lld\n", a[x - 1] + query(tree, 1, 0, N - 1, 0, x - 1));
        }
    }

    return 0;
}