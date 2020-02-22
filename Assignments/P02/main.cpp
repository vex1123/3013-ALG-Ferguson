#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include "Getch.hpp"
#include "Timer.hpp"
#include "json.hpp"
#include "JsonFacade.hpp"

using namespace std;

void main()
{
	Timer timey;
	int numwords = 0;				// holder for number of words found in search
	char k;							// holder for character being typed
	string word = "";			    // var to concatenate letters to
	vector<string> vec1, vec2;      // vector for holding key strings and value strings
	vector<string> sugg;            // vector for holding return array of strings
	struct WordNode	                //struct for holding words and their definitions for use in list
	{
		string word;                //the word itself
		string def;                 // the definition of the word
		WordNode * next;            // pointer to next WordNode

		WordNode(string nword, string ndef)
		{
			word = nword;
			def = ndef;
			next = nullptr;
		}

	};
	
	class List
	{
	private:
		WordNode *head, *tail;
	public:
		List()
		{
			head = nullptr;
			tail = nullptr;
		}

		/**
	 * push_back: places a new node at the backof the List
	 *
	 * returns: Void
	 *
	 */
		void push_back(WordNode *input)
		{
			//construction is done with struct constructor this merely adds the node to the list at the back

			WordNode *tmp;

			if (head == nullptr)
			{
				
				head = input;
				input->next = nullptr;
				tail = input;
			}
			else
			{
				tail->next = input;
				input ->next = nullptr;
				tail = input;
			}
		}
		/**
	 * searchFunc: searches for a word in the dict file
	 *
	 * returns: Vector of strings
	 *
	 */
		vector<string> searchFunc(List L, string searchword)
		{
			vector<string> sugg;				// vector to pass back suggestions
			bool found = false;					// set start condition to false
			WordNode *tmp;
			tmp = L.head;
			int count = 0;                      //ineger for count of vector fullness

			for (int q = 0; q < 18; q++)		//loop only up to 19
			{								    // because of issue at line 
				if (tmp->next != nullptr)
				{
					if (count < 10)					// condition to stop if 10 suggestions are already found
					{
						for (int i = 0; i < searchword.size() - 1; i++)
						{
							if (tmp->word.at(i) == searchword.at(i))
							{
								found = true;
							}
							else
							{
								found = false;
							}
							if (found == false)
							{
								i = 80;					//use size condition to break loop since false was found
							}
						}
						if (found == true)
						{
							sugg.push_back(tmp->word);  // push word onto vector starting with first found
							count += 1;					// increment count
						}
						tmp = tmp->next;			    // update tmp to next word
					}

				}

				
			}
			return sugg;						// return vector containing up to 10 suggestions
		}

	};

	//declare linked list for allocation
	List L;

	//My jsonFacade can only hande exactly 19 objects and not a one more
	//the siuze of the objects does not affect this exception
	//no exception code is returned
	//It throws and exception otherwise.
	//the program is working as intended other than this exception however...
	JsonFacade fac("dict_test.json");
	vec1 = fac.getKeys();
	vec2 = fac.getValues();
	for(int i=0; i<18; i++)														    // initializer for linked list	
	{
		WordNode*  newNode = new WordNode(vec1[i],vec2[i]);
		L.push_back(newNode);
	
	}
	
	cout << "Type any key to search dictionary for word. " << endl;                 // general instruction prompt
	cout << " Type @ to clear word field. Type 9 to quit." << endl;                 //key to erase word command

																				    // While 9 is not typed keep looping
	while ((k = getch()) != '9') {
		word += k;																    // append char to word

		if ((int)k != 10) {                                                         // if k is not a space print it
			cout << k << endl;
			timey.Start();
			sugg = L.searchFunc(L, word);
			timey.End();
			cout << numwords << " Words Found in " << timey.MilliSeconds() << " seconds" << endl;
			cout << "suggestions : " << endl;
			for (auto i = sugg.begin(); i != sugg.end(); ++i)
			{
				cout << *i;
				cout << ", ";
			}
		} 

		// hitting @ sets word back to empty
		if ((int)k == 64) {
			for(int i = 0; i < 35; i++)
			{
				cout << endl;
			}
			cout << "@ pressed ... Word is empty\nWord was : " << word << " before deletion." << endl;
			
			word = "";

		}
	}

}

