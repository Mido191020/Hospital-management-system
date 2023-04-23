#include<bits/stdc++.h>
using namespace std;
class patient{
private:
    string patientName, patientAddress,healthStatus,gender,patientId;
    int patientAge,patientPhoneNumber;
    double billAmount;
    chrono::steady_clock::time_point admitDate;
public:
    patient(){
        patientAddress=patientName=healthStatus=patientId=gender="";
        patientAge=patientPhoneNumber=0;
        billAmount=0.0;
        admitDate = std::chrono::steady_clock::now();
    }
    patient(string patientName,string patientAddress
            ,string healthStatus,string gender,
            int patientAge,int patientPhoneNumber
            ,string patientId,double billAmount)
            :patientName(patientName),
            patientAddress(patientAddress),
            healthStatus(healthStatus),
            gender(gender),patientAge(patientAge),
            patientPhoneNumber(patientPhoneNumber)
            ,patientId(patientId),
            billAmount(billAmount),
             admitDate(std::chrono::steady_clock::now())
            {

    }

    void setPatientName(string s){
                    patientName=s;
                             }
    void setPatientAddress(string s){
        patientAddress=s;
    }
    void setHealthStatus(string s){
        healthStatus=s;
    }
    void setPatientGender(string s){
       gender=s;
    }
    void setPatientAge(int s){
       patientAge=s;
    }
    void setPatientPhoneNumber(int s){
        patientPhoneNumber=s;
    }
    void setPatientId(int s){
        patientId=s;
    }
    void setBillAmount(double s){
        billAmount=s;
    }
    void setAdmitDate(std::chrono::steady_clock::time_point date) {
        admitDate = date;
    }
    string getPatientName()const{
        return patientName;
    }
    string getPatientAddress()const{
        return patientAddress;
    }
    string getHealthStatus()const{
        return healthStatus;
    }
    string getPatientGender()const{
        return gender;
    }
   int getPatientAge()const{
       return patientAge;
    }
    int getPatientPhoneNumber()const{
        return patientPhoneNumber;
    }
    double  getBillAmount()const{
        return billAmount;
    }
    string getPatientId()const{
        return patientId;
    }
    void display()const{
        cout<<"your information: \n";
        cout<<"Name: "<<getPatientName()<<"\n"
       <<"Age: "<<getPatientAge()<<"\n"
        <<"PatientGender: "<<getPatientGender()<<"\n"
        <<"HealthStatus: "<<getHealthStatus()<<"\n"
        <<"Address: "<<getPatientAddress()<<"\n"
        <<"Id: "<<getPatientId()<<"\n"
        <<"PhoneNumber: "<<getPatientPhoneNumber()<<"\n"
        <<"bill: "<<getBillAmount()<<"\n";
    }
    void editPatientInformation(){
        int choice;
        cin>>choice;
        do {
            cout<<"1-Edit name?\n";
            cout<<"2-Edit Address?\n";
            cout<<"3-Edit Age?\n";
            cout<<"4-Edit PhoneNumber?\n";
            cout<<"5-Edit HealthStatus?\n";
            cout<<"6-Edit Gender?\n";
            cout<<"7-Edit Id?\n";
            cout<<"8-exit?\n";

            if (choice==1){
                string s;
                cin>>s;
                setPatientName(s);
            }
            if (choice==2){
                string s;
                cin>>s;
                setPatientAddress(s);
            }
            if (choice==3){
                int s;cin>>s;
                setPatientAge(s);
            }
            if (choice==4){
               int s;
                cin>>s;
                setPatientPhoneNumber(s);
            }
            if (choice==5){
                string s;
                cin>>s;
                setHealthStatus(s);
            }
            if (choice==6){
                string s;
                cin>>s;
                setPatientGender(s);
            }
            if (choice==7){
                int s;
                cin>>s;
                setPatientId(s);
            }
            if (choice==8)break;
           cin>>choice;
        } while (choice!=8);

    }
    float calculateBillAmount() {

        std::chrono::duration<float> elapsed_time = std::chrono::steady_clock::now() - admitDate;
        int days = static_cast<int>(elapsed_time.count() / 86400); // 86400 seconds in a day

        // calculate the bill amount based on the daily rate and the patient's health status
        float daily_rate = 100.0; // arbitrary daily rate
        float health_factor = (healthStatus == "critical") ? 2.0 : 1.0; // arbitrary factor based on health status
        float bill_amount = days * daily_rate * health_factor;

        // update the bill amount property of the patient
        billAmount = bill_amount;

        return bill_amount;
    }

};
struct node{
    patient patient;
    node*next;
};
class Hospital{
    int numBeds;
node*head;
public:
    Hospital(){
        numBeds=0;
        head=NULL;
    }
    Hospital(int numBeds):numBeds(numBeds),head(NULL){

    }
    int getNumBeds()const{
        return numBeds;
    }
    void addPatient(const patient& data){
        if (numBeds==0){
            cout<<"No available beds in the hospital.\n";
            return;
        }
        node*temp=new node{data, head};
        head=temp;
        numBeds--;
    }
    void checkNumBeds()const{
        cout<<"the available beds in the hospital are: "<<numBeds<<endl;
    }
    void deletePatient(string patientId){
        //check the id to delete the patient
        node*curr=head;
        node*prev=NULL;
        while (curr!=NULL&&curr->patient.getPatientId()!=patientId){
            prev=curr;
            curr=curr->next;
        }
        if (curr== nullptr){
            cout<<"Patient with ID: "<<patientId<< " is not in the hospital." <<endl;
            return;
        }
        if (prev== nullptr){
            head=curr->next;
        } else
        {
            prev->next=curr->next;
        }
delete curr;
        numBeds++;
    }
   vector<patient>searchPatients(string searchTerm)const{
        vector<patient>result;
        node*curr=head;
       while (curr!= nullptr){
           if (curr->patient.getPatientName() == searchTerm || curr->patient.getPatientId()== searchTerm) {
                    result.push_back(curr->patient);
           }
           curr=curr->next;
    }
       return result;
    }
    void displayPatients()const{
        node*curr=head;
        while (curr!= nullptr){
            cout << "Patient Name: " <<curr->patient.getPatientName()<<"\n";
            cout << "Patient ID: " << curr->patient.getPatientId()<<"\n";
            cout << "Patient Age: " << curr->patient.getPatientAge()<<"\n";
            cout << "Patient Condition: " << curr->patient.getHealthStatus()<<"\n";
            cout << "----------------------" <<endl;
            curr=curr->next;
        }
    }
};
class schedule{
int staffId;
vector<string>tasks;
//represents the start and end times of a shift
vector<pair<time_t,time_t>>shiftTimes;
public:
    schedule(){
        staffId=0;
        tasks={" "};
        shiftTimes = {make_pair(time(nullptr), time(nullptr)), make_pair(time(nullptr), time(nullptr))};
    }
    schedule(int staffId,vector<string>tasks,vector<pair<time_t,time_t>>shiftTimes):staffId(staffId),tasks(tasks),shiftTimes(shiftTimes){
    }
    void addTask(const string&task){
        tasks.push_back(task);
    }
    void addShift(const pair<time_t,time_t>&shiftTime){
            shiftTimes.push_back(shiftTime);
    }
    vector<string> getTasks() const{
        return tasks;
    }
    pair<time_t, time_t> getShiftTimes(int shiftIndex) const{
        if (shiftIndex<0||shiftIndex>=shiftTimes.size()){
            throw out_of_range("out of bounds \n");
        }

        return shiftTimes[shiftIndex];
    }
    int getShiftCount() const {
        return shiftTimes.size();
    }
};
class staff{
private:
    string staffName,position,email,phoneNumber;
    vector<schedule>work;
public:
    staff(){
        staffName="";
        phoneNumber="";
        position="";
        email="";
    }
    staff( string staffName,string position,string email,string phoneNumber):staffName(staffName),position(position),email(email),phoneNumber(phoneNumber){

    }
    //staffName,position,email,phoneNumber
    void setStaffName(string s){
        staffName=s;
    }
    void setPosition(string s){
position=s;
    }
    void setEmail(string s){
email=s;
    }
    void setPhoneNumber(string s){
phoneNumber=s;
    }
   string getStaffName()const{
       return staffName;
    }
    string getPosition()const{
        return position;
    }
    string getEmail()const{
        return email;
    }
    string getPhoneNumber()const{
        return phoneNumber;
    }
    // Add a new schedule to the work  vector
    void addSchedule(schedule Schedule){
        work.push_back(Schedule);
    }
    // Remove a schedule from the work schedule vector
    void removeSchedule(int index) {
        if(index<0||index>=work.size()){
            throw out_of_range("out of range\n");
        }
        work.erase(work.begin()+ index);
    }
    // Calculate the total number of hours the staff member has worked
    double calculateHoursWorked() const {
        double totalHours = 0.0;
        for (const schedule &Schedule : work) {
            for (int i = 0; i < Schedule.getShiftCount(); i++) {
                pair<time_t, time_t> shiftTimes = Schedule.getShiftTimes(i);
                time_t startTime = shiftTimes.first;
                time_t endTime = shiftTimes.second;
                double hours = difftime(endTime, startTime) / (60.0 * 60.0);
                totalHours += hours;
            }
        }
        return totalHours;
    }
    double getPaycheck(double payRate){

        double totalPay=calculateHoursWorked()*payRate;
        return totalPay;
    }


};
class menu{
public:
    void displayMainMenu() {
        cout << "Main Menu:" << endl;
        cout << "1. Patients" << endl;
        cout << "2. Schedule" << endl;
        cout << "3. Staff" << endl;
        cout << "4. Exit" << endl;
    }
    void patientsMenu(vector<patient>& patients) {
        int choice;
        do {
            cout << "\n\n--- Patients Menu ---\n";
            cout << "1- Add a new patient\n";
            cout << "2- Display patient information\n";
            cout << "3- Edit patient information\n";
            cout << "4- Calculate patient bill\n";
            cout << "5- Exit\n";

            cin >> choice;

            switch (choice) {
                case 1:
                {
                    string name, address, healthStatus, gender, id;
                    int age, phoneNumber;
                    double billAmount;

                    cout << "Enter patient name: ";
                    cin >> name;
                    cout << "Enter patient address: ";
                    cin >> address;
                    cout << "Enter patient age: ";
                    cin >> age;
                    cout << "Enter patient phone number: ";
                    cin >> phoneNumber;
                    cout << "Enter patient health status: ";
                    cin >> healthStatus;
                    cout << "Enter patient gender: ";
                    cin >> gender;
                    cout << "Enter patient ID: ";
                    cin >> id;
                    cout << "Enter patient bill amount: ";
                    cin >> billAmount;

                    // create a new patient object and add it to the patients vector
                    patients.push_back(patient(name, address, healthStatus, gender, age, phoneNumber, id, billAmount));
                }
                    break;

                case 2: // display patient information
                {
                    string id;
                    cout << "Enter patient ID: ";
                    cin >> id;

                    // search for the patient with the given ID
                    bool found = false;
                    for (const auto& p : patients) {
                        if (p.getPatientId() == id) {
                            p.display();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Patient not found\n";
                    }
                }
                    break;

                case 3: // edit patient information
                {
                    string id;
                    cout << "Enter patient ID: ";
                    cin >> id;

                    // search for the patient with the given ID
                    bool found = false;
                    for (auto& p : patients) {
                        if (p.getPatientId() == id) {
                            p.editPatientInformation();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Patient not found\n";
                    }
                }
                    break;

                case 4: // calculate patient bill
                {
                    string id;
                    cout << "Enter patient ID: ";
                    cin >> id;

                    // search for the patient with the given ID
                    bool found = false;
                    for (auto& p : patients) {
                        if (p.getPatientId() == id) {
                            p.calculateBillAmount();
                            p.display(); // display the updated patient information
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Patient not found\n";
                    }
                }
                    break;

                case 5:{
                    cout<<"THANKS\n";
                    break;
                }

                default:
                    cout << "Invalid choice\n";
            }

        } while (choice != 5);
    }
    void displayScheduleMenu() {
        cout << "====== Schedule Menu ======" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Add shift" << endl;
        cout << "3. View tasks" << endl;
        cout << "4. View shifts" << endl;
        cout << "5. Go back" << endl;
        cout << "Enter your choice: ";
    }
    void handleScheduleMenu(schedule& Schedule) {
        int choice;
        while (true) {
            displayScheduleMenu();
            cin >> choice;
            if (choice == 1) {
                string task;
                cout << "Enter task: ";
                cin >> task;
                Schedule.addTask(task);
            } else if (choice == 2) {
                time_t start, end;
                cout << "Enter start time (YYYY-MM-DD HH:MM:SS): ";
                cin >> start;
                cout << "Enter end time (YYYY-MM-DD HH:MM:SS): ";
                cin >> end;
                Schedule.addShift(make_pair(start, end));
            } else if (choice == 3) {
                vector<string> tasks = Schedule.getTasks();
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i << ". " << tasks[i] << endl;
                }
            } else if (choice == 4) {
                for (int i = 0; i < Schedule.getShiftCount(); i++) {
                    pair<time_t, time_t> shift = Schedule.getShiftTimes(i);
                    cout << "Shift " << i << ": " << ctime(&shift.first) << " - " << ctime(&shift.second) << endl;
                }
            } else if (choice == 5) {
                return;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    void displayStaffMenu() {
        cout << "====== Staff Menu ======" << endl;
        cout << "1. Add schedule" << endl;
        cout << "2. Remove schedule" << endl;
        cout << "3. Calculate hours worked" << endl;
        cout << "4. Get paycheck" << endl;
        cout << "5. Go back" << endl;
        cout << "Enter your choice: ";
    }
    void handleStaffMenu(staff& Staff, double payRate) {
        int choice, index;
        while (true) {
            displayStaffMenu();
            cin >> choice;
            if (choice == 1) {
                schedule Schedule;
                handleScheduleMenu(Schedule);
                Staff.addSchedule(Schedule);
            } else if (choice == 2) {
                cout << "Enter index of schedule to remove: ";
                cin >> index;
                try {
                    Staff.removeSchedule(index);
                    cout << "Schedule removed successfully." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what();
                }
            } else if (choice == 3) {
                cout << "Total hours worked: " << Staff.calculateHoursWorked() << endl;
            } else if (choice == 4) {
                cout << "Total paycheck: " << Staff.getPaycheck(payRate) << endl;
            } else if (choice == 5) {
                return;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
void run() {
    int ch;
    do {
        cout << "Main Menu:" << endl;
        cout << "1. Patients" << endl;
        cout << "2. Schedule" << endl;
        cout << "3. Staff" << endl;
        cout << "4. Exit" << endl;
        cin >> ch;
        if (ch == 1) {
            vector<patient> patients;
            int choice;
            do {
                cout << "\n\n--- Patients Menu ---\n";
                cout << "1- Add a new patient\n";
                cout << "2- Display patient information\n";
                cout << "3- Edit patient information\n";
                cout << "4- Calculate patient bill\n";
                cout << "5- Exit\n";

                cin >> choice;

                switch (choice) {
                    case 1: {
                        string name, address, healthStatus, gender, id;
                        int age, phoneNumber;
                        double billAmount;

                        cout << "Enter patient name: ";
                        cin >> name;
                        cout << "Enter patient address: ";
                        cin >> address;
                        cout << "Enter patient age: ";
                        cin >> age;
                        cout << "Enter patient phone number: ";
                        cin >> phoneNumber;
                        cout << "Enter patient health status: ";
                        cin >> healthStatus;
                        cout << "Enter patient gender: ";
                        cin >> gender;
                        cout << "Enter patient ID: ";
                        cin >> id;
                        cout << "Enter patient bill amount: ";
                        cin >> billAmount;

                        // create a new patient object and add it to the patients vector
                        patients.push_back(
                                patient(name, address, healthStatus, gender, age, phoneNumber, id, billAmount));
                    }
                        break;

                    case 2: // display patient information
                    {
                        string id;
                        cout << "Enter patient ID: ";
                        cin >> id;

                        // search for the patient with the given ID
                        bool found = false;
                        for (const auto &p: patients) {
                            if (p.getPatientId() == id) {
                                p.display();
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Patient not found\n";
                        }
                    }
                        break;

                    case 3: // edit patient information
                    {
                        string id;
                        cout << "Enter patient ID: ";
                        cin >> id;

                        // search for the patient with the given ID
                        bool found = false;
                        for (auto &p: patients) {
                            if (p.getPatientId() == id) {
                                p.editPatientInformation();
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Patient not found\n";
                        }
                    }
                        break;

                    case 4: // calculate patient bill
                    {
                        string id;
                        cout << "Enter patient ID: ";
                        cin >> id;

                        // search for the patient with the given ID
                        bool found = false;
                        for (auto &p: patients) {
                            if (p.getPatientId() == id) {
                                p.calculateBillAmount();
                                p.display(); // display the updated patient information
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Patient not found\n";
                        }
                    }
                        break;

                    case 5: {
                        cout << "THANKS\n";
                        break;
                    }

                    default:
                        cout << "Invalid ch\n";
                }

            } while (choice != 5);
        }
        else if (ch == 2) {
            schedule s;
            cout << "====== Schedule Menu ======" << endl;
            cout << "1. Add task" << endl;
            cout << "2. Add shift" << endl;
            cout << "3. View tasks" << endl;
            cout << "4. View shifts" << endl;
            cout << "5. Go back" << endl;
            cout << "Enter your choice: ";
            schedule Schedule;
            int choice;
            while (true) {
                cin >> choice;
                if (choice == 1) {
                    string task;
                    cout << "Enter task: ";
                    cin >> task;
                    Schedule.addTask(task);
                } else if (choice == 2) {
                    time_t start, end;
                    cout << "Enter start time (YYYY-MM-DD HH:MM:SS): ";
                    cin >> start;
                    cout << "Enter end time (YYYY-MM-DD HH:MM:SS): ";
                    cin >> end;
                    Schedule.addShift(make_pair(start, end));
                } else if (choice == 3) {
                    vector<string> tasks = Schedule.getTasks();
                    for (int i = 0; i < tasks.size(); i++) {
                        cout << i << ". " << tasks[i] << endl;
                    }
                } else if (choice == 4) {
                    for (int i = 0; i < Schedule.getShiftCount(); i++) {
                        pair<time_t, time_t> shift = Schedule.getShiftTimes(i);
                        cout << "Shift " << i << ": " << ctime(&shift.first) << " - " << ctime(&shift.second) << endl;
                    }
                } else if (choice == 5) {
                    return;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
        else if (ch == 3) {
            double payRate;
            cout << "enter pay Rate\n";
            cin >> payRate;
            staff Staff;
            cout << "====== Staff Menu ======" << endl;
            cout << "1. Add schedule" << endl;
            cout << "2. Remove schedule" << endl;
            cout << "3. Calculate hours worked" << endl;
            cout << "4. Get paycheck" << endl;
            cout << "5. Go back" << endl;
            cout << "Enter your choice: \n";
            int choice, index;
            while (true) {
                displayStaffMenu();
                cin >> choice;
                if (choice == 1) {
                    schedule Schedule;
                    handleScheduleMenu(Schedule);
                    Staff.addSchedule(Schedule);
                } else if (choice == 2) {
                    cout << "Enter index of schedule to remove: ";
                    cin >> index;
                    try {
                        Staff.removeSchedule(index);
                        cout << "Schedule removed successfully." << endl;
                    } catch (const out_of_range &e) {
                        cout << e.what();
                    }
                } else if (choice == 3) {
                    cout << "Total hours worked: " << Staff.calculateHoursWorked() << endl;
                } else if (choice == 4) {
                    cout << "Total paycheck: " << Staff.getPaycheck(payRate) << endl;
                } else if (choice == 5) {
                    return;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
        else{
            cout << "invalid choice\n";
        }
    } while (ch != 4);

}

};
int main() {
menu m;
m.run();
}
