#ifndef BUILDING_H
#define BUILDING_H

#include "InterstoryParam.h"
#include "FloorParam.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class HazusSAM_Generator;
class Building
{
public:
    enum StruType{RM1, RM2, URM, C1, C2, C3, W1, W2, S1, S2, S3, S4, S5, PC1, PC2, MH, UNKNOWN}; //Hazus structural type
    enum BldgOccupancy{office, education, healthcare, hospitality, residence, retail, warehouse, research, unknown};

    struct EDP{     //engineering demand parameters
      vector<double> IDR; // Inter-story drift ratio. size = nStory
      vector<double> PFA; // Peak floor acceleration. size = nStory+1
      double residual;    // residual drift
      //vector<double> PFV; // Peak floor velocity. size = nStory
      //vector<double> rotation; // rotation. size = nStory
    };


    Building();    

    void readBIM(const char *fileBIM);
    void writeSAM(const char *path);
    void writeSAMSCI(const char *path);
    void writeSAMdamage(const char *path);
    string GetHazusType();    
    static StruType s2StruType(string s);
    BldgOccupancy s2BldgOccupancy(string s);
    
    //basic building info
    int id;
    string name;
    StruType strutype;
    string strutype1;
    int year;
    BldgOccupancy occupancy;
    int nStory;
    double storyheight;   //unit: m
    double area;	  //story area. unit: m^2
    double im;  //intensity measure
    
    double clpsMedian;	    //collapse median. unit: m/s^2
    double clpsDispersion;  //collapse dispersion
    
    //building structural info
    vector <InterstoryParam> interstoryParams;
    vector <FloorParam> floorParams;
    double damageCriteria[4];
    double dampingRatio;
    double T0;
    double T2;
    double x,y;

    int ndf;
    
    double lambda(int n) {
      return 0.4053*(double)(n*n)+0.405*(double)(n)+0.1869;
    }
};

#endif // BUILDING_H
