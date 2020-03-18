#include <iostream>
#include <vector>
using namespace std;
bool is_size_ok(int size) {
	const int max_size = 1024;
	if (size <= 0 || size > max_size) {
        cerr << "fibon_seq(): oops: invalid size: "
		<< size << " -- can't fulfill request.\n";
		return false;
	}	
	return true;
}
const vector<int>* fibon_seq(int size) {
	const int max_size = 1024;
	static vector<int> elems; // 定义一个局部静态对象，用来存截至到size的斐波那契数
	if (! is_size_ok(size)) 
		return 0;
	// 如果size小于elem.size()，那么已经存好了，不用再重新计算，会直接跳过for循环
	for (int ix = elems.size(); ix < size; ++ix) {
		if (ix == 0 || ix == 1)
			elems.push_back(1);
		else elems.push_back(elems[ix - 1] + elems[ix - 2]);
	}
	return &elems;
}
bool fibon_elem(int pos, int &elem) {
	const vector<int> *pseq = fibon_seq(pos);
	if (!pseq) {
		elem = 0;
		return false;
	}
	elem = (*pseq)[pos - 1];
	return true;
}
bool print_sequence(int pos) {
	if (pos <= 0 || pos > 1024) {
		cerr << "Invalid position: " << pos
			<< " -- cannot handle request!\n";
		return false;
	}
	cout << "The fibonacci Sequence for "
		<< pos << " positions:\n\t";
	switch (pos) {
	default:
	case 2:
		cout << "1 ";
	case 1:
		cout << "1 ";
		break;
	}
	int elem;
	int n_2 = 1, n_1 = 1;
	for (int ix = 3; ix <= pos; ++ix) {
		elem = n_2 + n_1;
		n_2 = n_1, n_1 = elem;
		cout << elem << ((!ix % 10) ? "\n\t" : " ");
	}
	cout << endl;
	return true;
}
int main() {
	int pos;
	cout << "Please enter a position:";
	cin >> pos;
	int elem;
	if (fibon_elem(pos, elem))
		cout << "element # " << pos
		<< " is " << elem << endl;
	else
	{
		cout << "Sorry. Could not calculate element # "
			<< pos << endl;
	}
	print_sequence(pos);
	return 0;
}