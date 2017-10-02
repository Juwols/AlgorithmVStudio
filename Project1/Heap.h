#pragma once

#include <iostream>
#include <vector>

namespace structures {
	namespace heap {
		using namespace std;

		class Heap {
		public:
			Heap(int size) {
			}

			virtual ~Heap() {
			}

			int getParentIndex(int i) {
				if (i == 0) return -1;

				if (i % 2) return i / 2;
				else return i / 2 - 1;
			}

			int getChildIndex(bool left, int current) {
				int r;
				if (left == true) r = current * 2 + 1;
				else r = current * 2 + 2;
				if (r >= v.size()) return -1;
				else return r;
			}

			void add(int i) {
				// push back to the last of heap
				v.push_back(i);
				// now check the parent 
				int pIndex = getParentIndex(v.size() - 1);
				int cIndex = v.size() - 1;
				while (pIndex >= 0) {
					if (v[pIndex] < v[cIndex]) {
						swap(v[pIndex], v[cIndex]);
						cIndex = pIndex;
						pIndex = getParentIndex(cIndex);
					}
					else break;
				}
			}

			void removeTop() {
				swap(v[0], v[v.size() - 1]);
				cout << "return: " << v[v.size() - 1];
				int current = 0; // top   
				int toCheck;

				v.resize(v.size() - 1);
				while (true) {
					int leftIndex = getChildIndex(true, current);
					if (leftIndex == -1) {
						break;
					}
					int rightIndex = getChildIndex(false, current);
					if (rightIndex == -1) {
						toCheck = leftIndex;
					}
					else {
						toCheck = (v[leftIndex] > v[rightIndex]) ? leftIndex : rightIndex;
					}
					if (v[toCheck] > v[current]) {
						swap(v[toCheck], v[current]);
						current = toCheck;
					}
					else break;
				}
			}

			int getElement(int index) {
				return v[index];
			}

			int size() {
				return v.size();
			}

		private:
			vector<int> v;
		};

#if 0
		int main() {
			Heap h(10);
			h.add(10);
			h.add(20);
			h.add(30);
			h.add(100);
			h.add(200);
			h.add(300);
			h.add(400);
			h.add(500);
			h.add(600);
			h.add(700);
			h.add(800);

			h.removeTop();
			for (int i = 0; i < h.size(); i++) {
				cout << h.getElement(i) << " ";
			}

			800
				700           300
				400      600    20    200
				10 100  30   500

				700
				600       300
				400   500  20   200
				10 100 30

#endif
	}
}