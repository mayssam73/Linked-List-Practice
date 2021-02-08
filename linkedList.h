#pragma once

using namespace std;

struct node {
	node* next;
	string currLine;
};

class linkedList {
private:
	node* head;
	int size;

public:
	linkedList() {
		head = 0;
		size = 0;
	}

	bool isDuplicate(string line) {
		node* curr = head;
		while (curr != nullptr) {
			if (curr->currLine == line) {
				return true;
			}
			curr = curr->next;
		}
		return false;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	int getListSize() {
		return size;
	}

	void insertAlphabetical(string line){
		if (isEmpty() == true) {
			insertBeginning(line);
		}
		else {
			node* curr = head;
			node* prev = 0;
			while (curr->currLine < line && curr->next != 0) {
				prev = curr;
				curr = curr->next;
			}
			if (prev != 0) {
				if (curr->currLine > line) {
					curr = prev;
				}
				node* temp = new node;
				temp->currLine = line;
				temp->next = curr->next;
				curr->next = temp;
				size++;
			}
			else if (prev == 0 && curr->currLine < line) {
				insertEnd(line);
			}
			else if (prev == 0 && curr->currLine > line) {
				insertBeginning(line);
			}
		}
	}

	void insertLength(string line) {
		if (isEmpty() == true) {
			insertBeginning(line);
		}
		else {
			node* curr = head;
			node* prev = 0;
			while (curr->currLine.size() < line.size() && curr->next != 0) {
				prev = curr;
				curr = curr->next;
			}
			if (prev != 0) {
				if (curr->currLine.size() > line.size()) {
					curr = prev;
				}
				node* temp = new node;
				temp->currLine = line;
				temp->next = curr->next;
				curr->next = temp;
				size++;
			}
			else if (prev == 0 && curr->currLine.size() < line.size()) {
				insertEnd(line);
			}
			else if (prev == 0 && curr->currLine.size() > line.size()) {
				insertBeginning(line);
			}
		}
	}

	void insertBeginning(string line) {
		node* temp = new node;
		temp->currLine = line;
		temp->next = head;
		head = temp;
		size++;
	}

	void insertEnd(string line) {
		if (isEmpty() == true) {
			insertBeginning(line);
		}
		else {
			node* curr = head;
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			node* temp = new node;
			temp->currLine = line;
			temp->next = 0;
			curr->next = temp;
			size++;
		}
	}

	void insertAtPos(int pos, string line) {
		if (isEmpty() == true) {
			insertBeginning(line);
		}
		else {
			node* curr = head;
			if (pos == 0) {
				insertBeginning(line);
			}
			else {
				for (int i = 0; i < pos - 1; i++) {
					curr = curr->next;
				}
				node* temp = new node;
				temp->currLine = line;
				temp->next = curr->next;
				curr->next = temp;
				size++;
			}
		}
	}

	void removeSegment(string segment) {
		node* prev = 0;
		node* curr = head;

		if (isEmpty() == false) {
			while (curr->next != 0 && getListSize() > 1) {
				if (curr->currLine.find(segment) != -1) {
					if (prev != 0) {
						curr = prev;
						node* temp = curr->next;
						curr->next = curr->next->next;
						delete temp;
						size--;
					}
					else if (prev == 0) {
						node* temp = head;
						head = temp->next;
						delete temp;
						prev = 0;
						curr = head;
						size--;
					}
				}
				else {
					prev = curr;
					curr = curr->next;
				}
			}

			if (curr->currLine.find(segment) != -1) {
				if (getListSize() > 1) {
					node* temp = curr;
					delete temp;
					prev->next = 0;
					size--;
				}
				else if (getListSize() == 1) {
					head = 0;
					size--;
				}
			}
		}
	}

	void sortAlphabetical() {
		if (getListSize() >= 3) {
			bool swapDone = false;
			while (swapDone == false) {
				node* prev = 0;
				node* swap1 = head;
				node* swap2 = swap1->next;
				swapDone = true;

				while (swap2->next != 0) {
					if (swap1->currLine > swap2->currLine) {
						if (prev != 0) {
							prev->next = swap2;
							swap1->next = swap2->next;
							swap2->next = swap1;
							swapDone = false;
						}
						else if (prev == 0) {
							head = swap2;
							swap1->next = swap2->next;
							swap2->next = swap1;
							swapDone = false;
						}
					}
					prev = swap1;
					swap1 = swap2;
					swap2 = swap2->next;
				}
				
				if (swap1->currLine > swap2->currLine) {
					prev->next = swap2;
					swap1->next = 0;
					swap2->next = swap1;
					swapDone = false;
				}
			}
		}
		else if (getListSize() == 2) {
			node* prev = head;
			node* curr = prev->next;
			if (prev->currLine > curr->currLine) {
				head = curr;
				curr->next = prev;
				prev->next = 0;
			}
		}
	}

	void sortLength() {
		if (getListSize() >= 3) {
			bool swapDone = false;
			while (swapDone == false) {
				node* prev = 0;
				node* swap1 = head;
				node* swap2 = swap1->next;
				swapDone = true;

				while (swap2->next != 0) {
					if (swap1->currLine.size() > swap2->currLine.size()) {
						if (prev != 0) {
							prev->next = swap2;
							swap1->next = swap2->next;
							swap2->next = swap1;
							swapDone = false;
						}
						else if (prev == 0) {
							head = swap2;
							swap1->next = swap2->next;
							swap2->next = swap1;
							swapDone = false;
						}
					}
					prev = swap1;
					swap1 = swap2;
					swap2 = swap2->next;
				}

				if (swap1->currLine.size() > swap2->currLine.size()) {
					prev->next = swap2;
					swap1->next = 0;
					swap2->next = swap1;
					swapDone = false;
				}
			}
		}
		else if (getListSize() == 2) {
			node* prev = head;
			node* curr = prev->next;
			if (prev->currLine.size() > curr->currLine.size()) {
				head = curr;
				curr->next = prev;
				prev->next = 0;
			}
		}
	}

	void print(ofstream& output) {
		node* curr = head;
		while (curr != nullptr) {
			output << curr->currLine << endl;
			curr = curr->next;
		}
	}
};