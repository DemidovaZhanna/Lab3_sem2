#ifndef MEASURING_TIME_H
#define MEASURING_TIME_H

#include "binary_search_tree.h"

auto time() {

	int64_t N = 1000000;
	AVL_tree<int, int> tree;
	int el = 1;
	int n = 1000;

	long long *y_time = new long long[N];
	long long *x_count = new long long[N];

	for(int i = 0; i < N/n; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		for(int i = 0; i < n; i++) {
			tree.insert(el, el);
			el++;
		}

		auto stop = std::chrono::high_resolution_clock::now();
		long long time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

		long long time_one = time / n;

		y_time[i] = time_one;

		x_count[i] = tree.size();
		el++;
	}
}

#endif // MEASURING_TIME_H
