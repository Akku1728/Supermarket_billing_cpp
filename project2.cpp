#include<iostream>
#include<fstream>
using namespace std;

class shopping{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
}obj;

int main()
{
        shopping s;
        s.menu();
        return 0;
}

void shopping :: menu(){
    m:
    int choice;
    string ID;
    string password;

    cout << "\t\t\t______________________________________\n";
    cout << "\t\t\t                                      \n";
    cout << "\t\t\t       Supermarket Main Menu          \n";
    cout << "\t\t\t                                      \n";
    cout << "\t\t\t______________________________________\n";
    cout << "\t\t\t                                      \n ";
    cout << "\t\t\t|           1) Administrator         |\n ";
    cout << "\t\t\t|                                    |\n ";
    cout << "\t\t\t|           2) Buyer                 |\n ";
    cout << "\t\t\t|                                    |\n ";
    cout << "\t\t\t|           3) Exit                  |\n ";
    cout << "\t\t\t                                      \n ";
    cout << "\t\t\t______________________________________\n";
    cout << "\t\t\t                                      \n ";
    cout << "\t\t\t Please Select ";
    cout << "\t\t\t                                      \n ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\n\n\n\t\t\t Enter User ID  \n";
        cin >> ID;
        cout << "\t\t\t Enter Password\n";
        cin >> password;

        if(ID=="akku" && password=="123"){
            obj.administrator();
        }
        else{
            cout << "\t\t\t Invalid User Name and Password\n";
        }
        break;

    case 2:
        {
        obj.buyer();
        }
        break;

    case 3:
        {
        exit(0);
        }
        break;

    default:
        {
        cout << "\t\t\t Please Select from the given Option \n";
        }
        break;
    }
    goto m;
}

void shopping :: administrator(){
    m:
    int choice;
    cout << "\n\n\n\n\t\t\t  Administrator Menu";
    cout << "\n\t\t\t|                           |";
    cout << "\n\t\t\t|_____1)Add the Product_____|";
    cout << "\n\t\t\t|                           |";
    cout << "\n\t\t\t|_____2)Modify the Product__|";
    cout << "\n\t\t\t|                           |";
    cout << "\n\t\t\t|_____3)Delete the Product__|";
    cout << "\n\t\t\t|                           |";
    cout << "\n\t\t\t|_____4)Show all Products___|";
    cout << "\n\t\t\t|                           |";
    cout << "\n\t\t\t|_____5)Back to Main Menu___|";
    cout << "\n\t\t\t|                           |";

    cout << "\n\t\t\t Please enter you choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1 :
        add();
        break;

    case 2 :
        edit();
        break;

    case 3 :
        rem();
        break;
    
    case 4 :
        list();
        break;

    case 5 :
        menu();
        break;

    default:
    {
    cout << "\t\t\t\t Please Select from the given Option \n";
    }
    break;
    }
    goto m;
}

void shopping :: buyer(){
    m:
    int choice;
    cout << "\n\t\t\t     Buyer            \n";
    cout << "                              \n";
    cout << "\n\t\t\t     1)Buy Product    \n";
    cout << "                              \n";
    cout << "\n\t\t\t     2)Go Back        \n";
    cout << "                              \n";
    cout << "\n\t\t\t  Enter your Choice : \n";
    cin >> choice;

    switch(choice)
    {
        case 1:
        receipt();   
        break;

        case 2:
        menu();
        break;

        default:
        {
        cout << "\t\t\t Please Select from the given Option \n";
        }
        break;
        }
    goto m;
}

void shopping :: add(){
    m:
    fstream data;
    int c, token = 0;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Add new Product ";
    cout << "\n\n\t Product code of the Product ";
    cin >> pcode;
    cout << "\n\n\t\t\t Name of the Product ";
    cin >> pname;
    cout << "\n\n\t\t\t Price of the Product ";
    cin >> price;
    cout << "\n\n\t\t\t Discount on the Product ";
    cin >> dis;

    data.open("database.txt", ios ::in); 

    if(!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if(token==1)
        goto m;
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    cout << "\n\t\t\t Record Edited";
}

void shopping :: edit(){
    fstream data, data1;
    int pkey, token = 0, c;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Modify the record ";
    cout << "\n\n\t\t\t Enter the product code ";
    cin >> pkey;

    data.open("database.txt", ios ::in);
    if(!data){
        cout << "\n\n File does not exist! ";
    }
    else{
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout << "\n\t\t\t New Product Code \n";
                cin >> c;
                cout << "\n\t\t\t Name of the Product \n";
                cin >> n;
                cout << "\n\t\t\t Price \n";
                cin >> p;
                cout << "\n\t\t\t Discount \n";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << " "<< "\n";
                cout << "\n\t\t\t Record Edited \n";
                token++;
                administrator();
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout << "\n\n Record not found sorry";
        }
    }
}

void shopping :: rem(){
    fstream data, data1;
    int pkey, token = 0;
    cout << "\n\t\t\t Delete Product ";
    cout << "\n\t\t\t Enter the Product code \n";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if(!data){
        cout << "\n\t\t\t File does not exist";
    }
    else{
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if(pcode==pkey)
            {
                cout << "\n\t\t\t Product deleted successfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout << "\n\n Record not found sorry";
        }

    }
}

void shopping :: list(){
    fstream data;
    data.open("database.txt", ios ::in);
    cout << "\n\n|_______________________________________________|\n";
    cout << "Product Code \t Name\t\t Price \n";
    cout << "\n\n|_______________________________________________|\n";
    data >> pcode >> pname >> price >> dis;
    while(!data.eof()){
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping :: receipt(){
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0, dis = 0, total=0;

    cout << "\n\n\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout << "\n\n Empty Database ";
    }
    else
    {
        data.close();

        list();
        cout << "\n_______________________________________________\n";
        cout << "\n|                                              \n";
        cout << "\n|             Please place the order           \n";
        cout << "\n|                                              \n";
        cout << "\n_______________________________________________\n";

        do
        {
            cout << "\n\n Enter Product Code :";
            cin >> arrc[c];
            cout << "\n\n Enter Quantity :";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout << "\n\n Duplicate Product Code. Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? If yes then press y else n "<<endl;
            cin >> choice;

        } while (choice == 'y');

        cout << "\n\n\t\t\t__________PRODUCTS__________\n";
        cout << "\n ProductNo. \t Product Name \t Product quantity \t Price \t Amount with Discount \n ";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while(!data.eof()){
                if(pcode==arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"<< pcode <<"\t\t" << pname <<"\t\t" << arrq[1] <<"\t\t" << price <<"\t\t" << amount <<"\t\t" << dis <<"\t\t";
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n________________________________________________________________________";
    cout << "\n Total Amount : " << total;
}
