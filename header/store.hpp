#ifndef STORE_HPP
#define STORE_HPP
#include <vector>
#include <string>

class Store
{
    private:
    
        // vector holding items and their info in the store
        vector <string> storeVector ; 
        
    public:

        // default contructor 
        Store () ; 

        // display items in store 
        void displayStoreContents() ; 

        // display details of an item
        void displayItemInfo( string userItem ) ; 

        // display quantity of user requested item; not sure if should count directly or display quantity 
        int displayItemQuantity( string userItem ) ;

        // display description for each user requested item 
        void displayItemDescription( string userItem ) ; 

        // purchase item (removes one from store array)
        void purchaseItem( string userItem ) ; 

        // store menu that allows players to choose actions within store
        void storeMenu() ; 

        // print menu
        void printMenu() ; 
 
}

#endif 