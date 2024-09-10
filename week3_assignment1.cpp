///////////////
//PID.h
///////////////
#include "mbed.h"

int t = 1; //fake time reading (real time doesn't work on this sim)

long us_ticker_read_test(){
    return t;
}

class PIDClass{
public:
    
    PIDClass(double kP, double ki, double kD);
    double calculate(double error);
    
private:
    
    double kP, kI, kD; //constants 
    
    long lastTime; //timestamp of the previous time
    double lastError; //error of previous loop
    double sumError; //integral of all the error
    
    double calculateP(double error); 
    double calculateI(double error);
    double calculateD(double error);
};
///////////////
//PID.cpp
///////////////

//include PID.h //not neccessary here as we are using one file for everything.
PIDClass::PIDClass(double kP, double kI, double kD){
    lastTime = 0; //No calculations yet, so lastTime is 0;
    
    //TODO: initialize the rest of the private variables here
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
    sumError = 0;
}

/*
 * Calculates the P section for our PID algorithm.
 * @param error The current error
 * @return the output from this calculation
 */
double PIDClass::calculateP(double error){
    //printf("p [%f %f]\n",error, kP);
    return error * kP;
}

/*
 * Calculates the I section for our PID algorithm.
 * @param error The current error
 * @return the output from this calculation
 */
double PIDClass::calculateI(double error){
    long currentTime = us_ticker_read_test();
    //printf("--cT %d lT %d--",currentTime, lastTime);
    
    sumError += error * (currentTime - lastTime);
    //printf("i [%f %f]\n",sumError, kI);
    return sumError * kI;
}

/*
 * Calculates the D section for our PID algorithm.
 * @param error The current error
 * @return the output from this calculation
 */
double PIDClass::calculateD(double error){
    long currentTime = us_ticker_read_test();
    //printf("--cT %d lT %d--",currentTime, lastTime);
    
    double dE = (error - lastError) / (currentTime - lastTime);
    //printf("d [%f %f]\n",dE, kD);
    return dE * kD;
}

/*
 * Calculates the output for our PID algorithm.
 * @param error The current error
 * @return the output from this calculation
 */
double PIDClass::calculate(double error){
    double result = calculateP(error) + calculateI(error) + calculateD(error);
    
    lastTime = us_ticker_read_test();
    lastError = error;
    
    return result;
}

///////////////
//main.cpp // DO NOT EDIT PERMANENTLY BELOW
///////////////

//#include "PID.cpp" //not neccessary here again as we are using one file for everything.

bool dbug = true;

int main(){
    PIDClass testP(3.2,0,0);
    PIDClass testI(0,2.1,0);
    PIDClass testD(0,0,4.2);
    
    PIDClass testAll(3.2,2.1,4.2);
    
    double errors[25] = {1.34,1.144,0.838,0.425,-0.037,-0.454,-0.751,-0.917,-0.985,-1,-0.993,-0.961,-0.919,-0.838,-0.713,-0.562,-0.408,-0.269,-0.15,-0.052,0.029,0.095,0.151,0.198};
    
    for(int i = 0; i < 25; i ++){
        if(dbug){
            printf("Results at time %d: P: %f, I: %f D: %f All: %f\n", t,
                testP.calculate(errors[i]),
                testI.calculate(errors[i]),
                testD.calculate(errors[i]),
                testAll.calculate(errors[i])
                );
        }
        t++;
    }
}