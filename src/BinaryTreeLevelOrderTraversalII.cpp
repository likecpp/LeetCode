
class Solution
{
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        vector <vector<int> > ans;
        if (root == NULL)
            return ans;
        vector<TreeNode*> x, y;
        x.push_back(root);

        while (1)
        {
            int len = x.size();
            vector <int> tt;
            for (int i = 0; i < len; i++)
            {
                tt.push_back(x[i]->val);
                if (x[i]->left)
                {
                    y.push_back(x[i]->left);
                }
                if (x[i]->right)
                {
                    y.push_back(x[i]->right);
                }
            }
            ans.push_back(tt);
            x = y;
            y.clear();
            if (x.size() == 0)
            {
                break;
            }
        }

        for (int i = 0, j = ans.size() - 1; i < j; i++, j--)
        {
            vector <int> t = ans[i];
            ans[i] = ans[j];
            ans[j] = t;
        }
        return ans;
    }
};
