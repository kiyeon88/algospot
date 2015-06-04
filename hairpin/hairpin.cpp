#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#include<math.h>

#define INF 6500

using namespace std;

int cache[6500][6500];
int l = 200, m = 10, h = 30;
//l=minimum length of the hairpin structure
//m=maximum number of miss(mismatch or insertion or deletion)
//h=maximum length of the loop length


string soybeanSequence;
bool pairRule(char a, char b){
	if (((a == 'A' || a == 'a')&&(b == 'T' || b == 't')) || 
		((a == 'T' || a == 't')&&(b == 'A' || b == 'a')) || 
		((a == 'C' || a == 'c')&&(b == 'G' || b == 'g')) || 
		((a == 'G' || a == 'g')&&(b == 'C' || b == 'c'))) return true;
	else return false;
}

int solve(int i, int j){
	int& ret = cache[i][j];
	if (ret != -1) return ret;
	if (j - i + 1 <= h) return ret = 0;
	else if (pairRule(soybeanSequence[i], soybeanSequence[j])) { return ret = solve(i + 1, j - 1); }
	else { return ret = min(min(solve(i + 1, j) + 1, solve(i, j - 1) + 1), solve(i + 1, j - 1) + 1); }
}


void makePair(int i, int j, string& sequence, vector<tuple<int, int, char> >& matchPair){
	
	while (j - i + 1 > h){
		if (solve(i, j) == solve(i + 1, j - 1)&&pairRule(sequence[i], sequence[j])) { matchPair.push_back(make_tuple(i, j, '|')); i++; j--; }
		else if (solve(i, j) == solve(i + 1, j) + 1) { matchPair.push_back(make_tuple(i, -1, ' ')); i++; }
		else if (solve(i, j) == solve(i, j - 1) + 1) { matchPair.push_back(make_tuple(-1, j, ' ')); j--; }
		else if (solve(i, j) == solve(i + 1, j - 1) + 1) { matchPair.push_back(make_tuple(i, j, ' ')); i++; j--; }

	}
	while (i < j){
		if (pairRule(sequence[i], sequence[j])) { matchPair.push_back(make_tuple(i, j, '|')); i++; j--; }
		else break;
	}
}

int parse_cmd(int argc, char** argv, char*& inputFile, int& minLengthOfHairpin, int& maxNumOfMiss, int& maxLengthOfLoop){
	for (int i = 1; i < argc; ++i){
		if (strcmp(argv[i], "-input") == 0){
			inputFile = argv[i + 1];
			break;
		}
	}
	for (int i = 1; i < argc; ++i){
		if (strcmp(argv[i], "-l") == 0){
			minLengthOfHairpin = atoi(argv[i + 1]);
			break;
		}
	}
	for (int i = 1; i < argc; ++i){
		if (strcmp(argv[i], "-m") == 0){
			maxNumOfMiss = atoi(argv[i + 1]);
			break;
		}
	}
	for (int i = 1; i < argc; ++i){
		if (strcmp(argv[i], "-h") == 0){
			maxLengthOfLoop = atoi(argv[i + 1]);
			break;
		}
	}
	return 0;
}

int main(int argc, char** argv){
	char* inputFile; 
	if (parse_cmd(argc, argv, inputFile, l, m, h) < 0) return 0;

	//ifstream openFile("soybean5Kseq_clean.fa.txt");
	ifstream openFile(inputFile);
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

	//solve(0, soybeanSequence.size()-1);
	vector<pair<int, int> > result;
	for (int lengthOfSeq = 1; lengthOfSeq <= soybeanSequence.size(); ++lengthOfSeq)
		for (int start = 0; start+lengthOfSeq-1 < soybeanSequence.size(); ++start){
			solve(start, start+lengthOfSeq-1);
			if ((lengthOfSeq >= l) && (solve(start, start+lengthOfSeq-1) <= m)) 
				result.push_back(make_pair(start, start+lengthOfSeq-1));
		}

	int maxIndex = 0; int lengthOflongest = 0;
	if (!result.empty()){
		for (int i = 0; i < result.size(); ++i){
			if (lengthOflongest < result[i].second - result[i].first + 1) { lengthOflongest = result[i].second - result[i].first + 1; maxIndex = i; }
		}
	}
	
	int start = result[maxIndex].first, end = result[maxIndex].second; int miss = solve(start, end);
	vector<tuple<int, int, char> > matchPair;
	makePair(start, end, soybeanSequence, matchPair);

	int numOfInsAndDel = 0;
	if (!matchPair.empty()){
		for (int i = 0; i < matchPair.size(); ++i)
			if (get<0>(matchPair[i]) == -1 || get<1>(matchPair[i]) == -1) numOfInsAndDel++;
	}

	int loop_length = end - start + 1 - (matchPair.size() * 2 - numOfInsAndDel);

	
	if (!result.empty())
	{
		cout << "i=" << start << ", j=" << end << ", length=" << end - start + 1 << ", loop_length=" << loop_length << ", miss=" << miss << endl;
		for (int k = 0; k < matchPair.size(); ++k){
			if (get<0>(matchPair[k]) == -1) cout << '-';
			else cout << soybeanSequence[get<0>(matchPair[k])];
		}
		cout << ' ';
		for (int k = get<0>(matchPair[matchPair.size() - 1]) + 1; k < get<0>(matchPair[matchPair.size() - 1]) + 1 + loop_length; ++k)
			cout << soybeanSequence[k];
		cout << endl;

		for (int k = 0; k < matchPair.size(); ++k)
			cout << get<2>(matchPair[k]);
		cout << endl;
		for (int k = 0; k < matchPair.size(); ++k){
			if (get<1>(matchPair[k]) == -1) cout << '-';
			else cout << soybeanSequence[get<1>(matchPair[k])];
		}
		cout << endl;
	}
	else
		cout << "NO HAIRPIN" << endl;


	return 0;
}