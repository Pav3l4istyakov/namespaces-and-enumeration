// ������������ ���-  ��� ������� ����������� ����������, �����, �������� � �������, ����������� � ������ ��� ������������� ����
// ������������-   ��� ������ ����������� �����, ������� �������� ����� �������� ��������
#include<iostream>
#include<string>
// ������������ ��� �������������� ��� ����, ����� ���������� �� � ���� ����, ��� �������� � ��������� ����
// ������������ ����� ��� ���� ����� ���������� ����� �������� ���������
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
            std::cout << "\t���: " << name << "\t�������: " << age << std::endl;
        }
    };

    class HouseResident : public Person {
    private:
        std::string RoomNumber;
    public:
        HouseResident(std::string n, int a, std::string room) : Person(n, a), RoomNumber(room) {}
        void DisplayResidentInfo() {
            DisplayInfo();
            std::cout << "\t����� �������: " << RoomNumber << std::endl;
        }
    };

    class HouseManager : public Person {
    private:
        std::string ManagementArea;
    public:
        HouseManager(std::string n, int a, std::string area) : Person(n, a), ManagementArea(area) {}
        void DisplayManagerInfo() {
            DisplayInfo();
            std::cout << "\t������� ����������: " << ManagementArea << std::endl;
        }
        void ManageHouse() {
            std::cout << name << "\t��������� ����� � ���� ������: " << ManagementArea << std::endl;
        }
    };
}

int main() {
    setlocale(LC_ALL, "RU");
    Housing::HouseResident resident("Alice", 30, "101");
    Housing::HouseManager manager("Bob", 45, "������� ���");
    std::cout << "���������� � ���������:" << std::endl;
    resident.DisplayResidentInfo();
    manager.ManageHouse();
    return 0;
}
