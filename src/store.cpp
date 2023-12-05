#include "../include/store.hpp"
#include "../include/Inventory.h"
#include "../header/Character.h"
#include <iostream>
#include <vector>
#include <string>

Store :: Store ()
{
    // initialize creation of store array 
    // store in a vector of vectors
    // i.e vector[0][0] -> first item's name
    // i.e vector [0][1] -> first item's description

    // creates vector for entire store

    // create separate vector for each item
    // 0 = name
    // 1 = description
    // 2 = quantity

    vector<string>itemOne = { "Sword", "increases attack by 5 points", "1" } ; 
    storeVector.push_back(itemOne) ; 

    vector<string>itemTwo = { "Shield", "decreases next attack of enemy by 2 points", "2" } ; 
    storeVector.push_back(itemTwo) ; 

    vector<string>itemThree = { "Apple Juice", "decreases next attack of enemy by 4 points", "1" } ; 
    storeVector.push_back(itemThree) ; 

    vector <string>itemFour = { "Buttered Toast", "next attack does 2 more damage points", "3" } ; 
    storeVector.push_back(itemFour) ; 

    vector <string>itemFive = { "Stick", "increases next attack by 1 point", "3" } ; 
    storeVector.push_back(itemFive) ; 

    vector <string>itemSix = { "Cool Jacket", "immune to enemy's next attack", "1" } ; 
    storeVector.push_back(itemSix) ; 

    vector <string>itemSeven = { "Party Hat", "heal 2 hearts", "2" } ; 
    storeVector.push_back(itemSeven) ; 

    vector <string>itemEight = { "Corn on the Cob", "heal 3 hearts", "1" } ; 
    storeVector.push_back(itemEight) ; 
}

void Store :: displayStoreContents ( )
{
    for ( i = 0 ; storeVector.at(i) ; i ++ )
    {
        cout << "< Available Items >" << endl ; 
        cout << (storeVector[i])[0] << endl ; 
        // cout << "\tdescription: " << (storeVector[i])[1] << endl ; 
        // cout << "\tquantity: " << (storeVector [i])[2] << endl ; 
        // cout << endl ; 
    }
}

void Store :: displayItemInfo ( string userItemInfo )
{
    int userItemIndex = 1000 ; 

    for ( i = 0 ; storeVector.at(i) ; i ++ )
    {
        if ( (storeVector[i])[0] == userItem || (storeVector[i])[0] == tolower(useritem) )  
        {
        cout << (storeVector[i])[0] << endl ; 
        cout << "\tdescription: " << (storeVector[i])[1] << endl ; 
        cout << "\tquantity: " << (storeVector [i])[2] << endl ; 
        cout << endl ; 
        }
    }

    if ( userItemIndex == 1000 )
    {
        throw invalid_argument("Invalid item entered") ;
        return ; 
    }

    storeMenu() ; 

    return ; 
}

void Store :: purchaseItem ( string userItem )
{
    // useritem is removed from vector if quantity = 1
    // quantity decreased if quantity is > 1 
    
    int userItemIndex = 1000 ; 
    for ( i = 0 ; storeVector.at(i) ; i ++ )
    {
        if ( (storeVector[i])[0] == userItem || (storeVector[i])[0] == tolower(useritem) )  
        {
            userItemIndex = i ; 
            return ; 
        }
    }

    if ( userItemIndex == 1000 )
    {
        throw invalid_argument("Invalid item entered") ;
        storeMenu() ; 
        return ; 
    }

    if ( (storeVector[userItemIndex])[2] == "0" )
    {
        throw item_out_of_stock( "Item out of stock; quantity = 0" ) ; 
        storeMenu() ; 
        return ; 
    }

    // quantity adjustment 

    if ((storeVector[userItemIndex])[2] == "1" )
    {
        (storeVector[userItemIndex])[2] = "0" ;  
    }
    else if ((storeVector[userItemIndex])[2] == "2" )
    {
        (storeVector[userItemIndex])[2] = "1" ;  
    }
    else
    {
        (storeVector[userItemIndex])[2] = "2" ;  
    } 

    // ADD TO INVENTORY

    string userItemName = storeVector[userItemIndex][0] ; 

    for (auto it = items.begin(); it != items.end(); ) {
        if (it->name == userItemName) {
            items.addItem(it);
        } else {
            ++it;
        }
    }

    return ;
}

void Store :: displayItemQuantity ( string userItem )
{
    // displays quantity of item name entered by user
    int userItemIndex = 1000 ; 
    for ( i = 0 ; storeVector.at(i) ; i ++ )
    {
        if ( (storeVector[i])[0] == userItem || (storeVector[i])[0] == tolower(useritem) )  
        {
            userItemIndex = i ; 
            cout << "Description: " << (storeVector[userItemIndex])[1] << endl ;
            return ; 
        }
    }

    if ( userItemIndex == 1000 )
    {
        throw invalid_argument("Invalid item entered") ;
        storeMenu() ; 
    }

    storeMenu() ; 

    return ;   
}

void Store :: displayItemDescription ( string userItem )
{
    // displays description of item name entered by user
    int userItemIndex = 1000 ; 
    for ( i = 0 ; storeVector.at(i) ; i ++ )
    {
        if ( (storeVector[i])[0] == userItem || (storeVector[i])[0] == tolower(useritem) )  
        {
            userItemIndex = i ; 
            return ; 
        }
    }

    if ( userItemIndex == 1000 )
    {
        throw invalid_argument("Invalid item entered") ;
        return ; 
    }

    cout << "Quantity: " << (storeVector[userItemIndex])[2] << endl ;

    storeMenu() ; 
    
}

void Store :: storeMenu ()
{
    // cout a menu for users to choose their next step from 
    // numbered options
    cout << "< Welcome to the Store >" << endl ; 
    cout << "What would you like to do?" << endl ; 
    cout << endl ; 
    printMenu() ; 

    int userChoice ; 
    cin >> userChoice ; 

    while ( userChoice != 4 )
    {
        if ( userChoice == 1 )
        {
            displayStoreContents() ;   
        }
        else if ( userChoice == 2 )
        {
            string userItemInfo ; 
            cout << "Enter item name" << endl ; 
            getline ( cin, userItemInfo ) ; 

            displayItemInfo( userItemInfo ) ;
        }
        else if ( userChoice == 3 )
        {
            string userPurchaseItem ; 
            cout << "Enter item to be purchased" << endl ; 
            getline ( cin, userPurchaseItem ) ; 
            purchaseItem( userPurchaseItem ) ; 
        }

        printMenu() ;
        cin >> userChoice ;
    }

    return ; 
}

void Store :: printMenu ()
{
    // prints out numbered menu
    // issue: should see items in store if choosing option 2 and when asking for details (3,4)
    
    cout << "< Menu >" << endl ; 
    cout << "1) View available items in Store" << endl ; // print item names ONLY
    cout << "2) Learn more about an item" << endl ; // prints description and quantity of spoecific item
    cout << "3) Purchase an item" << endl ; 
    cout << "4) Leave Store" << endl ; 
} 
