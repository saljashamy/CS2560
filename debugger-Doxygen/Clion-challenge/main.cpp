#include <iostream>

int main(){
    int scores = 0;
    double total = 0;
    double score = -1;
    std::string input = "";
    while(score != 0){
        scores++;
        std::cout << "Enter score, (0 to stop):" << std::endl;
        std::cin >> input;
        score = std::stod(input);
        total += score;
    }
    scores--;
    std::cout << "number of scores: " << scores << std::endl;
    std::cout << "average: " << total/scores << std::endl;
}