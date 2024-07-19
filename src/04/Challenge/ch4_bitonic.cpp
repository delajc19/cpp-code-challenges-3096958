// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

using namespace std;

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int> &v){
    //edge case for empty or singleton arrays
    if(v.size() <= 1){return true;}

    //declare increasing boolean and determine whether the sequence
    //begins increasing or decreasing
    bool increasing = v[1] >= v[0];

    //initialize slopes counter
    int slopes = 1;

    for(size_t i = 1; i < v.size(); i++){
        //keep track of transitions from increasing to decreasing
        if(!increasing && v[i] > v[i-1]){increasing = true; slopes++;}
        if(increasing && v[i] <= v[i-1]){increasing = false; slopes++;}
        
        //when the number of slopes surpasses 2, check whether the new
        //is actually part of the initial slope
        //if it is not, then there are in fact >2 slopes, so the sequence is not bitonic
        if(slopes > 2){
            if(increasing && v[i] <= v[0]){
                continue;
            }
            else if (!increasing && v[i] >= v[0]){
                continue;
            }
            else{
                return false;
            }
        }

    }
    
    return true;
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    vector<vector<int>> sequences;
    
    sequences.push_back({1, 2, 5, 4, 3});  // Yes
    sequences.push_back({1, 1, 1, 1, 1});  // Yes
    sequences.push_back({3, 4, 5, 2, 2});  // Yes
    sequences.push_back({3, 4, 5, 2, 4});  // No
    sequences.push_back({1, 2, 3, 4, 5});  // Yes
    sequences.push_back({1, 2, 3, 1, 2});  // No
    sequences.push_back({5, 4, 6, 2, 6});  // No
    sequences.push_back({5, 4, 3, 2, 1});  // Yes
    sequences.push_back({5, 4, 3, 2, 6});  // Yes
    sequences.push_back({5, 4, 6, 5, 4});  // No
    sequences.push_back({5, 4, 6, 5, 5});  // Yes

    for(auto x: sequences){
        std::cout << (is_bitonic(x) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
        std::cout << std::endl << std::flush;
    }
    
    return 0;
}
