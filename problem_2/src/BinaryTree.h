#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"
#include <iostream>

using namespace std;

template<class T>
class BinaryTree : public Tree<T> {
private:
    TreeNode<T> *root;

    int height(TreeNode<T> *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector <T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T> *root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector <T> traverseInOrder() override {
        // homework, to be done iteratively
        vector <T> result;
        TreeNode<T> *curr = root;
        LinkedStack<TreeNode<T> *> s;


        while (curr != nullptr || !s.isEmpty()) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->getLeft();
            }
            curr = s.peek();
            s.pop();
            //cout << curr->getVal() << " ";
            result.push_back(curr->getVal());
            curr = curr->getRight();
        }
        return result;

    }

    std::vector <T> traversePreOrder() override {
        // don't bother
    }

    std::vector <T> traversePostOrder() override {
        // homework, to be done iteratively
        vector <T> result;
        TreeNode<T> *curr = root;
        LinkedStack<TreeNode<T> *> s1, s2;

        s1.push(root);
        while (!s1.isEmpty()) {
            curr = s1.peek();
            s1.pop();
            s2.push(curr);

            if (curr->getLeft() != nullptr) {
                s1.push(curr->getLeft());
            }
            if (curr->getRight() != nullptr) {
                s1.push(curr->getRight());
            }
        }

        while (!s2.isEmpty()) {
            curr = s2.peek();
            s2.pop();
            //cout << curr->getVal() << " ";
            result.push_back(curr->getVal());
        }

        //delete curr;

        return result;

    }

    virtual ~BinaryTree() {
        // homework
        LinkedStack<TreeNode<T> *> stack;

        if (root == nullptr) {
            return;
        }

        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode<T> *node = stack.peek();
            stack.pop();

            if (node->right != nullptr) {
                stack.push(node->right);
            }
            if (node->left != nullptr) {
                stack.push(node->left);
            }
            delete node;
        }

    }

    TreeNode<T> *_LCA(TreeNode<T> *node, T value1, T value2) {
        if (node == nullptr) {
            return nullptr;
        }

        // check root
        if (node->val == value1 || node->val == value2) {
            return node;
        }

        // check both childrens
        TreeNode<T> *left = _LCA(node->left, value1, value2);
        TreeNode<T> *right = _LCA(node->right, value1, value2);

        if (left != nullptr && right != nullptr) {
            return node;
        }

        if (left == nullptr && right == nullptr) {
            return nullptr;
        }

        return left == nullptr ? right : left;
    }

    T LCA(T node1, T node2) {
        if (root== nullptr){
            return -1;
        }
        TreeNode<T> *node = _LCA(root, node1, node2);
        return node == nullptr ? -1 : node->val;

    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
