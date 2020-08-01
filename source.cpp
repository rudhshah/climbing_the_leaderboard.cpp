#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int l, int r, int x)
{
	int max = r;
	if (r >= l && r <= max ) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle 
		// itself 
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (arr[mid] < x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(arr, mid + 1, r, x);
	}
	else
	{
		return r;
	}

}
int main() {
	int num_players, num_rounds;
	int temp;
	cin >> num_players;

	vector<int> scores;
	vector<int> ranks;
	scores.resize(num_players);
	ranks.resize(num_players);
	ranks[0] = 1;
	for (int i = 0; i < num_players; i++) {
		cin >> temp;
		scores[i] = temp;
		
		if (i != 0) {
			if (scores[i] == scores[i - 1]) {
				ranks[i] = ranks[i - 1];
			}
			else {
				ranks[i] = ranks[i - 1] + 1;
			}
		}
	}//for


	cin >> num_rounds;

	for (int i = 0; i < num_rounds; i++) {
		cin >> temp;
		if (num_players < 150) {
			for (int j = num_players - 1; j >= 0; j--) {
				if (temp < scores[j]) {
					if (temp == scores[j]) {
						cout << ranks[j] << endl;
					}
					else
					{
						cout << ranks[j] + 1 << endl;
					}
					break;
				}
				else if (j == 0) {
					cout << "1" << endl;
				}
			}
		}
		else {

			if (temp > scores[0]) {
				cout << "1" << endl;
				break;
			}
			int x = binarySearch(scores, 0, num_players - 1, temp);
			if (scores[x] == temp) {
				cout << ranks[x] << endl;
			}
			else {
				cout << ranks[x] + 1 << endl;
			}
		}
	}

	return 0;
}

//Did you get the catch?????
