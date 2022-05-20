#include "Player.cpp"
class Midfielder:public Player
{
	private:
	string defenseSupport;
	string AttackSupport;
	string boxToBoxAble;
	float distanceMove;
	string cornerKick;
	public:
	void setdefenseSupport(string defenseSupport)
	    this->defenseSupport=defenseSupport;
	string getdefenseSupport(string defenseSupport)
	    return this->defenseSupport;
	void setAttackSupport(string AttackSupport)
	    this->AttackSupport=AttackSupport;
	string getAttackSupport(string AttackSupport)
	    return this->AttackSupport;
	void setboxToBoxAble(string boxToBoxAble)
	    this->boxToBoxAble=boxToBoxAble;
	string getboxToBoxAble(string boxToBoxAble)
	    return this->boxToBoxAble;
	void setdistanceMove(float distanceMove)
	    this->distanceMove=distanceMove;
	float getdistanceMove(float distanceMove)
	    return this->distanceMove;    
	void setcornerKick(string cornerKick)
	    this->cornerKick=cornerKick;
	string getcornerKick(string cornerKick)
	    return this->cornerKick;   
	Midfielder()
	{
	this->defenseSupport="";
	this->AttackSupport="";
	this->boxToBoxAble="";
	this->distanceMove=0;
	this->cornerKick="";
	}
	void input()
	{
		Player::input();
		cout<<"Nhap kha nang ho tro phong ngu:";
		getline(cin,this->defenseSupport);
		cout<<"Nhap kha nang ho tro tan cong:";
		getline(cin,this->AttackSupport);
		cout<<"Nhap kha nang len cong ve thu:";
		getline(cin,this->boxToBoxAble);
		cout<<"Nhap quang duong di chuyen:";
		cin>>this->distanceMove;
		cout<<"Nhap kha nang phat goc";
		getline(cin,this->cornerKick);
	}
	void output()
	{
		Player::output();
		cout<<"defenseSupport:"<<this->defenseSupport<<"  "<<"AttackSupport:"
		<<this->AttackSupport<<"  "<<"boxToBoxAble:"<<this->boxToBoxAble<<"  "<<
		"distanceMove:"<<this->distanceMove<<"  "<<"cornerKick:"<<this->cornerKick<<endl;
	}
	string mission()
	{
		string a="\nNhiem vu chinh la cam trich loi choi\n";
		return a;
		string b="\nPhai choi chan de ho tro tien dao\n";
		return b;
		if(this->getTechniqueStat()>90 ||this->getAssistNumInSeason()>20 ||this->getGoalsNumInSeason()>12 ||this->getShootBall=="good")
		{
			cout<<"\nCo the tham gia kien tao hoac lap cong\n";
			cout<<"\nCo the lui ve phong ngu khi can\n";
		}
	}
	long long calculateWage()
	{
		long long bonus,wage,salary;
		if(this->AttackSupport=="good" ||this->defenseSupport=="good" ||this->boxToBoxAble=="good"||this->cornerKick=="good")
		{
			salary=4000000;
		}else if(this->AttackSupport=="normal" ||this->defenseSupport=="normal" ||this->boxToBoxAble=="normal"||this->cornerKick=="normal")
		{
			salary=3000000;
		}else
		{
			salary=1800000;
		}
		
		for(int i=1;i<this->distanceMove;i++)
		{
			bonus+=1000000;
		}
		wage=bonus+salary;
		cout<<"\nTong tien thuong la:";
		return wage;
	}
	
	bool signingCondition()
	{
		if(this->getTechniqueStat()<70 ||this->getShootBall=="bad" || this->getEscapePressing()=="bad"||this->getNumOfRedCard()==3)
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
		if(this->AttackSupport=="bad" ||this->defenseSupport=="bad" ||this->boxToBoxAble=="bad"||this->cornerKick=="bad")
		{
			cout<<"\nViec cham dut hop dong hoan toan co the xay ra\n";
		}else if(this->AttackSupport=="normal" ||this->defenseSupport=="normal" ||this->boxToBoxAble=="normal"||this->cornerKick=="normal")
		{
			cout<<"\nViec cham dut hop dong kho xay ra\n";
		}else
		{
			cout<<"\nViec cham dut hop dong khong the nao xay ra\n";
		}
	}
	void oppRenewContract()
	{
		if(this->getSpecialGoals()=="good"||this->cornerKick=="good"||this->getPassingBall()=="good"||this->distanceMove>70)
		{
			cout<<"\nRat co the se ki hop dong gia han\n";
		}else if(this->getSpecialGoals()=="normal"||this->cornerKick=="normal"||this->getPassingBall()=="normal"||this->distanceMove>60)
		{
			cout<<"\nCo the xem xet gia han\n";
		}else
		{
			cout<<"\nKho co the gia han\n";
		}
	}
	
	void valueBringgingLastSeason()
	{
		if(this->getEscapePressing()=="good" ||this->boxToBoxAble=="good"||this->getGoalsNumInSeason()>13 ||this->setDutyInTeam()=="good"||this->getNumOfRedCard()==0||this->getSpeed()>80||this->getInjury()=="good") 
		{
			cout<<"\nNam trong top cau thu thi dau hay nhat doi\n";
			cout<<"\nKha nang dem lai danh hieu cho doi bong cao\n";
		}else
		{
			cout<<"\nKhong mang lai gia tri gi cho doi bong\n";
		}
	}
};

