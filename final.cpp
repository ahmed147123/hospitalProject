#include <iostream>
#include<queue>
using namespace std;

struct prescription_data {
    int patient_ID;
    std::string doctor_name;
    int precriptiont_code;
    std::string prescript_text;

};


struct prescription {
    int top = -1;
    prescription_data  pricript[3];
};

struct doctor {
    std::string name;
    std::string sex;
    int birth_date;
    int social_security_number;
    std::string scientific_area;
    std::string  degree;
    int doctor_id;

};

struct doctor_stack {

    int top = -1;
    doctor DOCTOR[20];

}d_s;
struct Drugs_data
{
    std::string drug_name;
    int time_h;
    int time_min;
};

struct  patient {
    int patient_ID;
    std::string name;
    std::string sex;
    int patient_phone;
    std::string address;
    int birth_date;
    std::string medical_histroy;
    std::string allegry;
    int systolic_blood_pressure;
    int distolic_blood_pressure;
    int heart_rate;
    double tempreture;
    int health_condition;

    prescription p_s;
    std::string date;
    Drugs_data p_drugs[30];
};
struct patient_no {
    int rear = 0, fronte = 0;
    patient item[10];

}
q;

struct icu {
    std::string icu_name;
    int  icu_code;
    std::string icu_manager_name;
    int icu_beds_number;
    patient_no q;
};

icu ICU[3];

