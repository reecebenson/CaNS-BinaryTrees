// Reece Benson © 2017
// Computer and Network Systems - Binary Tree Data Calculator

// > Includes
#include <iostream>
#include <string>
using namespace std;

struct location {
	int index, lower, upper;
	string data;
};

// > Variables
location tree[100];

// > Create our tree
void init_tree()
{
	// > Empty location
	location temp;
	temp.data = "";

	for (int i = 1; i < 20; i++)
	{
		// > Update our temp data
		temp.index = i;
		temp.lower = (i + 1);
		temp.upper = (i + 2);
		tree[i] = temp;

		// > Debug
		//printf("-> Created branch [I=%d, L=%d, U=%d, D=\"%s\"]\n", temp.index, temp.lower, temp.upper, temp.data.c_str());
	}

	// > Debug
	printf("|> Binary tree initialised.\n\n");
}

// > Print our tree
void print_tree()
{
	// > Debug
	for (int i = 1; i < 20; i++)
	{
		// > Debug
		printf("-> Reading branch [I=%d, L=%d, U=%d, D=\"%s\"]\n", tree[i].index, tree[i].lower, tree[i].upper, tree[i].data.c_str());
	}

	// > Debug
	printf("|> Binary tree finished.\n\n");
}

// > Store our data
void store(int loc, string data)
{
	if (tree[loc].data == "")
	{
		// empty
		tree[loc].data = data;
	}
	else
	{
		// move down the branch
		if (tree[tree[loc].lower].data == "" && tree[tree[loc].upper].data == "")
		{
			store(tree[loc].lower, data);
		}
		else
		{
			store(tree[loc].upper, data);
		}
	}
}

int main()
{
	init_tree();
	store(1, "osman"), store(1, "james"), store(1, "perez"), store(1, "loyson"), store(1, "sundas");
	//store(1, "osman"), store(1, "james"), store(1, "loyson"), store(1, "perez"), store(1, "sundas");
	//store(1, "perez"), store(1, "osman"), store(1, "sundas"), store(1, "james"), store(1, "loyson");
	//store(1, "rong"), store(1, "martin"), store(1, "abdullahi"), store(1, "graham"), store(1, "laurence");
	//store(1, "abdullahi"), store(1, "graham"), store(1, "martin"), store(1, "laurence"), store(1, "rong");
	//store(1, "james"), store(1, "sundas"), store(1, "loyson"), store(1, "osman"), store(1, "perez");
	//store(1, "abdullahi"), store(1, "rong"), store(1, "graham"), store(1, "martin"), store(1, "laurence");
	print_tree();

	getchar();
	return 0;
}