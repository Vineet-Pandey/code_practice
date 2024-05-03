//
// Created by vineet on 4/26/24.
//

#include <iostream>
#include<vector>
#include <algorithm>
#include <cassert>
#include <stack>
#include <optional>
class PointerLearn
{
public:
    int var_1;
    double var_2;
    std::string var_3;
    PointerLearn* left;
    PointerLearn* right;

    PointerLearn(int value):var_1(value),left (nullptr),right(nullptr){

    }
    PointerLearn* insertLeft(int value){
        this->left = new PointerLearn(value);
        return this->left;
    }
    PointerLearn* insertRight(int value){
        this->right = new PointerLearn(value);
        return this->right;
    }

};

void printInOrder(PointerLearn* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        std::cout << node->var_1 << " ";
        printInOrder(node->right);
    }
}

int main(){
PointerLearn* root =new PointerLearn(10);
PointerLearn* left_child  = root ->insertLeft(2);
PointerLearn* right_child = root ->insertRight(3);
PointerLearn* left_child_1 = left_child->insertLeft(5);
PointerLearn* left_child_2 = left_child->insertRight(6);

auto displayBinarytree = [&](PointerLearn* root,auto displayBinaryTree)->void{
    if(root != nullptr){
        std::cout<<root->var_1 <<" ";
        displayBinaryTree(root->left, displayBinaryTree);
        displayBinaryTree(root->right, displayBinaryTree);


    }
};
displayBinarytree(root,displayBinarytree);
//    printInOrder(root);

    return 0;
}