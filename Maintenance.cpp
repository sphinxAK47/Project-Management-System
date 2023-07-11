#include<iostream>
#include<cstring>
using namespace std;

class Manager
{
    private:

    string name;

    public:

    Manager()
    {
        name = " ";
    }

    Manager(string n1)
    {
        name = n1;
    }

    string getManager()
    {
        return name;
    }
};

class Project
{
    private:

    string title;
    Manager* manager;

    public:

    Project()
    {
        title = "No Project";
        manager = NULL;
    }

    void setTitle(string s1)
    {
        title = s1;
    }

    string getTitle()
    {
        return title;
    }

    void setManager(Manager* m1)
    {
        manager = m1;
    }

    Manager* getManager()
    {
        return manager;
    }

    ~Project()
    {
        delete manager;
    }
};

class Employee
{
    private:

    string name;
    Project* project;
    Manager* manager;

    public:

    Employee()
    {
        name = " ";
        project = new Project();
        manager = NULL;
    }

    void setName(string bob)
    {
        name = bob;
    }

    void setProject(Project* peter)
    {
        if (peter == NULL)
            return;

        project = peter;
        manager = (*peter).getManager();
    }

    void allocateManager(Manager* mike)
    {
        manager = mike;
    }

    void print()
    {
        cout<<"Employee Name: "<<name<<"\nProject: "<<project->getTitle()<<endl;
        if (manager != NULL)
            cout<<"Manager: "<<manager->getManager()<<endl;
    }

    ~Employee()
    {
        delete project;
    }
};

int main()
{
    Manager* mike = new Manager("Michael"), dike("Dwight"), jike("Jim"), aike("Andy");

    Employee* emp = new Employee[15];

    string nameBank[] = {"Akira", "Hikaru", "Ryutaro", "Kazuki", "Haruka", "Naoki", "Sakura", "Yusuke", "Arisa", "Satoshi", "Miyuki", "Shota", "Tomoko", "Junpei", "Ayaka"};
   
    for (int i=0; i<15; i++) 
    {
        emp[i].setName(nameBank[i]);
    }

    Project* p1 = new Project[7];
    p1[0].setTitle("Project 1");
    p1[1].setTitle("Project 2");
    p1[2].setTitle("Project 3");
    p1[3].setTitle("Project 4");
    p1[4].setTitle("Project 5");
    p1[5].setTitle("Project 6");
    p1[6].setTitle("Project 7");

    int count = 0;

    for (int i=0; i<15; i++)
    {
        if (i%2 == 1)
        {
            emp[i].setProject(&p1[count]);
            count++;
        }  
    }

    emp[0].allocateManager(mike);
    emp[1].allocateManager(mike);
    emp[2].allocateManager(&dike);
    emp[3].allocateManager(&jike);
    emp[4].allocateManager(&jike);
    emp[5].allocateManager(&jike);
    emp[6].allocateManager(&dike);
    emp[7].allocateManager(&jike);
    emp[8].allocateManager(&jike);
    emp[13].allocateManager(&aike);
    emp[14].allocateManager(&aike);

    for (int i=0; i<15; i++)
    {
        emp[i].print();
        cout<<endl;
    }

    delete [] emp;
    delete [] p1;
    delete mike;
return 0;
}