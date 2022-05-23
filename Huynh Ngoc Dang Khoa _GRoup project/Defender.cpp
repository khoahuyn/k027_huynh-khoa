#include "Player.cpp"
class Defender:public Player
{
	private:
	string tackleAbility;
	string defense1vs1;
	string offsideTrap;
	string areaDefense;
	public:
	void setTackleAbility(string tackleAbility)
	{
	    this->tackleAbility=tackleAbility;
	}
	string getTackleAbility(string tackleAbility)
	{
	    return this->tackleAbility;
	}
	void setDefense1vs1(string defense1vs1)
	{
	    this->defense1vs1=defense1vs1;
	}
	string getDefense1vs1(string defense1vs1)
	{
	    return this->defense1vs1;
	}
	void setOffsideTrap(string offsideTrap)
	{
	    this->offsideTrap=offsideTrap;
	}
	string getOffsideTrap(string offsideTrap)
	{
	    return this->offsideTrap;
	}
	void setAreaDefense(string areaDefense)
	{
	    this->areaDefense=areaDefense;
	}
	string getAreaDefense(string areaDefense)
	{
	    return this->areaDefense; 
	}  
	Defender()
	{
	this->tackleAbility="";
	this->defense1vs1="";
	this->offsideTrap="";
	this->areaDefense="";
	}
	void input()
	{
		Player::input();
		cout<<"Nhap kha nang phan ung:";
		getline(cin,this->tackleAbility);
		cout<<"Nhap kha nang tranh chap tay doi:";
		getline(cin,this->defense1vs1);
		cout<<"Nhap kha nang bay viet vi:";
		getline(cin,this->offsideTrap);
		cout<<"Nhap tam hoat dong:";
		getline(cin,this->areaDefense);
	}
	void output()
	{
		Player::output();
		cout<<"tackleAbility:"<<this->tackleAbility<<"  "<<"defense1vs1:"
		<<this->defense1vs1<<"  "<<"offsideTrap:"<<this->offsideTrap<<
		"areaDefense:"<<this->areaDefense<<endl;
	}
	string mission()
	{
		string a="\nNhiem vu chinh la khong de doi thu vuot qua\n";
		return a;
		string b="\nCung nen  gioi choi chan de ho tro dong thoat fressing\n";
		return b;
		if(this->getAssistNumInSeason()>10 ||this->getGoalsNumInSeason()>7)
		{
			string c="\nNen tham gia kien tao hoac lap cong\n";
			return c;
		}
	}
	long long calculateWage()
	{
		long long bonus,wage,salary;
		if(this->areaDefense=="good" ||this->tackleAbility=="good" ||this->offsideTrap=="good"||this->defense1vs1=="good")
		{
			salary=2500000;
		}else if(this->areaDefense=="normal" ||this->tackleAbility=="normal" ||this->offsideTrap=="normal"||this->defense1vs1=="normal")
		{
			salary=1200000;
		}else
		{
			salary=800000;
		}

		if(this->getGoalsNumInSeason()>8 ||this->getAssistNumInSeason()>11 ||this->getEscapePressing()=="good"||this->getHeader()=="good")
		{
			bonus=500000;
		}else if(this->getGoalsNumInSeason()>6 ||this->getAssistNumInSeason()>9 ||this->getEscapePressing()=="normal"||this->getHeader()=="normal")
		{
			bonus=300000;
		}else
		{
			bonus=150000;
		}
		wage=bonus+salary;
		cout<<"\nTong tien thuong la:";
		return wage;
	}
	/
	bool signingCondition()
	{
		if(this->getAppearance()<6 ||this->getWeight()>80 ||this->getSpeed()<50 || this->getInjury()=="bad")
		{
			return false;
			cout<<"\nKhong dat yeu cau\n";
		}else
		{
			return true;
			cout<<"\nNen ki ket hop dong voi ho\n";
		}
	}
	void riskOfTerminateContract()
	{
		if(this->areaDefense=="bad" ||this->tackleAbility=="bad" ||this->offsideTrap=="bad"||this->defense1vs1=="bad")
		{
			cout<<"\nViec cham dut hop dong hoan toan co the xay ra\n";
		}else if(this->areaDefense=="normal" ||this->tackleAbility=="normal" ||this->offsideTrap=="normal"||this->defense1vs1=="normal")
		{
			cout<<"\nViec cham dut hop dong kho xay ra\n";
		}else
		{
			cout<<"\nViec cham dut hop dong khong the nao xay ra\n";
		}
	}
	void oppRenewContract()
	{
		if(this->getTechniqueStat()>85 ||this->getWeight()<72 || this->getEscapePressing()=="good" ||this->getPassingBall()=="good" )
		{
			cout<<"\nRat co the se ki hop dong gia han\n";
		}else if(this->getTechniqueStat()>75 ||this->getWeight()<77 || this->getEscapePressing()=="normal" ||this->getPassingBall()=="normal")
		{
			cout<<"\nCo the xem xet gia han\n";
		}else
		{
			cout<<"\nKho co the gia han\n";
		}
	}
	void valueBringgingLastSeason()
	{
		if(this->getEscapePressing()=="good" ||this->getPassingBall()=="good"||this->getGoalsNumInSeason()>9 ||this->setDutyInTeam()=="good"||this->getNumOfRedCard()==0) 
		{
			cout<<"\nNam trong top cau thu thi dau hay nhat doi\n";
			cout<<"\nKha nang dem lai danh hieu cho doi bong cao\n";
		}else
		{
			cout<<"\nKhong mang lai gia tri gi cho doi bong\n";
		}
	}
};

