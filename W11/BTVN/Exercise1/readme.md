```mermaid
    class Project {
        <<Abstract>>
        #string projectName
        +Project(string name)
        +calculateSponsor()* double
        +~Project()
    }

    %% Lớp con cho dự án Idea
    class IdeaProject {
        -int developMonths
        -double devCostPerMonth
        +IdeaProject(string name, int months, double cost)
        +calculateSponsor() double
    }

    %% Lớp con cho dự án MVP
    class MVPProject {
        -int runMonths
        -int marketingMonths
        -double runCostPerMonth
        -double marketingCostPerMonth
        +MVPProject(string name, int rMonths, int mktMonths, double rCost, double mktCost)
        +calculateSponsor() double
    }

    %% Quan hệ kế thừa
    Project <|-- IdeaProject
    Project <|-- MVPProject
```