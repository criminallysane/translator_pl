//Example 3: Program to demonstrate the use of string functions to convert a sentence to pig latin 
/* pigLatin.cpp: string functions can be used to convert sentences into piglatin!*/
#include <iostream>
#include <string>

using namespace std;

void pigLatin();
string platword(string); // platword for "pig latin word"

int main()
{
	char again = '1';
	
	cout<<"-------------Pig Latin Converter--------------\n";
	
	while(again=='1')
	{
		pigLatin();
		cout<<"\n\nType 1 to do another one : ";
		cin>>again;
		cin.ignore(80,'\n');
	}
 
	return 0;
}
void pigLatin()
{
	string entry="", platin="";
	string entword="";
	
	cout<<"Enter an English phrase below, on one line please!\n"
	<<"English: ";
	getline(cin,entry);

	int i=entry.find(' ');
	
	while( i < entry.length()-1) 
	{
		entword=entry.substr(0,i);
		entry=entry.substr(i+1); // takes 1st letter after space to end of string
		platin+=platword(entword)+" "; // translates current word and adds to accumulating pig latin phrase
 
		i=entry.find(' '); //find next space
	}
	
	platin+=platword(entry); // adds final word to accumulating pig latin phrase

	cout<<"\n";
	
	cout<<"Pig Latin: "<<platin;
}

string platword(string x) // accepts word in English, returns word in pig latin
{
	string ans="", prefix="";
	for(int y=0; y<x.length(); y++) 
	{
		x[y]=tolower(x[y]);
	}
	
	if ((x[0]=='a')||(x[0]=='e')||(x[0]=='i')||(x[0]=='o')||(x[0]=='u')) // if first letter a vowel
	{
	ans = x + "yay"; 
	}
	else
	{ 
		for (int j=0; j<x.length();j++)
		{
			if ((x[j]!='a')&&(x[j]!='e')&&(x[j]!='i')&&(x[j]!='o')&&(x[j]!='u'))
			{
				prefix+=x[j]; // accumluates letters at beginning until hits a vowel
			}
			else
			{ 
				break;
			}
		}
		
		ans = x.substr(prefix.length()); // first takes letters from vowel on
		
		ans += prefix + "ay"; // then adds prefix and "ay"
	}
	return ans;
}	