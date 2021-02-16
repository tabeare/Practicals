#include <iostream> 
#include <vector>
using namespace std;

class Date {
  private:
    int day;
    int month; 
    int year;

  public: 
    // constructor
    Date(int d, int m, int y): day{d}, month{m}, year{y} {}

    // defining friend function to overwrite operator
    friend ostream& operator<<(ostream &out, const Date &d);
};

// overwriting << operator which allows to print Date element
ostream& operator<<(ostream &out, const Date &d)
{
    out << d.day << "/" << d.month << "/" << d.year;
    return out;
}

class Blood {
  private: 
    int systolic;
    int diastolic;
    Date date;

  public: 
    // constructor
    Blood(int s, int di, Date da): systolic{s}, diastolic{di}, date{da} {}

    // Getter methods
    int getSystolic() { return systolic; }
    int getDiastolic() { return diastolic; }
    Date getDate() { return date; }

    friend ostream& operator<<(ostream &out, const Blood &b);
};

// overwriting << operator for printing
ostream& operator<<(ostream &out, const Blood &b)
{
    out << b.date << ": " << b.systolic << ", " << b.diastolic;
    return out;
}

class Patient {
  private:
    string name;
    vector<Blood> records;

  public:
    // constructor
    Patient(string n): name{n} {}

    // Setter method
    void addRecord(Blood b) {
      records.push_back(b);
    }

    void printReport() {
      cout << "Report for " << name << endl << "------------------" << endl;
      // get abnormal systolic blood pressures
      cout << "Abnormal systolic blood pressures: " << endl;
      bool any = false;
      for (int i=0; i<records.size(); i++) { 
        if (records[i].getSystolic() >= 140) {
          cout << records[i] << endl;
          any = true;
        }
      }
      if (!any) {
          cout << "No measurement was too high" << endl;
      }
      
      // calculate average diastolic blood pressures
      cout << "Average diastolic blood pressure: ";
      int sum = 0;
      for (int i=0; i<records.size(); i++) { 
        sum += records[i].getDiastolic();
      }
      cout << sum/records.size() << endl;

      // get maximal systolic pressures
      cout << "Maximum blood pressure: " << endl;
      int highest = 0;
      for (int i=0; i<records.size(); i++) { 
        if (records[i].getSystolic() > highest){
          highest = records[i].getSystolic();
        }
      }
      for (int i=0; i<records.size(); i++) {
        if (records[i].getSystolic() == highest) {
          cout << records[i] << endl;
        }
      }
      cout << endl;
    }
};

int main() {
  // Defining some test patients
  Patient mary("Mary");
  mary.addRecord(Blood(94,61, Date(2,5,2013)));
  mary.addRecord(Blood(97,65, Date(3,5,2013)));
  mary.addRecord(Blood(144,99, Date(4,5,2013)));
  mary.addRecord(Blood(123,88, Date(5,5,2013)));
  mary.addRecord(Blood(177,110, Date(6,5,2013)));
  mary.addRecord(Blood(145,89, Date(7,5,2013)));
  mary.printReport();

  Patient john("John");
  john.addRecord(Blood(88, 57, Date(15,5,2013)));
  john.addRecord(Blood(95, 61, Date(16,5,2013)));
  john.addRecord(Blood(114, 80, Date(17,5,2013)));
  john.addRecord(Blood(151, 96, Date(18,5,2013)));
  john.addRecord(Blood(176, 104, Date(19,5,2013)));
  john.addRecord(Blood(176, 110, Date(20,5,2013)));
  john.printReport();

  return 0;
}