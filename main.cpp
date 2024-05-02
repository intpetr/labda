#include <iostream>
#include <cstdlib>
#include <iostream>

#include <chrono>
#include <thread>


using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;



void createball(char* ball[6])
{
    char* arr1 = new char[6] {' ', ' ', ' ', ' ', ' ', ' '};

    //char l1[6] = {' ', ' ', ' ', ' ', ' ', '0'};
    

    char* arr2 = new char[6] {' ', ' ', '0', '0', ' ', ' '};

    //char l2[6] = {' ', ' ', '0', '0', ' ', ' '};
    

    char* arr3 = new char[6] {' ', '0', '0', '0', '0', ' '};
    //char l3[6] = {' ', '0', '0', '0', '0', ' '};
    

    char* arr4 = new char[6] {' ', '0', '0', '0', '0', ' '};
    //char l4[6] = {' ', '0', '0', '0', '0', ' '};

    

    char* arr5 = new char[6] {' ', ' ', '0', '0', ' ', ' '};
    //char l5[6] = {' ', ' ', '0', '0', ' ', ' '};
   

    char* arr6 = new char[6] {' ', ' ', ' ', ' ', ' ', ' '};
    //char l6[6] = {' ', ' ', ' ', ' ', ' ', ' '};
    

    ball[0] = arr1;
    ball[1] = arr2;
    ball[2] = arr3;
    ball[3] = arr4;
    ball[4] = arr5;
    ball[5] = arr6;







}


void show(char* a[25])
{
    int m = 25;
    int n = 25;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void plotball(char* a[25],char* b[6],int x, int y)
{
    int nx = x-2;
    int ny = y-2;

    int fx = nx + 6;
    int fy = ny + 6;

    int m = 25;
    int n = 25;


    int xcount = 0;
    int ycount = 0;


    for (int i = 0; i < 6; i++) {
            ycount++;
        for (int j = 0; j < 6; j++) {
            xcount++;




            
            if (b[i][j]!=' ')
            {
                

                a[i+nx][j+ny] = '0';
            }



        }
        cout << endl;
    }
}



void clear(char* a[25])
{
    int m = 25, n = 25, c = 0;
    for (int i = 0; i < m; i++) {

        
        a[i] = new char[n];
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            
            a[i][j] = '.';
        }
    }
}


int main()
{


    int m = 25, n = 25, c = 0;

    
    char** a = new char*[m];

    for (int i = 0; i < m; i++) {

        
        a[i] = new char[n];
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            
            a[i][j] = '.';
        }
    }

    
    char** test = new char*[6];


    createball(test);
    

    int currentx = 10;
    int currenty = 10;


    int i = 1;
    int v = -1;

    int errcount = 0;
    while(true)
    {

        if (currentx+v >1 && currenty+i > 1 && currentx+v <23 && currenty+i <23)
        {
           currentx = currentx + v;
        currenty = currenty + i;
        plotball(a,test,currentx,currenty);
        show(a);
        clear(a);
        sleep_until(system_clock::now() + milliseconds(200));
        errcount = 0;
        cout<<v<<" "<<i<<endl;
        cout<<"Current x "<<currentx<<" current y "<<currenty<<endl;
        }
        else{
                errcount++;

                if (errcount == 2)
            {
                return 0;
            }

                //i v vektor


            if (v == -1 && currenty+i > 1)
            {
                cout<<"halo halo halo"<<endl;
                i = -1;
                v = 1;
                cout<<v<<" "<<i<<endl;
                continue;
            }






            if (v == 1 &&  currenty == 2 )
            {
                
                i = 1;
                v = 1;
                cout<<v<<" "<<i<<endl;
                continue;
            }

            if (v == -1 &&  currenty == 2 )
            {
                
                i = 1;
                v = -1;
                
                continue;
            }



            if (v == -1 &&  currentx== 2 )
            {
                
                i = -1;
                v = 1;
                
                continue;
            }


            if (v == 1 &&  currentx == 22 )
            {
                
                i = 1;
                v = -1;
                
                continue;
            }

            if (v == -1 &&  currentx == 22 )
            {
                cout<<"masik oldal"<<endl;
                i = -1;
                v = -1;
                
                continue;
            }



            //int random = rand() % (1 -1 + 1) -1;
            //int b = i;
            //v = (-1)*i*random;
            //i = (-1)*b;
            //cout<<random<<endl;
            
            
            if (errcount == 2)
            {
                return 0;
            }
            //return 0;
        }


    }

    delete test[0];
    delete test[1];
    delete test[2];
    delete test[3];
    delete test[4];
    delete test[5];
    delete test;
}
