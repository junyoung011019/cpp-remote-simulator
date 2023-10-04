#include <iostream>
#include <conio.h>
#include<windows.h>
using namespace std;

string now_channel(int num);

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13


class TV {
private:
	bool on;
	int channel;
	int volume;
public:
	TV() : on(false), channel(0), volume(15) {

	}

	void powerOn() {
		on = true;
		cout << "TV�� �������ϴ�.\n";
	}
	void powerOff() {
		on = false;
		cout << "TV�� �������ϴ�.\n";
	}
	void increaseChannel() {
		channel += 1;
		if (channel == 10) {
			channel = 0;
		}
		cout << "TV ä���� 1 �����߽��ϴ�.\n"<<now_channel(channel)<<"\n";
	}
	void decreaseChannel() {
		channel -= 1;
		if (channel == -1) {
			channel = 9;
		}
		cout << "TV ä���� 1 �����߽��ϴ�.\n"<< now_channel(channel) << "\n";
	}
	void increaseVolume() {
		if (volume == 30) {
			cout << "�� �̻� ������ �ø� �� �����ϴ�.\n" << volume << "\n";
		}
		else {
			volume += 1;
			cout << "TV ������ 1 �����߽��ϴ�.\n" << volume << "\n";
		}
		
	}
	void decreaseVolume() {
		if (volume == 0) {
			cout << "�� �̻� ������ ���� �� �����ϴ�.\n" << volume << "\n";
		}
		else {
			volume -= 1;
			cout << "TV ������ 1 �����߽��ϴ�.\n" << volume << "\n";
		}
	}
	bool isOn() {
		return on;
	}

	int channel_num() {
		return channel;
	}


};

string now_channel(int num) {
	switch (num) {
	case 0:
		return "ä�� 0 : �⺻ ä��";
		break;
	case 1:
		return "ä�� 1 : tvN";
		break;
	case 2:
		return "ä�� 2 : �Ե� Ȩ����";
		break;
	case 3:
		return "ä�� 3 : SBS";
		break;
	case 4:
		return "ä�� 4 : KBS2";
		break;
	case 5:
		return "ä�� 5 : KBS1";
		break;
	case 6:
		return "ä�� 6 : MBC";
		break;
	case 7:
		return "ä�� 7 : EBS";
		break;
	case 8:
		return "ä�� 8 : JTBC";
		break;
	case 9:
		return "ä�� 9 : MBN";
		break;
	default:
		return "�� �� ���� ä��";


	}
}

void function(TV& tv,char answer) {
	switch (answer) {
		case UP:
			tv.increaseChannel();
			break;
		case DOWN:
			tv.decreaseChannel();
			break;
		case RIGHT:
			tv.increaseVolume();
			break;
		case LEFT:
			tv.decreaseVolume();
			break;
		case ENTER:
			tv.powerOff();
			break;
		default:
			cout << "�߸��� ���Դϴ�.\n";
			
	}
}

int main() {
	TV tv;
	while (1) {
		if (tv.isOn()) {
				cout << "���� TV ���� : ON\n";
				cout << now_channel(tv.channel_num()) << "\n";
				cout << "����� �Է����ּ���.\n";
				
				char function_answer;
				function_answer = _getch();
				function(tv, function_answer);
				if (tv.isOn() == false) {
					Sleep(1000);
					system("cls");
				}
					
		}
		else{
			cout << "���� TV ���� : OFF\n";
			cout <<"TV�� �ѽðڽ��ϱ� ? (�� : Y / �ƴϿ� : N / ���α׷� ���� : E) > ";
			char power_answer;
			cin >> power_answer;
			if (power_answer == 'Y') {
				system("cls");
				tv.powerOn();
			}
			else if (power_answer != 'Y' && power_answer != 'N' && power_answer != 'E') {
				system("cls");
				cout << "�߸��� ���� �Է� �Ǿ����ϴ�. ���Է� ���ּ���.\n";
			}
			else if (power_answer == 'E') {
				cout << "���α׷��� �����մϴ�.";
				return 0;
			}
			//Ƽ�� ����������(power_answer�� N�̸�) �ݺ�
		}

	}

}