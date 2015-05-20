#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;

short cache[100][1000];
vector<short> volume;
vector<short> importance;
short solve(int from, int limit){
	short& ret = cache[from][limit];
	
	if (from == volume.size() - 1 && volume[from] <= limit) return ret = importance[from];
	if (from == volume.size() - 1 && volume[from] > limit) return ret = 0;
	
	short minimum = volume[from];
	for (int i = from + 1; i < volume.size(); ++i)
		minimum = min(minimum, volume[from]);
	if (minimum > limit) return 0;

	if (ret != -1) return ret;
	ret = importance[from] + solve(from + 1, limit - volume[from]);
	for (int i = 1; from + i < volume.size(); ++i)
		ret = max(ret, solve(from + i, limit));
	return ret;
	
	// 	
// 	if (left == right&&volume[left] <= limit) return ret=importance[left];
// 	if (max(volume[left], volume[right]) > limit) return ret=0;
// 	
// 	
// 	if (ret != -1) return ret;
// 	ret = importance[left] + solve(left + 1, right, limit - volume[left]);
// 	ret = max(ret, solve(left + 1, right, limit));
// 	return ret;
}



int main(){
	int cases; cin >> cases;
	while (cases--){
		int numOfItems, volumeOfCarrier;
		cin >> numOfItems >> volumeOfCarrier;
		vector<string> items(numOfItems);
		volume.resize(numOfItems);
		importance.resize(numOfItems);
		int count = 0;
		while (numOfItems--){
			cin >> items[count] >> volume[count] >> importance[count];
			count++;
		}
		memset(cache, -1, sizeof(cache));
		cout << solve(0, volumeOfCarrier) << endl;
	}

}