

//Открытие файла и запись (ofstream)
/*
#include <iostream>
#include <fstream>

int main() 
{
    std::ofstream file("example.txt"); // Открываем файл для записи

    if (file.is_open()) 
    { 
        file << "Hello, world!\n"; 
        file.close(); // Закрываем файл
        std::cout << "Файл записан.\n";
    } 
    else { std::cout << "Ошибка открытия файла.\n"; }

    return 0;
}
*/













/*
//Чтение файла (ifstream)
#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    std::ifstream file("example.txt"); // Открываем файл для чтения

    if (file.is_open()) 
    {
        std::string line;
        while (getline(file, line)) 
        { // Читаем построчно
            std::cout << line << std::endl;
        }

        file.close();
    } 
    else { std::cout << "Ошибка открытия файла.\n"; }

    return 0;
}
*/




/*
std::ofstream file("example.txt", std::ios::app); 
file << "Новая строка\n";
*/







//Работа с файловой системой (std::filesystem)



/*
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem; 

int main() 
{
    std::string path = "test_folder";

    if (fs::create_directory(path)) 
    { // Создаём папку
        std::cout << "Папка создана: " << path << std::endl;
    } else {
        std::cout << "no.\n";
    }

    fs::remove("example.txt");  // Удаление файла
    fs::remove_all("test_folder"); // Удаление папки и её содержимого

    

    return 0;
}
*/












#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class FileManager 
{
public:
    void listDirectory(const std::string& path) 
    {
        std::cout << "Содержимое " << path << ":\n";

        for (const auto& entry : fs::directory_iterator(path))
            std::cout << entry.path().filename().string() << std::endl;
    }

    void createFile(const std::string& path, const std::string& text) 
    {
        std::ofstream file(path);
        if (file) 
        {
            std::cout << "Файл создан: " << path << std::endl;
            // Запись переданного текста в файл
            file << text;
            std::cout << "Текст записан в файл: " << path << std::endl;
        } 
        else 
        {
            std::cerr << "Ошибка при создании файла: " << path << std::endl;
        }
    }

    void createFolder(const std::string& path) 
    {
        if (fs::create_directory(path))
            std::cout << "Папка создана: " << path << std::endl;
        else
            std::cerr << "Ошибка создания папки или папка уже существует: " << path << std::endl;
    }

    void deleteItem(const std::string& path) 
    {
        if (fs::remove_all(path))
            std::cout << "Удалено: " << path << std::endl;
        else
            std::cerr << "Ошибка при удалении: " << path << std::endl;
    }

    void renameItem(const std::string& oldPath, const std::string& newPath) 
    {
        fs::rename(oldPath, newPath);
        std::cout << "Переименовано: " << oldPath << " -> " << newPath << std::endl;
    }
};

int main() 
{
    FileManager fm;

    std::string folder = "test";
    std::string file = folder + "/file.txt";
    std::string newFile = folder + "/new_file.txt";
    std::string textToWrite = "Привет, это текст, записанный в файл!\nЕще одна строка текста.";

    // Создание папки
    fm.createFolder(folder);

    // Создание файла и запись текста
    fm.createFile(file, textToWrite);

    // Просмотр содержимого папки
    fm.listDirectory(folder);

    // Переименование файла
    fm.renameItem(file, newFile);

    //Удаление папки
    fm.deleteItem(folder);

    return 0;
}
*/
















