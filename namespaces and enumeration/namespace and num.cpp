// Пространство имён-  это область определения переменных, типов, констант и функций, объединённая в единый или неименованный блок
// перечисления-   это способ определения типов, которые содержат набор числовых констант
#include<iostream>
#include<string>
// пространство имён использовалось для того, чтобы объеденить всё в один блок, для удобства и отработки темы
// перечесления нужны для того чтобы объединить набор числовых констатнт
namespace Housing {

    enum class Role {
        Resident,
        Manager
    };

    class Person {
    protected:
        std::string name;
        int age;
    public:
        Person(std::string n, int a) : name(n), age(a) {}
        void DisplayInfo() {
            std::cout << "\tимя: " << name << "\tвозраст: " << age << std::endl;
        }
    };

    class HouseResident : public Person {
    private:
        std::string RoomNumber;
    public:
        HouseResident(std::string n, int a, std::string room) : Person(n, a), RoomNumber(room) {}
        void DisplayResidentInfo() {
            DisplayInfo();
            std::cout << "\tномер комнаты: " << RoomNumber << std::endl;
        }
    };

    class HouseManager : public Person {
    private:
        std::string ManagementArea;
    public:
        HouseManager(std::string n, int a, std::string area) : Person(n, a), ManagementArea(area) {}
        void DisplayManagerInfo() {
            DisplayInfo();
            std::cout << "\tобласть управления: " << ManagementArea << std::endl;
        }
        void ManageHouse() {
            std::cout << name << "\tуправляет домом в этом районе: " << ManagementArea << std::endl;
        }
    };
}

int main() {
    setlocale(LC_ALL, "RU");
    Housing::HouseResident resident("Alice", 30, "101");
    Housing::HouseManager manager("Bob", 45, "главный зал");
    std::cout << "информация о резиденте:" << std::endl;
    resident.DisplayResidentInfo();
    manager.ManageHouse();
    return 0;
}
