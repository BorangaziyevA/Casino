#include "automatConsole.h"

automatConsole::automatConsole()
	:model(0, 0)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int r = 10 + rand() % 5;
	int x = 0;
	for (size_t i = 0; i < r; i++)
	{
		cout << "����� ���������� � ����!\n";
		cout << "��������\n";
		for (size_t i = 0; i < x; i++)
		{
			cout << ".";
		}
		Sleep(300);
		x++;
		if (x == 4)
		{
			x = 0;
		}
		system("cls");
	}
}

void automatConsole::start()
{
	system("cls");
	addMoneyMenu();
	Sleep(5000);
	changeBetMenu();
	Sleep(5000);


	int choice = 0;
	while (choice != 4)
	{
		mainMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (!model.play())
			{
				cout << "������������ �������" << endl;
				cout << "������� ������ ��� ��������� ������" << endl;
			}
			break;
		case 3:
			addMoneyMenu();
			break;
		case 2:
			changeBetMenu();
			break;
		case 4:
			cout << "�� ��������" << endl;
			cout << "��� ������� ���������� " << model.getMoney() << " ����";
			break;
		default:
			cout << "������, ���������� ������" << endl;
		}
	}
}

void automatConsole::mainMenu()
{
	system("cls");
	cout << "__________________________________________________" << endl;
	cout << ".\t.\t.\t" << model[0] << " " << model[1] << " " << model[2] << "\t.\t.\t." << endl;
	cout << "__________________________________________________" << endl;
	cout << "��� ������ ����� " << model.getMoney() << " ����\n";
	cout << "���� ������: " << model.getBet() << endl;
	cout << "1.�������\n2.�������� ������\n3.�������� ������\n4.����� �� ����\n";

}

void automatConsole::addMoneyMenu()
{
	system("cls");
	cout << "��� ������ ����� " << model.getMoney()<< " ����\n";
	cout << "������� ������:\n";
	int money;
	cin >> money;
	model.addMoney(money);
	cout << "���������� ������ �������\n";
}

void automatConsole::changeBetMenu()
{
	system("cls");
	cout << "���� ������: " << model.getBet() << endl;
	cout << "������� ������\n";
	int money;
	cin >> money;
	model.setBet(money);
	cout << "������ �����������\n";
}

void automatConsole::CoeffsMenu()
{
	system("cls");
	cout << "�������\n";
}
