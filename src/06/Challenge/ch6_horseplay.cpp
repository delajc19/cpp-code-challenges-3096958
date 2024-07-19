// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
void helper(vector<string>&v,char x, char y, int run, int rise){
    if(x+run <= 'h' && x+run >= 'a' && y+rise <= '8' && y+rise >= '1'){
        string s = "";
        s.push_back(x+run); s.push_back(y+rise);
        v.push_back(s);
    }
}
vector<string> knight_moves(string knight){
    vector<string> moves;
    char file = knight.at(0);
    char rank = knight.at(1);

    // file+2, rank+1d5
    helper(moves,file,rank,2,1);
    // file+2, rank-1
    helper(moves,file,rank,2,-1);
    // file-2, rank+1
    helper(moves,file,rank,-2,1);
    // file-2, rank-1
    helper(moves,file,rank,-2,-1);
    // file+1, rank+2
    helper(moves,file,rank,1,2);
    // file+1, rank-2
    helper(moves,file,rank,1,-2);
    // file-1, rank+2
    helper(moves,file,rank,-1,2);
    // file-1, rank-2
    helper(moves,file,rank,-1,-2);

    
    return moves;
}


// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}