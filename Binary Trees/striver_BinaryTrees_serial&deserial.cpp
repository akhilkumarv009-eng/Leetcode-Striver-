#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Codec {
public:

    // Encodes a tree to a single string
    string serialize(TreeNode* root) {

        if (root == NULL)
            return "";

        queue<TreeNode*> q;
        q.push(root);

        string s;

        while (!q.empty()) {

            TreeNode* cur = q.front();
            q.pop();

            if (cur == NULL) {
                s.append("#,");
            }
            else {
                s.append(to_string(cur->val));
                s.append(",");

                q.push(cur->left);
                q.push(cur->right);
            }
        }

        return s;
    }


    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {

        if (data.size() == 0)
            return NULL;

        // Convert string into a stream
        stringstream ss(data);

        queue<TreeNode*> q;

        string str;

        // First value is the root
        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        q.push(root);

        while (!q.empty()) {

            TreeNode* cur = q.front();
            q.pop();

            // Get left child
            getline(ss, str, ',');

            if (str == "#") {
                cur->left = NULL;
            }
            else {
                TreeNode* temp = new TreeNode(stoi(str));
                cur->left = temp;
                q.push(temp);
            }

            // Get right child
            getline(ss, str, ',');

            if (str == "#") {
                cur->right = NULL;
            }
            else {
                TreeNode* temp = new TreeNode(stoi(str));
                cur->right = temp;
                q.push(temp);
            }
        }

        return root;
    }
};


int main() {

    /*
             1
            / \
           2   3
              / \
             4   5
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);


    Codec obj;

    // Serialize
    string data = obj.serialize(root);

    cout << "Serialized tree: " << data << endl;


    // Deserialize
    TreeNode* newRoot = obj.deserialize(data);

    cout << "Root after deserialization: "
         << newRoot->val << endl;

    cout << "Left child: "
         << newRoot->left->val << endl;

    cout << "Right child: "
         << newRoot->right->val << endl;

    return 0;
}