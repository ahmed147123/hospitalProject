#include <iostream>
#include<string>

using namespace std;


struct prescription_data {
string pateint_name ;
string doctor_name;
int precriptiont_code;
string prescript_text;

};

struct prescription {
int top=-1;
prescription_data  pricript[3];
};

struct doctor {
string name;
string sex;
int birth_date;
int social_security_number;
string scientific_area ;
string  degree ;
int doctor_id;

};

struct doctor_stack {

int top=-1;
doctor DOCTOR[20];

}d_s;


struct  pateint {
int pateint_ID;
string  name ;
string sex ;
int pateint_phone;
string address;
int birth_date;
string medical_histroy;
string allegry ;
int systolic_blood_pressure;
int distolic_blood_pressure;
int heart_rate;
double tempreture;
prescription p_s;
string date ;

};
struct queue{
int rear=0,fronte=0;
pateint item[10];

}q;

struct icu {
string icu_name ;
int  icu_code;
string icu_manager_name;
int icu_beds_number;
queue q;
};

icu ICU[3];



            void enqueue(icu *,int,int,string,string,int,string,int,string,string,int,int,int,double);  //تسجيل مريض في وحد عنايه مركزه
            void dequeue(icu *,int);//اخراج مريض من وحده العنايه
            int  isfull(icu *,int);//اختبار هل وحده العنايه ممتلئه
            int  isempty(icu *,int );//الاختبار هل وحده العنايه فارغه
            void display(icu *,int);//عرض المرضي الموجودين في وحده عنايه محدده
            int  check_id(icu *,int,int);//اختبار لمعرفه تكرار الا الكود الخاص بالمريض متكرر ام لا
            void display_ICU_information(icu *,int);//فنكشن لعرض معلومات وحده العنايه المركزه
            void add_new_doctor(doctor_stack &,int );//اضافه مرض
            int  check_d_s_isempty(doctor_stack );//اختبار اذا كانت المستشفي بها مرضي ام لا
            void display_d_with_id(doctor_stack ,int );//عرض معلومات الداتره عن طريق ال الاي دي
            int  check_d_id(doctor_stack,int);//اختبار الاي دي موجود ام لا
            void display_prescription (icu *);//عرض الروشته
            void write_prescription(icu *,doctor_stack &);//كتابه روشته
            int  check_pateint_name(icu *,string);//معرفه اذاكان المريض في المستشفي ام لا
            int  check_doctor_name(doctor_stack,string);//معرفه اذا كان الدكتور في المستشفي ام لا
            int  find_icu_number(icu *,string);//ايجاد رقم العانيه الموجود بها مريض معين عن طريق اسم المريض
            int  find_pateint_number(icu *,string);//ايجاد رقم المريض
            int  empty_prescription(icu *,string);// اختبار ما اذان كانت لاتوجد روشته مكتوبه للمريض
  int icu_num;
   int pateint_num;
