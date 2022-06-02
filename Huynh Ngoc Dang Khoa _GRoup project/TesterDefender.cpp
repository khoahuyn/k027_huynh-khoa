#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream> 
using namespace std;

class FootballClub {
	private:
		string idMembers;
		string contractTerm;
	public:
		bool checkDate(int day, int month, int year) {
		switch (month) {
			case 1 :
			case 3:
			case 5 :
			case 7 :
			case 8 :
			case 10 :
			case 12 :
					if(day<1 || day > 31) {
						return false;
					}
					break;
			case 4 :
			case 6 :
			case 9 :
			case 11 :
				if(day < 1 || day > 30) {
					return false;
				}
				break;
			case 2 :
				if (year % 4 == 0) {
  					if (year % 100 == 0) {
   						 if (year % 400 == 0) {
							if(day < 1 || day > 29) {
								return false;
							}
					}else{
						if(day < 1 || day > 28) {
								return false;
					}}
				}else {
						if(day < 1 || day > 29) {
								return false;
							}
				}}else{
						if(day < 1 || day > 28) {
								return false;
				}}
					
				break;
			default :
				return false;
		}
		if(year <= 2022) {
			return false;
		} 
		return true;
		}
		void setMember(string idMembers){
			this->idMembers = idMembers;
		}
		string getMember(){
			return this->idMembers;
		}
		void setcontract(string contractTerm){
			this->contractTerm = contractTerm;
		}
		string getcontract(){
			return this->contractTerm;
		}
	FootballClub(){
		this->idMembers = " ";
		this->contractTerm = " ";
	}
	void input(){
		cout<<"Enter the ID.Members: ";
		cin>>this->idMembers;
		for(int i=0;i<=10;i++){
			if(this->idMembers[i]>=97&&this->idMembers[i]<=122)
				this->idMembers[i]-=32;
		}
		cin.ignore();
		cout<<"Enter the ContractTerm(Format DD/MM/YYYY): \n\n";
		int day,month,year;
		do {
			cout << "Day : ";
			cin >> day;
			cout << "Month : ";
			cin >> month;
			cout << "Year : ";
			cin >> year;
		}while(checkDate(day,month,year)==false);
		string sday,smonth,syear;
		sday = to_string(day);
		smonth = to_string(month);
		syear = to_string(year);
		this->contractTerm = sday+'/'+smonth+'/'+syear;
	}
	void output(){
		cout<<"*ID of Members: "<<this->idMembers<<endl;
		cout<<"*Contract Term: "<<this->contractTerm<<endl;
	}
//	virtual string mission() = 0;
//	virtual long long calculateWage() = 0;
//	virtual bool signingCondition() = 0;
//	virtual void riskOfTerminateContract() = 0;
//	virtual void oppRenewContract() = 0;
};
class Person:public FootballClub {
	private : 
		int idCardNumber ;
		string fullName ;
		int age ;
		long long salary  ;
	public :
		int getIDCardNumber ()  {
		  return this->idCardNumber ;
		} 
		string getFullName() {
		return this->fullName ;	
		} 
		int getAge() {
			return this->age ;
		} 
		int getSalary() {
			return this->salary ;
		} 
		
		void setIDCardNumber (int ID) {
			this->idCardNumber=ID ;
		} 
		void setFullName (string name) {
			this->fullName=name ;
		} 
		void setAge(float age) {
			this->age=age ;
		} 
		void setSalary(long long salary) {
			this->salary=salary ;
		} 

		Person() {
			this->idCardNumber=0;
			this->fullName="" ;
			this->age=0;
			this->salary=0;
		} 
		
