#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "inord_list.h"
#include <ctype.h>

using namespace std;

int main (int argc, char *argv[])
{
InorderLinkedList List;
string line;
string conword;
ListElemType word;
ListElemType command;
ListElemType command_word;
ListElemType repos;
ListElemType insertword;
bool status;
ListElemType item;
int wordcount;
int charcount = 0;
string searchword;
string occurword;
int j = 0;
int distword;
int i;
int linecount = 0;
int countline;
if(argc != 3)
{
    cout<<"Incorrect number of arguments";
    return 0;
}

ifstream myfile (argv[1]);
if (myfile.is_open())
{
    while (getline (myfile,line))
    { linecount++;
      istringstream iss(line);
      while(iss)
      {   string word;
          iss >> word;
        for(i = 0; i < word.size(); i++)
        {
        if (word[i] == ' ' || word[i] == '.' || word[i] == '\n' || word[i] == ',' || word[i] == '\t' )
        {
               word.erase(i,1);
               i--;
        }
        else
        {
        word[i] = tolower(word[i]);
        }
        }
          if(word == " " || word == "\0" || word == "\n" || word == "\t")
                           {
                              NULL;
                           }
          else {
                status = List.insert(word,linecount);
               }

      }

     }
     myfile.close();
}
else
{
    cout << "File not found";
    return 0;
}
fstream commandsfile;
		commandsfile.open(argv[2]);

		if (!commandsfile.is_open()){
                       cout << "File not found";
                           return 0;
		                              }

		while (getline(commandsfile,command_word)){
                stringstream file1(command_word);
                        file1 >> command;

			if (command.compare("wordCount") == 0)

			{
			    if (List.first(item))
               {
                    wordcount = 1;
                    while(List.next(item))
                            {
                                wordcount++;
                            }
                        cout<<wordcount<<" words"<<endl;
                }
                    else
                            {
                                cout<<"List is empty";
                            }
			}
			else if (command.compare("distWords") == 0)	{

				int j = List.distWords();
				cout <<j<<" "<<"distinct words" << endl;
			}

			else if (command.compare("charCount") == 0){
				char num_of_chars;
				int sum = 0;
				myfile.open(argv[1]);
				while (!myfile.eof())
				{
					myfile.get(num_of_chars);
					sum++;
				}
				cout <<(sum-1)<<" "<<"characters" << endl;

			}
				else if (command.compare("frequentWord") == 0){

				List.frequentWord();

			}

			else if (command.compare("countWord") == 0){
				file1 >> repos;
				for (int j= 0; j < repos.length(); j++){
					repos[j] = tolower(repos[j]);
				}
				if (command_word.length() <= 10){
					cout << "Incorrect number of arguments" << endl;
				}
				else {
					cout << repos <<" "<< "is repeated"<<" " << List.countWord(repos)<<" " << "times" << endl; }
			                                                                                                        }

			else if (command.compare("starting") == 0){
				file1 >> repos;
				for (int j = 0; j < repos.length(); j++){
					repos[j] = tolower(repos[j]);
				}
				if (command_word.length() <= 9){
					cout << "Incorrect number of arguments" << endl;

				}
				else{
					List.starting(repos); }
                                                                     }


			else if (command.compare("containing") == 0){
				file1 >> repos;

				for (int j = 0; j< repos.length(); j++){
					repos[j] = tolower(repos[j]);
				}
				if (command_word.length() <= 11){
					cout << "Incorrect number of arguments" << endl;
				                                                        }
				else{
					List.containing(repos);
                                            }
			                                     }

			else if (command.compare("search") == 0){
				file1 >> repos;
				for (int j = 0; j < repos.length(); j++){
					repos[j] = tolower(repos[j]);
				}

				if (command_word.length() <= 6){
					cout << "Incorrect number of arguments" << endl;
                                                                     }
				else{
					List.Search(repos,linecount);  }

			                                                                }
			else {
				cout << "Undefined command" << endl;
			                                            }

		                                                                               }
                        commandsfile.close();



}
