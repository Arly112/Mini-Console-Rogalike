#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <random>

bool Has_name(std::vector<std::string>& weapons, std::string name_weapons);
void Base_Menu(Player& pl, int& ur_Or);
void Loots_Menu();
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<>dist(1,100);
class Player
{
private:
	int hpp, uronn, bas_ur, exp;
	std::string vubb;
public:
	std::vector<std::string>weapons;
	Player(int hp, int uron, std::string vub)
	{
		hpp = hp;
		uronn = uron;
		vubb = vub;
		bas_ur = uron;
		exp = 0;
	}

	void dam(int damm)
	{
		hpp -= damm;
		if (hpp <= 0)
		{
			hpp = 0;
		}
	}

	void Heel(int hel)
	{
		hpp += hel;
	}

	void Stat()
	{
		std::cout << "Здоровье:" << hpp << std::endl;
		std::cout << "Урон:" << uronn << std::endl;
		std::cout << "Ваше количество exp = " << exp << std::endl;
		std::cout << "Оружие в руке: " << vubb;
	}

	void WEP(std::string inv)
	{
		vubb = inv;
	}

	std::string RetVubb()
	{
		return vubb;
	}

	void Stat_oru(int& ur_Or)
	{
		std::string inv;
		std::cout << "Введите название оружия чей урон хотите узнать?"<<std::endl;
		std::getline(std::cin, inv);
		if (inv == "Кулаки" && Has_name(weapons, inv))
		{
			std::cout << "Урон: " << bas_ur;
		}
		else if (inv == "Кинжал" && Has_name(weapons, inv))
		{
			std::cout << "Урон: "<< ur_Or;
		}
		else if (inv == "Меч" && Has_name(weapons, inv))
		{
			std::cout << "Урон: " << ur_Or;
		}
		else if (inv == "Топор " && Has_name(weapons, inv))
		{
			std::cout << "Урон: " << ur_Or;
		}
		else if (inv == "Лук" && Has_name(weapons, inv))
		{
			std::cout << "Урон: " << ur_Or;
		}
		else if (inv == "Жезл мага" && Has_name(weapons, inv))
		{
			std::cout << "Урон: " << ur_Or;
		}
		else if (!Has_name(weapons, inv))
		{
			std::cout << "\nОружие " << inv << " ещё не найдено";
		}

	}

	void VAB_oru(int& ur_Or)
	{
		
		std::setlocale(LC_ALL, "ru");
		std::string inv;
		std::cout << "Введите название оружия какое хотите взять?" << std::endl;
		std::getline(std::cin, inv);
		if (inv == "Кулаки"&&Has_name(weapons,inv))
		{
			std::cout << "\nВы взяли оружие " <<inv;
			uronn = bas_ur;
			vubb = inv;
		}
		else if (inv == "Кинжал" && Has_name(weapons, inv))
		{
			std::cout << "\nВы взяли оружие " << inv;
			ur_Or = 5;
			Final_uron(ur_Or);
			uronn = bas_ur + ur_Or;
			vubb = inv;
		}
		else if (inv == "Меч" && Has_name(weapons, inv))
		{
			std::cout << "\nВы взяли оружие " << inv;
			ur_Or = 10;
			uronn = bas_ur + ur_Or;
			vubb = inv;
		}
		else if (inv == "Топор" && Has_name(weapons, inv))
		{
			std::cout << "\nВы взяли оружие " << inv;
			ur_Or = 16;
			uronn = bas_ur + ur_Or;
			vubb = inv;
		}
		else if (inv == "Лук" && Has_name(weapons, inv))
		{
			std::cout << "\nВы взяли оружие " << inv;
			ur_Or = 12;
			uronn = bas_ur + ur_Or;
			vubb = inv;
		}
		else if (inv == "Жезл мага" && Has_name(weapons, inv))
		{
			std::cout << "\nВы взяли оружие " << inv;
			ur_Or = 21;
			uronn = bas_ur + ur_Or;
			vubb = inv;
		}
		else if (inv == "Пасхалка")
		{
			system("start https://www.youtube.com/watch?v=c-eBWR_Mzbo");
		}
		else if(!Has_name(weapons,inv))
		{
			std::cout << "\n Оружие "<<inv<<" ещё не найдено";
		}
	}

