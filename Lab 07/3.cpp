#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id,string name,double p, string d, string dest)
        : ticketID(id),passengerName(name), price(p),date(d),destination(dest) {}

    virtual void reserve(){
        cout<<"Ticket reserved for " << passengerName<<endl;
    }

    virtual void cancel() {
        cout<<"Ticket cancelled for "<<passengerName<< endl;
    }

    virtual void displayTicketInfo() const{
        cout<< "ID: "<< ticketID<< ", Name: " << passengerName
             << ", Price: $" << price << ", Date: " << date << ", Destination: " << destination << endl;
    }
};

class FlightTicket : public Ticket {
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double p, string d, string dest,
                 string airline, string flight, string seat)
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << ", Flight #: " << flightNumber << ", Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double p, string d, string dest,
                string trainNo, string coach, string dep)
        : Ticket(id, name, p, d, dest), trainNumber(trainNo), coachType(coach), departureTime(dep) {}

    void reserve() override {
        cout << "Seat auto-assigned in train " << trainNumber << endl;
    }
};

class BusTicket : public Ticket {
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string name, double p, string d, string dest,
              string company, int seat)
        : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override {
        cout << "Bus ticket canceled, seat " << seatNumber << " is now available." << endl;
    }
};

class ConcertTicket : public Ticket {
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double p, string d, string dest,
                  string artist, string v, string seat)
        : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(seat) {}

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << ", Venue: " << venue << ", Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket ft(101, "Ali", 350.0, "2025-06-10", "Karachi", "AirBlue", "AB123", "Economy");
    TrainTicket tt(102, "Babar", 75.0, "2025-06-12", "Lahore", "TR789", "AC", "08:00AM");
    BusTicket bt(103, "Iqra", 25.0, "2025-06-15", "Faisalabad", "MegaBus", 15);
    ConcertTicket ct(104, "Ayesha", 120.0, "2025-06-20", "Islamabad", "Coldplay", "Stadium A", "VIP");

    ft.displayTicketInfo();
    tt.reserve();
    bt.cancel();
    ct.displayTicketInfo();

    return 0;
}