int check_patient_id(icu* ICU, int p_id);// check weather there is a patient with id or not
int T_fix ();
void enqueue(icu*, int, int, std::string, std::string, int, std::string, int, std::string, std::string, int, int, int, double);  //تسجيل مريض في وحد عنايه مركزه
void dequeue(icu*, int);//اخراج مريض من وحده العنايه
int  isfull(icu*, int);//اختبار هل وحده العنايه ممتلئه
int  isempty(icu*, int);//الاختبار هل وحده العنايه فارغه
void display(icu*, int);//عرض المرضي الموجودين في وحده عنايه محدده
int  check_id(icu*, int, int);//اختبار لمعرفه تكرار الا الكود الخاص بالمريض متكرر ام لا
void display_ICU_information(icu*, int);//فنكشن لعرض معلومات وحده العنايه المركزه
void add_new_doctor(doctor_stack&, int);//اضافه مرض
int  check_d_s_isempty(doctor_stack);//اختبار اذا كانت المستشفي بها مرضي ام لا
void display_d_with_id(doctor_stack, int);//عرض معلومات الداتره عن طريق ال الاي دي
int  check_d_id(doctor_stack, int);//اختبار الاي دي موجود ام لا
void display_prescription(icu*);//عرض الروشته
void write_prescription(icu*, doctor_stack&);//كتابه روشته
int  check_doctor_name(doctor_stack, std::string);//معرفه اذا كان الدكتور في المستشفي ام لا
int  find_patient_number_using_id(icu* ICU, int patient_id);
int find_icu_number_using_id(icu* ICU, int patient_id);
int  empty_prescription(icu*,int patient_ID);// اختبار ما اذان كانت لاتوجد روشته مكتوبه للمريض
int icu_num;
int patient_num;
int main()
{
    priority_queue<int>health_conditions;
    q.fronte = 0;
    q.rear = 0;

    int choice, elements, choice0, icu_number, choice2, numer_of_doctor, icu_nom, choice3;
    int patient_ID;
    std::string  name;
    std::string sex;
    int patient_phone;
    std::string address;
    int birth_date;
    std::string medical_histroy;
    std::string allegry;
    int systolic_blood_pressure;
    int distolic_blood_pressure;
    int heart_rate;
    double tempreture;
    int health_condition;
    std::string date;
    char esc = 'f';
    while (esc == 'f')                                        //while loop containing the program
    {
        std::cout << "please choose one choice " << std::endl;
        std::cout << "1-icu and its patient track" << std::endl;
        std::cout << "2-doctors  track" << std::endl;
        std::cout << "3-prescription of patients" << std::endl;
        std::cout << "4-patien's drug data" << std::endl;
        std::cout << "5-exit from the programe" << std::endl;
        choice0 = T_fix();


        if (choice0 == 1)
        {                                    // start track 1
            char back = 'n';
            while (back == 'n') {
                std::cout << "choose the ICU you want" << std::endl;
                std::cout << "1-ICU number 1 " << std::endl;
                std::cout << "2-ICU number 2 " << std::endl;
                std::cout << "3-ICU number 3 " << std::endl;
                std::cout << "4-back to main menu" << std::endl;

                     icu_number = T_fix();//اختيار رقم الالوحده
                if (icu_number == 1 || icu_number == 2 || icu_number == 3)
                {
                    char k = 'f';
                    while (k == 'f')
                    {

                        std::cout << "1- enqueue an patient in the ICU number" << icu_number << std::endl;
                        std::cout << "2- dequeue an patient from the ICU number" << icu_number << std::endl;
                        std::cout << "3- display all patients data in the ICU number " << icu_number << std::endl;
                        std::cout << "4- display the data of ICU number" << icu_number << std::endl;
                        std::cout << "5- back to icu menu" << std::endl;
                        std::cout << "please choose one of these elements  " << std::endl;
                           choice= T_fix();


                        if (choice == 1)
                        {

                            std::cout << "what is the number of patients you want to enqueue?" << std::endl;
                               elements= T_fix();
                            for (int i = 1; i <= elements; i++) {
                                std::cout << "please enter the data of patient " << i << std::endl << "*****" << std::endl;
                                std::cout << "patient ID:";
                                patient_ID= T_fix();
                                while (check_id(&ICU[0], icu_number, patient_ID))
                                {
                                    std::cout << "the id already exist please enter another ID" << std::endl;
                                    std::cout << "patient ID:";
                                patient_ID= T_fix();

                                }
                                std::cin.ignore();
                                std::cout <<  "name:"<< std::endl ;
                                getline(cin, name);
                                std::cout << "sex:"<< std::endl ;
                                getline(cin, sex);
                                std::cout <<"phone:"<< std::endl ;
                                patient_phone = T_fix();
                                std::cout << "adress:"<< std::endl ;
                                getline(cin, address);
                                std::cout << "birthdate:"<< std::endl ;
                                 birth_date = T_fix();
                                 std::cin.ignore();
                                std::cout << "medical history:"<< std::endl ;
                                getline(cin, medical_histroy);
                                std::cout <<"allgry:"<< std::endl ;
                                getline(cin, allegry);
                                std::cout << "systolic_blood_pressure:"<< std::endl ;
                                systolic_blood_pressure= T_fix();
                                std::cout <<"distolic_blood_pressure:"<< std::endl ;
                                distolic_blood_pressure = T_fix();
                                std::cout << "heart_rate:"<< std::endl ;
                                heart_rate= T_fix();
                                std::cout <<"tempreture:"<< std::endl ;
                                std::cin >> tempreture;
                                std::cout << std::endl << "health condition from 10:";
                                health_condition=T_fix();
                                health_conditions.push(health_condition);

                                enqueue(
                                    &ICU[0],
                                    icu_number,
                                    patient_ID,
                                    name,
                                    sex,
                                    patient_phone,
                                    address,
                                    birth_date,
                                    medical_histroy,
                                    allegry,
                                    systolic_blood_pressure,
                                    distolic_blood_pressure,
                                    heart_rate,
                                    tempreture
                                );
                            }
                            std::cout << "done" << std::endl;


                        }

                        else if (choice == 2)
                        {

                            if (isempty(&ICU[0], icu_number)) {
                                std::cout << "the ICU number" << icu_number << " is empty" << std::endl;
                            }
                            else
                            {
                                int way;
                                cout << "you want dequeue patient based on " << endl;
                                cout << "1_prioritet" << endl;
                                cout << "2_time he/she spent in icu" << endl;
                                    way= T_fix();
                                if (way == 1)
                                {
                                    cout << "whate is the number you wante to dequeue" << endl;
                                       elements = T_fix();
                                    while (elements > health_conditions.size()) {
                                        cout << "ther are " << health_conditions.size() << " elements only " << endl;
                                        cout << "please enter number less than or equal: " << health_conditions.size() << endl;
                                           elements = T_fix();
                                    }
                                    for (int i = 1; i <= elements; i++) {
                                        health_conditions.pop();
                                    }

                                }
                                if (way == 2)
                                {
                                    cout << "whate is the number you wante to dequeue" << endl;
                                    elements = T_fix();
                                    while (elements > (ICU[icu_number].q.fronte - ICU[icu_number].q.rear)) {
                                        cout << "ther are " << ICU[icu_number].q.rear - ICU[icu_number].q.fronte << " elements only " << endl;
                                        cout << "please enter number less than or equal: " << ICU[icu_number].q.rear - ICU[icu_number].q.fronte << endl;
                                     elements = T_fix();
                                    }
                                    for (int i = 1; i <= elements; i++) {
                                        dequeue(&ICU[0], icu_number);
                                    }
                                }



                            }
                            std::cout << "done" << std::endl;
                        }

                        else if (choice == 3)
                        {
                            display(&ICU[0], icu_number);
                        }

                        else if (choice == 4)
                        {

                            display_ICU_information(&ICU[0], icu_number);
                        }
                        else if (choice == 5)
                        {
                            k = 'T';
                        }
                        else
                        {
                            std::cout << "there is no ICU with the number" << icu_number << "please chose ICU 1 or 2 or 3" << std::endl;
                        }

                    }
                }
                else if (icu_number == 4)
                {
                    back = 'y';
                }
                else
                {
                    std::cout << "invalid choice" << std::endl;
                }
            }
        }                                                      //end track 1

        else if (choice0 == 2)
        {
            char back = 'n';
            while (back == 'n') {
                std::cout << "1-add new doctors" << std::endl;
                std::cout << "2-display specific doctor information with id " << std::endl;
                std::cout << "3-go back to main menu" << std::endl;
      choice2= T_fix();
                if (choice2 == 1)
                {
                    std::cout << "whate is the number of doctors you want to add?" << std::endl;
                numer_of_doctor = T_fix();
                    for (int i = 1; i <= numer_of_doctor; i++)
                    {
                        add_new_doctor(d_s, i);

                    }
                }
                else if (choice2 == 2)
                {

                    if (check_d_s_isempty(d_s))
                    {

                        std::cout << "there is  no doctor in the hospiatal" << std::endl;

                    }
                    else
                    {
                        std::cout << "please  enter the the id of the doctor you want to display" << std::endl;
                        std::cout << "ID:";
                        int d_id;      //d_id اختصار ل الاي دي الخاص بالدكتور
                         d_id = T_fix();

                        while (check_d_id(d_s, d_id)) {
                            std::cout << "the id" << d_id << " doesn't exsit please enter anothe one" << std::endl;
                            std::cout << "ID:";
                             d_id = T_fix();

                        }

                        display_d_with_id(d_s, d_id);

                    }

                }
                else if (choice2 == 3)
                {
                    back = 't';
                }
                else
                {
                    std::cout << "invalid choice" << std::endl;
                }
            }
            //end track 2
        }
        else if (choice0 == 3)
        {
            char back = 'n';
            while (back == 'n')
            {
                std::cout << "1-write a prescrition" << std::endl;
                std::cout << "2-display a patient prescrption" << std::endl;
                std::cout << "3-go back to main menu" << std::endl;
                   choice3 = T_fix();
                if (choice3 == 1)
                {
                    if (isempty(&ICU[0], 0) && isempty(&ICU[0], 1) && isempty(&ICU[0], 2)) {    //السطر ده بيختبر هل المستشفي فاضيه ولا فيها مرضي تم تسجلهم
                        std::cout << "there is no patient recorded in the system" << std::endl;
                        std::cout << "please choose the the track of ice and patient and record patient" << std::endl;
                        back = 't';
                    }
                    else if (d_s.top == -1) {      // السطر ده بيخبر هل في داكتره تم تسجلم ام لا
                        std::cout << "there is no doctores recorder in the system " << std::endl;
                        std::cout << "please go to the track of doctor and add doctores in the syatem" << std::endl;
                        back = 't';
                    }
                    else {
                        write_prescription(&ICU[0], d_s);

                    }
                }
                else if (choice3 == 2)
                {
                    if (isempty(&ICU[0], 0) && isempty(&ICU[0], 1) && isempty(&ICU[0], 2)) {
                        std::cout << "there is no patient recorded in the system" << std::endl;
                        std::cout << "please chose the the track of ice and patient and record patient" << std::endl;
                         back = 't';
                    }
                    else if (d_s.top == -1) {
                        std::cout << "there is no doctores recorder in the system " << std::endl;
                        std::cout << "please go to the track of doctor and add doctores in the syatem" << std::endl;
                        back = 't';
                    }
                    else {

                        display_prescription(&ICU[0]);
                        std::cout << "************" << std::endl;


                    }
                }
                else if (choice3 == 3)
                {
                    back = 't';
                }
                else
                {
                    std::cout << "invalid choice" << std::endl;
                }
            }
        }

        else if (choice0==4)
        {
            char back ='n', k ='f',cont='f';
            int day,hour,mins,choice_d,p_N =0,icu_number =0 ;
            std::string  drug_name;
            while (back=='n')
            {
                std::cout << "choose the ICU you want" << std::endl;
                std::cout << "1-ICU number 1 " << std::endl;
                std::cout << "2-ICU number 2 " << std::endl;
                std::cout << "3-ICU number 3 " << std::endl;
                std::cout << "4-back to main menu" << std::endl;
              icu_number = T_fix();                       //اختيار رقم الالوحده
                if (icu_number == 1 || icu_number == 2 || icu_number == 3)
                {

            std::cout<<"enter patient id"<<std::endl;
             patient_ID= T_fix();
            while (!check_patient_id(&ICU[0],patient_ID)&&k=='f')
            {

              std::cout <<"this patient id doesn't  exist in this icu "<<std::endl;
              std::cout<<"1.enter patient id again"<<std::endl;
              std::cout<<"2.back to main menu"<<std::endl;
                  choice_d = T_fix();
              if(choice_d==1)
              {
                  std::cout <<" patient id :"<<std::endl;
                  patient_ID= T_fix();
              }
              else if (choice_d==2)
              {
              k='t';
              back='y';
              }
              else
              {
              std::cout<<"invalid choice"<<std::endl;
              }
              }
            while (k=='f')
            {

              p_N = find_patient_number_using_id(&ICU[icu_number],patient_ID);
              std::cout<<"choose one of the following:"<<std::endl;
              std::cout<<"1.enter drugs data to this patient"<<std::endl;
              std::cout<<"2.represent the drugs data of this patient"<<std::endl;
              std::cout<<"3.back to previous menu"<<std::endl;
               choice_d= T_fix();
              if(choice_d==1)
              {
                  std::cout<<"enter the day(form 1 to 30)"<<std::endl;//* note
                    day= T_fix();
                  std::cout<<"enter drug name"<<std::endl;
                  std::cin.ignore();
                  getline(cin, drug_name);
                  std::cout<<"enter time in hours (24 format)"<<std::endl;
                   hour = T_fix();
                  std::cout<<"enter time in mins"<<std::endl;
                 mins = T_fix();
                  ICU[icu_number].q.item[q.fronte].p_drugs[day-1].drug_name= drug_name;//add patient struct to the call
                  ICU[icu_number].q.item[q.fronte].p_drugs[day-1].time_h= hour;
                  ICU[icu_number].q.item[q.fronte].p_drugs[day-1].time_min= mins;//المفروض نرجع للقائمه تانى
                  std::cout<<"done"<<std::endl;
              }
              else if (choice_d==2)
              {
                  while(cont=='f')
                  {
                  std::cout<<"how many days to you want to represent?"<<std::endl;
                  day= T_fix();
                  if(day<31)
                  {
                  for (int i=0;i<day;i++)
                  {
                  std::cout<<"day"<< i+1<<":"<<std::endl;
                  std::cout<<"drug name:"<<ICU[icu_number].q.item[q.fronte]. p_drugs[i].drug_name<<std::endl;
                  std::cout<<"time : { "<<ICU[icu_number].q.item[q.fronte].p_drugs[i].time_h<<":"<<ICU[icu_number].q.item[q.fronte].p_drugs[i].time_min<<" } "<<std::endl;
                  cont='t';
                  }
                  }
                  else
                  {
                   std::cout<<"the maximum number of days you can store and represent is 30 days"<<std::endl;
                  }
                  }

              }
              else if (choice_d==3)
              {
                  k='t';
                  back='y';
              }
              else
              {
               std::cout<<"invalid choice"<<std::endl;
              }
             }
             }
                else if (icu_number==4)
                {
                 back='y';
                }
                else
                {
                 std::cout<<"invalid choice"<<std::endl;
                }
            }
         }

         else if (choice0==5)
         {
          esc ='T';
         }
         else
         {
         std::cout <<"invalid choice"<<std::endl;
         }
        }
    }

    //END OF THE PROGRAME


