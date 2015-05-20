#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int getMinSqureError(vector<int> sequence){
	if (sequence.empty()) return 0;
	float mean=(float)accumulate(sequence.begin(), sequence.end(), 0)/ sequence.size();
// 	int nearIdx = 0; float difference = abs(sequence[0] - mean);
// 	for (int i = 1; i < sequence.size(); ++i){
// 		if (difference>abs(sequence[i] - mean)) {
// 			difference = abs(sequence[i] - mean); 
// 			nearIdx = i;
// 		}
// 	}
	int roundingInteger = round(mean);
	int ret = 0;
	for (int i = 0; i < sequence.size(); ++i){
		ret += (sequence[i] - roundingInteger) * (sequence[i] - roundingInteger);
	}
	return ret;
		

}

int solve(vector<int> sequence, vector<int> boundNum)


int main(){
	int cases; cin >> cases;
	while (cases--){
		int lengthOfSequence, numOfUse;
		cin >> lengthOfSequence >> numOfUse;
		int input, count = 0;
		vector<int> sequence(lengthOfSequence);
		while (lengthOfSequence--){
			cin >> input; sequence[count++] = input;
		}

	}
	return 0;
}