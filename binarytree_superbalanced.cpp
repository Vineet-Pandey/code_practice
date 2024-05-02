//
// Created by vineet on 4/26/24.
//

#include <iostream>
#include<vector>
#include <algorithm>
#include <cassert>
#include <stack>

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode *left_;
    BinaryTreeNode *right_;

    BinaryTreeNode(int value):value_(value),left_(nullptr),right_(nullptr){}

    BinaryTreeNode* insertLeft(int value){
        this->left_ = new BinaryTreeNode(value);
        return  this->left_;
    }
    BinaryTreeNode* insertRight(int value){
        this ->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
    ~BinaryTreeNode(){
        delete left_;
        delete right_;
    }
};

bool isBalanced( BinaryTreeNode* root){
    if(root == nullptr){
        return true;
    }

    size_t depths[3];
    size_t depth_ct=0;

    std::stack<std::pair<BinaryTreeNode*, size_t>> nodes;
    nodes.push(std::make_pair(root,0));

    if (!nodes.empty()){
        BinaryTreeNode* node = nodes.top().first;
        size_t depth = nodes.top().second;

        nodes.pop();

        if(!node->left_ && !node->right_){
            if(depth_ct == 0 ||
            std::find(depths,depths+depth_ct,depth) == depths+depth_ct){
                depths[depth_ct] =depth;
                depth_ct++;

                if(depth_ct>2 ||
                depth_ct ==2 && std::max(depths[0],depths[1])- std::min(depths[0],depths[1])>1){
                    return false;
                }
            }
        }
        else {
            if(node->left_){
                nodes.push(std::make_pair(node->left_,depth+1));
            }
            if(node -> right_){
                nodes.push(std::make_pair(node->right_,depth+1));
            }
        }


    }

    return true;
}

int main(){

    return 0;
}