int T_fix()
{
    int numbers ;

    std::cin >> numbers;
    while (!std::cin.good())
    {
        std::cout << "u can only type numbers here pls try again" << std::endl;
        std::cin.clear();
        std::cin.ignore(INT_FAST32_MAX, '\n');
        std::cin >> numbers;
    }
    return numbers;
}
void enqueue(
    icu* ICU,
    int icu_number,
    int patient_ID,
    std::string  name,
    std::string sex,
    int patient_phone,
    std::string address,
    int birth_date,
    std::string medical_histroy,
    std::string allegry,
    int systolic_blood_pressure,
    int distolic_blood_pressure,
    int heart_rate,
    double tempreture)
{
    if (isfull(&ICU[0], icu_number))
        std::cout << "the queue is full" << std::endl;
    else {
        ICU[icu_number].q.item[q.rear].patient_ID = patient_ID;
        ICU[icu_number].q.item[q.rear].name = name;
        ICU[icu_number].q.item[q.rear].address = address;
        ICU[icu_number].q.item[q.rear].allegry = allegry;
        ICU[icu_number].q.item[q.rear].birth_date = birth_date;
        ICU[icu_number].q.item[q.rear].distolic_blood_pressure = distolic_blood_pressure;
        ICU[icu_number].q.item[q.rear].heart_rate = heart_rate;
        ICU[icu_number].q.item[q.rear].medical_histroy = medical_histroy;
        ICU[icu_number].q.item[q.rear].patient_phone = patient_phone;
        ICU[icu_number].q.item[q.rear].sex = sex;
        ICU[icu_number].q.item[q.rear].systolic_blood_pressure = systolic_blood_pressure;
        ICU[icu_number].q.item[q.rear].tempreture = tempreture;
        ICU[icu_number].q.rear = ICU[icu_number].q.rear + 1;
    }

}
void dequeue(icu* ICU, int icu_number) {



    ICU[icu_number].q.fronte = ICU[icu_number].q.fronte + 1;

}

