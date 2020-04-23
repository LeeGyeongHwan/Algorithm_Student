/* 
ACMICPC 
문제 번호 : 1076 
문제 제목 : 저항
풀이 날짜 : 2020-04-23
Solved By Reamer 
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string color1, color2, color3;
    map<string, pair<string, long long>> ohmMap;

    ohmMap["black"] = make_pair("0", 1);
    ohmMap["brown"] = make_pair("1", 10);
    ohmMap["red"] = make_pair("2", 100);
    ohmMap["orange"] = make_pair("3", 1000);
    ohmMap["yellow"] = make_pair("4", 10000);
    ohmMap["green"] = make_pair("5", 100000);
    ohmMap["blue"] = make_pair("6", 1000000);
    ohmMap["violet"] = make_pair("7", 10000000);
    ohmMap["grey"] = make_pair("8", 100000000);
    ohmMap["white"] = make_pair("9", 1000000000);

    cin >> color1 >> color2 >> color3;

    string ohm = ohmMap[color1].first + ohmMap[color2].first;

    cout << stol(ohm) * ohmMap[color3].second << endl;

    return 0;
}