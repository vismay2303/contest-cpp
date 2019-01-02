#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

typedef std::vector<int> vint;
typedef std::vector<vint> vvint;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t k;
	std::cin >> k;

	vvint d;

	size_t ni; vint ai;
	for (size_t i = 0; i < k; ++i) {	
		std::cin >> ni;
		
		ai.resize(ni);

		for (size_t j = 0; j < ni; ++j)
			std::cin >> ai[j];

		int s = std::accumulate(std::begin(ai), std::end(ai), 0);

		for (size_t j = 0; j < ni; ++j) {
			d.push_back({s - ai[j], i + 1, j + 1});
		}
	}

	std::sort(std::begin(d), std::end(d));

	bool ok = false;

	for (size_t i = 0; i + 1 < std::size(d); ++i) {
		if (d[i][0] == d[i + 1][0] && d[i][1] != d[i + 1][1]) {
			std::cout << "YES\n";
			std::cout << d[i][1] << " " << d[i][2] << "\n";
			std::cout << d[i + 1][1] << " " << d[i + 1][2] << "\n";
			return 0;
		}
	}

	std::cout << "NO";
	return 0;
}
