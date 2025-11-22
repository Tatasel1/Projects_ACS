#include <iostream>
#include<fstream>
#include<string>
#include<ctime>

using namespace std;

class Student {
protected:
    string studentID;
    int age;
    string gender;
    float study_hours_per_day;
    float social_media_hours;
    float netflix_hours;
    bool part_time_job;
    float attendance_percentage;
    float sleep_hours;
    string diet_quality;
    int exercise_frequency;
    string parental_education_level;
    string internet_quality;
    int mental_health_rating;
    bool extracurricular_participation;
    float exam_score;
public:
    int uni;
    Student() = default;

    Student(int un, string stId, int ag, string gen, float studyHrs, float socialHrs,
           float netfHrs, bool partTime, float attendPerc, float sleepHrs,
           string dietQual, int exerciseFreq, string parentEduc,
           string internetQual, int mentalHealth, bool extraCurric,
           float examScr) :

       uni(un), studentID(stId), age(ag), gender(gen), study_hours_per_day(studyHrs),
       social_media_hours(socialHrs), netflix_hours(netfHrs), part_time_job(partTime),
       attendance_percentage(attendPerc), sleep_hours(sleepHrs), diet_quality(dietQual),
       exercise_frequency(exerciseFreq), parental_education_level(parentEduc),
       internet_quality(internetQual), mental_health_rating(mentalHealth),
       extracurricular_participation(extraCurric), exam_score(examScr)
    {}

    int getAge() {
        return age;
    }

    float getStudyHrs() {
        return study_hours_per_day;
    }

    float getSocialMediaHrs() {
        return social_media_hours;
    }

    virtual bool partTime() = 0;

    friend class Import;
};

class StudentPolitehnica : public Student {
public:
    void examRisk(){
        if ( this ->exam_score < 50.0 || this->attendance_percentage < 75.0) {
            cout << "Student " << this->studentID << " is at risk of failing the exam." << endl;
        }
    }

    bool partTime() override {
        if (this->part_time_job) {
            return true;
        }
        else return false;
    }

};

class StudentMedicina : public Student {
public:

    void isHealthy(){
        if ( this ->diet_quality == "Poor" || this -> exercise_frequency < 2) {
            cout << "Student " << this->studentID << " has unhealthy habits." << endl;
        }
    }


    bool partTime() override {
        if (this -> part_time_job) {
            return true;
        }
        else return false;
    }
};

class Import {
private:
    fstream file;
    int nrLines = 0;
public:
    void openCSV() {

        file.open("C:\\Users\\Rog PC\\Desktop\\FACULTATE\\POO\\student_habits_performance-1.csv", ios::in);

        if (!file.is_open()) {
            cout << "File not found" << endl;
            return;
        }

        string line;

        while (getline(file, line)) {
            nrLines++;
        }

        file.clear();
        file.seekg(0, ios::beg);

    }

    Student** readCSV() {

        Student** students = new Student* [nrLines];

        srand(time(0));
        string line;
        int k = 0;

        /// Se sare peste prima linie din csv
        getline(file, line);

        while (getline(file, line)) {

            string aux = "";
            int nr_values = 0;

            int un = rand() % 2;

            if(un == 0) {
                students[k] = new StudentPolitehnica();
            }
            else {
                students[k] = new StudentMedicina();
            }
            students[k]->uni=un;

            for (int i = 0; i <= line.size(); i++) {

                if ( i == line.size() || line[i] == ',') {
                    try {
                        switch (nr_values) {
                            case 0:students[k] -> studentID = aux; break;
                            case 1:students[k]->age = stoi(aux); break;
                            case 2:students[k]->gender = aux; break;
                            case 3:students[k]->study_hours_per_day = stof(aux); break;
                            case 4:students[k]->social_media_hours = stof(aux); break;
                            case 5:students[k]->netflix_hours = stof(aux); break;
                            case 6:students[k]->part_time_job = (aux == "Yes") ? true : false; break;
                            case 7:students[k]->attendance_percentage = stof(aux); break;
                            case 8:students[k]->sleep_hours = stof(aux); break;
                            case 9:students[k]->diet_quality = aux; break;
                            case 10:students[k]->exercise_frequency = stoi(aux); break;
                            case 11:students[k]->parental_education_level = aux; break;
                            case 12:students[k]->internet_quality = aux; break;
                            case 13:students[k]->mental_health_rating = stoi(aux); break;
                            case 14:students[k]->extracurricular_participation = (aux == "Yes") ? true : false; break;
                            case 15:students[k]->exam_score = stof(aux); break;

                            default: break;

                        }
                    }
                    catch (...) {
                        cout << "Conversion error at line " << k + 1 << ", value " << nr_values + 1 << endl;
                    }
                    aux = "";
                    nr_values++;
                }
                else {
                    aux += line[i];
                }
            }

        k++;

        }

        return students;
    }


    int getStudentsCount() {
        return nrLines - 1;
    }

    ~Import() {
        if (file.is_open()) {
            file.close();
        }
    }


};



int main() {
    Import import;
    import.openCSV();

    Student** students = import.readCSV();

    StudentPolitehnica** sp;
    StudentMedicina** sm;

    int count = import.getStudentsCount();

    int nr_politehnica = 0;
    int nr_medicina = 0;

    for (int i = 0; i < count; i++) {
        if (students[i] -> uni == 0) {
            nr_politehnica++;

        }
        else{
            nr_medicina++;
        }
    }

    sm= new StudentMedicina* [nr_medicina];
    sp= new StudentPolitehnica* [nr_politehnica];

    int indexPolitehnica=0;
    int indexMedicina=0;
    for (int i = 0; i < count; i++) {
        if (students[i] -> uni == 0) {
            sp[indexPolitehnica++] = (StudentPolitehnica*)students[i];
        }
        else{
            sm[indexMedicina++] = (StudentMedicina*)students[i];
        }
    }


    float sumAgeMed = 0.0;
    for (int i = 0; i < nr_medicina; i++) {
        sumAgeMed += sm[i]->getAge();
    }

    sumAgeMed /= nr_medicina;
    cout << "Average age of Medicina students: " << sumAgeMed << endl;


    return 0;
}
