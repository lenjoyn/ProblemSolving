#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <algorithm>
class AddressBook{

private:
	class Entry{
 
        private:
		std::string First;
		std::string Other;
		std::string Country;
		std::string Street;
		std::string Town;


        public:

	      Entry(std::string name){
	             First  = name;
		     Other  = "NONE";
		     Street = "NONE";
		     Town   = "NONE";
		     Country= "NONE";
              }
	      void addOther(std::string name){
                      Other = name;
              }
	      void addStreet(std::string add){
		      Street = add;
	      }
	      void addTown(std::string add){
		      Town = add;
              }
	      void addCountry(std::string add){
		      Country = add;
	      }

	      //get methods for private members
	      std::string getFirst(){
		      return First;
	      }
	      std::string getOther(){
		      return Other;
	      }
	      std::string getCountry(){
		      return Country;
	      }
	      std::string getStreet(){
		      return Street;
	      }
	      std::string getTown(){
		      return Town;
	      }
        };

	//unordered map to manage the addressbook
	std::unordered_map<std::string, std::shared_ptr<Entry>>    FirstMap;
        
	std::unordered_map<std::string, std::vector<std::string>> OtherMap;
	std::unordered_map<std::string, std::vector<std::string>> StreetMap;
	std::unordered_map<std::string, std::vector<std::string>> TownMap;
	std::unordered_map<std::string, std::vector<std::string>> CountryMap;

        void addOther(std::string name, std::shared_ptr<Entry> entry){
		
		if(entry->getOther()==name ) return;
		else if(entry->getOther()=="NONE") {
			entry->addOther(name);
			OtherMap[name].push_back(entry->getFirst());
	        }
		else{
			std::string old = entry->getOther();
			std::string first=entry->getFirst();
			entry->addOther(name);
			//a new value is given to other name, erase the old one from map
			OtherMap[old].erase(std::remove_if(OtherMap[old].begin(),OtherMap[old].end(),
						[&](std::string s)->bool{ return s==first;}),OtherMap[old].end());
			OtherMap[name].push_back(first);
		}
		
        }
        void addStreet(std::string add, std::shared_ptr<Entry> entry){
		
		if(entry->getStreet()==add ) return;
		else if(entry->getStreet()=="NONE") {
			entry->addStreet(add);
			StreetMap[add].push_back(entry->getFirst());
	        }
		else{
			std::string old = entry->getStreet();
			std::string first=entry->getFirst();
			StreetMap[old].erase(std::remove_if(StreetMap[old].begin(), StreetMap[old].end(),
						[&](std::string s)->bool{return s==first;}), StreetMap[old].end());

			StreetMap[add].push_back(first);
			entry->addStreet(add);
		}
        }
        void addTown(std::string add, std::shared_ptr<Entry> entry){
		
		if(entry->getTown()==add ) return;
		else if(entry->getTown()=="NONE") {
			entry->addTown(add);
			TownMap[add].push_back(entry->getFirst());
	        }
		else{
			std::string old = entry->getTown();
			std::string first=entry->getFirst();
                        TownMap[old].erase(std::remove_if(TownMap[old].begin(), TownMap[old].end(),
			                          [&](std::string s)->bool{return s==first;}), TownMap[old].end());

			TownMap[add].push_back(first);
			entry->addTown(add);
		}
	}
	void addCountry(std::string add, std::shared_ptr<Entry> entry){
		
		if(entry->getCountry()==add ) return;
		else if(entry->getCountry()=="NONE") {
			entry->addCountry(add);
			CountryMap[add].push_back(entry->getFirst());
	        }
		else{
			std::string old = entry->getCountry();
			std::string first=entry->getFirst();
			CountryMap[old].erase(remove(CountryMap[old].begin(),CountryMap[old].end(), first),CountryMap[old].end());
			CountryMap[old].erase(std::remove_if(CountryMap[old].begin(), CountryMap[old].end(),
						[&](std::string s)->bool{return s==first;}), CountryMap[old].end());
			CountryMap[add].push_back(first);
			entry->addCountry(add);
		}
        }

	std::string getAddress(std::shared_ptr<Entry> entry){
		return entry->getStreet()+" "+entry->getTown()+" "+entry->getCountry();
	}
	
public:
        //methods to modify addressbook
	//add entry only available by firstname
	void add(std::string name); 

	//other parameters could only be modified if firstname exists
        void modifyOther(std::string first, std::string other);
        void modifyStreet(std::string first, std::string add);
        void modifyTown(std::string first, std::string add);
	void modifyCountry(std::string first, std::string add);
/*
	//search entry
	std::shared_ptr<Entry> searchFirts(std::string name){return FirstMap[name];}
	std::vector<std::shared_ptr<Entry>> searchOther(std::string name){return OtherMap[name];}
	std::vector<std::shared_ptr<Entry>> searchTown(std::string add)  {return StreetMap[name];}
	std::vector<std::shared_ptr<Entry>> searchCountry(std::string add){return CountryMap[name];};
*/
	//delete is only available by first name 
	void deleteFirst(std::string name); 
/*
	void OutWriet();   //method to output the record
	void InLoad(std::string txt);  //method to load the existing record
*/};
#endif
