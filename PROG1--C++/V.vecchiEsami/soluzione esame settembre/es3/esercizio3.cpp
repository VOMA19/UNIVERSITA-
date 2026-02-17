#include <iostream>

struct Employee {
    int id;
    char name[50];
    double salary;
    double projectBudget;
    Employee* directReports; // Linked list of direct reports
    Employee* nextReport;   // Next report in the list
};

// Helper function to add a direct report
void addDirectReport(Employee* manager, Employee* report) {
    if (!manager || !report) return;
    
    if (!manager->directReports) {
        manager->directReports = report;
    } else {
        Employee* last = manager->directReports;
        while (last->nextReport) {
            last = last->nextReport;
        }
        last->nextReport = report;
    }
}

// Add here below the declaration of the function calcola

// Add here above the declaration of the function calcola


int main(int argc, char* argv[]) {
    if (argc != 1) {
        std::cerr << "Usage: " << argv[0] << std::endl;
        return 1;
    }

    // Example of how to use the Employee structure
    Employee ceo;
    ceo.id = 1;
    strcpy(ceo.name, "John Doe");
    ceo.salary = 50000.0;
    ceo.projectBudget = 10000.0;
    ceo.directReports = nullptr; // No direct reports initially
    ceo.nextReport = nullptr;     // No next report initially

    Employee cto;
    cto.id = 2;
    strcpy(cto.name, "Jane Smith");
    cto.salary = 40000.0;
    cto.projectBudget = 8000.0;
    cto.directReports = nullptr; // No direct reports initially
    cto.nextReport = nullptr;     // No next report initially

    Employee cfo;
    cfo.id = 3;
    strcpy(cfo.name, "Alice Johnson");
    cfo.salary = 45000.0;
    cfo.projectBudget = 9000.0;
    cfo.directReports = nullptr; // No direct reports initially
    cfo.nextReport = nullptr;     // No next report initially

    Employee cmo;
    cmo.id = 4;
    strcpy(cmo.name, "Bob Brown");
    cmo.salary = 42000.0;
    cmo.projectBudget = 8500.0;
    cmo.directReports = nullptr; // No direct reports initially
    cmo.nextReport = nullptr;     // No next report initially   

    Employee eng1;
    eng1.id = 5;
    strcpy(eng1.name, "Charlie Green");
    eng1.salary = 30000.0;
    eng1.projectBudget = 5000.0;
    eng1.directReports = nullptr; // No direct reports initially
    eng1.nextReport = nullptr;     // No next report initially  

    Employee eng2;
    eng2.id = 6;
    strcpy(eng2.name, "Daisy White");
    eng2.salary = 32000.0;
    eng2.projectBudget = 6000.0;
    eng2.directReports = nullptr; // No direct reports initially
    eng2.nextReport = nullptr;     // No next report initially

    Employee sa;
    sa.id = 7;
    strcpy(sa.name, "Eve Black");
    sa.salary = 28000.0;
    sa.projectBudget = 4000.0;
    sa.directReports = nullptr; // No direct reports initially
    sa.nextReport = nullptr;     // No next report initially

    Employee ma;
    ma.id = 8;
    strcpy(ma.name, "Frank Gray");
    ma.salary = 29000.0;
    ma.projectBudget = 4500.0;
    ma.directReports = nullptr; // No direct reports initially
    ma.nextReport = nullptr;     // No next report initially

    Employee ml;
    ml.id = 9;
    strcpy(ml.name, "Grace Blue");
    ml.salary = 31000.0;
    ml.projectBudget = 5500.0;
    ml.directReports = nullptr; // No direct reports initially
    ml.nextReport = nullptr;     // No next report initially

    Employee developer;
    developer.id = 10;
    strcpy(developer.name, "Hank Yellow");
    developer.salary = 35000.0;
    developer.projectBudget = 7000.0;
    developer.directReports = nullptr; // No direct reports initially
    developer.nextReport = nullptr;     // No next report initially

    // Building the hierarchy
    addDirectReport(&ceo, &cto);
    addDirectReport(&ceo, &cfo);
    addDirectReport(&ceo, &cmo);
    addDirectReport(&cto, &eng1);
    addDirectReport(&cto, &eng2);
    addDirectReport(&cfo, &sa);
    addDirectReport(&sa, &ma);
    addDirectReport(&cmo, &ml);
    addDirectReport(&cmo, &developer);

    // Output example
    std::cout << "CEO Total cost: " << calcola(&ceo) << std::endl;
    std::cout << "CTO Department cost: " << calcola(&cto) << std::endl;
    std::cout << "CFO Department cost: " << calcola(&cfo) << std::endl;
    std::cout << "CMO Department cost: " << calcola(&cmo) << std::endl;
    std::cout << "Marketing Lead cost: " << calcola(&ml) << std::endl;
    std::cout << "Null cost: " << calcola(nullptr) << std::endl;
    return 0;
}

// Add here below the definition of the function calcola

// Add here above the definition of the function calcola