int isempty(icu* ICU, int icu_number) {
    if (ICU[icu_number].q.fronte == ICU[icu_number].q.rear)
        return 1;
    else
        return 0;
}
int isfull(icu* ICU, int icu_number) {

    if (ICU[icu_number].q.rear == 9) {
        return 1;
    }
    else
        return 0;
}
void display(icu* ICU, int icu_number) {

    for (int i = ICU[icu_number].q.fronte; i != ICU[icu_number].q.rear; i++) {
        std::cout << "patient_ID:" << ICU[icu_number].q.item[q.fronte].patient_ID << std::endl;
        std::cout << "name:" << ICU[icu_number].q.item[q.fronte].name << std::endl;
        std::cout << "sex:" << ICU[icu_number].q.item[q.fronte].sex << std::endl;
        std::cout << "birth date:" << ICU[icu_number].q.item[q.fronte].birth_date << std::endl;
        std::cout << "phone:0" << ICU[icu_number].q.item[q.fronte].patient_phone << std::endl;
        std::cout << "adress:" << ICU[icu_number].q.item[q.fronte].address << std::endl;
        std::cout << "sex:" << ICU[icu_number].q.item[q.fronte].sex << std::endl;
        std::cout << "tempreture:" << ICU[icu_number].q.item[q.fronte].tempreture << std::endl;
        std::cout << "presure:" << ICU[icu_number].q.item[q.fronte].systolic_blood_pressure << "/" << q.item[q.fronte].distolic_blood_pressure << std::endl;
        std::cout << "heart reate:" << ICU[icu_number].q.item[q.fronte].heart_rate << std::endl;
        std::cout << "medical history:" << ICU[icu_number].q.item[q.fronte].medical_histroy << std::endl;
        std::cout << "allegry:" << ICU[icu_number].q.item[q.fronte].allegry << std::endl;
        std::cout << "**************" << std::endl;

    }
}
int check_id(icu* ICU, int icu_number, int patient_ID) {
    if (ICU[icu_number].q.rear == 0)
        return 0;
    else {
        for (int i = ICU[icu_number].q.fronte; i < ICU[icu_number].q.rear; i++) {
            if (ICU[icu_number].q.item[i].patient_ID == patient_ID)
                return 1;
            else
                return 0;
        }
    }
}
void display_ICU_information(icu* ICU, int icu_number) {


    if (icu_number == 1) {
        std::cout << "ICU name:NICU" << std::endl;
        std::cout << "ICU code:111" << std::endl;
        std::cout << "ICU beds number:100" << std::endl;
        std::cout << "ICU manager:saeed khaleed" << std::endl;
    }
    else if (icu_number == 2) {

        std::cout << "ICU name:PJDB" << std::endl;
        std::cout << "ICU code:555" << std::endl;
        std::cout << "ICU beds number:50" << std::endl;
        std::cout << "ICU manager:haytham emad" << std::endl;
    }
    else if (icu_number == 3) {
        std::cout << "ICU name:DYUS" << std::endl;
        std::cout << "ICU code:222" << std::endl;
        std::cout << "ICU beds number:30" << std::endl;
        std::cout << "ICU manager:mahmoud el behady" << std::endl;
    }
}

