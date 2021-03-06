#include <algorithm>
#include <iostream>
#include <utility>
#include <climits>
#include <vector>

typedef unsigned long long ullong;
typedef std::pair<ullong, ullong> pullong;
typedef std::vector<ullong> vullong;
typedef std::vector<pullong> vpullong;

ullong f(size_t pos, vullong& a, vullong& b, vpullong& tc, vpullong& d, ullong k, size_t m, ullong s) {
	ullong mx = a[0], my = b[0], ans = 0, p1 = 0, p2 = 0;
	for (size_t i = 0; i <= pos; ++i) {
		if (mx > a[i]) p1 = i;
		if (my > b[i]) p2 = i;
		mx = std::min(mx, a[i]);
		my = std::min(my, b[i]);
	}

	for (size_t j = 0; j < m; ++j)
		d[j] = pullong(tc[j].first == 1 ? mx * tc[j].second : my * tc[j].second, j);

	std::sort(std::begin(d), std::end(d));

	for (size_t i = 0; i < k; ++i) ans += d[i].first;

	return ans <= s;
}

void solve(size_t n, size_t m, ullong k, ullong s, vullong& a, vullong& b, vpullong& tc) {
	vpullong d(m);

	size_t l = 0, r = n;
	while (l < r) {
		size_t mid = (l + r) >> 1;
		if (f(mid, a, b, tc, d, k, m, s)) r = mid;
		else l = mid + 1;
	}

	if (l >= n) std::cout << -1;
	else {
		std::cout << l + 1 << "\n";

		ullong mx = a[0], my = b[0], p1 = 0, p2 = 0;
		for (size_t i = 0; i <= l; ++i) {
			if (mx > a[i]) p1 = i;
			if (my > b[i]) p2 = i;
			mx = std::min(mx, a[i]);
			my = std::min(my, b[i]);
		}			

		for (size_t j = 0; j < m; ++j)
			d[j] = pullong(tc[j].first == 1 ? mx * tc[j].second : my * tc[j].second, j);

		std::sort(std::begin(d), std::end(d));

		for (size_t i = 0; i < k; ++i) {
			std::cout << d[i].second + 1 << " " << 
				1 + (tc[d[i].second].first == 1 ? p1 : p2) << "\n";
		}
	}
}

int main() {
	size_t n, m;
	ullong k, s;
	std::cin >> n >> m >> k >> s;
	
	vullong a(n);
	for(size_t i = 0; i < n; ++i) std::cin >> a[i];
	
	vullong b(n);
	for(size_t i = 0; i < n; ++i) std::cin >> b[i];

	ullong t, c;
	vpullong tc(m);
	for(size_t j = 0; j < m; ++j) {
		std::cin >> t >> c;
		tc[j] = pullong(t, c);
	}

	solve(n, m, k, s, a, b, tc);

	return 0;
}
