//
// Created by vineet on 4/26/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

auto movieDecider(int flight_time, std::vector<int> movie_times ) {
    auto bubble_sort =[](std::vector<int> unsorted_vector){
        int size = unsorted_vector.size();
        for (int i=0; i<size-1; i++){
            for (int j = 0; j < size-i-1; ++j) {
                if(unsorted_vector[j]<unsorted_vector[j+1]){
                    std::swap(unsorted_vector[j],unsorted_vector[j+1]);
                }

            }
        }
        return unsorted_vector;
    };
    auto sorted_movie_times = bubble_sort(movie_times);
    std::unordered_set<int> movie_lengths_seen;

    for(int first_movie_length : movie_times){
        int matching_second_movie = flight_time-first_movie_length;
        if(movie_lengths_seen.find(matching_second_movie) != movie_lengths_seen.end()){
            return true;
        }
        movie_lengths_seen.insert(first_movie_length);
    }

return false;

}
int main() {
    auto movie_vec = {120,130,125,260,110,300,135,566,655,780};
   std::cout<<"Are there two movies with flight time: "<< movieDecider(560,movie_vec);
    return 0;
}
