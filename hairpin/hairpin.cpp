#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;
int cache[6500][6500];
int l = 200, m = 4, h = 20;
string soybeanSequence;
bool pairRule(char a, char b){
	if ((a == 'A'&&b == 'T') || (a == 'T'&&b == 'A') || (a == 'C'&&b == 'G') || (a == 'G'&&b == 'C')) return true;
	else return false;
}

int solve(int i, int j){
	int& ret = cache[i][j];
	if (ret != -1) return ret;
	if (j - i + 1 <= h) return ret = 0;
	else if(pairRule(soybeanSequence[i],soybeanSequence[j])) return ret = solve(i + 1, j - 1);
	else return ret = min(min(solve(i + 1, j) + 1, solve(i, j - 1) + 1), solve(i + 1, j - 1) + 1);
}

void makePair(int i, int j, string& sequence, vector<tuple<int, int, char> >& matchPair){
	
	while (j - i + 1 > h){
		if (solve(i, j) == solve(i + 1, j - 1)) { matchPair.push_back(make_tuple(i, j, '|')); i++; j--; }
		else if (solve(i, j) == solve(i + 1, j) + 1) { matchPair.push_back(make_tuple(i, -1, ' ')); i++; }
		else if (solve(i, j) == solve(i, j - 1) + 1) { matchPair.push_back(make_tuple(-1, j, ' ')); j--; }
		else if (solve(i, j) == solve(i + 1, j - 1) + 1) { matchPair.push_back(make_tuple(i, j, ' ')); i++; j--; }

	}
	while (i < j){
		if (sequence[i] == sequence[j]) { matchPair.push_back(make_tuple(i, j, '|')); i++; j--; }
		else break;
	}
}

void main(){
	ifstream openFile("soybean5Kseq_clean.fa.txt");
	vector<string> oneLineOfSequence;
	while (!openFile.eof()){
		string oneLine;
		getline(openFile, oneLine);
		oneLineOfSequence.push_back(oneLine);
	}
	openFile.close();
	//string soybeanSequence;
	for (int i = 1; i <= 101; ++i)
		soybeanSequence += oneLineOfSequence[i];

	//int l = 200, m = 4, h = 20;
	memset(cache, -1, sizeof(cache));

	solve(0, soybeanSequence.size()-1);
// 	vector<pair<short, short> > result;
// 	for (int i = 0; i < soybeanSequence.size(); ++i)
// 		for (int j = i + 200 - 1; j < soybeanSequence.size(); ++j){
// 			if ((j - i + 1 >= 200) && solve(i, j) < m) result.push_back(make_pair(i, j));
// 		}
// 
// 	int maxIndex = 0; int lengthOflongest = 0;
// 	if (!result.empty()){
// 		for (int i = 0; i < result.size(); ++i){
// 			if (lengthOflongest < solve(result[i].first, result[i].second)) { lengthOflongest = solve(result[i].first, result[i].second); maxIndex = i; }
// 		}
// 	}
// 	int i = result[maxIndex].first, j = result[maxIndex].second;
// 	vector<tuple<int, int, char> > matchPair;
// 	makePair(i, j, soybeanSequence, matchPair);
// 
// 	int numOfInsAndDel;
// 	if (!matchPair.empty()){
// 		for (int i = 0; i < matchPair.size(); ++i)
// 			if (get<0>(matchPair[i]) == -1 || get<1>(matchPair[i]) == -1) numOfInsAndDel++;
// 	}

// 	int loop_length = j - i + 1 - (matchPair.size() * 2 - numOfInsAndDel);
// 	cout << "i=" << i << ",j=" << j << ", length=" << j - i + 1 << ", loop_length=" << j - i + 1 - (matchPair.size() * 2 - numOfInsAndDel) << ",miss=" << solve(i, j) << endl;
// 	for (int i = 0; i < matchPair.size(); ++i){
// 		if (get<0>(matchPair[i]) == -1) cout << '-';
// 		else cout << get<0>(matchPair[i]);
// 	}
// 	for (int k = i + matchPair.size(); k < i + matchPair.size() + loop_length; ++k)
// 		cout << soybeanSequence[k];
// 	cout << endl;
// 	for (int k = 0; k < matchPair.size(); ++k)
// 		cout << get<2>(matchPair[i]);
// 	cout << endl;
// 	for (int k = j; k >= i + matchPair.size() + loop_length; --j){
// 		if (get<1>(matchPair[i]) == -1) cout << '-';
// 		else cout << get<1>(matchPair[i]);
// 	}
}