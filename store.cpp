#include "../include/store.hpp"\
#include <iostream>
#include <vector>
#include <string>

Store :: Store ()
{
    // initialize creation of store array 
    // store in a vector of vectors
    // i.e vector[0][0] -> first item's name
    // i.e vector [0][1] -> first item's description

    // create vector for entire store
    vector<string>storeVector ;

    // create separate vector for each item
    // 0 = name
    // 1 = description
    // 2 = quantity
    vector<string>itemOne = { "Sword", "increases next attack by 5 points", "2" } ; 
    storeVector.push_back(itemOne) ; 

    vector<string>itemTwo = { "Shield", "decreases next attack of enemy by 3 points", "2" } ; 
    storeVector.push_back(itemTwo) ; 

    vector<string>itemThree = { "Apple Juice", "next attack from enemy does 50% less damage points", "1" } ; 
    storeVector.push_back(itemThree) ; 

    vector <string>itemFour = { "Buttered Toast", "next attack does 20% more damage points", "3" } ; 
    storeVector.push_back(itemFour) ; 

    vector <string>itemFive = { "Stick", "increases next attack by 1 point", "3" } ; 
    storeVector.push_back(itemFive) ; 

    vector <string>itemSix = { "Cool Jacket", "immune to enemy's next attack", "1" } ; 
    storeVector.push_back(itemSix) ; 

    vector <string>itemSeven = { "Party Hat", "heal 4 hearts", "2" } ; 
    storeVector.push_back(itemSeven) ; 

    vector <string>itemEight = { "Corn on the Cob", "heal an extra 3 hearts a round for the next two rounds", "1" } ; 
    storeVector.push_back(itemEight) ; 
}

void Store :: displayStoreContents ( )
{
    for ( i = 0 ; storeVector.at(i) ; i ++ )
    {
        cout << "Item name: " << (storeVector[i])[0] << endl ; 
        cout << "\tdescription: " << (storeVector[i])[1] << endl ; 
        cout << "\tquantity: " << (storeVector [i])[2] << endl ; 
        cout << endl ; 
    }
}

void Store :: purchaseItem ( string userItem )
{
    // useritem is removed from vector if quantity = 1
    // quantity decreased if quantity is > 1
    
    int userItemIndex ; 
    for ( i = 0 ; storeVector.at(i) ; i ++ )
    {
        if ( (storeVector[i])[0] == userItem || (storeVector[i])[0] == tolower(useritem) )  
        {
            userItemIndex = i ; 
            return ; 
        }
    }

    if ( (storeVector[userItemIndex])[2] == 1 )
    {
        // remove entire item
        // out of stock
    }
    else
    {
        // since quantity is in string might have to change type or check what string says and replace with right value
        (storeVector[userItemIndex])[2] = 
    }
}

void Store :: updateStoreContents ()
{

}

void Store :: displayItemQuantity ( string userItem )
{
    // displays quantity of item name entered by user
    int userItemIndex ; 
    for ( i = 0 ; storeVector.at(i) ; i ++ )
    {
        if ( (storeVector[i])[0] == userItem || (storeVector[i])[0] == tolower(useritem) )  
        {
            userItemIndex = i ; 
            return ; 
        }
    }

    cout << "Description: " << (storeVector[userItemIndex])[1] << endl ;
    
}

void Store :: displayItemDescription ( string userItem )
{
    // displays description of item name entered by user
    int userItemIndex ; 
    for ( i = 0 ; storeVector.at(i) ; i ++ )
    {
        if ( (storeVector[i])[0] == userItem || (storeVector[i])[0] == tolower(useritem) )  
        {
            userItemIndex = i ; 
            return ; 
        }
    }

    cout << "Quantity: " << (storeVector[userItemIndex])[2] << endl ;
    
}

void Store :: storeMenu ()
{
    // cout a menu for users to choose their next step from 
    // numbered options
    cout << "< Welcome to the Store >" << endl ; 
    cout << "What would you like to do?" << endl ; 
    cout << endl ; 
    printMenu() ; 



}

void Store :: printMenu ()
{
    // prints out numbered menu
    // issue: should see items in store if choosing option 2 and when asking for details (3,4)
    
    cout << "< Menu >" << endl ; 
    cout << "1) View items in Store" << endl ; // print only items 
    cout << "2) Purchase an item" << endl ; 
}

// void Store :: storeMenuSelect ( int userMenuSelection )
// {
//     // user chooses option, triggering next line of events
//     // option is given in numbers on menu 
// }
