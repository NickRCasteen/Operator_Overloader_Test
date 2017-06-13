
//Overloading Testaroo (Just so I can remember)

#include <iostream>
using namespace std;

//Make a simple class with an addition operator overloader. Make a function overload that adds 2 to whatever you do (Char, int, float, whatever.)

class StrengthPotion
{
	public:
	//POTION VALUES
	int Augment;
	int DaysLasting;
	int Modslots;

	int AlcoholicB; //0 for X-Eye. 1 to Totter. 2 for milk. 3 for Quayoffi Juice.

	//OVERLOADER FOR COMBINING POTIONS
	StrengthPotion operator+(const StrengthPotion& sp)
	{
		StrengthPotion Base;
		Base.Augment = this->Augment + sp.Augment;
		Base.DaysLasting = this->DaysLasting + sp.DaysLasting;
		Base.Modslots = this->Modslots + sp.Modslots;
		return Base;
	}

	//FOR WHEN YOU ARE CHANGING BASE.
	void ChangeBase(int selection)
	{

		AlcoholicB = selection;

		if(AlcoholicB == 0)
		{
			Augment = 1;
		        DaysLasting = 1;
        		Modslots = 1;
		}

		else if(AlcoholicB == 1)
		{
			Augment *= 2;
		}

                else if(AlcoholicB == 2)
                {
			DaysLasting++;
                }

                else if(AlcoholicB == 3)
                {
			Modslots++;
                }
		
		else
		{
			cout << "Invalid\n";
		}

	}
};

//PROTOTYPE
void MakeNew();

//THE MAIN FUNCTION
int main()
{
	bool looping = true;
	int choice = 0;
	cout << "Make Some Potions! Type 1 to make a new potion, 2 to exit.\n";
	
	while(looping)
	{
		cin >> choice;
		if(choice == 1)
		{
			MakeNew();
		}
	
		else if(choice == 2)
		{
			cout << "Goodbye!\n";
			looping = false;
		}
		
		else
		{
			cout << "Dummy.\n";
		}
		cout << "1 to make new potion, 2 to exit!\n";
	}

return 0;

}


//NOW FOR MAKE NEW

void MakeNew()
{
	int choiceB = 0;
	cout << "Making a Potion is easy! Press 1 to change the Alcoholic base, 2 to check the potion. \n 3 to change the 2nd potion's Base, 4 to check the 2nd potion, 5 to combine the potions, 6 to exit!\n";
	
	//3 POTIONS. 2 TO PLAY WITH, ONE TO BE A SUM.
	StrengthPotion MyPot;
	StrengthPotion MyPot2;
	StrengthPotion MyPotCombo;
	//SET VALUES
	MyPot.Augment = 1;
	MyPot.DaysLasting = 1;
	MyPot.Modslots = 1;
	MyPot.AlcoholicB = 0;
	MyPot2.Augment = 1;
        MyPot2.DaysLasting = 1;
        MyPot2.Modslots = 1;
        MyPot2.AlcoholicB = 0;
	MyPotCombo.Augment = 1;
        MyPotCombo.DaysLasting = 1;
        MyPotCombo.Modslots = 1;
        MyPotCombo.AlcoholicB = 0;
	//SET VALUES
	
	cin >> choiceB;
	while (choiceB != 6)
	{
		if(choiceB == 1)
		{
			//CHANGES BASE BASED ON INPUT.
			cout << "Potion 1 selected. 0 for X eye, 1 for Totter, 2 for Milk, 3 for Quayoffi.\n";
			cin >> choiceB;
			MyPot.ChangeBase(choiceB);
			cout << "Done!\n";
				
		}

                else if(choiceB == 2)
                {
			cout << "Potion 1 Potency = " << MyPot.Augment << endl;
			cout << "Potion 1 Lifespan = " << MyPot.DaysLasting << " days.\n";
			cout << "Potion 1 Modslots = " << MyPot.Modslots << endl;
                }

                else if(choiceB == 3)
                {
			cout << "Potion 2 selected. 0 for X eye, 1 for Totter, 2 for Milk, 3 for Quayoffi.\n";
                        cin >> choiceB;
                        MyPot2.ChangeBase(choiceB);
                        cout << "Done!\n";
                }

                else if(choiceB == 4)
                {
                        cout << "Potion 2 Potency = " << MyPot2.Augment << endl;
                        cout << "Potion 2 Lifespan = " << MyPot2.DaysLasting << " days.\n";
                        cout << "Potion 2 Modslots = " << MyPot2.Modslots << endl;

                }

                else if(choiceB == 5)
                {
			
			cout << "Combining the Potions!\n";
			MyPotCombo = MyPot + MyPot2;
			cout << "Result:\n";
			cout << "New Potion Potency = " << MyPotCombo.Augment << endl;
                        cout << "New Potion Lifespan = " << MyPotCombo.DaysLasting << " days.\n";
                        cout << "New Potion Modslots = " << MyPotCombo.Modslots << endl;
			
                }
		
		else
		{
			cout << "Follow directions, eeiot.\n";
		}

		cin >> choiceB;
	}	

}

