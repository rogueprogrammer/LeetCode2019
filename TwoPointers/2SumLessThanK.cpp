int twoSumLessThanK(vector<int> A, int k) {
	sort(A.begin(), A.end());
	int S = INT_MIN;
	int l = 0;
	int r = A.size() - 1;
	while (l < A.size() - 1 && l < r) {
		if (A[l] + A[r] < k) {
			S = max(S, A[l] + A[r]);
			++l;
		}
		else {
			--r;
		}
	}
	if (S == INT_MIN) return -1;
	return S;
}
