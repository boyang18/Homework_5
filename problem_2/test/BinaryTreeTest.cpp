#include "BinaryTree.h"
#include "gtest/gtest.h"
#include <vector>
using namespace std;

BinaryTree<int>* generateTree() {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(8));
    BinaryTree<int> *tree = new BinaryTree<int>(root);

    return tree;
}

TEST(tree, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));
    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);

}

TEST(tree,traverseInOrder){
TreeNode<int>* root = new TreeNode<int>(3);
root->setLeft(new TreeNode<int>(1));
root->setRight(new TreeNode<int>(5));
root->getLeft()->setLeft(new TreeNode<int>(2));
root->getLeft()->setRight(new TreeNode<int>(7));
root->getRight()->setLeft(new TreeNode<int>(5));
BinaryTree<int> tree(root);
ASSERT_EQ(tree.height(),3);
std::vector<int> answer{2, 1, 7, 3, 5, 5};
ASSERT_EQ(answer,tree.traverseInOrder());

TreeNode<int>* root2 = new TreeNode<int>(3);
root2->setLeft(new TreeNode<int>(1));
root2->setRight(new TreeNode<int>(5));
root2->getLeft()->setLeft(new TreeNode<int>(2));
root2->getLeft()->setRight(new TreeNode<int>(7));
root2->getRight()->setLeft(new TreeNode<int>(5));
root2->getRight()->setRight(new TreeNode<int>(9));
BinaryTree<int> tree2(root2);
ASSERT_EQ(tree2.height(),3);
std::vector<int> answer2{2, 1, 7, 3, 5, 5, 9};
ASSERT_EQ(answer2,tree2.traverseInOrder());

TreeNode<int>* root1 = new TreeNode<int>(3);
BinaryTree<int> tree1(root1);
ASSERT_EQ(tree1.height(),1);
std::vector<int> answer1{3};
ASSERT_EQ(answer1,tree1.traverseInOrder());


TreeNode<int>* root0 = nullptr;
BinaryTree<int> tree0(root0);
ASSERT_EQ(tree0.height(),0);
std::vector<int> answer0{};
ASSERT_EQ(answer0,tree0.traverseInOrder());
}

TEST(tree,traversePostOrder){
TreeNode<int>* root = new TreeNode<int>(3);
root->setLeft(new TreeNode<int>(1));
root->setRight(new TreeNode<int>(5));

root->getLeft()->setLeft(new TreeNode<int>(2));
root->getLeft()->setRight(new TreeNode<int>(7));

root->getRight()->setLeft(new TreeNode<int>(5));

BinaryTree<int> tree(root);
//tree.traversePostOrder();
std::vector<int> answer{2, 7, 1, 5, 5, 3};
ASSERT_EQ(answer,tree.traversePostOrder());
TreeNode<int>* root2 = new TreeNode<int>(3);
root2->setLeft(new TreeNode<int>(1));
root2->setRight(new TreeNode<int>(5));
root2->getLeft()->setLeft(new TreeNode<int>(2));
root2->getLeft()->setRight(new TreeNode<int>(7));
root2->getRight()->setLeft(new TreeNode<int>(5));
root2->getRight()->setRight(new TreeNode<int>(9));
BinaryTree<int> tree2(root2);
ASSERT_EQ(tree2.height(),3);
std::vector<int> answer2{2, 7, 1, 5, 9, 5, 3};
ASSERT_EQ(answer2,tree2.traversePostOrder());

TreeNode<int>* root1 = new TreeNode<int>(3);
BinaryTree<int> tree1(root1);
ASSERT_EQ(tree1.height(),1);
std::vector<int> answer1{3};
ASSERT_EQ(answer1,tree1.traversePostOrder());


TreeNode<int>* root0 = nullptr;
BinaryTree<int> tree0(root0);
ASSERT_EQ(tree0.height(),0);
std::vector<int> answer0{};

ASSERT_EQ(answer0,tree0.traverseInOrder());


}
TEST(tree, LCA) {
BinaryTree<int>* tree = generateTree();
ASSERT_EQ(tree->LCA(1, 2), 1);
ASSERT_EQ(tree->LCA(2, 1), 1);
ASSERT_EQ(tree->LCA(5, 1), 3);
ASSERT_EQ(tree->LCA(1, 5), 3);
ASSERT_EQ(tree->LCA(2, 8), 3);
ASSERT_EQ(tree->LCA(2, 3), 3);
ASSERT_EQ(tree->LCA(3, 2), 3);
ASSERT_EQ(tree->LCA(1, 1), 1);
ASSERT_EQ(tree->LCA(0, 0), -1);
ASSERT_EQ(tree->LCA(10, 10), -1);

delete tree;

TreeNode<int>* root1 = new TreeNode<int>(3);
BinaryTree<int> tree1(root1);
ASSERT_EQ(tree1.LCA(1, 1), -1);
ASSERT_EQ(tree1.LCA(3, 3), 3);

TreeNode<int>* root2 = new TreeNode<int>(3);
root2->setLeft(new TreeNode<int>(1));
root2->setRight(new TreeNode<int>(5));
root2->getLeft()->setLeft(new TreeNode<int>(2));
root2->getLeft()->setRight(new TreeNode<int>(7));
BinaryTree<int> tree2(root2);
ASSERT_EQ(tree2.LCA(2, 7), 1);
ASSERT_EQ(tree2.LCA(7, 7), 7);
ASSERT_EQ(tree2.LCA(1, 5), 3);
ASSERT_EQ(tree2.LCA(2, 5), 3);

}
