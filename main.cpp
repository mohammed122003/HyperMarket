#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "HyperMarketSystem.h"
using namespace std;

int main()
{
    int ch;
    HyperMarketSystem H;
    int D_count=0;
    Department* depart=new Department[10];
    cout << "\n\t\tWelcome to Hyper System Market !" << endl;
    do{
    cout<<"\n\n1- Employee"<<"\n2- Product "<<"\n3- Department"<<"\n4-Assignment Department to Emp";
    cout<<"\n>>> "; cin>>ch;
    switch(ch)
    {

    case 1:
        cout<<"\n1- Add Employee"<<"\n2- Edit Employee"<<"\n3- Find Employee"<<"\n4- Delete Employee"<<"\n5- Show Employees"<<"\n00- Back"<<"\n0- Exit "<<endl;
        //int EmpCh;
        cout<<"\n>>> ";cin>>ch;
        switch(ch)
        {
        case 1:
            H.addEmployee();
            break;
        case 2:
            H.EditEmployee();
            break;
        case 3:
            H.findEmployee();
            break;
        case 4:
            H.DeleteEmployee();
            break;
        case 5:
            H.showEmployees();
            break;
        }
        system("pause");
        system("cls");
        break;
    case 2:
        cout<<"\n1- Add Product"<<"\n2- Edit Product"<<"\n3- Find Product"<<"\n4- Delete Product"<<"\n5- Show Product"<<"\n00- Back "<<"\n0- Exit"<<endl;
        //int ProdCh;
        cout<<"\n>>> ";cin>>ch;
        switch(ch)
        {
        case 1:
            H.addProduct();
            break;
        case 2:
            H.EditProduct();
            break;
        case 3:
            H.SearchProduct();
            break;
        case 4:
            H.DeleteProduct();
            break;
        case 5:
            H.ShowProduct();
            break;
        }
        system("pause");
        system("cls");
        break;
    case 3:
        cout<<"\n1- Add Department"<<"\n2- Show Department"<<"\n00- Back "<<"\n0- Exit"<<endl;
        cout<<"\n>>> ";cin>>ch;
        switch(ch)
        {
        case 1:
            depart[D_count].getdepartment();
            D_count++;
            break;
        case 2:
            for(int i=0;i<D_count;i++)
                depart[i].print();
            break;
        }
        system("pause");
        system("cls");
        break;
    case 4:
        //Assign
        int dept_id=-1;
        cout<<"Enter Department ID: ";
        cin>>dept_id;
        int Dept_index=-1;
        for(int i=0;i<D_count;i++)
        {
            if(depart[i].get_ID()==dept_id)
                Dept_index=i;
        }
        if(Dept_index==-1)
            cout<<"Department is not found...\n";
        else
        {
            int emp_id=-1;
            cout<<"Enter Employee ID: ";
            cin>>emp_id;
            bool AssignSuccessful=H.Assign_Dept_to_emp(emp_id,depart+Dept_index);
            if(AssignSuccessful)
                cout<<"Assignment Successfully!";
            else
                cout<<"Assignment is failed";
        }
        break;
        return 0;
    }

    }while(ch != 0 || ch == 00);
    return 0;
}