void  add_new_doctor(doctor_stack& d_s, int i) {

    std::cout << "please enter the data of the doctor number" << i << std::endl << "********";
    d_s.top = d_s.top + 1;
    std::cout << std::endl << "doctor code:";
    int doctor_id;
        doctor_id= T_fix();
    d_s.DOCTOR[d_s.top].doctor_id = doctor_id;

    std::cout << std::endl << "doctor name:";
    std::string doctor_name;
    std::cin.ignore();
    getline(cin, doctor_name);
    d_s.DOCTOR[d_s.top].name = doctor_name;

    std::cout << std::endl << "doctor sex:";
    std::string doctor_sex;
    getline(cin, doctor_sex);
    d_s.DOCTOR[d_s.top].sex = doctor_sex;

    std::cout << std::endl << "doctor birth date:";
    int doctor_birth_date;
    doctor_birth_date = T_fix();

    d_s.DOCTOR[d_s.top].birth_date = doctor_birth_date;

    std::cout << std::endl << "doctor social security number:";
    int social_security_number;
     social_security_number = T_fix();
    d_s.DOCTOR[d_s.top].social_security_number = social_security_number;

    std::cout << std::endl << "doctor scientific area:";
    std::string scientific_area;
    std::cin.ignore();
    getline(cin,scientific_area);
    d_s.DOCTOR[d_s.top].scientific_area = scientific_area;

    std::cout << std::endl << "doctor degree:";
    std::string degree;
    std::cin >> degree;
    d_s.DOCTOR[d_s.top].degree = degree;

}

