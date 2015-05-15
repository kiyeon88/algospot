#include<vector>
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include"omp.h"

using namespace std;

vector<vector<int>> adj;
vector<string> graph[26][26];
vector<int> indegree, outdegree;

void makeGraph(const vector<string>& words){
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			graph[i][j].clear();
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);

	for (int i = 0; i < words.size(); ++i){
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		outdegree[a]++;
		indegree[b]++;
	}
}

void getEulerCircuit2(int here, vector<int>& circuit){
	for (int there = 0; there<adj.size(); ++there)
		while (adj[here][there] > 0){
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit2(there, circuit);
		}
	circuit.push_back(here);
}

void getEulerCircuit(int here, vector<int>& circuit){
	for (int there = 0; there < adj.size(); ++there)
		while (adj[here][there] > 0){
			adj[here][there]--;
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here);
}

vector<int> getEulerTrailOrCircuit(){
	vector<int> circuit;
	for (int i = 0; i < 26; ++i)
		if (outdegree[i] == indegree[i] + 1){
			getEulerCircuit(i, circuit);
			return circuit;
		}
	for (int i = 0; i < 26; ++i)
		if (outdegree[i]){
			getEulerCircuit(i, circuit);
			return circuit;
		}
	return circuit;

}
bool checkEuler(){
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; ++i){
		int delta = outdegree[i] - indegree[i];
		if (delta < -1 || 1 < delta) return false;
		if (delta == 1) plus1++;
		if (delta == -1) minus1++;

	}
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}
string solve(const vector<string>& words){
	makeGraph(words);
	if (!checkEuler()) return "IMPOSSIBLE";
	vector<int> circuit = getEulerTrailOrCircuit();
	if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";

	reverse(circuit.begin(), circuit.end());
	string ret;
	for (int i = 1; i < circuit.size(); i++) {
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size()) ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;
}

vector<int> discovered, finished;
int counter;
void dfs2(int here){
	discovered[here] = counter++;
	for (int i = 0; i < adj[here].size(); ++i){
		int there = adj[here][i];
		cout << "(" << here << "," << there << ") is a ";
		if (discovered[there] == -1){
			cout << "tree edge" << endl;
			dfs2(there);
		}
		else if (discovered[here] < discovered[there])
			cout << "forward edge" << endl;
		else
			cout << "cross edge" << endl;
	}
	finished[here] = 1;
}

int main(){
	int cases;
	cin >> cases;
	while (cases--){
		int wordsCount;
		cin >> wordsCount;
		vector<string> words(wordsCount);
		cin.ignore();
		while (wordsCount--){
			getline(cin, words[words.size() - 1 - wordsCount]);
		}
		string result;
		result=solve(words);
		cout << result << endl;

	}

	return 0;
}