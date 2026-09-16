#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

void obhod(int v, const vector<vector<int>>& matrix, vector<bool>& visited, list<int>& order) {
	visited[v] = true;
	for (int to = 0; to < matrix.size(); to++) {
		if (matrix[v][to] == 1 && !visited[to]) {
			obhod(to, matrix, visited, order);
		}
	}
	order.push_front(v);
}
int main() {
	setlocale(LC_ALL, "Russian");

	ifstream in("D:\\1.txt");
	int n;
	in >> n;
	vector<vector<int>> matrix(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			in >> matrix[i][j];
		}
	}

	vector<bool> visited(n, false);
	list<int> order;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			obhod(i, matrix, visited, order);
		}
	}

	cout << "Топологический порядок вершин:" << endl;

	for (int v : order) {
		cout << v + 1 << " ";
	}
	cout << endl;

	return 0;
}