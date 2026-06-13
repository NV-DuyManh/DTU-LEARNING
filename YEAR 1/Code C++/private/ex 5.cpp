#include <iostream>
using namespace std;
class Student{
	private:
		string name;
	    int age;
	    float grade_math, grade_phys, grade_chemistry;
	public:
		Student(){
			this->name = " ";
			this->age = 0;
			this->grade_math = 0;
			this->grade_phys = 0;
			this->grade_chemistry = 0;
		}
		Student(string name, int age, float grade_math, float grade_phys,float grade_chemistry){
			this->name = name;
			this->age = age;
			this->grade_math = grade_math;
			this->grade_phys = grade_phys;
			this->grade_chemistry = grade_chemistry;
	
		}
		Student(Student *sv){
			this->name = sv->name;
			this->age = sv->age;
			this->grade_math = sv->grade_math;
			this->grade_phys = sv->grade_phys;
			this->grade_chemistry = sv->grade_chemistry;
		}
	string getName() {
        return name;
    }

    int getAge() {
        return age;
    }


    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }


	float gradePointAverage(){
		return (grade_math + grade_phys + grade_chemistry)/3;
	}
	void Input(){
		fflush(stdin);
		cout <<"enter name: ";
		getline(cin, name) ;
		cout <<"enter age: ";
		cin >> age;
		cout <<"enter grade_math: ";
		cin >> grade_math;
		cout <<"enter grade_phys: ";
		cin >> grade_phys;
		cout <<"enter grade_chemistry: ";
		cin >> grade_chemistry;
};
	void Output(){
		cout <<"name: "<<name<<endl;
		cout <<"age: "<<age<<endl;
		cout <<"grade_math:"<<grade_math<<endl;
		cout <<"grade_phys: "<<grade_phys<<endl;
		cout <<"grade_chemistry: "<<grade_chemistry<<endl;
	
	};
	
};

int main(){
	Student *sv1 = new Student();
	Student *sv2 = sv1;
	sv1->Input();
	sv1->Output();
	cout <<"gradePointAverage sv1: "<<sv1->gradePointAverage()<<endl;
	sv2->Output();
	cout <<"gradePointAverage sv2: "<<sv2->gradePointAverage()<<endl;
	delete sv1;
	delete sv2;

	return 0;
}


