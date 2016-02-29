/*
 * File: graphexercise.cpp
 * -------------------------
 * This file exercise of the graph.
 * Reader - Chapter 18
 */

#include "graph.h"
#include <fstream>
#include <string>
#include "strlib.h"
#include "tokenscanner.h"

using namespace std;

struct arcT;
struct nodeT;

struct nodeT 
{
	string name;
	Set<arcT *> arcs;
};

struct arcT
{
	int distance;
	nodeT *start;
	nodeT *finish;	
};

void readGraph(Graph<nodeT, arcT> & g, ifstream & infile);
void graphAddNode(Graph<nodeT, arcT> & g, string & str);
void writeGraph(Graph<nodeT, arcT> & g, ofstream & outfile);

int main()
{

	Graph<nodeT, arcT> g;

	ifstream infile;
	ofstream outfile;
	// infile.open("airlines.txt");
	readGraph(g, infile);
	writeGraph(g, outfile);


	return 0;
}

void readGraph(Graph<nodeT, arcT> & g, ifstream & infile) {
	infile.open("airlines.txt");
	string line;
	
	while(getline(infile,line)) {

		// for(int i = 0; i < line.length(); i++) {
		// 	cout << i << " : " << line[i] << endl;
		// }

		string node1Name = "";
		string node2Name = "";
		int distance = 0;

		int hyphen = line.find("-");
		int parenStart = line.find("(");
		int parenEnd = line.find(")");

		// get distance of two nodes.
		if(parenStart != string::npos) {
			string disStr = line.substr(parenStart + 1,parenEnd - parenStart - 1);
			distance = stringToInteger(disStr);
		}

		// check whether is only node
		if(hyphen != string::npos) {
			node1Name = trim(line.substr(0, hyphen));
			graphAddNode(g, node1Name);
			nodeT *np1 = g.getNode(node1Name);
			
			// check bidirection
			if(line[hyphen + 1] == '>') {
				node2Name = trim(line.substr(hyphen + 2, parenStart - hyphen - 2));
				graphAddNode(g, node2Name);
				nodeT *np2 = g.getNode(node2Name);
				arcT *arc1 = new arcT();
				arc1->distance = distance;
				arc1->start = np1;
				arc1->finish = np2;
				np1->arcs.add(arc1);
				np2->arcs.add(arc1);
				g.addArc(arc1);
			}
			else {
				node2Name = trim(line.substr(hyphen + 1, parenStart - hyphen - 1));
				graphAddNode(g, node2Name);
				nodeT *np2 = g.getNode(node2Name);
				arcT *arc1 = new arcT();
				arc1->distance = distance;
				arc1->start = np1;
				arc1->finish = np2;
				np1->arcs.add(arc1);
				np2->arcs.add(arc1);
				g.addArc(arc1);
				arcT *arc2 = new arcT();
				arc2->distance = distance;
				arc2->start = np2;
				arc2->finish = np1;
				np1->arcs.add(arc2);
				np2->arcs.add(arc2);
				g.addArc(arc2);
			}
		} else {
			node1Name = line;
			graphAddNode(g, node1Name);
		}
	}

	cout << g.toString() << endl;
	infile.close();
}


void graphAddNode(Graph<nodeT, arcT> & g, string & str) {
	nodeT *node = g.getNode(str);
	if(node == NULL) {
		g.addNode(str);
	}
}

void writeGraph(Graph<nodeT, arcT> & g, ofstream & outfile) {
	// outfile.open("airGraphs.txt");
	// foreach (nodeT *node in g.getNodeSet()) {
		foreach(arcT *arc in g.getArcSet()) {
			cout << arc->start->name << " -> " << arc->finish->name << " ("
				<< arc->distance << ")" << endl;
		}
	// }
}