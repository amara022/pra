#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<deque>
#include<map>
#include<set>
#include<stack>
#include<vector>
using namespace std;


class StateTransitionDiagram
{
public:
	StateTransitionDiagram();//constructor
	StateTransitionDiagram(int s);//constructor with a initial value
	int getNode();//get the value of the node
	multimap<char, int> getTransitionMatrix();//get the transition matrix
	void addTransition(char val, int n);//add transition to the current node
	void print();//print the graph
private:
	int node; //the number of the node
	multimap<char, int>transitionMatrix;//record the state transition
};


StateTransitionDiagram::StateTransitionDiagram()
{
	node = 0;
}

StateTransitionDiagram::StateTransitionDiagram(int n)
{
	node = n;
}

int StateTransitionDiagram::getNode()
{
	return node;
}

multimap<char, int> StateTransitionDiagram::getTransitionMatrix()
{
	return transitionMatrix;
}

void StateTransitionDiagram::addTransition(char v, int n)
{
	transitionMatrix.insert(make_pair(v, n));
}

void StateTransitionDiagram::print()
{
	for (multimap<char, int>::iterator it = transitionMatrix.begin(); it != transitionMatrix.end(); ++it)
		cout << "node:" << node << "   edge value:" << it->first << "  node:" << it->second << endl;
}


#define EPSILON '#'
typedef deque<StateTransitionDiagram*>NFA; //define NFA with a deque,and the type of the element in the deque id StateTransitionDiagram
typedef deque<StateTransitionDiagram*>DFA;//same with NFA
typedef set<int>::iterator set_it;
typedef multimap<char, int>::iterator multimap_it;
void NFAtoDFA();                                         //determine the NFA with subset method
set<int> epsilonClosure(set<int> &s);             //epsilon closure
multimap<char, int> getTranMatrix(int n);        //get the transition matrix of the node n
set<int>getSet(set<int>&, char);                      //get set when input a char
bool getUnhandled(multimap<set<int>, int>::iterator &it);  //judge whether the node is handled
map<set<int>, int>dfaTran;                             //transition in the dfa
set<char> inputChar;                                       //input char
vector<int>dfaT;
vector<int>nfaT;

NFA nfa;                                                        //nfa
DFA dfa;                                                        //dfa

int main()
{
	StateTransitionDiagram *n0 = new StateTransitionDiagram();
	StateTransitionDiagram *n1 = new StateTransitionDiagram(1);
	n0->addTransition('a', 0);
	n0->addTransition('b', 1);
	n1->addTransition('a', 1);
	n1->addTransition('a', 0);
	n1->addTransition('b', 0);
	inputChar.insert('a');
	inputChar.insert('b');
	nfa.push_back(n0);
	nfa.push_back(n1);
	nfaT.push_back(1);
	NFAtoDFA();
	cout << "---------------------------NFA----------------------------" << endl;
	for (NFA::iterator it = nfa.begin(); it != nfa.end(); ++it)
		(*it)->print();
	cout << "Terminal statein NFA:";
	for (vector<int>::iterator it = nfaT.begin(); it != nfaT.end(); ++it)
		cout << *it << "   ";
	cout << endl;
	cout << "---------------------------DFA----------------------------" << endl;
	for (DFA::iterator it = dfa.begin(); it != dfa.end(); ++it)
		(*it)->print();
	cout << "Terminal statein NFA:";
	for (vector<int>::iterator it = dfaT.begin(); it != dfaT.end(); ++it)
		cout << *it << "   ";
	cout << endl;
	return 0;
}

multimap<char, int> getTranMatrix(int n)
{
	multimap<char, int>multim;
	NFA::iterator it;
	//find the postion of the node n
	for (it = nfa.begin(); it != nfa.end(); ++it)
	{
		if (n == (*it)->getNode())
		{
			multim = (*it)->getTransitionMatrix();
			break;
		}
	}
	return multim;
}

set<int>epsilonClosure(set<int> &s)
{
	set<int> closureSet = s;   //first, add the initial set to the closure set
	stack<int>nodeStack;      //save all the node
	int currentNode;              //the node being handling
	for (set_it it = closureSet.begin(); it != closureSet.end(); ++it)
		nodeStack.push(*it);
	while (!nodeStack.empty())
	{
		//get the node in the top of the state stack
		currentNode = nodeStack.top();
		nodeStack.pop();
		//get the transition matrix
		multimap<char, int> tranMax = getTranMatrix(currentNode);
		for (multimap_it it = tranMax.begin(); it != tranMax.end(); ++it)
		{
			//if the edge is epsilon and the node is not included in the set,then add the node 
			if (it->first == EPSILON && closureSet.find(it->second) == closureSet.end())
			{
				closureSet.insert(it->second);
				nodeStack.push(it->second);
			}
		}
	}
	return closureSet;
}

set<int>getSet(set<int> &s, char ch)
{
	set<int>ss;
	stack<int>nodeStack;
	multimap<char, int>mmap;
	for (set_it it = s.begin(); it != s.end(); ++it)
		nodeStack.push(*it);
	while (!nodeStack.empty())
	{
		//get the transition matrix
		mmap = getTranMatrix(nodeStack.top());
		nodeStack.pop();
		for (multimap_it it = mmap.begin(); it != mmap.end(); ++it)
		{
			//if match the ch,then add it into the set
			if (it->first == ch)
			{
				ss.insert(it->second);
			}
		}
	}
	return ss;
}

bool getUnhandled(multimap<set<int>, int>::iterator &it)
{
	for (it = dfaTran.begin(); it != dfaTran.end(); ++it)
	{
		if (it->second < 0)
			return true;
	}
	return false;
}

void NFAtoDFA()
{
	//initiate dfa with the initial state of nfa
	set<int> s;
	s.insert(0);
	dfaTran.insert(make_pair(s, 0));
	map<set<int>, int>::iterator map_it = dfaTran.begin();
	//constructor the DFA
	do
	{
		s = map_it->first;
		map_it->second = abs(map_it->second);
		//create a new node, if map_it is negtive,the state is not handled,otherwise,handled
		StateTransitionDiagram *sTranNode = new StateTransitionDiagram(map_it->second);
		dfa.push_back(sTranNode);
		//find the terminal node
		for (vector<int>::iterator it = nfaT.begin(); it != nfaT.end(); ++it)
		{
			if (s.find(*it) != s.end())
			{
				dfaT.push_back(map_it->second);
			}
		}

		for (set<char>::iterator it = inputChar.begin(); it != inputChar.end(); ++it)
		{
			set<int>tempSet = epsilonClosure(getSet(s, *it));
			if (!tempSet.empty())//if the set is empty,then no edge
			{
				if (dfaTran.find(tempSet) == dfaTran.end())
				{
					dfaTran.insert(make_pair(tempSet, -(int)dfaTran.size()));
				}
				map_it = dfaTran.find(tempSet);
				sTranNode->addTransition(*it, abs(map_it->second));
			}
		}

	} while (getUnhandled(map_it));
}
