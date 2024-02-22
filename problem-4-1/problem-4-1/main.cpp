//
//  main.cpp
//  problem-4-1
//
//  Created by Nurmukhammed Ernestov on 20/2/24.
//

#include <iostream>
#include <random>
using namespace std;

class DynamicMatrix
{
public:
    int x;
    int y;
    DynamicMatrix(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int randomNum(int lowBound, int upBound)
    {
        random_device rd;
        mt19937 gen(rd());
        
        int lower_bound = lowBound;
        int upper_bound = upBound;
        uniform_int_distribution<> distribution(lower_bound, upper_bound);
        
        return distribution(gen);
    }
};

int main(int argc, const char * argv[])
{
    int x, y;
    cin >> x >> y;
    
    DynamicMatrix obj (x, y);
    char** nums = new char* [obj.x];
    
    for (int i = 0; i < obj.x; i++) {
        nums[i] = new char[obj.y];
    }
    
    for (int i = 0; i < obj.x; i++) {
        for (int j = 0; j < obj.y; j++) {
            int num = obj.randomNum(65, 67);
            nums[i][j] = num;
        }
    }
    for (int i = 0; i < obj.x; i++) {
        for (int j = 1; j < obj.y - 1; j++) {
            if (nums[i][j - 1] == nums[i][j] && nums[i][j - 1] == nums[i][j + 1]) {
                cout << "horizontal match" << endl;
            }
        }
    }
    for (int i = 1; i < obj.x - 1; i++) {
        for (int j = 0; j < obj.y; j++) {
            if (nums[i - 1][j] == nums[i][j] && nums[i - 1][j] == nums[i + 1][j]) {
                cout << "vertical match" << endl;
            }
        }
    }
    
    for (int i = 0; i < obj.x; i++) {
        for (int j = 0; j < obj.y; j++) {
            cout << nums[i][j] << ' ';
        }
        cout << endl;
    }
    
    for (int i = 0; i < obj.x; i++) {
        delete [] nums[i];
    }
    delete[] nums;
    
    return 0;
}
