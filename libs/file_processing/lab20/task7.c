#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if (numsSize == 0) {
        return NULL;
    }

    int max_value = nums[0];
    int max_index = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > max_value) {
            max_value = nums[i];
            max_index = i;
        }
    }

    struct TreeNode* root = newNode(max_value);

    root->left = constructMaximumBinaryTree(nums, max_index);

    root->right = constructMaximumBinaryTree(nums + max_index + 1, numsSize - max_index - 1);

    return root;
}

void printInorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d", root->value);
    printInorder(root->left);
    printInorder(root->right);
}

int main() {
    int nums[] = {3, 2, 1, 6, 0, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode* root = constructMaximumBinaryTree(nums, numsSize);

    printInorder(root);
    printf("\n");

    return 0;
}