// Store employee structures in a file, read their salaries, apply the specified increments, update the file, and display the records. 
#include <stdio.h>

struct emp{
    int empid;
    char name[20];
    float salary;
};

int main(){
    struct emp emp[10];

    for(int i=0;i<4;i++){
        printf("Enter employee ID of emp%d: ",i+1);
        scanf("%d",&emp[i].empid);
        printf("Enter name of emp%d: ",i+1);
        scanf("%s",&emp[i].name);
        printf("Enter salary of emp%d: ",i+1);
        scanf("%f",&emp[i].salary);
    }

    FILE *fp;

    fp=fopen("Employee.dat","wb");
    for(int j=0;j<4;j++){
        fwrite(&emp[j],sizeof(struct emp),1,fp);

    }
    fclose(fp);

    fp=fopen("Employee.dat","rb");
    for(int i=0;i<4;i++){
        fread(&emp[i], sizeof(struct emp), 1, fp);
        if(emp[i].salary>=50000){
            emp[i].salary=emp[i].salary+(emp[i].salary*0.05);
        }
        else if(emp[i].salary>=20000 && emp[i].salary<50000){
            emp[i].salary=emp[i].salary+(emp[i].salary*0.1);
            
        }
        else{
            emp[i].salary=emp[i].salary+(emp[i].salary*0.15);
            
        }
    }
    fclose(fp);

    fp=fopen("Employee.dat","wb");
    for (int i=0;i<4;i++){
        fwrite(&emp[i],sizeof(struct emp),1,fp);
    }
    fclose(fp);

    fp=fopen("Employee.dat","rb");
    for(int i=0;i<4;i++){
        fread(&emp[i], sizeof(struct emp), 1, fp);
        printf("Data of emp%d: %d %s %.2f\n",i+1,emp[i].empid,emp[i].name,emp[i].salary);
    }
    fclose(fp);
    


    return 0;
}