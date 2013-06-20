#include <iostream>
#include <list>

int main()
{
	std::list<int> a = {692, 1, 32};
	std::list<int> b = {0, 0, 0, 14, 15, 123, 2431};
	auto aa = a.begin(), bb = b.begin();

	for (; aa!=a.end(); ++aa)
	{
		while (*aa > *bb)
		{
			++bb;
		}
		b.pop_front();
		b.insert (bb, *aa);
		bb=b.begin();
	}

	for (auto i : b)
		std::cout<<i<<" "<<std::endl;
		
	return 0;
}
