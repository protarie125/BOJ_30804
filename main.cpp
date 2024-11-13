#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll N;
vl S;
map<ll, ll> counts;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
  S = vl(N);
  for (auto&& s : S) cin >> s;

  ll i = 0;
  ll j = -1;
  ll ans = 0;
  counts.clear();
  while (i < N) {
    if (j == N) {
      counts[S[i]] -= 1;
      if (counts[S[i]] == 0) {
        counts.erase(S[i]);
      }

      ++i;
      if (counts.size() <= 2) {
        ans = max(ans, j - i + 1);
      }

      continue;
    }

    if (i >= j) {
      ++j;
      if (N <= j) continue;

      counts[S[j]] += 1;

      if (counts.size() <= 2) {
        ans = max(ans, j - i + 1);
      }

      continue;
    }

    if (counts.size() > 2) {
      counts[S[i]] -= 1;
      if (counts[S[i]] == 0) {
        counts.erase(S[i]);
      }

      ++i;
      if (counts.size() <= 2) {
        ans = max(ans, j - i + 1);
      }
    } else {
      ++j;
      if (N <= j) continue;

      counts[S[j]] += 1;
      if (counts.size() <= 2) {
        ans = max(ans, j - i + 1);
      }
    }
  }

  cout << ans;

  return 0;
}