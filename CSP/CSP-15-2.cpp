#include <cstdio>
#include <iostream>
using namespace std;

long long r, y, g, n;

int main() {
	scanf("%lld%lld%lld%lld", &r, &y, &g, &n);
	long long all = r + y + g;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long k, t;
		scanf("%lld%lld", &k, &t);
		if (k == 0) {
			sum += t;
		} else if (k == 2) {
			long long mod = (sum - t + all) % all;
			if (mod <= r) {
				sum += (r - mod);
			} else if (mod <= r + g) {
				sum += 0;
			} else {
				sum += (all - mod + r);
			}
		} else if (k == 3) {
			long long mod = (sum - t + all) % all;
			if (mod <= y + r) {
				sum += (y - mod + r);
			}
		} else if (k == 1) {
			long long mod = (sum - t + all) % all;
			if (mod <= g) {
				sum += 0;
			} else if (mod <= g + y + r) {
				sum += (all - mod);
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}
