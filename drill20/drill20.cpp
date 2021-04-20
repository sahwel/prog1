#include <iostream>
#include <vector>
#include <list>
template<typename In, typename Out>
Out mycopy(In first, In last, Out res)
{
    if(first == last) return res;
    while (first!=last) {
        *res = *first; 
        ++res;
        ++first;
    }
return res;
}

template<typename Iterator>
void addValue(Iterator first, Iterator last, int num){
    while(first != last){
        *first += num;
        first++;
    }
}
int main() {

    int array[] =  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> v = {0, 1, 2, 1, 4, 3, 6, 7, 8, 9};
    std::list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 
    int* array2 = array;
    std::vector<int> v2 = v;
    std::list<int> l2 = l;

    addValue(std::begin(array), std::end(array),2);
    //addValue(v.begin(), v.end(), 3);
    addValue(l.begin(), l.end(),5);

    //mycopy(std::begin(array), std::end(array), v.begin());
    //mycopy(l.begin(), l.end(), std::begin(array));


    if(std::find(v.begin(), v.end(), 3) == v.end())
        std::cout << "Nincs benne" << std::endl;
    else    
        std::cout << "Benne van: " << -( v.begin() - std::find(v.begin(), v.end(), 3)) <<std::endl;
    return 0;
}

