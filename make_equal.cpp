#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int steps[1001]={0};

int max_coins(int size_of_array, int * target, int * coins, int remaining_operations){
    if((remaining_operations <= 0) || (size_of_array == 0)){
        return 0;
    }

    int option_1 = 0;
    int option_2 = 0;

    if(remaining_operations >= steps[target[size_of_array - 1]]){
        option_1 = max_coins(size_of_array, target, coins, remaining_operations - steps[target[size_of_array - 1]]) + coins[size_of_array - 1];
    }

    option_2 = max_coins(size_of_array - 1, target, coins, remaining_operations);

    return max(option_1, option_2);
}

int main(){

    for(int i = 1; i <= 1000; i++){
        if((i % 2) == 0){
            steps[i] = min(steps[i/2], steps[i-1]) + 1;
        }
        else{
            steps[i] = steps[i - 1] + 1;
        }
    }

    int number_of_test_cases;
    cin >> number_of_test_cases;

    for(int i = 0; i < number_of_test_cases; i++){
        int size_of_array;
        cin >> size_of_array;

        int number_of_operations;
        cin >> number_of_operations;

        int * target = new int [size_of_array];
        for(int i = 0; i < size_of_array; i++){
            cin >> target[i];
        }

        int * coins = new int [size_of_array];
        for(int i = 0; i < size_of_array; i++){
            cin >> coins[i];
        }
        
        cout << max_coins(size_of_array, target, coins, number_of_operations) << endl;
    }

    return 0;
}