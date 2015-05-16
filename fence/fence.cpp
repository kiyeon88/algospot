#include<vector>
#include<stack>
#include<tuple>
#include<iostream>
#include <algorithm>
#include<cmath>

using namespace std;

vector< vector<bool> > fencesBox;

void makeBox(vector<int>& fences){
	int numOfFences = fences.size();
	int numOfFloor = (*max_element(fences.begin(), fences.end()));
	fencesBox=vector < vector<bool> > (numOfFloor+1, vector<bool>(numOfFences, false));
	for (int i = 0; i < numOfFloor; ++i)
		for (int j = 0; j < numOfFences; ++j)
			if (i < fences[j])
				fencesBox[i][j] = true;
}



bool isStackUsed=false;
void solve(int floor, int start, int end, stack<tuple<short, short, short,  bool> >& continuousFences, vector<int>& result){
	
	if (continuousFences.size()==1&&get<3>(continuousFences.top())) return;

	vector<int> checkStartContinuousFence, checkFinalContinuousFence;
	bool searchFence = false;
	vector<bool> fencesEachFloor = fencesBox[floor];
	int priorFloor=-1;
	
	
	
	searchFence = get<3>(continuousFences.top());
	if (!searchFence){
		///////search continuous fences ///////
		bool checkContinousFence = false;
		for (int i = start; i <= end; ++i){
			if (!checkContinousFence&&fencesEachFloor[i]){
				checkContinousFence = true; checkStartContinuousFence.push_back(i);
			}
			else if (checkContinousFence && !fencesEachFloor[i]){
				checkContinousFence = false; checkFinalContinuousFence.push_back(i - 1);
			}

		}
		if (checkContinousFence && fencesEachFloor[end] == true)
			checkContinousFence = false; checkFinalContinuousFence.push_back(end);

		get<3>(continuousFences.top()) = true;
		//////////////////////////////////////
		for (int i = 0; i < checkStartContinuousFence.size(); ++i){
			continuousFences.push(make_tuple(checkStartContinuousFence[i], checkFinalContinuousFence[i], floor, false));
			int tmp = (floor + 1)*(checkFinalContinuousFence[i] - checkStartContinuousFence[i] + 1);
			if (tmp>result[0]) result[0] = tmp;
			//result.push_back((floor+1)*(checkFinalContinuousFence[i] - checkStartContinuousFence[i] + 1));

		}
		if (!checkStartContinuousFence.empty())
			floor++;

		if (checkStartContinuousFence.empty()){

			//result.push_back((floor)*(get<1>(continuousFences.top()) - get<0>(continuousFences.top()) + 1));
			int tmp = (floor)*(get<1>(continuousFences.top()) - get<0>(continuousFences.top()) + 1);
			if (tmp > result[0]) result[0] = tmp;
			priorFloor = get<2>(continuousFences.top());
			continuousFences.pop();
		}
	}
	else{
		priorFloor = get<2>(continuousFences.top());
		continuousFences.pop();
	}

	if (priorFloor > get<2>(continuousFences.top()) ) floor--;


	solve(floor, get<0>(continuousFences.top()), get<1>(continuousFences.top()), continuousFences, result);
	
}

int bruteForce(const vector<int>& h){
	int ret = 0; int N = h.size();
	for (int left = 0; left < N; ++left){
		int minHeight = h[left];
		for (int right = left; right < N; ++right){
			minHeight = min(minHeight, h[right]);
			ret = max(ret, (right - left + 1)*minHeight);
		}
	}
	return ret;
}

vector<int> h;
int solve2(int left, int right){
	if (left == right) return h[left];
	int mid = (left + right) / 2;
	int ret = max(solve2(left, mid), solve2(mid + 1, right));
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);
	while (left < lo || hi < right){
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])){
			++hi;
			height = min(height, h[hi]);
		}
		else{
			--lo;
			height = min(height, h[lo]);

		}
		ret = max(ret, height*(hi - lo + 1));

	}
	return ret;
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
		//makeBox(fences);
		//vector<int> result; result.push_back(0);
		//stack< tuple< short, short, short, bool> > continuousFences;
		//continuousFences.push(make_tuple(0, fences.size() - 1, 0, false));
		//solve(0, 0, fences.size() - 1, continuousFences, result);
		h = fences;
		cout<<solve2(0, fences.size() - 1)<<endl;
		//cout << *max_element(result.begin(), result.end()) << endl;
		//cout << result[0] << endl;
		//continuousFences.clear();

	}

	return 0;
}