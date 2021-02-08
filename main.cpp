#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include "linkedList.h"

using namespace std;

int main(int argc, char* argv[]) {
	ArgumentManager am(argc, argv);
	ifstream input(am.get("input"));
	ifstream command(am.get("command"));
	ofstream output(am.get("output"));

	string addMethod;
	input >> addMethod;

	linkedList myList;

	string currentLine;

	if (addMethod == "Alphabetically") {
		while (getline(input, currentLine)) {
			if (currentLine != "" && myList.isDuplicate(currentLine) == false) {
				myList.insertAlphabetical(currentLine);
			}
		}
	}
	else if (addMethod == "Length") {
		while (getline(input, currentLine)) {
			if (currentLine != "" && myList.isDuplicate(currentLine) == false) {
				myList.insertLength(currentLine);
			}
		}
	}
	else if (addMethod == "Beginning") {
		while (getline(input, currentLine)) {
			if (currentLine != "" && myList.isDuplicate(currentLine) == false) {
				myList.insertBeginning(currentLine);
			}
		}
	}
	else if (addMethod == "End") {
		while (getline(input, currentLine)) {
			if (currentLine != "" && myList.isDuplicate(currentLine) == false) {
				myList.insertEnd(currentLine);
			}
		}
	}

	string currentCommand;

	while (getline(command, currentCommand)) {
		int size = myList.getListSize();

		if (currentCommand.find("Add") != -1) {
			int location = stoi(currentCommand.substr(currentCommand.find('(') + 1, currentCommand.find(')') - currentCommand.find('(') - 1));
			string toAdd = currentCommand.substr(currentCommand.find('[') + 1, currentCommand.find(']') - currentCommand.find('[') - 1);
			if (location <= size && myList.isDuplicate(toAdd) == false) {
				myList.insertAtPos(location, toAdd);
			}
		}
		else if (currentCommand.find("Remove") != -1) {
			string toRemove = currentCommand.substr(currentCommand.find('[') + 1, currentCommand.find(']') - currentCommand.find('[') - 1);
			myList.removeSegment(toRemove);
		}
		else if (currentCommand.find("Sort") != -1) {
			string sortType = currentCommand.substr(currentCommand.find('(') + 1, currentCommand.find(')') - currentCommand.find('(') - 1);
			if (sortType == "alphabetically") {
				myList.sortAlphabetical();
			}
			else if (sortType == "length") {
				myList.sortLength();
			}
		}
	}

	myList.print(output);
	
	return 0;
}