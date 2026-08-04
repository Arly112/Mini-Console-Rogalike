#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <random>

class Player;
void Base_Menu(Player& pl);
void Loots_Menu(Player& pl);
void Final_uron(int& p, std::string& stat);
void NOP_Menu();
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<>dist(1,100);

struct Weapon
{
	std::string name_weapon,stat;
	int uron;

};

class Player
{
private:
	int hpp, uronn, bas_ur, exp;
	std::string vubb;
public:
	std::vector<Weapon>weapons;
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

	void Stat_oru()
	{
		std::string inv;
		int ind;
		std::cout << "Введите номер оружия чей урон хотите узнать?"<<std::endl;
		std::cin>>ind;

		if (ind<0 || ind>weapons.size())
		{
			std::cout << "\nОружия под данным номером нет" << std::endl;
			return;
		}

		std::cout << "Урон оружия " << weapons[ind].stat << ' ' << weapons[ind].name_weapon << " равен " << weapons[ind].uron<<std::endl;

	}

	void VAB_oru()
	{
		
		std::setlocale(LC_ALL, "ru");
		std::string inv;
		int ind;
		std::cout << "Введите номер оружия которое хотите взять?" << std::endl;
		std::cin >> ind;

		if (ind == -1)
		{
			system("start https://www.youtube.com/watch?v=c-eBWR_Mzbo");
			return;
		}

		if (ind<-1 || ind>= weapons.size())
		{
			std::cout << "\nОружия под таким номером нет";
			return;
		}
		std::cout << "Вы взяли " << weapons[ind].name_weapon;
		
		uronn = (bas_ur + weapons[ind].uron);
		vubb = weapons[ind].stat + ' ' + weapons[ind].name_weapon;
	}

	void SEE_Inv()
	{
		int vab;
		for (int i = 0; i < weapons.size(); i++)
		{
			if (i == (weapons.size() - 1))
			{
				std::cout<<i<<'.' << weapons[i].stat << ' ' << weapons[i].name_weapon;
			}
			else
				std::cout << i << '.' << weapons[i].stat << ' ' << weapons[i].name_weapon << ',';
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
				VAB_oru();
				std::cout << "\n";
				break;
			case 2:std::cout << "\n";
				Stat_oru();
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
void At(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);
void NoAt(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);
void Run(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);
void NoRun(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);
void Prow_VubRun(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);
void Vabor(Player& pl, std::string& mobl, int& Hp_mobs, int& Damage_mobs, bool& escp);


void Events(Player& pl)
{
	int event = dist(gen);

	if (event < 30)
	{
		Mobs_menu(pl);
	}
	else if (event > 30 && event < 45)
	{
		Loots_Menu(pl);
	}
	else if (event > 45 && event < 75)
	{
		Evil_Menu(pl);
	}
	else if (event > 75 && event <= 100)
	{
		NOP_Menu();
	}
}

void Final_uron(int& p, std::string& stat)
{
	int Change = dist(gen);
	double mnosh;
	mnosh = 1.0;
	std::string name_oru;
	if (Change <= 50)
	{
		stat = "Обычное";
		mnosh = 1;
	}

	else if (Change > 50&&Change<=75)
	{
		stat = "Необычное";
		mnosh = 1.2;
	}

	else if (Change > 75 &&Change<=90)
	{
		stat = "Редкое";
		mnosh = 1.5;
	}

	else if (Change > 90 &&Change<=98)
	{
		stat = "Эпическое";
		mnosh = 1.8;
	}

	else if (Change > 98 &&Change<=100)
	{
		stat = "Легендарное";
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
		return;
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

void Base_Menu(Player& pl)
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
			pl.SEE_Inv();
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

void Loots_Menu(Player& pl)
{
	int loot = dist(gen);
	Weapon oru;
	if (loot <=35)
	{
		oru.name_weapon="Кинжал";
		oru.uron = 5;
	}

	else if (loot >35 && loot<=60)
	{
		oru.name_weapon = "Меч";
		oru.uron = 10;
	}

	else if (loot >60 && loot<=80)
	{
		oru.name_weapon = "Лук";
		oru.uron = 12;
	}

	else if (loot >80 && loot<=90)
	{
		oru.name_weapon = "Топор";
		oru.uron = 16;
	}

	else if (loot >90 && loot<=100)
	{
		oru.name_weapon = "Жезл мага";
		oru.uron = 21;
	}

	Final_uron(oru.uron,oru.stat);
	std::cout << "Вам выпало " << oru.stat << " оружие " << oru.name_weapon <<" с уроном равным "<<oru.uron;
	pl.weapons.push_back(oru);
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

	else if (no >30&& no <= 50)
	{

		std::cout <<"Вы вышли на лесную дорожку." << std::endl;
		std::cout <<"Идя по ней вы так засмотрелись на красоты что головой попали в паутину.А вы с детства боитесь пауков(Чтобы побороть подобные страхи вы и стали ходить в подобные походы)!!" << std::endl;
		std::cout <<"Вы в скором времени убрали с лица и головы всю паутину и переведя дух от этого пошли дальше";
	}

	else if (no > 50 && no <= 65)
	{
		std::cout << "Вы прошли мимо старого дуба." << std::endl;
		std::cout << "На ветке сидела сова и пристально смотрела на вас, но ничего не сказала." << std::endl;
		std::cout << "Вы решили, что мудрый взгляд — это не повод для разговора, и пошли дальше.";
	}

	else if (no > 65 && no <= 80)
	{
		std::cout << "Вы нашли небольшой ручей." << std::endl;
		std::cout << "Вода была прохладной и чистой. Вы напились, помыли лицо и даже немного отдохнули." << std::endl;
		std::cout << "Никакой пользы для дела, но приятно.";
	}

	else if (no > 80 && no <= 95)
	{
		std::cout << "В траве что-то шевельнулось." << std::endl;
		std::cout << "Вы напряглись, схватились за оружие... но это оказался просто ежик." << std::endl;
		std::cout << "Ёжик уставился на вас, фыркнул и убежал в кусты. Вы чувствовали себя немного неловко.";
	}

	else if(no > 95 && no <= 100)
	{
		std::cout << "Вы услышали странный шум позади себя." << std::endl;
		std::cout << "Резко обернувшись, вы увидели... свой собственный след." << std::endl;
		std::cout << "Похоже, вы ходите по кругу уже второй час. Или это вам кажется.";
	}

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::setlocale(LC_ALL, "ru");
	Player pl(20, 3, "Кулаки");
	Weapon Base;
	Base.name_weapon = "Кулаки";
	Base.uron = 3;
	pl.weapons.push_back(Base);
	Base_Menu(pl);


}
