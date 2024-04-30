//
// Created by vineet on 4/26/24.
//

#include <iostream>
#include<vector>
#include <algorithm>
#include <cassert>

auto rotationPointBinarySearch(std::vector<std::string> dictionary_words){
    size_t floor = 0;
    size_t ceiling = dictionary_words.size()-1;

    while (floor < ceiling){

        size_t guess_idx = floor + ((ceiling-floor)/2);


        if(dictionary_words[guess_idx][0] >= dictionary_words[floor][0]){
            floor = guess_idx;

        }
        else if(dictionary_words[guess_idx][0] <= dictionary_words[floor][0]){
            ceiling =guess_idx;
        }

        if(floor+1 ==ceiling){
            std::cout<<"Converged"<<std::endl;
            break;
        }
    }

    return ceiling;
}



int main(){
    const std::vector<std::string> words {
            "ptolemaic",
            "retrograde",
            "supplant",
            "undulate",
            "xenoepist",
            "asymptote",  // <-- rotates here!
            "babka",
            "banoffee",
            "engender",
            "karpatka",
            "othellolagkage",
    };

    std::cout<<"the rotation point in the vector is: " <<rotationPointBinarySearch(words)<<std::endl;


    return 0;
}