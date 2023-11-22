#ifndef STORE_HPP
#define STORE_HPP

class Store
{
    private:
    
        // description for item
        string itemDescription ; 
        
        // name of item
        string itemName ;

    public:

        // array holding items and their info in the store
        string storeContents[] ; 

        // display everything in store in a table like format
        void updateStoreContents() ; 

        // display items in store in a table? format; shows quantity, description, name, etc.
        void displayStoreContents() ; 

        // display quantity of user requested item; not sure if should count directly or display quantity 
        int displayItemQuantity( string userItem ) ;

        // display description for each user requested item 
        void displayItemDescription( string userItem ) ; 
 
}

#endif 
