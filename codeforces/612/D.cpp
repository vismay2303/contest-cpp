#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

typedef unsigned int uint;
typedef std::pair<int, int> pint;
typedef std::vector<int> vint;
typedef std::vector<pint> vpint;

void solve(size_t n, uint k, vint& a, vint& b) {
	vpint events(n << 1);
	
	for (size_t i = 0; i < n; ++i) 
		events[i] = pint(a[i], -1);

	for (size_t i = 0; i < n; ++i) 
		events[n + i] = pint(b[i], 1);

	std::sort(std::begin(events), std::end(events));

	vpint answer; uint balance = 0;
	for (auto event: events) {
		if (balance == k - 1 && event.second == -1)
			if (answer.empty() || answer.back().second != event.first)
				answer.push_back(pint(event.first, 0));
		
		if (balance == k && event.second == 1)
			answer.back().second = event.first;

		balance -= event.second;
	}

	std::cout << std::size(answer) << "\n";
	for (auto answer_i: answer)
		std::cout << answer_i.first << " " << answer_i.second << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t n; uint k;
	std::cin >> n >> k;

	vint a(n), b(n);
	for (size_t i = 0; i < n; ++i)
		std::cin >> a[i] >> b[i];

	solve(n, k, a, b);

	return 0;
}