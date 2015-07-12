#include<iostream>
using namespace std;
void viewDetails(int id,int is_emp);
void editDetails(int id,int is_emp);
void createCustomer();
void deleteNode(int id,int is_emp);
int d1,d2,new_dob,new_phone,new_email,login_count;
void newLine()
{
    cout<<endl<<endl;
    for(int i=0;i<204;i++)
        cout<<"-";
    cout<<endl<<endl;
}
void halfline()
{
    for(int i=0;i<80;i++)
        cout<<" ";
}
void halflineempty()
{
    for(int i=0;i<40;i++)
        cout<<" ";
}
struct employee
{
        int emp_id;
        string emp_name;
        string emp_tpin;
        string dob;
        long int phone;
        string email;
        int is_locked;
        struct employee *next;
}*e_head=0;
struct customer
{
        int cust_id;
        string cust_name;
        string cust_tpin;
        string dob;
        int phone;
        string email;
        int is_locked;
        int age;
        int is_minor;
        struct customer *next;
}*c_head;
int main()
{
        struct employee *new_emp,*current;
        int cntnu;
        do
        {
                new_emp=new employee;
                cout<<"emp name:";
                cin>>new_emp->emp_name;
                cout<<"emp id:";
                cin>>new_emp->emp_id;
                cout<<"emp tpin:";
                cin>>new_emp->emp_tpin;
                cout<<"dob:";
                cin>>new_emp->dob;
                cout<<"phone:";
                cin>>new_emp->phone;
                cout<<"email:";
                cin>>new_emp->email;
                new_emp->is_locked=0;
                new_emp->next=0;
                if(e_head==0)
                {
                    e_head=new_emp;
                    current=new_emp;
                }
                else
                {
                    current->next=new_emp;
                    current=new_emp;
                }
                cout<<"continue creating employee..(1:yes / 2:no)";
                cin>>cntnu;
        }while(cntnu==1);
//starts here...
    newLine();
    halfline();
    cout<<"   welcome to sahara banking";
    halfline();
    cout<<endl;
    halfline();
    cout<<"smart banking for smart people ";
    halfline();
    newLine();
    int ch,ch1,ch2,ch3,ch4,ch5,age,accntnum,amt,def_pswd,e_id,c_id,m_num,acc_num2,amt2,m_amt,w_amt,b_amt,b_no,m_no,w_no,ch6,cust_id1,ch7,cust_id2,ch8,ch9,emp_id10,emp_tpin10,cust_id10,cust_tpin10,cust_id11;
    string name,e_pwd,c_pwd;
    wrong_option:
    do
    {
    halflineempty();
    cout<<"enter your choice\n";
    cout<<" \t\t\t\t\t1.Employee\n\t\t\t\t\t2.customer\n\t\t\t\t\t3.Logout\n";
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"welcome to employee section\n";
            cout<<"enter login id\n";
            cin>>emp_id10;
            cout<<"enter the pswd\n";
            cin>>emp_tpin10;
            //login validation...
            //login count...
            //is_locked...
            do
            {
            cout<<"enter ur choice\n";
            cout<<"1.view details\n2.edit details\n3.create customer\n4.delete customer\n";
            cin>>ch1;
            switch(ch1)
            {
                case 1:
                    do
                    {
                    cout<<"1.view your details\n2.other employee details\n3.customer details\n";
                    cin>>ch6;
                        switch(ch6)
                        {
                        case 1:
                            viewDetails(emp_id10,1);
                            cout<<"continue(1:yes / 2:no)";
                            cin>>cntnu;
                            break;
                        case 2:
                            cout<<"enter the employee id..";
                            cin>>e_id;
                            viewDetails(e_id,1);
                                cout<<"continue(1:yes / 2:no)";
                                cin>>cntnu;
                            break;
                        case 3:
                            cout<<"enter the customer id..";
                            cin>>cust_id1;
                            viewDetails(cust_id10,0);
                                cout<<"continue(1:yes / 2:no)";
                                cin>>cntnu;
                            break;
                        default:
                            cout<<"enter valid option..";
                            goto wrong_option;
                        }
                    }while(cntnu==1);
                    cout<<"continue(1:yes / 2:no)";
                    cin>>cntnu;
                break;
                case 2:
                    do
                    {
                    cout<<"1.edit your details\n2.edit customer details\n";
                    cin>>ch7;
                        switch(ch7)
                        {
                        case 1:
                            editDetails(emp_id10,1);
                                cout<<"continue(1:yes / 2:no)";
                                cin>>cntnu;
                            break;
                        case 2:
                            cout<<"enter customer id..";
                            cin>>cust_id2;
                            editDetails(cust_id2,0);
                                cout<<"continue(1:yes / 2:no)";
                                cin>>cntnu;
                            break;
                        case 3:
                            createCustomer();
                            break;
                        case 4:
                            cout<<"enter employee id..";
                            cin>>ch8;
                            deleteNode(ch8,0);
                                cout<<"continue(1:yes / 2:no)";
                                cin>>cntnu;
                            break;
                        default:
                            cout<<"invalid input\n";
                            goto wrong_option;
                        }
                    }while(cntnu==1);
                    cout<<"continue(1:yes / 2:no)";
                    cin>>cntnu;
                    break;
                case 3:
                    createCustomer();
                    cout<<"continue(1:yes / 2:no)";
                    cin>>cntnu;
                    break;
                case 4:
                    cout<<"enter customer id..";
                    cin>>cust_id11;
                    deleteNode(cust_id11,0);
                    cout<<"continue(1:yes / 2:no)";
                    cin>>cntnu;
                    break;
                default:
                    cout<<"invalid option..";
                    goto wrong_option;
            }
            }while(cntnu==1);
            cout<<"continue(1:yes / 2:no)";
            cin>>cntnu;
            break;
        case 2:
                cout<<"welcome to customer section\n";
                cout<<"loginid\n";
                cin>>cust_id10;
                cout<<"enter pswd\n";
                cin>>cust_tpin10;
            do
            {
                cout<<"enter ur choice\n";
                cout<<"1.view profile\n2.edit profile\n3.money transfer\n4.paybill\n5.view balance\n";
                cin>>ch2;
                    switch(ch2)
                    {
                    case 1:
                        viewDetails(cust_id10,0);
                            cout<<"continue(1:yes / 2:no)";
                            cin>>cntnu;
                        break;
                    case 2:
                        editDetails(cust_id10,0);
                            cout<<"continue(1:yes / 2:no)";
                            cin>>cntnu;
                        break;
                    case 3:
                        cout<<"enter accnt number\n";
                        cin>>acc_num2;
                        cout<<"enter amount\n";
                        cin>>amt2;
                        cout<<"enter your choice\n";
                        cout<<"1.send\n 2. cancel\n";
                        cin>>ch3;
                        switch(ch3)
                        {
                            case 1:
                                cout<<"sucessfully send\n";
                                amt=amt-amt2;
                                cout<<"current bal is="<<amt;
                                break;
                            case 2:cout<<"sending failed\n";
                                break;
                                default:cout<<"invalid input\n";
                                goto wrong_option;
                        }
                            cout<<"continue(1:yes / 2:no)";
                            cin>>cntnu;
                        break;
                    case 4:
                        cout<<"paybill";
                        cout<<" enter your choice\n 1.electric bill \n2. water bill\n 3. mobile bill \n ";
                        switch(ch4)
                        {
                            case 1:
                                cout<<"enter electric bill nco\n";
                                cin>>b_no;
                                cout<<" enter bill amt";
                                cin>>b_amt;
                                cout<<"bill paid sucessfully\n";
                                amt= amt - b_amt;
                                cout<<"amt=\n"<<amt;
                                break;
                            case 2:
                                cout<<"enter water bill no";
                                cin>>w_no;
                                cout<<" enter bill amt";
                                cin>>w_amt;
                                cout<<"bill paid sucessfully\n";
                                amt= amt - w_amt;
                                cout<<"amt\n";
                                break;
                            case 3:
                                cout<<"enter mobile bill no\n";
                                cin>>m_no;
                                cout<<" enter bill amt\n";
                                cin>>m_amt;
                                cout<<"bill paid sucessfully\n";
                                amt= amt - m_amt;
                                cout<<"amt\n";
                                break;
                            default:
                                cout<<"invalid input\n";
                                break;
                        }
                            cout<<"continue(1:yes / 2:no)";
                            cin>>cntnu;
                            break;
                    case 5:
                        cout<<"your balance is ="<<amt;
                            cout<<"continue(1:yes / 2:no)";
                            cin>>cntnu;
                        break;
                    default:cout<<"invalid input\n";
                        goto wrong_option;
                    }
                }while(cntnu==1);
            cout<<"continue(1:yes / 2:no)";
            cin>>cntnu;
            break;
        case 3:
            //logout code....
        default:cout<<"invalid input\n";
        goto wrong_option;
    }
    }while(cntnu==1);
