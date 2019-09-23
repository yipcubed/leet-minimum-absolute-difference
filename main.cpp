#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/minimum-absolute-difference/
using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    int diff = INT_MAX;
    for (int i = 1; i < arr.size(); ++i) {
      diff = min(diff, arr[i] - arr[i-1]);
    }
    for (int i = 1; i < arr.size(); ++i) {
      if (diff == (arr[i] - arr[i-1])) {
        res.push_back(vector<int>{arr[i-1], arr[i]});
      }
    }
    return res;
  }
};

void test1() {
  vector<int> v1{4, 2, 1, 3};

  cout << "[[1,2],[2,3],[3,4]] ?\n" << Solution().minimumAbsDifference(v1) << endl;

  vector<int> v2 = {1, 3, 6, 10, 15};
  cout << "[[1,3]] ?\n" << Solution().minimumAbsDifference(v2) << endl;

  vector<int> v3 = {3, 8, -10, 23, 19, -4, -14, 27};
  cout << "[[-14,-10],[19,23],[23,27]] ?\n" << Solution().minimumAbsDifference(v3) << endl;
}

void test2() {

}

void test3() {

}