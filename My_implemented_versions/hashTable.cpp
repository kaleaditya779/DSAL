#include <iostream>
#define size 10
using namespace std;

struct Client_Info
{
    string name;
    long long MobNo;
};

class Hash_class
{
    Client_Info hash_table[10];
    int key;

public:
    Hash_class()
    {
        key = -1;
        for (int i = 0; i <= 9; i++)
        {
            hash_table[i].name = "NULL";
            hash_table[i].MobNo = 0;
        }
    }

    int calcHash(long long num)
    {
        key = num % 10;
        return key;
    }

    int insert(string name, long long no)
    {
        int flag = 0; // To check for collision if whether to start probing from index 0.
        int hash_key = calcHash(no);
        int placed_index = -1;
        if (hash_table[hash_key].name == "NULL")
        {
            hash_table[hash_key].name = name;
            hash_table[hash_key].MobNo = no;
            placed_index = hash_key;
        }
        else
        {
            cout << endl
                 << "Collision has occured.";
            cout << endl
                 << "Implementing linear probing" << endl;
            for (int i = hash_key; i < 10; i++)
            {
                if (hash_table[i].name == "NULL")
                {
                    hash_table[i].name = name;
                    hash_table[i].MobNo = no;
                    placed_index = i;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                for (int i = 0; i < 10; i++)
                {
                    if (hash_table[i].name == "NULL")
                    {
                        hash_table[i].name = name;
                        hash_table[i].MobNo = no;
                        placed_index = i;
                        break;
                    }
                }
            }
        }
        return placed_index;
    }

    void createEmp()
    {
        Client_Info temp;
        int n, place;
        cout << "Enter the no of clients to insert : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter client name : ";
            cin >> temp.name;
            cout << "Enter client phone : ";
            cin >> temp.MobNo;
            place = insert(temp.name, temp.MobNo);
            if (place == -1)
            {
                cout << "Table overflow. Not inserted";
            }
            else
            {
                cout << "Inserted record on index :" << place << endl;
            }
        }
    }

    void display()
    {
        cout << endl
             << "Your hash table is: " << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << hash_table[i].name << " : " << hash_table[i].MobNo << endl;
        }
    }
};

int main()
{

    Hash_class obj_cls;
    obj_cls.createEmp();
    obj_cls.display();
    return 0;
}