		void input () {
		FootballClub::input() ;
		cout<<"CardNumber :" ;
		cin>>this->idCardNumber ;
		cin.ignore();
		cout<<"Full name :" ;
		getline(cin,this->fullName) ;
		cout<<"Age :" ;
		cin>>this->age ;
		cout<<"Salary :" ;
		cin>>this->salary ;
		
		} 
		void output() {
		FootballClub::output() ; 
		cout<<"CardNumber :"<<this->idCardNumber<<"\n";
		cout<<"Full Name :" <<this->fullName <<"\n" ;
		cout<<"Age :" <<this->age<<"\n" ;
		cout<<"Salary :"<<this->salary<<"\n" ;
		
		} 
	   
};
class Player:public Person
{
	private:
		int numberOfShirt; // So ao dau
		int Appearance; // So lan tham gia tran dau
		int numOfYellowCard; // So the vang
		int numOfRedCard; // So the do
		int techniqueStat; // Chi so ki thuat
		int assistNumInSeason; // So luong kien tao trong 1 mua
		int goalsNumInSeason; // SO luong ban thang trong 1 mua
		int assistNumInCareer; // So luong kien tao trong su nghiep cau thu
		int goalsNumInCareer; // So luong ban thang trong su nghiep cau thu
		float height; // Chieu cao
		float weight; // Can nang
		float speed; // Toc do
		float scoreAverage; // Trung binh so ban thang
		string injury; // Loai chan thuong
		string dutyInTeam; // Vai tro trong doi bong
		string escapePressing; // Kha nang thoat Pressing
		string  passingBall; // Kha nang chuyen bong
		string shootBall; // Kha nang sut bong
		string header; // Kha nang lanh dao
		string specialGoals; // Ban thang dac biet
	public:
		void setInjury(string injury){
			this->injury = injury;
		}
		string getInjury(){
			return this->injury;
		}			
		void setDutyInTeam(string dutyInTeam){
			this->dutyInTeam = dutyInTeam;
		}
		string getDutyInTeam(){
			return this->dutyInTeam;
		}			
		void setEscapePressing(string escapePressing){
			this->escapePressing = escapePressing;
		}
		string getEscapePressing(){
			return this->escapePressing;
		}			
		void setPassingBall(string passingBall){
			this->passingBall = passingBall;
		}			
		string getPassingBall(){
			return this->passingBall;
		}			
		void setShootBall(string shootBall){
			this->shootBall = shootBall;
		}		
		string getShootBall(){
			return this->shootBall;
		}		
		void setHeader(string header){
			this->header = header;
		}			
		string getHeader(){
			return this->header;
		}			
		void setSpecialGoals(string specialGoals){
			this->specialGoals = specialGoals;
		}			
		string getSpecialGoals(){
			return this->specialGoals;	
		}			


		void setNumberOfShirt(int numberOfShirt){
			this->numberOfShirt = numberOfShirt;
		}			
		int getNumberOfShirt(){
			return this->numberOfShirt;
		}			
		void setAppearance(int Appearance){
			this->Appearance = Appearance;
		}			
		int getAppearance(){
			return this->Appearance;
		}			
		void setNumOfYellowCard(int numOfYellowCard){
			this->numOfYellowCard = numOfYellowCard;
		}			
		int getNumOfYellowCard(){
			return this->numOfYellowCard;
		}			
		void setNumOfRedCard(int numOfRedCard){
			this->numOfRedCard = numOfRedCard;
		}			
		int getNumOfRedCard(){
			return this->numOfRedCard;
		}			
		void setTechniqueStat(int techniqueStat){
			this->techniqueStat = techniqueStat;
		}					
		int getTechniqueStat(){
			return this->techniqueStat;
		}			
		void setAssistNumInSeason(int assistNumInSeason){
			this->assistNumInSeason = assistNumInSeason;
		}			
		int getAssistNumInSeason(){
			return this->assistNumInSeason;
		}			
		void setGoalsNumInSeason(int goalsNumInSeason){
			this->goalsNumInSeason = goalsNumInSeason;
		}			
		int getGoalsNumInSeason(){
			return this->goalsNumInSeason;
		}			
		void setAssistNumInCareer(int assistNumInCareer){
			this->assistNumInCareer = assistNumInCareer;
		}			
		int getAssistNumInCareer(){
			return this->assistNumInCareer;
		}			
		void setGoalsNumInCareer(int goalsNumInCareer){
			this->goalsNumInCareer = goalsNumInCareer;
		}			
		int getGoalsNumInCareer(){
			return this->goalsNumInCareer;
		}			
		
		
		void setHeight(float height){
			this->height = height;
		}			
		float getHeight(){
			return this->height;
		}			
		void setWeight(float weight){
			this->weight = weight;
		}			
		float getWeight(){
			return this->weight;
		}			
		void setSpeed(float speed){
			this->speed = speed;
		}			
		float getSpeed(){
			return this->speed;
		}			
		void setScoreAverage(float scoreAverage){
			this->scoreAverage = scoreAverage;
		}			
		float getScoreAverage(){
			return this->scoreAverage;		
		}
																				
