#include <gtest/gtest.h>
#include "../header/store.hpp"

// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

TEST(testConstructor, constructor)
{
    Store s;
    EXPECT_NO_THROW(s);
}

TEST(testStore, DisplayStoreContents) {
    Store store;
    EXPECT_NO_THROW(store.displayStoreContents()) ;
}

TEST(testStore, displayItemInfo)
{
    Store store;
    string item = "Chainmail Armor";
    EXPECT_NO_THROW(store.displayItemInfo(item)) ;
}

TEST(testStore, displayItemInfo1)
{
    Store store;
    string item = "Gun";
    EXPECT_NO_THROW(store.displayItemInfo(item)) ;
}

TEST(testStore, displayItemInfo2)
{
    Store store ; 
    string item = "Invalid item entered" ;
    EXPECT_THROW(store.displayItemInfo(item), std:: invalid_argument) ; 
}

TEST(testStore, displayItemQuantity)
{
    Store store ; 
    string item = "Wood Sword" ;
    EXPECT_NO_THROW(store.displayItemQuantity(item)) ; 
}