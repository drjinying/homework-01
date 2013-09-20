/*
 * Author: Shone JIN, 11061128
 * Sept. 19, 2013. Version 1.1
 */

#include <fstream>
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int *a, int l)
{
	int tmp = a[0];
	for (; l > 0; l--){
		if (a[l] < tmp){
			tmp = a[l];
		}
	}
	return tmp;
}
int sum_max(int * a, int l)
{
	int max_former, max_updated;
	max_former = min(a, l);
	max_updated = max_former;

	for (int i = 0; i <= l; i++){
		max_updated = max(max_updated + a[i], a[i]);
		max_former = max(max_former, max_updated);
	}
	return max_former;
}

int main()
{
	int array[100];
	int i = 0;
	
	ifstream infile("input.txt", ios::in);
	if(! infile){
		cerr << "File Error" << endl;
		exit(1);
	}

	while(! infile.eof()){
		infile >> array[i++];
	}
	
	cout << sum_max(array, i - 1) << endl;
	return 0;
}