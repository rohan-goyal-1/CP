#include <iostream>
#include <vector>

using namespace std;

struct TreeNode { vector<TreeNode*> children; };

int compute (TreeNode* node, int m) {
    int ways[m + 1][2];
    for (int i = 0; i <= m; i++) {
        ways[i][0] = 0;
        ways[i][1] = 0;
    }

    ways[1][0] = 0;
    ways[1][1] = 1;

    for (TreeNode* child : node->children) {
        int newWays[m + 1][2];
        for (int i = 0; i <= m; i++) {
            newWays[i][0] = 0;
            newWays[i][1] = 0;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= i - 1; j++) {
                newWays[i][0] += ways[j][0];
                newWays[i][1] += ways[j][1];
            }
        }

        for (int i = 1; i <= m; i++) {
            ways[i][0] *= newWays[i][1];
            ways[i][1] *= newWays[i][1];
        }
    }

    int result = 0;
    for (int i = 1; i <= m; i++)
        result += ways[i][0];

    return result;
}

int solve (int n, int m) {
    vector<TreeNode*> nodes(n);
    for (int i = 0; i < n; i++)
        nodes[i] = new TreeNode;

    int result = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        nodes[u - 1]->children.push_back(nodes[v - 1]);
    }

    for (int i = 0; i < n; i++)
        result += compute(nodes[i], m);

    return result;
}

int main () {
    int n, m;
    cin >> n >> m; 
    int ans = solve(n, m);
    cout << ans << endl;
    return 0;
}

