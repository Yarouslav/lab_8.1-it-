#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char* str) {
    if (strlen(str) < 3)
        return 0;
    int k = 0;
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == ',')
            k++;
    return k;
}

char* Change(char* str) {
    size_t len = strlen(str);
    if (len < 3)
        return str;

    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;

    while (i <= len - 1) {
        if (str[i] == ',') {
            strcat(t, "**");
            t += 2;
            i += 1;
        }
        else {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    strcpy(str, tmp);
    return str;
}


int FindThirdCommaPosition(char* str) {
    int commaCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',') {
            commaCount++;
            if (commaCount == 3) {
                return i;  
            }
        }
    }
    return -1;  
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int thirdCommaPosition = FindThirdCommaPosition(str);
    if (thirdCommaPosition != -1) {
        cout << "Position of the third comma: " << thirdCommaPosition << endl;
    }
    else {
        cout << "The third comma was not found." << endl;
    }

    cout << "String contained " << Count(str) << " groups of ','" << endl;

    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}