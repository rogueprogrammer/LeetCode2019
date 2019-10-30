 #include "header.h"
 
 //https://leetcode.com/problems/valid-perfect-square/
 //passed all test cases
 bool isPerfectSquare(int num) {
  if(num == 1)return true;
	long lo = 1;
	long hi = floor(num / 2);
	while (lo <= hi) {
		long mid = ((lo + hi) / 2);
		long prod = mid * mid;
		if (prod == num) return true;
		else if (prod < num) lo = mid+1;
		else if (prod > num) hi = mid-1;
	}
	return false;
}
