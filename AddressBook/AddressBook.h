class AddressBook{

private:
	class Entry{
 
        private:
		string Firts;
		string Other;
		string Email;
		string Phone;
		string Town;
		string Country;
		string Street;
		string Address;
 


        public:
	      void addFirst(string name){
		      First = name;
              }
	      void addOther(string name){
                      Other = name;
              }
              void addMail(string mail){
		      Email = mail;
	      }
	      void addPhone(string number){
		      Phone = number;
	      }
	      void addStreet(string add){
		      Street = add;
	      }
	      void addTown(string add){
		      Town = add;
              }
	      void addCountry(string add){
		      Country = add;
	      }
	      
	    
        }

	//unordered map to manage the addressbook
	unordered_map<string, std::shared_ptr<Entry>>    FirstMap;
	unordered_map<ap<string, std::shared_ptr<Entry>> OtherMap;
	unordered_map<string, std::shared_ptr<Entry>>    MailMap;
	unordered_map<string, std::shared_ptr<Entry>>    PhoneMap;
	unordered_map<string, std::shared_ptr<Entry>>    StreetMap;
	unordered_map<string, std::shared_ptr<Entry>>    TownMap;
	unordered_map<string, std::shared_ptr<Entry>>    CountryMap;

        void addFirst(string name, std::shared_ptr<Entry>>; 
        void addOther(string name, std::shared_ptr<Entry>);
        void addMail(string mail, std::shared_ptr<Entry>);
        void addPhone(string phone,);
        void addStreet(sring add);
        void addTown(string add);
	void addCountry(string add);
	
public:
        //methods to modify addressbook
	//add entry
	void addFirst(string name); 
        void addOther(string name);
        void addMail(string mail);
        void addPhone(string phone);
        void addStreet(sring add);
        void addTown(string add);
	void addCountry(string add);
        //search entry
	Entry* searchFirts(string name);
	Entry* searchOther(string name);
	Entry* searchMail(string mail);
	Entry* searchPhone(string phone);
	Entry* searchTown(string add);
	Entry* searchCountry(string add);

	void searchGeneral(string s);
       
	
	void deleteFirst(string name); 
        void deleteOther(string name);
        void deleteMail(string mail);
        void deletePhone(string phone);
        void deleteStreet(sring add);
        void deleteTown(string add);
	void deleteCountry(string add);

	void OutWriet();   //method to output the record
	void InLoad(string txt);  //method to load the existing record
}
