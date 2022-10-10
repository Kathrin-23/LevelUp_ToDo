//
// Created by Dmitry Morozov on 7/10/22.
//

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>

///Split string into words;
std::vector<std::string> Split_To_Words(std::string &text) {

    std::vector<std::string> words;
    std::string word;
    for (char i: text) {
        if (i == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += i;
        }
    }
    words.push_back(word);
    return words;
}

int main() {

//    char c[20] = "Hello, World!";
//    std::string s = "Hello, World!";
//
////    int a[5] = {1, 2, 3, 4, 5};
////
////
////    for (int i = 0; i < 20; ++i) {
////        std::cout << a[i] << std::endl;
////    }
//    std::array<int, 5> a = {1, 2, 3, 4, 5};
//    std::vector<int> v = {1, 2, 3, 4, 5};
//    v.push_back(6);
//    v.push_back(7);
//
//    std::cout << v[1] << " " << v.at(1) << std::endl;
//    try {
//        std::cout << v.at(20) << std::endl;
//    } catch (std::out_of_range &e) {
//        std::cout << "A - ta -ta Index too high " << std::endl;
//    }
//
//    for (auto i: v) {
//        std::cout << i << std::endl;
//    }
//    for (int i = 0; i < v.size(); ++i) {
//        std::cout << v[i] << std::endl;
//    }
//
//    for (int i: v) {
//        std::cout << i << std::endl;
//    }
//
//    for (auto i: a) {
//        std::cout << i << std::endl;
//    }

    std::map<std::string, int> callBook;

    callBook["Dima"] = 123;
    callBook["Katerina"] = 456;
    callBook["Arina"] = 789;

    for (auto i: callBook) {
        std::cout << i.first << " : " << i.second << std::endl;
    }

    for (auto &[name, number]: callBook) {
        std::cout << name << " : " << number << std::endl;
    }


    std::string text = "We and our partners store and/or access information on a device, such as cookies and process personal data, such as unique identifiers and standard information sent by a device for personalised ads and content, ad and content measurement, and audience insights, as well as to develop and improve products. With your permission we and our partners may use precise geolocation data and identification through device scanning. You may click to consent to our and our partners’ processing as described above. Alternatively you may click to refuse to consent or access more detailed information and change your preferences before consenting. Please note that some processing of your personal data may not require your consent, but you have a right to object to such processing. Your preferences will apply to this website only. You can change your preferences at any time by returning to this site or visit our privacy policy.";

    std::map<std::string, int> Frequency;

    for (auto &word: Split_To_Words(text)) {
        Frequency[word]++;
    }

    for (auto &[word, count]: Frequency) {
        std::cout << word << " : " << count << std::endl;
    }
    return 0;
}