void display_d_with_id(doctor_stack d_s, int d_id) {

    while (d_s.top >= 0) {
        if (d_s.DOCTOR[d_s.top].doctor_id == d_id) {
            std::cout << "the information of doctor with id:" << d_id << "is" << std::endl;
            std::cout << "doctor name:" << d_s.DOCTOR[d_s.top].name << std::endl;
            std::cout << "doctor sex:" << d_s.DOCTOR[d_s.top].sex << std::endl;
            std::cout << "doctor birth date:" << d_s.DOCTOR[d_s.top].birth_date << std::endl;
            std::cout << "doctor social security number:" << d_s.DOCTOR[d_s.top].social_security_number << std::endl;
            std::cout << "doctor scientific area:" << d_s.DOCTOR[d_s.top].scientific_area << std::endl;
            std::cout << "doctor degree:" << d_s.DOCTOR[d_s.top].degree << std::endl;
            break;
        }

        d_s.top = d_s.top - 1;
    }
}

int check_d_s_isempty(doctor_stack d_s) {
    if (d_s.top == -1) {
        return 1;
    }
    else
        return 0;
}

int check_d_id(doctor_stack d_s, int d_id) {


    while (d_s.top >= 0) {
        if (d_s.DOCTOR[d_s.top].doctor_id == d_id) {

            return 0;
            break;
        }
        d_s.top = d_s.top - 1;

    }

    return 1;
}

void write_prescription(icu* ICU, doctor_stack& d_s) {

    std::cout << " patient id :";
    int patient_ID;
   patient_ID= T_fix();
    while (!check_patient_id(&ICU[0], patient_ID)) {
        std::cout << "this patient id doesn't exist in the hospital enter another id" << std::endl;
        std::cout << " patient name :";
       patient_ID= T_fix();
    }

    std::cout << " prescription code :";
    int pr_code;
       pr_code= T_fix();

    std::cout << " doctor name:";
    std::string d_name;
    std::cin.ignore();
    getline(cin, d_name);
    while (!check_doctor_name(d_s, d_name)) {
        std::cout << "the doctor name doesn't exist in the hospital enter another name" << std::endl;
        std::cout << " doctor name:";
        std::cin.ignore();
        getline(cin, d_name);
    }
    std::cout << "please write your prescription" << std::endl;
    std::string p_prescription;
    std::cin.ignore();
    getline(cin, p_prescription);

    icu_num = find_icu_number_using_id(&ICU[0], patient_ID);
    patient_num = find_patient_number_using_id(&ICU[0], patient_ID);

    ICU[icu_num].q.item[patient_num].p_s.top = ICU[icu_num].q.item[patient_num].p_s.top + 1; /////item1 for patient number
    ICU[icu_num].q.item[patient_num].p_s.pricript[ICU[icu_num].q.item[patient_num].p_s.top].patient_ID = patient_ID;                              ///// item2 for prescription
    ICU[icu_num].q.item[patient_num].p_s.pricript[ICU[icu_num].q.item[patient_num].p_s.top].doctor_name = d_name;
    ICU[icu_num].q.item[patient_num].p_s.pricript[ICU[icu_num].q.item[patient_num].p_s.top].precriptiont_code = pr_code;
    ICU[icu_num].q.item[patient_num].p_s.pricript[ICU[icu_num].q.item[patient_num].p_s.top].prescript_text = p_prescription;

}

