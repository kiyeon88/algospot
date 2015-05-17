#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
// int cache[101][101];
// string W, S;
// bool matchMemoized(int w, int s){
// 	int& ret = cache[w][s];
// 	if (ret != -1) return ret;
// 	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])){
// 		++w; ++s;
// 	}
// 	if (w == W.size()) return ret = (s == S.size());
// 	if (W[w] == '*')
// 	for (int skip = 0; skip + s <= S.size(); ++skip)
// 		if (matchMemoized(w + 1, s + skip))
// 			return ret = 1;
// 	return ret = 0;
// }
// bool match(const string& w, const string& s){
// 	int pos = 0;
// 	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) ++pos;
// 	if (pos == w.size()) return pos == s.size();
// 	if (w[pos] == '*')
// 		for (int skip = 0; pos + skip <= s.size(); ++skip)
// 			if (match(w.substr(pos + 1), s.substr(pos + skip))) 
// 				return true;
// 	return false;
// }


bool match(const string wildCard, const string fileName){
	int pos = 0;
	while (pos < wildCard.size() && pos < fileName.size() && (wildCard[pos] == '?' || wildCard[pos] == fileName[pos])) ++pos;
	if (pos == wildCard.size()) return pos == fileName.size();
	else if (pos == fileName.size()) return false;
	if (wildCard[pos] != fileName[pos]) return false;
	
	
	if (wildCard[pos] == '*')
	for (int skip = 0; skip + pos <= wildCard.size(); ++skip)
	if (match(wildCard.substr(pos + 1), fileName.substr(pos + skip))) return true;

	//return false;
}

int cache[101][101];
string wildCard, fileName;
bool matchMemoized(int posOfWild, int posOfFile){
	int& ret = cache[posOfWild][posOfFile];
	if (ret != -1) return ret;
	while (posOfWild < wildCard.size() && posOfFile < fileName.size() && (wildCard[posOfWild] == '?' || wildCard[posOfWild] == fileName[posOfFile])){
		++posOfWild; ++posOfFile;
	}
	if (posOfWild == wildCard.size()) return ret = (posOfFile == fileName.size());
	if (wildCard[posOfWild] == '*')
		for (int skip = 0; skip + posOfWild <= wildCard.size(); ++skip)
			if (matchMemoized(posOfWild + 1, posOfFile + skip)) return ret = 1;
	return ret=0;
}
void solve(string wildCard, vector<string> fileNames, vector<string>& ret){
	vector<int> posOfStar;
	vector<int> posOfQuestion;
	for (int i = 0; i < wildCard.length(); ++i){
		if (wildCard[i] == '*') posOfStar.push_back(i);
		else if (wildCard[i] == '?') posOfQuestion.push_back(i);
	}
}

int main(){
	int cases; cin >> cases;
	while (cases--){
		string wildCard;
		cin >> wildCard;
		int numOfFiles; cin >> numOfFiles;
		vector<string> fileNames(numOfFiles);
		int count = 0;
		while (numOfFiles--){
			cin >> fileNames[count++];

		}
		vector<string> result;
		for (int i = 0; i < fileNames.size(); ++i){
			if (match(wildCard, fileNames[i])) cout << fileNames[i] << endl;
// 			memset(cache, -1, sizeof(cache));
// 			W = wildCard; S = fileNames[i];
// 			
// 			if (matchMemoized(0, 0)) result.push_back(fileNames[i]);

		}
// 		sort(result.begin(), result.end());
// 		for (int i = 0; i < result.size(); ++i)
// 			cout << result[i] << endl;

	}
	return 0;
}


