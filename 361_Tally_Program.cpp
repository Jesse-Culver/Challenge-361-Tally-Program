// Author: Jesse Culver
// Directions: 5 Friends (let's call them a, b, c, d and e) are playing a game and need to keep track of the scores. 
// Each time someone scores a point, the letter of his name is typed in lowercase. If someone loses a point, the letter of his name is typed in uppercase. 
// Give the resulting score from highest to lowest.

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char *argv[]){
  // Create Player Score Keeping Variables
  int playerA = 0, playerB = 0, playerC = 0, playerD = 0, playerE = 0;
  std::vector<std::pair<int,char>> playersSorted;

  // Make sure they actually gave us an input
  if(argc > 1){
    std::string inputString = argv[1];
    for(char& c : inputString){
      switch(std::tolower(c)){
        case 'a':
          playerA += (std::islower(c) ? 1 : -1); // if lower +1 else -1
          break;
        case 'b':
          playerB += (std::islower(c) ? 1 : -1);
          break;
        case 'c':
          playerC += (std::islower(c) ? 1 : -1);
          break;
        case 'd':
          playerD += (std::islower(c) ? 1 : -1);
          break;
        case 'e':
          playerE += (std::islower(c) ? 1 : -1);
          break;
        default:
          break;
      }
    }
    // Sort the results
    playersSorted.push_back(std::make_pair(playerA,'a'));
    playersSorted.push_back(std::make_pair(playerB,'b'));
    playersSorted.push_back(std::make_pair(playerC,'c'));
    playersSorted.push_back(std::make_pair(playerD,'d'));
    playersSorted.push_back(std::make_pair(playerE,'e'));
    std::sort(playersSorted.begin(),playersSorted.end());

    // Print Results
    // Rather then reorder just run the loop backwards
    for(int i = 4; i > 0; --i){
      std::cout << playersSorted[i].second << ":" << playersSorted[i].first << ", ";
    }
    std::cout << playersSorted[0].second << ":" << playersSorted[0].first << std::endl;
  }
  // Didn't provide input arg
  else{
    std::cout << "Please provide an input string composed of lowercase and uppercase letters between A and E\n";
  }

  return 0;
}
