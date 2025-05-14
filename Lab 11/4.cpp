#include <iostream>
#include <exception>
using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {};
class QueryTimeoutException : public DatabaseException {};

template<typename T>
class DatabaseConnector {
public:
    void connect(T dbName) {
        if (dbName == "invalid_db")
            throw ConnectionFailedException();
        if (dbName == "slow_db")
            throw QueryTimeoutException();
        cout << "Connected to " << dbName << endl;
    }
};

int main() {
    DatabaseConnector<string> db;

    try {
        db.connect("invalid_db");
    } catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException\nwhat(): " << e.what() << endl;
    }

    try {
        db.connect("slow_db");
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException\nwhat(): " << e.what() << endl;
    }

    return 0;
}