//ends here...
        return 0;
}
void viewDetails(int id,int is_emp)
{
    if(is_emp==1)
    {
        struct employee *e_check;
        e_check=e_head;
        while(e_check!=NULL)
        {
            if(e_check->emp_id==id)
            {
                cout<<"emp name:"<<e_check->emp_name;
                cout<<"emp id:"<<e_check->emp_id;
                cout<<"dob:"<<e_check->dob;
                cout<<"phone:"<<e_check->phone;
                cout<<"email"<<e_check->email;
            }
            e_check=e_check->next;
        }
    }
    else
    {
        struct customer *c_check;
        c_check=c_head;
        while(c_check!=NULL)
        {
            if(c_check->cust_id==id)
            {
                cout<<"cust name:"<<c_check->cust_name;
                cout<<"cust id:"<<c_check->cust_id;
                cout<<"dob:"<<c_check->dob;
                cout<<"phone:"<<c_check->phone;
                cout<<"email"<<c_check->email;
            }
            c_check=c_check->next;
        }
    }
    return;
}
void editDetails(int id,int is_emp)
{
    if(is_emp==1)
    {
        struct employee *e_check;
        e_check=e_head;
        while(e_check!=NULL)
        {
            if(e_check->emp_id==id)
            {
                cout<<"\nselect the detail to be edited..\n1.dob\n2.phone:\n3.email\n";
                cin>>d1;
                switch (d1)
                {
                    case 1:
                        cout<<"enter the new value..";
                        cin>>new_dob;
                        e_check->dob=new_dob;
                        break;
                    case 2:
                        cout<<"enter the new value..";
                        cin>>new_phone;
                        e_check->phone=new_phone;
                        break;
                    case 3:
                        cout<<"enter the new value..";
                        cin>>new_email;
                        e_check->email=new_email;
                        break;
                        
                    default:
                        cout<<"enter corrcet option";
                        break;
                }
            }
            e_check=e_check->next;
        }
    }
    else
    {
        struct customer *c_check;
        c_check=c_head;
        while(c_check!=NULL)
        {
            if(c_check->cust_id==id)
            {
                cout<<"\nselect the detail to be edited..\n1.dob\n2.phone:\n3.email\n";
                cin>>d2;
                switch (d2)
                {
                    case 1:
                        cout<<"enter the new value..";
                        cin>>new_dob;
                        c_check->dob=new_dob;
                        break;
                    case 2:
                        cout<<"enter the new value..";
                        cin>>new_phone;
                        c_check->phone=new_phone;
                        break;
                    case 3:
                        cout<<"enter the new value..";
                        cin>>new_email;
                        c_check->email=new_email;
                        break;
                        
                    default:
                        cout<<"enter corrcet option";
                        break;
                }
            }
            c_check=c_check->next;
        }
    }
    return;
}
void createCustomer()
{
    struct customer *new_cust,*current_cust;
    new_cust=new customer;
    cout<<"enter the following details..";
    cout<<"cust name:";
    cin>>new_cust->cust_name;
    cout<<"cust id:";
    cin>>new_cust->cust_id;
    cout<<"cust tpin:";
    cin>>new_cust->cust_tpin;
    cout<<"dob:";
    cin>>new_cust->dob;
    cout<<"enter age:";
    cin>>new_cust->age;
    cout<<"phone:";
    cin>>new_cust->phone;
    cout<<"email";
    cin>>new_cust->email;
    new_cust->is_locked=0;
    if(new_cust->age < 18)
    {
        new_cust->is_minor=1;
    }
    else
    {
        new_cust->is_minor=0;
    }
    new_cust->next=0;
    if(c_head==0)
    {
        c_head=new_cust;
        current_cust=new_cust;
    }
    else
    {
        current_cust->next=new_cust;
        current_cust=new_cust;
    }
    return;
}
void deleteNode(int id,int is_emp)
{
    if(is_emp==1)
    {
        struct employee *e_check;
        e_check=e_head;
        while(e_check->next!=NULL)
        {
            if(e_check->next->emp_id==id)
            {
                e_check->next=e_check->next->next;
                delete(e_check->next);
            }
            e_check=e_check->next;
        }
    }
    else
    {
        struct customer *c_check;
        c_check=c_head;
        while(c_check->next!=NULL)
        {
            if(c_check->next->cust_id==id)
            {
                c_check->next=c_check->next->next;
                delete(c_check->next);
            }
            c_check=c_check->next;
        }
    }
    return;
}














