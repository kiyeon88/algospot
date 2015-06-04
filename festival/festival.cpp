#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>

#define INF -1.0

using namespace std;
double cache[1000];
int solve(int until, vector<int>& costs){
	double& ret = cache[until];
	if (ret != INF) return ret;
	if (until == 0) return ret = costs[0];
	ret = solve(until - 1, costs);
	//ret = accumulate(costs.begin(), costs.end(), 0);
	for (int i = 0; i <= until; ++i)
		ret = min(ret, accumulate(costs.begin()+i, costs.begin()+until+1, 0)/(double)(until-i+1));
	return ret;
}
int main(){
	int cases; cin >> cases;
	while (cases--){
		int numOfDays, numOfTeams;
		cin >> numOfDays >> numOfTeams;
		vector<int> costs(numOfDays);
		int count = 0;
		while (numOfDays--)	cin >> costs[count++];
		memset(cache, INF, sizeof(cache));
		cout << solve(costs.size() - 1, costs) << endl;
		

	}
}