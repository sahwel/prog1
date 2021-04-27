#include <iostream>
#include <vector>
#include <list>

struct Item
{
    std::string name;
    int iid;
    double value;

    Item(std::string nn, int id, double vv) {
        name = nn;
        iid = id;
        value = vv;
        //std::cout << name << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Item& i){
        return os << "Name: " << i.name << " ,  iid: " << i.iid << " , value: " << i.value <<std::endl;
    }
};

struct Item_order_name {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.name < b.name;
	}
};

struct Item_order_iid {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.iid < b.iid;
	}
};

struct Item_order_value {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.value > b.value;
	}
};

void write_out(std::vector<int> array){
     for(int i = 0; i < array.size(); i++){
       std::cout << array[i];
   } 
}

template<typename Iterator, typename T>
Iterator getPlace_byname(Iterator first, Iterator last, T c){
    while(first != last){
        if((*first).name == c) return first;
        first++;
    }
    return last;
}

template<typename Iterator, typename T>
Iterator getPlace_byiid(Iterator first, Iterator last, T c){
    while(first != last){
        if((*first).iid == c) return first;
        first++;
    }
    return last;
}


int main() {
    std::vector<Item> vi;
    std::list<Item> li;
    std::string nn;
    int id;
    double vv;

/*     std::cout */

    while(vi.size() < 10){
        std::cin >> nn >> id >> vv;
        Item newItem(nn, id, vv);
        vi.push_back(newItem);
        li.push_back(newItem);
        
    }
  

    //vector rendezés név szerint
	std::sort(vi.begin(), vi.end(), Item_order_name());
    std::cout << "Sorted by name vector:" << std::endl;
    for(int i = 0; i < li.size(); i++){
        std::cout << vi[i];
    }

   
    //vector rendezés név szerint
    std::sort(vi.begin(), vi.end(), Item_order_iid());
    std::cout << "Sorted by iid:" << std::endl;
    for(int i = 0; i < vi.size(); i++){
        std::cout << vi[i];
    } 

    
    //vector rendezés érték szerint
    std::sort(vi.begin(), vi.end(), Item_order_value());
    std::cout << "Sorted by value vector:" << std::endl;
    for(int i = 0; i < vi.size(); i++){
        std::cout << vi[i];
    } 


    vi.push_back( Item("horse shoe",99,12.34));
    vi.push_back( Item("Canon S400", 9988,499.95));


    std::cout << "vector after erease: " << std::endl;
    std::vector<Item>::iterator it;
    it = getPlace_byname(vi.begin(), vi.end(), "Canon S400");
    if(it != vi.end())
        vi.erase(it);

    it = getPlace_byname(vi.begin(), vi.end(), "horse shoe");
    if(it != vi.end())
        vi.erase(it);

    it = getPlace_byiid(vi.begin(), vi.end(), 312);
    if(it != vi.end())
        vi.erase(it);

    it = getPlace_byiid(vi.begin(), vi.end(), 7);
    if(it != vi.end())
        vi.erase(it);

     for(int i = 0; i < vi.size(); i++){
        std::cout << vi[i];
    } 
     std::cout << std::endl  << std::endl  << std::endl  << std::endl  << std::endl;

      //lista rendezés név szerint
    li.sort([](const Item & i, const Item & i2){ return i.name < i2.name; });
    std::cout << "Sorted by name list:" << std::endl;
    for(Item &item : li){
        std::cout << item;
    }
  
     //lista rendezés iid szerint
    li.sort([](const Item & i, const Item & i2){ return i.iid < i2.iid; });
    std::cout << "Sorted by iid list:" << std::endl;
     for(Item &item : li){
        std::cout << item;
    }

    //lista rendezés érték szerint
    li.sort([](const Item & i, const Item & i2){ return i.value > i2.value; });
    std::cout << "Sorted by iid list:" << std::endl;
     for(Item &item : li){
        std::cout << item;
    }

    li.push_back( Item("horse shoe",99,12.34));
    li.push_back( Item("Canon S400", 9988,499.95));

    std::cout << "list after erease: " << std::endl;
    std::list<Item>::iterator it_list;
    it_list = getPlace_byname(li.begin(), li.end(), "Canon S400");
    if(it_list != li.end())
        li.erase(it_list);

     it_list = getPlace_byname(li.begin(), li.end(), "horse shoe");
    if(it_list != li.end())
        li.erase(it_list);

    it_list = getPlace_byiid(li.begin(), li.end(), 312);
    if(it_list != li.end())
        li.erase(it_list);

    it_list = getPlace_byiid(li.begin(), li.end(), 7);
    if(it_list != li.end())
        li.erase(it_list);
 
    for(Item &item : li){
        std::cout << item;
    }
  
    return 0;
}

