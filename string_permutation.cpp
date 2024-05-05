//
// Created by vineet on 4/26/24.
//

#include <iostream>
#include<vector>
#include <algorithm>
#include <cassert>
#include <stack>
#include <optional>
#include <unordered_set>

std::unordered_set<std::string> getPermutations(const std::string& inputString)
{
    std::unordered_set<std::string> permutations;

    // base case
    if (inputString.length() <= 1) {
        permutations.insert(inputString);
        return permutations;
    }

    std::string allCharsExceptLast = inputString.substr(0, inputString.length() - 1);
    char lastChar = inputString[inputString.length() - 1];

    // recursive call: get all possible permutations for all chars except last
    const auto permutationsOfAllCharsExceptLast = getPermutations(allCharsExceptLast);

    // put the last char in all possible positions for each of the above permutations
    for (const std::string& permutationOfAllCharsExceptLast : permutationsOfAllCharsExceptLast) {
        for (size_t position = 0; position <= allCharsExceptLast.length(); ++position) {
            std::string permutation = permutationOfAllCharsExceptLast.substr(0, position)
                                 + lastChar + permutationOfAllCharsExceptLast.substr(position);
            permutations.insert(permutation);
        }
    }

    return permutations;
}

int main(){
auto p = getPermutations("pandey");

    for(auto i:p){
        std::cout<<" The permutations are: "<<i<<" ";
    }
    return 0;
}