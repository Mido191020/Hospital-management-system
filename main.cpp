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
    void display(){
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
void simpleTest1(){
    Hospital hospital(3);
    patient p("John Doe", "123 Main St", "critical", "male", 35, 5551234, "P001", 0.0);
    hospital.addPatient(p);
    p.display();
    p.editPatientInformation();
    p.display();
    float bill = p.calculateBillAmount();
    std::cout << "Patient bill amount: $" << bill << std::endl;
}
int main() {

}
