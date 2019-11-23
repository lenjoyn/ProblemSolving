all: AddressBook AddressBook.o
AddressBook.o:AddressBook.cpp
	g++ -c AddressBook.cpp -o AddressBook.o
AddressBook: AddressBook.o
	g++ Addressbook.o -o Addressbook -I .
clean: 
	rm AddressBook.o AddressBook
