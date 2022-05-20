#include "Player.cpp"
class Goalkeeper:public Player
{
	private:
	string reflexesAble;
	int numOfKeptCleanSheet;
	int goalSaveRate;
	public:
	void setreflexesAble(string reflexesAble)
	    this->reflexesAble=reflexesAble;
	string getreflexesAble(string reflexesAble)
	    return this->reflexesAble;
	void setnumOfKeptCleanSheet(int numOfKeptCleanSheet)
	    this->numOfKeptCleanSheet=numOfKeptCleanSheet;
	int getnumOfKeptCleanSheet(int numOfKeptCleanSheet)
	    return this->numOfKeptCleanSheet;
	void setgoalSaveRate(int goalSaveRate)
	    this->goalSaveRate=goalSaveRate;
	int getgoalSaveRate(int goalSaveRate)
	    return this->goalSaveRate;
	Goalkeeper()
	{
	this->reflexesAble="";
	this->numOfKeptCleanSheet=0;
	this->goalSaveRate=0;
	}
	void input()
	{
		Player::input();
		cout<<"Nhap kha nang phan xa:";
		getline(cin,this->reflexesAble);
		cout<<"Nhap so tran giu sach luoi:";
		cin>>this->numOfKeptCleanSheet;
		cout<<"Nhap ti le cuu thua:";
		cin>>this->goalSaveRate;
	}
	void output()
	{
		Player::output();
		cout<<"reflexesAble:"<<this->reflexesAble<<"  "<<"numOfKeptCleanSheet:"
		<<this->numOfKeptCleanSheet<<"  "<<"goalSaveRate:"<<this->goalSaveRate<<endl;
	}
	string mission()
	{
		string a="\nNhiem vu chinh la giu sach luoi\n";
		return a;
		string b="\nCung nen  gioi choi chan de ho tro luan chuyen bong\n";
		return b;
	}
	long long calculateWage()
	{
		long long bonus,wage,salary;
		if(this->goalSaveRate>8 ||this->reflexesAble=="good")
		{
			salary=3000000;
		}else if(this->goalSaveRate>6 ||this->reflexesAble=="normal")
		{
			salary=1800000;
		}else
		{
			salary=1000000;
		}
		for(int i=1;i<this->numOfKeptCleanSheet;i++)
		{
			bonus+=100000;
		}
		wage=bonus+salary;
		cout<<"\nTong tien thuong la:";
		return wage;
	}
	bool signingCondition()
	{
		if(this->getAppearance()<5 ||this->getHeight()<1.8 ||this->getHeader()=="bad" ||this->getPassingBall()=="bad")
		{
			return false;
			cout<<"\nKhong dat yeu cau\n";
		}else
		{
			return true;
			cout<<"\nNen ki hop dong voi ho\n";
		}
	}
	void riskOfTerminateContract()
	{
		if(this->goalSaveRate<5 || this->reflexesAble=="bad" || this->numOfKeptCleanSheet<6)
		{
			cout<<"\nViec cham dut hop dong hoan toan co the xay ra\n";
		}else if(this->goalSaveRate<7 || this->reflexesAble=="normal" || this->numOfKeptCleanSheet<8)
		{
			cout<<"\nViec cham dut hop dong kho xay ra\n";
		}else
		{
			cout<<"\nViec cham dut hop dong khong the nao xay ra\n";
		}
	}
	void oppRenewContract()
	{
		if(this->goalSaveRate<9 || this->reflexesAble=="good" || this->numOfKeptCleanSheet<10)
		{
			cout<<"\nRat co the se ki hop dong gia han\n";
		}else if(this->goalSaveRate<7 || this->reflexesAble=="normal" || this->numOfKeptCleanSheet<8)
		{
			cout<<"\nCo the xem xet gia han\n";
		}else
		{
			cout<<"\nKho co the gia han\n";
		}
	}
	void valueBringgingLastSeason()
	{
		if(this->getEscapePressing()=="good" ||this->getPassingBall()=="good"||this->getHeader()=="good" ||this->setDutyInTeam()=="good") 
		{
			cout<<"\nNam trong top cau thu thi dau hay nhat doi\n";
			cout<<"\nKha nang dem lai danh hieu cho doi bong cao\n";
		}else
		{
			cout<<"\nKhong mang lai gia tri gi cho doi bong\n";
		}
	}
};

