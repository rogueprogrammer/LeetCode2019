#include "Header.h"

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
		// check if cur building doesn't collide with previous building
		// if not, then add (prev building's RP x, 0) as a new LP
		if (i > 0) {
			vector<int> prevBuilding = buildings[i - 1];
			int prevRpX = prevBuilding[1];
			if (lx > prevRpX) {
				vector<int> newLp = { prevRpX, 0 };
				Lps.push_back(newLp);
			}
		}
		vector<int> lp = { lx, y };
		vector<int> rp = { rx, y };
		m[lp] = rp;
		Lps.push_back(lp); Rps.push_back(rp);
		
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
			maxHeight = 0;
			res.push_back(cur); continue;
		}
		else {
			vector<int> highestBuildingRP = m[maxBuildingLp];
			if (curY == maxBuildingLp[1]) { //if going upward trend
				res.push_back(maxBuildingLp);
				continue;
			}
			vector<int> curRp = m[cur];
			vector<int> prev = Lps[i - 1];
			vector<int> prevRp = m[prev];
			if (prevRp.size() > 0 && curRp[0] > prevRp[0]) { //going downward and RP of cur building is greater than RP of previous building
				int x = prevRp[0];
				int y = curRp[1];
				vector<int> newlpToAdd = { x, y };
				res.push_back(newlpToAdd);
			}
		}
	}
	vector<int> lastPoint = buildings[buildings.size() - 1];
	vector<int> lastLp = { lastPoint[1], 0 };
	res.push_back(lastLp);
	return res;
}




void main() {

	/*
	Input           - [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
    Output          - [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24, 0]]
    Expected        - [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
    
I:    [[0,2,3],[2,5,3]]
O:    [[0,3],[2,3],[5,0]]
E:    [[0,3],[5,0]]
    
	*/
	vector<vector<int>> buildings = {
		{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}
		//{15,20,10},{19,24,8}
	};
	vector<vector<int>> res = getSkyline(buildings);
	cout << "RES: " << endl;
	DEBUG_2D(res);

	system("PAUSE");
}
