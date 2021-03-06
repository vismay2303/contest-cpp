#include <iostream>
#include <string>

typedef unsigned int uint;

void solve(size_t n, std::string s) {
	s += 'a'; // not to check the end in a special way

	uint answer = 0, count_subsequent_x = 0;
	bool remove = false;

	for (auto c: s) {
		if (count_subsequent_x >= 3)
			++answer;
		if (c == 'x')
			++count_subsequent_x;
		else
			count_subsequent_x = 0;
	}

	std::cout << answer << "\n";
}

int main() {
	size_t n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	solve(n, s);

	return 0;
}