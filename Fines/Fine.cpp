#include "Fine.h"
#include<iostream>
using namespace std;
void Fine::setName(const string& name)
{
	this->name = name;
}

const string& Fine::GetName()
{
	return name;
}

void Fine::setDate(const string& date)
{
	this->date = date;
}

const string& Fine::GetDate()
{
	return date;
}

void Fine::setSum(float& sum)
{
	this->sum = sum;
}

float Fine::GetSum()
{
	return sum;
}

bool CarNode::isEmpty() const
{
	return root==nullptr;
}

void CarNode::AddNode(int number, Fine* fine)
{
    Node* add = new Node{ number};
	if (isEmpty()) {
		add->fines.push_back(fine);
		root = add;
		return;
	}
	Node* tmp= root;
	bool found = false;
	while (!found) {
		if (number == tmp->number) {
			tmp->fines.push_back(fine);
			found = true;
		}
		if (number < tmp->number) {
			if (tmp->left == nullptr) {
				tmp->left = add;
				add->fines.push_back(fine);
				add->parent = tmp;
				found = true;
			}
			else {
				tmp = tmp->left;
			}
		}
		else if(number>tmp->number) {
			if (tmp->right == nullptr) {
				tmp->right = add;
				add->fines.push_back(fine);
				add->parent = tmp;
				found = true;
			}
			else {
				tmp = tmp->right;
			}
		}
		
	}
}

void CarNode::print() const
{
	printHelper(root);
}

auto CarNode::fineNode(Node* node, int d)
{
	if (node == nullptr) {
		return (Node*)nullptr;
	}
	if (node->number == d)
		return node;

	if (d < node->number) {
		return fineNode(node->left, d);
	}
	else {
		return fineNode(node->right, d);
	}
}

void CarNode::printByNumber(int number)
{
	if (isEmpty()) {
		cout << "Fine not found" << endl;
	}
	cout << "Number->" << number << endl;
	fineNode(root, number)->show();
	
}

void CarNode::deleteByNumber(int number)
{
	if (root == nullptr) {
		cout << "Fine not found" << endl;
		return;
	}
	else
		delete fineNode(root, number);
}


	
void CarNode::printHelper(Node* p) const
{
	if (p != nullptr) {
		printHelper(p->left);
		cout <<"Number->"<<p->number<< "\n";
		p->show();
		printHelper(p->right);

	}
}




