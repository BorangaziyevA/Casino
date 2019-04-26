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
		cout << "Добро пожаловать в игру!\n";
		cout << "Загрузка\n";
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
				cout << "Недостаточно средств" << endl;
				cout << "Введите деньги или поменяйте ставку" << endl;
			}
			break;
		case 3:
			addMoneyMenu();
			break;
		case 2:
			changeBetMenu();
			break;
		case 4:
			cout << "До свидания" << endl;
			cout << "Ваш выигрыш составляет " << model.getMoney() << " евро";
			break;
		default:
			cout << "Ошибка, попробуйте заново" << endl;
		}
	}
}

void automatConsole::mainMenu()
{
	system("cls");
	cout << "__________________________________________________" << endl;
	cout << ".\t.\t.\t" << model[0] << " " << model[1] << " " << model[2] << "\t.\t.\t." << endl;
	cout << "__________________________________________________" << endl;
	cout << "Ваш баланс равен " << model.getMoney() << " евро\n";
	cout << "Ваша ставка: " << model.getBet() << endl;
	cout << "1.Сыграть\n2.Изменить ставку\n3.Добавить деньги\n4.Выйти из игры\n";

}

void automatConsole::addMoneyMenu()
{
	system("cls");
	cout << "Ваш баланс равен " << model.getMoney()<< " евро\n";
	cout << "Введите деньги:\n";
	int money;
	cin >> money;
	model.addMoney(money);
	cout << "Транзакция прошла успешно\n";
}

void automatConsole::changeBetMenu()
{
	system("cls");
	cout << "Ваша ставка: " << model.getBet() << endl;
	cout << "Введите ставку\n";
	int money;
	cin >> money;
	model.setBet(money);
	cout << "Ставка установлена\n";
}

void automatConsole::CoeffsMenu()
{
	system("cls");
	cout << "Справка\n";
}
