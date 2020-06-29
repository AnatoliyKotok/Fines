#include<string>
#include<list>
#include"Fine.h"
using namespace std;

int main() {
	Fine fine("Bad", "12.12.12", 123);
	Fine fine2("Cros street", "1.2.12", 153);
	CarNode node;
	node.AddNode(1, &fine);
	node.AddNode(2, &fine);
	node.print();
	node.printByNumber(1);
	node.deleteByNumber(1);
	node.print();
}