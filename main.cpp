/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Victor Urena
 */

#include "std_lib_facilities.h"
#include "Name_value.h"

void printNamesAndValues(vector<Name_value> printList)
{
    int i;

    for (i = 0; i < printList.size(); i++)
    {
        printList[i].printContents();
    }
}

void checkDuplicate(vector<Name_value> listToCheck, Name_value instanceToCheck)
{
    int i;

    for(i = 0; i < listToCheck.size(); i++)
    { 
        Name_value instance = listToCheck[i];

	    if((instanceToCheck.getName() == instance.getName())&& (instanceToCheck.getValue() == instance.getValue()))
        {
            cout << "Error: Do not enter duplicate values.\n";
            exit(1);
        }
    } 
}


int main()
{
    String name;
    int val;
    vector<Name_value> list;

    while (true)
    {
        cout << "Enter a name and value pair (Ex: Joe 17). Enter \"NoName 0\" to terminate : ";
        cin >> name >> val;

        if (name == "NoName" && val == 0)
        {
            printNamesAndValues(list);
            exit(1);
        }
        else
        {
            Name_value instance(name, val);

            checkDuplicate(list, instance);

            list.push_back(instance);
        }
        
    }

}