//
// Created by robos on 2020/10/29.
//

#ifndef TEST_2_TREES_HPP
#define TEST_2_TREES_HPP

#include "iostream"

struct BinaryTreeNode{
  char data_;
  BinaryTreeNode *left_;
  BinaryTreeNode *right_;
};


class BinaryTree{
public:
  explicit BinaryTree();
  BinaryTreeNode *build_by_pre_and_infix(const char *pre, const char *infix,int size);
private:
  BinaryTreeNode *root_;
};

BinaryTree::BinaryTree() {
  root_ = new BinaryTreeNode;
  //root_->data_ = root;
  root_->left_ = nullptr;
  root_->right_ = nullptr;
}

BinaryTreeNode *BinaryTree::build_by_pre_and_infix(const char *pre, const char *infix, int size) {
  if(size == 0)return nullptr;

  BinaryTreeNode *temp_node_1;
  if(root_->left_ == nullptr && root_->right_ == nullptr) temp_node_1 = root_;
  else temp_node_1 = new BinaryTreeNode;
  std::cout<<pre[0]<<std::endl;
  temp_node_1->data_ = pre[0];
  int temp_int_1 = 0;
  while(temp_node_1->data_ != infix[temp_int_1]){
    temp_int_1++;
  }
  temp_node_1->left_ = build_by_pre_and_infix(pre + 1, infix, temp_int_1);
  temp_node_1->right_ = build_by_pre_and_infix(pre + temp_int_1 + 1, infix + temp_int_1 + 1, size - 1 - temp_int_1);

  return temp_node_1;
}
#endif // TEST_2_TREES_HPP
