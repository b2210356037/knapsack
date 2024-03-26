#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

int knapsack(vector<int> weights, vector<int> values, int W) {
    const int n = weights.size(); //rows
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < W+1; j++){ //j represnts all the possible weight options
            if(j - weights[i-1] >= 0){
                dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n-1][W];
    
}

int main() {
    int total = 7;
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7}; 
	int res = knapsack(weights, values, total);
    cout << res;
    return 0;
}
