#include <iostream>
#include <tchar.h>

//1
void replaceSpacesWithTabs(_TCHAR* str) 
{//замена пробелов на табы
//_T это _ТЕХТ
    while (*str) 
    {
        if (*str == _T(' ')) { *str = _T('\t'); }
        str++;
    }
}

//2
void countCharacters(const _TCHAR* str, int& lettersCount, int& digitsCount, int& otherCount) 
{//кол во букв, цыфр и тп
    while (*str) 
    {
        if (_istalpha(*str)) 
        {
            //БУКВА
            lettersCount++;
        } 
        else if (_istdigit(*str)) 
        {
            //ЦЫФРА
            digitsCount++;
        } 
        else { otherCount++; } // что то рандомное
        
        str++;
    }
}

//3
int countWords(const _TCHAR* str) 
{// слова в строке

//изначально все на 0
    int wordCount = 0;
    bool inWord = false;

    while (*str) 
    {
        if (_istspace(*str)) 
        {
            //если сейчас пробел или таб новая строка
            inWord = false;
        } 
        else 
        {
            //если не пробел и тп
            if (!inWord) 
            {
                wordCount++;
                inWord = true;
            }
        }

        str++;
    }

    return wordCount;
}

//4
int countVowels(const _TCHAR* str) 
{//кол во гласных
    int vowelCount = 0; 
    const _TCHAR vowels[] = _T("aeiouAEIOU"); //эти символы надо найти в строке

    while (*str) 
    {
        if (_tcschr(vowels, *str) != nullptr) 
        {
           //нашли гласную, то есть те символы которые былио в массиве
            vowelCount++;
        }
        str++;
    }

    return vowelCount;
}

//5
bool isPalindrome(const _TCHAR* str) 
{//палиндромом?
    
    int length = _tcslen(str); //ДЛИНА СТРОКИ!
    
    //для сравнения!!!!!!!!!!!
    int start = 0; // индекс НАЧАЛА
    int end = length - 1; // индекс КОНЦА

    //не середина 
    while (start < end) 
    {
        //=> если символы не совпадают то есть это не то 
        if (str[start] != str[end]) { return false; }

        // Переход к следующим символам
        start++;
        end--;
    }

    return true; // строка = палиндромом
}

//6
void removeCharacter(_TCHAR* str, int position) 
{//УДАЛЕНИЕ символа на позиции
    int length = _tcslen(str);


    if (position >= 0 && position < length) 
    {//проверка номера 
        //сдвиг влево
        for (int i = position; i < length - 1; i++) { str[i] = str[i + 1]; }
      
        str[length - 1] = _T('\0'); //конец строки
    }
}

//7
void removeAllOccurrences(_TCHAR* str, _TCHAR target) 
{// Удаляет все вхождения заданного символа из строки
    _TCHAR* pos = _tcschr(str, target);

    while (pos != nullptr) 
    {
        //НАШЛИ=УДАЛЯЕМ
        _tcscpy(pos, pos + 1);
        pos = _tcschr(pos, target);
    }
}

//8
void insertCharacter(_TCHAR* str, int position, _TCHAR character) 
{// Вставляет символ в указанную позицию строки
    int length = _tcslen(str);

    //ПРОВЕРКА номера
    if (position >= 0 && position <= length) 
    {
        // Сдвиг вправо
        for (int i = length; i > position; i--) { str[i] = str[i - 1]; }

        //символ на позицию
        str[position] = character;
    }
}








//проверка
int _tmain(int argc, _TCHAR* argv[]) 
{
    
    _TCHAR inputString[] = _T("Htllo, Maya! My card 4441 6556 7940 1124. Bye!");

//1
    //Меняем пробел на ТАБ
    replaceSpacesWithTabs(inputString);
    _tprintf(_T("spaces -> tabs:\n%s\n"), inputString);

//2
    //кол во БУКВ, цыфр и чего то еще рандомного что будет в строке
    int lettersCount = 0;
    int digitsCount = 0;
    int otherCount = 0;

    countCharacters(inputString, lettersCount, digitsCount, otherCount);
    
    _tprintf(_T("Letters: %d\n"), lettersCount); //буквы
    _tprintf(_T("Digits: %d\n"), digitsCount); // цыфры
    _tprintf(_T("Other characters: %d\n"), otherCount); //рандомное

//3
    //кол во СЛОВ
    int wordCount = countWords(inputString);
    _tprintf(_T("Number of words: %d\n"), wordCount);

//4
    //ГЛАСНЫЕ
    int vowelCount = countVowels(inputString);
    _tprintf(_T("Number of vowels: %d\n"), vowelCount);

//5
// в две стороны читается одинаково
    //палиндромом
    if (isPalindrome(inputString)) 
    {
        _tprintf(_T("Yep\n"));
    } 
    else {  _tprintf(_T("No\n")); }

//6
    //УДАЛЕНИЕ символа на позиции 2
    removeCharacter(inputString, 2);
    _tprintf(_T("after removing (position 2):\n%s\n"), inputString);

//7
    // Удаление всех 'l'
    removeAllOccurrences(inputString, _T('l'));
    _tprintf(_T("String after removing all occurrences of 'e':\n%s\n"), inputString);


//8
    //символа '-' на 8
    insertCharacter(inputString, 8, _T('-'));
    _tprintf(_T("inserting:\n%s\n"), inputString);



    return 0;
}


