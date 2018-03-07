#include<iostream>
#include<cstdlib>
#include<ctime>
#include"stcktp.h"
const int Num = 10;
int main()
{
	std::srand(std::time(0));
	std::cout << "please enter stack size: ";
	int stacksize;
	std::cin >> stacksize;
	Stack<const char*> st(stacksize);
	const char* in[Num] = {
		"1","2","3","4","5","1","2","3","4","5"
	};
	const char* out[Num];
	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
	{
		std::cout << out[i] << std::endl;
	}
	std::cout << "Bye\n";
	system("pause");
	return 0;
}