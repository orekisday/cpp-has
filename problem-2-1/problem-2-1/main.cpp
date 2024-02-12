//
//  main.cpp
//  problem-2-1
//
//  Created by Nurmukhammed Ernestov on 9/2/24.
//

#include <iostream>
#include <random>
using namespace std;


int main() {
    int nums[6][8];
    random_device rd;
    mt19937 gen(rd());
    
    int lower_bound = 1;
    int upper_bound = 5;
    uniform_int_distribution<> distribution(lower_bound, upper_bound);
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            nums[i][j] = distribution(gen);
        }
    }
    
    for (int i = 0; i < 6; i++) {
        for (int j = 1; j < 7; j++) {
            if (nums[i][j - 1] == nums[i][j] && nums[i][j - 1] == nums[i][j + 1]) {
                cout << "horizontal match" << endl;
            }
        }
    }
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            if (nums[i - 1][j] == nums[i][j] && nums[i - 1][j] == nums[i + 1][j]) {
                cout << "vertical match" << endl;
            }
        }
    }
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            cout << nums[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
