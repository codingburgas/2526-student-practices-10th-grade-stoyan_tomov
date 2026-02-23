#include <iostream>
#include <fstream>
using namespace std;

void print()
{
	cout << ifstream("CinemaMenu.txt").rdbuf();
}
int main()
{
	print();
}