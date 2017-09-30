#pragma once
#include <iostream>
using namespace std;
namespace utility {
	/*
	* http://www.geeksforgeeks.org/evaluation-of-expression-tree/
	*/
	namespace tree {
		struct Node {
			int value;
			Node* left;
			Node* right;
		};

		enum Traversal {
			PRE,
			IN,
			POST,
			Bottom,
			Diagonal,
			ExtremAlternate,
			LevelOrder,
			LeftView,
			Boundary, // http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
		};

		class IntegerTree {
		public:
			IntegerTree(int* arr, int size, bool(*leftAddPredicate)(int newValue, int nodeValue));

			void createNode(Node * node, int value);

			virtual ~IntegerTree() {

			}
			void preVisit(Node* node, void(*funcPtr)(Node*));
			void inVisit(Node * node, void(*funcPtr)(Node *));
			void postVisit(Node * node, void(*funcPtr)(Node *));
			void traverse(Traversal way, void(*funcPtr)(Node*));
			Node* findInBst(Node* startNode,int value);
			Node* insertInBst(int value, bool(*leftAddPredicate)(int newValue, int nodeValue));
			void removeInBst(Node *startNode, int value);
			int getMaxHeight();
			bool isBST();
			bool isBalanced();
			void getLowestCommonAncestor(int value1, int value2);
			int getDistance(int value1, int value2);
			Node* getInorderSuccessor(int value);
			Node* getLargestBST();
			Node* toBSTfromBT();
			Node* converToSumTree(); // http://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
			int getMaxLevelSum();
			static bool isIdentical(Node* roo1, Node* root2);
			static string serialize(Node*);
			static Node* deserialize(string);
			int getKthSmallest();
			static int allPossibleBST(int* array, int size); // [NF]
			Node* getRoot() { return rootPtr; };
		private:
			void createTree(int* arr, int size, bool(*leftAddPredicate)(int newValue, int nodeValue));
			Node* addNode(int * arr, int size, int index);
			Node* getNextToSwap(Node* node);
			Node* getParentOf(Node* startNode, Node* node);
			Node* rootPtr;
		};
	}
}