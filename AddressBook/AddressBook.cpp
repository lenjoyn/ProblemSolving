#include "AddressBook.h"
#include "iostream"
#include <iostream>
#include <sstream>
#include <fstream>

void AddressBook::add(std::string first){
  
  	if(FirstMap[first]!=NULL) {
		std::cout<<"entry exists, try another name\n";
		return; 
        }
        
        FirstMap[first] = std::make_shared<Entry>(first); 
}


void AddressBook::modifyOther(std::string first, std::string other){
	if(FirstMap[first]==NULL){
		std::cout<<"entry doesn't exist, please check the given first name\n";
		return;
	}

	addOther(other, FirstMap[first]);
}


void AddressBook::modifyStreet(std::string first, std::string street){
	if(FirstMap[first]==NULL){
		std::cout<<"entry doesn't exist, please check the given first name\n";
		return;
	}

	addStreet(street, FirstMap[first]);
}
void AddressBook::modifyTown(std::string first, std::string town){
	if(FirstMap[first]==NULL){
		std::cout<<"entry doesn't exist, please check the given first name\n";
		return;
	}

	addTown(town, FirstMap[first]);
}
void AddressBook::modifyCountry(std::string first, std::string country){
	if(FirstMap[first]==NULL){
		std::cout<<"entry doesn't exist, please check the given first name\n";
		return;
	}

	addCountry(country, FirstMap[first]);
}

void AddressBook::deleteFirst(std::string first){
	if(FirstMap[first]==NULL){
		std::cout<<"entry doesn't exist, so nothing will be performed\n";
		return;
	}

	FirstMap[first]=NULL;
}

int main(int argc, char* argv[] ){ 


   AddressBook adb;
   std::string inFile = "record.txt";
   std::ofstream of;
   // read the file list, check the format is correct, and assign the numbers 
   std::ifstream input(inFile.c_str());
   if(!input) {
	   std::cout<<"no record is found, creating a new file\n";
	   of.open(inFile);
   }
   else{
      std::string line;
      while(getline(input, line)){
	   std::istringstream iss(line);
           std::string str;
	   std::vector<std::string> cols;
	   while(iss>>str) cols.push_back(str);

           adb.add(cols[0]);
	   adb.modifyOther(cols[0],cols[1]);
	   adb.modifyTown(cols[0],cols[2]);
	   adb.modifyCountry(cols[0],cols[3]);
	   adb.modifyStreet(cols[0],cols[4]);
      }
   }

/*   std::string command;
   cin>>command;
   while(command!="exit"){
	std::cout>>"which operation??\n";

	istringstream iss(command);
	string operation, content;
	iss>>operation>>" ">>content;

	if(operation == "addFirstName") abd.add(content);
	cin>>command;
   }
*/
   return 0;
}
