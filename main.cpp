#include"creature_header.h"
#include<fstream>
#include<cctype>

void printMenu();

int main()
{

	// int strength, health;
	const int numCreatures = 5;
	Creature creatures[numCreatures];
	int current_loop = 0;
	string user_search;
	string temp1;

	// parallel arrays
	string id[numCreatures];
	int strength[numCreatures];
	int health[numCreatures];
	int damage[numCreatures];

	enum user_input {
		update = 1,
		print_attributes = 2,
		print_damage = 3

	};
	int choice = -1;

	do {
		printMenu();
		cout << "Enter Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			// update the array of creatures by setting hit points, strength, and id

			for (int i = 0; i < numCreatures; i++)
			{
				cout << "Set an ID for creature " << i + 1 << endl;
				cin >> id[i];
				temp1 = id[i];

				// uppercase all creature id's
				for (int j = 0; j < temp1.length(); j++)
				{
					temp1[j] = toupper(temp1[j]);
				}

				// reassigns the user input from temp into creature id
				id[i] = temp1;
			}

			// sort all creatures
			for (int i = 0; i < numCreatures; i++)
			{
				for (int j = i + 1; j < numCreatures; j++)
				{
					if (id[i] > id[j])
					{
						temp1 = id[i];
						id[i] = id[j];
						id[j] = temp1;
					}
				}
			}

			// sets all variables in a parallel array
			for (int i = 0; i < numCreatures; i++)
			{
				health[i] = rand() % 100 + 10;
				strength[i] = rand() % 100 + 10;

				creatures[i].setCreature(strength[i], health[i], id[i]);

				damage[i] = creatures[i].setDamage(&strength[i]);

				current_loop++;
			}
			break;

		case 2:
			// prints all creatures in array (damage not included)
			if (current_loop == 0)
				cout << "Please update creatures by pressing option 2." << endl << endl;
			else
			{
				cout << setw(-20) << "ID" << setw(18) << "Health" << setw(17) << "Strength" << endl;

				for (int i = 0; i < current_loop; i++)
				{
					cout << creatures[i].to_sting(&id[i], &health[i], &strength[i]) << endl;
				}
			}
			break;

		case 3:
			// print all creatures in array (damage included)
			if (current_loop == 0)
				cout << "Please update creatures by pressing 2." << endl;
			else
			{
				// prints headers
				cout << setw(15) << "ID" << setw(10) << "Damage" << setw(10) << "Health" << setw(10) << "Strength" << endl;

				for (int i = 0; i < current_loop; i++)
				{
					cout << setw(15) << id[i] << setw(10) << damage[i] << setw(10) << health[i] << setw(10) << strength[i] << endl;
				}
			}
			break;

		case 4: 
			// searching by creature attribute
			if (current_loop == 0)
				cout << "Please update creatures by pressing 2." << endl;
			else
			{

				cout << "Type a creature attribute to search database." << endl;
				cin >> user_search;

				// uppercases user search
				for (int i = 0; i < user_search.length(); i++)
				{
					user_search[i] = toupper(user_search[i]);
				}

				// search for creature
				for (int i = 0; i < numCreatures; i++)
				{
					if (user_search == id[i])
						cout << "The Creature that you are looking for is: " << endl;
						cout << setw(15) << "ID" << setw(10) << "Health" << setw(10) << "Strength" << setw(10) << "Damage" << endl;
						search_function(&id[i], &health[i], &strength[i], &damage[i]);
				}

				cout << "Your search was not found in our database" << endl;
			}

		case 5:
			// exist case
			cout << "Thanks for using this application.\n";
			break;

		default:
			cout << "Wrong choice...Try again.\n";
			break;
		}

	} while (choice != 5);

	return 0;
}

void printMenu()
{
	cout << "1.Update the array of creatures by setting hit points, strengthand id." <<
		"\n2.Print the array of creatures." <<
		"\n3.Print damage for all creatures." <<
		"\n4.Search database of creatures." <<
		"\n5.Exit." << endl;
}