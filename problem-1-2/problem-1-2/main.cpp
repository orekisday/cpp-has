//
//  main.cpp
//  problem-1-2
//
//  Created by Nurmukhammed Ernestov on 8/2/24.
//

#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    int sum = 0;
    
    while (x != 0) {
        int rem = x % 10;
        sum += rem;
        x /= 10;
    }
    cout << sum << endl;
    
    return 0;
}
