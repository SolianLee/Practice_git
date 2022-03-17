#include <iostream>
#include <cstdlib>

using namespace std;

struct Subject{//���� ����
	char SubName[30];  //�����̸�
	int Hakjum;  //��������
	char Grade[10];  //������
	float GPA;	//���� ����
};
struct Student{//�л�����
	char StdName[30];	//�л��̸�
	int Hakbun;	//�й�
	Subject Sub[3];	//����
	float AveGPA;	//������ ��� ����
};

void selected_menu(int choice);	//��� �ҷ����� �Լ�
float get_gradenum(char grade[]);	//�Է� ���� ������ �������� �ٲ��ִ� �Լ�

int load_menu();	//�޴� ���

struct Student stu_list[2]; //�л� ��: 2��

int main()
{
	while(1)
	{
		int choice = load_menu();	//�޴��� �ҷ��� ���� ����
		selected_menu(choice);		//��� �ҷ�����
	}
	return EXIT_SUCCESS;	//��������
}
int load_menu()	//�޴� �ҷ�����
{
	int choice;
	cout << "----- �޴� -----" << endl;
	cout << "1. �л� ���� �Է�" << endl;
	cout << "2. ��ü �л� ���� ����" << endl;
	cout << "3. ���α׷� ����\n" << endl;
	cout << "���ϴ� ����� �Է��ϼ���: ";
	cin >> choice;
	if (choice == 3)	//3�Է½� ����
	{
		cout << "\n���α׷��� �����մϴ�.";
		exit(0);
	}
	if (1 > choice || choice > 3) 
	{
		cout << "�߸��Է��ϼ̽��ϴ�. \n" << endl;
		load_menu();
	}
	return choice;
}
void selected_menu(int choice)		//��� �ҷ�����
{
	switch (choice)
	{
		case 1:	//�л��� �����Է�
			for (int k = 0; k < 2; k++)
			{
				cout << "* " << k+1 << " ��° �л� �̸��� �й��� �Է��ϼ���." << endl;
				cout << "�̸� : ";
				cin >> stu_list[k].StdName;
				cout << "�й� : ";
				cin >> stu_list[k].Hakbun;
				cout << "\n\n\n" << endl;

				cout << "* ������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���.\n" << endl;
				
				float add_GPA = 0;

				for (int i = 0; i < 3; i++)
				{
					cout << "������� : ";
					cin >> stu_list[k].Sub[i].SubName;
					cout << "���������� : ";
					cin >> stu_list[k].Sub[i].Hakjum;
					cout << "������(A+~F) : ";
					cin >> stu_list[k].Sub[i].Grade;
					stu_list[k].Sub[i].GPA = stu_list[k].Sub[i].Hakjum * get_gradenum(stu_list[k].Sub[i].Grade); // ������ ���� ���
					
					add_GPA += stu_list[k].Sub[i].GPA;	// �������� ���ϱ�
					stu_list[k].AveGPA = add_GPA / 3;	//���� �л��� ������ ��� ���� ���
					cout << "\n";
				}
			}
			cout << "\n\n\n" << endl;
			break;
		case 2: //��ü �л��� �Ż�/���� ���� ���
			cout << "\n		��ü�л� ��������" << endl;
			cout << "=======================================================" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout.width(10);
				cout << "�̸�: " << stu_list[i].StdName;
				cout.width(10);
				cout<< "�й�: " << stu_list[i].Hakbun << endl;
				cout << "=======================================================" << endl;
				cout.width(10);
				cout << "����� ";
				cout.width(10);
				cout << "�������� ";
				cout.width(10);
				cout << "������ ";
				cout.width(10);
				cout << "�������� " << endl;
				cout << "=======================================================" << endl;
				for (int k = 0; k < 3; k++)
				{
					cout.width(10);
					cout << stu_list[i].Sub[k].SubName;
					cout.width(10);
					cout << stu_list[i].Sub[k].Hakjum;
					cout.width(10);
					cout << stu_list[i].Sub[k].Grade;
					cout.width(10);
					cout << fixed;
					cout.precision(2);
					cout << stu_list[i].Sub[k].GPA << endl;
				}
				cout << "=======================================================" << endl;
				cout << "\t\t\t\t\t\t��� ����: " << "\t";
				cout << fixed;
				cout.precision(2);
				cout << stu_list[i].AveGPA << endl;
			}
			break;
	}
}
float get_gradenum(char grade[]) //�Է� ���� ���ڸ� �������� ��ȯ
{
	float gradenum;
	switch (grade[0])
	{
	case 'A':
		gradenum = (grade[1] == '+') ? 4.5 : 4.0;
		break;
	case 'B':
		gradenum = (grade[1] == '+') ? 3.5 : 3.0;
		break;
	case 'C':
		gradenum = (grade[1] == '+') ? 2.5 : 2.0;
		break;
	case 'D':
		gradenum = (grade[1] == '+') ? 1.5 : 1.0;
		break;
	default:
		if (grade[0] == 'F')
			gradenum = 0;
		else
		{
			cout << "�߸��Է��ϼ̽��ϴ�.\n" << endl;
			cout << "������(A+~F) : ";
			cin >> grade;
			gradenum = get_gradenum(grade);	//***�߸� �Էµ� ��� �ٽ� �Է� �ް� ��ȯ
		}
		break;
	}
	return gradenum;
}