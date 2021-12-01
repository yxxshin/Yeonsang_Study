#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
string input;

string reverseTree(string::iterator& it) {
    char start = *it;
    it++;
    if(start == 'b' || start == 'w') {
        // base case: not divided part
        return string(1, start);    // string constructor
    }
    
    // Divide and Conquer
    string upperLeft = reverseTree(it);
    string upperRight = reverseTree(it);
    string lowerLeft = reverseTree(it);
    string lowerRight = reverseTree(it);
    
    return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}


int main()
{
    int test_num;
    scanf("%d", &test_num);
    while(test_num--) {
        std::cin >> input;
        string::iterator input_it = input.begin();
        std::cout << reverseTree(input_it) << std::endl;
    }
}
