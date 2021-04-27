#include <iostream>
#include <map>

void write(std::map<std::string, int> m){
    if(m.size() < 1) {
        std::cout << "A map üres" << std::endl;
        return;
    }
    for (const auto& p : m)
		std::cout << p.first << ": " << p.second << std::endl;
}
int sum(std::map<std::string, int> msi){
    int sum = 0;
    for (const auto& p : msi)
		sum += p.second;

    return sum;
}
std::map<std::string, int> addPair(std::map<std::string, int> msi){
    std::string text;
    int value;
    std::cin >> text >> value;
    msi[text] = value;
    return msi;
}

int main() {
    
  
	std::map<std::string, int> msi;
    msi["lecture1"]=1;
    msi["lecture2"]=2;
    msi["lecture3"]=3;
    msi["lecture4"]=4;
    msi["lecture5"]=5;
    msi["lecture6"]=6;
    msi["lecture7"]=7;
    msi["lecture8"]=8;
    msi["lecture9"]=9;
    msi["lecture10"]=10;

    write(msi);

    msi.erase(msi.begin(), msi.end());
    int howMany = 3;
    write(msi);
    while(msi.size() < howMany){  
    msi = addPair(msi);
    }
    /* msi = addPair(msi);
    msi = addPair(msi);
    msi = addPair(msi); */
    std::cout << std::endl;
    write(msi);

    std::cout << sum(msi) << std::endl;


	std::map<int, std::string> mis;
    for (const auto& p : msi)
		mis[p.second]= p.first;


    std::cout << "mis:" << std::endl;
    for (const auto& p : mis)
		std::cout << p.first << ": " << p.second << std::endl;
    return 0;
}