int main()
{

    q.fronte=0;
    q.rear=0;

int choise ,elements,choise0,icu_number,choise2,numer_of_doctor,icu_nom, choise3;
int patient_ID;
string  name ;
string sex ;
int pateint_phone;
string address;
int birth_date;
string medical_histroy;
string allegry ;
int systolic_blood_pressure;
int distolic_blood_pressure;
int heart_rate;
double tempreture;
string date;

    cout <<"1-icu and its pateint track"<<endl;
    cout <<"2-doctors traclk track"<<endl;
    cout <<"3-prescription of pateints"<<endl;
    cout <<"4-exit from the programe"<<endl;
    cout <<"please chose one choise "<<endl;
    cin>>choise0;
    while (choise0!=4){
     if (choise0==1){                                    // start track 1
    choise=6;
    while (choise==6){
    cout <<"chose the ICU you want"<<endl;
    cout <<"1-ICU number 1 "<<endl;
    cout <<"2-ICU number 2 "<<endl;
    cout <<"3-ICU number 3 "<<endl;
    cin>>icu_number;                         //اختيار رقم الالوحده
    while(icu_number!=1&&icu_number!=2&&icu_number!=3){                    //هذا الاخبار لضمان اخيار الامسخدم واحده من الوحدات الثلاثه

        cout <<"there is no ICU with number" <<icu_number<<"please chose ICU 1 or 2 or 3"<<endl;
        cin>>icu_number;
    }

    cout <<"1- enqueue an patient in the ICU number"<<icu_number<<endl;
    cout <<"2- dequeue an patient from the ICU number"<<icu_number<<endl;
    cout <<"3- display all patients data in the ICU number "<<icu_number<<endl;
    cout <<"4- display the data of ICU number"<<icu_number<<endl;
    cout <<"5- exist from this track an chose another one "<<endl;
    cout <<"6- choose another ICU"<<endl;
    cout <<"please choose one of this element  "<<endl;
    cin >>choise;

         }
    while(choise!=5){
        if (choise==1){

            cout <<"what the number of patient you want to enqueue"<<endl;
            cin>>elements;
            for (int i=1;i<=elements;i++){
                cout <<"please enter the data of patient "<<i<<endl<<"*****"<<endl;
                cout<<"patient ID:";
                cin>>patient_ID;
                while (check_id(&ICU[0],icu_number,patient_ID)){
                     cout <<"the id is existed please enter another ID"<<endl;
                      cout<<"patient ID:";
                cin>>patient_ID;

                }

                cout<<endl<<"name:";
                cin>>name;
                  cout<<endl<<"sex:";
                cin>>sex;
                  cout<<endl<<"phone:";
                cin>>pateint_phone;
                 cout<<endl<<"adress:";
                cin>>address;
                  cout<<endl<<"birthdate:";
                cin>>birth_date;
                  cout<<endl<<"medical hotory:";
                cin>>medical_histroy;
                 cout<<endl<<"allgry:";
                cin>>allegry;
                  cout<<endl<<"systolic_blood_pressure:";
                cin>>systolic_blood_pressure;
                cout<<endl<<"distolic_blood_pressure:";
                cin>>distolic_blood_pressure;
                cout<<endl<<"heart_rate:";
                cin>>heart_rate;
                cout<<endl<<"tempreture:";
                cin>>tempreture;

                enqueue(
&ICU[0],
icu_number,
patient_ID,
name,
sex ,
pateint_phone,
 address,
birth_date,
 medical_histroy,
 allegry ,
 systolic_blood_pressure,
 distolic_blood_pressure,
 heart_rate,
 tempreture
 );
            }

        }

        if (choise==2){

             if (isempty(&ICU[0],icu_number)){
cout<<"the ICU number"<<icu_number<<" is empty"<<endl;
}
            else {
            cout <<"whate is the number you wante to dequeue"<<endl;
            cin >>elements;
            while (elements>(ICU[icu_number].q.fronte-ICU[icu_number].q.rear)){
                cout <<"ther are "<<ICU[icu_number].q.rear-ICU[icu_number].q.fronte<<" elements only "<<endl;
            cout <<"please enter number less than or equal: "<<ICU[icu_number].q.rear-ICU[icu_number].q.fronte<<endl;
            cin >>elements;
            }
            for (int i=1;i<=elements;i++){
                dequeue(&ICU[0],icu_number);
            }
            }
        }

        if (choise ==3){
            display(&ICU[0],icu_number);
        }

        if (choise==4){

            display_ICU_information(&ICU[0],icu_number);
        }
          cout <<endl<<"choose another  one   "<<endl;
                cin>>choise;

    }



    cout <<"1-icu and its pateint track"<<endl;
    cout <<"2-doctors traclk track"<<endl;
    cout <<"3-write a prescrition to pateints"<<endl;
    cout <<"4-exit from the programe"<<endl;
    cout <<"please chose one choise "<<endl;
    cin>>choise0;

    }                                                      //end track 1

    if (choise0==2){                                     ///////////start track 2222222222222222


        cout <<"1-add new doctor"<<endl;
        cout <<"2-display specific doctor information with id "<<endl;
        cout <<"3-get back and choose another track"<<endl;
        cin >>choise2;
        while (choise2!=3){
            if (choise2==1){

                    cout <<"whate is the number you want to add"<<endl;
            cin>>numer_of_doctor;
            for (int i=1;i<=numer_of_doctor;i++){
             add_new_doctor(d_s,i);

            }

            }
            else if (choise2=2){

                if (check_d_s_isempty(d_s)){

        cout<<"there is  no doctor in the hospiatal"<<endl;

            }
                else{
                    cout <<"please  enter the the id of doctor you want to display"<<endl;
                    cout <<"ID:";
                    int d_id;      //d_id اختصار ل الاي دي الخاص بالدكتور
                    cin>>d_id;

                    while(check_d_id(d_s,d_id)){
                        cout <<"the id" <<d_id<<" isnt exsited please enter anothe one"<<endl;
                        cout <<"ID:";
                        cin>>d_id;

                    }

                    display_d_with_id(d_s,d_id);

                    }

        }

        cout <<"choose another choise"<<endl;
        cin >>choise2;
        }

    cout <<"1-icu and its pateint track"<<endl;
    cout <<"2-doctors traclk track"<<endl;
    cout <<"3-prescription of pateints track"<<endl;
    cout <<"4-exit from the programe"<<endl;
    cout <<"please chose one choise "<<endl;
    cin>>choise0;                                                               //end track 2
    }
    if (choise0==3){                                                               //////start  TRACK NUMBER 3
        cout <<"1-write aprescrition"<<endl;
        cout <<"2-display a pateint prescrption"<<endl;
        cout <<"3-get back and choose another track"<<endl;
        cin>>choise3;
        while(choise3==1){
        if (isempty(&ICU[0],0)&&isempty(&ICU[0],1)&&isempty(&ICU[0],2)){    //السطر ده بيختبر هل المستشفي فاضيه ولا فيها مرضي تم تسجلهم
        cout <<"there is no pateint recorded in the system"<<endl;
        cout <<"please chose the the track of ice and patient and record patient"<<endl;
        cout <<"1-write a aprescrition"<<endl;
        cout <<"2-display a pateint prescrption"<<endl;
        cout <<"3-get back and choose another track"<<endl;
        cin>>choise3;
        }
        else if (d_s.top==-1){      // السطر ده بيخبر هل في داكتره تم تسجلم ام لا
        cout <<"there is no doctores recorder in the system "<<endl;
        cout <<"please go to the track of doctor and add doctores in the syatem"<<endl;
        cout <<"1-write a prescrition"<<endl;
        cout <<"2-display a pateint prescrption"<<endl;
        cout <<"3-get back and choose another track"<<endl;
        cin>>choise3;
        }
        else {
                write_prescription(&ICU[0],d_s);
        cout <<"1-write another  aprescrition"<<endl;
        cout <<"2-display a pateint prescrption"<<endl;
        cout <<"3-get back and choose another track"<<endl;
        cin>>choise3;
        }
        }
        while(choise3==2){
           if (isempty(&ICU[0],0)&&isempty(&ICU[0],1)&&isempty(&ICU[0],2)){
        cout <<"there is no pateint recorded in the system"<<endl;
        cout <<"please chose the the track of ice and patient and record patient"<<endl;
        cout <<"1-write a aprescrition"<<endl;
        cout <<"2-display a pateint prescrption"<<endl;
        cout <<"3-get back and choose another track"<<endl;
        cin>>choise3;
        }
        else if (d_s.top==-1){
        cout <<"there is no doctores recorder in the system "<<endl;
        cout <<"please go to the track of doctor and add doctores in the syatem"<<endl;
        cout <<"1-write a prescrition"<<endl;
        cout <<"2-display a pateint prescrption"<<endl;
        cout <<"3-get back and choose another track"<<endl;
        cin>>choise3;
        }
        else {

        display_prescription(&ICU[0]);
        cout <<"************"<<endl;
        cout <<"1-write aprescrition"<<endl;
        cout <<"2-display another pateint prescrption"<<endl;
        cout <<"3-get back and choose another track"<<endl;
        cin>>choise3;
        }
        }
            if (choise3==3){
    cout <<"1-icu and its pateint track"<<endl;
    cout <<"2-doctors traclk track"<<endl;
    cout <<"3-prescription of pateints"<<endl;
    cout <<"4-exit from the programe"<<endl;
    cout <<"please chose one choise "<<endl;
    cin>>choise0;                                                  //end track 3
    }
    }
    }

    return 0;
                                                                   //END OF THE PROGRAME
}

            void enqueue(
icu *ICU,
int icu_number,
int pateint_ID,
string  name ,
string sex ,
int pateint_phone,
string address,
int birth_date,
string medical_histroy,
string allegry ,
int systolic_blood_pressure,
int distolic_blood_pressure,
int heart_rate,
double tempreture)
{
            if (isfull(&ICU[0],icu_number ))
                cout<<"the queue is full"<<endl;
            else {
            ICU[icu_number].q.item[q.rear].pateint_ID=pateint_ID;
            ICU[icu_number].q.item[q.rear].name= name;
            ICU[icu_number].q.item[q.rear].address=address;
            ICU[icu_number].q.item[q.rear].allegry=allegry;
            ICU[icu_number].q.item[q.rear].birth_date=birth_date;
            ICU[icu_number].q.item[q.rear].distolic_blood_pressure=distolic_blood_pressure;
            ICU[icu_number].q.item[q.rear].heart_rate=heart_rate;
            ICU[icu_number].q.item[q.rear].medical_histroy=medical_histroy;
            ICU[icu_number].q.item[q.rear].pateint_phone=pateint_phone;
            ICU[icu_number].q.item[q.rear].sex=sex;
            ICU[icu_number].q.item[q.rear].systolic_blood_pressure=systolic_blood_pressure;
            ICU[icu_number].q.item[q.rear].tempreture=tempreture;
            ICU[icu_number].q.rear=ICU[icu_number].q.rear+1;
            }

            }
