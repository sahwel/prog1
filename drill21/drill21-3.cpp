#include <iostream>
#include <vector>
#include <numeric>
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

template<typename Iterator, typename Out, typename Pred>
Out my_copy_if (Iterator first, Iterator last, Out res, Pred pred)
{
	while (first != last){
		if (pred(*first))
			*res++ = *first;
		++first;
	}
	return res;
}

template<typename T>
void write(T t){
    for (const auto& elem : t)
		std::cout << elem <<  " ";
    std::cout << std::endl;
}

template<typename In, typename D>
D mean(In first, In last, D d, int size){
   while(first != last){
		d += *first;
        ++first;
   }
    return d/size;
}

int main() {
    
    std::vector<double> vd;
    for(float num; std::cin >> num; )
        vd.push_back(num);
    std::vector<int> vi(vd.size());
    mycopy(vd.begin(), vd.end(), vi.begin());
    std::cout << "Vd:" << std::endl;
    write(vd);
    std::cout << std::endl;
    std::cout << "Both:" << std::endl;
    for (int i = 0; i < vd.size(); i++)
    {
       std::cout << vd[i] << ", " << vi[i] << std::endl;
    }

    std::cout << std::endl;
    auto vd_sum = std::accumulate(vd.begin(), vd.end(), .0);
    std::cout << "Sum: " <<  vd_sum  << std::endl;

    std::cout << std::endl;
    auto vi_sum = std::accumulate(vi.begin(), vi.end(), .0);
    std::cout << "Difference: " << (vd_sum - vi_sum)  << std::endl;


    std::cout << std::endl;
    std::reverse(vd.begin(), vd.end());
    std::cout << "After reverse: " << std::endl;
    write(vd);

    std::cout << std::endl;
    auto vd_mean = mean(vd.begin(), vd.end(), .0, vd.size());
    std::cout << "Vd mean: " << vd_mean << std::endl;

    std::vector<double> vd2(vd.size());

    std::cout << std::endl;
    std::cout << "Vd2:" << std::endl;
    my_copy_if(vd.begin(), vd.end(), vd2.begin(), [vd_mean](int x) -> bool { return x < vd_mean; });
    write(vd2);


    std::cout << std::endl;
    std::cout << "Vd after sort:" << std::endl;
    std::sort(vd.begin(), vd.end());
    write(vd);
    return 0;
}