int check_patient_id(icu* ICU, int p_id) {

    for (int i = 0; i < 3; i++) {

        for (int ii = 0; ii < 10; ii++) {

            if (ICU[i].q.item[ii].patient_ID == p_id)
            {
                return 1;
                break;
            }
        }
    }
    return 0;

}
int check_doctor_name(doctor_stack d_s, std::string d_name) {

    while (d_s.top >= 0) {

        if (d_s.DOCTOR[d_s.top].name == d_name)
        {
            return 1;
            break;
        }
        else
            d_s.top = d_s.top - 1;

    }
    return 0;
}

int find_icu_number_using_id(icu* ICU, int patient_id)
{
    for (int i = 0; i < 3; i++)
        for (int ii = 0; ii < 10; ii++)
            if (ICU[i].q.item[ii].patient_ID == patient_id)
            {
                return i;
                break;
            }
}


void  display_prescription(icu* ICU)
{

    std::cout << " patient id :";
    int patient_ID;
   patient_ID= T_fix();
    while (!check_patient_id(&ICU[0], patient_ID)) {
        std::cout << "this patient id doesn't exist in the hospital enter another name" << std::endl;
       patient_ID= T_fix();
    }
    int icu_num;
    int patient_num;
    icu_num = find_icu_number_using_id(&ICU[0], patient_ID);
    patient_num = find_patient_number_using_id(&ICU[0], patient_ID);

    if (empty_prescription(&ICU[0], patient_ID)) {
        std::cout << "no prescription written yet" << std::endl;
    }
    else {

        std::cout << "there is " << ICU[icu_num].q.item[patient_num].p_s.top << "witten" << std::endl;
        while (ICU[icu_num].q.item[patient_num].p_s.top >= 0) {
            std::cout << "**********************" << std::endl;

            std::cout << "prescription code:" << ICU[icu_num].q.item[patient_num].p_s.pricript[ICU[icu_num].q.item[patient_num].p_s.top].precriptiont_code << std::endl;

            std::cout << "prescription writen to:" << ICU[icu_num].q.item[patient_num].p_s.pricript[ICU[icu_num].q.item[patient_num].p_s.top].patient_ID << std::endl;

            std::cout << "prescription writen from:" << ICU[icu_num].q.item[patient_num].p_s.pricript[ICU[icu_num].q.item[patient_num].p_s.top].doctor_name << std::endl;

            std::cout << "prescription_text:" << ICU[icu_num].q.item[patient_num].p_s.pricript[ICU[icu_num].q.item[patient_num].p_s.top].prescript_text << std::endl;
            ICU[icu_num].q.item[patient_num].p_s.top = ICU[icu_num].q.item[patient_num].p_s.top - 1;
        }
    }
}

int empty_prescription(icu* ICU,int patient_ID)
{

    int icu_num;

    int patient_num;

    icu_num = find_icu_number_using_id(&ICU[0],patient_ID);

    patient_num = find_patient_number_using_id(&ICU[0], patient_ID);

    if (ICU[icu_num].q.item[patient_num].p_s.top == -1)

        return 1;

    else

        return 0;

}

int  find_patient_number_using_id(icu* ICU, int patient_id)
{
    int icu_num;
    icu_num = find_icu_number_using_id(&ICU[0], patient_id);
    for (int i = 0; i < 10; i++)
        if ( ICU[icu_num].q.item[i].patient_ID == patient_id) {
            return i;
            break;
        }
}


