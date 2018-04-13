//============================================================================
// Name        : Random Cut Search.cpp
// Author      : Sujeendran Menon
// Version     : 1.0
// Copyright   : All rights reserved to Sujeendran Menon
// Description : RCSearch vs BSearch Comparison, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("RCS_log.txt", fstream::app);
int bsearch(int num, int l, int a[]) {
	fout << "<Binary Search>" << endl;
	int s, e, mid, steps = 0;
	s = 1, e = l, mid = l / 2;
	fout << "Search range: " << s << "-" << e << endl;
	while (a[mid] != num && s <= e) {
		if (a[mid] < num) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
		mid = (s + e) / 2;
		fout << "Search range: " << s << "-" << e << endl;
		steps++;
	}
	if (a[mid] == num) {
		fout << "Found" << endl;
		steps++;
	}
	return steps;
}
int rcsearch(int num, int l, int a[]) {
	fout << "<Random Cut Search>" << endl;
	srand(time(NULL));
	int s, e, mid, steps = 0;
	s = 1, e = l;
	mid = rand() % (e - s + 1) + s;
	fout << "Search range: " << s << "-" << e << endl;
	while (a[mid] != num && s <= e) {
		if (a[mid] < num) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
		mid = rand() % (e - s + 1) + s;
		fout << "Search range: " << s << "-" << e << endl;
		steps++;
	}
	if (a[mid] == num) {
		fout << "Found" << endl;
		steps++;
	}
	return steps;
}
int main() {
	int l, num, a[10000];
	int draws = 0, bscore = 0, rcscore = 0;
	int bssteps, rcsteps;
	int t,c=1;
	fin >> t;
	time_t now = time(0);
	char* dt = ctime(&now);
	fout<<"\nTest Time: +4 GMT\n"<<dt;
	while (c <= t) {
		fout<<"\nCase "<<c<<": \n";
		fin >> num >> l;
		fout<<"Number to search: "<<num<<"\nSample Set Size: "<<l<<endl;
		for (int i = 1; i <= l; i++) {
			fin >> a[i];
		}
		bssteps = bsearch(num, l, a);
		rcsteps = rcsearch(num, l, a);
		fout << "Iterations to complete: \nUsing Binary Search Method: "
				<< bssteps << endl << "Using Random Cut Search Method: "
				<< rcsteps << endl;
		if (bssteps < rcsteps)
			bscore++;
		else if (rcsteps < bssteps)
			rcscore++;
		else
			draws++;
		c++;
	}

	fout << "<FINAL TEST SCORES>\nBinary Search: " << bscore
			<< "\nRandom Cut Search: " << rcscore << "\nDraws: " << draws
			<< endl;
	cout << "<FINAL TEST SCORES>\nBinary Search: " << bscore
				<< "\nRandom Cut Search: " << rcscore << "\nDraws: " << draws
				<< endl;
	return 0;
}