	void SEE_Inv(int& ur_Or)
	{
		int vab;
		for (int i = 0; i < weapons.size(); i++)
		{
			if (i == (weapons.size() - 1))
			{
				std::cout << weapons[i];
			}
			else
				std::cout << weapons[i] << ',';
		}
		do
		{
			std::string pr;
			std::cout << "\n1.Выбрать оружие" << std::endl;
			std::cout << "2.Посмотреть урон оружия" << std::endl;
			std::cout << "0.Выйти из инвентаря" << std::endl;
			std::cin >> vab;
			std::cin.ignore(1000, '\n');
			switch (vab)
			{
			case 1: std::cout << "\n";
				VAB_oru(ur_Or);
				std::cout << "\n";
				break;
			case 2:std::cout << "\n";
				Stat_oru(ur_Or);
				std::cout << "\n";
				break;
			case 0:
				break;
			}
		} while (vab != 0);
	}

	int retUr()
	{
		return uronn;
	}

	int retHpp()
	{
		return hpp;
	}

	void retexp(int c)
	{
		exp += c;
	}

};

void Evil_Menu(Player& pl);
void Mobs_menu(Player& pl);
void Base_Menu(Player& pl, int& ur_Or);
void At(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);
void NoAt(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);
void Run(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);
void NoRun(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);
void Prow_VubRun(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);
void Vabor(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);

bool Has_name(std::vector<std::string>& weapons, std::string name_weapons)
{
	auto prow = std::find(weapons.begin(), weapons.end(), name_weapons);
	return prow != weapons.end();
}

void Events(Player& pl)
{
	int event = dist(gen);

	if (event < 30)
	{
		Mobs_menu(pl);
	}
	else if (event > 30 && event < 45)
	{
		//Loots_Menu();
	}
	else if (event > 45 && event < 75)
	{
		Evil_Menu(pl);
	}
	else if (event > 75 && event <= 100)
	{
		//NOP_Menu();
	}
}

void Final_uron(int p)
{
	int Change = dist(gen);
	double mnosh;
	std::string name;
	if (Change <= 50)
	{
		name = "Обычное";
		mnosh = 1;
	}

	if (Change > 50&&Change<=75)
	{
		name = "Необычное";
		mnosh = 1.2;
	}

	if (Change > 75 &&Change<=90)
	{
		name = "Редкое";
		mnosh = 1.5;
	}

	if (Change > 91 &&Change<=98)
	{
		name = "Эпическое";
		mnosh = 1.8;
	}

	if (Change > 98 &&Change<=100)
	{
		name = "Легендарное";
		mnosh = 2.5;
	}

	p *= mnosh;
}

void Mobs_menu(Player& pl)
{
	int mob = dist(gen);
	int Hp_mobs, Damage_mobs, expm;
	Hp_mobs = 0;
	Damage_mobs = 0;
	expm = 0;
	std::string mobl;
	bool escp;
	escp = false;

	if (mob <= 25)
	{
		mobl = "Ведьма";
		Hp_mobs = 35;
		Damage_mobs = 6;
		expm = 30;
	}

	else if (mob > 25 && mob <= 45)
	{
		mobl = "Скелет";
		Hp_mobs = 25;
		Damage_mobs = 5;
		expm = 20;
	}

	else if (mob > 45 && mob < 75)
	{
		mobl = "Слизень";
		Hp_mobs = 20;
		Damage_mobs = 3;
		expm = 15;
	}
	
	else if (mob > 75 && mob < 99)
	{
		mobl = "Летучая мышь";
		Hp_mobs = 15;
		Damage_mobs = 5;
		expm = 10;
	}
	else if (mob == 100)
	{
		mobl = "Пасхалку";
		system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
	}
	else if (mob == 99)
	{
		mobl = "Херобрин";
		Hp_mobs = 500;
		Damage_mobs = 100;
		expm = 495;
	}

	std::cout << "==========ВНИМАНИЕ==========" << std::endl;
	std::cout << "Вы встретили " << mobl << std::endl;
	std::cout << std::endl;

	do
	{
		if (escp == true)
		{
			break;
		}
		Vabor(pl, mobl, Hp_mobs, Damage_mobs, escp);
		if (escp == true)
		{
			break;
		}
	} while (Hp_mobs > 0 && pl.retHpp() > 0 && escp == false);

	if (Hp_mobs <= 0)
	{
		std::cout << "Поздравляем вы убили " << mobl << " вы получили " << expm << " единиц опыта" << std::endl;

		pl.retexp(expm);

	}

}

