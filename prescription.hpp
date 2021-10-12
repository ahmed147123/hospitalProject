
int check_doctor_name(doctor_stack d_s,string d_name){

while (d_s.top>=0){

      if(d_s.DOCTOR[d_s.top].name==d_name)
        {
        return 1;
      break;
        }
        else
            d_s.top=d_s.top-1;

}
return 0;
}

int find_icu_number(icu *ICU,string p_name){
 for (int i=0;i<3;i++)
      for (int ii=0;ii<10;ii++)
      if(ICU[i].q.item[ii].name==p_name)
        {
        return i;
      break;
        }
    }

  void  display_prescription(icu *ICU){

    cout <<" pateint name :";
    string p_name ;
    cin >>p_name ;
      while (!check_pateint_name(&ICU[0],p_name)){
        cout <<"the pateint name isnt exist in he hospital enter another name"<<endl;
        cin>>p_name;
      }
        int icu_num;
        int pateint_num;
        icu_num=find_icu_number(&ICU[0],p_name);
        pateint_num =find_pateint_number(&ICU[0],p_name);

        if( empty_prescription(&ICU[0],p_name)){
        cout<<"no aprescription witeen yet"<<endl;
       }
       else {

       cout <<"there is "<<ICU[icu_num].q.item[pateint_num].p_s.top<<"witten"<<endl;
       while(ICU[icu_num].q.item[pateint_num].p_s.top>=0){
            cout <<"**********************"<<endl;

      cout<<"prescription code:"       << ICU[icu_num].q.item[pateint_num].p_s.pricript[ICU[icu_num].q.item[pateint_num].p_s.top].precriptiont_code<<endl;

      cout<<"prescription writen to:"  << ICU[icu_num].q.item[pateint_num].p_s.pricript[ICU[icu_num].q.item[pateint_num].p_s.top].pateint_name<<endl;

      cout<<"prescription writen from:"<< ICU[icu_num].q.item[pateint_num].p_s.pricript[ICU[icu_num].q.item[pateint_num].p_s.top].doctor_name<<endl;

      cout<<"prescription_text:"       << ICU[icu_num].q.item[pateint_num].p_s.pricript[ICU[icu_num].q.item[pateint_num].p_s.top].prescript_text<<endl;
      ICU[icu_num].q.item[pateint_num].p_s.top=ICU[icu_num].q.item[pateint_num].p_s.top-1;
       }
       }
    }

    int empty_prescription(icu *ICU,string p_name){

        int icu_num;

        int pateint_num;

        icu_num=find_icu_number(&ICU[0],p_name);

        pateint_num =find_pateint_number(&ICU[0],p_name);

         if (ICU[icu_num].q.item[pateint_num].p_s.top==-1)

         return 1;

         else

        return 0;

    }


    int  find_pateint_number(icu *ICU,string p_name){
       int icu_num;
         icu_num=find_icu_number(&ICU[0],p_name);
     for (int i=0;i<10;i++)
     if (i=ICU[icu_num].q.item[i].name==p_name){
        return i;
        break ;
     }
   }
