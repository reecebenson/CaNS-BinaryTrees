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

	for (int i = 1; i <= 15; i++)
	{
		// > Update our temp data
		temp.index = i;
		temp.lower = (i * 2);
		temp.upper = ((i * 2) + 1);
		tree[i] = temp;

		// > Debug
		printf("-> Created branch [I=%d, L=%d, U=%d, D=\"%s\"]\n", temp.index, temp.lower, temp.upper, temp.data.c_str());
	}

	// > Debug
	printf("|> Binary tree initialised.\n\n");
}

// > Print our tree
void print_tree()
{
	// > Debug
	for (int i = 1; i < 15; i++)
	{
		// > Debug
		printf("-> Reading branch [I=%d, L=%d, U=%d, D=\"%s\"]\n", tree[i].index, tree[i].lower, tree[i].upper, tree[i].data.c_str());
	}

	// > Debug
	printf("|> Binary tree finished.\n\n");
}

// > Store our data
int iteration = 0;
void store(int loc, string data)
{
	// > Variables
	char first_letter = data.at(0);
	bool lowerbound = false;

	if (tree[loc].data == "")
	{
		// > Branch/node is empty, add data to here
		printf("[i=%d] \"%s\" placed into location: %d\n", iteration, data.c_str(), loc);
		tree[loc].data = data;
		iteration = 0;
		printf("\n");//splitter
	}
	else
	{
		// > Branch/node is filled, check our data
		// -> Is the start of our data lower from our location?
		if(first_letter < tree[loc].data.at(0))
		{
			printf("[i=%d] [l=%d] %c is lower than prev data: %c\n", iteration, loc, first_letter, tree[loc].data.at(0));
			iteration++;
			store(tree[loc].lower, data);
		}
		else
		{
			printf("[i=%d] [l=%d] %c is higher than prev data: %c\n", iteration, loc, first_letter, tree[loc].data.at(0));
			iteration++;
			store(tree[loc].upper, data);
		}
	}
}

int main()
{
	init_tree();
	printf("If the following commands store(1, james), store(1, sundas), store(1, perez), store(1, loyson) and store(1, osman), are executed what will be stored at location(6) ?\n");
	store(1, "james"), store(1, "sundas"), store(1, "perez"), store(1, "loyson"), store(1, "osman");
	print_tree();

	getchar();

	init_tree();
	printf("If the following commands store(1,osman), store(1,james), store(1,perez), store(1, loyson) and store(1,sundas) are executed what will be stored at location (3)?\n");
	store(1, "osman"), store(1, "james"), store(1, "perez"), store(1, "loyson"), store(1, "sundas");
	print_tree();

	getchar();

	init_tree();
	printf("If the following commands store(1,osman), store(1,james), store(1, loyson), store(1,perez) and store(1,sundas) are executed what will be stored at location (5)?\n");
	store(1, "osman"), store(1, "james"), store(1, "loyson"), store(1, "perez"), store(1, "sundas");
	print_tree();

	getchar();

	init_tree();
	printf("If the following commands store(1,perez), store(1,osman), store(1,sundas), store(1,james) and store(1, loyson) are executed what will be stored at location (2)?\n");
	store(1, "perez"), store(1, "osman"), store(1, "sundas"), store(1, "james"), store(1, "loyson");
	print_tree();

	getchar();

	init_tree();
	printf("If the following commands store(1, rong), store(1,martin), store(1,abdullahi), store(1,graham) and store(1,laurence) are executed what will be stored at location (2)?\n");
	store(1, "rong"), store(1, "martin"), store(1, "abdullahi"), store(1, "graham"), store(1, "laurence");
	print_tree();

	getchar();

	init_tree();
	printf("If the following commands store(1,abdullahi), store(1,graham), store(1,martin), store(1,laurence) and store(1, rong) are executed what will be stored at location (7)?\n");
	store(1, "abdullahi"), store(1, "graham"), store(1, "martin"), store(1, "laurence"), store(1, "rong");
	print_tree();

	getchar();

	init_tree();
	printf("If the following commands store(1,james) , store(1,sundas), store(1, loyson), store(1,osman) and store(1,perez) are executed what will be stored at location (2)?\n");
	store(1, "james"), store(1, "sundas"), store(1, "loyson"), store(1, "osman"), store(1, "perez");
	print_tree();

	getchar();

	init_tree();
	printf("If the following commands store(1,abdullahi), store(1, rong), store(1,graham), store(1,martin) and store(1,laurence), are executed what will be stored at location (6)?\n");
	store(1, "abdullahi"), store(1, "rong"), store(1, "graham"), store(1, "martin"), store(1, "laurence");
	print_tree();

	getchar();

	init_tree();
	printf("If the following commands store(1,martin), store(1,laurence), store(1,abdullahi), store(1,graham) and store(1, rong) are executed what will be stored at location (4)?\n");
	store(1, "martin"), store(1, "laurence"), store(1, "abdullahi"), store(1, "graham"), store(1, "rong");
	print_tree();

	getchar();

	init_tree();
	printf("If the following commands store(1,laurence), store(1, rong), store(1,graham), store(1,abdullahi) and store(1,martin) are executed what will be stored at location (3)?\n");
	store(1, "laurence"), store(1, "rong"), store(1, "graham"), store(1, "abdullahi"), store(1, "martin");
	print_tree();

	getchar();

	printf("\n\nend.");

	getchar();

	return 0;
}