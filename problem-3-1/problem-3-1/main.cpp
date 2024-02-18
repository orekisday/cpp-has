//
//  main.cpp
//  problem-3-1
//
//  Created by Nurmukhammed Ernestov on 13/2/24.
//

#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    
    int lower_bound = 1;
    int upper_bound = 5;
    uniform_int_distribution<> distribution(lower_bound, upper_bound);
    
    int x, y;
    cout << "enter the num of rows and columns" << endl;
    cin >> x >> y;
    
    int** nums = new int* [x];
    
    for (int i = 0; i < x; i++) {
        nums[i] = new int[y];
    }
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            nums[i][j] = distribution(gen);
        }
    }
    
    for (int i = 0; i < x; i++) {
        for (int j = 1; j < y - 1; j++) {
            if (nums[i][j - 1] == nums[i][j] && nums[i][j - 1] == nums[i][j + 1]) {
                cout << "horizontal match" << endl;
            }
        }
    }
    for (int i = 1; i < x - 1; i++) {
        for (int j = 0; j < y; j++) {
            if (nums[i - 1][j] == nums[i][j] && nums[i - 1][j] == nums[i + 1][j]) {
                cout << "vertical match" << endl;
            }
        }
    }
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << nums[i][j] << ' ';
        }
        cout << endl;
    }
    
    for (int i = 0; i < x; i++) {
        delete [] nums[i];
    }
    delete[] nums;
    
    return 0;
}
