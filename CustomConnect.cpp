class Solution {
public:
    void connectLeafNodes(Node* root) {
        if (!root) return;

        Node* curr = root; // Pointer to traverse the current level
        Node* nextLevelStart = nullptr; // Leftmost node of the next level
        Node* prevLeaf = nullptr; // Tracks the last connected leaf node

        while (curr) {
            while (curr) {
                // Check if current node is a leaf node
                if (!curr->left && !curr->right) {
                    if (prevLeaf) {
                        prevLeaf->next = curr; // Connect the previous leaf to the current leaf
                    }
                    prevLeaf = curr;
                }

                // Find the starting node for the next level
                if (!nextLevelStart) {
                    if (curr->left) nextLevelStart = curr->left;
                    else if (curr->right) nextLevelStart = curr->right;
                }

                curr = curr->next; // Move to the next node on the same level
            }

            // Connect the rightmost leaf node to the leftmost leaf node of the next level
            if (prevLeaf) prevLeaf->next = nullptr;

            // Move to the next level
            curr = nextLevelStart;
            nextLevelStart = nullptr;
            prevLeaf = nullptr;
        }
    }
};
