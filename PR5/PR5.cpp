#include <iostream>
#include <string>
using namespace std;

int ascii_cod(char x)
{
    int a = static_cast<int>(x);
    b
    //int a = int(x);
    return a;
}

//char cMyCharacter = 'A';
//int iMyAsciiValue = static_cast<int>(cMyCharacter);
//int asciiVal = 65;
//char asciiChar = static_cast<char>(asciiVal);

int main()
{
    setlocale(LC_ALL, "Rus");
    // Наш Алфавит и его ASCII код
    string s; //= "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    for (char ch = 'А'; ch <= 'Я'; ch++)
    {
        s.push_back(ch);
        cout << s.back() << " = " << ascii_cod(s.back()) << '\n';
    }
    
    cout << '\n';

    string text = "СУПЕРПРОГРАММА";
    string key = "МАША";

    //---------------------------ЗАШИФРОВКА-----------------------------
    
    string shifr = "";
    for (int r = 0;r < text.size();r++)
    { 
        int t = ascii_cod(text[r]); // Код одного из символа-текста
        int k = ascii_cod(key[r % key.size()]); // Код одного из символов ключа
        int g = (k - 'А' + 1) + t; // Код символа-зашифрованного
        char с;

        с = (g > -33) ? static_cast<char>(g - 32) : static_cast<char>(g);

        //if (g > - 33)
        //{
        //    с = static_cast<char>(g-32); // Символ-зашифрованный
        //   
        //}
        //else
        //{
        //     с = static_cast<char>(g); // Символ-зашифрованны
        //    
        //}   
        cout << "Из " << text[r] << " через " << key[r % key.size()] << " = " << с << '\n';
        shifr = shifr + с;
        
    }

    //Красивый вывод
    cout << "\n" << text << " - исходный текст" << "\n" ;
    for (int i = 0; i < text.size(); i++)
        cout << key[i % key.size()];
    cout << " - ключ" << "\n";
    for (int i = 0; i < text.size(); i++)
        cout << "|";
    cout << "\n" << shifr << " - зашиврованный текст" << "\n\n";


    //---------------------------РАСШИФРОВКА-----------------------------
    
    string ras = "";
    for (int r = 0;r < shifr.size();r++)
    {
        int s = ascii_cod(shifr[r]);// Код одного из символа зашифрованного текста
        int k = ascii_cod(key[r % key.size()]); // Код одного из символов ключа
        int g = s - k - 65; // Код символа-изначального

        if (g < -64)
        {
            char с = static_cast<char>(g + 32); // Символ-зашифрованный
            ras = ras + с;
           
        }
        else
        {
            char с = static_cast<char>(g); // Символ-зашифрованный
            ras = ras + с;
            
        }
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