void Prow_VubAt(Player& pl, std::string& mobl, int& Hp_mobs,int& Damage_mobs,bool& escp)
{
	int vubAT = dist(gen);
	if (vubAT <= 60)
	{
		At(pl, mobl, Hp_mobs,Damage_mobs,escp);
	}

	if (vubAT > 60 && vubAT<=100)
	{
		NoAt(pl, mobl, Hp_mobs, Damage_mobs, escp);
	}

}

void Prow_VubRun(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp)
{
	int vubRun = dist(gen);
	if (vubRun <= 60)
	{
		Run(pl, mobl, Hp_mobs, Damage_mobs, escp);
	}

	if (vubRun > 60 && vubRun <= 100)
	{
		NoRun(pl, mobl, Hp_mobs, Damage_mobs, escp);
	}

}

void Vabor(Player& pl, std::string& mobl, int& Hp_mobs,int& Damage_mobs,bool& escp)
{
	int vub;

	std::cout << "Ваши действия?" << std::endl;
	std::cout << "1.Атака" << std::endl;
	std::cout << "2.Попытаться скрыться" << std::endl;
	std::cin >> vub;
	switch (vub)
	{
	case 1:Prow_VubAt(pl, mobl, Hp_mobs,Damage_mobs, escp);
		break;
	case 2:Prow_VubRun(pl, mobl, Hp_mobs,Damage_mobs, escp);
		break;
	default:
		break;
	}
}

void At(Player& pl,std::string& mobl,int& Hp_mobs, int& Damage_mobs,bool& escp)
{
	
	std::cout << "Вы Атаковали " << mobl<<" и нанесли ему(ей) "<< pl.retUr() << std::endl;
	Hp_mobs -= pl.retUr();
	if (Hp_mobs<=0)
	{
		Hp_mobs = 0;
	}
	std::cout << "Его(её) ХП = " << Hp_mobs << std::endl;
	std::cout << std::endl;
}

void NoAt(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp)
{
	if (pl.retHpp() == 0)
	{
		std::cout<<"Вы проиграли!! Вы мертвы!!"<< std::endl;
		return;
	}

	std::cout << "Неудача. Вас в ответ атаковал(а) " << mobl << " и нанёс вам " <<Damage_mobs<< std::endl;
	pl.dam(Damage_mobs);
	std::cout << "Ваш хп стал равен = " << pl.retHpp()<< std::endl;
	std::cout << std::endl;
}

void Run(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp)
{
	escp = true;
	std::cout << "Вы смогли убежать от " << mobl <<" !!!"<< std::endl;
}

void NoRun(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp)
{	
	escp = false;
	std::cout << "Вы к сожалению не смогли убежать от " << mobl<< " !!!" << std::endl ;
	std::cout << "Вам нанесено "<<(Damage_mobs/2)<<" урона" << std::endl;
	pl.dam((Damage_mobs /2));
	std::cout << "Ваш хп стал равен = "<< pl.retHpp() << std::endl;
	std::cout << std::endl;
	std::cout << mobl<<" вас догнал(а)" << std::endl;
}




