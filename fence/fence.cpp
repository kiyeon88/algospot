#include<vector>
#include<iostream>
#include <algorithm>
#include<cmath>

using namespace std;

vector< vector<bool> > fencesBox;

void makeBox(vector<int>& fences){
	int numOfFences = fences.size();
	int numOfFloor = (*max_element(fences.begin(), fences.end()));
	fencesBox=vector < vector<bool> > (numOfFloor, vector<bool>(numOfFences, 0));
	for (int i = 0; i < numOfFloor; ++i)
		for (int j = 0; j < numOfFences; ++j)
			if (i <= fences[j])
				fencesBox[i][j] = 1;
}

int solve(vector<bool>& fencesEachFloor, int start, int end, vector<pair<int, int> > continuousFences){
	vector<int> checkFence(fencesEachFloor.size());
	for (int i = 0; i < fencesEachFloor.size(); ++i){
		if (fencesEachFloor[i] && !fencesEachFloor[i + 1]) checkFence[i] = -1;
		else if (!fencesEachFloor[i] && fencesEachFloor[i + 1]) checkFence[i] = 1;
		else checkFence[i] = 0;
	}
	


	
}


int main(){
	int cases; cin >> cases;
	while (cases--){
		int numOfFences; cin >> numOfFences;
		vector<int> fences(numOfFences, 0);
		int counter = 0;
		while (numOfFences--){
			cin >> fences[counter++];
		}
		
	}

	return 0;
}