void dequeue(icu *ICU,int icu_number){



ICU[icu_number].q.fronte=ICU[icu_number].q.fronte+1;

}

int isempty(icu *ICU,int icu_number){
if (ICU[icu_number].q.fronte==ICU[icu_number].q.rear)
return 1;
else
return 0;
}
int isfull(icu *ICU,int icu_number){

if (ICU[icu_number].q.rear==9){
return 1;
}
else
return 0;
}
void display(icu *ICU,int icu_number){

for(int i=ICU[icu_number].q.fronte;i!=ICU[icu_number].q.rear;i++){
cout <<"patient_ID:"<<ICU[icu_number].q.item[q.fronte].pateint_ID<<endl;
cout <<"name:"<<ICU[icu_number].q.item[q.fronte].name<<endl;
cout <<"sex:"<<ICU[icu_number].q.item[q.fronte].sex<<endl;
cout <<"birth date:"<<ICU[icu_number].q.item[q.fronte].birth_date<<endl;
cout <<"phone:0"<<ICU[icu_number].q.item[q.fronte].pateint_phone<<endl;
cout <<"adress:"<<ICU[icu_number].q.item[q.fronte].address<<endl;
cout <<"sex:"<<ICU[icu_number].q.item[q.fronte].sex<<endl;
cout <<"tempreture:"<<ICU[icu_number].q.item[q.fronte].tempreture<<endl;
cout <<"presure:"<<ICU[icu_number].q.item[q.fronte].systolic_blood_pressure<<"/"<<q.item[q.fronte].distolic_blood_pressure<<endl;
cout <<"heart reate:"<<ICU[icu_number].q.item[q.fronte].heart_rate<<endl;
cout <<"medical history:"<<ICU[icu_number].q.item[q.fronte].medical_histroy<<endl;
cout <<"allegry:"<<ICU[icu_number].q.item[q.fronte].allegry<<endl;
cout <<"**************"<<endl;

}
}
    int check_id(icu *ICU,int icu_number,int patient_ID){
if (ICU[icu_number].q.rear==0)
return 0;
else{
for(int i=ICU[icu_number].q.fronte;i<ICU[icu_number].q.rear;i++){
if (ICU[icu_number].q.item[i].pateint_ID==patient_ID)
return 1;
else
return 0;
}
}
}
void display_ICU_information(icu *ICU ,int icu_number){


    if (icu_number==1){
    cout<<"ICU name:NICU"<<endl;
    cout<<"ICU code:111"<<endl;
    cout<<"ICU beds number:100"<<endl;
    cout<<"ICU manager:saeed khaleed"<<endl;
    }
    else if(icu_number==2){

    cout<<"ICU name:PJDB"<<endl;
    cout<<"ICU code:555"<<endl;
    cout<<"ICU beds number:50"<<endl;
    cout<<"ICU manager:haytham emad"<<endl;
             }
    else if(icu_number==3){
    cout<<"ICU name:DYUS"<<endl;
    cout<<"ICU code:222"<<endl;
    cout<<"ICU beds number:30"<<endl;
    cout<<"ICU manager:mahmoud el behady"<<endl;
    }
    }

     void  add_new_doctor(doctor_stack &d_s,int i){

        cout <<"please enter the data of the doctor number"<<i<<endl<<"********";
        d_s.top=d_s.top+1;
        cout <<endl<<"doctor code:";
        int doctor_id;
        cin >>doctor_id ;
       d_s.DOCTOR[d_s.top].doctor_id=doctor_id;

        cout <<endl<<"doctor name:";
        string doctor_name;
        cin >>doctor_name ;
        d_s.DOCTOR[d_s.top].name=doctor_name;

        cout <<endl<<"doctor sex:";
        string doctor_sex ;
        cin >> doctor_sex ;
        d_s.DOCTOR[d_s.top].sex=doctor_sex;

        cout <<endl<<"doctor birth date:";
        int doctor_birth_date ;
        cin >>doctor_birth_date ;
        d_s.DOCTOR[d_s.top].birth_date=doctor_birth_date;

        cout <<endl<<"doctor social security number:";
        int social_security_number ;
        cin >> social_security_number ;
        d_s.DOCTOR[d_s.top].social_security_number=social_security_number;

        cout <<endl<<"doctor scientific area:";
        string scientific_area ;
        cin >>  scientific_area ;
        d_s.DOCTOR[d_s.top].scientific_area=scientific_area;

        cout <<endl<<"doctor degree:";
        string degree ;
        cin >> degree ;
        d_s.DOCTOR[d_s.top].degree=degree;

    }

     void display_d_with_id(doctor_stack d_s,int d_id){

                while (d_s.top>=0){
                    if (d_s.DOCTOR[d_s.top].doctor_id==d_id){
                    cout <<"the information of doctor with id:"<<d_id<<"is"<<endl;
                    cout <<"doctor name:"<<d_s.DOCTOR[d_s.top].name<<endl;
                    cout <<"doctor sex:"<<d_s.DOCTOR[d_s.top].sex<<endl;
                    cout <<"doctor birth date:"<<d_s.DOCTOR[d_s.top].birth_date<<endl;
                    cout <<"doctor social security number:"<<d_s.DOCTOR[d_s.top].social_security_number<<endl;
                    cout <<"doctor scientific area:"<<d_s.DOCTOR[d_s.top].scientific_area<<endl;
                    cout <<"doctor degree:"<<d_s.DOCTOR[d_s.top].degree<<endl;
                    break ;
                    }

                    d_s.top=d_s.top-1;
                    }
                    }

      int check_d_s_isempty(doctor_stack d_s){
     if (d_s.top==-1){
        return 1;
     }
     else
        return 0;
     }

     int check_d_id(doctor_stack d_s,int d_id){


         while(d_s.top>=0){
             if (d_s.DOCTOR[d_s.top].doctor_id==d_id){

                return 0;
                break ;
             }
             d_s.top=d_s.top-1;

         }

return 1;
     }