void Evil_Menu(Player& pl)
{
	int evil = dist(gen);
	int evur;
	if (evil <= 25)
	{
		std::cout << "Вы зашли в тёмную-тёмную комнату, и когда проходили глубже, увидели много красных глаз. Это была стая летучих мышей" << std::endl;
		std::cout << "Они все вылетили на вас и поцарапали вас!!" << std::endl;
		evur = 5;
		std::cout << "Вы получили "<<evur<<" единиц урона" << std::endl;
		pl.dam(evur);
	}

	if (evil > 25 && evil <= 45)
	{
		std::cout << "Вы прошли дальше но наступили в медвежий капкан, вы пытаетесь осободиться" << std::endl;
		std::cout << "Через некоторое время вам всё же удалось удалось это сделать но из - за кровотечения ";
		evur = 8;
		std::cout << "вы получили " << evur << " единиц урона" << std::endl;
		pl.dam(evur);
	}

	if (evil > 45 && evil <= 50)
	{
		std::cout << "Вы зашли в хорошо осветлённую комнату, там на столе стояла бутылочка с красной жидкостью." << std::endl;
		std::cout << "У вас разыгралась жажда и вы решили выпить эту жидкость." << std::endl;
		std::cout << "И к счастью вам повезло и вы";
		evur = 6;
		std::cout << " востановили " << evur << " единиц  здоровья" << std::endl;
		pl.Heel(evur);
	}

	if (evil > 50 && evil <= 80&&pl.retHpp()>12)
	{
		std::cout << "Вы наступили на скрытую плиту в полу..." << std::endl;
		std::cout << "Из стены вылетела стрела и попала вам в плечо и задела важный сосуд но вы успели остановить кровотечение!" << std::endl;
		std::cout << "Но из-за потери крови вы ";
		evur = 12;
		std::cout << "получили " << evur << " единиц  здоровья" << std::endl;
		pl.dam(evur);
	}

	if (evil > 50 && evil <= 80&&pl.retHpp()<=12)
	{
		std::cout << "Вы наступили на скрытую плиту в полу..." << std::endl;
		std::cout << "Из стены вылетела стрела и попала вам в плечо и задела важный сосуд и вы истекли кровью!!" << std::endl;
		evur = 12;
		pl.dam(evur);
	}

	if (evil > 80 && evil < 100)
	{
		std::cout << "Вы задели рычаг на стене и из щелей в полу повалил зелёный дым..." << std::endl;
		std::cout << "Ядовитый газ обжёг ваши лёгкие!" << std::endl;
		evur = 9;
		std::cout << " Вы получили " << evur << " единиц  урона" << std::endl;
		pl.dam(evur);
	}

	if (evil==100)
	{
		std::cout << "Вы не заметили яму под ногами и провалились вниз!" << std::endl;
		std::cout << "Острые колья пронзили вас насквозь!" << std::endl;
		std::cout << " Вы погибли мгновенно " << std::endl;
		pl.dam(pl.retHpp());
	}

}

void Base_Menu(Player& pl,int& ur_Or)
{
	int vab;
	do
	{
		std::cout << "\n1.Открыть инвентарь" << std::endl;
		std::cout << "2.Открыть статистику игрока" << std::endl;
		std::cout << "3.Шаг вперёд" << std::endl;
		std::cout << "4.Очистить консоль" << std::endl;
		std::cout << "0.Закрыть игру" << std::endl;
		std::cin >> vab;

		switch (vab)
		{
		case 1: std::cout << "\n";
			pl.SEE_Inv(ur_Or);
			std::cout << "\n";
			break;
		case 2:std::cout << "\n";
			pl.Stat();
			std::cout << "\n";
			break;
		case 3:std::cout << "\n";
			Events(pl);
			if (pl.retHpp() == 0)
			{
				std::cout << "Вы проиграли";
				return;
			}
			std::cout << "\n";
			break;
		case 4:system("cls");
			break;
		case 0:std::cout << "\nХорошего вам дня!!";
			break;
		}
	} while (vab != 0);
}

void Loots_Menu()
{
	int loot = dist(gen);
	int ur_Or;
	std::string name_Weopens;
	if (loot <=35)
	{
		name_Weopens = "Кинжал";
	}
	
}

void NOP_Menu()
{
	int no = dist(gen);

	if (no <= 30)
	{
		std::cout << "Вы зашли в пещеру." << std::endl;
		std::cout <<"Вы идя по пещере краем глаза замечаете как будто, что то хочет на вас напасть.Вы резко поворачиваетесь а это была просто большая коряга." << std::endl;
		std::cout <<"Вы её пнули за то что напугала и пошли дальше.";
	}

	else if (no>30&& no<50)
	{

		std::cout <<"Вы вышли на лесную дорожку." << std::endl;
		std::cout <<"Идя по ней вы так засмотрелись на красоты что головой попали в паутину.А вы с детства боитесь пауков(Чтобы побороть подобные страхи вы и стали ходить в подобные походы)!!" << std::endl;
		std::cout <<"Вы в скором времени убрали с лица и головы всю паутину и переведя дух от этого пошли дальше";
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::setlocale(LC_ALL, "ru");
	Player pl(20, 3, "Кулаки");
	pl.weapons.push_back("Кулаки");
	Base_Menu(pl,ur_Or);


}
