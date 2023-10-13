#include <iostream>
#include <map>
#include <string>

typedef std::map<int, std::string> Dictionary;

Dictionary arr;

void insert(int key, const std::string& value) { arr[key] = value; }

void access(int key) { std::cout << "Element with key " << key << ": " << arr[key] << std::endl;  }

void iterate() 
{
    for (auto it = arr.begin(); it != arr.end(); ++it) 
    {
        std::cout << "Key: " << it->first << "  Value: " << it->second << std::endl;
    }
}

void search(int key) 
{
    auto search = arr.find(key);
    if (search != arr.end()) 
    {
        std::cout << "Element found: " << search->second << std::endl;
    } 
    else { std::cout << "Element not found!" << std::endl; }
}

void remove(int key) 
{
    auto search = arr.find(key);
    if (search != arr.end()) 
    {
        arr.erase(search);
        std::cout << "Element with key " << key << " removed." << std::endl;
    } 
    else { std::cout << "Element not found" << std::endl; }
}

void edit(int key, const std::string& newValue) 
{
    auto search = arr.find(key);
    if (search != arr.end()) 
    {
        search->second = newValue;
        std::cout << "Element with key " << key << " edited." << std::endl;
    } 
    else { std::cout << "Element not found" << std::endl; }
}

void displayMenu() 
{
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Insert Element" << std::endl;
    std::cout << "2. Access Element" << std::endl;
    std::cout << "3. Iterate Elements" << std::endl;
    std::cout << "4. Search Element" << std::endl;
    std::cout << "5. Remove Element" << std::endl;
    std::cout << "6. Edit Element" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << std::endl;
}

int main() 
{
    int choice;

    while (true) 
    {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                int key;
                std::string value;
                std::cout << "Enter key: ";
                std::cin >> key;
                std::cout << "Enter value: ";
                std::cin >> value;
                insert(key, value);
                break;
            }
            case 2:
            {
                int key;
                if (!arr.empty()) 
                {
                    std::cout << "Enter key: ";
                    std::cin >> key;
                    access(key);
                }
                else { std::cout << "No elements" << std::endl; }
                break;
            }
            case 3:
                if (!arr.empty()) 
                {
                    iterate();
                } 
                else { std::cout << "No elements" << std::endl; }
                break;
            case 4: {
                int key;
                if (!arr.empty()) 
                {
                    std::cout << "Enter key: ";
                    std::cin >> key;
                    search(key);
                } 
                else { std::cout << "No elements" << std::endl; }
                break;
            }
            case 5: 
            {
                int key;
                if (!arr.empty()) 
                {
                    std::cout << "Enter key: ";
                    std::cin >> key;
                    remove(key);
                } 
                else { std::cout << "No elements" << std::endl; }
                break;
            }
            case 6: 
            {
                int key;
                if (!arr.empty()) 
                {
                    std::string value;
                    std::cout << "Enter key: ";
                    std::cin >> key;
                    std::cout << "Enter new value: ";
                    std::cin >> value;
                    edit(key, value);
                }
                else {  std::cout << "No elements" << std::endl; }
                break;
            }
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }

    return 0;
}











/*
#include<iostream>
#include <vector>

int main()
{
    std::vector<int> vec{1,2,3,4,5};

    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << "    ";
    }
    std::cout << std::endl;

    std::vector<int> ::iterator ptr;

    for(ptr = vec.begin(); ptr != vec.end(); ++ptr)
    {
        std::cout << *ptr << "    ";
    }
    std::cout << std::endl;
}
*/