		Player()
		{
			numberOfShirt = 0;
			height = 0;
			weight = 0;	
			speed = 0;
			scoreAverage = 0;
			injury = " ";
			Appearance = 0;
			numOfYellowCard = 0;
			numOfRedCard = 0;
			dutyInTeam = " ";
			techniqueStat = 0;
			escapePressing = " ";
			passingBall = " ";
			shootBall = " ";
			header = " ";
			assistNumInSeason = 0;
			goalsNumInSeason = 0;
			assistNumInCareer = 0;
			goalsNumInCareer = 0;
			specialGoals = " ";
		}
		void input()
		{
			cout<<"INPUT THE PLAYER'S INFORMATION'"<<endl;
			Person::input();
			cout<<"Number of shirt: ";
			cin>>numberOfShirt;
			cout<<"Height: ";
			cin>>height;
			cout<<"Weight: ";
			cin>>weight;
			cout<<"Speed: ";
			cin>>speed;
			cout<<"The average of score: ";
			cin>>scoreAverage;
			cout<<"Injury: ";
			cin.ignore();
			getline(cin,injury);
			cout<<"Appearance: ";
			cin>>Appearance;
			cout<<"Number of Yellow Card: ";
			cin>>numOfYellowCard;
			cout<<"Number of Red Card: ";
			cin>>numOfRedCard;
			cout<<"The duty in Team: ";
			cin.ignore();
			getline(cin,dutyInTeam);
			cout<<"The technique stat: ";
			cin>>techniqueStat;
			cout<<"The escapation of Pressing: ";
			cin.ignore();
			getline(cin,escapePressing);
			cout<<"The passing Ball: ";
			getline(cin,passingBall);
			cout<<"The ability of shooting Ball: ";
			getline(cin,shootBall);
			cout<<"The header: ";
			getline(cin,header);
			cout<<"The number of assistance in Season: ";
			cin>>assistNumInSeason;
			cout<<"The number of goals in Season: ";
			cin>>goalsNumInSeason;
			cout<<"The number of assistance in Career: ";
			cin>>assistNumInCareer;
			cout<<"The number of goals in Career: ";
			cin>>goalsNumInCareer;
			cout<<"The special goals: ";
			cin.ignore();
			getline(cin,specialGoals);			
		}
		void output()
		{
			cout<<"--------------------------------------------------"<<endl;
			cout<<"                         OUTPUT THE PLAYER'S INFORMATION'"<<endl;
			Person::output();
			cout<<"Number of shirt: "<<numberOfShirt<<"  "<<"Height: "<<height<<"  "<<"Weight: "<<weight<<"  "<<"Speed: "<<speed<<endl;                
			cout<<"The average of score: "<<scoreAverage<<"  "<<"Injury: "<<injury<<"  "<<"Appearance: "<<Appearance<<endl;
			cout<<"Number of Yellow Card: "<<numOfYellowCard<<"  "<<"Number of Red Card: "<<numOfRedCard<<"  "<<"The duty in Team: "<<dutyInTeam<<endl;
			cout<<"The technique stat: "<<techniqueStat<<"  "<<"The escapation of Pressing: "<<escapePressing<<"  "<<"The passing Ball: "<<passingBall<<endl;
			cout<<"The ability of shooting Ball: "<<shootBall<<"  "<<"The header: "<<header<<"  "<<endl;
			cout<<"The number of assistance in Season: "<<assistNumInSeason<<"  "<<"The number of goals in Season: "<<goalsNumInSeason<<endl;
			cout<<"The number of assistance in Career: "<<assistNumInCareer<<"  "<<"The number of goals in Career: "<<goalsNumInCareer<<endl;
			cout<<"The special goals: "<<specialGoals<<endl;		
		}
		void longOrShortTermRest()
		{
			// injury
			cout<<"--------------------------------------------------"<<endl;
			cout<<"THE TIME NEED FOR THE TERM REST BECAUSE OF INJURY"<<endl;
			if(this->injury == "ligament rupture" )   // dut day chang
				cout<<"2 months for the term rest(Long term rest)"<<endl;
			else if(this->injury == "sprain")  // bong gan
				cout<<"1 moth for the term rest(Short term rest)"<<endl;
			else if(this->injury == "tendinitis")  // viem gan
				cout<<"1.5 months for the term rest(Long term rest)"<<endl;
			else if(this->injury == "fracture")  // gay xuong
				cout<<"from 6 months to 1 year for the term rest(Long term rest)"<<endl;
			else if(this->injury == "muscle injury")  // chan thuong co
				cout<<"1 month for the term rest(Short term rest)"<<endl;
			else if(this->injury == "tear cartilage")  // rach sun
				cout<<"2 months for the term rest(Long term rest)"<<endl;
			else if(this->injury == "minor injury")  // chan thuong nhe
				cout<<"from 1 to 2 weeks for the term rest(Short term rest)"<<endl;
			else 
				cout<<"NO TERM REST"<<endl;			
			}
		float numOfExpectedGoal()
		{
			// goalsNumInSeason & Appearance
			float Num_Of_Expected_Goals;
			cout<<"--------------------------------------------------"<<endl;
			cout<<"==========The Number Of Expected Goals=========="<<endl;
			Num_Of_Expected_Goals = this->goalsNumInSeason / this->Appearance;
			return Num_Of_Expected_Goals;	
		}	
		float numOfExpectedAssist()
		{
			// assistNumInSeason & Appearance
			float Num_Of_Expected_Assists;
			cout<<"--------------------------------------------------"<<endl;
			cout<<"==========The Number Of Expected Assists=========="<<endl;
			Num_Of_Expected_Assists = this->assistNumInSeason / this->Appearance;
			return Num_Of_Expected_Assists;
		}		
};
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
	string getTackleAbility()
	{
	    return this->tackleAbility;
	}
	void setDefense1vs1(string defense1vs1)
	{
	    this->defense1vs1=defense1vs1;
	}
	string getDefense1vs1()
	{
	    return this->defense1vs1;
	}
	void setOffsideTrap(string offsideTrap)
	{
	    this->offsideTrap=offsideTrap;
	}
	string getOffsideTrap()
	{
	    return this->offsideTrap;
	}
	void setAreaDefense(string areaDefense)
	{
	    this->areaDefense=areaDefense;
	}
	string getAreaDefense()
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
		cout<<"Enter the tackleAbility :";
		getline(cin,this->tackleAbility);
		cout<<"Enter the defense1vs1:";
		getline(cin,this->defense1vs1);
		cout<<"Enter the offsideTrap :";
		getline(cin,this->offsideTrap);
		cout<<"Enter the areaDefense :";
		getline(cin,this->areaDefense);
	}
	void output()
	{
		Player::output();
		cout<<"tackleAbility:"<<this->tackleAbility<<"  "<<"defense1vs1:"
		<<this->defense1vs1<<"  "<<"offsideTrap:"<<this->offsideTrap<<" "<<
		"areaDefense:"<<this->areaDefense<<endl;
	}
	string mission()
	{
		string a="\nThe main task is not to let the opponent pass\n";
		return a;
		string b="\nYou should also be good at playing with your feet to help escape pressing\n";
		return b;
		if(this->getAssistNumInSeason()>10 ||this->getGoalsNumInSeason()>7)
		{
			string c="\nShould participate in creating or creating merit\n";
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
		cout<<"\nThe total bonus is:";
		return wage;
	}
	
	bool signingCondition()
	{
		if(this->getAppearance()<6 ||this->getWeight()>80 ||this->getSpeed()<50 || this->getInjury()=="bad")
		{
			return false;
			cout<<"\nUnsatisfactory\n";
		}else
		{
			return true;
			cout<<"\nShould sign a contract with them\n";
		}
	}
	void riskOfTerminateContract()
	{
		if(this->areaDefense=="bad" ||this->tackleAbility=="bad" ||this->offsideTrap=="bad"||this->defense1vs1=="bad")
		{
			cout<<"\nFull contract termination is possible\n";
		}else if(this->areaDefense=="normal" ||this->tackleAbility=="normal" ||this->offsideTrap=="normal"||this->defense1vs1=="normal")
		{
			cout<<"\nContract termination is unlikely\n";
		}else
		{
			cout<<"\nTermination of the contract cannot happen\n";
		}
	}
	void oppRenewContract()
	{
		if(this->getTechniqueStat()>85 ||this->getWeight()<72 || this->getEscapePressing()=="good" ||this->getPassingBall()=="good" )
		{
			cout<<"\nMost likely will sign a contract extension\n";
		}else if(this->getTechniqueStat()>75 ||this->getWeight()<77 || this->getEscapePressing()=="normal" ||this->getPassingBall()=="normal")
		{
			cout<<"\nExtension may be considered\n";
		}else
		{
			cout<<"\nUnable to extend\n";
		}
	}
	void valueBringgingLastSeason()
	{
		if(this->getEscapePressing()=="good" ||this->getPassingBall()=="good"||this->getGoalsNumInSeason()>9 ||this->getDutyInTeam()=="good"||this->getNumOfRedCard()==0) 
		{
			cout<<"\nOne of the best players on the team\n";
			cout<<"\nThe ability to bring titles to the team is high\n";
		}else
		{
			cout<<"\nDoes not bring any value to the team\n";
		}
	}
};


class listDefender:public Defender
{
	public:
		vector<Defender> v;
		void inputlist(int &n){
			Defender arnold;
			for(int i=0;i<n;i++)
 			{
 				arnold.input();
 				v.push_back(arnold);
			 }
			ofstream fo;
			fo.open("D:\\test\\danh sach.txt");
			if(fo.is_open()){
				for(int i=0;i<v.size();i++){
					fo<<"Name:"<<v[i].getFullName()<<"\t|Age:"<<v[i].getAge()<<"\t|height:"<<v[i].getHeight()<<"\t|weight:"<<v[i].getWeight()<<endl;
				}
				fo.close();
			}else{
				cout<<"error!!"<<endl;
			}
			
			
		}
};
int main(){
	Defender arnold;
//	arnold.input();
//	arnold.output();
	vector<Defender> v;
	int n;
	cout<<"Enter the Defender :";
	cin>>n;
	listDefender li;
	li.inputlist(n);
	return 0;
}
