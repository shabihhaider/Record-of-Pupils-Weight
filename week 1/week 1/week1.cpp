#include<iostream>
using namespace std;

const int MAX_Students = 30; //You can input the size of the array (How many records of Pupils do you want to store)

class StudentWeightRecord
{
private:
    string names[MAX_Students];
    float weightsFirstDay[MAX_Students];
    float weightsDiff[MAX_Students];
    float weightsLastDay[MAX_Students];
    int size;
public:
    StudentWeightRecord()
    {
        for (int i = 0; i < MAX_Students; i++)
        {
            names[i] = "";
            weightsFirstDay[i] = 0;
            weightsLastDay[i] = 0;
            weightsDiff[i] = 0;
        }
        size = 0;
    }

    bool weightValidation(float weight)
    {
        if (weight <= 0 || weight > 200)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool uniqueName(string n) const
    {
        for (int i = 0; i < MAX_Students; i++)
        {
            if (n == names[i])
            {
                return true;
            }
        }
    }

    bool isAlphabetic(const string& str)
    {
        for (char ch : str)
        {
            if (!isalpha(ch))
            {
                return false;
            }
        }
        return true;
    }

    string getName()
    {
        string n;
        cout << "Enter the name of student" << endl;
        cin >> n;

        if (!isAlphabetic(n)) //Check name is alphabetic or not?
        {
            cout << "Invalid name. Please enter a name containing only alphabetic characters." << endl;
            getName();
        }

        return n;
    }

    float getWeight()
    {
        float w;
        cout << "Enter the weight of student in kg." << endl;
        cin >> w;

        return w;
    }

    void inputData()
    {
        string name;
        name = getName();

        while (uniqueName(name) == true) //Name must be unique
        {
            cout << "This name already exists! Please Enter a UNIQUE Name.\n" << endl;
            name = getName();
        }

        float weight;
        weight = getWeight();

        while (weightValidation(weight) == true) //Check weight is valid or not?
        {
            cout << "Weight Range between 0-200 and weight in kg." << endl;
            cout << "Invalid weight, please enter again\n" << endl;
            weight = getWeight();
        }

        names[size] = name;
        weightsFirstDay[size] = weight;
        size++;
    }

    void calculateWeightDiff() //Calculate the difference between the first day and last day term of Pupils
    {
        for (int i = 0; i < MAX_Students; i++)
        {
            float weight = 0;
            cout << "Weight of last day of term (in kg)." << endl;
            cout << "(Weight of Last Day of Term) Student '" << names[i] << "'\n" << endl;
            weight = getWeight();

            while (weightValidation(weight) == true) //Check weight is valid or not?
            {
                cout << "Weight Range between 0-200 and weight in kg." << endl;
                cout << "Invalid weight, please enter again\n" << endl;
                weight = getWeight();
            }

            weightsLastDay[i] = weight;
            weightsDiff[i] = weightsFirstDay[i] - weight;
        }

    }

    void printSpecificData() const
    {
        for (int i = 0; i < MAX_Students; i++)
        {
            cout << "Pupil's Name: " << names[i] << endl;
            cout << "First day term weight: " << weightsFirstDay[i] << endl;
            cout << "Last day term weight: " << weightsLastDay[i] << endl;
            cout << "Difference in weight: " << weightsDiff[i] << endl;

            if (weightsDiff[i] > 2.5)
            {
                cout << "Status: " << " Rise\n" << endl;
            }
            else if (weightsDiff[i] < 2.5)
            {
                cout << "Status: " << " Fall\n" << endl;
            }
            else if (weightsDiff[i] == 0)
            {
                cout << "Status: " << " No Change\n" << endl;
            }
            cout << "--------------------" << endl;
        }
    }

    void printData() const
    {
        cout << "NAME --------- WEIGHT\n" << endl;
        for (int i = 0; i < MAX_Students; i++)
        {
            cout << names[i] << "---------" << weightsFirstDay[i] << endl;
        }

    }
};

int main()
{
    StudentWeightRecord stdWR;

    cout << "TOTAL STUDENTS: " << MAX_Students << endl;

    //TASK - 1
    for (int i = MAX_Students; i > 0; i--)
    {
        cout << "Remaining Students: " << i << endl;
        stdWR.inputData(); //Get Names and Weights of Pupils from user
    }

    cout << "Would you like to see the RECORD of Students? (y/n)\n" << endl;
    char ch;
    cin >> ch;

    if (ch == 'y')
    {
        stdWR.printData();
    }

    cout << "Going to Task 2......!" << endl;
    system("pause");

    //TASK 2
    stdWR.calculateWeightDiff();

    cout << "Going to Task 3......!" << endl;
    system("pause");

    //TASK 3
    stdWR.printSpecificData();

    return 0;
}
