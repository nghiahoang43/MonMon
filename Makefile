#Default
all: MonMon

#MonMon_demo
MonMon: Person.o Computer.o Monster.o Species.o Attribute.o Item.o Item_list.o Boss.o Zone.o MonMon.cpp add_on_func.cpp
	g++ -Wall Person.o Computer.o Monster.o Species.o Attribute.o Item.o Item_list.o Boss.o Zone.o MonMon.cpp add_on_func.cpp -o MonMon


#Class for MonMon
#Zone
Zone.o: Zone.cpp Zone.h
	g++ -c Zone.cpp -o Zone.o

#Attribute
Attribute.o: Attribute.cpp Attribute.h
	g++ -c Attribute.cpp -o Attribute.o

#Monster
Monstern.o: Monster.cpp Monster.h
	g++	-c Monster.cpp -o Monster.o

#Species
Species.o: Monster.o Species.cpp Species.h 
	g++ -c Species.cpp -o Species.o

#Boss
Boss.o: Monster.o Boss.cpp Boss.h
	g++ -c Boss.cpp -o Boss.o

#Player
Person.o: Player.h Person.h Person.cpp
	g++ -c Person.cpp -o Person.o
 
#Computer
Computer.o: Player.h Computer.h Computer.cpp
	g++ -c Computer.cpp -o Computer.o

#Item
Item.o: Item.h Item.cpp
	g++ -c Item.cpp -o Item.o

#Item_list
Item_list.o: Item_list.h Item_list.cpp
	g++ -c Item_list.cpp -o Item_list.o


#Unit Testing
#This section mostly for class with random inside
#Test by scanning and compare format
#Monster testing check with format in expected_format_Monster_testing.txt
Monster_testing: Attribute.o Monster.o Species.o Monster_testing.cpp add_on_func.cpp
	g++ Attribute.o Monster.o Species.o Monster_testing.cpp add_on_func.cpp -o Monster_testing
	./Monster_testing < input_Monster_testing.txt 

#Player testing check with format in expected_format_Player_testing.txt
Player_testing: Person.o Computer.o Item.o Item_list.o Attribute.o Monster.o Species.o Player_testing.cpp add_on_func.cpp
	g++ Person.o Computer.o Item.o Item_list.o Attribute.o Monster.o Species.o Player_testing.cpp add_on_func.cpp -o Player_testing
	./Player_testing < input_Player_testing.txt 

#Automated testing
#Zone automated testing
Zone_automated_testing: Attribute.o Zone.o Monster.o Species.o Boss.o Zone_automated_testing.cpp add_on_func.cpp
	g++ Attribute.o Zone.o Monster.o Species.o Boss.o Zone_automated_testing.cpp add_on_func.cpp -o Zone_automated_testing
	./Zone_automated_testing < input_Zone_automated_testing.txt | diff - expected_Zone_automated_testing.txt

#Item automated testing
Item_automated_testing: Item.o Item_list.o Item_automated_testing.cpp add_on_func.cpp
	g++ Item.o Item_list.o Item_automated_testing.cpp add_on_func.cpp -o Item_automated_testing
	./Item_automated_testing < input_Item_automated_testing.txt | diff - expected_Item_automated_testing.txt

#Attribute automated testing
Attribute_automated_testing: Attribute.o Attribute_automated_testing.cpp add_on_func.cpp
	g++ Attribute.o Attribute_automated_testing.cpp add_on_func.cpp -o Attribute_automated_testing
	./Attribute_automated_testing < input_Attribute_automated_testing.txt | diff - expected_Attribute_automated_testing.txt

#Clean
clean:
	rm -f *.o 
	rm -f Monster_testing Player_testing MonMon
	rm -f Item_automated_testing Zone_automated_testing Attribute_automated_testing