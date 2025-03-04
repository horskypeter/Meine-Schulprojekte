#include <iostream>
#include "chartree.h"


using namespace std;

int main()
{
	CharTree prve;
	NodePtr currentNode = NodePtr();
	NodePtr previousNode = NodePtr();

	cout << "\t  <a>    Vytvorenie prazdneho stromu" << endl;						//vytvorit strom
	cout << "\t  <b>    Vytvorenie laveho nasledovnika " << endl;					//pridat vlavo
	cout << "\t  <c>    Vytvorenie praveho nasledovnika" << endl;					//pridat vpravo	
	cout << "\t  <d>    Nastavenie na root " << endl;								//koren
	cout << "\t  <e>    Nastavenie na lave dieta" << endl;							//Ldieta
	cout << "\t  <f>    Nastavenie na prave dieta " << endl;						//Pdieta
	cout << "\t  <g>    Nastavenie aktivneho prvku na rodica" << endl;				//getparent
	cout << "\t  <h>    Vypise hodnotu aktivneho vrcholu a jeho hodnoty lavy a pravy (pripadne null ak nemaju data)" << endl;  //get data
	cout << "\t  <i>    Spustenie hry " << endl;
	cout << "\t  <x>    Ukonci program" << endl;

	char menu = 0;
	char repeat = 0;
	string question;
	string newQuestion;
	string oldQuestion;
	string choice;
	string animal;
	while (menu != 'x')
	{
		cout << "Z akeho menu mam hladat? ";
		cin >> menu;
		switch (menu)
		{
		case 'a':																		//zostavenie stromu
			cout << "Aka bude otazka: ";
			cin.ignore();
			getline(cin, question, '\n');
			prve.BuildRoot(question);
			currentNode = prve.Root();
			break;
		case 'b':																		//pridat vlavo
			cout << "Aka bude otazka vlavo: ";
			cin.ignore();
			getline(cin, question, '\n');
			previousNode = prve.GetParent(currentNode);
			if (currentNode != NULL)
			{
				prve.AppendLeft(currentNode, question);
			}
			else
			{
				cout << "Nemam kam pridavat strom neexistuje" << endl;
			}
			break;
		case 'c':																		//pridat vpravo
			cout << "Aka bude otazka vpravo: ";
			cin.ignore();
			getline(cin, question, '\n');
			previousNode = prve.GetParent(currentNode);
			if (currentNode != NULL)
			{
				prve.AppendRight(currentNode, question);
			}
			else
			{
				cout << "Nemam kam pridavat strom neexistuje" << endl;
			}
			break;
		case 'd':																		//nastavenie na koren
			currentNode = prve.Root();
			cout << "Hodnota korena je: " << prve.GetData(currentNode) << endl << '\t';
			break;
		case 'e':																		//nastavenie na lave dieta
			cout << "Nastavujem sa na lave dieta" << endl;
			currentNode = prve.LChild(currentNode);
			break;
		case 'f':																		//nastavenie na prave dieta
			cout << "Nastavujem sa na prave dieta" << endl;
			currentNode = prve.RChild(currentNode);
			break;
		case 'g':																		//nastavenie aktivneho prvku
			cout << "Nastavujem na rodica" << endl;
			currentNode = prve.GetParent(currentNode);
			break;
		case 'h':																		//aktualna hodnota
			cout << "Hodnotu aktivneho vrcholu: " << prve.GetData(currentNode) << endl;
			cout << "Hodnota vlavo: " + prve.GetData(prve.LChild(currentNode)) << endl;
			cout << "Hodnota vpravo: " + prve.GetData(prve.RChild(currentNode)) << endl;
			break;
		case 'i':																		//hra
			cout << "Mysli si zviera a ja sa ho pokusim uhadnut " << endl;
			cout << "Ak mas mozeme ist na to " << endl;
			cin >> animal;
			while (repeat != 'n')
			{
				currentNode = previousNode = prve.Root();
				while (!prve.IsLeaf(currentNode))							//citanie ulozenych dat zo stromu pokial nepride na list
				{
					cout << prve.GetData(currentNode) << endl << '\t';
					cin >> choice;
					if (choice == "y")
					{
						previousNode = currentNode;
						currentNode = prve.LChild(currentNode);
					}
					else if (choice == "n")
					{
						previousNode = currentNode;
						currentNode = prve.RChild(currentNode);
					}
				}
				if (currentNode != NULL)
				{
					cout << prve.GetData(currentNode) << endl << '\t';
					cin >> choice;
				}

				if (choice == "y" && currentNode != NULL)									//ak na list bola odpoved y pc vyhral
				{
					cout << "Nasiel som" << endl;
				}
				else if (choice == "n" || currentNode == NULL)								//ak nie tak pridavam nove zviera
				{
					cout << "Dopln zviera: " << endl << '\t';
					cin.ignore();
					getline(cin, animal);
					cout << "Zadaj otazku aby odpoved bola " << animal << endl << '\t';
					getline(cin, question);
					newQuestion = "Je to " + animal + "?";								//ukladam ako list
					oldQuestion = prve.GetData(currentNode);
					if (currentNode == NULL)
					{
						currentNode = new TreeNode(question, NULL, NULL, previousNode);
						if (previousNode != NULL)
						{
							previousNode->rLink = currentNode;
						}
					}
					else
					{
						prve.SetData(question, currentNode);
					}
					prve.AppendLeft(currentNode, newQuestion);
					if (oldQuestion != "NULL")
					{
						prve.AppendRight(currentNode, oldQuestion);
					}
				}
				cout << "Chces hrat znovu? " << endl << '\t';
				cin >> repeat;
			}
			break;
		case 'x':																		//ukoncenie 
			cout << "Tvoja volba na ukoncenie programu " << endl;
			break;
		default:
			string nothing;
			cin >> nothing;
			cout << "Zadal si hlupost " << endl;
			continue;
		}
	}

	system("pause");
	return 0;
}