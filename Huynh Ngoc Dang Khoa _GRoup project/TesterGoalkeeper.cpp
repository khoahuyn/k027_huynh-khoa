#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
#include<conio.h>
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
	}
	
	FootballClub(string idMembers , string contractTerm) {
		this->idMembers = idMembers;
		this->contractTerm = contractTerm;
	}
	
	virtual void input(){
		cout<<"\n\nWe need the ID for this person : ";
		cin>>this->idMembers;
		for(int i=0;i<=10;i++){
			if(this->idMembers[i]>=97&&this->idMembers[i]<=122)
				this->idMembers[i]-=32;
		}
		cin.ignore();
		cout<<"\nHow long do you want your contract to last?(Format DD/MM/YYYY): \n\n";
		int day,month,year;
		do {
			cout << "Day : ";
			cin >> day;
			cout << "Month : ";
			cin >> month;
			cout << "Year : ";
			cin >> year;
		}while(checkDate(day,month,year)==false);
		cout<<"\n";
		string sday,smonth,syear;
		sday = to_string(day);
		smonth = to_string(month);
		syear = to_string(year);
		this->contractTerm = sday+'/'+smonth+'/'+syear;
	}
	virtual void output(){
		cout<<"ID of Members: "<<this->idMembers<<endl<<endl;
		cout<<"Contract Term: "<<this->contractTerm<<endl;
	}
	virtual string mission() = 0;
	virtual bool signingCondition() = 0;
	virtual void oppRenewContract() = 0;
	long long calculateWage() {
	}
	void riskOfTerminateContract() {
	}
};
class Person:public FootballClub  {
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
			
		}
		
		Person(string idMembers , string contractTerm , int idCardNumber , string fullName , int age , long long salary) : FootballClub(idMembers,contractTerm) {
			this->idCardNumber = idCardNumber;
			this->fullName = fullName;
			this->age = age;
			this->salary = salary;
		}
		
		void input () {
		FootballClub::input() ;
		cout<<"\nIdentity card number : " ;
		cin>>this->idCardNumber ;
		cin.ignore();
		cout << "\nFull name : ";
		getline(cin,this->fullName);
		string s = "";
		stringstream st(fullName);
		string token;
		while(st>>token) {
		s += toupper(token[0]);
		for(int i=1 ; i<token.length() ; i++) {
	   		s += tolower(token[i]);
		}
			s += " ";
		}
		s.erase(s.length()-1);
		fullName=s ;
		cout<<"\nAge :" ;
		cin>>this->age ;
		cout<<"\nSalary :" ;
		cin>>this->salary ;
		
		} 
		void output() {
		FootballClub::output() ; 
		cout<<"\nCardNumber :"<<this->idCardNumber<<"\n\n";
		cout<<"Full Name :" <<this->fullName<<"\n\n" ;
		cout<<"Age :" <<this->age<<"\n\n" ;
		cout<<"Salary :"<<this->salary<<"\n\n" ;
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
		float height; // Chieu cao
		float weight; // Can nang
		string injury; // Loai chan thuong
		string position; // vi tri
	public:
		void setInjury(string injury){
			this->injury = injury;
		}
		string getInjury(){
			return this->injury;
		}					
		void setPosition(string position)
		{
			this->position = position;
		}	
		string getPosition()
		{
			return this->position;
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
	
																				
		Player() {
		} 
		Player(	string idMembers,string contractTerm,int idCardNumber,string fullName,int age,long long salary,int numberOfShirt,int Appearance,int numOfYellowCard,int numOfRedCard,int techniqueStat,int assistNumInSeason,int goalsNumInSeason,float height,float weight,string injury,string position) :Person(idMembers, contractTerm,idCardNumber, fullName, age, salary)
		{	
	     this->numberOfShirt=numberOfShirt ;
	     this->Appearance=Appearance ;
	     this->numOfYellowCard=numOfYellowCard ;
	     this->numOfRedCard=numOfRedCard ;
	     this->techniqueStat=techniqueStat;
	     this->assistNumInSeason=assistNumInSeason ;
	     this->goalsNumInSeason=goalsNumInSeason ;
	     this->height=height;
	     this->weight=weight ;
	     this->injury=injury ;
		}
		void input()
		{
			cout<<"INPUT THE PLAYER'S INFORMATION'"<<endl;
			Person::input();
			cout<<"Number of shirt(1-25): ";
			cin>>numberOfShirt;
			cout<<"Height: ";
			cin>>height;
			cout<<"Weight: ";
			cin>>weight;
			cout<<"Injury: ";
			cin.ignore();
			getline(cin,injury);
			cout<<"Appearance: ";
			cin>>Appearance;
			cout<<"Number of Yellow Card: ";
			cin>>numOfYellowCard;
			cout<<"Number of Red Card: ";
			cin>>numOfRedCard;
			cout<<"The number of assistance in Season: ";
			cin>>assistNumInSeason;
			cout<<"The number of goals in Season: ";
			cin>>goalsNumInSeason;	
			cout<<"Position: ";
			getline(cin,position);		
		}
		void output()
		{
			cout<<"--------------------------------------------------"<<endl;
			cout<<"                         OUTPUT THE PLAYER'S INFORMATION'"<<endl;
			Person::output();
			cout<<"Number of shirt: "<<numberOfShirt<<"  "<<"Height: "<<height<<"  "<<"Weight: "<<weight<<endl;                
			cout<<"Injury: "<<injury<<"  "<<"Appearance: "<<Appearance<<endl;
			cout<<"Number of Yellow Card: "<<numOfYellowCard<<"  "<<"Number of Red Card: "<<numOfRedCard<<"  "<<endl;
			cout<<"The technique stat: "<<techniqueStat<<endl;
			cout<<"The number of assistance in Season: "<<assistNumInSeason<<"  "<<"The number of goals in Season: "<<goalsNumInSeason<<endl;		
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

class Goalkeeper:public Player
{
	private:
	string reflexesAble;
	int numOfKeptCleanSheet;
	int goalSaveRate;
	public:
	void setReflexesAble(string reflexesAble)
	{
	    this->reflexesAble=reflexesAble;
	}
	string getReflexesAble()
	{
	    return this->reflexesAble;
	}
	void setNumOfKeptCleanSheet(int numOfKeptCleanSheet)
	{
	    this->numOfKeptCleanSheet=numOfKeptCleanSheet;
	}
	int getNumOfKeptCleanSheet()
	{
	    return this->numOfKeptCleanSheet;
	}
	void setGoalSaveRate(int goalSaveRate)
	{
	    this->goalSaveRate=goalSaveRate;
	}
	int getGoalSaveRate()
	{
	    return this->goalSaveRate;
	}
	Goalkeeper()
	{
		
	} 
	Goalkeeper(string idMembers,string contractTerm,int idCardNumber,string fullName,int age,long long salary,int numberOfShirt,int Appearance,int numOfYellowCard,int numOfRedCard,int techniqueStat,int assistNumInSeason,int goalsNumInSeason,float height,float weight,string injury,string position,	string reflexesAble,int numOfKeptCleanSheet,int goalSaveRate):Player(idMembers,contractTerm,idCardNumber,fullName,age,salary,numberOfShirt,Appearance,numOfYellowCard,numOfRedCard,techniqueStat,assistNumInSeason,goalsNumInSeason,height,weight,injury,position) {
		this->reflexesAble=reflexesAble;
		this->numOfKeptCleanSheet=numOfKeptCleanSheet;
		this->goalSaveRate=goalSaveRate ;
	}
	void input()
	{
		Player::input();
		cout<<"Enter the reflexesAble:";
		getline(cin,this->reflexesAble);
		cout<<"Enter the numOfKeptCleanSheet:";
		cin>>this->numOfKeptCleanSheet;
		cout<<"Enter the goalSaveRate:";
		cin>>this->goalSaveRate;
	}
	void output()
	{
		Player::output();
		cout<<"reflexesAble:"<<this->reflexesAble<<endl;
		cout<<"numOfKeptCleanSheet:"<<this->numOfKeptCleanSheet<<endl;
		cout<<"goalSaveRate:"<<this->goalSaveRate<<endl;
	}
	string mission()
	{
		string a="\nThe main task is to keep a clean sheet\n";
		return a;
		string b="\nYou should also be good at playing with your feet to help with ball rotation\n";
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
		cout<<"\nThe total bonus is:";
		return wage;
	}
	bool signingCondition()
	{
		if(this->getAppearance()<5 ||this->getHeight()<1.8 )
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
		if(this->goalSaveRate<5 || this->reflexesAble=="bad" || this->numOfKeptCleanSheet<6)
		{
			cout<<"\nFull contract termination is possible\n";
		}else if(this->goalSaveRate<7 || this->reflexesAble=="normal" || this->numOfKeptCleanSheet<8)
		{
			cout<<"\nContract termination is unlikely\n";
		}else
		{
			cout<<"\nTermination of the contract cannot happen\n";
		}
	}
	void oppRenewContract()
	{
		if(this->goalSaveRate<9 || this->reflexesAble=="good" || this->numOfKeptCleanSheet<10)
		{
			cout<<"\nMost likely will sign a contract extension\n";
		}else if(this->goalSaveRate<7 || this->reflexesAble=="normal" || this->numOfKeptCleanSheet<8)
		{
			cout<<"\nExtension may be considered\n";
		}else
		{
			cout<<"\nUnable to extend\n";
		}
	}
	
};





class listGoalkeeper:public Goalkeeper
{
	public:
		vector<Goalkeeper> v;
		int n;
		string searchinfo;
		void inputlist(){
			cout<<"Enter the Goalkeeper :";
			cin>>n;
			for(int i=0;i<n;i++)
 			{
 				Goalkeeper degea;
 				degea.input();
 				v.push_back(degea);
			 }
			ofstream fo;
			fo.open("D:\\danh sach.txt");
			if(fo.is_open()){
				for(int i=0;i<v.size();i++){
					fo<<i+1<<"/"<<endl;
					fo<<"Name: "<<v[i].getFullName()<<endl;
					fo<<"Age: "<<v[i].getAge()<<endl;
					fo<<"Height: "<<v[i].getHeight()<<endl;
					fo<<"Weight: "<<v[i].getWeight()<<endl;
					fo<<"Position: "<<v[i].getPosition()<<endl;
				}
				fo.close();
			}else{
				cout<<"Error!!"<<endl;
			}
		}
	void search(){
		ofstream fo;
			fo.open("D:\\danh sach_new.txt");
			if(fo.is_open()){
					cin.ignore();
					cout<<"Enter the searchinfo:";
					getline(cin,this->searchinfo);
					for(int i=0;i<v.size();i++){
					if(this->searchinfo==v[i].getFullName()){
					fo<<"\t\t======The information you need about Goalkeeper====="<<endl;	
					cout<<"\t\t======The information you need about Goalkeeper====="<<endl;
					fo<<"Name: "<<v[i].getFullName()<<endl;
					cout<<"Name: "<<v[i].getFullName()<<endl;
					fo<<"Age: "<<v[i].getAge()<<endl;
					cout<<"Age: "<<v[i].getAge()<<endl;
					fo<<"Height: "<<v[i].getHeight()<<endl;
					cout<<"Height: "<<v[i].getHeight()<<endl;
					fo<<"Weight: "<<v[i].getWeight()<<endl;
					cout<<"Weight: "<<v[i].getWeight()<<endl;
					fo<<"Position: "<<v[i].getPosition()<<endl;
					cout<<"Position: "<<v[i].getPosition()<<endl;
					}
					}
				fo.close();
			}else{
				cout<<"Error!!"<<endl;
			}
	}	
};
int main(){
	Goalkeeper g1("GK001","31/08/2030",111222,"Thibaut Courtois",30,4000000,1,19,3,0,4,2,1,199,91,"NO","GK","good",15,80);
	Goalkeeper g2("GK002","17/10/2031",111333,"Alisson Becker",30,2000000,17,5,1,0,2,1,0,193,91,"NO","GK","normal",3,60);
	Goalkeeper g3("GK003","22/04/2032",111444,"David De Gea ",32,1500000,23,1,0,0,1,0,0,192,76,"NO","GK","bad",0,0);
	g1.output();
	g2.output();
	g3.output();
	return 0;
}
