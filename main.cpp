#include <iostream>
#include <fstream>
#include "boat.h"
#include <string>
#include <iostream>

using namespace std;

bool solve(boat &x, int value_type, Item y[], int counter){
    // if(x.curr_weight() > x.weight()){
	// 	x.remove(y, counter);
	// 	cout << "remove " << endl;
	// 	if(x.get_curr_most() < x.get_total_value()){
	// 		x.setCurrMost(x.get_total_value(), y);
	// 		cout << x.get_curr_most() << endl;
	// 	} else if (x.get_curr_most() == x.get_total_value()){
	// 		if(x.getCurrMostWeight() > x.curr_weight()){ 
	// 			x.setCurrMost(x.get_total_value(), y);
	// 		} else if(x.getCurrMostWeight() == x.curr_weight())
	// 			if(x.getTotalAmount() > x.getCurrAmount(y))
	// 				x.setCurrMost(x.get_total_value(), y);
	// 	} 
	// 	return true;
	// } else {
		for(;counter < value_type; counter++){
		
		if(x.weight() - x.curr_weight() >= y[counter].weight){
			x.add(y[counter]);
			y[counter].amount++;
			// cout << "add "<< counter << " "<< x.curr_weight() << endl;
			// cout << "the total value is " << x.get_total_value() << endl;
			bool success = solve(x, value_type, y, counter);
			
			if(x.get_curr_most() < x.get_total_value()){
				x.setCurrMost(x.get_total_value(), y);
				// cout << x.get_curr_most() << endl;
			} else if (x.get_curr_most() == x.get_total_value()){
				if(x.getCurrMostWeight() > x.curr_weight()){ 
					x.setCurrMost(x.get_total_value(), y);
				} else if(x.getCurrMostWeight() == x.curr_weight())
					if(x.getTotalAmount() > x.getCurrAmount(y))
						x.setCurrMost(x.get_total_value(), y);
		}
			x.remove(y, counter);
			// cout << " "  << x.get_curr_most() << endl;
			// cout << " "  << x.getItemAmount(0) << x.getItemAmount(1) << x.getItemAmount(2) << endl;
			if(success) return true;
			}
		}
		return false;
	}

int main() {
	string boatWeight, numValuable, temp, itemWeight, itemValue;
	int weight, number, num_valuable, boat_weight;
	string choice;
	cout << endl;
	cout << "********************************" << endl;
	cout << "Menu: "<< endl;
	cout << "1. to import from data file " << endl;
	cout << "2. to enter the value by input "<< endl;
	cout << "********************************" << endl;
	getline(cin, choice);
	if (choice == "1"){
		string input;
		cout << endl << "enter data file name: "<< endl;
		getline(cin, input);
		ifstream insertion_file;
		insertion_file.open(input.c_str());
	 	if(!insertion_file.fail()){
	 		getline(insertion_file, boatWeight);
			weight = stoi(boatWeight);
			getline(insertion_file, numValuable);
			number = stoi(numValuable);
			boat titanic(weight, number);
			Item items[number];
			for(int i = 0; i < number; i++){
				getline(insertion_file, temp);
				int index1 = temp.find(' ');
				string temp1 = temp.substr(index1+1);
				int index2 = temp1.find(' ');
				items[i].number = i;
				itemWeight = temp1.substr(0, index2);
				itemValue = temp1.substr(index2);
				items[i].weight = stoi(itemWeight);
				items[i].value = stoi(itemValue);
			}
			solve(titanic, number, items, 0);
			titanic.print_output(items);

	 	} else {
			 cout << "invalid data file" << endl;
		 }

	}

	if(choice == "2"){
		cout << "Enter the amount of weight the baot can carry: ";
		cin >> boat_weight;
		cout << endl << "Enter the number of valuable item types: ";
		cin >> num_valuable;
		// to obtain the number weight of the boat and the numebr of valuable items types
		boat titanic(boat_weight, num_valuable);
		Item items[num_valuable];
		
		for(int i = 0; i < num_valuable; i++){
			cout << endl << "Item " << i << ": " << endl;
			items[i].number = i+1; 
			cout << "Enter the weight of this item: " << endl;
			cin >> items[i].weight;
			cout << "Enter the value of this item: " << endl;
			cin >> items[i].value;
			cout << endl;
		}

		solve(titanic, num_valuable, items, 0);
			titanic.print_output(items);
	}	
}