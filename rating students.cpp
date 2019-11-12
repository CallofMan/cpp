#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

struct Students
{
	std::string name;
	int point;
};

// ����������
void sortStudents(Students *students, int &length)
{
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		int largestIndex = startIndex;
		
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (students[currentIndex].point > students[largestIndex].point)
				largestIndex = currentIndex;
		}
		std::swap(students[startIndex], students[largestIndex]);
	}
}

int main() 
{
	using namespace std;
	
	int quantityStudents = 0;
	
	// ������ �������� � ����������� 
	while (true)
	{
		cout << "Enter a quantity students (0 to 100): ";
		cin >> quantityStudents;
		
		if (cin.fail() || quantityStudents < 0 || quantityStudents > 100)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			
			cout << "You entered incorrect value. Try again! \n" << endl;
		}
		else break;
	}
	
	// ������ ������ � ����� ������ ����� ���������  
	Students *students = new Students[quantityStudents];
	
	// ���������� ������� ����������������� ����������		
	for (int index = 0; index < quantityStudents; ++index)
	{
		cout << "Enter a student's name: ";
		cin >> students[index].name;
		
		// ���� �������� �� ���������� ��������
		while (true)
		{
			cout << "Enter a student's point: ";
			cin >> students[index].point;
			
			if(cin.fail() || students[index].point < 0 || students[index].point > 100)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				
				cout << "You entered incorrect value. Try again!\n";
			}
			else break;
		}
	}
	
	int &length = quantityStudents;
	
	// ���������
	sortStudents(students, length);
	
	// ����� ����������
	for (int index = 0; index < quantityStudents; ++index)
	{
		cout << students[index].name << " got a grade of " << students[index].point << endl;
	}
	
	return 0;
}
