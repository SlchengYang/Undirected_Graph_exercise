#include"graph.h"
int main()
{
	Graph a;
	Is_Twocolor x(&a);
	cout << x.get_tc();
}