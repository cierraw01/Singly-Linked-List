//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 

 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"

using namespace std;

#include <iostream>
#include <cstdlib>




void simpleSortTotal(LinkedList* list);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    LinkedList* list = new LinkedList();			// Replace array with Linked List
    int   airportCount;
    //Airport* a[13500];
    
    infile.open ("./USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            Airport* airportArr = new Airport();
            infile.getline(airportArr->code, 256, ',');
            infile.getline(cNum, 256, ',');
            airportArr->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airportArr->latitude = atof(cNum);

            if (!(c % 100)){
                cout << airportArr->code << " long: " << airportArr->longitude << " lat: " << airportArr->latitude <<  "\n";
                //cout << "hello" << "\n";
            }
            /*
            if (!(c % 100))
            {
                cout << airportArr->code << " long: " << airportArr->longitude << " lat: " << airportArr->latitude <<  "\n";
                //cout << (*list).get(c)->next->data->code << "\n"; //" long: " << (*list).get(c+1)->longitude << " lat: " << (*list).get(c+1)->latitude <<  "\n";                               
            }
            */
            
            (*list).add(airportArr);
            
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
        //cout << "finished adding" << "\n";
         for (int c=0; c < airportCount; c++){
            if (!(c % 100))
            {
                cout << (*list).get(c)->code << " long: " << (*list).get(c)->longitude << " lat: " << (*list).get(c)->latitude <<  "\n";
                cout << (*list).get(c+1)->code << " long: " << (*list).get(c+1)->longitude << " lat: " << (*list).get(c+1)->latitude <<  "\n";
                cout <<"Distance between " << (*list).get(c)->code << " and " << (*list).get(c+1)->code << " is "
                  << distanceEarth((*list).get(c)->longitude,(*list).get(c)->latitude , (*list).get(c+1)->longitude, (*list).get(c+1)->latitude) << "\n";
            }
          }
          simpleSortTotal(list);
          (*list).toString();


    }
    else
    {
        cout << "Error opening file";
    }
 


    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/
/*
void simpleSortTotal()
{
}
*/

void simpleSortTotal(LinkedList *list){
  Node* current = new Node;
  current = list->head;
  Node* after = new Node;
  after = list->head;
  Airport* temp = new Airport;
    for (int i = 0; i < list->length; i++){
      //cout << i << "\n";
      after = current->next;
      for (int j = i+1; j < list->length; j++){
       // cout << j << "\n";
        //cout << "true " << i << "\n";
        //cout << "hello" << "\n"; 
        if (distanceEarth((*list).get(i)->latitude, (*list).get(i)->longitude, 30.1944, 97.6700)>distanceEarth((*list).get(j)->latitude, (*list).get(j)->longitude, 30.1944,97.6700)){
          temp = (*list).get(i);
          current->data = (*list).get(j);
          after->data = temp;
        }
          //cout << "friend" << "\n";
        after = after->next;
      }
      current = current->next;
    }
}
