#include <iostream>
#include <vector>
#include <algorithm>

void printShoppingList(const std::vector<std::string>& shoppingList) {
    std::cout << "Items: ";
    for (size_t i = 0; i < shoppingList.size(); i++) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << shoppingList[i];
    }
    std::cout << std::endl;
}

int main() {
    // Create an empty vector. Print it.
    std::vector<std::string> shoppingList;
    printShoppingList(shoppingList);

    // Append the items, "eggs," "milk," "sugar," "chocolate," and "flour" to the list. Print it.
    shoppingList.push_back("eggs");
    shoppingList.push_back("milk");
    shoppingList.push_back("sugar");
    shoppingList.push_back("chocolate");
    shoppingList.push_back("flour");
    printShoppingList(shoppingList);

    // Remove the last element from the vector. Print it.
    shoppingList.pop_back();
    printShoppingList(shoppingList);

    // Append the item, "coffee" to the vector. Print it.
    shoppingList.push_back("coffee");
    printShoppingList(shoppingList);

    // Write a loop that searches for the item, "sugar" and replaces it with "honey". Print the vector.
    for (size_t i = 0; i < shoppingList.size(); i++) {
        if (shoppingList[i] == "sugar") {
            shoppingList[i] = "honey";
        }
    }
    printShoppingList(shoppingList);

    // Write a loop that searches for the item, "milk," and then remove it from the vector. Print the vector.
    shoppingList.erase(std::remove(shoppingList.begin(), shoppingList.end(), "milk"), shoppingList.end());
    printShoppingList(shoppingList);

    return 0;
}