/*
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

class FileManager 
{
public:
    virtual void listDirectory(const std::string& path) = 0;
    virtual void createFile(const std::string& path) = 0;
    virtual void createFolder(const std::string& path) = 0;
    virtual void deleteFile(const std::string& path) = 0;
    virtual void deleteFolder(const std::string& path) = 0;
    virtual void rename(const std::string& oldPath, const std::string& newPath) = 0;
    virtual void copy(const std::string& from, const std::string& to) = 0;
    virtual void move(const std::string& from, const std::string& to) = 0;
    virtual uintmax_t calculateSize(const std::string& path) = 0;
    virtual void search(const std::string& directory, const std::string& pattern) = 0;
    virtual ~FileManager() = default;
};

class SimpleFileManager : public FileManager
{
public:
    void listDirectory(const std::string& path) override 
    {
        std::cout << "Содержимое папки " << path << ":\n";
        for (const auto& entry : fs::directory_iterator(path)) 
        {
            std::cout << entry.path().filename().string() << std::endl;
        }
    }

    void createFile(const std::string& path) override 
    {
        std::ofstream file(path);
        if (file) 
        {
            std::cout << "Файл создан: " << path << std::endl;
        } 
        else 
        {
            std::cerr << "Ошибка создания файла!\n";
        }
    }

    void createFolder(const std::string& path) override 
    {
        if (fs::create_directory(path)) 
        {
            std::cout << "Папка создана: " << path << std::endl;
        } 
        else 
        {
            std::cerr << "Ошибка создания папки!\n";
        }
    }

    void deleteFile(const std::string& path) override 
    {
        if (fs::remove(path)) 
        {
            std::cout << "Файл удалён: " << path << std::endl;
        } 
        else 
        {
            std::cerr << "Ошибка удаления файла!\n";
        }
    }

    void deleteFolder(const std::string& path) override 
    {
        if (fs::remove_all(path)) 
        {
            std::cout << "Папка удалена: " << path << std::endl;
        } 
        else 
        {
            std::cerr << "Ошибка удаления папки!\n";
        }
    }

    void rename(const std::string& oldPath, const std::string& newPath) override 
    {
        fs::rename(oldPath, newPath);
        std::cout << "Переименовано: " << oldPath << " -> " << newPath << std::endl;
    }

    void copy(const std::string& from, const std::string& to) override 
    {
        fs::copy(from, to, fs::copy_options::recursive);
        std::cout << "Копировано: " << from << " -> " << to << std::endl;
    }

    void move(const std::string& from, const std::string& to) override {
        fs::rename(from, to);
        std::cout << "Перемещено: " << from << " -> " << to << std::endl;
    }


    size_t calculateSize(const std::string& path) override {
        if (fs::is_regular_file(path)) 
            return fs::file_size(path);
    
        size_t size = 0;
        for (const auto& entry : fs::recursive_directory_iterator(path))
            if (entry.is_regular_file())
                size += entry.file_size();
    
        return size;
    }




    uintmax_t calculateSize(const std::string& path) override 
    {
        uintmax_t size = 0;

        if (fs::is_regular_file(path))
        {
            return fs::file_size(path);
        }

        for (const auto& entry : fs::recursive_directory_iterator(path))
        {
            if (fs::is_regular_file(entry.path())) 
            {
                size += fs::file_size(entry.path());
            }
        }

        return size;
    }

    void search(const std::string& directory, const std::string& pattern) override 
    {
        std::cout << "Поиск файлов с \"" << pattern << "\" в " << directory << ":\n";

        for (const auto& entry : fs::recursive_directory_iterator(directory)) 
        {
            if (entry.path().filename().string().find(pattern) != std::string::npos) 
            {
                std::cout << "Найдено: " << entry.path().string() << std::endl;
            }
        }
    }
};

int main() 
{
    SimpleFileManager manager;
    std::string folder = "test_folder";
    std::string file = folder + "/test.txt";

    manager.createFolder(folder);  
    manager.createFile(file);      
    manager.listDirectory(".");    

    std::cout << "Размер папки: " << manager.calculateSize(folder) << " байт" << std::endl;

    manager.rename(file, folder + "/renamed.txt");  
    manager.copy(folder, "backup");                
    manager.move("backup", "moved_backup");        

    manager.search(".", "test");  
    manager.deleteFolder(folder);  
    manager.deleteFolder("moved_backup");  

    return 0;
}
*/