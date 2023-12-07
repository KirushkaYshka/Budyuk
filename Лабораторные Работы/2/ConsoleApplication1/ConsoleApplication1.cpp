#include <iostream>
#include <string>

std::string HtmlEncode(std::string const& text) {
    std::string result;
    for (char c : text) {
        switch (c) {
        case '"':
            result += "&quot;";
            break;
        case '\'':
            result += "&apos;";
            break;
        case '<':
            result += "&lt;";
            break;
        case '>':
            result += "&gt;";
            break;
        case '&':
            result += "&amp;";
            break;
        default:
            result += c;
            break;
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RUS");
    std::string input;
    std::cout << "Введите текст для функции HTML encode: ";
    std::getline(std::cin, input);
    std::string encoded = HtmlEncode(input);
    std::cout << "Зашифрованый текст: " << encoded << std::endl;
    return 0;
}