#include <iostream>
#include <string>
using namespace std;

class Device{
protected:
    int deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(int id,string name,bool stat,string loc = "")
        :deviceID(id),deviceName(name),status(stat), location(loc) {}

    virtual void turnOn(){status= true;}
    virtual void turnOff() {status=false;}
    virtual void getStatus()const{cout<< "Status: "<<(status?"On": "Off") <<endl;}
    virtual void displayInfo() const{
        cout << "ID: " << deviceID<<",Name: "<<deviceName<<",Location: " <<location<<endl;
    }
};

class Light: public Device {
    int brightnessLevel;
    string colorMode;

public:
    Light(int id,string name, bool stat,int brightness, string color, string loc = "")
        : Device(id,name,stat,loc),brightnessLevel(brightness), colorMode(color) {}

    void displayInfo()const override{
        Device::displayInfo();
        cout <<"Brightness: "<<brightnessLevel << ", Color Mode: " << colorMode << endl;
    }
};

class Thermostat:public Device {
    float temperature;
    string mode;
    float targetTemperature;

public:
    Thermostat(int id,string name,bool stat,float temp, string m, float targetTemp, string loc = "")
        : Device(id,name,stat,loc),temperature(temp), mode(m), targetTemperature(targetTemp) {}

    void getStatus() const override {
        cout << "Current Temperature: " << temperature << ", Mode: " << mode
             << ", Target: " << targetTemperature << endl;
    }
};

class SecurityCamera : public Device {
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, bool stat, string res, bool recording, bool nightVision, string loc = "")
        : Device(id, name, stat, loc), resolution(res), recordingStatus(recording), nightVisionEnabled(nightVision) {}

    void turnOn() override {
        status = true;
        recordingStatus = true;
        cout << "Camera turned on and recording started." << endl;
    }
};

class SmartPlug : public Device {
    float powerConsumption;
    int timerSetting;

public:
    SmartPlug(int id, string name, bool stat, float power, int timer, string loc = "")
        : Device(id, name, stat, loc), powerConsumption(power), timerSetting(timer) {}

    void turnOff() override {
        status = false;
        cout << "Smart Plug turned off. Power logged: " << powerConsumption << "W" << endl;
    }
};

int main(){
    Light light(1, "Living Room Light", false, 75, "Warm White", "Living Room");
    Thermostat thermostat(2, "Main Thermostat", true, 22.5, "Heating", 24.0, "Hallway");
    SecurityCamera camera(3, "Front Door Cam", false, "1080p", false, true, "Entrance");
    SmartPlug plug(4, "Coffee Maker Plug", true, 800.0, 30, "Kitchen");

    light.turnOn();
    light.displayInfo();

    thermostat.getStatus();

    camera.turnOn();

    plug.turnOff();

    return 0;
}
