#include <iostream>
#include "boat.h"

using namespace std;

boat::boat(int weight, int type){
	boat_weight = weight;
	total_type = type;
	itemAmount[type];
}

// boat::boat(Item *y){
// 	Item temp[10];
// 	for(int i = 0; i < total_type; i++){
// 		temp[i].number = y[i].number;
// 		temp[i].amount = y[i].amount;
// 	}
// }

void boat::add(Item x){
	
	total_weight += x.weight;
	total_value += x.value;
}


int boat::curr_weight(){
	return total_weight;
}

int boat::weight(){
	return boat_weight;
}

void boat::print_output(Item x[]){
	cout << "the solution contains: " << endl;
	for(int i = 0; i < total_type; i++){
		if(itemAmount[i] > 0)
		cout << itemAmount[i] << " Item " << i << endl;  
	}

	cout << endl << "Total weight: ";
	bool print = false;
	int tempWeight = 0;
	for(int i = 0; i < total_type; i++){
		if(itemAmount[i] > 0){
			cout << itemAmount[i] << " * " << x[i].weight;
			print = true;
			tempWeight += (itemAmount[i]*x[i].weight);
		
			if(i == total_type - 1 || total_type < 3){
				cout << " = " << tempWeight << endl;;
			} else if (print){
				cout << " + ";
				print = false;
			}
		}
	}
	cout << endl << "Total value: ";
	print = false;
	int tempValue = 0;
	for(int i = 0; i < total_type; i++){
		if(itemAmount[i] > 0){
			cout << itemAmount[i] << " * " << x[i].value;
			print = true;
			tempValue += (itemAmount[i]*x[i].value);
			if(i == total_type - 1 || total_type < 3){
				cout << " = " << tempValue << endl;
				break;
			} else if (print){
				cout << " + ";
				print = false;
			}
		}
	}
}

void boat::remove(Item x[], int pos){
	if(x[pos].amount >= 1)
		x[pos].amount--;
	total_value -= x[pos].value;
	total_weight -= x[pos].weight;
}

int boat::get_curr_most(){
	return curr_most;
}
void boat::setCurrMost(int x, Item y[]){
	curr_most = x;
	for(int i = 0; i < total_type; i++){
		itemAmount[i] = y[i].amount;
	}
	currMostWeight = total_weight;
}

int boat::getCurrAmount(Item y[]){
	int currAmount = 0;  
	for(int i = 0; i < total_type; i++){
		currAmount += y[i].amount;
	}
	return currAmount;
}

int boat::getTotalAmount(){
	int totalAmount = 0;
	for(int i = 0; i < total_type; i++){
		totalAmount += itemAmount[i];
	}
	return totalAmount;
}

int boat::get_total_value(){
	return total_value;
}

void boat::setSameValueSol(){
	sameValueSol + 1;
}

int boat::getSameValueSol(){
	return sameValueSol;
}

void boat::resetSameValueSol(){
	sameValueSol = 0;
}

int boat::getCurrMostWeight() {
	return currMostWeight;
}

// int boat::getEmptySpace(){
// 	return boat_weight - total_weight;
// }

// bool boat::done(){

// }

int boat::getItemAmount(int x){ 
	return itemAmount[x];
}