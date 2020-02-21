bool doesCurBuildingandNextBuildingOverlap(int curLpx, int curRpx,  int nexLpx, int nexRpx)
{
	// if building1 is nested between building2 or if building2 is nested between building1
	if (curRpx >= nexLpx && curRpx <= nexRpx) {
		return true;
	}
	else if (nexLpx >= curLpx && nexLpx <= curRpx) {
		return true;
	}

	return false;
}

struct VectorHasher {
	int operator()(const vector<int> &V) const {
		int hash = 0;
		for (int i = 0; i < V.size(); i++) {
			hash += V[i]; // Can be anything
		}
		return hash;
	}
};

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

	vector<vector<int>> Lps;
	vector<vector<int>> Rps;
	vector<vector<int>> res;
	unordered_map<vector<int>, vector<int>, VectorHasher> m;
	for (int i = 0; i < buildings.size(); ++i) {
		vector<int> b = buildings[i];
		int lx = b[0]; int rx = b[1]; int y = b[2];
		vector<int> lp = { lx, y };
		vector<int> rp = { rx, y };
		m[lp] = rp;
		Lps.push_back(lp); Rps.push_back(rp);
		// check if next building overlaps with current building. if not, then add coordinate of (Cur_rx, 0)
		// into Lps
		if (i + 1 < Lps.size()) {
			vector<int> nextLp = { buildings[i + 1][0], buildings[i + 1][2] };
			vector<int> nextRp = { buildings[i + 1][1], buildings[i + 1][2] };
			//this below clause doesn't work, need to debug why
			if (!doesCurBuildingandNextBuildingOverlap(lx, rx, nextLp[0], nextRp[0])) {
				vector<int> newCoord = { rx, 0 };
				Lps.push_back(newCoord);
			}
		}
	}
	cout << "Lps: " << endl;
	DEBUG_2D(Lps);
	cout << "Rps: " << endl;
	DEBUG_2D(Rps);
	int maxHeight = -1;
	vector<int> maxBuildingLp = { -1, -1 };
	for (int i = 0; i < Lps.size(); ++i) {
		vector<int> cur = Lps[i]; int curX = cur[0]; int curY = cur[1];
		if (curY > maxHeight) {
			maxHeight = max(maxHeight, curY); maxBuildingLp[0] = curX; maxBuildingLp[1] = curY;
		}
		if ((i == 0) || (curY == 0)) {
			res.push_back(cur); continue;
		}
		else {
			vector<int> highestBuildingRP = m[maxBuildingLp];
			if (curY == maxBuildingLp[1]) {
				res.push_back(maxBuildingLp);
			}
			if (curY < maxHeight && curX > highestBuildingRP[0]) {
				// if x of maxBuildingRP is greater than curX
				// take intersection of RP of highest building and next LP
				// => x of LP, y of next LP
				if (i + 1 < Lps.size()) {
					vector<int> intersection = { highestBuildingRP[0], Lps[i+1][1] };
					res.push_back(intersection);
				}
			}
		}
	}
	return res;
}
