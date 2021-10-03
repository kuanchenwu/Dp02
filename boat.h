struct Item{
	int weight = 0;
	int value = 0;
	int amount = 0;
	int number = 0;
}; // to keep the amount of each item, the weight and value of the item

class boat{
public:
	boat(int boat_weight, int total_type); //set the amount of weight the boat can carry
	void add(Item x);// put item x onto the boat
	void print_output(Item x[]);// print out the total value of the items
	int curr_weight();// return the current weight
	int weight(); // return the total weight the boat can carry
	void remove(Item x[], int pos);
	int get_curr_most();
	// return current most valuable set of items
	int get_total_value();
	//return total value from boat
	void setCurrMost(int x, Item y[]);

	void setTotalValue(int x);

	int getSameValueSol();

	void setSameValueSol();

	void resetSameValueSol();
	
	int getCurrMostWeight();
	// bool done();

	int getTotalAmount();

	int getCurrAmount(Item y[]);
	
	int getItemAmount(int x);

private:
	int boat_weight;
	int total_weight = 0;
	int total_value = 0;
	bool status = true; 
	int total_type = 0;
	int curr_most = 0;
	int currMostWeight = 0;
	int sameValueSol = 0;
	int itemAmount[];
};