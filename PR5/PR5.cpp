#include <iostream>
#include <string>
using namespace std;

int ascii_cod(char x) // Метод воззвращающий ASCII код символа
{
    int a = static_cast<int>(x);
    return a;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    // Наш Алфавит и его ASCII код - Для удобства разработки
    string s;
    for (char ch = 'А'; ch <= 'Я'; ch++)
    {
        s.push_back(ch);
        cout << s.back() << " = " << ascii_cod(s.back()) << '\n';
    }
    
    cout << '\n';

    string text = "СУПЕРПРОГРАММА"; // Исходный текст, который мы хотим зашифровать
    string key = "МАША"; // Ключ для шифрования

    //---------------------------ЗАШИФРОВКА-----------------------------
    
    string shifr = ""; // Строка для зашифрованного текста
    char с; // Зашифрованный символ
    for (int r = 0;r < text.size();r++)
    { 
        int t = ascii_cod(text[r]); // Код символа исходного текста
        int k = ascii_cod(key[r % key.size()]); // Код символа ключа
        int g = (k - 'А' + 1) + t; // Код зашифрованого символа
            
        с = (g > -33) ? static_cast<char>(g - 32) : static_cast<char>(g); // Условие того, что мы не выйдем за границы алфавита

        cout << "Из " << text[r] << " через " << key[r % key.size()] << " = " << с << '\n'; // Просто вывод
        shifr = shifr + с; // Добавляем новый символ к зашифрованной строке
    }

    // Красивый вывод
    cout << "\n" << text << " - исходный текст" << "\n" ;
    for (int i = 0; i < text.size(); i++)
        cout << key[i % key.size()];
    cout << " - ключ" << "\n";
    for (int i = 0; i < text.size(); i++)
        cout << "|";
    cout << "\n" << shifr << " - зашиврованный текст" << "\n\n";


    //---------------------------РАСШИФРОВКА-----------------------------
    
    string ras = ""; // Строка для расшифрованного текста
    for (int r = 0;r < shifr.size();r++)
    {
        int s = ascii_cod(shifr[r]); // Код зашифрованого символа
        int k = ascii_cod(key[r % key.size()]); // Код символа ключа
        int g = s - k - 65; // Код символа исходного текста

        с = (g < -64) ? static_cast<char>(g + 32) : static_cast<char>(g); // Условие того, что мы не выйдем за границы алфавита
        ras = ras + с; // Добавляем новый символ к расшифрованной строке
    }

    //Красивый вывод
    cout << "\n" << shifr << " - зашиврованный текст" << "\n";   
    for (int i = 0; i < text.size(); i++)
        cout << key[i % key.size()];
    cout << " - ключ" << "\n";
    for (int i = 0; i < text.size(); i++)
        cout << "|";
    cout << "\n" << ras << " - исходный текст" << "\n\n";

    system("pause");
}