void write_prescription(icu *ICU, doctor_stack &d_s){

    cout <<" pateint name :";
    string p_name ;
    cin >>p_name ;
      while (!check_pateint_name(&ICU[0],p_name)){
        cout <<"the pateint name isnt exist in he hospital enter another name"<<endl;
        cout <<" pateint name :";
        cin>>p_name;
      }

    cout <<" prescription code :";
    int pr_code;
    cin >>pr_code ;

    cout <<" doctor name:";
    string d_name;
    cin>>d_name;
    while (!check_doctor_name(d_s,d_name)){
        cout <<"the doctor name isnt exist in he hospital enter another name"<<endl;
        cout <<" doctor name:";
        string d_name;
        cin>>p_name;
      }
     cout <<"please write your prescription"<<endl;
     string p_prescription;
     cin >>p_prescription;

   icu_num=find_icu_number(&ICU[0],p_name);
   pateint_num =find_pateint_number(&ICU[0],p_name);

     ICU[icu_num].q.item[pateint_num].p_s.top=ICU[icu_num].q.item[pateint_num].p_s.top+1 ; /////item1 for pateint number
     ICU[icu_num].q.item[pateint_num].p_s.pricript[ ICU[icu_num].q.item[pateint_num].p_s.top].pateint_name=p_name;                              ///// item2 for prescription
     ICU[icu_num].q.item[pateint_num].p_s.pricript[ ICU[icu_num].q.item[pateint_num].p_s.top].doctor_name=d_name;
     ICU[icu_num].q.item[pateint_num].p_s.pricript[ ICU[icu_num].q.item[pateint_num].p_s.top].precriptiont_code=pr_code;
     ICU[icu_num].q.item[pateint_num].p_s.pricript[ ICU[icu_num].q.item[pateint_num].p_s.top].prescript_text=p_prescription;

}

int check_pateint_name(icu *ICU,string p_name){

     for (int i=0;i<3;i++){

     for(int ii=0;ii<10;ii++){

     if(ICU[i].q.item[ii].name==p_name)
        {
        return 1;
      break;
        }
     }
     }
        return 0;

}

#include "prescription.hpp"




















