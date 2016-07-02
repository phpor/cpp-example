#include<iostream>
#include<string>
using namespace std;

int hanoyi(int n, string p1, string p2, string p3) {
	int count = 0;
	if (n == 1) {
		cout << n << ": " << p1 << " -> " << p3 << endl;
		count++;
	} else {
		count += hanoyi(n-1, p1, p3, p2);
		cout << n << ": " << p1 << " -> " << p3 << endl;
		count++;
		count += hanoyi(n-1, p2, p1, p3);
	}
	return count;
}
int main(int ac, char**av) {
	int count;
	count = hanoyi(stoi(av[1]), "A", "B", "C");
	cout << "count: " << count <<endl;
	return 0;
}
