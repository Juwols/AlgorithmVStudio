#pragma once

#include <iostream>
using namespace std;

namespace structures {
	namespace doubleLinkedList {
		class Node {
		public:
			int _value;
			Node* _next;
			Node(int value, Node* next) : _value(value), _next(next) {

			};
			~Node() {
				cout << "Dispose !! " << _value << endl;
			};
		private:
		};

		class DoubleLinkedList {
		public:
			Node* _head;

			DoubleLinkedList() : _head(NULL) {

			};

			~DoubleLinkedList() {
			};

			void Add(Node* node) {
				if (_head != NULL) {
					node->_next = _head;
					_head = node;
				}
				else _head = node;
			};
			void Print() {
				Node* tmp = _head;

				if (tmp == NULL) cout << "Empty !!!" << endl;

				while (tmp != NULL) {
					cout << tmp->_value << " , ";
					tmp = tmp->_next;
				}
				cout << "" << endl;
			};

			void Remove(int value) {
				if (_head == NULL) return;
				Node* tmp = _head;
				Node* prv = NULL;

				while (tmp != NULL) {
					if (tmp->_value == value) {
						if (tmp == _head) {
							_head = tmp->_next;
						}
						else if (tmp->_next == NULL) {
							prv->_next = NULL;
						}
						else {
							prv->_next = tmp->_next;
						}
						delete tmp;
						break;
						// if tail
					}
					else {
						prv = tmp;
						tmp = tmp->_next;
					}
				}
			};
		private:
		};
	}
}
