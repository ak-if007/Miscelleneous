#include <bits/stdc++.h>
#include<cstring>
using namespace std;
class Course;
Course* ptr;
int c;
class Course
{

    int term;
    int level;
    float credit;

public:
    char *Coursecode;
    Course()
    {
    }


    void set_Course(char *a)
    {
        int i = 0, c = 0, j = 0;
        char b[20];
        while (a[i])
        {

            if (a[i] == ' ' || i == strlen(a) - 1)
            {
                c++;


                if (c == 1)
                {
                    Coursecode = new char[strlen(b) + 1];
                    strcpy(Coursecode, b);
                }
                if (c == 2)
                {

                    credit = atof(b);
                }
                if (c == 3)
                {
                    term = atoi(b);
                }
                if (c == 4)
                {
                    level = atoi(b);
                }

                b[0] = '\0';
                j = 0;
            }
            else
            {
                b[j] = a[i];
                b[j + 1] = '\0';
                j++;
            }

            i++;

        }
    }

     float get_credit(){return credit;}

    void set_course_result(char* a)
        {
            Coursecode=new char[strlen(a)+1];
            for(int i=0;i<strlen(a);i++)
            {
                Coursecode[i]=a[i];
                Coursecode[i+1]='\0';
            }

            int i=0;

            while(strcmp(this->Coursecode,ptr[i].Coursecode))
            {

                i++;
            }

            this->credit=ptr[i].get_credit();



        }
        char* get_Course(){
            char * b=new char[strlen(Coursecode)+1];
            strcpy(b,Coursecode);
        return b;}

    ~Course()
    {

        //cout<<"Destructing Course"<<endl;
        delete[] Coursecode;
    }

};

class Course_Result{
    float GP;
     Course x;

public:

    Course_Result(){

    }

    ~Course_Result(){
    }
    void set_CourseResult(char* a,float b)
    {
         x.set_course_result(a);
        GP=b;
    }
    float get_GP(){return GP;}
    char* get_Coursecode(){return x.get_Course();}


     float get_credit(){return x.get_credit();}

};


class Student{
   char *name;
   char *ID;
   Course_Result* p;
   int n;

   public:

       Student(){}
       Student(const Student &s){

             //cout<<"Copy Constructor";
            name=new char[strlen(s.name)+1];
            strcpy(name,s.name);

            ID=new char[strlen(s.ID)+1];
            strcpy(ID,s.ID);


            p=new Course_Result[s.n];

            for(int i=0;i<s.n;i++)
            {


                p[i].set_CourseResult(s.p[i].get_Coursecode(),s.p[i].get_GP());

            }

            this->n=s.n;


        }
       ~Student(){
          delete[] name;
          delete [] ID;
          delete[] p;

       }

       void set_Student_Name(char *a)
       {


        name=new char[strlen(a)+1];
        for(int i=0;i<strlen(a);i++)
        {
            name[i]=a[i];
            name[i+1]='\0';
        }

       }
       void set_ID(char* a)
       {
           ID=new char[strlen(a)+1];
           for(int i=0;i<strlen(a);i++)
        {
            ID[i]=a[i];
            ID[i+1]='\0';
        }

       }
       void set_course(char **a,float* b,int x)
       {
          n=x;
          p=new Course_Result[x];
          for(int i=0;i<x;i++)
          {

              p[i].set_CourseResult(a[i],b[i]);
          }

       }
      double getCGPA(){

                double cg=0,s=0;
                for(int i=0;i<n;i++)
                {
                         cg+=(p[i].get_credit()*p[i].get_GP());
                         s+=p[i].get_credit();

                }
                //CG=(cg/s);



                return (cg/s);

       }

       char* get_ID(){return ID;}


};

double getCGPA(Student student){
            return student.getCGPA();
}

