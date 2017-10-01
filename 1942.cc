// Dp & math
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

double combination(unsigned int n, unsigned int m) {
	m = std::min(m, n - m);
	double ans = 1.0;
	while (m > 0)
		ans *= double(n--) / double(m--);
	return ans;
}
int main() {
	unsigned int n, m;
	while (std::cin >> n >> m) {
		if (!n && !m)
			break;
		std::cout << std::fixed << std::setprecision(0) << combination(n + m, m) << std::endl;
	}
	return 0;
}
