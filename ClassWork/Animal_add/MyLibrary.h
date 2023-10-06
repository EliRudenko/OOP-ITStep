#pragma once
#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <iostream>

using namespace std;

struct IFly   // интерфейс для летающих
{
	virtual void Fly() = 0;
};
struct ISwim   // интерфейс для плавающих
{
	virtual void Swim() = 0;
};

class Animal  // абстрактный класс !!
{
protected:
	char * name;
	int kg;
public:
	Animal() = default;
	Animal(const char * n, int k)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		kg = k;
	}
	void Print()
	{
		cout << "Name: " << name << "Kg: " << kg << endl;
	}	
    
	virtual void Continent() = 0;
	virtual void Eat() = 0;
	virtual void Sound() = 0;

	~Animal()
	{
		delete[] name;
	}
};

class Plane : public IFly
{
public:
    virtual void Fly()
    {
        std::cout << "Plane: fly" << std::endl;
    }

};

class Parrot : public Animal, public IFly
{
    char* continent;

public:
	Parrot() = default;
	Parrot(const char *  n, int kg, const char* cont) :Animal(n, kg)
	{
		continent = new char[strlen(cont) + 1];
		strcpy_s(continent, strlen(cont) + 1, cont);
	}
	// реализация интерфейса IAnimal
    virtual void Eat()
    {
        std::cout << "Parrot: eat" << std::endl;
    }
    virtual void Sound()
    {
        std::cout << "Parrot: sound" << std::endl;
    }
    virtual void Contintnt()
    {
        std:: cout << "Parrot: Contintnt A" << std::endl;
    }

    virtual void Fly()
    {
        std::cout << "Parrot:fly" << std::endl;
    }

	~Parrot()
	{
		delete[] continent;
	}

};



/*
class Pinguin: public Animal, public ISwim
{
	char* continent;

public:
	Pinguin() = default;
	Pinguin(const char *  n, int kg, const char* cont) :Animal(n, kg)
	{
		continent = new char[strlen(cont) + 1];
		strcpy_s(continent, strlen(cont) + 1, cont);
	}
	// реализация интерфейса IAnimal
	virtual void Eat()
	{
		cout << "Пингвины едят рыбу\n";
	}
	virtual void Sound()
	{
		cout << "Пингвины издают какие то звуки\n";
	}
	virtual void Continent()
	{
		cout << "Пингвины живут в Антарктиде\n";
	}
	// реализация интерфейса ISwim

	virtual  void Swim()
	{
		cout << "Пингвины отлично плавают\n";
	}
	~Pinguin()
	{
		delete[] continent;
	}

};
*/




/*
//все по умолчанию паблик поэтому структура
struct IFly
{
    virtual void Fly() = 0;
};


struct IAnimal
{
    virtual void Eat() = 0;
    virtual void Sound() = 0;
    virtual void Contintnt() = 0;
};

struct ISwim
{
    virtual void Swim() = 0;
};




//АБСТРАКТНЫЙ КЛАСС
//ЕСТЬ ЗАГОТОВКА, ЕСТЬ ПОЛЯ, ЕСТЬ МЕТОДЫ КОТОРЫЕ ЧТО-ТО ДЕЛАЮТ И ЕСТЬ ВИРТУАЛ МЕТОДЫ
class Animal : public IAnimal
{
    int kg;
    std::string name;

public:
    Animal() = default;
    Animal(std::string n, int k) :name(n), kg(k) {}

    void Print() { std::cout << name << " " << kg << std::endl ; }


    virtual void Continent()const = 0;

    void Eat() { std::cout << name << " eat" << std::endl; }

    void Sound() { std::cout << name << " aaaa" << std::endl; }

    void Fly() { std::cout << name << " fly" << std::endl; }

    void Swim() { std::cout << name << " swim" << std::endl; }

};
/*

class Pinguin : public Animal, public ISwim
{
    std::string continent;
public:

    Pinguin() = default;
    Pinguin(std::string n, int kg, std::string cont) : Animal(n, kg)
    {
        continent = cont;
    }

    
    virtual void Continent()
    {
        std::cout << "Continent"  << continent << std::endl;
    }
    

//IAnimal
    virtual void Eat()
    {
        std::cout << "eat f" << std::endl;
    }
    virtual void Sound()
    {
        std::cout << "aoaoao" << std::endl;
    }
    virtual void Contintnt()
    {
        std:: cout << "Contintnt A" << std::endl;
    }


//ISwim

    virtual void Swim()
    {
        std::cout << "Swim w" << std::endl;
    }

};
*/