Student getTopstudent(const char *dept,const char* batch,Student *s){

           char* ID=new char[10];
           char a[3],b[5];
               int z=0,top=-1;
               double low=-1;
             for(int i=0;i<c;i++)
             {

                  strcpy(ID,s[i].get_ID());

                   for(int j=0;j<6;j++){
                        if(j<4)
                        {
                            b[j]=ID[j];

                            b[j+1]='\0';

                        }
                        else{

                            a[z]=ID[j];

                            a[z+1]='\0';
                            z++;
                        }


                   }
                   z=0;
                   if(!strcmp(a,dept) && !strcmp(b,batch))
                   {

                       if(s[i].getCGPA()>low)
                        top=i;
                   }




             }
              cout<<s[top].get_ID()<<s[top].getCGPA()<<endl;

             delete[] ID;

             return s[top];

}

Student getTopstudent( const char *dept,Student *s){

           char* ID=new char[10];
           char a[3];
               int z=0,top=-1;
               double low=-1;
             for(int i=0;i<c;i++)
             {

                  strcpy(ID,s[i].get_ID());

                   a[0]=ID[4];
                   a[1]=ID[5];
                   a[2]='\0';
                   if(!strcmp(a,dept))
                   {

                       if(s[i].getCGPA()>low)
                        top=i;
                   }




             }


             delete[] ID;

             return s[top];

}
Student getTopstudent(Student *s, const char* batch){

           char* ID=new char[10];
           char a[5];
               int z=0,top=-1;
               double low=-1;
             for(int i=0;i<c;i++)
             {

                  strcpy(ID,s[i].get_ID());

                  for(int j=0;j<4;j++)
                  {
                      a[j]=ID[j];
                      a[j+1]='\0';
                  }
                   if(!strcmp(a,batch))
                   {

                       if(s[i].getCGPA()>low)
                        top=i;
                   }




             }


             delete[] ID;

             return s[top];

}

int main()
{
      FILE *p;
    p = fopen("Course.txt", "r");
    if (p == NULL)
    {
        cout << "Error while reading Course.txt ";
        return 0;
    }
    int n = 0, d;
    float b;
    char* a=new char[100];

    while (!feof(p))
    {
        fgets(a, 1000, p);

        n++;
    }


    rewind(p);

     ptr = new Course[n];

    int i = 0;
    while (!feof(p))
    {
        fgets(a, 10000, p);

        ptr[i].set_Course(a);


        i++;
    }

    FILE *ab;
    ab = fopen("Student.txt", "r");
    if (ab == NULL)
    {
        cout << "Error while reading Student.txt ";
        return 0;
    }
    int* z=new int[1000], t = 0;
    i = 0, c = 0;
    while (1)
    {

        fgets(a, 1000, ab);

        t++;
        if (!strcmp(a, "\n") || feof(ab))
        {
            c++;
            z[i] = t;
            t = 0;
            i++;
        }

        if (feof(ab))
            break;
    }
      rewind(ab);


    int cnt = 0;
    //string temp;
    char* temp=new char[100];

    Student *s = new Student[c];
    float zy;
       char ch;

    for (int i = 0; i < c; i++)
    {


        //string* course=new string[z[i]-3];
        char **course =new char*[z[i]-3];
        float* GP=new float[z[i]-3];

        for (int j = 0; j < z[i]; j++)
        {
             if(j==z[i]-1 && i==c-1)
                continue;

         if(j==0 || j==1 || j==z[i]-1)
         {
             fgets(temp,1000,ab);



                 if(j==0)
                 {
                     s[i].set_Student_Name(temp);

                 }

               else if(j==1)
                       {
                          s[i].set_ID(temp);


                       }

         }


         else{
                fscanf(ab,"%s %f%c",temp,&zy,&ch);


              course[cnt]=new char[strlen(temp)+1];
              strcpy(course[cnt],temp);
            GP[cnt]=zy;
            ///cout<<course[cnt]<<" "<<GP[cnt]<<endl;
            cnt++;
         }



        }
        cnt=0;
        s[i].set_course(course,GP,z[i]-3);
        delete[]course;
        delete[]GP;


    }

      getTopstudent("06","2021",s);
      cout<<getCGPA(s[0])<<endl;

      cout<<s[0].getCGPA();

     fclose(ab);
    fclose(p);
    delete[] ptr;
     delete []a;
    delete []temp;
    delete []z;
    delete[] s;




        return 0;
}
