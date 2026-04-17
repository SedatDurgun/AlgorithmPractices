#include <iostream>
#include <optional>
#include <functional>
#include <string>



std::optional<int> doIntDivision(int x
,int y)
{
	if(y==0)
		return std::nullopt;
	return x / y;
}
struct Person
{
	std::string  name;
	int id;
};

void printPerson(std::optional<std::reference_wrapper<Person>> person)
{
	if (person)
	{
		std::cout << "Person Name:" << person->get().name << "\nPerson ID:" << person->get().id << '\n';
	}
	else
	{
		std::cout << "Person information is not available.\n";
	}
}

int main()
{
	std::optional<int> resultX = doIntDivision(40, 40);
	if (resultX)
	{
		std::cout << "Result X :" << *resultX<<'\n';
	}
	else
	{
		std::cout << "Result X,Division by zero is not allowed.\n";
	}

	std::optional<int> resultY = doIntDivision(40,0);
	if (resultY)
	{
		std::cout << "Result Y:" << *resultY << '\n';
	}
	else 
	{
		std::cout << "Division by zero is not allowed.\n";
	}



	//hasvalue  :It is a member function of the std::any class template and is used to check whether an object contains any value.
	// std::reference_wrapper : It is a class template that makes references into copyable and assignable objects. (<functional> header)
 
	std::optional<int> val1{ 44 };
	std::optional<int> val2{ std::nullopt }; //or std::optional<int> val2; std::optiona<int> val2= std::nullptr both are same


	if(val1.has_value())
		std::cout << "val1 has value:" << *val1 << '\n';
	else
	{
		std::cout << "val1 does not have value.\n";
	}
	if (val2.has_value())
	{
		std::cout << "Val2 has a value" << *val2 << '\n';
	}
	else
	{ 
		std::cout << "val2 does not have value.\n";
		
	}

	printPerson(std::nullopt); // No person information available or you can also pass std::optional<std::reference_wrapper<Person>> person = std::nullopt; to the function printPerson
	Person person{ "Alice", 123 };
	printPerson(std::make_optional<std::reference_wrapper<Person>>(person)); // Person information is available

	return 0;
}