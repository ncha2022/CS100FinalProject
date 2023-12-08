#include "../header/store.hpp"
#include "../header/Inventory.h"
#include "../header/Character.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std ;

Store::Store(Inventory& inv) : inventory(inv) {
            vector<string>itemOne = { "Leather Armor", "increases max health by 10 hp", "1" } ;
            storeVector.push_back(itemOne) ;

            vector<string>itemTwo = { "Chainmail Armor", "increases max health by 30 hp", "1" } ;
            storeVector.push_back(itemTwo) ;

            vector<string>itemThree = { "Iron Armor", "increases max health by 60 hp", "1" } ;
            storeVector.push_back(itemThree) ;

            vector <string>itemFour = { "Gold Armor", "increases max health by 70 hp", "1" } ;
            storeVector.push_back(itemFour) ;

            vector <string>itemFive = { "Diamond Armor", "increases max health by 120 hp", "1" } ;
            storeVector.push_back(itemFive) ;

            vector <string>itemSix = { "Wood Sword", "increases attack by 10 points", "1" } ;
            storeVector.push_back(itemSix) ;

            vector <string>itemSeven = { "Stone Sword", "increases attack by 30 points", "1" } ;
            storeVector.push_back(itemSeven) ;

            vector <string>itemEight = { "Iron Sword", "increases attack by 60 points", "1" } ;
            storeVector.push_back(itemEight) ;

            vector <string>itemNine = { "Gold Sword", "increases attack by 70 points", "1" } ;
            storeVector.push_back(itemNine) ;

            vector <string>itemTen = { "Diamond Sword", "increases attack by 100 points", "1" } ;
            storeVector.push_back(itemTen) ;

            vector <string>itemEleven = { "Gun", "increases attack by 100000 points", "1" } ;
            storeVector.push_back(itemEleven) ;

            vector <string>itemTwelve = { "Small Health Potion", "increases current health by 40 hp", "8" } ;
            storeVector.push_back(itemTwelve) ;

            vector <string>itemThirteen = { "Medium Health Potion", "increases current health by 70 hp", "8" } ;
            storeVector.push_back(itemThirteen) ;

            vector <string>itemFourteen = { "Large Health Potion", "increases current health by 100 hp", "8" } ;
            storeVector.push_back(itemFourteen) ;
        }

void Store :: displayStoreContents ( )
{
    cout << "< Available Items >" << endl ;
    for ( int i = 0 ; i < storeVector.size() ; i ++ )
    {
        cout << (storeVector[i])[0] << endl ;
        // cout << "\tdescription: " << (storeVector[i])[1] << endl ;
        // cout << "\tquantity: " << (storeVector [i])[2] << endl ;
        // cout << endl ;
    }

    cout << endl ; 
}

void Store::displayItemInfo(string& userItem)
{
    bool itemFound = false;

    cout << endl << "User Input: " << userItem << endl;

    for (int i = 0; i < storeVector.size(); i++)
    {
        if (storeVector[i][0] == userItem)
        {
            cout << "Item found!" << endl;
            cout << endl;
            cout << storeVector[i][0] << endl;
            cout << "\tdescription: " << storeVector[i][1] << endl;
            cout << "\tquantity: " << storeVector[i][2] << endl;
            cout << endl;
            itemFound = true ; 
            break ; 
        }
    }
    // throw invalid_argument("Invalid item entered");

    if ( !itemFound )
    {
        cout << "Invalid item entered" ;
    }

    storeMenu() ; 
}


void Store::purchaseItem(string userItem) {
    int userItemIndex = -1; // Initialize to an invalid value
    for (int i = 0; i < storeVector.size(); i++) {
        if (storeVector[i][0] == userItem) {
            userItemIndex = i;
            break; // Break the loop once the item is found
        }
    }

    if (userItemIndex == -1) {
        cout << "Invalid item entered" << endl;
        storeMenu();
        return;
    }

    if (storeVector[userItemIndex][2] == "0") {
        cout << "Item out of stock." << endl;
        storeMenu();
        return;
    }

    // Decrease quantity if more than one, or set to "0" if only one left
    if (storeVector[userItemIndex][2] != "1") {
        int quantity = stoi(storeVector[userItemIndex][2]) - 1;
        storeVector[userItemIndex][2] = to_string(quantity);
    } else {
        storeVector[userItemIndex][2] = "0"; 
    }

    // Add item to the inventory
    string userItemName = storeVector[userItemIndex][0];
    inventory.addItem(userItemName);

    cout << "Purchased: " << userItemName << endl;

    storeMenu(); 
}


void Store :: displayItemQuantity ( string userItem )
{
    // displays quantity of item name entered by user
    int userItemIndex = 1000 ;
    for ( int i = 0 ; i < storeVector.size() ; i ++ )
    {
        if ( (storeVector[i])[0] == userItem )
        {
            userItemIndex = i ;
            cout << "Description: " << (storeVector[userItemIndex])[1] << endl ;
            return ;
        }
    }

    if ( userItemIndex == 1000 )
    {
        cout << "Invalid item entered" ;
    }

    storeMenu() ;

    return ;
}

void Store :: storeMenu ()
{
    // cout a menu for users to choose their next step from
    // numbered options
    bool exitStore = false;
    while(!exitStore)
    {
        cout << "< Welcome to the Store >" << endl ;
        cout << "What would you like to do?" << endl ;
        cout << endl ;
        printMenu() ;

        string userItemInfo ; 
        string userPurchaseItem ; 
        int userChoice ;
        cin >> userChoice ;

        cin.ignore(numeric_limits<streamsize>::max(), '\n') ; 

        switch ( userChoice )
        {
            case 1 :

                displayStoreContents() ;
                break ; 

            case 2:
                
                cout << "Enter item name" << endl ;
                getline ( cin, userItemInfo ) ; 
                displayItemInfo( userItemInfo ) ;
                break ; 

            case 3:
                
                cout << "Enter item to be purchased" << endl ;
                getline ( cin, userPurchaseItem ) ;
                purchaseItem( userPurchaseItem ) ;
                break ; 

            case 4:
                exitStore = true;
                break ; 

            default:

                cout << "invalid input" << endl ;
        }
    }
}

void Store :: printMenu ()
{
    // prints out numbered menu
    // issue: should see items in store if choosing option 2 and when asking for details (3,4)

    cout << "< Menu >" << endl ;
    cout << "1) View available items in Store" << endl ; // print item names ONLY
    cout << "2) Learn more about an item" << endl ; // prints description and quantity of specific item
    cout << "3) Purchase an item" << endl ;
    cout << "4) Leave Store" << endl ;
}
